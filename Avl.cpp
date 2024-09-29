#include "Avl.h"
#include <algorithm>

template <typename T>
Avl<T>::Avl()
    : Tree<T>()
{
}

// Parameterized constructor
template <typename T>
Avl<T>::Avl(T value)
    : Tree<T>(value)
{
}

// Destructor
template <typename T>
Avl<T>::~Avl()
{
    this->clear();
}

template <typename T>
int Avl<T>::BalanceFactor(typename Tree<T>::Node* node)
{
    if (!node)
    {
        return 0;
    }

    return this->getHeight(node->left) - this->getHeight(node->right);
}

template <typename T>
typename Tree<T>::Node* Avl<T>::leftRotate(typename Tree<T>::Node* node)
{
    typename Tree<T>::Node* newRoot = node->right; 
    typename Tree<T>::Node* leftSubtreeOfNewRoot = newRoot->left; 

    newRoot->left = node;
    node->right = leftSubtreeOfNewRoot;

    return newRoot;
}

template <typename T>
typename Tree<T>::Node* Avl<T>::rightRotate(typename Tree<T>::Node* node)
{
    typename Tree<T>::Node* newRoot = node->left; 
    typename Tree<T>::Node* rightSubtreeOfNewRoot = newRoot->right; 

    newRoot->right = node;
    node->left = rightSubtreeOfNewRoot;

    return newRoot;
}

template <typename T>
typename Tree<T>::Node* Avl<T>::balance(typename Tree<T>::Node* node)
{
    int bf = BalanceFactor(node);

    // Left Left Case
    if (bf > 1 && BalanceFactor(node->left) >= 0)
    {
        return rightRotate(node);
    }

    // Left Right Case
    if (bf > 1 && BalanceFactor(node->left) < 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Right Case
    if (bf < -1 && BalanceFactor(node->right) <= 0)
    {
        return leftRotate(node);
    } 

    // Right Left Case
    if (bf < -1 && BalanceFactor(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

template <typename T>
void Avl<T>::insert(const T val)
{
    if (!this->m_root)
    {
        this->m_root = new typename Tree<T>::Node(val);
    }
    else
    {
        this->m_root = insert(this->m_root, val);
    }
}

template <typename T>
typename Tree<T>::Node* Avl<T>::insert(typename Tree<T>::Node* node, const T value)
{
    if (!node)
    {
        return new typename Tree<T>::Node(value);
    }

    if (value < node->data)
    {
        node->left = insert(node->left, value);
    }
    else
    {
        node->right = insert(node->right, value);
    }

    return balance(node);
}

template <typename T>
void Avl<T>::deleteValue(const T value)
{
    typename Tree<T>::Node* tmp = this->search(this->m_root, value);

    if (!tmp)
    {
        throw std::runtime_error("Value not found in the Avl");
    }

    this->m_root = deleteValue(this->m_root, value);
}

template <typename T>
typename Tree<T>::Node* Avl<T>::deleteValue(typename Tree<T>::Node* node, const T value)
{
    if (!node)
    {
        return nullptr;
    }

    if (value < node->data)
    {
        node->left = deleteValue(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = deleteValue(node->right, value);
    }
    else
    {
        if (!node->left)
        {
            typename Tree<T>::Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right)
        {
            typename Tree<T>::Node* temp = node->left;
            delete node;
            return temp;
        }
        else
        {
            typename Tree<T>::Node* temp = this->getMin(node->right);
            node->data = temp->data;
            node->right = deleteValue(node->right, temp->data);
        }
    }

    return balance(node);
}
