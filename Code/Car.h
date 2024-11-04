#ifndef CAR_H
#define CAR_H

#include "Transport.h"
#include <string>
using namespace std;

/**
 * @class Car
 * @brief Represents a car as a mode of transport with attributes such as travel time, seating capacity, and fees.
 * 
 * This class inherits from the Transport base class and implements functionalities specific to car transport,
 * including seating reservations, maintenance, and satisfaction calculation.
 */
class Car : public Transport {
private:
    bool isUnderMaintenance;  /**< Flag indicating if the car is under maintenance. */
    double travelTime;        /**< Travel time for this mode of transport. */
    double fee;               /**< Fee for using this car transport. */
    int seatingCapacity;      /**< Total seating capacity for passengers. */
    string name;              /**< Name of the car transport. */
    int availableSeats;       /**< Number of currently available seats. */
    // int cargoCapacity;      /**< Total cargo capacity of the car. */
    // int availableCargoSpace;/**< Available cargo space in the car. */

public:
    /**
     * @brief Constructs a Car transport object with specified attributes.
     * @param name Name of the car.
     * @param travelTime Travel time for the car transport.
     * @param seatingCapacity Total seating capacity of the car.
     */
    Car(string name, double travelTime, int seatingCapacity);
    
    /**
     * @brief Marks the car as under maintenance.
     */
    void doMaintenance() override;

    /**
     * @brief Calculates and returns the commute time for the car transport.
     * @return The commute time in hours.
     */
    double commuteTime() override;

    /**
     * @brief Calculates passenger satisfaction based on seating and travel conditions.
     * @return An integer representing satisfaction score.
     */
    int calculateSatisfaction() override;

    /**
     * @brief Checks if the car is available for service.
     * @return True if available, false if under maintenance or fully booked.
     */
    bool isAvailable() const override;

    /**
     * @brief Gets the travel fee for the car transport.
     * @return The travel fee as a double.
     */
    double getFee() const override;

    /**
     * @brief Gets the type of transport as a string.
     * @return A string representing the type of transport (e.g., "Car").
     */
    std::string getType() const override;

    /**
     * @brief Gets the seating capacity of the car.
     * @return Seating capacity as an integer.
     */
    int getSeatingCapacity() const override;

    /**
     * @brief Gets the number of available seats.
     * @return Number of available seats as an integer.
     */
    int getAvailableSeats() const override;

    /**
     * @brief Reserves a seat if one is available.
     * @return True if the seat was successfully reserved, false if no seats are available.
     */
    bool reserveSeat() override;

    /**
     * @brief Releases a previously reserved seat.
     */
    void releaseSeat() override;

    /**
     * @brief Checks if the car supports cargo.
     * @return True if it supports cargo, false otherwise.
     */
    bool hasCargoCapacity() const;

    /**
     * @brief Gets the total cargo capacity of the car.
     * @return Cargo capacity as an integer.
     */
    int getCargoCapacity() const;

    /**
     * @brief Gets the available cargo space in the car.
     * @return Available cargo space as an integer.
     */
    int getAvailableCargoSpace() const;

    /**
     * @brief Loads cargo into the car.
     * @param cargo Amount of cargo to load.
     * @return True if cargo was successfully loaded, false otherwise.
     */
    bool loadCargo(int cargo);

    /**
     * @brief Unloads cargo from the car.
     * @param cargo Amount of cargo to unload.
     */
    void unloadCargo(int cargo);
};

#endif // CAR_H
