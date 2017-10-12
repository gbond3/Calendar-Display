/***********************************************************************
* Program:
*    CS124
* Author:
*    Garrett Bond
* Summary: 
*    Below will display the user's desired month belonging to their
*    entered year.
*
*    Estimated:  8.0 hrs   
*    Actual:     9.0 hrs
*
*    The most difficult portion of the project was understanding how to
*    implement the isleapyear function.
*
************************************************************************/

#include <iostream>
using namespace std;

/******************************************************************
* Below will get the user's desired month.
*****************************************************************/
int getMonth()
{
   int month;
   do
   {
      cout << "Enter a month number: ";
      cin >> month;

      if ( month > 12 || month < 1)
         cout << "Month must be between 1 and 12." << endl;
   }
   while ( month > 12 || month < 1);
   return month;
}

/******************************************************************
* Below will get the user's desired year.
*****************************************************************/
int getYear()
{
   int year;
   do
   {
      cout << "Enter year: ";
      cin >> year;

      if ( year < 1753)
         cout << "Year must be 1753 or later." << endl;
   }
   while ( year < 1753);
   return year;
}

/**********************************************************************
* Below will determine when February is a leap year
***********************************************************************/
bool isLeapYear(int month, int year)
{
   if ( year % 4 != 0)
      return false;
   else if ( year % 100 != 0)
      return true;
   else if ( year % 400 != 0)
      return false;
   else
      return true;
}
                                            
/**********************************************************************
* Below will calculate the days in the entered month.
***********************************************************************/
int daysInMonth(int month, int year)
{
   if ( month == 9 || month == 4 || month == 6 || month == 11)
      return 30;
   else if ( month == 2 && isLeapYear(month, year))
      return 29;
   else if ( month == 2)
      return 28;
   else
      return 31;
}

/**********************************************************************
* Below will calculate the days in the desired year.
***********************************************************************/
int calculateNumberOfDaysThisYear(int targetMonth, int targetYear)
{
   int totalDays = 0;

   for ( int month = 1; month < targetMonth; month++)
      totalDays += daysInMonth(month, targetYear);

   return totalDays;
}


/**********************************************************************
* Below will calculate the days in a year depending if a leap year
* occurs.
***********************************************************************/
int calculateDaysInWholeYears(int month, int year)
{

   if ( isLeapYear(month, year))
      return 366;
   else
      return 365;
}

/**********************************************************************
* Below will calculate the days that have past for the offset.
***********************************************************************/
int calculateDaysPastThisYear(int targetMonth, int year)
{
   int daysPastThisYear = 0;



   for ( int month = 1;month < targetMonth; month++)
   {
      if ( month == 9 || month == 4 || month == 6 || month == 11)
         daysPastThisYear += 30;
      else if ( month == 2 && isLeapYear(month, year))
         daysPastThisYear += 29;
      else if ( month == 2)
         daysPastThisYear += 28;
      else
         daysPastThisYear += 31;
   }


   return daysPastThisYear;
}

/**********************************************************************
* Below will display the names of the month.
***********************************************************************/
void displayName(int month, int year)
{

   if ( month == 1)
      cout << "January";
   else if ( month == 2)
      cout << "February";
   else if ( month == 3)
      cout << "March";
   else if ( month == 4)
      cout << "April";
   else if ( month == 5)
      cout << "May";
   else if ( month == 6)
      cout << "June";
   else if ( month == 7)
      cout << "July";
   else if ( month == 8)
      cout << "August";
   else if ( month == 9)
      cout << "September";
   else if ( month == 10)
      cout << "October";
   else if ( month == 11)
      cout << "November";
   else if ( month == 12)
      cout << "December";

   cout << ", " << year << endl;
   

}

/**********************************************************************
* Below will calculate the offset for the positioning for the first
* day of the month.
***********************************************************************/
int calculateOffset(int month, int year)
{
   int daysInWholeYears = 0;

   for (int i = 1753; i < year; i++)
   {
      daysInWholeYears += calculateDaysInWholeYears(month, i);
   }
   daysInWholeYears += calculateDaysPastThisYear(month, year);   

   
   return daysInWholeYears % 7;
}


/**********************************************************************
* Below will display the formulated calendar.
***********************************************************************/
void display(int numDays,int offset)
{

   cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;

   if (offset != 6)
   {

      for (int i = 0; i <= offset; i++)
      {
         cout << "    ";
      }
   }
   for (int i = 1; i <= numDays; i++)
   {
      if ((offset + i) % 7 == 0 && i != 1)
      {
         cout << endl;
      }
      if (i < 10)
         cout <<  " ";

      cout << "  " << i;
   }
   cout << endl;
   return;
}

/**********************************************************************
* Below will display the desired month corresponding to the entered
* year by the user.
***********************************************************************/
int main()
{

   
   int month = getMonth();
   int year = getYear();
   cout << endl;
   displayName(month, year);
   int day = daysInMonth(month, year);
   int offset = calculateOffset(month, year);

  

   display(day, offset);
   
   
   return 0;
}
