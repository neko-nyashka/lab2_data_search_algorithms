#include "bstree.h"
TreeNode::TreeNode(Flight key_) {
    key = key_;
}
void BSTree::SetRoot(TreeNode* root_) {
    root = root_;
}
const TreeNode* BSTree::GetRoot() const {return root;}
void BSTree::Insert(TreeNode*& node, Flight key) {
    if (node == nullptr) {
        node = new TreeNode(key);
    }
    else if (key < node->key) {
        Insert(node->left, key);
    }
    else {
        Insert(node->right, key);
    }
}

BSTree::BSTree() {
    root = nullptr;
}

BSTree::BSTree(TreeNode* root_) {
    root = root_;
}

int BSTree::Search(TreeNode* node, Flight key, std::vector<Flight>& v) {
    int count = 0;
    if (node != nullptr) {
        if (key < node->key) {
            count = Search(node->left, key, v);
        }
        else {
            if (key == node->key) {
                v.push_back(node->key);
                count = 1;
            }
            count += Search(node->right, key, v);
        }
    }
    return count;
}

void  BSTree::DeleteTree(TreeNode *& node) {
    if (node != nullptr) {

        DeleteTree(node->left);
        DeleteTree(node->right);

        delete node;
        node = nullptr; 
    }
}

BSTree::~BSTree() {
    this->DeleteTree(root);
}

void BSTree::Insert(Flight key) {
    this->Insert(root, key);
}

int BSTree::Search(Flight key, std::vector<Flight>& result) {
    return this->Search(root, key, result);
}