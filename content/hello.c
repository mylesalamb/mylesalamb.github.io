#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define BACKSPACE '\r'  //ascii code for backspace
#define UPPER 126       //upper boundary for the chars we want to print
#define LOWER 32        //likewise lower
#define DELAY 10000     // 100ms sleep time

int main(void){

    //string we want to print to stdout
    const char * const target = "Hello World";
    const size_t len = strlen(target);
    char outstr[len+1];
    srand(time(NULL));
    
    for(int i = 0; i < len; i++){

        int cursor = (rand() % (UPPER - LOWER)) + LOWER;

        outstr[i+1] = '\0';
        //continuously try to print the right character to stdout
        //for nice effect
        while(1){

            //make sure the line is clear
            putc(BACKSPACE,stdout);
            fflush(stdout);

            outstr[i] = cursor; 
            printf("%s",outstr);

            if(cursor == target[i])
                break;

            if(++cursor > UPPER)
                cursor = LOWER;

            usleep(DELAY);
        }

    }	
    putc('\n',stdout);
}