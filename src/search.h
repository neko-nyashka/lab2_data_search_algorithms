#ifndef SEARCH_H
#define SEARCH_H
#include"flight.h"
#include "bstree.h"
#include "rbtree.h"
#include <map>
#include "hash_table.h"

#define KEY "Ural Airlines" ///< Default search key

/**
 * @brief Parses CSV file into flight vector
 * @param filename CSV file path
 * @param result Vector to store flights
 * @return 0 on success, error code otherwise
 */
int parseCSV(std::string filename, std::vector<Flight> &result);

/**
 * @brief Linear search implementation
 * @param flights Flight vector to search
 * @param result Vector for results
 * @return Number of matches
 */
int linear_search(const std::vector<Flight>& flights, std::vector<Flight>& result);

/**
 * @brief Builds BST from flights
 * @param flights Flight vector
 * @return Pointer to constructed BST
 */
BSTree* binary_insert(const std::vector<Flight>& flights);

/**
 * @brief Builds RBTree from flights
 * @param flights Flight vector
 * @return Pointer to constructed RBTree
 */
RBTree* rb_insert(const std::vector<Flight>& flights);

/**
 * @brief Builds HashTable from flights
 * @param flights Flight vector
 * @param collisions Output collision count
 * @return Pointer to constructed HashTable
 */
HashTable* hash_table_insert(const std::vector<Flight>& flights, int& collisions);

/**
 * @brief Builds multimap from flights
 * @param flights Flight vector
 * @return Pointer to constructed multimap
 */
std::multimap<std::string, Flight>* multimap_insert(const std::vector<Flight>& flights);

#endif