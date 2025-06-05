#ifndef FLIGHT_H
#define FLIGHT_H
#include <string>
#include <iostream>

/**
 * @class Flight
 * @brief Represents flight information
 */
class Flight {
private:
    std::string flight_number; ///< Flight identifier
    std::string airline;       ///< Airline name
    std::string arrival_date;  ///< Arrival date (YYYY-MM-DD)
    std::string arrival_time;  ///< Arrival time (HH:MM)
    int passengers;            ///< Number of passengers

public:
    /**
     * @brief Default constructor
     */
    Flight();
    
    /**
     * @brief Parameterized constructor
     * @param flight_number_ Flight number
     * @param airline_ Airline name
     * @param arrival_date_ Arrival date
     * @param arrival_time_ Arrival time
     * @param passengers_ Passenger count
     */
    Flight(std::string flight_number_, std::string airline_, 
           std::string arrival_date_, std::string arrival_time_, int passengers_); 
    
    /**
     * @brief Default destructor
     */
    ~Flight() = default;

    // Accessor methods
    std::string Get_flight_number() const;
    std::string Get_airline() const;
    std::string Get_arrival_date() const;
    std::string Get_arrival_time() const;
    int Get_passengers() const;

    // Mutator methods
    void Set_flight_number(std::string);
    void Set_airline(std::string);
    void Set_arrival_date(std::string);
    void Set_arrival_time(std::string);
    void Set_passengers(int);

    // Comparison operators
    bool operator>(const Flight& other) const;
    bool operator<(const Flight& other) const;
    bool operator<=(const Flight& other) const;
    bool operator>=(const Flight& other) const;
    bool operator==(const Flight& other) const;
    
    /**
     * @brief Assignment operator
     * @param other Flight to assign
     * @return Reference to current object
     */
    Flight& operator=(const Flight& other) = default;
    
    /**
     * @brief Output stream operator
     * @param os Output stream
     * @param flight Flight to output
     * @return Reference to output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const Flight& flight);
};

#endif