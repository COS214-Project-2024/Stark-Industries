#ifndef TRANSPORTSYSTEM_H
#define TRANSPORTSYSTEM_H

#include "Transport.h"
#include <string>
using namespace std;

/**
 * @class TransportSystem
 * @brief Represents a transportation system that manages various transport modes.
 * 
 * The TransportSystem class encapsulates the functionality for maintaining transport services,
 * checking availability, managing reservations, and calculating fees and commute times.
 */
class TransportSystem {

private:
	Transport* transportStrategy;/**< Pointer to the current transport strategy being used. */

	//double totalCommuteTime;

public:
    /**
     * @brief Default constructor for the TransportSystem.
     */
 TransportSystem();
   
   /**
     * @brief Sets the transport strategy to be used by the system.
     * @param strategy Pointer to the Transport object representing the desired transport strategy.
     */
    void setTransportStrategy(Transport* strategy);

    /**
     * @brief Performs maintenance on the selected transport strategy.
     */
    void performMaintenance();

    /**
     * @brief Checks if the selected transport is available for use.
     * @return True if the transport is available, false otherwise.
     */
    bool isTransportAvailable() const;

    /**
     * @brief Retrieves the travel fee for the selected transport strategy.
     * @return The travel fee as a double.
     */
    double getTransportFee() const;

    /**
     * @brief Calculates and returns the commute time for the selected transport.
     * @return The commute time in hours as a double.
     */
    double getCommuteTime() const;

    /**
     * @brief Calculates satisfaction based on the selected transport.
     * @return An integer representing the satisfaction score.
     */
    int calculateSatisfaction() const;

    /**
     * @brief Gets the type of the current transport strategy as a string.
     * @return A string representing the type of transport.
     */
    std::string getTransportType() const;

    /**
     * @brief Destructor for the TransportSystem.
     */
    ~TransportSystem();    

    /**
     * @brief Checks the availability of seats in the selected transport.
     * @return True if seats are available, false otherwise.
     */
    bool checkSeatAvailability() const;

    /**
     * @brief Reserves a seat in the selected transport.
     * @return True if the seat was successfully reserved, false if no seats are available.
     */
    bool reserveSeat();

    /**
     * @brief Releases a previously reserved seat.
     */
    void releaseSeat();

    /**
     * @brief Checks the availability of cargo space in the selected transport.
     * @param cargo Size of cargo to check availability for.
     * @return True if there is enough cargo space, false otherwise.
     */
    bool checkCargoAvailability(int cargo) const;

    /**
     * @brief Loads cargo onto the selected transport.
     * @param cargo Size of cargo to be loaded.
     * @return True if the cargo was successfully loaded, false otherwise.
     */
    bool loadCargo(int cargo);

    /**
     * @brief Unloads cargo from the selected transport.
     * @param cargo Size of cargo to be unloaded.
     */
    void unloadCargo(int cargo);

    /**
     * @brief Checks the availability of the transport based on its infrastructure.
     * @param TransportInfastructure_transInfas Identifier for the transport infrastructure.
     */
    void checkAvailability(int TransportInfastructure_transInfas);
};

#endif // TRANSPORTSYSTEM_H