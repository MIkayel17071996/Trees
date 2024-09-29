#include "Bst.h"
#include <algorithm>

template <typename T>
Bst<T>::Bst()
    : Tree<T>()
{
}

// Parameterized constructor
template <typename T>
Bst<T>::Bst(T value)
    : Tree<T>(value)
{
}

// Destructor
template <typename T>
Bst<T>::~Bst()
{
    this->clear();
}

template <typename T>
void Bst<T>::insert(const T val)
{
    if (!this->m_root)
    {
        this->m_root = new typename Tree<T>::Node(val);
    }
    else
    {
        insert(this->m_root, val);
    }
}

template <typename T>
typename Tree<T>::Node* Bst<T>::insert(typename Tree<T>::Node* node, const T value)
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
    return node;
}


template <typename T>
void Bst<T>::deleteValue(const T value)
{
    typename Tree<T>::Node *tmp = this->search(this->m_root, value);

    if (!tmp)
    {
        throw std::runtime_error("Value not found in the BST");
    }

    typename Tree<T>::Node *tm2p = deleteValue(this->m_root, value);
}

template <typename T>
typename Tree<T>::Node* Bst<T>::deleteValue(typename Tree<T>::Node* root, const T value) {
    if (root == nullptr) {
        return root;
    }

    if (root->data > value) {
        root->left = deleteValue(root->left, value);
    } else if (root->data < value) {
        root->right = deleteValue(root->right, value);
    } else {
        if (root->left == nullptr) {
            typename Tree<T>::Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            typename Tree<T>::Node* temp = root->left;
            delete root;
            return temp;
        }

        typename Tree<T>::Node* temp = this->getMin(root->right);

        root->data = temp->data;

        root->right = deleteValue(root->right, temp->data);
    }

    return root;
}


