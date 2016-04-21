#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include "Fleet.h"
#include <time.h>

using namespace std;

int main() {
    vector<Fleet*> fleets;
    bool finished = true;
    do {
        try {
            Fleet* fleet = userInterfaceCreateFleet();
            finished = fleet == nullptr;
            fleets.push_back(fleet);
        } catch (invalid_argument e) {
            cout << "There was a problem: " << e.what() << endl;
            cout << "Try again.";
            finished = false;
        }
    } while (!finished);
    return 0;
}

int Ship::getEnergyConsumption() const {
    return energy;
}

int Ship::getWeight() const {
    return weight;
}

int Ship::getCost() const {
    return cost;
}

string Ship::getTypeName() const {
    return type;
}

bool Ship::isDestroyed() const {
    return false;
}

bool Ship::isSupported(string type) {
    return type == "Medic";
}


int Fleet::getWeight() const {
    vector<Ship*> ships = shipList();
    int total = 0;
    for (int i = 0; i < ships.size(); i++) {
        total += ships[i]->getWeight();
    }
    return total;
}

int Fleet::getEnergyConsumption() const {
    vector<Ship *> ships = shipList();
    int total = 0;
    for(int i =0; i< ships.size();i++){
        total += ships[i] -> getEnergyConsumption();
    }
    return total;
}

int Fleet::getColonistCount() const {
    vector<ColonyShip *> colonies = colonyShipList;
    int total = 0;
    for(int i= 0;i<colonies.size();i++){
        total += colonies[i]->getColonistCount();
    }
    return total;
}

int Fleet::getCost() const {
    int totalcost = 0;
    vector<Ship *> ships = shipList();
    for(int i=0; i<ships.size(); i++){
        totalcost += ships[i]->getCost();
    }
    return totalcost;
}

int Fleet::EnergyProduction() const {
    int totalenergy = 0;
    vector<Ship*> ships = shipList();
    for(int i=0; i<ships.size(); i++){
        totalenergy += ships[i]->getEnergyConsumption();
    }
    return totalenergy;
}

int Fleet::countProtectedShips() const {
    vector<MilitaryEscortShip*> ships = militaryShips;
    int totalships = 0;
    for(int i=0; i<ships.size(); i++){
        totalships += ships[i]->getNrProtected();
    }
    return totalships;
}

bool Fleet::hasMedic() const {
    vector<Ship* > ships = shipList();
    string temp="";

    for(int i =0; i<shipList().size(); i++){
        temp = ships[i]->getTypeName();
        if(temp == "Medic"){
            return true;
        }
    }
    return false;
}

string Fleet::getCorporationName() const {
    return corporationName;
}

vector<Ship *> Fleet::protectedShips() const {
    vector<Ship*> colony = colonyShips();

    int shipsCount = countProtectedShips();

    sort(colony.begin(),colony.end(),Fleet::compareColonist);

    return vector<Ship *>(colony.begin(), colony.begin() + shipsCount);
}

vector<Ship *> Fleet::unprotectedShips() const {
    vector<Ship*> colony = colonyShips();

    int shipsCount = countProtectedShips();

    sort(colony.begin(),colony.end(),Fleet::compareColonist);

    return vector<Ship *>(colony.begin() + shipsCount, colony.end());
}

vector<Ship *> Fleet::colonyShips() const {
    vector<Ship* > list;
    vector<ColonyShip* > allShip = colonyShipList;

    string temp ="";
    for(int i=0;i<allShip.size();i++){
        //temp = allShip[i]->getTypeName();
        //if (temp=="Ferry" || temp =="Liner" || temp =="Cloud"){
            list.push_back(allShip[i]);
        //}
    }
    return list;
}

vector<Ship *> Fleet::shipList() const {
    vector<Ship *> list;
    vector<Ship *> colonies = colonyShips();
    for (int i = 0; i < colonies.size(); i++) {
        list.push_back(colonies[i]);
    }
    vector<Ship *> others = otherShips;
    for (int i = 0; i < others.size(); i++) {
        list.push_back(others[i]);
    }
    return list;
}

void Fleet::destroyShip(Ship *i) {
    //colonyShipList.erase(std::find(colonyShipList.begin(), colonyShipList.end(), dynamic_cast<ColonyShip*>(i)), colonyShipList.end());
    for (auto it = colonyShipList.begin(); it != colonyShipList.end(); it++) {
        if (*it == i) {
            colonyShipList.erase(it);
            return;
        }
    }
}

void Fleet::addColonyShip(Ship *i) {
    colonyShipList.push_back((ColonyShip*) i);
}

Fleet *Fleet::createFleetFromFile(string file) {
    Fleet* fleet = new Fleet;
    ifstream infile(file);
    string shipType;
    int number;
    bool foundSomething = false;
    while (infile >> shipType >> number) {
        for (int i = 0; i < number; i++) {
            foundSomething = true;
            if (MilitaryEscortShip::isSupported(shipType)) {
                fleet->addColonyShip(new MilitaryEscortShip(shipType));
            } else if (SolarSailShip::isSupported(shipType)) {
                fleet->addSolarSailShip(new SolarSailShip(shipType));
            } else if (ColonyShip::isSupported(shipType)) {
                fleet->addColonyShip(new SolarSailShip(shipType));
            } else if (Ship::isSupported(shipType)) {
                fleet->addOtherShip(new Ship(shipType));
            } else {
                delete fleet;
                throw invalid_argument("Unknown ship.");
            }
        }
    }
    if (!foundSomething) {
        delete fleet;
        throw invalid_argument("Couldn't read the file or it was empty.");
    }
    return fleet;
}

void Fleet::addMilitaryShip(Ship *i) {
    militaryShips.push_back((MilitaryEscortShip*) i);
}

void Fleet::addSolarSailShip(Ship *i) {
    solarsailShip.push_back((SolarSailShip*) i);
}

void Fleet::addOtherShip(Ship *i) {
    otherShips.push_back(i);
}

bool Fleet::compareColonist(Ship* lhs, Ship* rhs) {
    return static_cast<ColonyShip*>(lhs)->getColonistCount() <
            static_cast<ColonyShip*>(rhs)->getColonistCount();
}


int ColonyShip::getColonistCount() const {
    return colonists;
}

void ColonyShip::infect() {
    colonists = 0;

}

bool ColonyShip::isInfected() const {
    return colonists == 0;
}

bool ColonyShip::isSupported(string type) {
    return type == "Ferry" || type == "Liner" || type == "Cloud";
}

ColonyShip::ColonyShip(const string type) : Ship(type) {
    if (type == "Ferry") {
        weight = 10;
        energy = 5;
        cost = 500;
        colonists = 100;
    }

    else if (type == "Liner") {
        weight = 20;
        energy = 7;
        cost = 1000;
        colonists = 250;
    }

    else if (type == "Cloud") {
        weight = 30;
        energy = 9;
        cost = 2000;
        colonists = 750;
    }
}


int SolarSailShip::getEnergyProduction() const {
    return 0;
}

bool SolarSailShip::isSupported(string type) {
    return false;
}


SolarSailShip::SolarSailShip(const string type) : Ship(type) {

}


int MilitaryEscortShip::getNrProtected() const {
    return 0;
}

bool MilitaryEscortShip::isSupported(string type) {
    return false;
}

MilitaryEscortShip::MilitaryEscortShip(const string type) : Ship(type) {

}


Fleet *userInterfaceCreateFleet() {
    cout << "Please enter the file name or type stop: ";
    string name;
    cin >> name;
    if (name == "stop") {
        return nullptr;
    }
    return Fleet::createFleetFromFile(name);
}

Ship *addShipByType(string name) {

}