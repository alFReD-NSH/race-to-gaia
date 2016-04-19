#ifndef RACE_TO_GAIA_FLEET_H
#define RACE_TO_GAIA_FLEET_H

#include <string>
#include <vector>

using namespace std;

class Ship {
public:
    int getEnergyConsumption() const; // Returns energy consumption of a ship
    int getWeight() const; // Returns weight of a ship
    int getCost() const; // Returns cost of a ship
    string getTypeName() const; // Returns the ship type, e.g. Ferry, Cruiser, or Ebulient. Note that spelling mistakes may effect your grade!
    bool isDestroyed() const; // Returns true if the ship is destroyed, false otherwise
private:
    int weight;
};

class ColonyShip : public Ship {
public:
    int getColonistCount() const; // Returns nr of colonists of a ship
    void infect(); // Infects a colony ship
    bool isInfected() const; // Returns True if the ship is infected with a disease, False otherwise
};

class SolarSailShip : public Ship {
public:
    int getEnergyProduction() const; // Returns energy production of Solar Sail Ship
};

class MilitaryEscortShip : public Ship {
public:
    int getNrProtected() const;   // Returns nr of colony ships protected by this ship
};

class Fleet {
public:
    int getWeight() const; // Returns cumulative weight of fleet
    int getEnergyConsumption() const; // Returns cumulative energy consumption of fleet
    int getColonistCount() const; // Returns cumulative colonist count of fleet
    int getCost() const; // Returns cumulative fleet cost
    int EnergyProduction() const; // Returns cumulative energy production of fleet
    int countProtectedShips() const; // Returns nr of colony ships protected in fleet
    bool hasMedic() const; // Returns True if the fleet has a medic ship, false otherwise
    string getCorporationName() const; // Returns your chosen name of your corporation.
    vector<Ship *> protectedShips() const;// Returns a vector with ship numbers of protected colony ships
    vector<Ship *> unprotectedShips() const; // Returns a vector with ship numbers of unprotected colony ships
    vector<Ship *> colonyShips() const; // Returns a vector with ship numbers of all ships that are a colony ship
    vector<Ship *> shipList() const; // Returns a vector with all ships in the fleet
    void destroyShip(Ship *i); // Removes ship i from the fleet
    void addShip(Ship *i);
private:
    vector<Ship *> otherShips;
    vector<MilitaryEscortShip *> militaryShips;
    vector<ColonyShip *> colonyShipList;
    vector<SolarSailShip *> solarsailShip;
};

Fleet *userInterfaceCreateFleet();

#endif //RACE_TO_GAIA_FLEET_H
