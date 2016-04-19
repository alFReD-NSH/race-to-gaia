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
    return 0;
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
    return std::vector<Ship *>();
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

