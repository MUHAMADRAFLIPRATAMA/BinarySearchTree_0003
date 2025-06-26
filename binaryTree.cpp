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

    void insert()
    {
        int x;
        cout << "Masukkan Nilai: ";
        cin >> x;

        //step 1 : Allocate memory for the new node
        Node *newNode = new Node();

        //setp 2 : assign value to the data field of new node
        newNode->info = x;

        //step 3 : Make the left and right child of the new node point
        newNode->leftchild = nullptr;
        newNode->rightchild = nullptr;

        //step 4 : locate the new node which will be the parent of the node
        Node *parent = nullptr;
        Node *currentNode = nullptr;
        search(x, parent, currentNode);

        //step 5 : if parent is null (tree is empty)
        if (parent == nullptr)
        {
            //5a : mark the new node as ROOT
            ROOT = newNode;

            //5b : exit
            return;
        }

        