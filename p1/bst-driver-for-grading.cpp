#include <iostream>
#include <string>
#include "BinarySearchTree.h"
#include "Survivor.h"
using namespace std;

// Test functions for the BST operations
void test_insert(BinaryTree *, int);
void test_find(BinaryTree *);
void test_remove(BinaryTree *, int);
void test_copy();
void test_assignment();

int main()
{
    BinaryTree *BST = new BinarySearchTree;
    test_insert(BST, 5);
    test_find(BST);    
    test_remove(BST, 2);
    test_copy();
    test_assignment();
    delete BST;
}


// Function test_insert
// Parameters: BT pointer, int for # of inserts
// Returns void
// Does: prints success if all the inserts worked
void test_insert(BinaryTree *bt, int num_items)
{
    Survivor *vives = new Survivor[num_items];
    for (int i = 0; i < num_items; i++)
    {
        string lname = "Hatch";
        lname += to_string(i+1);
        vives[i].set_name("Richard", lname);
        bt->insert_item(vives[i]);
    }
    if (bt->get_length() == num_items)
    {
        cout << "test insert SUCCESS!\n";
    }
    else
    {
        cout << "test insert FAIL\n";
    }
    delete []vives;
}



void test_find(BinaryTree *BT)
{
    Survivor there("Richard", "Hatch1"), 
        notthere("Tom", "Hanks");
    bool found;
    BT->find_item(there, found);

    if (found)
        cout << "test find (existing item): SUCCESS\n";
    else
        cout << "test find (existing item): FAIL\n";

    BT->find_item(notthere, found);
    if (!found)
        cout << "test find (nonexisting): SUCCESS\n";
    else
        cout << "test find (nonexisting): FAIL\n";
}

// Function: test remove
// Remove a leaf node, one-child node, two-child node
void test_remove(BinaryTree *BT, int new_length)
{
    Survivor leaf("Richard", "Hatch5"), 
        root("Richard", "Hatch1"),
        onechild("Richard", "Hatch4"),
        alreadyremoved("Richard", "Hatch4");

    BT->remove_item(leaf);
    BT->remove_item(root);
    BT->remove_item(onechild);
    BT->remove_item(alreadyremoved);

    if (BT->get_length() == new_length)
        cout << "test remove SUCCESS\n";
    else
        cout << "test remove FAIL\n";
}

void test_copy()
{
    BinarySearchTree bst;
    Survivor s("Gloria", "Gaynor");
    bst.insert_item(s);
    BinarySearchTree bst2 = bst;
    if (bst2.get_length() == bst.get_length())
        cout << "Copy constructor SUCCESS\n";
    else
        cout << "Copy constructor FAIL\n";
}

void test_assignment()
{
    BinarySearchTree bst;
    Survivor s("Gloria", "Gaynor");
    BinarySearchTree bst2;
    bst2 = bst;
    if (bst2.get_length() == bst.get_length())
        cout << "Assignment Operator SUCCESS\n";
    else
        cout << "Assignment operator FAIL\n";
}
