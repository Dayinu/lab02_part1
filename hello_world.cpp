#include <iostream>
#include <string>

// Main program function
int
main()
{
    // Variable to store the name
    std::string name;
    
    // Prompt for user's name
    std::cout << "Enter your name: ";
    std::cin >> name;
    
    // Output greeting
    std::cout << "Hello world from " << name << std::endl;
    
    // Return success status
    return 0;
}
