#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "Survivor.h"
using namespace std;

// test functions for binary tree
void test_insert(BinaryTree *, int);
void test_copy(BinaryTree *);
void test_assignment(BinaryTree *);

int main()
{
    BinaryTree *BT = new BinaryTree;
    test_insert(BT, 5);
    test_copy(BT);
    test_assignment(BT);

    delete BT;
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


void test_copy(BinaryTree *BT)
{
    BinaryTree bt2 = *(BT);
    if (bt2.get_length() == BT->get_length())
        cout << "Copy constructor SUCCESS\n";
    else
        cout << "Copy constructor FAIL\n";
}

void test_assignment(BinaryTree *BT)
{
    BinaryTree bt2;
    bt2 = *(BT);
    if (bt2.get_length() == BT->get_length())
        cout << "Assignment Operator SUCCESS\n";
    else
        cout << "Assignment operator FAIL\n";
}
