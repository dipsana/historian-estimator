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
void clearBuffer();
int run(), reRun(), coRun(), isLeapYear(int year), daysInMonth(int month, int year), daysinYear(int year), swap(Date *min, Date *max), rectifyDates(Date *min, Date *max);
Date init(), compareDates(Date min, Date max);
long long compareDatesInDays(Date min, Date max);

int main()
{
    // Welcome user prompt
    puts("\nWelcome Historian! I'm your estimator based on Gregorian Calendar."
         "\nEnter any two dates separated by spaces in dd mm yyyy format for comparison."
         "\nYou may also enter negative or exceeding values to try my auto-correct feature (^-^)\n");
    // Continue on yes
    do
    {
        // Init: Min and max dates and their diff
        Date min, max, diff;

        printf("Enter Date 1 (dd mm yyyy): ");
        min = init();

        printf("Enter Date 2 (dd mm yyyy): ");
        max = init();

        // Exit if dates are equal
        if (rectifyDates(&min, &max) == -1)
            return 0;

        printf("\nMin Date: %02d/%02d/", min.day, min.month);
        (min.year < 0) ? printf("%d AD", -min.year) : printf("%d", min.year);
        puts(".");
        printf("Max Date: %02d/%02d/", max.day, max.month, max.year);
        (max.year < 0) ? printf("%d AD", -max.year) : printf("%d", max.year);
        puts(".");
        puts("\n*******************************************");

        // O/p 1: Days
        long long days = compareDatesInDays(min, max);
        printf("Difference between the two dates: %lld day%s.\n", days, (days > 1) ? "s" : "");

        // O/p 2: Date
        diff = compareDates(min, max);
        printf("Difference between the two dates: ");
        if (diff.year > 0)
            printf("%d year%s", diff.year, (diff.year > 1) ? "s" : "");
        else if (diff.year < 0)
            printf("%d year%s", diff.year, (diff.year < 1) ? "s" : "");

        if (diff.month > 0)
            printf(" %d month%s", diff.month, (diff.month > 1) ? "s" : "");

        if (diff.day > 0)
            printf(" %d day%s", diff.day, (diff.day > 1) ? "s" : "");

        puts(".");
    } while (coRun());
    puts("\nStay tuned for more features, bye...:)");
    return 0;
}

// Function Definitions:

// Clear input buffer
void clearBuffer()
{
    for (int c; (c = getchar()) != '\n' && c != EOF;);
}

// Safe date input with auto-correct
Date init()
{
    // Safe date input
    int day, month, year;
    do
    {
        while (scanf("%d %d %d", &day, &month, &year) != 3)
        {
            clearBuffer();
            printf("\nInvalid Entry! Please enter in dd mm yyyy format!\n");
        }
        clearBuffer();
    } while (reRun());

    // Init: auto-correct prompt
    int prompt = 0;

    // Check if dates will auto-correct
    if (day < 1 || month < 1 || month > 12)
        prompt = 1;
    else if (year < 0)
    {
        prompt = 1;
        year *= -1;
    }

    // Date auto-correct:
    if (day == 0) day = 1;
    if (month == 0) month = 1;

    // Adjust years if months exceed +12 or -12
    year += month / 12;

    // Adjust months & years if months is negative
    if (month < 0) month = 12 - (month % 12);

    // Adjust months if exceed 12
    if (month > 12) month %= 12;

    // Init: daysInMonth with further checks
    int DIM = daysInMonth(month, year);
    if (day > DIM) prompt = 1;

    // Adjust day if negative
    while (day < 0)
    {
        day += DIM;
        if (month < 1)
        {
            month = 12;
            year--;
        }
        DIM = daysInMonth(--month, year);
    }

    // Adjust day if exceed DIM
    while (day > DIM)
    {
        day -= DIM;
        if (month > 12)
        {
            month = 0;
            year++;
        }
        DIM = daysInMonth(++month, year);
    }

    // Re-enter (Y/N)? Prompt
    if (prompt)
    {
        printf("\nDate auto corrected: %02d/%02d/", day, month);
        (year < 0) ? printf("%d AD", -year) : printf("%d", year);
        puts(".");
    }

    // Assign date & Return
    Date d;
    d.day = day;
    d.month = month;
    d.year = year;
    return d;
}

// Swap & Rectify: min and max dates
int rectifyDates(Date *min, Date *max)
{
    if (min->year > max->year)
        return swap(min, max);

    if (min->year < max->year)
        return 0;

    if (min->month > max->month)
        return swap(min, max);

    if (min->month < max->month)
        return 0;

    if (min->day > max->day)
        return swap(min, max);

    if (min->day < max->day)
        return 0;

    printf("\nBoth the dates are the same! You have entered: %02d/%02d/%d.\n", min->day, min->month, min->year);
    return -1;
}

// Returns: 1 for successful swap
int swap(Date *min, Date *max)
{
    Date temp = *min;
    *min = *max;
    *max = temp;
    return 1;
}

int isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysinYear(int year)
{
    if (isLeapYear(year))
        return 366;
    return 365;
}

int daysInMonth(int month, int year)
{
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return 29; // Leap year
    return days[month];
}

// Compare two dates
Date compareDates(Date min, Date max)
{
    Date diff = {0};

    diff.year = max.year - min.year;    // Year difference
    diff.month = max.month - min.month; // Month difference
    diff.day = max.day - min.day;       // Day difference

    // Adjust day difference
    if (diff.day < 0)
    {
        diff.month--;
        diff.day += daysInMonth(min.month, min.year);
    }

    // Adjust months and years if months exceed 12
    if (diff.month < 0)
    {
        diff.year--;
        diff.month += 12;
    }
    return diff;
}

// Compare two dates in days
long long compareDatesInDays(Date min, Date max)
{
    long long days = 0;

    // 1: Calc leftover days in first & last month
    days += daysInMonth(min.month, min.year) - min.day + max.day;

    // 2: Convert months into days (remaining months of first year + passed months of last year)
    while (++min.month <= 12)
        days += daysInMonth(min.month, min.year);

    while (--max.month > 0)
        days += daysInMonth(max.month, max.year);

    // 3: Convert full years into days
    while (++min.year < max.year)
        days += daysinYear(min.year);

    return days;
}

int run()
{
    while (1)
    {
        char opt = tolower(getchar());
        if (opt == 'y')
            return 1;
        else if (opt == 'n')
            return 0;
        printf("\nEnter 'y' for yes and 'n' for no: ");
        clearBuffer();
    }
}

// re-enter (Y/N) prompt
int reRun()
{
    printf("\nDo you want to re-enter the date? (y/n): ");
    return run();
}

// compare (Y/N) prompt
int coRun()
{
    printf("\nDo you want to compare more dates? (y/n): ");
    clearBuffer();
    return run();
}
