#ifndef RBTREE_H
#define RBTREE_H
#include "flight.h"

#define BLACK 0 ///< Black node color constant
#define RED 1   ///< Red node color constant

/**
 * @struct RBTreeNode
 * @brief Node structure for Red-Black Tree
 */
struct RBTreeNode {
    Flight key;                 ///< Flight data
    std::vector<Flight> flights; ///< Vector for duplicate keys
    RBTreeNode* left;           ///< Left child pointer
    RBTreeNode* right;          ///< Right child pointer
    RBTreeNode* parent;         ///< Parent pointer
    int color;                  ///< Node color (RED or BLACK)
    
    /**
     * @brief Constructs a new RBTreeNode
     * @param key_ Flight object to initialize node
     */
    RBTreeNode(Flight key_);
};

/**
 * @class RBTree
 * @brief Red-Black Tree implementation with balancing
 */
class RBTree {
private:
    RBTreeNode* root; ///< Root node of the tree

    /**
     * @brief Inserts a flight with parent tracking
     * @param node Current node reference
     * @param key Flight to insert
     * @param parent Parent node pointer
     * @return Newly inserted node
     */
    RBTreeNode* Insert(RBTreeNode *& node, Flight key, RBTreeNode* parent);
    
    /**
     * @brief Searches for matching flights
     * @param node Current node
     * @param key Flight with search criteria
     * @param result Vector for results
     * @return Number of matches
     */
    int Search(RBTreeNode* node, Flight key, std::vector<Flight>& result);
    
    /**
     * @brief Deletes all tree nodes
     * @param node Current node reference
     */
    void DeleteTree(RBTreeNode *& node);
    
    /**
     * @brief Performs balancing after insertion
     * @param node Node to balance
     */
    void Balance(RBTreeNode*& node);
    
    /**
     * @brief Left rotation operation
     * @param node Pivot node
     */
    void rotateLeft(RBTreeNode*& node);
    
    /**
     * @brief Right rotation operation
     * @param node Pivot node
     */
    void rotateRight(RBTreeNode*& node);
        
public:
    /**
     * @brief Public insert interface
     * @param key Flight to insert
     */
    void Insert(Flight key);
    
    /**
     * @brief Public search interface
     * @param key Flight with search criteria
     * @param result Vector for results
     * @return Number of matches
     */
    int Search(Flight key, std::vector<Flight>& result);

    /**
     * @brief Default constructor
     */
    RBTree();
    
    /**
     * @brief Constructor with root initialization
     * @param root_ Node to set as initial root
     */
    RBTree(RBTreeNode* root_);
    
    /**
     * @brief Destructor - cleans up all nodes
     */
    ~RBTree();

    /**
     * @brief Gets root node
     * @return const RBTreeNode* Read-only root pointer
     */
    const RBTreeNode* GetRoot() const;
    
    /**
     * @brief Sets new root node
     * @param root_ Pointer to new root
     */
    void SetRoot(RBTreeNode* root_);
};
#endif