#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>

/**
 * @class Transport
 * @brief Abstract base class representing a mode of transport.
 * 
 * This class defines the interface for various transport types, 
 * including methods for maintenance, commuting, satisfaction calculation,
 * and seating and cargo management.
 */
class Transport {


public:
    /**
     * @brief Marks the transport as under maintenance.
     */
    virtual void doMaintenance() = 0;

    /**
     * @brief Calculates and returns the commute time for the transport.
     * @return The commute time in hours.
     */
    virtual double commuteTime() = 0;

    /**
     * @brief Calculates passenger satisfaction based on transport conditions.
     * @return An integer representing satisfaction score.
     */
    virtual int calculateSatisfaction() = 0;

    /**
     * @brief Checks if the transport is available for service.
     * @return True if available, false if under maintenance or fully booked.
     */
    virtual bool isAvailable() const = 0;

    /**
     * @brief Gets the travel fee for using the transport.
     * @return The travel fee as a double.
     */
    virtual double getFee() const = 0;

    /**
     * @brief Gets the type of transport as a string.
     * @return A string representing the type of transport.
     */
    virtual std::string getType() const = 0;

    /**
     * @brief Virtual destructor to ensure proper cleanup of derived classes.
     */
    virtual ~Transport() = default;

    /**
     * @brief Gets the seating capacity of the transport.
     * @return Seating capacity as an integer.
     */
    virtual int getSeatingCapacity() const = 0;

    /**
     * @brief Gets the number of available seats.
     * @return Number of available seats as an integer.
     */
    virtual int getAvailableSeats() const = 0;

    /**
     * @brief Reserves a seat if one is available.
     * @return True if the seat was successfully reserved, false if no seats are available.
     */
    virtual bool reserveSeat() = 0;

    /**
     * @brief Releases a previously reserved seat.
     */
    virtual void releaseSeat() = 0;

    /**
     * @brief Checks if the transport supports cargo.
     * @return True if it supports cargo, false otherwise.
     */
    virtual bool hasCargoCapacity() const = 0;

    /**
     * @brief Gets the total cargo capacity of the transport.
     * @return Cargo capacity as an integer.
     */
    virtual int getCargoCapacity() const = 0;

    /**
     * @brief Gets the available cargo space in the transport.
     * @return Available cargo space as an integer.
     */
    virtual int getAvailableCargoSpace() const = 0;

    /**
     * @brief Loads cargo into the transport.
     * @param cargo Amount of cargo to load.
     * @return True if cargo was successfully loaded, false otherwise.
     */
    virtual bool loadCargo(int cargo) = 0;

    /**
     * @brief Unloads cargo from the transport.
     * @param cargo Amount of cargo to unload.
     */
    virtual void unloadCargo(int cargo) = 0;
};

#endif // TRANSPORT_H