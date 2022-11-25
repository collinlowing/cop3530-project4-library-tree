#ifndef NODE_HPP
#define NODE_HPP

#include"Book.hpp"

class Node
{
  public:
    Node(Book* b, Node* l, Node* r);
    ~Node();
    void setBook(Book* b);
    Book* getBook();
    void setLeft(Node* c);
    Node* getLeft();
    void setRight(Node* c);
    Node* getRight();
  private:
    Book* book;
    Node* left;
    Node* right;
};

#endif
