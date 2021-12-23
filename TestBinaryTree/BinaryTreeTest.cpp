//
//  BinaryTreeTest.cpp
//  Lab2_3s
//
//  Created by  Николай Фонов on 16.12.2021.
//

#include "BinaryTreeTest.hpp"


void avlAdd(){
    auto* tree = new BinaryTree<int>();
    
    tree->add(10);
    assert(tree->exist(10) == true);
    
    tree->add(1);
    assert(tree->exist(1) == true);
    assert(tree->exist(10) == true);
    
    tree->add(20);
    assert(tree->exist(1) == true);
    assert(tree->exist(10) == true);
    assert(tree->exist(20) == true);
    
    delete tree;
    
    
    auto* tree2 = new BinaryTree<int>();
    
    tree2->add(1);
    assert(tree2->exist(1) == true);
    
    tree2->add(2);
    assert(tree2->exist(1) == true);
    assert(tree2->exist(2) == true);
    
    tree2->add(3);
    assert(tree2->exist(1) == true);
    assert(tree2->exist(2) == true);
    assert(tree2->exist(3) == true);
    
    delete tree2;
}

void avlDelete(){
    auto* tree = new BinaryTree<int>();
    
    tree->add(10);
    tree->add(1);
    tree->add(20);
    
    tree->remove(1);
    assert(tree->exist(1) == false);
    assert(tree->exist(10) == true);
    assert(tree->exist(20) == true);
    
    tree->remove(10);
    assert(tree->exist(1) == false);
    assert(tree->exist(10) == false);
    assert(tree->exist(20) == true);
    
    tree->remove(20);
    assert(tree->exist(1) == false);
    assert(tree->exist(10) == false);
    assert(tree->exist(20) == false);
    
    delete tree;
    
    
    auto* tree2 = new BinaryTree<int>();
    
    tree2->add(1);
    tree2->add(2);
    tree2->add(3);
    
    tree2->remove(1);
    assert(tree2->exist(1) == false);
    assert(tree2->exist(2) == true);
    assert(tree2->exist(3) == true);
    
    tree2->remove(2);
    assert(tree2->exist(1) == false);
    assert(tree2->exist(2) == false);
    assert(tree2->exist(3) == true);
    
    tree2->remove(3);
    assert(tree2->exist(1) == false);
    assert(tree2->exist(2) == false);
    assert(tree2->exist(3) == false);
    
    delete tree2;
}

void avlBalance(){
    auto* tree = new BinaryTree<int>();
    
    tree->add(10);
    tree->add(1);
    tree->add(20);
    assert(tree->depth() == 2);
    
    tree->add(24);
    assert(tree->depth() == 3);
    
    tree->add(2);
    assert(tree->depth() == 3);
    
    delete tree;
    
    
    auto* tree2 = new BinaryTree<int>();
    
    tree2->add(1);
    tree2->add(2);
    tree2->add(3);
    assert(tree2->depth() == 2);
    
    tree2->add(4);
    assert(tree2->depth() == 3);
    
    tree2->add(5);
    assert(tree2->depth() == 3);
    
    delete tree2;
}

void avlGetCountNodes(){
    auto* tree = new BinaryTree<int>();
    
    tree->add(10);
    assert(tree->getCountNodes() == 1);
    
    tree->add(1);
    assert(tree->getCountNodes() == 2);
    
    tree->add(20);
    assert(tree->getCountNodes() == 3);
    
    tree->add(24);
    assert(tree->getCountNodes() == 4);
    
    tree->add(2);
    assert(tree->getCountNodes() == 5);
    
    delete tree;
    
    
    auto* tree2 = new BinaryTree<int>();
    
    tree2->add(1);
    assert(tree2->getCountNodes() == 1);
    
    tree2->add(2);
    assert(tree2->getCountNodes() == 2);
    
    tree2->add(3);
    assert(tree2->getCountNodes() == 3);
    
    tree2->add(4);
    assert(tree2->getCountNodes() == 4);
    
    tree2->add(5);
    assert(tree2->getCountNodes() == 5);
    
    delete tree2;
}

void avlUnionTree(){
    auto* tree = new BinaryTree<int>();
    tree->add(10);
    tree->add(1);
    tree->add(20);
    tree->add(24);
    tree->add(2);
    
    auto* tree2 = new BinaryTree<int>();
    tree2->add(1);
    tree2->add(2);
    tree2->add(3);
    tree2->add(4);
    tree2->add(5);
    
    auto* tree3 = tree->unionTree(tree2);
    
    assert(tree3->exist(1) == 1);
    assert(tree3->exist(2) == 1);
    assert(tree3->exist(3) == 1);
    assert(tree3->exist(4) == 1);
    assert(tree3->exist(5) == 1);
    assert(tree3->exist(10) == 1);
    assert(tree3->exist(20) == 1);
    assert(tree3->exist(24) == 1);
    
    delete tree;
    delete tree2;
    delete tree3;
}

void avlIntersecTree(){
    auto* tree = new BinaryTree<int>();
    tree->add(10);
    tree->add(1);
    tree->add(20);
    tree->add(24);
    tree->add(2);
    
    auto* tree2 = new BinaryTree<int>();
    tree2->add(1);
    tree2->add(2);
    tree2->add(3);
    tree2->add(4);
    tree2->add(5);
    
    auto* tree3 = tree->intersecTree(tree2);
    
    assert(tree3->exist(1) == 1);
    assert(tree3->exist(2) == 1);
    assert(tree3->exist(3) == 0);
    assert(tree3->exist(4) == 0);
    assert(tree3->exist(5) == 0);
    assert(tree3->exist(10) == 0);
    assert(tree3->exist(20) == 0);
    assert(tree3->exist(24) == 0);
    
    delete tree;
    delete tree2;
    delete tree3;
}

void except(){
    auto* tree = new BinaryTree<int>();
    tree->add(10);
    tree->add(1);
    tree->add(20);
    tree->add(24);
    tree->add(2);
    
    auto* tree2 = new BinaryTree<int>();
    tree2->add(1);
    tree2->add(2);
    tree2->add(3);
    tree2->add(4);
    tree2->add(5);
    
    auto* tree3 = tree->except(tree2);
    
    assert(tree3->exist(1) == 0);
    assert(tree3->exist(2) == 0);
    assert(tree3->exist(3) == 0);
    assert(tree3->exist(4) == 0);
    assert(tree3->exist(5) == 0);
    assert(tree3->exist(10) == 1);
    assert(tree3->exist(20) == 1);
    assert(tree3->exist(24) == 1);
    
    delete tree;
    delete tree2;
    delete tree3;
}

void avlTests(){
    std::cout << "Tree Tests:\n";
    avlAdd();
    std::cout << "1)Tree add test compleated\n";
    avlDelete();
    std::cout << "2)Tree delete test compleated\n";
    avlBalance();
    std::cout << "3)Tree getRoot test compleated\n";
    avlGetCountNodes();
    std::cout << "4)Tree getCountNodes test compleated\n";
    avlUnionTree();
    std::cout << "5)Tree union test compleated\n";
    avlIntersecTree();
    std::cout << "6)Tree intersec test compleated\n";
    except();
    std::cout << "7)Tree except test compleated\n";
}
