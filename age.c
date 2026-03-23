#include <stdio.h>
#include <stdlib.h>

int LeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getMonthDays(int month, int year) {
    switch (month) {
        case 1: return 31;
        case 2: return LeapYear(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;
    }
}

int CorrectDetails(int day, int month, int year) {
    if (month < 1 || month > 12) return 0;
    int maxDays = getMonthDays(month, year);
    return day >= 1 && day <= maxDays;
}

int main() {
    int birthday, birthmonth, birthyear;
    int currentday, currentmonth, currentyear;
    int ageday, agemonth, ageyear;

    printf("Enter birth date (Date Month Year): ");
    scanf("%d %d %d", &birthday, &birthmonth, &birthyear);

    if (!CorrectDetails(birthday, birthmonth, birthyear)) {
        printf("Enter correct details!\n");
        return 1;
    }

    if (LeapYear(birthyear)) {
        printf("Hey! You were born in a leap year!\n");
    }

    printf("Enter current date (Date Month Year): ");
    scanf("%d %d %d", &currentday, &currentmonth, &currentyear);

    if (!CorrectDetails(currentday, currentmonth, currentyear)) {
        printf("Enter correct details!\n");
        return 1;
    }

    if (currentday < birthday) {
        currentmonth -= 1;
        if (currentmonth == 0) {
            currentmonth = 12;
            currentyear -= 1;
        }
        currentday += getMonthDays(currentmonth, currentyear);
    }

    if (currentmonth < birthmonth) {
        currentmonth += 12;
        currentyear -= 1;
    }

    ageday = currentday - birthday;
    agemonth = currentmonth - birthmonth;
    ageyear = currentyear - birthyear;

    printf("\nYour age is: %d years, %d months, and %d days.\n", ageyear, agemonth, ageday);

    return 0;
}