Overly Complicated Hello World
##############################

:date: 2020-05-24 10:22
:modified: 2010-05-24 18:40
:tags: C
:category: Programming
:slug: overly-complicated-c
:authors: Myles
:summary: Boredom -> overly complicated C

I was bored so I wrote an overly complicated C program

.. code-block:: python
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

and some other stuff after the code