#include <vector>
#include "Fleet.h"

using namespace std;

int main() {
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
    return 0;
}

int Fleet::getColonistCount() const {
    return 0;
}

int Fleet::getCost() const {
    return 0;
}

int Fleet::EnergyProduction() const {
    return 0;
}

int Fleet::countProtectedShips() const {
    return 0;
}

bool Fleet::hasMedic() const {
    return false;
}

string Fleet::getCorporationName() const {
    return std::basic_string<char, char_traits<char>, allocator<char>>();
}

vector<Ship *> Fleet::protectedShips() const {
    return std::vector<Ship *>();
}

vector<Ship *> Fleet::unprotectedShips() const {
    return std::vector<Ship *>();
}

vector<Ship *> Fleet::colonyShips() const {
    return std::vector<Ship *>();
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

