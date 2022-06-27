#pragma once
#include "BinarySearchTree.hpp"

template <typename T>
class AVLtree : public BinarySearchTree<T>
{
public:
    BinNodePtr(T) insert(const T &data);
    bool remove(const T &data);
};