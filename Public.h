#ifndef PUBLIC_H
#define PUBLIC_H

#include "Transport.h"
#include <string>
using namespace std;

/**
 * @class Public
 * @brief Represents a public transportation service, such as buses or trams, with seating capacity and travel fees.
 * 
 * This class inherits from the Transport base class and implements functionalities specific to public transport,
 * including seating reservations, maintenance, and commute time calculation.
 */
class Public : public Transport {
private:
    bool isUnderMaintenance;  /**< Flag indicating if the public transport is under maintenance. */
    double travelTime;        /**< Travel time for this mode of transport. */
    double fee;               /**< Fee for using this public transport. */
    int seatingCapacity;      /**< Total seating capacity for passengers. */
    int availableSeats;       /**< Number of currently available seats. */
    string name;              /**< Name of the public transport. */
    //int cargoCapacity;
    //int availableCargoSpace;

public:
    /**
     * @brief Constructs a Public transport object with specified attributes.
     * @param name Name of the public transport.
     * @param travelTime Travel time for the transport.
     * @param fee Travel fee for using this transport.
     * @param seatingCapacity Total seating capacity.
     */
    Public(string name, double travelTime, double fee, int seatingCapacity);

    /**
     * @brief Marks the public transport as under maintenance.
     */
    void doMaintenance() override;

    /**
     * @brief Calculates and returns the commute time for the public transport.
     * @return The commute time in hours.
     */
    double commuteTime() override;

    /**
     * @brief Calculates passenger satisfaction based on seating and travel conditions.
     * @return An integer representing satisfaction score.
     */
    int calculateSatisfaction() override;

    /**
     * @brief Checks if the public transport is available for service.
     * @return True if available, false if under maintenance or fully booked.
     */
    bool isAvailable() const override;

    /**
     * @brief Gets the travel fee for the public transport.
     * @return The travel fee as a double.
     */
    double getFee() const override;

    /**
     * @brief Gets the type of transport as a string.
     * @return A string representing the type of transport (e.g., "Public").
     */
    std::string getType() const override;

    /**
     * @brief Gets the seating capacity of the public transport.
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
     * @brief Checks if public transport supports cargo.
     * @return True if it supports cargo, false otherwise.
     */
     bool hasCargoCapacity() const ; // Check if this transport supports cargo
  
    /**
     * @brief Gets the total cargo capacity of the public transport.
     * @return Cargo capacity as an integer.
     */
   int getCargoCapacity() const ;

   /**
     * @brief Gets the available cargo space in the public transport.
     * @return Available cargo space as an integer.
     */
     int getAvailableCargoSpace() const;

     /**
     * @brief Loads cargo into the public transport.
     * @param cargo Amount of cargo to load.
     * @return True if cargo was successfully loaded, false otherwise.
     */
     bool loadCargo(int cargo) ;

     /**
     * @brief Unloads cargo from the public transport.
     * @param cargo Amount of cargo to unload.
     */
     void unloadCargo(int cargo) ;
};

#endif