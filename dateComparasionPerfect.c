// Program to compare two dates
#include <stdio.h>
#include <stdlib.h>

// Structure data type to store a date
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
int calculateDurationDays(Date high, Date low);
int compareDates(Date date1, Date date2, Date *high, Date *low);
Date calculateDuration(Date high, Date low);
Date initialize();

int main()
{
    Date date1, date2; // To store two dates
    Date high, low;    // To store high and low months
    Date dateDiff;     // To store difference between two dates

    printf("\nEnter the two dates to compare in 'dd mm yyyy' format.\n");
    // Input date 1
    printf("Enter Date 1 (dd mm yyyy): ");
    date1 = initialize();

    // Input date 2
    printf("Enter Date 2 (dd mm yyyy): ");
    date2 = initialize();

    if (compareDates(date1, date2, &high, &low) == -1) // Store high and low months
        return 0;                                      // Exit program if dates are equal

    // Output 1
    printf("\nHigh Date: %02d/%02d/%04d.\nLow Date: %02d/%02d/%04d.\n", high.day, high.month, high.year, low.day, low.month, low.year);
    printf("\n*******************************************\n");
    printf("Difference between the two dates: %d days.\n", calculateDurationDays(high, low));

    // Output 2
    dateDiff = calculateDuration(high, low);
    printf("Difference between the two dates:");
    if (dateDiff.year > 0)
        (dateDiff.year > 1) ? printf(" %d years", dateDiff.year) : printf(" %d year", dateDiff.year);

    if (dateDiff.month > 0)
        (dateDiff.month > 1) ? printf(" %d months", dateDiff.month) : printf(" %d month", dateDiff.month);

    if (dateDiff.day > 0)
        (dateDiff.day > 1) ? printf(" %d days", dateDiff.day) : printf(" %d day", dateDiff.day);

    printf(".\n");
    return 0;
}

// Function Descriptions:
// To initialize a date error free
Date initialize()
{
    Date date;
    // Initialize Error Free
    while (scanf("%02d %02d %04d", &date.day, &date.month, &date.year) != 3)
    {
        // Clear input buffer
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
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

// To compare two dates and identify which is higher or lower
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

// To check if a year is a leap year
int isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// To calculate the no. of days of a given year
int daysinYear(int year)
{
    if (isLeapYear(year))
    {
        return 366; // Leap year
    }
    return 365;
}

// To calculate the no. of days in a given month of a given year
int daysInMonth(int month, int year)
{
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
    {
        return 29; // Leap year
    }
    return days[month];
}

// To calculate the difference between two dates
Date calculateDuration(Date high, Date low)
{
    Date dateDiff = {0}; // Set dateDiff parameters to 0
    int temp;            // To store temp values

    // Counting the no. of days
    temp = daysInMonth(low.month, low.year);
    dateDiff.day = temp - low.day + high.day;
    if (dateDiff.day >= temp)
    {
        dateDiff.month++;
        dateDiff.day -= temp;
    }
    low.month++; // NOTE: In total only one month is gone not two.

    // Counting the no. of months
    dateDiff.month += 12 - low.month + high.month;
    low.year++; // NOTE: In total only one year is gone not two.

    // Adjusting months and years if months exceed 12
    dateDiff.year += dateDiff.month / 12;
    dateDiff.month %= 12;

    // Counting the no. of years
    dateDiff.year += high.year - low.year;
    return dateDiff;
}

// To calculate the difference in days between two dates
int calculateDurationDays(Date high, Date low)
{
    int days = 0;

    // Equalizing the day parameter of both the dates. In simple terms counting days in dd.
    days = daysInMonth(low.month, low.year) - low.day + high.day;
    low.month++;
    high.month--;

    // Equalizing the month parameter of both the dates. In simple terms counting days in mm.
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

    // Finally calculating the leftover days via year difference of both the dates. In simple terms counting days in yyyy.
    while (low.year < high.year)
    {
        days += daysinYear(low.year++);
    }

    return days;
}