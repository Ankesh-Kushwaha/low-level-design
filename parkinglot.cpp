#include<bits/stdc++.h>
using namespace std;

enum VehicleType
{
  CAR,
  BIKE,
  TRUCK
};

enum SpotType
{
 CAR,
 BIKE,
 TRUCK
};

class Vehicle
{
private:
  string number;
  VehicleType type;

public:
  Vehicle(string number, VehicleType type)
  {
    this->number = number;
    this->type = type;
  }

  string getNumber() { return number; }
  VehicleType getType() { return type; }
};

class ParkingSpot
{
private:
  int id;
  SpotType type;
  bool isOccupied;
  Vehicle *vehicle;

public:
  ParkingSpot(int id, SpotType type)
  {
    this->id = id;
    this->type = type;
    this->isOccupied = false;
    this->vehicle = nullptr;
  }

  bool isFree() { return !isOccupied; }

  bool canFit(Vehicle *v)
  {
    return isFree() && (int)type == (int)v->getType();
  }

  void park(Vehicle *v)
  {
    vehicle = v;
    isOccupied = true;
  }

  void unpark()
  {
    vehicle = nullptr;
    isOccupied = false;
  }
};

class ParkingFloor
{
private:
  int floorNumber;
  vector<ParkingSpot *> spots;

public:
  ParkingFloor(int floorNumber, int numSpots)
  {
    this->floorNumber = floorNumber;

    for (int i = 0; i < numSpots; i++)
    {
      if (i % 3 == 0)
        spots.push_back(new ParkingSpot(i, SpotType::CAR));
      else if (i % 3 == 1)
        spots.push_back(new ParkingSpot(i, SpotType::BIKE));
      else
        spots.push_back(new ParkingSpot(i, SpotType::TRUCK));
    }
  }

  vector<ParkingSpot *> &getSpots()
  {
    return spots;
  }
};

class ParkingAssignmentStrategy
{
public:
  virtual ParkingSpot *assignSpot(vector<ParkingFloor *> &floors, Vehicle *v) = 0;

  virtual ~ParkingAssignmentStrategy() {}
};

class AssignFirstAvailable : public ParkingAssignmentStrategy
{
public:
  ParkingSpot *assignSpot(vector<ParkingFloor *> &floors, Vehicle *v) override
  {
    for (auto floor : floors)
    {
      for (auto spot : floor->getSpots())
      {
        if (spot->canFit(v))
        {
          return spot;
        }
      }
    }
    return nullptr;
  }
};

class ParkingLot
{
private:
  vector<ParkingFloor *> floors;
  ParkingAssignmentStrategy *strategy;

public:
  ParkingLot(ParkingAssignmentStrategy *strategy)
  {
    this->strategy = strategy;
  }

  void addFloor(ParkingFloor *floor)
  {
    floors.push_back(floor);
  }

  void parkVehicle(Vehicle *v)
  {
    ParkingSpot *spot = strategy->assignSpot(floors, v);

    if (spot)
    {
      spot->park(v);
      cout << "Vehicle parked\n";
    }
    else
    {
      cout << "No spot available\n";
    }
  }
};

int main()
{
  ParkingAssignmentStrategy *strategy = new AssignFirstAvailable();
  ParkingLot lot(strategy);

  lot.addFloor(new ParkingFloor(1, 5));
  lot.addFloor(new ParkingFloor(2, 5));

  Vehicle v1("UP32AB1234", VehicleType::CAR);
  Vehicle v2("UP32XY5678", VehicleType::BIKE);

  lot.parkVehicle(&v1);
  lot.parkVehicle(&v2);
  
  return 0;
}