#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "heapsort.hh"

void interactive_test(std::istream& is, std::ostream& os)
{
    using namespace Asd;
    std::string command, line;
    std::stringstream stream;
    int arg;

    std::vector<int> numbers;
    
    while(is.good())
    {
	std::getline(is, line);
	if(!is.good())
	    break;

	stream.clear();
	stream.str(line + ' ');
	command = "";
	stream >> command;
	
	if(command == "")
	    continue;

	if(command == "insert")
	{
	    while(stream.good())
	    {
		stream >> arg;
		if(stream.good())
		    numbers.push_back(arg);
	    }
	}
	else if(command == "clear")
	{
	    numbers.clear();
	}
	else if(command == "print")
	{
	    for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
		os << *it << " ";
	    
	    os << std::endl;
	}
	else if(command == "sort")
	{
	    int* tab = new int[numbers.size()];
	    
	    for(unsigned int i = 0; i < numbers.size(); ++i)
		tab[i] = numbers[i];

	    heapsort(tab, numbers.size());
	    
	    for(unsigned int i = 0; i < numbers.size(); ++i)
		os << tab[i] << " ";

	    os << std::endl;

	    delete tab;	    
	}
	else if(command == "quit")
	{
	    break;
	}
	else if(command == "help")
	{
	    os << "Valid commands:\n"
	       << "\t insert int [int ...]\n"
	       << "\t clear\n"
	       << "\t print\n"
	       << "\t sort\n"
	       << "\t quit\n"
	       << "\t help"
	       << std::endl;
	}
	else
	{
	    os << "Invalid command '" << command << "'. Type 'help' for the list of valid commands." << std::endl;
	}
    }
}

int main()
{
    interactive_test(std::cin, std::cout);
    
    return 0;
}
