
#include <iostream>
#include "Queue.h"
using namespace std;

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

class FullTree : public exception
{
public:
    const char *what () const throw() { return "Full Tree!\n"; }
};

class EmptyTree : public exception
{
public:
    const char * what() const throw() { return "Empty Tree!\n"; }
};

// Prototypes for recursive wrapper functions
void destroy(BinaryNode *&);
void copy_tree(BinaryNode *&, BinaryNode *);
int count_nodes(BinaryNode *);
int get_max_depth(BinaryNode *);
TreeItem return_leftmost(BinaryNode *);
void print_inorder(BinaryNode *, ostream &);
void print_preorder(BinaryNode *, ostream &);
void print_postorder(BinaryNode *, ostream &);
void insert_bt(BinaryNode *&, TreeItem);
void find_bt(BinaryNode *, TreeItem &, bool &);
void remove_bt(BinaryNode *&, TreeItem);
void delete_deepest(BinaryNode *&, BinaryNode *&);

// REMOVE ME FROM STARTER CODE
int count_leaves(BinaryNode *);
void get_predecessor(BinaryNode *, TreeItem &);
double get_total_age(BinaryNode *);
TreeItem return_rightmost(BinaryNode *);


class BinaryTree
{
public:
    BinaryTree();
    // destructor in base class will give
    // warning if not virtual when we have pointers
    virtual ~BinaryTree();
    BinaryTree(const BinaryTree &);
    BinaryTree & operator = (const BinaryTree &);    

    // implemented in base class, and
    // inherited by all derived classes
    int get_length() const;
    TreeItem get_leftmost() const;
    void inorder(ostream &) const;
    void preorder(ostream &) const;
    void postorder(ostream &) const;
    int get_height() const;

    // remove me from starter code
    bool is_full() const;
    bool is_empty() const;
    int get_num_leaves() const;
    void print_tree(ostream &) const;
    void print_root(ostream &) const;
    double get_average_age() const;
    TreeItem get_rightmost() const;

    // virtual function is defined in base class,
    // overridden in derived class
    virtual void insert_item(TreeItem);
    virtual void find_item(TreeItem &, bool &) const;
    virtual void remove_item(TreeItem);

    // remove from starter code, suggested but not req'd for proj
    friend ostream &operator << (ostream &, const BinaryTree &);

protected:
    BinaryNode *root;
};

#endif
