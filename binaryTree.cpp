#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *leftchild;
    Node *rightchild;

    //Constructor for the node Class
    Node()
    {
        leftchild = nullptr; // initizlize left child to null
        rightchild = nullptr; // initialize right child to nul
    }
};

class BinaryTree
{
public:
    Node *ROOT;

    BinaryTree()
    {
        ROOT = nullptr; // initializing ROOT to null
    }

    