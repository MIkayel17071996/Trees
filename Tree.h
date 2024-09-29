#ifndef TREE_H
#define TREE_H

template <typename T>
class Tree
{
public:
    struct Node
    {
        T data;
        Node *left;
        Node *right;

        Node(T value)
            : data(value), left(nullptr), right(nullptr)
        {
        }
    };

public:
    Tree();
    Tree(const T value);
    virtual ~Tree() = default;

public:
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();
    void levelOrderTraversal();
    virtual void insert(const T) = 0;
    virtual void deleteValue(const T) = 0;

    bool search(const T);
    void clear();
    const T getMin() const;
    const T getMax() const;
    const int getHeight() const;
    const T getPredecessor(const T);
    const T getSuccessor(const T);

protected:
    void preOrderTraversal(Node*);
    void inOrderTraversal(Node*);
    void postOrderTraversal(Node*);
    void levelOrderTraversal(Node*);
    void printLevelOrderTraversal(Node*, T);
    virtual Node* insert(Node*, T) = 0;
    Node* search(Node*, const T);
    void clearTree(Node*);
    Node* getMin(Node*) const;
    Node* getMax(Node*) const;
    const int getHeight(Node*) const;
    Node* getPredecessor(Node*);
    Node* getSuccessor(Node*);
    virtual Node* deleteValue(Node*, const T) =0;

protected:
    Node *m_root;

};

#include "Tree.cpp"

#endif // TREE_H
