#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include "BinarySearchTree.h"
using namespace std;

const string INPUT_CASTAWAY = "castaways.txt";
const string INPUT_STOWAWAY = "stowaways.txt";

void populate_tree_from_file(BinaryTree *, string);
BinaryTree *play_round_one(BinaryTree *, BinaryTree *);
void play_round_two(BinaryTree *);

int main()
{
    srand(time(NULL));

    // Make one of each tree
    BinaryTree *bstcast = new BinarySearchTree;
    BinaryTree *btcast = new BinaryTree;

    // Play the first round
    BinaryTree *tribe_winner;
    tribe_winner = play_round_one(bstcast, btcast);
   
    tribe_winner->print_tree(cout);
    cout << endl;

    // Play the second round
    play_round_two(tribe_winner);
    cout << "\nWINNING SURVIVOR:\n";
    tribe_winner->print_root(cout);

    delete bstcast;
    delete btcast;
}

BinaryTree* play_round_one(BinaryTree *bst, BinaryTree *bt)
{
    // Randomly choose how to populate
    int r = rand() % 2;
    if (r == 0)
    {
        populate_tree_from_file(bst, INPUT_CASTAWAY);
        populate_tree_from_file(bt, INPUT_STOWAWAY);
    }
    else
    {
        populate_tree_from_file(bt, INPUT_CASTAWAY);
        populate_tree_from_file(bst, INPUT_STOWAWAY);
    }

    // Compare the number of leaves
    if (bst->get_num_leaves() < bt->get_num_leaves())
    {
        cout << "Loser had " << bt->get_num_leaves() << " leaves\n";
        cout << "ROUND ONE WINNER: BST\n";
        return bst;
    }
    else
    {
        cout << "Loser had " << bst->get_num_leaves() << " leaves\n";
        cout << "ROUND ONE WINNER: BT\n";
        return bt;
    }
}


void populate_tree_from_file(BinaryTree *tree, string filename)
{
    ifstream infile;
    infile.open(filename.c_str());

    if (!infile.is_open())
    {
        cerr << "Could not open file for reading\n";
        return;
    }
    Survivor s;
    while (!infile.eof())
    {
        int success = s.generate_next_survivor(infile);
        if (success == -1)
            break;
        tree->insert_item(s);
        
    }
    infile.close();
}

void play_round_two(BinaryTree *tree)
{
    Survivor s1, s2; 
   while (tree->get_length() > 1)
    {
        double avg = tree->get_average_age();
        cout << "Average age this round " << avg << endl;
        try
        {
            s1 = tree->get_leftmost();
            s2 = tree->get_rightmost();
        }
        catch(EmptyTree except)
        {
            cerr << except.what() << endl;
            return;
        }

        double abs1 = s1.get_age() - avg;
        double abs2 = s2.get_age() - avg;
        if (abs1 < abs2)
        {
            cout << "Voted off the island:\n";
            s1.print(cout);
            tree->remove_item(s1);
        }
        else
        {
            cout << "Voted off the island:\n";
            s2.print(cout);
            tree->remove_item(s2);
        }
    }

}
