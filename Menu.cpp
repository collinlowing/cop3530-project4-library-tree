#include "Menu.hpp"

bool Menu::readFile() // Read file
{
	std::ifstream in(fileName);

	if(in.is_open()) // Check if file is open
	{
		std::string line;

		while(getline(in, line)) // getting first line, always the title.
		{
			 std::string title = line;

			 std::string author;
			 getline(in, author);

			 std::string course;
			 getline(in, course);

			 std::string print;
			 getline(in, print);

			 std::string publisher;
			 getline(in, publisher);

			 int quantity;
			 in >> quantity;
			 if(in.fail()) 			// checks if next value is not an integer
			 {
				 in.clear();		// clears errors
				 getline(in, line);	// skips line*
				 continue;			// skips the book insertion
			 }
			 getline(in, line);		//skips line*
			 Book* newBook = new Book(title, author, course, print, publisher, quantity); // creates new book
			 tree.insert(newBook);	//inserts the new book
		}

		return true;
	}
	else
	{
		std::cout << "Could not read bookData.txt" << std::endl;
		std::cout << "Please try again." << std::endl;

		// returns false when file could not be opened
		return false;
	}
}

void Menu::choiceMenu()
{
	char choice;
	bool initialRun = true;

	while(choice != '7')
	{
		if(initialRun)	//checks for first run for welcome banner
		{
			initialRun = false;

			std::cout << "================================================================" 		<< std::endl;
			std::cout << std::setw(32) << "Welcome to Your Neighborhood Library" << std::setw(0) 	<< std::endl;
			std::cout << "================================================================" 		<< std::endl;
		}
		else // otherwise, outputs a newline only
		{
			std::cout << std::endl;
		}

		// Menu options
		std::cout << "Select an option (1 - 7):" 													<< std::endl;
		std::cout << std::setw(10) << "1: Check if a book is in the library system" << std::setw(0)	<< std::endl;
		std::cout 				   << "2: Show the names of all the books in the library" 			<< std::endl;
		std::cout 				   << "3: Show all the books with full details" 					<< std::endl;
		std::cout 				   << "4: Check if a book is currently available" 					<< std::endl;
		std::cout 				   << "5: Check out a book" 										<< std::endl;
		std::cout 				   << "6: Return a book" 											<< std::endl;
		std::cout 				   << "7: Exit the program" 										<< std::endl;
		std::cout << "================================================================" 			<< std::endl;
		std::cout << "Please enter your selection from the menu ->" 								<< std::endl;

		std::cin  >> choice;

		std::string line;
		getline(std::cin, line); // skips over line after choice

		switch(choice)
		{
		case '1': // Check if book is in library
		{
			std::cout << "Please type the exact title of the book for search:" << std::endl;
			std::string title;
			getline(std::cin, title);

			std::cout << std::endl;

			Book* found = tree.search(title);

			if (found != nullptr)
			{
				std::cout << found->getTitle() << " is in the library" << std::endl;
			}
			else
			{
				std::cout << "Book not found." << std::endl;
			}
			break;
		}

		case '2': // Show all books titles
		{
			tree.printTitle();
			break;
		}
		
		case '3': // Print all book details
		{
			tree.printDetail();
			break;
		}

		case '4': // Check book inventory
		{
			std::cout << "Please type the exact title of the book for search:" << std::endl;
			std::string title;
			getline(std::cin, title);

			std::cout << std::endl;

			Book* found = tree.search(title);

			if (found != nullptr)
			{
				std::cout << "Book found!" << std::endl;
				std::cout << found->getTitle() << " has " << found->getQuantity() << " available for check out." << std::endl;
			}
			else
			{
				std::cout << "Book not found." << std::endl;
			}
			break;
		}

		case '5': // Check out book
		{
			std::cout << "Please type the exact title of the book for checkout:" << std::endl;
			std::string title;
			getline(std::cin, title);

			std::cout << std::endl;

			Book* found = tree.search(title);

			if (found != nullptr)
			{
				if (found->checkOut())
				{
					std::cout << found->getTitle() << " is checked out. " << std::endl;
					std::cout << found->getQuantity() << " books are left in inventory." << std::endl;
				}
				else
				{
					std::cout << "Book could not be checked out." << std::endl;
				}
			}
			else
			{
				std::cout << "Book not found. Nothing was checked out." << std::endl;
			}
			break;
		}

		case '6': // Return a book
		{
			std::cout << "Please type the exact title of the book for return:" << std::endl;
			std::string title;
			getline(std::cin, title);

			std::cout << std::endl;

			Book* found = tree.search(title);

			if (found != nullptr)
			{
				if (found->returnBook())
				{
					std::cout << found->getTitle() << " is returned." << std::endl;
					std::cout << found->getQuantity() << " books are left in inventory." << std::endl;
				}
				else
				{
					std::cout << "Book could not be returned." << std::endl;
				}
			}
			else
			{
				std::cout << "Book not found. Nothing was checked out." << std::endl;
			}
			break;
		}

		case '7': // Exit program
		{
			std::cout << "Exiting program, goodbye!" << std::endl;
			tree.garbage();
			break;
		}

		default: // Error handling
			std::cout << "Invalid response, please choose a number between 1 and 7." << std::endl;
		}
	}
}
