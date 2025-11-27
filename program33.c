#include <stdio.h>

// Define structure for date
struct date {
    int day;
    int month;
    int year;
};

// Function to read a date in dd/mm/yyyy format
struct date readDate() {
    struct date d;
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d.day, &d.month, &d.year);
    return d;
}

// Function to display a date in dd/mm/yyyy format
void displayDate(struct date d) {
    printf("%02d/%02d/%04d\n", d.day, d.month, d.year);
}

// Function to compare two dates (equal or not)
int compareDates(struct date d1, struct date d2) {
    if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year)
        return 1;  // Dates are equal
    else
        return 0;  // Dates are not equal
}

int main() {
    struct date d1, d2;

    printf("Enter first date:\n");
    d1 = readDate();

    printf("Enter second date:\n");
    d2 = readDate();

    printf("\nFirst date: ");
    displayDate(d1);

    printf("Second date: ");
    displayDate(d2);

    if (compareDates(d1, d2))
        printf("\nThe two dates are equal.\n");
    else
        printf("\nThe two dates are not equal.\n");

    return 0;
}

