// patients-cli.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void PrintHelp() 
{
    std::cout << std::endl;
    std::cout << "Usage: patients <command> <args>" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Commands:" << std::endl;
    std::cout << "list" << std::endl;
    std::cout << "add <first_name> <second_name> \"<medical_info>\"" << std::endl;
    std::cout << "delete <id>" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << std::endl;
}

int main()
{
    std::cout << "Welcome to the patient records CLI" << std::endl;
    PrintHelp();
}
