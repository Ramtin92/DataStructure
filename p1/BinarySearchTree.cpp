//#include <cstddef>
#include "BinarySearchTree.h"


// Member function definitions
BinarySearchTree::BinarySearchTree()
{

}

// Destructor requires no action, base class handles it
BinarySearchTree::~BinarySearchTree()
{

}

// REMOVE ME FROM STARTER CODE
// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &b)
{
    if (b.root == NULL)
        root = NULL;
    else
        copy_tree(root, b.root);
}

// REMOVE ME FROM STARTER CODE
// assignment operator
BinarySearchTree & BinarySearchTree::operator = (const BinarySearchTree &b)
{
    destroy(root);
    if (b.root == NULL)
        root = NULL;
    else
        copy_tree(root, b.root);
    return *this;
}

// Function find_item
// Searches for given TreeItem in BST
// Uses wrapper function for recursion
void BinarySearchTree::find_item(TreeItem &item, bool &found) const
{
    find_bst(root, item, found);
}

// Function to insert into a BST
// Throws exception if full
// Calls wrapper function for recursion
void BinarySearchTree::insert_item(TreeItem item)
{
    if (is_full())
        throw FullTree();
    else
        insert_bst(root, item);
}

// REMOVE ME FROM STARTER CODE
void BinarySearchTree::remove_item(TreeItem item)
{
    if (is_empty())
        throw EmptyTree();
    else
    {
        bool found = false;
        find_item(item, found);
        if (found)
            remove_bst(root, item);
    }
}


// Definitions for wrapper functions
void find_bst(BinaryNode *tree, TreeItem &item, bool &found)
{
    if (tree == NULL)
    {
        found = false;
     }
    else if (item < tree->info)
        find_bst(tree->left, item, found);
    else if (item > tree->info)
        find_bst(tree->right, item, found);
    else
    {
        found = true;
        item = tree->info;
    }
}

void insert_bst(BinaryNode *&tree, TreeItem item)
{
    if (tree == NULL)
    {
        tree = new BinaryNode; // this part is why pass by ref
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }
    else if (item < tree->info)
    {
        insert_bst(tree->left, item);
    }
    else    
    {
        insert_bst(tree->right, item);
    }
}

void remove_bst(BinaryNode *&tree, TreeItem item)
{
    if (item < tree->info)
        remove_bst(tree->left, item);
    else if (item > tree->info)
        remove_bst(tree->right, item);
    else
        delete_node(tree);  // do the actual removal
}

void delete_node(BinaryNode *&tree)
{
    TreeItem data;
    BinaryNode *temp;

    temp = tree;
    if (tree->left == NULL)
    {
        tree = tree->right;
        delete temp;
    }

    else if (tree->right == NULL)
    {
        tree = tree->left;
        delete temp;
    }
    else
    {
        get_predecessor(tree->left, data);
        tree->info = data;
        remove_bst(tree->left, data);
    }
}
