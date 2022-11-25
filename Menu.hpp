#ifndef MENU_HPP
#define MENU_HPP

#include"Tree.hpp"
#include"Book.hpp"

#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

class Menu
{
private:
	std::string fileName = "bookData.txt";
	Tree tree;
public:
	bool readFile();
	void choiceMenu();
};

#endif
