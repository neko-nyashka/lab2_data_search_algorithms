#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <string>
#include "flight.h"
#include <vector>

/**
 * @class HashTable
 * @brief Hash table implementation with chaining
 */
class HashTable {
private:
    std::vector<std::vector<Flight>> table; ///< Buckets with flight vectors
    int size = 0;                           ///< Number of buckets
    int collision_count = 0;                ///< Collision counter
    
    /**
     * @brief Computes hash value for a key
     * @param key String to hash
     * @return Computed hash value
     */
    int hash_function(const std::string& key) const;

public:
    /**
     * @brief Default constructor
     */
    HashTable() = default;
    
    /**
     * @brief Constructor with size initialization
     * @param size_ Number of buckets
     */
    HashTable(int size_);
    
    /**
     * @brief Default destructor
     */
    ~HashTable() = default;
    
    /**
     * @brief Inserts flight into table
     * @param value Flight to insert
     */
    void insert(const Flight& value);
    
    /**
     * @brief Searches flights by airline name
     * @param key Airline name to search
     * @param result Vector for results
     * @return Number of matches
     */
    int search(const std::string& key, std::vector<Flight>& result) const;
    
    /**
     * @brief Gets collision count
     * @return Number of collisions
     */
    int get_collision_count() const;
};
#endif