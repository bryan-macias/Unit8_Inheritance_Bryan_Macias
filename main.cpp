//Bryan Macias COSC 1437
//A program that calculates the price of college.
#include <iostream>
#include "functions.h"

using namespace std;
int main() 
{
  cout << fixed <<setprecision(2);  
  Semester full;
  Semester part;
  Semester half;

  char option = '\0';

  full.setCreditHour(12.0);
  part.setCreditHour(9.0);
  half.setCreditHour(6.0);

  do
  {
    showMenu(full, part, half);
    showOptions();
    option = validateChar(option);
    handleOption(full, part,half, option);

  }while(option != 'X' && option != 'x');

  cout << "Program Exited" << endl;  
return 0;
}