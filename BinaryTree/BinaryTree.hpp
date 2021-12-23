#ifndef Tree_2_hpp
#define Tree_2_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <set>


//https://www.niisi.ru/iont/projects/rfbr/90308/90308_miphi6.php - AVL tree


template<class T>
struct AVLNode{
    T data;
    AVLNode<T>* left = nullptr;
    AVLNode<T>* right = nullptr;
    unsigned int height = 1;
    bool right_is_thread = 0;

};

template<typename T>
class BinaryTree{
private:
    AVLNode<T>* root = nullptr;
    
    //helpful functions
    AVLNode<T>*  add(AVLNode<T>* tree, AVLNode<T>* parent, const T& sought);
    AVLNode<T>* search(AVLNode<T>* tree, const T& data);
    AVLNode<T>* search(const T& sought);
    AVLNode<T>* remove(AVLNode<T> *node, T key);
    size_t depth(AVLNode<T>* tree, size_t cnt);
    AVLNode<T>* removeMin(AVLNode<T>* node);
    AVLNode<T>* findMin(AVLNode<T>* node);
    void removeSubTree(AVLNode<T> *node);
    int getCountNodes(AVLNode<T>* node, int count_nodes);
    
    //balancing
    unsigned int height(AVLNode<T>* node);
    int bfactor(AVLNode<T>* node);
    void fixheight(AVLNode<T>* node);
    AVLNode<T>* rotateright(AVLNode<T>* node);
    AVLNode<T>* rotateleft(AVLNode<T>* node);
    AVLNode<T>* balance(AVLNode<T>* node);
    
    //Set function
    void unionTree(AVLNode<T>* node1, BinaryTree<T>* tree);
    void intersecTree(AVLNode<T>* node, BinaryTree<T>* tree, BinaryTree<T>* res);
    void except(AVLNode<T>* node, BinaryTree<T>* tree, BinaryTree<T>* res);
    
    //Thread
    void threadTree(AVLNode<T>* node);
    void threadTree();
    void deleteThread();

public:
    //constructor
    BinaryTree() = default;
    BinaryTree(const T& data);
    BinaryTree(const AVLNode<T>& other);
    
    //Add data
    void add(const T& data);
    
    //Find data
    T getData(const T& sought);
    bool exist(const T& sought);
    
    //Get tree depth
    size_t depth();
    
    //Count nodes in tree
    int getCountNodes();
    
    //Delete node
    void remove(const T& sought);
    //Delete recursive nodes
    void removeRecursive(const T& data);
    
    //Function for set
    BinaryTree<T>* unionTree(BinaryTree<T>* node);
    BinaryTree<T>* intersecTree(BinaryTree<T>* tree);
    BinaryTree<T>* except(BinaryTree<T>* tree);
    
    T getOnIndex(int index);
    
    //Delete tree
    ~BinaryTree();
};


template <typename T>
BinaryTree<T>::BinaryTree(const T& data){
    root = new AVLNode<T>;
    root->data = data;
};


template<typename T>
BinaryTree<T>::BinaryTree(const AVLNode<T>& other){
    if (other.root != nullptr){
        AVLNode<T>* root = other.root;
        root->height = 1;
    }
}


template<typename T>
AVLNode<T>* BinaryTree<T>::add(AVLNode<T>* tree, AVLNode<T>* parent, const T& sought){
    ///Recursive function for add.
    
    if (tree == nullptr){
        tree = new AVLNode<T>;
        tree->data = sought;
        return tree;
    }
    if (sought < tree->data) { // если прошивается дерево слева, то добавить left_is_thread
        tree->left = this->add(tree->left, tree, sought);
    }
    else if (sought > tree->data and not tree->right_is_thread) {
        tree->right = this->add(tree->right, tree, sought);
    }
    else {
        return tree;
    }
    
    return this->balance(tree);
}

template<typename T>
void BinaryTree<T>::add(const T& data){
    ///Add new value if it doesn't exist of do nothing otherwise.
    
    if(root == nullptr){
        root = new AVLNode<T>;
        root->data = data;
    }
    else{
        this->root = this->add(this->root, nullptr, data);
    }
}

template<typename T>
AVLNode<T>* BinaryTree<T>::search(AVLNode<T>* tree, const T& data){
    ///Recursive function for search.
    
    if (tree == nullptr){
        return nullptr;
    }
    if (tree->data == data){
        return tree;
    }
    if (tree->left != nullptr and data < tree->data){ // если прошивается дерево слева, добавить left_is_thread
        return search(tree->left, data);
    }
    else if (tree->right != nullptr and data > tree->data and not tree->right_is_thread){
        return search(tree->right, data);
    }
    else return nullptr;
}

template<typename T>
AVLNode<T>* BinaryTree<T>::search(const T& sought){
    ///Return node with input data.
    
    AVLNode<T>* res = search(root, sought);
    if (res != nullptr){
        return res;
    }
    else{
        return nullptr;
    }
}

template<typename T>
T BinaryTree<T>::getData(const T& sought){
    ///Return full value.

    AVLNode<T>* res = search(root, sought);
    if (res != nullptr){
        return res->data;
    }
    else{
        throw std::invalid_argument("Missing key!");
    }
}

template<typename T>
bool BinaryTree<T>::exist(const T& sought){
    ///Return true if data exist in tree and otherwise false.
    
    if (search(sought) == nullptr){
        return false;
    }
    else{
        return true;
    }
}

template<typename T>
int BinaryTree<T>::getCountNodes(AVLNode<T>* node, int count_nodes){
    ///Recursive function for getCountNodes.
    
    if (node != nullptr){
        count_nodes += 1;
        if (not node->right_is_thread){
            count_nodes = getCountNodes(node->right, count_nodes);
        }
        count_nodes = getCountNodes(node->left, count_nodes);
    }
    return count_nodes;
}

template<typename T>
int BinaryTree<T>::getCountNodes(){
    ///Return count of nodes.
    
    return getCountNodes(root, 0);
}

template<typename T>
size_t BinaryTree<T>::depth(AVLNode<T>* tree, size_t cnt){
    ///Recursive function for depth.
    
    if (tree == nullptr or tree->right_is_thread){
        return cnt;
    }
    return std::max(depth(tree->left, cnt + 1), depth(tree->right, cnt + 1));
}

template<typename T>
size_t BinaryTree<T>::depth(){
    ///Return depth of tree.
    
    return depth(root, 0);
}

template<typename T>
AVLNode<T>* BinaryTree<T>::findMin(AVLNode<T>* node){
    ///Find node with minimum value.
    
    return node->left != nullptr ? this->findMin(node->left) : node;
}

template<typename T>
AVLNode<T>* BinaryTree<T>::removeMin(AVLNode<T>* node) {
    ///Delete node with minimum value.
    
    if (node->left == nullptr) {
        return node->right;
    }
    node->left = this->removeMin(node->left);
    return this->balance(node);
}

template<typename T>
AVLNode<T>* BinaryTree<T>::remove(AVLNode<T> *node, T key) {
    ///Recursive function dor delete node.
    
    if (node == nullptr or node->right_is_thread) {
        return nullptr;
    }
    if (key < node->data) {
        node->left = this->remove(node->left, key);
    } else if (key > node->data) {
        node->right = this->remove(node->right, key);
    } else {
        AVLNode<T> *q = node->left;
        AVLNode<T> *r = node->right;
        delete node;
        if (r == nullptr) {
            return q;
        }
        AVLNode<T> *min = this->findMin(r);
        min->right = this->removeMin(r);
        min->left = q;
        return this->balance(min);
    }
    return this->balance(node);
}

template<typename T>
void BinaryTree<T>::remove(const T& sought){
    ///Delete node.
    
    this->root = this->remove(this->root, sought);
}

template<typename T>
void BinaryTree<T>::removeRecursive(const T& data){
    ///Recursive delete starting from value.
    
    removeSubTree(search(data));
}

template<typename T>
void BinaryTree<T>::removeSubTree(AVLNode<T> *node) {
    ///Delete subtree of current node.
    
    if (node != nullptr and node->right_is_thread) {
        this->removeSubTree(node->left);
        this->removeSubTree(node->right);
        delete node;
    }
    this->root = nullptr;
}

template<typename T>
BinaryTree<T>::~BinaryTree(){
    ///Tree destructor.
    
    this->removeSubTree(root);
}

//Balancer
template<typename T>
unsigned int BinaryTree<T>::height(AVLNode<T>* node){
    ///Return height of current node.
    
    return node != nullptr ? node->height : 0;
}

template<typename T>
int BinaryTree<T>::bfactor(AVLNode<T>* node){
    ///Calculate balance factor of tree
    
    return this->height(node->right) - this->height(node->left);
}

template<typename T>
void BinaryTree<T>::fixheight(AVLNode<T>* node){
    ///Fixing heights of all nodes for current node.
    
    unsigned int hl = this->height(node->left);
    unsigned int hr = this->height(node->right);
    node->height = (hl > hr ? hl : hr) + 1;
}

template<typename T>
AVLNode<T>* BinaryTree<T>::rotateright(AVLNode<T>* node){
    ///Right rotation of subtree for current node.
    
    AVLNode<T> *newNode = node->left;
    node->left = newNode->right;
    newNode->right = node;
    this->fixheight(node);
    this->fixheight(newNode);
    return newNode;
}

template<typename T>
AVLNode<T>* BinaryTree<T>::rotateleft(AVLNode<T>* node){
    ///Left rotation of subtree for current node.
    
    AVLNode<T>* newNode = node->right;
    node->right = newNode->left;
    newNode->left = node;
    this->fixheight(node);
    this->fixheight(newNode);
    return newNode;
}

template<typename T>
AVLNode<T>* BinaryTree<T>::balance(AVLNode<T>* node){
    ///Balancing all nodes for current node.
    
    this->fixheight(node);
    if (this->bfactor(node) == 2) {
        if (this->bfactor(node->right) < 0) {
            node->right = this->rotateright(node->right);
        }
        return this->rotateleft(node);
    }
    if (this->bfactor(node) == -2) {
        if (this->bfactor(node->left) > 0) {
            node->left = this->rotateleft(node->left);
        }
        return this->rotateright(node);
    }
    return node;
}

template<typename T>
void BinaryTree<T>::unionTree(AVLNode<T>* node1, BinaryTree<T>* tree){
    ///Recursive function for union of trees.
    
    if (node1 != nullptr){
        tree->add(node1->data);
        tree->unionTree(node1->left, tree);
        tree->unionTree(node1->right, tree);
    }
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::unionTree(BinaryTree<T>* tree){
    ///Returns a tree with values of two trees.
    
    auto* res = new BinaryTree<T>();
    unionTree(this->root, res);
    unionTree(tree->root, res);
    return res;
}

template<typename T>
void BinaryTree<T>::intersecTree(AVLNode<T>* node, BinaryTree<T>* tree, BinaryTree<T>* res){
    ///Recursive function for Intersec of trees.
    
    if (node != nullptr){
        if (tree->exist(node->data)){
            res->add(node->data);
        }
        this->intersecTree(node->left, tree, res);
        this->intersecTree(node->right, tree, res);
    }
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::intersecTree(BinaryTree<T>* tree){
    ///Returns a tree with values common to two trees.
    
    auto* res = new BinaryTree<T>();
    res->intersecTree(this->root, tree, res);
    return res;
}

template<typename T>
void BinaryTree<T>::except(AVLNode<T>* node, BinaryTree<T>* tree, BinaryTree<T>* res){
    ///Recursive function for except.
    
    if (node != nullptr){
        if (not tree->exist(node->data)){
            res->add(node->data);
        }
        this->except(node->left, tree, res);
        this->except(node->right, tree, res);
    }
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::except(BinaryTree<T>* tree){
    ///Returns a tree with subtracting the values of one tree from another.
    
    auto* res = new BinaryTree<T>();
    res->except(this->root, tree, res);
    return res;
}

template<typename T>
T BinaryTree<T>::getOnIndex(int index){
    ///Getting the value of a node based on the index of the thread tree.
    
    if (index < 0 or index >= this->getCountNodes()){
        throw std::out_of_range("Index out of range!");
    }
    this->threadTree();
    AVLNode<T>* node = this->root;
    for (int i = 0; i < index; i++){
        if (node->left != nullptr){
            node = node->left;
        }
        else{
            node = node->right;
        }
    }
    this->deleteThread();
    return node->data;
}


template<typename T>
void BinaryTree<T>::threadTree(AVLNode<T>* node){
    ///Recursive function for creation thread.
    
    AVLNode<T>* start = node;
    
    while ((node->right != nullptr) or (node->left != nullptr)) {
        if (node->left != nullptr){
            node = node->left;
        }
        else if (node->right != nullptr){
            node = node->right;
        }
    }
    if (node != start){
        AVLNode<T>* seq = findNextR(this->root, node);
        if (seq != nullptr){
            
            node->right = seq;
            node->right_is_thread = 1;
            this->threadTree(node->right);
        }
    }
}


template<typename T>
void BinaryTree<T>::threadTree(){
    ///Single-threading tree.
    
    this->threadTree(root);
}


template<typename T>
AVLNode<T>* findNextR(AVLNode<T>* from, AVLNode<T>* what){
    ///The function searches for a node with a minimum value that is greater than the value of this node.
    
    AVLNode<T>* res = nullptr;
    if (from->right != nullptr){
        res = from->right;
    }

    while ((from->right != nullptr or from->left != nullptr) and (from->data != what->data)){
        if (from->left != nullptr and what->data < from->data){
            if (from->right != nullptr){
                res = from->right;
            }
            from = from->left;
        }
        else if (from->right != nullptr and what->data > from->data){
            from = from->right;
            res = from->right;
        }
        if (from->data == what->data){
            return res;
        }
    }
    return res;
}


template<typename T>
void BinaryTree<T>::deleteThread(){
    ///Delete tree thread.
    
    if (root != nullptr){
        AVLNode<T>* node = root;
        AVLNode<T>* help = nullptr;
        while (node->left != nullptr or node->right != nullptr){
            if (node->left != nullptr){
                node = node->left;
            }
            else if (node->right != nullptr){
                if (node->right_is_thread){
                    help = node->right;
                    node->right = nullptr;
                    node->right_is_thread = 0;
                    node = help;
                    delete help;
                }
                else node = node->right;
            }
        }
    }
}

#endif /* Tree_2_hpp */
