#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void print_time() {
    time_t raw_time;
    struct tm *time_info;
    char buffer[10];

    // Get the current time
    time(&raw_time);
    time_info = localtime(&raw_time);

    // Format the time in AM/PM format
    strftime(buffer, sizeof(buffer), "%I:%M %p", time_info);
    printf("Current time: %s\n", buffer);
}

// Function to print the current date
void print_date() {
    time_t raw_time;
    struct tm *time_info;
    char buffer[11];

    // Get the current time
    time(&raw_time);
    time_info = localtime(&raw_time);

    // Format the date in YYYY-MM-DD format
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", time_info);
    printf("Current date: %s\n", buffer);
}

// Function to display uptime of the device
void uptime() {
    FILE *file = fopen("/proc/uptime", "r");
    if (file == NULL) {
        perror("Error opening /proc/uptime");
        return;
    }

    double uptime_seconds;
    if (fscanf(file, "%lf", &uptime_seconds) != 1) {
        perror("Error reading uptime");
        fclose(file);
        return;
    }
    fclose(file);

    int hours = (int)(uptime_seconds / 3600);
    int minutes = (int)((uptime_seconds / 60)) % 60;
    int seconds = (int)uptime_seconds % 60;

    printf("Uptime: %d hours, %d minutes, %d seconds\n", hours, minutes, seconds);
}

// Function to perform basic math operations
void math() {
    double num1, num2;
    char operator[100];
    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);
    printf("Enter operator (+, -, *, /, sqrt , power): ");
    scanf("%s", operator);

    if (strcmp(operator, "+") == 0) {
        printf("Result: %.2lf\n", num1 + num2);
    } else if (strcmp(operator, "-") == 0) {
        printf("Result: %.2lf\n", num1 - num2);
    } else if (strcmp(operator, "*") == 0) {
        printf("Result: %.2lf\n", num1 * num2);
    } else if (strcmp(operator, "/") == 0) {
        if (num2 != 0) {
            printf("Result: %.2lf\n", num1 / num2);
        } else {
            printf("Error: Division by zero.\n");
        }
    } else if (strcmp(operator, "sqrt") == 0) {
        printf("Result: %.2lf\n", sqrt(num1));
    } else if (strcmp(operator, "power") == 0) {
        printf("Result: %.2lf\n", pow(num1, num2));
    } else {
        printf("Invalid operator.\n");
    }
    printf("More math operations coming soon.\n");
}

int main() {
    printf("\nWelcome to the ASERDEV App!\n");
    printf("1:time 2:date 3:math 4:exit 5:uptime\n");

    printf("More coming soon.\n");
    printf("Please select an option: ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            print_time();
            break;
        case 2:
            print_date();
            break;
        case 3:
            math();
            break;
        case 4:
            printf("Exiting the app.\n");
            return 0;
        case 5:
            uptime();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
    return 0;
}