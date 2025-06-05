#include "rbtree.h"
RBTreeNode::RBTreeNode(Flight key_) {
    key = key_;
    color = RED;
    flights.push_back(key_);
}

void RBTree::SetRoot(RBTreeNode* root_) {
    root = root_;
}
const RBTreeNode* RBTree::GetRoot() const {return root;}

void RBTree::rotateLeft(RBTreeNode*& node) {
    RBTreeNode* rightChild = node->right;
    if(rightChild) {
        RBTreeNode* grandparent = node->parent;
        RBTreeNode* grandson = rightChild->left;


    node->right = grandson;
    if (grandson)
        grandson->parent = node;


    rightChild->left = node;
    rightChild->parent = grandparent;


    if (!grandparent) {
        root = rightChild;
    } else if (node == grandparent->left) {
        grandparent->left = rightChild;
    } else {
        grandparent->right = rightChild;
    }

    node->parent = rightChild;

    node = rightChild;

        
    }
}

void RBTree::rotateRight(RBTreeNode*& node) {
    RBTreeNode* leftChild = node->left;
    if(leftChild) {
        RBTreeNode* grandparent = node->parent;
        RBTreeNode* grandson = leftChild->right;


    node->left = grandson;
    if (grandson)
        grandson->parent = node;


    leftChild->right = node;
    leftChild->parent = grandparent;


    if (!grandparent) {
        root = leftChild;
    } else if (node == grandparent->left) {
        grandparent->left = leftChild;
    } else {
        grandparent->right = leftChild;
    }

    node->parent = leftChild;

    node = leftChild;

        
    }

}

void RBTree::Balance(RBTreeNode*& node) {
    while (node != root && node->parent && node->parent->color == RED && node->parent->parent) {
        RBTreeNode* parent = node->parent;
        RBTreeNode* grandparent = parent->parent;


        RBTreeNode* uncle = (parent == grandparent->left) ? grandparent->right : grandparent->left;

        if (uncle && uncle->color == RED) {
            // Case 1: Uncle is RED — recolor
            parent->color = BLACK;
            uncle->color = BLACK;
            grandparent->color = RED;
            node = grandparent;
        } else {
            if (parent == grandparent->left) {
                if (node == parent->right) {
                    // Case 2: Left-Right — rotate left on parent
                    rotateLeft(parent);
                    node = parent;
                    parent = node->parent;
                }
                // Case 3: Left-Left — rotate right on grandparent
                parent->color = BLACK;
                grandparent->color = RED;
                rotateRight(grandparent);
            } else {
                if (node == parent->left) {
                    // Case 2 mirror: Right-Left
                    rotateRight(parent);
                    node = parent;
                    parent = node->parent;
                }
                // Case 3 mirror: Right-Right
                parent->color = BLACK;
                grandparent->color = RED;
                rotateLeft(grandparent);
            }
        }
    }
    root->color = BLACK;
}


RBTreeNode* RBTree::Insert(RBTreeNode*& node, Flight key, RBTreeNode* parent) {
    if (node == nullptr) {
        node = new RBTreeNode(key);
        node->parent = parent;
        return node;
    }
    else if (key < node->key) {
        return Insert(node->left, key, node);
    }
    else if (key > node->key) {
        return Insert(node->right, key, node);
    } else {
        node->flights.push_back(key);
        return node;
    }
}

RBTree::RBTree() {
    root = nullptr;
}

RBTree::RBTree(RBTreeNode* root_) {
    root = root_;
    root->color = BLACK;
}

int RBTree::Search(RBTreeNode* node, Flight key, std::vector<Flight>& v) {
    int count = 0;
    if (node != nullptr){
        if (key < node->key) {
            count = Search(node->left, key, v);
        } else if (key > node->key) {
            count = Search(node->right, key, v);
        } else {
            v.insert(v.end(), node->flights.begin(), node->flights.end());
            count = node->flights.size();
        }
    }
    return count;
}

void  RBTree::DeleteTree(RBTreeNode *& node) {
    if (node != nullptr) {

        DeleteTree(node->left);
        DeleteTree(node->right);

        delete node;
        node = nullptr; 
    }
}

RBTree::~RBTree() {
    this->DeleteTree(root);
}

void RBTree::Insert(Flight key) {
    RBTreeNode* inserted = this->Insert(root, key, nullptr);
    Balance(inserted);
}

int RBTree::Search(Flight key, std::vector<Flight>& result) {
    return this->Search(root, key, result);
}
