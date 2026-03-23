# Age Calculator in C

A simple command-line C program that calculates a person's exact age in years, months, and days based on their birth date and the current date.

---

## Features

- Validates birth date and current date inputs
- Detects and announces leap year births
- Calculates precise age broken down into years, months, and days
- Handles month-end borrowing correctly during subtraction

---

## Files

```
age_calculator.c   - Main source file containing all logic
README.md          - This file
```

---

## Requirements

- A C compiler such as `gcc` or `clang`
- Standard C library (`stdio.h`, `stdlib.h`)

---

## Compilation

```bash
gcc age_calculator.c -o age_calculator
```

---

## Usage

Run the compiled program:

```bash
./age_calculator
```

You will be prompted to enter two dates in `Day Month Year` format:

```
Enter birth date (Date Month Year): 15 8 1998
Hey! You were born in a leap year!
Enter current date (Date Month Year): 23 3 2026

Your age is: 27 years, 7 months, and 8 days.
```

---

## Input Format

Both dates must be entered as three space-separated integers:

```
Day Month Year
```

| Field  | Example | Range              |
|--------|---------|--------------------|
| Day    | 23      | 1 – 28/29/30/31    |
| Month  | 3       | 1 – 12             |
| Year   | 2026    | Any valid year     |

The program will print `Enter correct details!` and exit if an invalid date is provided (e.g., month 13, or day 31 in April).

---

## How It Works

### Leap Year Check (`LeapYear`)
A year is a leap year if it is divisible by 4 but not by 100, or divisible by 400.

### Days in Month (`getMonthDays`)
Returns the correct number of days for a given month and year, accounting for leap years in February.

### Date Validation (`CorrectDetails`)
Ensures the month is between 1–12 and the day does not exceed the maximum for that month.

### Age Calculation (`main`)
1. Reads and validates the birth date.
2. Checks if the birth year is a leap year and notifies the user.
3. Reads and validates the current date.
4. If the current day is less than the birth day, borrows days from the previous month.
5. If the current month is less than the birth month, borrows 12 months from the previous year.
6. Subtracts birth date from current date to get age in years, months, and days.

---

## Limitations

- Does not validate that the current date is after the birth date.
- Does not handle negative ages if the current date is earlier than the birth date.
- Year input is not bounded; very large or negative years are accepted as-is.

---

## License

This project is free to use and modify for educational purposes.
