#ifndef BOOK_HPP
#define BOOK_HPP

#include<string>

class Book
{
private:
	std::string title;
	std::string author;
	std::string course;
	std::string print;
	std::string publisher;
	int quantity;
	int startingQuantity;
public:
	Book(std::string title, std::string author, std::string course, std::string print, std::string publisher, int quantity);
	std::string getTitle();
	int getQuantity();
	bool checkOut();
	bool returnBook();
	std::string printBook();
};

#endif
