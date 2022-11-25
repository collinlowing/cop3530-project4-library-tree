#include"Tree.hpp"

void Tree::insert(Node* p, Book* b)
{
	if(root == nullptr)
		root = new Node(b, nullptr, nullptr);

	else if(p->getLeft() == nullptr && ((p->getBook()->getTitle().compare(b->getTitle())) > 0))
		p->setLeft(new Node(b, nullptr, nullptr));

	else if ((p->getRight() == nullptr) && ((p->getBook()->getTitle().compare(b->getTitle())) < 0))
		p->setRight(new Node(b, nullptr, nullptr));

	else if ((p->getBook()->getTitle().compare(b->getTitle())) > 0)
		insert(p->getLeft(), b);

	else
		insert(p->getRight(), b);
}

void Tree::insert(Book* b)
{
	insert(root, b);
}

void Tree::printDetail()
{
	std::cout <<"Available Books:" << std::endl;
	std::cout << printDetail(root) << std::endl;
}

std::string Tree::printDetail(Node* p)
{
	std::string str;
	if(p == nullptr)
	{
		return "";
	}
	else
	{
		str += printDetail(p->getLeft());
		str += p->getBook()->printBook();
		str += printDetail(p->getRight());
		return str;
	}
}

void Tree::printTitle()
{
	std::cout << "Available Books:" << std::endl;
	std::cout << printTitle(root);
}

std::string Tree::printTitle(Node* p)
{
	std::string str = "\n";
	if(p == nullptr)
	{
		return "";
	}
	else
	{
		str += printTitle(p->getLeft());
		str += p->getBook()->getTitle() + "\n";
		str += printTitle(p->getRight());
		return str;
	}
}

Book* Tree::search(std::string title)
{
	Node* p = search(title, root);
	if (p != nullptr)
	{
		return p->getBook();
	}
	else
	{
		return nullptr;
	}
}

Node* Tree::search(std::string title, Node* p)
{
	if (p != nullptr)
	{
		if (p->getBook()->getTitle().compare(title) == 0)
			return p;
		 else if (p->getBook()->getTitle().compare(title) < 0)
		{
			return search(title, p->getRight());
		}
		else
		{
			return search(title, p->getLeft());
		}
	}
	else
	{
		return nullptr;
	}
}

void Tree::garbage()
{
	garbage(root);
}

void Tree::garbage(Node* p) // Post order deletion of nodes in the tree
{
	if(p == NULL)
		return;

	garbage(p->getLeft());

	garbage(p->getRight());

	delete p;
}

