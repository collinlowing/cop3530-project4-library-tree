#ifndef TREE_HPP
#define TREE_HPP
#include"Node.hpp"
#include"Book.hpp"
#include<iostream>
#include<string>

class Tree
{
  public:
    void insert(Book* b);
    Book* search(std::string title);
    Node* search(std::string title, Node* p);
    void printTitle();
    void printDetail();
    void garbage();
    void garbage(Node* p);
  private:
    void insert(Node* root, Book* b);
    std::string printTitle(Node* p);
    std::string printDetail(Node* p);
    Node* root = nullptr;
};

#endif
