    /*
  My name : waad
  Class : second 
  Department : computer
    
    */
#include <iostream>
#include <string>

int main()
{

      std::string name;
          std::string degry;
    std::string input;
  std::cout << "enter name ";
  getline (std::cin, name);
     std::cout << "enter name" << std::endl;
        std::cin >> input;
        if( input == "A" )
        {
           std::cout << "in control ";
        }
        else if( input == "T" )
        {
              std::cout << "in communications";
        }
           else if( input == "c" )
        {
              std::cout << " in computer";
        }
        else
        {
            std::cout << "The entrance section is not one of sections that belong to the university: " << input << std::endl;
        }
        return 0;
        }
    