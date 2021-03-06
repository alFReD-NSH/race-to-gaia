#ifndef RACE_TO_GAIA_FLEET_H
#define RACE_TO_GAIA_FLEET_H

#include <string>
#include <vector>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

class Ship {
public:
    Ship(const string type);
    static bool isSupported(string type);
    int getEnergyConsumption() const; // Returns energy consumption of a ship
    int getWeight() const; // Returns weight of a ship
    int getCost() const; // Returns cost of a ship
    string getTypeName() const; // Returns the ship type, e.g. Ferry, Cruiser, or Ebulient. Note that spelling mistakes may effect your grade!
    bool isDestroyed() const; // Returns true if the ship is destroyed, false otherwise
protected:
    string type; // Type of ship
    int cost;  // Cost of ship
    int weight; // Weight of ship
    int energy; // Energy consumption of a ship
};


class ColonyShip : public Ship {
public:
    ColonyShip(const string type);
    static bool isSupported(string type);
    int getColonistCount() const; // Returns nr of colonists of a ship
    void infect(); // Infects a colony ship
    bool isInfected() const; // Returns True if the ship is infected with a disease, False otherwise
private:
    int colonists; // Number of colonists in a colony ship
};

class SolarSailShip : public Ship {
public:
    SolarSailShip(const string type);
    static bool isSupported(string type);
    int getEnergyProduction() const; // Returns energy production of Solar Sail Ship
private:
    int energyGenerated;
};

class MilitaryEscortShip : public Ship {
public:
    MilitaryEscortShip(const string type);
    static bool isSupported(string type);
    int getNrProtected();   // Returns nr of colony ships protected by this ship
    int getFighters() const; // Returns number of fighters in a military ship
private:
    vector<MilitaryEscortShip *> militaryShips;
    int fighters;
    int sumShipsProtected;

};

const int distanceToGaiaInLightYears = 33;
const long lightSpeed = 299792458;
const long long lightYearInMeters = 946073047258800;
const long long distanceToGaiaInMeters = lightYearInMeters * distanceToGaiaInLightYears;
const int yearsPerTick = 3; // Amount of game-time that is supposed to be simulated between each tick

class Fleet {
public:
    // It does what it says
    static Fleet *createFleetFromFile(string);
    static bool compareColonist(Ship* lhs, Ship* rhs); // compare the colonist count between colony ships
    static void simulate(Fleet *fleet);

    ~Fleet();

    int getFighters() const; //Return cumulative fighters in a a fleet
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
    void addColonyShip(Ship *i);
    void addMilitaryShip(Ship *i);
    void addSolarSailShip(Ship *i);
    bool isKilled();
private:
    vector<Ship *> otherShips;
    vector<MilitaryEscortShip *> militaryShips;
    vector<MilitaryEscortShip *> fighters;
    vector<ColonyShip *> colonyShipList;
    vector<SolarSailShip *> solarsailShip;

    bool killed = false;
    void addOtherShip(Ship *ship);
    double getSpeedPerTick();
    string corporationName;
    long long distanceLeft = distanceToGaiaInMeters;
    int settledPopulation = 0;

    void kill();

    void alienAttack();

    void infect();
};

Fleet *userInterfaceCreateFleet();
vector<Fleet*> readFleets();
Fleet* currentGaiaColonist = nullptr;
void sleepOneSecond();

#endif //RACE_TO_GAIA_FLEET_H
