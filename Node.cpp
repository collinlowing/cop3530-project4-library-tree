#include"Node.hpp"

	Node::Node(Book* b, Node* l, Node* r)
	{
		book = b;
		left = l;
		right = r;
	}

    void Node::setBook(Book* b)
    {
    	book = b;
    }

    Book* Node::getBook()
    {
    	return book;
    }

    void Node::setLeft(Node* l)
    {
    	left = l;
    }

    Node* Node::getLeft()
    {
    	return left;
    }

    void Node::setRight(Node* r)
    {
    	right = r;
    }

    Node* Node::getRight()
    {
    	return right;
    }

    Node::~Node() // deletes Book pointers when nodes are deleted
    {
    	delete book;
    }
	
