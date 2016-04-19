#include <vector>
#include <iostream>
#include <algorithm>
#include "Fleet.h"

using namespace std;

int main() {
    Fleet fleet;
    ColonyShip* ship = new ColonyShip();
    fleet.addShip(ship);
    fleet.addShip(new ColonyShip);

    fleet.destroyShip(ship);
    cout << fleet.colonyShips().size();

    return 0;
}

int Ship::getEnergyConsumption() const {
    return 0;
}

int Ship::getWeight() const {
    return 0;
}

int Ship::getCost() const {
    return 0;
}

string Ship::getTypeName() const {
    return std::basic_string<char, char_traits<char>, allocator<char>>();
}

bool Ship::isDestroyed() const {
    return false;
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
    return std::basic_string<char, char_traits<char>, allocator<char>>();
}

static bool compareColonist (ColonyShip lhs, ColonyShip rhs){
    return (lhs.getColonistCount()<rhs.getColonistCount());
}

vector<Ship *> Fleet::protectedShips() const {
    vector<Ship*> colony = colonyShips();

    int shipsCount = countProtectedShips();

    sort(colony.begin(),colony.end(),compareColonist);

    return vector<Ship *>(colony.begin(), colony.begin() + shipsCount);
}

vector<Ship *> Fleet::unprotectedShips() const {
    vector<Ship*> colony = colonyShips();

    int shipsCount = countProtectedShips();

    sort(colony.begin(),colony.end(),compareColonist);

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
        }
    }
}

void Fleet::addShip(Ship *i) {
    colonyShipList.push_back((ColonyShip*) i);
}


int ColonyShip::getColonistCount() const {
    return 0;
}

void ColonyShip::infect() {

}

bool ColonyShip::isInfected() const {
    return false;
}


int SolarSailShip::getEnergyProduction() const {
    return 0;
}


int MilitaryEscortShip::getNrProtected() const {
    return 0;
}


Fleet *userInterfaceCreateFleet() {
    return nullptr;
}

