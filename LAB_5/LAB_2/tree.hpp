#pragma once

#include <iostream>
#include <algorithm>
#include "node.hpp"

// relation: type Node is at agregtion with Tree.
template<typename T>
class Tree
{
private:
    Node<T>* _root;
    size_t _size;
    
public:
    using size_type = size_t;
    
    Tree(size_t size = 0, Node<T>* root = nullptr) : _size(size), _root(root) { }
    Tree(const Tree<T>* tree);
    
    ~Tree();
    
    
    void insert(T value) noexcept;
    bool find(T value) const;
    void Print() const;
    void remove(const T& value_for_delete); // -
    void deleteTree();
    
    Tree<T>& operator =(const Tree<T>& other);
    
    friend std::ostream& operator <<(std::ostream& os, const Tree<T>& rhs);
    friend std::istream& operator >>(std::istream& is, Tree<T>& rhs);
};

template<typename T>
Tree<T>::Tree(const Tree* rhs) : _root(nullptr)
{
    _root = rhs->_root->cloneTree();
}

template<typename T>
void Tree<T>::insert(T value) noexcept
{
    if(_root == nullptr)
    {
        _root = new Node(value);
    }
    else
    {
        Node<T>* iter = _root;
        while(true)
        {
            if(value > iter->GetData())
            {
                if(iter->GetRightNode() != nullptr)
                {
                    iter = iter->GetRightNode();
                }
                else
                {
                    iter->SetRightNode(new Node(value));
                    break;
                }
            }
            else
            {
                if(iter->GetLeftNode() != nullptr)
                {
                    iter = iter->GetLeftNode();
                }
                else
                {
                    iter->SetLeftNode(new Node(value));
                    break;
                }
            }
        }
    }
    ++_size;
}

template<typename T>
void Tree<T>::Print() const
{
    if(_root == nullptr)
    {
        return;
    }
    _root->Print("");
}

template<typename T>
Tree<T>::~Tree()
{
    if(_root == nullptr)
    {
        return;
    }
}

template<typename T>
bool Tree<T>::find(T value) const
{
    auto iter = _root;
    while(iter != nullptr)
    {
        if(iter->GetData() == value)
        {
            return true;
        }
        if (iter->GetData() <= value)
        {
            iter = iter->GetRightNode();
        }
        else
        {
            iter = iter->GetLeftNode();
        }
    }
    return false;
}

template<typename T>
void Tree<T>::deleteTree()
{
    _root->DeleteTree();
    _root = nullptr;
}

template<typename T>
Tree<T>& Tree<T>::operator =(const Tree<T>& other)
{
    if(this == &other)
    {
        return *this;
    }
    
    _root->DeleteTree();
    _root = other._root->cloneTree();
    return *this;
}

template<typename T>
std::ostream& operator <<(std::ostream& os, const Tree<T>& rhs)
{
    if(rhs._root == nullptr)
    {
        return os;
    }
    rhs._root->Print("");
    return os;
}

template<typename T>
std::istream& operator >>(std::istream& is, Tree<T>& rhs)
{
    std::string data_for_tree;
    getline(is, data_for_tree);
    
    std::string str;
    for(size_t i = 0; i < data_for_tree.size(); ++i)
    {
        if(data_for_tree[i] == ' ')
        {
            if(str.size() != 0)
            {
                rhs.insert(std::stoi(str));
            }
            str = " ";
            continue;
        }
        
        str += data_for_tree[i];
    }
    if(str.size() != 0)
    {
        rhs.insert(std::stoi(str));
    }
    
    return is;
}
