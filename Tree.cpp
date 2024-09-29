#include "Tree.h"
#include <iostream>

// Default constructor
template <typename T>
Tree<T>::Tree()
    : m_root(nullptr)
{
}

// Parameterized constructor
template <typename T>
Tree<T>::Tree(const T value)
    : m_root(new Node(value))
{
}

template <typename T>
void Tree<T>::preOrderTraversal()
{
    if (m_root)
    {
        preOrderTraversal(m_root);
    }
    else
    {
        std::cout << "The BST is empty" << std::endl;
    }
}

template <typename T>
void Tree<T>::inOrderTraversal()
{
    if (m_root)
    {
        inOrderTraversal(m_root);
    }
    else
    {
        std::cout << "The BST is empty" << std::endl;
    }
}

template <typename T>
void Tree<T>::postOrderTraversal()
{
    if (m_root)
    {
        postOrderTraversal(m_root);
    }
    else
    {
        std::cout << "The BST is empty" << std::endl;
    }
}

template <typename T>
void Tree<T>::preOrderTraversal(Node *root)
{
    if (root)
    {
        std::cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

template <typename T>
void Tree<T>::inOrderTraversal(Node *root)
{
    if (root)
    {
        inOrderTraversal(root->left);
        std::cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

template <typename T>
void Tree<T>::postOrderTraversal(Node *root)
{
    if (root)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        std::cout << root->data << " ";
    }
}

template <typename T>
void Tree<T>::levelOrderTraversal()
{
    if (!m_root)
    {
        std::cout << "The BST is empty" << std::endl;
        return;
    }

    levelOrderTraversal(m_root);
}

template <typename T>
void Tree<T>::levelOrderTraversal(Node *root)
{
    const int height = this->getHeight(root);

    for (int i = 0; i < height; ++i)
    {
        printLevelOrderTraversal(root, i);
    }
}

template <typename T>
void Tree<T>::printLevelOrderTraversal(Node *root, T level)
{
    if (root == nullptr)
    {
        return;
    }

    if (level == 0)
    {
        std::cout << root->data << " ";
    }
    else
    {
        printLevelOrderTraversal(root->left, level - 1);
        printLevelOrderTraversal(root->right, level - 1);
    }
}

template <typename T>
bool Tree<T>::search(const T value)
{
    return search(m_root, value);
}

template <typename T>
typename Tree<T>::Node* Tree<T>::search(Node *root, const T value)
{
    if (!root)
    {
        return root;
    }

    if (root->data == value)
    {
        return root;
    }
    else if (root->data > value)
    {
        return search(root->left, value);
    }

    return search(root->right, value);
}

template <typename T>
void Tree<T>::clear()
{
    clearTree(m_root);
}

template <typename T>
void Tree<T>::clearTree(Node *root)
{
    if (root)
    {
        clearTree(root->left);
        clearTree(root->right);
        delete root;
    }
}



template <typename T>
const T Tree<T>::getMin() const
{
    return getMin(m_root)->data;
}

template <typename T>
typename Tree<T>::Node *Tree<T>::getMin(Node *root) const
{
    if (!m_root)
    {
        std::cout << "The BST is empty!" << std::endl;
        return m_root;
    }

    while (root->left)
    {
        root = root->left;
    }

    return root;
}

template <typename T>
const T Tree<T>::getMax() const
{
    return getMax(m_root)->data;
}

template <typename T>
typename Tree<T>::Node *Tree<T>::getMax(Node *root) const
{
    if (!m_root)
    {
        std::cout << "The BST is empty!" << std::endl;
        return nullptr;
    }

    while (root->right)
    {
        root = root->right;
    }

    return root;
}


template <typename T>
const int Tree<T>::getHeight() const
{
    return getHeight(m_root);
}

template <typename T>
const int Tree<T>::getHeight(Node *root) const
{
    if (!root)
    {
        return 0;
    }

    return std::max(getHeight(root->left), getHeight(root->right)) + 1;
}



template <typename T>
const T Tree<T>::getPredecessor(const T value)
{
    Node *tmp = search(m_root, value);

    if (!tmp)
    {
        throw std::runtime_error("Value not found in the BST");
    }

    return getPredecessor(tmp)->data;
}

template <typename T>
typename Tree<T>::Node *Tree<T>::getPredecessor(Node *root)
{
    if (root == getMin(m_root))
    {
        std::cout << "There is no successor. The value is the minimum in the BST." << std::endl;
        return root;
    }
    else if (root->left != nullptr)
    {
        return getMax(root->left);
    }
    else
    {
        Node *predecessor = nullptr;
        Node *current = m_root;

        while (current != root)
        {
            if (root->data <= current->data)
            {
                current = current->left;
            }
            else
            {
                predecessor = current;
                current = current->right;
            }
        }

        return predecessor;
    }
}

template <typename T>
const T Tree<T>::getSuccessor(const T value)
{
    Node *tmp = search(m_root, value);

    if (!tmp)
    {
        throw std::runtime_error("Value not found in the BST");
    }

    return getSuccessor(tmp)->data;
}

template <typename T>
typename Tree<T>::Node *Tree<T>::getSuccessor(Node *root)
{

    if (root == getMax(m_root))
    {
        std::cout << "There is no successor. The value is the maximum in the BST." << std::endl;
        return root;
    }
    else if (root->right != nullptr)
    {

        return getMin(root->right);
    }
    else
    {

        Node *successor = nullptr;
        Node *current = m_root;

        while (current != root)
        {
            if (root->data < current->data)
            {
                successor = current;
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        return successor;
    }
}