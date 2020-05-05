#include "Input_Validation_Extended.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

class Cost
{
  protected:
  double books = 100.00, food = 150.00, travel = 90.00, boarding = 400.00, rate = 59.00, creditHour = 12.00;
  public:
  Cost()
  {

  }
  //setters
  void setRate(double r)
  {
    rate = r;
  }
  void setCreditHour(double cr) 
  {
    creditHour = cr;
  }
  void setBooks(double b) 
  {
    books =b;
  }
  void setBoarding(double bo) 
  {
    boarding = bo;
  }
  void setFood(double f) 
  {
    food =f;
  }
  void setTravel(double t)
  {
    travel =t;
  }
  //getters
  double getrate() const 
  { 
    return rate;
  }
  double getCreditHour() const 
  {
    return creditHour;
  }
  double getBooks() const 
  {
    return books;
  }
  double getBoarding()const 
  {
    return boarding;
  }
  double getFood()const 
  {
    return food;
  }
  double getTravel()const
  {
    return travel;
  }  
};

class Semester: public Cost
{
  private:
    int hoursPerClass = 3, monthsInSemester = 4;
    int semesterInAYear = 3;
    double hoursInADegree = 60.0;
  public:
    Semester(): Cost(){}
  double tuition()
  {
    return (creditHour * rate);
  }
  double booksCost()
  {
    return ( (books * creditHour ) / hoursPerClass);
  }

  double boardingCost()
  {
    return (boarding * monthsInSemester);
  }

  double travelCost()
  {
    return (travel * monthsInSemester);
  }

  double foodCost()
  {
    return (food * monthsInSemester);
  }

  double semestersInAdegree()
  {
    return ( hoursInADegree/creditHour ); 
  }

  double costForDegree()
  {
    return (totalCost() * semestersInAdegree());  
  }

  double timeInYears()
  {
    return (semestersInAdegree() / semesterInAYear); 
  }

  double totalCost()
  {
    return (tuition() + booksCost() + boardingCost() + travelCost() + foodCost());
  }
  //setters
  void setMonthsInSemester( int mis) 
  {
    monthsInSemester = mis;
  }
  void setHoursPerClass( int hpc) 
  {
    hoursPerClass = hpc;
  }
  void setHoursInADegree(double dg)
  {
    hoursInADegree = dg;
  }
  void setSemestersInAYear(int sy) 
  {
    semesterInAYear = sy;
  }
  //getters
  int getMonthsInSemester() const 
  {
    return monthsInSemester;
  }
  int getHoursPerClass() const 
  { 
    return hoursPerClass;
  }
  double getHoursInADegree()const 
  {
    return hoursInADegree;
  }
  int getSemestersInAYear()const
  {
    return semesterInAYear;
  }  
};

//function for menu GUI
void showMenu(Semester full, Semester part, Semester half)
{
//actual code display with default values
//first chunk of code here is the FULL TIME COST PER SEMESTER
  cout << "FULL TIME COST PER SEMESTER: " << endl;
  cout <<"TUITION: $ " << full.tuition() <<(full.getrate() > 83.0 ? setw(52): setw(53)) <<  "Cost per credit hour: $" <<full.getrate() << endl;
  cout << "ROOM AND BOARD: $ " << full.boardingCost(); cout << setw(39) << "Hours per class: " << full.getHoursPerClass() <<endl;
  cout << "TRAVEL: $ " << full.travelCost(); cout <<setw(53) << "Months in a semester: " << full.getMonthsInSemester()<< endl;
  cout << "FOOD: $ " << full.foodCost(); cout << setw(50)  << "Full time hours: " <<full.getCreditHour() << endl;
  cout << "BOOKS: $ " << full.booksCost();cout <<setw(48) <<"Part time hours:" << part.getCreditHour()<< endl;
  cout << "TOTAL COST: $ " <<full.totalCost() <<(full.getrate() > 586.0 ? setw(42): setw(43))  << "Half time hours: "<<half.getCreditHour() <<endl;
  cout << setw(69) << "Book cost per class: $"<< full.getBooks();

//Chunk: PART TIME COST PER SEMESTER
  cout << "\nPART TIME COST PER SEMESTER:"; cout << setw(51) << "Room and Board cost per month: $" <<full.getBoarding()<< endl;
  cout << "TUITION: $" <<part.tuition()<<(full.getrate() > 111.0 ? setw(52): setw(53))  << "Food cost per month: $" <<full.getFood()<< endl;
  cout << "ROOM AND BOARD: $ " << part.boardingCost();cout << setw(46) << "Travel cost per month: $" <<full.getTravel()<< endl;
  cout << "TRAVEL: $ " << part.travelCost();cout << setw(52)<< "Semesters in a year: " << full.getSemestersInAYear()<< endl;
  cout << "FOOD: $ " << part.foodCost();cout <<setw(52)<< "Hours in a degree: " << full.getHoursInADegree()<< endl;
  cout << "BOOKS: $ " << part.booksCost() << endl;
  cout << "TOTAL COST: $ " <<part.totalCost() <<  setw(52) << "COST AND TIME PER DEGREE: " <<endl;
  cout << setw(56) <<"Time for " << full.getHoursInADegree()<< " hrs @ full time : " << full.semestersInAdegree() << " semesters" ;
//Chunk: HALF TIME COST PER SEMESTER
  cout << "\nHALF TIME COST PER SEMESTER: " <<setw(27) << "Time for " << full.getHoursInADegree()<< " hrs @ part time : " << part.semestersInAdegree() << " semesters" << endl;
  cout <<"TUITION: $ " << half.tuition() <<(full.getrate() > 166.0 ? setw(38): setw(39)) << "Time for " << full.getHoursInADegree()<< " hrs @ half time : " << half.semestersInAdegree() << " semesters" << endl;
  cout << "ROOM AND BOARD: $ " << half.boardingCost() <<setw(31) << "Cost for " << full.getHoursInADegree() << " hrs @ full time : $"  <<full.costForDegree() <<endl; 
  cout << "TRAVEL: $ " << half.travelCost() <<setw(40) << "Cost for " << full.getHoursInADegree() << " hrs @ part time : $"  <<part.costForDegree() << endl; 
  cout << "FOOD: $ " << half.foodCost() << setw(42) <<"Cost for " << full.getHoursInADegree() << " hrs @ half time : $"  <<half.costForDegree() << endl;
  cout << "BOOKS: $ " << half.booksCost() << setw(41) << "Time for " << full.getHoursInADegree() << " hrs @ full time : " << full.timeInYears()<< " years"<<endl; 
  cout << "TOTAL COST: $ " <<half.totalCost() << setw(35)  << "Time for " << full.getHoursInADegree() << " hrs @ part time : " << part.timeInYears()<< " years"<< endl;
  cout << setw(56) << "Time for " << full.getHoursInADegree() << " hrs @ half time : " << half.timeInYears()<< " years"<< endl;
}

//function for showing options to edit
void showOptions()
{
  cout << "\n|" << "EDIT OPTIONS";
  cout << "\n|\t\t\t\t\t\t                                      |";
  cout << "\n|" << " A - Cost Per Credit Class           " << " |";
  cout << "\n|" << " B - Hours Per Class                 " << " |";
  cout << "\n|" << " C - Months in a Semester            " << " |";
  cout << "\n|" << " D - Hours a full time student takes " << " |";
  cout << "\n|" << " E - Hours a part time student takes " << " |";
  cout << "\n|" << " F - Hours a half time student take  " << " |";
  cout << "\n|" << " G - Cost per book                   " << " |";
  cout << "\n|" << " H - Room and Boarding cost per month" << " |";
  cout << "\n|" << " I - Food cost per month             " << " |";
  cout << "\n|" << " J - Travel Cost per month           " << " |";
  cout << "\n|" << " K - Hours in a degree               " << " |";
  cout << "\n|" << " X - Exit Program                    " << " |";
  cout << "\n|______________________________________|" << endl;
  cout << "\n|" << "Enter an option to edit> " << endl;
}
//function to actually handle the choice and edit
void handleOption(Semester &full, Semester &part, Semester &half, char option)
{
  double r,h;
  int hours;

  if(option == 'A' || option == 'a')
  {
    cout <<"\nWhat is the new rate: " << endl;
    r = validateDouble(r);
    full.setRate(r);
    part.setRate(r);
    half.setRate(r);
  }

  else if(option == 'B' || option =='b')
  {
    cout << "\nHow many hours per class: " << endl;
    hours = validateInt(hours);
    full.setHoursPerClass(hours);
    part.setHoursPerClass(hours);
    half.setHoursPerClass(hours);
  }
else if(option == 'D' || option == 'd')
  {
    cout << "\nHow many hours does a full time student take: " << endl;
    h=validateDouble(h);
    full.setCreditHour(h);
  }
  else if (option == 'C' || option == 'c')
  {
    cout << "\nHow many months in a semeseter: " << endl;
    h=validateDouble(h);
    full.setMonthsInSemester(h);
    part.setMonthsInSemester(h);
    part.setMonthsInSemester(h);
  }
  else if(option == 'E' || option == 'e')
  {
    cout << "\nHow many hours does a part time student take: " << endl;
    h=validateDouble(h);
    part.setCreditHour(h);

  }
  else if(option == 'F' || option == 'f')
  {
    cout << "\nHow many hours does a half time student take: " << endl;
    h=validateDouble(h);
    half.setCreditHour(h);
  }
  else if(option == 'G' || option== 'g')
  {
    cout << "\nWhat is the new books cost: " << endl;
    h=validateDouble(h);
    full.setBooks(h);
    half.setBooks(h);
    part.setBooks(h);
  }
  else if(option == 'H' || option == 'h')
  {
    cout << "\nWhat is the new room and boarding cost: "<< endl;
    h=validateDouble(h);
    full.setBoarding(h);
    part.setBoarding(h);
    half.setBoarding(h);
  }
  else if(option == 'I' || option == 'i')
  {
    cout <<"\nWhat is the new food cost per month:"<< endl;
   h=validateDouble(h);
    full.setFood(h);
    part.setFood(h);
    half.setFood(h);
  }
  else if(option == 'J' || option == 'j')
  {
    cout <<"\nWhat is the new travel cost per month:"<< endl;
    h=validateDouble(h);
    full.setTravel(h);
    part.setTravel(h);
    half.setTravel(h);
  }
  else if(option == 'K' || option == 'k')
  {
    cout <<"\nHow many hours in a degree" << endl;
    hours = validateInt(hours);
    full.setHoursInADegree(hours);
    part.setHoursInADegree(hours);
    half.setHoursInADegree(hours);
  }
  else  
  {
    cout << "\nAn Error Occurred" << endl;
  }
}
#endif