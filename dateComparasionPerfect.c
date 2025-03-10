// Program to compare two dates
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Date Structure
typedef struct Date
{
    int day;
    int month;
    int year;
} Date;

// Function Prototypes:
int isLeapYear(int year);
int daysInMonth(int month, int year);
int daysinYear(int year);
int compareDates(Date date1, Date date2, Date *high, Date *low);
long calculateDurationDays(Date high, Date low);
Date calculateDuration(Date high, Date low);
Date initialize();
char continuation();

int main()
{
    // Continue on yes
    do
    {
        Date date1, date2, high, low, dateDiff; // Store two dates, high and low dates and the difference between two dates

        printf("\nEnter the two dates to compare in 'dd mm yyyy' format.\n");
        // I/p date 1
        printf("Enter Date 1 (dd mm yyyy): ");
        date1 = initialize();

        // I/p date 2
        printf("Enter Date 2 (dd mm yyyy): ");
        date2 = initialize();

        if (compareDates(date1, date2, &high, &low) == -1) // Store high and low dates
            return 0;                                      // Exit if dates are equal

        // O/p 1: Days
        long days = calculateDurationDays(high, low);
        printf("\nHigh Date: %02d/%02d/%04d.\nLow Date: %02d/%02d/%04d.\n", high.day, high.month, high.year, low.day, low.month, low.year);
        printf("\n*******************************************\n");
        printf("Difference between the two dates: %d day%s.\n", days, (days > 1) ? "s" : "");

        // O/p 2: Date Difference
        dateDiff = calculateDuration(high, low);
        printf("Difference between the two dates:");
        if (dateDiff.year > 0)
            printf(" %d year%s", dateDiff.year, (dateDiff.year > 1) ? "s" : "");

        if (dateDiff.month > 0)
            printf(" %d month%s", dateDiff.month, (dateDiff.month > 1) ? "s" : "");

        if (dateDiff.day > 0)
            printf(" %d day%s.\n", dateDiff.day, (dateDiff.day > 1) ? "s" : "");

    } while (continuation() == 'y');
    printf("\nExiting the program...\n");
    return 0;
}

// Function Descriptions:
// Initialize a date error free
Date initialize()
{
    Date date;
    while (scanf("%02d %02d %04d", &date.day, &date.month, &date.year) != 3)
    {
        // Clear input buffer
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        date = (Date){0};                                                // Reset dates
        printf("\nInvalid Entry! Please enter in dd mm yyyy format!\n"); // Error Statement
    }

    // Date Validation Check
    if (date.day < 1 || date.day > daysInMonth(date.month, date.year) || date.month < 1 || date.month > 12)
    {
        printf("\nInvalid Date! Please try again.\n");
        return initialize();
    }
    return date;
}

// Identify high and low dates
int compareDates(Date date1, Date date2, Date *high, Date *low)
{
    if (date1.year > date2.year)
    {
        *high = date1;
        *low = date2;
    }
    else if (date1.year < date2.year)
    {
        *high = date2;
        *low = date1;
    }
    else if (date1.month > date2.month)
    {
        *high = date1;
        *low = date2;
    }
    else if (date1.month < date2.month)
    {
        *high = date2;
        *low = date1;
    }
    else if (date1.day > date2.day)
    {
        *high = date1;
        *low = date2;
    }
    else if (date1.day < date2.day)
    {
        *high = date2;
        *low = date1;
    }
    else
    {
        printf("\nBoth the entered dates are the same! You have entered: %02d/%02d/%04d.\n", date1.day, date1.month, date1.year);
        return -1;
    }
    return 0;
}

// Check if a year is a leap year
int isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Calculate the no. of days of a given year
int daysinYear(int year)
{
    if (isLeapYear(year))
    {
        return 366; // Leap year
    }
    return 365;
}

// Calculate the no. of days in a given month of a given year
int daysInMonth(int month, int year)
{
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
    {
        return 29; // Leap year
    }
    return days[month];
}

// Difference between two dates
Date calculateDuration(Date high, Date low)
{
    Date dateDiff = {0}; // Set dateDiff parameters to 0
    int temp;            // Store temp values

    // Count day difference
    temp = daysInMonth(low.month, low.year);
    dateDiff.day = temp - low.day + high.day;
    if (dateDiff.day >= temp)
    {
        dateDiff.month++;
        dateDiff.day -= temp;
    }
    low.month++; // NOTE: Only one month is adjusted not two.

    // Count month difference
    dateDiff.month += 12 - low.month + high.month;
    low.year++; // NOTE: Only one year is adjusted not two.

    // Adjusting months and years if months exceed 12
    dateDiff.year += dateDiff.month / 12;
    dateDiff.month %= 12;

    // Count year difference
    dateDiff.year += high.year - low.year;
    return dateDiff;
}

// Difference between two dates in days
long calculateDurationDays(Date high, Date low)
{
    long days = 0;

    // Equalizing the day parameter of both the dates. In simple terms, days in dd2 - dd1 accurately.
    days = daysInMonth(low.month, low.year) - low.day + high.day;
    low.month++;
    high.month--;

    // Equalizing the month parameter of both the dates. In simple terms, days in mm2 - mm1 accurately.
    while (low.month < 13)
    {
        days += daysInMonth(low.month, low.year);
        low.month++;
    }
    while (high.month > 0)
    {
        days += daysInMonth(high.month, high.year);
        high.month--;
    }
    low.year++;

    // Calculate the leftover days via year difference of both the dates. In simple terms, days in yyyy2 - yyyy1 accurately.
    while (low.year < high.year)
    {
        days += daysinYear(low.year++);
    }
    return days;
}

// Re-compare? (Y/N) prompt
char continuation()
{
    char choice = 'y';
    do
    {
        printf("\nDo you want to compare another date (y/n)?: ");
        scanf(" %c", &choice);
        choice = tolower(choice);
    } while (choice != 'y' && choice != 'n');
    return choice;
}
