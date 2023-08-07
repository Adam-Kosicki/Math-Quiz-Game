#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int counter=0;

void sig_alarm(int signo) {
    printf("Your score: %d\n", counter);
    exit(0);
}	


int main() {
    srand(time(NULL) + getpid() + getuid());
    alarm(20);
    while (1) {
        //generate 2 random numbers in the range of 1-1000
        int num1 = rand() % 1000 + 1;
        int num2 = rand() % 1000 + 1;
        //prompt the user
        printf( "%d + %d ? ", num1, num2);
        int result = num1 + num2;
        int input;
        if (scanf("%d", &input) == 1)
            if (result == input){
                puts("Great!");
		counter++;
	    }
            else
                printf( "Not quite. Answer is %d.\n", result);
        else
            exit(1);
    }
}

