#ifndef BSTREE_H
#define BSTREE_H

#include <vector>
#include "flight.h"
#include <iostream>

/**
 * @struct TreeNode
 * @brief Node structure for Binary Search Tree
 */
struct TreeNode {
    Flight key;          ///< Flight data stored in the node
    TreeNode* left;      ///< Pointer to left child node
    TreeNode* right;     ///< Pointer to right child node
    
    /**
     * @brief Constructs a new TreeNode
     * @param key_ Flight object to initialize the node
     */
    TreeNode(Flight key_);
};

/**
 * @class BSTree
 * @brief Binary Search Tree implementation for Flight objects
 */
class BSTree {
private:
    TreeNode* root; ///< Root node of the tree

    /**
     * @brief Recursively inserts a flight into the tree
     * @param node Current node reference
     * @param key Flight object to insert
     */
    void Insert(TreeNode *& node, Flight key);
    
    /**
     * @brief Recursively searches for flights
     * @param node Current node
     * @param key Flight object to search for
     * @param result Vector to store matching flights
     * @return Number of matches found
     */
    int Search(TreeNode* node, Flight key, std::vector<Flight>& result);
    
    /**
     * @brief Recursively deletes all tree nodes
     * @param node Current node reference
     */
    void DeleteTree(TreeNode *& node);
        
public:
    /**
     * @brief Inserts a flight into the tree
     * @param key Flight object to insert
     */
    void Insert(Flight key);
    
    /**
     * @brief Searches for flights matching criteria
     * @param key Flight object with search criteria
     * @param result Vector to store matching flights
     * @return Number of matches found
     */
    int Search(Flight key, std::vector<Flight>& result);

    /**
     * @brief Default constructor
     */
    BSTree();
    
    /**
     * @brief Constructor with root initialization
     * @param root_ Node to set as initial root
     */
    BSTree(TreeNode* root_);
    
    /**
     * @brief Destructor - cleans up all nodes
     */
    ~BSTree();

    /**
     * @brief Gets root node
     * @return const TreeNode* Read-only pointer to root
     */
    const TreeNode* GetRoot() const;
    
    /**
     * @brief Sets new root node
     * @param root_ Pointer to new root node
     */
    void SetRoot(TreeNode* root_);
};

#endif