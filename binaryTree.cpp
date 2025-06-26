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

        //step 6 : if the value in the data field of new node less then that
        if(x < parent->info)
        {
            //6a : Make the left child of parent point to the new node
            parent->leftchild = newNode;

            //6b : exit
            return;
        }

        //step 7 : if the value in the data field of the newnode is greater than that of the parent
        else if (x > parent->info)
        {
            //7a : make the right child of parent point to the new node
            parent->rightchild = newNode;

            //7b : exit
            return;
        }
    }

    void search(int element, Node *&parent, Node *&currentNode)
    {
        // this fuction searches the currentNode of the specified Node
        currentNode = ROOT;
        parent = nullptr;
        while ((currentNode != nullptr) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    }

    void inorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is Empty" << endl;
            return;
        }
        if (ptr == nullptr)
        return;

        inorder(ptr->leftchild);
        cout << ptr->info << " "; // parent
        inorder(ptr->rightchild);
    }
    void preorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
        return;

        cout << ptr->info << " ";
        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
    }

    void postorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
        return;

        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
        cout << ptr->info << " ";
    }

    bool isEmpty()
    {
        //check if the tree is empty
        return ROOT == nullptr;
    }
};

int main(){
BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            x.insert();
            break;
        }
        case '2':
        {
            x.inorder(x.ROOT);
            break;
        }
        case '3':
        {

            x.preorder(x.ROOT);
            break;
        }
        case '4':
        {

            x.postorder(x.ROOT);
            break;
        }
        case '5':
            return 0;
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
    }
}
}