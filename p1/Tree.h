#include "Survivor.h"

#ifndef TREE_H_
#define TREE_H_

//typedef Survivor TreeItem;
typedef TreeItem Survivor;

struct BinaryNode
{
    TreeItem info;
    BinaryNode *left;
    BinaryNode *right;
};


#endif
