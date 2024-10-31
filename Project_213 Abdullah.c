//M. Abdullah Khan (021201036)

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int month, year;
    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Enter month (Two digit): ");
    scanf("%d", &month);

    if (year < 2000) {
        printf("\nError: Please enter from 2000!");
        return;
    }

    if (month < 1) {
        printf("\nError: Please enter from 01 to 12!");
        return;
    }

    int daysSinceJan2000 = 0, y, m;

    for (y = 2000, m = 1; y < year || m < month; m++) {

        daysSinceJan2000 += numOfDays(m, y);

        if (m == 12) {
            m = 0;
            y++;
        }
    }
    printf("\nYour selected month's calender:");
    printf("\n S  M  T  W  T  F  S\n");
    int dayOfWeek = (daysSinceJan2000 % 7) + 1;
    int p;
    for (p = 0; p < (dayOfWeek * 3) - 1; p++) {
        printf(" ");
    }

    int d,
        days = numOfDays(m, y);
    for (d = 1; d <= days; d++, dayOfWeek++) {
        if (dayOfWeek > 0) {
            printf (" %2d", d);
        } else {
            printf ("%2d", d);
        }
        if (dayOfWeek == 6) {
            dayOfWeek = -1;
            printf("\n");
        }
    }
}

int numOfDays(int m, int y)
{
    switch (m) {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if (y % 4 == 0 && ((y % 100) || (y % 400) == 0)) {
                return 29;
            } else {
                return 28;
            }
        default:
            return 31;
    }
    int month, day, year, prevyear, numdays;

    printf("Please enter a date for month-day-year: ");
    scanf("%d-%d-%d", &month, &day, &year);

    prevyear = ((year - 1) * 365 + ((year - 1)/4) - ((year - 1)/100) + ((year - 1)/400)) % 7;

    numdays = 0;

switch(month)
{
    case 12:
        numdays += 30;
        break;
    case 11:
        numdays += 31;
        break;
    case 10:
        numdays += 30;
        break;
    case 9:
        numdays += 31;
        break;
    case 8:
        numdays += 31;
        break;
    case 7:
        numdays += 30;
        break;
    case 6:
        numdays += 31;
        break;
    case 5:
        numdays += 30;
        break;
    case 4:
        numdays += 31;
        break;
    case 3:
        if ((!(year % 4) && (year % 100)) || ! (year % 400))
            numdays += 29;
        else numdays += 28;
        break;
    case 2:
        numdays += 31;
        break;


}

switch(day)
{
    case 6:
        printf("The day was Saturday");
break;
    case 5:
        printf("The day was Friday");
break;
    case 4:
        printf("The day was Thursday");
break;
    case 3:
        printf("The day was Wedensday");
break;
    case 2:
        printf("The day was Tuesday");
break;
    case 1:
        printf("The day was Monday");
break;
    case 0:
        printf("The day was Sunday");
break;
}
}
