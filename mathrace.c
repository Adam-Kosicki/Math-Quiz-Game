#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int counter = 0; // Variable to store the user's score

// Function to handle the alarm signal
void sig_alarm(int signo) {
    printf("Your score: %d\n", counter);
    exit(0);
}

int main() {
    // Seed the random number generator using a combination of time, process ID, and user ID
    srand(time(NULL) + getpid() + getuid());

    // Set up an alarm signal to trigger after 20 seconds
    alarm(20);

    // Infinite loop to generate and present addition problems
    while (1) {
        // Generate two random numbers in the range of 1-1000
        int num1 = rand() % 1000 + 1;
        int num2 = rand() % 1000 + 1;

        // Prompt the user with the addition problem
        printf("%d + %d ? ", num1, num2);
        int result = num1 + num2; // Calculate the correct result
        int input;

        // Read the user's input
        if (scanf("%d", &input) == 1) {
            // Compare the user's input with the correct result
            if (result == input) {
                puts("Great!");
                counter++; // Increment the score
            } else {
                printf("Not quite. Answer is %d.\n", result);
            }
        } else {
            exit(1); // Exit the program if input is not read properly
        }
    }

    return 0;
}
