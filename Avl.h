#ifndef AVL_H
#define AVL_H

#include "Tree.h"
#include <iostream>

template <typename T>
class Avl : public Tree<T>
{
public:
    Avl();
    Avl(T);
    ~Avl();

public:
    virtual void insert(const T) override;
    virtual void deleteValue(const T) override;

private:
    virtual typename Tree<T>::Node* insert(typename Tree<T>::Node*, T) override;
    virtual typename Tree<T>::Node* deleteValue(typename Tree<T>::Node*, const T) override;
    int BalanceFactor(typename Tree<T>::Node*);
    typename Tree<T>::Node* balance(typename Tree<T>::Node*);
    typename Tree<T>::Node* leftRotate(typename Tree<T>::Node*);
    typename Tree<T>::Node* rightRotate(typename Tree<T>::Node*);
};

#include "Avl.cpp"

#endif // AVL_H
