#include "Book.hpp"

Book::Book(std::string title, std::string author, std::string course, std::string print, std::string publisher, int quantity)
{
	this->title = title;
	this->author = author;
	this->course = course;
	this->print = print;
	this->publisher = publisher;
	this->quantity = quantity;
	startingQuantity = quantity;
}

std::string Book::getTitle()
{
	return title;
}

int Book::getQuantity()
{
	return quantity;
}

bool Book::checkOut()
{
	if(quantity > 0)
	{
		quantity--;
		return true;
	}
	else
	{
		return false;
	}
}

bool Book::returnBook()
{
	if(quantity < startingQuantity) // only returns if books are less than starting amount
	{
		quantity++;
		return true;
	}
	else
	{
		return false;
	}
}

std::string Book::printBook()
{
	std::string out;
	out += title + ", by " + author + "\n";
	out += "\tSubject: " + course + "\n";
	out += "\tPublisher: " + publisher + "\n";
	out += "\t" + std::to_string(quantity) + ' ' + print + " copies available" + "\n";
	
	return out;
}

