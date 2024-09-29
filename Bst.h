#ifndef BST_H
#define BST_H

#include "Tree.h"
#include <iostream>


template <typename T>
class Bst : public Tree<T>
{
public:
    Bst();
    Bst(T);
    ~Bst();

public:
    virtual void insert(const T) override;
    virtual void deleteValue(const T) override;

private:
    virtual typename Tree<T>::Node* insert(typename Tree<T>::Node*, T) override;
    virtual typename Tree<T>::Node* deleteValue(typename Tree<T>::Node*, const T) override;
};

#include "Bst.cpp"

#endif // BST_H



