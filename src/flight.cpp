#include "flight.h"


Flight::Flight() {
    flight_number = "";
    airline = "";
    arrival_date = "";
    arrival_time = "";
    passengers = 0;
}


Flight::Flight(std::string flight_number_, std::string airline_, std::string arrival_date_, std::string arrival_time_, int passengers_) {
    flight_number = flight_number_;
    airline = airline_;
    arrival_date = arrival_date_;
    arrival_time = arrival_time_;
    passengers = passengers_;
}

std::string Flight::Get_flight_number() const{
    return flight_number;
}
std::string Flight::Get_airline() const{
    return airline;
}
std::string Flight::Get_arrival_date() const{
    return arrival_date;
}

std::string Flight::Get_arrival_time() const{
    return arrival_time;
}

int Flight::Get_passengers() const{
    return passengers;
}

void Flight::Set_flight_number(std::string flight_number_) {
    flight_number = flight_number_;
}
void Flight::Set_airline(std::string airline_) {
    airline = airline_;
}
void Flight::Set_arrival_date(std::string arrival_date_) {
    arrival_date = arrival_date_;
}

void Flight::Set_arrival_time(std::string arrival_time_) {
    arrival_time = arrival_time_;
}

void Flight::Set_passengers(int passengers_) {
    passengers = passengers_;
}


bool Flight::operator>(const Flight& other) const {
    return airline > other.airline;
}

bool Flight::operator>=(const Flight& other) const {
    return  airline >= other.airline;
}

bool Flight::operator<(const Flight& other) const {
    return airline < other.airline;
}

bool Flight::operator<=(const Flight& other) const {
    return airline <= other.airline;
}

bool Flight::operator==(const Flight& other) const {
    return airline == other.airline;
}


std::ostream& operator<<(std::ostream& os, const Flight& flight) {
    os << flight.flight_number << " " << flight.airline << " " << flight.arrival_date << " " << flight.arrival_time << " " << flight.passengers;
    return os;
}

