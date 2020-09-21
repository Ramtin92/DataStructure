
//#include <cstddef>
#include "Queue.h"
#include "BinaryTree.h"

// Constructor
BinaryTree::BinaryTree()
{
    root = NULL;
}

// Destructor
BinaryTree::~BinaryTree()
{
    destroy(root);
}

// Copy constructor
BinaryTree::BinaryTree(const BinaryTree &b)
{
    if (b.root == NULL)
        root = NULL;
    else
        copy_tree(root, b.root);
}

// Assignment Operator
BinaryTree & BinaryTree::operator = (const BinaryTree &b)
{
    destroy(root);
    if(b.root == NULL)
        root = NULL;
    else
        copy_tree(root, b.root);
    return *this;
}

// Function get_length (const)
// Counts the total number of nodes in the tree
int BinaryTree::get_length() const
{
    return count_nodes(root);
}

// Inorder traversal
void BinaryTree::inorder(ostream &out) const
{
    print_inorder(root, out);
}

// preorder traversal
void BinaryTree::preorder(ostream &out) const
{
    print_preorder(root, out);
}

// postorder traversal
void BinaryTree::postorder(ostream &out) const
{
    print_postorder(root, out);
}

// Function insert_item
// Checks for fullness, throws exception if necessary
// insert item into next open slot
void BinaryTree::insert_item(TreeItem item)
{
    if (is_full())
        throw FullTree();
    else
        insert_bt(root, item);
}

// Function find_item
// finds the given item using queue as auxiliary structure
void BinaryTree::find_item(TreeItem &item, bool & found) const
{
    find_bt(root, item, found);
}

// Function remove_item
// Checks for empty tree, throws exception if necssary
// remove item, if found
void BinaryTree::remove_item(TreeItem item)
{
    if (is_empty())
        throw EmptyTree();
    else
    {    
        bool found = false;
        find_item(item, found);
        if (found)
            remove_bt(root, item);
    }
}

// Function get_height
// Figure out the overall height of the tree
int BinaryTree::get_height() const
{
    return get_max_depth(root);
}

// Return the item at the deepest left node
// (Would come first in an in-order traversal)
// Throws exception if tree is empty
TreeItem BinaryTree::get_leftmost() const
{
    return return_leftmost(root);
}

// REMOVE ME FROM STARTER CODE
// Counts the total number of leaves in the tree
int BinaryTree::get_num_leaves() const
{
    return count_leaves(root);
}

// REMOVE ME FROM STARTER CODE
// Returns true if tree is full
bool BinaryTree::is_full() const
{
    try
    {
        BinaryNode *node = new BinaryNode;
        delete node;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}

// REMOVE ME FROM STARTER CODE
// Return true if tree is empty
bool BinaryTree::is_empty() const
{
    return (root == NULL);
}

// REMOVE ME FROM STARTER CODE
double BinaryTree::get_average_age() const
{
    return (get_total_age(root) / get_length());
}


// REMOVE ME FROM STARTER CODDE
TreeItem BinaryTree::get_rightmost() const
{
    if (is_empty())
        throw EmptyTree();
    return return_rightmost(root);
}

// REMOVE ME FROM STARTER CODE
// print key information about the tree
void BinaryTree::print_tree(ostream &out) const
{
    root->info.print(out);
    out << "Height: " << get_height() << endl;
    out << "Number of nodes: " << get_length() << endl;
    out << "Number of leaves: " << get_num_leaves() << endl;
}

// REMOVE ME FROM STARTER CODE
// just overloading the << operator
ostream &operator << (ostream &out, const BinaryTree &tree)
{
    tree.root->info.print(out);
    out << "Height: " << tree.get_height() << endl;
    out << "Number of nodes: " << tree.get_length() << endl;
    out << "Number of leaves: " << tree.get_num_leaves() << endl;
    return out;
}

// REMOVE ME FROM STARTER CODE
// prints just the root information
void BinaryTree::print_root(ostream &out) const
{
    root->info.print(out);
}

/* Definitions for Recursive Wrapper Functions */

// Function copy_tree (wrapper)
// Used by copy constructor and = operator
// Visit nodes in prefix order, copy each one as we go
void copy_tree(BinaryNode *&tree, BinaryNode *source)
{
    if (source == NULL)
        tree = NULL;
    else
    {
        try
        {
            tree = new BinaryNode;
            tree->info = source->info;
            tree->left = NULL;
            tree->right = NULL;
            copy_tree(tree->left, source->left);
            copy_tree(tree->right, source->right);
        }
        catch (bad_alloc exception)
        {
            cerr << "Out of memory, could not copy tree!\n";
        }
    }
}

// Function destroy (wrapper)
// Used by destructor and = operator
// Follows postfix order, deletes nodes one by one
void destroy(BinaryNode *&tree)
{
    if (tree != NULL)
    {
        destroy(tree->left);
        destroy(tree->right);
        delete tree;
    }
}

// Recursively counts the total number of nodes in the tree
int count_nodes(BinaryNode *tree)
{
    if (tree == NULL)
        return 0;
    else
        return count_nodes(tree->left) + count_nodes(tree->right) + 1;
}

// REMOVE ME FROM STARTER CODE
// Recursively count leaf nodes (proj 1?)
int count_leaves(BinaryNode *tree)
{
    if (tree == NULL)
        return 0;
    if (tree->right == NULL && tree->left == NULL)
        return 1;
    else
        return count_leaves(tree->left) + count_leaves(tree->right);
}

// Function get_predecessor
// Parameters: BinaryNode (the tree), and TreeItem reference
// Does: Updates treeitem reference with item in predecessor
//       position (would come immediately before tree in
//       in-order traversal)
void get_predecessor(BinaryNode *tree, TreeItem &item)
{
    while (tree->right != NULL)
        tree = tree->right;
    item = tree->info;
}

// Print in  order
void print_inorder(BinaryNode *tree, ostream &out)
{
    if (tree != NULL)
    {
        print_inorder(tree->left, out);
        tree->info.print(out);
        print_inorder(tree->right, out);
    }
} 

// Print in prefix order
void print_preorder(BinaryNode *tree, ostream &out)
{
    if (tree != NULL)
    {
        tree->info.print(out);
        print_preorder(tree->left, out);
        print_preorder(tree->right, out);
    }
} 

// Print in postfix order
void print_postorder(BinaryNode *tree, ostream &out)
{
    if (tree != NULL)
    {
        print_postorder(tree->left, out);
        print_postorder(tree->right, out);
        tree->info.print(out);
    }
}

// Function insert_bt (wrapper)
// Params: BinaryNode reference, TreeItem
// Returns: void
// Does: Finds next open spot using a queue
//       allocates a new BinaryNode and sets
//       its info to the given tree
void insert_bt(BinaryNode *&tree, TreeItem item)
{
    // enqueue and dequeue until empty
    BinaryNode *temp = NULL;
    BinaryNode *node = new BinaryNode;
    node->info = item;
    node->left = NULL;
    node->right = NULL;
    if (tree == NULL)
    {
        tree = node;
        return;
    }
    
    Queue q;
    q.enqueue(tree);
    while (!q.is_empty())
    {
        q.dequeue(temp);
        if (temp->left != NULL)
        {
            q.enqueue(temp->left);
        }
        else
        {
            temp->left = node;
            return;
        }
        if (temp->right != NULL)
        {
            q.enqueue(temp->right);
        }
        else
        {
            temp->right = node;
            return;
        }
    }
}

// Function find_bt (not a member function)
// Parameters: BinaryNode (root), TreeItem reference, bool reference
// Returns: void
// Does: Uses an auxiliary queue to iterate through each node
//       until the item is found. Updates the item reference with
//       the one actually found, and bool reference with true/false. 
void find_bt(BinaryNode *tree, TreeItem &item, bool &found)
{ 
    found = false;
    if (tree == NULL)
    {
        return;
    }

    Queue q;
    q.enqueue(tree);

    while (!q.is_empty())
    {
        BinaryNode *node; 
        q.dequeue(node);
        if (node->info == item)
        {
            item = node->info;
            found = true;
            return;
        }
        if (node->left != NULL)
            q.enqueue(node->left);
        if (node->right != NULL)
            q.enqueue(node->right);
    }
}

// Function remove_bt (wrapper)
// Parameters: BinaryNode reference (root), TreeItem to remove
// Returns: void
// Does: Uses an auxiliary queue to find the deepest item
//       swaps one to delete with deepest item
//       deletes deepest item
void remove_bt(BinaryNode *&tree, TreeItem item) 
{
    if (tree == NULL)
    {
        return;
    }

    Queue q;
    q.enqueue(tree);

    BinaryNode *deep = NULL, *keynode = NULL;

    while (!q.is_empty())
    {
        q.dequeue(deep);
        if (deep->info == item)
            keynode = deep;
        if (deep->left != NULL)
            q.enqueue(deep->left);
        if (deep->right != NULL)
            q.enqueue(deep->right);
    }

    TreeItem val = deep->info;
    delete_deepest(tree, deep);
    if (deep != keynode)
        keynode->info = val;
}

// Delete deepest node in the tree
// Helper function for remove
void delete_deepest(BinaryNode *&tree, BinaryNode *&deepnode)
{
    Queue q;
    q.enqueue(tree);

    BinaryNode *temp;
    while (!q.is_empty())
    {
        q.dequeue(temp);
        if (temp->right != NULL)
        {
            if (temp->right->info == deepnode->info)
            {
                temp->right = NULL;
                delete deepnode;
                return;
            }
            else
                q.enqueue(temp->right);
        }
        if (temp->left != NULL)
        {
                if (temp->left->info == deepnode->info)
                {
                    temp->left = NULL;
                    delete deepnode;
                    return;
                }
                else
                    q.enqueue(temp->left);
        }
    }
}

// Function get_max_depth (wrapper)
// Params: BinaryNode *
// Returns: integer
// Does: recursively finds the height of the overall tree
int get_max_depth(BinaryNode *tree)
{
    if (tree == NULL)
        return -1;
    else
    {
        int ldepth = get_max_depth(tree->left);
        int rdepth = get_max_depth(tree->right);
        if (ldepth > rdepth)
            return (ldepth + 1);
        else
            return (rdepth + 1);
    }
}

// REMOVE ME FROM STARTER CODE
double get_total_age(BinaryNode *tree)
{
    if (tree == NULL)
        return 0;
    else if (tree->left == NULL && tree->right == NULL)
        return tree->info.get_age();
    else
    {
       double leftsum = get_total_age(tree->left);
       double rightsum = get_total_age(tree->right);
       return (leftsum + rightsum + tree->info.get_age());
    }
}

// Function return_leftmost(wrapper)
// Params: BinaryNode *, the tree
// Returns: TreeItem, the info in the deepest left node
TreeItem return_leftmost(BinaryNode *tree)
{
    if (tree == NULL)
        throw EmptyTree();
    else if (tree->left == NULL)
        return tree->info;
    else
       return return_leftmost(tree->left);
}

// REMOVE ME FROM STARTER CODE
TreeItem return_rightmost(BinaryNode *tree)
{
    if (tree == NULL)
        throw EmptyTree();
       if (tree->right == NULL)
           return tree->info;
       else
           return return_rightmost(tree->right);
}
