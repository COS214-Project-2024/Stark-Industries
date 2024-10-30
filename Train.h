#ifndef TRAIN_H
#define TRAIN_H

#include "Transport.h"
#include <string>
using namespace std;

/**
 * @class Train
 * @brief Represents train-based transportation with attributes such as seating, cargo capacity, maintenance status, etc.
 * 
 * This class inherits from the Transport base class and implements methods specific
 * to train transportation, including handling maintenance, seating reservations, and cargo loading.
 */
class Train : public Transport {
private:
    bool isUnderMaintenance;  /**< Flag to indicate if the train is under maintenance. */
    double travelTime;        /**< Travel time for the train. */
    double fee;               /**< Travel fee for using this train transport. */
    int seatingCapacity;      /**< Total seating capacity of the train. */
    int availableSeats;       /**< Number of available seats currently. */
    int cargoCapacity;        /**< Maximum cargo capacity. */
    int availableCargoSpace;  /**< Currently available cargo space. */
    string name;              /**< Name of the train vehicle. */

public:
    /**
     * @brief Constructs a Train object with specified attributes.
     * @param name Name of the train.
     * @param travelTime Travel time of the train.
     * @param fee Travel fee for the train.
     * @param seatingCap Total seating capacity.
     * @param cargoCap Cargo capacity.
     */
    Train(string name, double travelTime, double fee, int seatingCap, int cargoCap);
    
    /**
     * @brief Puts the train into maintenance mode.
     */
    void doMaintenance() override;

    /**
     * @brief Calculates and returns the commute time.
     * @return The commute time in hours.
     */
    double commuteTime() override;

    /**
     * @brief Calculates passenger satisfaction based on seating and travel conditions.
     * @return An integer representing satisfaction score.
     */
    int calculateSatisfaction() override;

    /**
     * @brief Checks if the train is available for travel.
     * @return True if available, false if under maintenance or fully booked.
     */
    bool isAvailable() const override;

    /**
     * @brief Gets the travel fee.
     * @return The travel fee as a double.
     */
    double getFee() const override;

    /**
     * @brief Gets the type of transport as a string.
     * @return A string indicating the type (e.g., "Train").
     */
    std::string getType() const override;

    /**
     * @brief Gets the seating capacity of the train.
     * @return Seating capacity as an integer.
     */
    int getSeatingCapacity() const override;

    /**
     * @brief Gets the number of available seats.
     * @return Number of available seats as an integer.
     */
    int getAvailableSeats() const override;

    /**
     * @brief Reserves a seat if available.
     * @return True if the seat was successfully reserved, false if no seats are available.
     */
    bool reserveSeat() override;

    /**
     * @brief Releases a previously reserved seat.
     */
    void releaseSeat() override;

    /**
     * @brief Checks if the train has cargo capacity.
     * @return True if it has cargo capacity, false otherwise.
     */
    bool hasCargoCapacity() const override;

    /**
     * @brief Gets the total cargo capacity.
     * @return Cargo capacity as an integer.
     */
    int getCargoCapacity() const override;

    /**
     * @brief Gets the currently available cargo space.
     * @return Available cargo space as an integer.
     */
    int getAvailableCargoSpace() const override;

    /**
     * @brief Loads cargo into the train if space is available.
     * @param cargo Amount of cargo to load.
     * @return True if the cargo was successfully loaded, false if not enough space.
     */
    bool loadCargo(int cargo) override;

    /**
     * @brief Unloads cargo from the train.
     * @param cargo Amount of cargo to unload.
     */
    void unloadCargo(int cargo) override;
};

#endif // TRAIN_H
