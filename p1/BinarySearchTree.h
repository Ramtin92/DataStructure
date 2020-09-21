// BST of integers
#include "BinaryTree.h"

#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

// Prototypes for recursive wrapper functions
void find_bst(BinaryNode *, TreeItem &, bool &);
void insert_bst(BinaryNode *&, TreeItem);
void remove_bst(BinaryNode *&, TreeItem);
void delete_node(BinaryNode *&);

class BinarySearchTree : public BinaryTree
{

public:
    BinarySearchTree();
    // BT has a virtual destructor
    // so we write our own for BST
    ~BinarySearchTree();

    // REMOVE ME FROM STARTER CODE
    // Rule of Three
    BinarySearchTree(const BinarySearchTree &);
    BinarySearchTree & operator = (const BinarySearchTree &);

    // overwritten from BinaryTree
    void insert_item(TreeItem);

    // REMOVE ME FROM STARTER CODE
    void find_item(TreeItem &, bool &) const;
    void remove_item(TreeItem);
};

#endif
