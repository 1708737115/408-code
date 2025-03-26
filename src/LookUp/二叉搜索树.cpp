#include <iostream>
#include "BST.h"

bool BST::Insert(int val) {
    return insertNOde(root, val);
}

BSTNode* BST::Search(int val) {
    return searchNode1(root, val); // or use searchNode2 for iterative approach
}

bool BST::Remove(int val) {
    return removeNode(root, val);
}

bool BST::insertNOde(BSTNode* T, int val) {
    if (root == nullptr) { // Special case: inserting into an empty tree
        root = new BSTNode{val, nullptr, nullptr};
        return true;
    }
    if (T == nullptr) return false; // Should not happen in normal flow
    if (T->data > val) {
        if (T->left == nullptr) {
            T->left = new BSTNode{val, nullptr, nullptr};
            return true;
        } else {
            return insertNOde(T->left, val);
        }
    } else if (T->data < val) {
        if (T->right == nullptr) {
            T->right = new BSTNode{val, nullptr, nullptr};
            return true;
        } else {
            return insertNOde(T->right, val);
        }
    }
    return false; // Duplicate value
}

BSTNode* BST::searchNode1(BSTNode* T, int key) {
    if (T == nullptr || T->data == key) return T;
    if (key < T->data) return searchNode1(T->left, key);
    else return searchNode1(T->right, key);
}

BSTNode* BST::searchNode2(BSTNode* T, int key) {
    BSTNode* current = T;
    while (current != nullptr) {
        if (current->data == key) return current;
        else if (key < current->data) current = current->left;
        else current = current->right;
    }
    return nullptr;
}

bool BST::removeNode(BSTNode* T, int key) {
    if (T == nullptr) return false; // Key not found
    if (key < T->data) {
        return removeNode(T->left, key);
    } else if (key > T->data) {
        return removeNode(T->right, key);
    } else { // Key found
        if (T->left == nullptr) {
            BSTNode* temp = T;
            T = T->right;
            delete temp;
        } else if (T->right == nullptr) {
            BSTNode* temp = T;
            T = T->left;
            delete temp;
        } else {
            BSTNode* temp = getLeftMax(T->left);
            T->data = temp->data;
            removeNode(T->left, temp->data);
        }
        return true;
    }
}

bool BST::InitTree(std::vector<int>& nodes) {
    for(auto& node : nodes) {
        if(!Insert(node)) return false;
    }
    return true;
}

BSTNode* BST::getLeftMax(BSTNode* T) {
    if (T == nullptr) return nullptr;
    while (T->right != nullptr) T = T->right;
    return T;
}

BSTNode* BST::getRightMin(BSTNode* T) {
    if (T == nullptr) return nullptr;
    while (T->left != nullptr) T = T->left;
    return T;
}

void BST::deleteTree(BSTNode* T) {
    if(T == nullptr) return;
    if(T->left != nullptr) deleteTree(T->left);
    if(T->right != nullptr) deleteTree(T->right);
    delete T;
}

BST::~BST() {
    deleteTree(root);
}

int main()
{
    BST bst;

    // 初始化一个数组并构建二叉搜索树
    std::vector<int> nodes = {20, 10, 30, 5, 15, 25, 35};
    if(bst.InitTree(nodes)) {
        std::cout << "Tree initialized successfully." << std::endl;
    } else {
        std::cout << "Failed to initialize tree." << std::endl;
        return -1;
    }

    // 插入新节点
    bst.Insert(17);
    std::cout << "Inserted node with value 17." << std::endl;

    // 查找节点
    int searchValue = 15;
    BSTNode* foundNode = bst.Search(searchValue);
    if(foundNode != nullptr) {
        std::cout << "Found node with value: " << foundNode->data << std::endl;
    } else {
        std::cout << "Node with value " << searchValue << " not found." << std::endl;
    }

    // 删除节点
    int removeValue = 10;
    bst.Remove(removeValue);
    std::cout << "Removed node with value " << removeValue << "." << std::endl;

    // 再次查找已被删除的节点
    foundNode = bst.Search(removeValue);
    if(foundNode != nullptr) {
        std::cout << "Found node with value: " << foundNode->data << std::endl;
    } else {
        std::cout << "Node with value " << removeValue << " not found after removal." << std::endl;
    }

    return 0;
}