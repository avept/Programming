#pragma once

#include <iostream>

template<typename T>
class Node
{
private:
    Node* _right;
    Node* _left;
    T _data;
    
public:
    using size_type = size_t; // size_type
    
    Node(T data = NULL, Node* right = nullptr, Node* left = nullptr) : _right(right), _left(left), _data(data) { }
    
    Node* GetRightNode() const;
    void SetRightNode(Node* right);
    
    Node* GetLeftNode() const;
    void SetLeftNode(Node* left);
    
    int GetData() const;
    void SetData(T& value);
    
    void Print(std::string offset) const;
    
    void DeleteTree();
    
    Node* cloneTree() noexcept;

};

template<typename T>
void Node<T>::Print(std::string offset) const
{
    if (_right != nullptr)
    {
        _right->Print(offset + "   ");
    }
    
    std::cout << offset << _data << std::endl;
    
    if (_left != nullptr)
    {
        _left->Print(offset + "   ");
    }
}

template<typename T>
Node<T>* Node<T>::cloneTree() noexcept
{
    if(this == nullptr)
    {
        return nullptr;
    }
    
    Node* copyRoot = new Node(GetData());
    
    copyRoot->_left = _left->cloneTree();
    copyRoot->_right = _right->cloneTree();
    return copyRoot;
}

template<typename T>
void Node<T>::DeleteTree()
{
    if(_left != nullptr)
    {
        _left->DeleteTree();
    }
    
    delete this;
    
    if(_right != nullptr)
    {
        _right->DeleteTree();
    }
}

template<typename T>
void Node<T>::SetData(T& value)
{
    _data = value;
}

template<typename T>
int Node<T>::GetData() const
{
    return _data;
}

template<typename T>
Node<T>* Node<T>::GetLeftNode() const
{
    return _left;
}

template<typename T>
void Node<T>::SetLeftNode(Node* left)
{
    _left = left;
}

template<typename T>
Node<T>* Node<T>::GetRightNode() const
{
    return _right;
}

template<typename T>
void Node<T>::SetRightNode(Node* right)
{
    _right = right;
}

