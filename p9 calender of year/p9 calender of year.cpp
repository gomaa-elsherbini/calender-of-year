#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;



short readNumber(string msg)
{
    short num;

    cout << msg;
    cin >> num;

    return num;
}

short orderOfDay(short year, short month, short day)
{
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + (12 * a) - 2;

    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

bool isLeapYear(short year)
{
    return (year % 400 == 0 || ((year % 4 == 0) && (year % 100 != 0)));
}

short numberOfDaysInMonth(short year, short month)
{
    if (month == 2)
    {
        if (isLeapYear(year))
            return  29;
        else
            return  28;
    }

    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return  31;

    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;

    else
        return 0;
}

string nameOfMonth(short month)
{
    string arrOfMonths[12] = { "Jan", "Feb", "Mar", "App", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

    return arrOfMonths[month - 1];
}

string nameOfDay(short order)
{
    string arrOfDaysNames[7] = { "Sun","Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return arrOfDaysNames[order];
}

void distributeMonthDays(short year, short month)
{
    short days = numberOfDaysInMonth(year, month);

    short firstDayOrder = orderOfDay(year, month, 1);

    for (int i = 1; i <= firstDayOrder; i++)
        printf("     ");

    for (int x = 1; x <= days; x++)
    {
        printf("%5d", x);
        if ((x + firstDayOrder) % 7 == 0)
            cout << endl;
    }
    cout << endl;
}

void printMonthCalender(short year, short month)
{
    cout << "  ______________ " << nameOfMonth(month) << " ______________\n\n";

    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    distributeMonthDays(year, month);

    cout << "  _________________________________\n\n";
}

void printYearCalender(short year)
{
    cout << "  _________________________________\n\n";
    cout << "           Calender - " << year << "\n";
    cout << "  _________________________________\n\n";
 
    for (short month = 1; month <= 12; month++)
        printMonthCalender(year, month);
}

int main()
{
    short year = readNumber("\nPlease Enter a year? ");

    printYearCalender(year);
    //printYearCalender(2023);

    system("pause>0");

    return main();

}