//------------------------------------------------------------------
// File: seconds.c
//   
// Description: This program takes a string indicating the time of day
//      as input and returns the number of seconds that have passed from 
//      the beginning of the day until the entered time. It also counts 
//      how many of each digit appear in the input.
//       
// Syntax:
//      This program takes in a string in the form HH:MM:SS, where HH 
//      indicates the hour, MM the minutes and SS the seconds of the 
//      'current' time.  It prints to the screen the time entered, the 
//      number of seconds that have passed and the number of each digit
//      in the input as its output in the following style:
//
//      Hour   = 'HH'
//      Minute = 'MM'
//      Second = 'SS'
//      ------------
//      Total  =  XX seconds
//
//      Number of '0' = x
//                '1' = x
//                '2' = x
//                '3' = x
//                '4' = x
//                '5' = x
//                '6' = x
//                '7' = x
//                '8' = x
//                '9' = x
//
//-------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define VALID_ARGS 2
#define VALID_LEN 8
#define TIME_ARG 1
#define HOUR_DIG_1 0
#define HOUR_DIG_2 1
#define MINUTE_DIG_1 3
#define MINUTE_DIG_2 4
#define SECOND_DIG_1 6
#define SECOND_DIG_2 7
#define TIME_SEPARATOR_1 2
#define TIME_SEPARATOR_2 5


int main(int argc, char * argv[])
{
        // -----------------------------------------
        // Creation of local variables 
        // -----------------------------------------
        
        int digits[10] = {0,0,0,0,0,0,0,0,0,0};
        char hourst[3] = {0,0};
        char minutest[3] = {0,0};
        char secondsst[3] = {0,0};
        long int hour;
        long int minute;
        long int seconds;
        long int total;

        // -----------------------------------------
        // Checking of input validity
        // -----------------------------------------

        // Verify valid number of arguments 

        if (argc != VALID_ARGS){
                printf("Error. Invalid number of inputs.\n");
                exit (-1);

        }

        // Verify that time argument is the correct length 

        if (strlen(argv[TIME_ARG]) != VALID_LEN){
                printf("Error. Invalid input length.\n");
                exit (-1);
        }        
        
        // Verify each element of the time input and count the digits 

        for (int i=0; i<8; ++i){
                
                // Check that there are digits in the digit slots
              
                if ((i!=TIME_SEPARATOR_1) && (i!=TIME_SEPARATOR_2)){
                        
                        // Increment the counter for each digit seen

                        if (isdigit(argv[TIME_ARG][i])){

                                digits[argv[TIME_ARG][i]-'0'] += 1;

                        // Report error and exit if not a digit
                        
                        } else {
                                printf("Error. %c is not a digit.\n",
                                       argv[TIME_ARG][i]);
                                exit (-1);
                        }
                }       
                
                // Check that the time separators are ':'
                // Print an error and exit if they are not

                if ((i==TIME_SEPARATOR_1) || (i==TIME_SEPARATOR_2)){
                        if (argv[TIME_ARG][i] != ':'){
                                printf("Error. Invalid time separator.\n");
                                exit (-1);
                        }
                }
        };

        // ----------------------------------------------------
        // Calculation and output sections
        // ----------------------------------------------------

        // Parse the input to separate the hour, minutes and seconds 

        hourst[0] = argv[TIME_ARG][HOUR_DIG_1]; 
        hourst[1] = argv[TIME_ARG][HOUR_DIG_2]; 

        minutest[0] = argv[TIME_ARG][MINUTE_DIG_1]; 
        minutest[1] = argv[TIME_ARG][MINUTE_DIG_2];

        secondsst[0] = argv[TIME_ARG][SECOND_DIG_1]; 
        secondsst[1] = argv[TIME_ARG][SECOND_DIG_2];

        // Convert the above into long integers

        hour = strtol(hourst, NULL, 10);

        minute = strtol(minutest, NULL, 10);

        seconds = strtol(secondsst, NULL, 10);

        // Error checking for proper range for hour, minutes and seconds

        if ((hour < 0) || (hour > 23)){
                printf("Error.  Hours is not in the" 
                        " proper range (0-23).\n");
                exit (-1);
        }
        if ((minute < 0) || (minute > 59)){
                printf("Error.  Minutes is not in the" 
                        " proper range (0-59).\n");
                exit (-1);
        }
        if ((seconds < 0) || (seconds > 59)){
                printf("Error.  Seconds is not in the"
                       " proper range (0-59).\n");
                exit (-1);
        }

        // Calculate the total seconds that have passed 

        total = 3600 * hour + 60 * minute + seconds;

        // Format and print the output

        printf("\n");
        printf("Hour    = '%s'\n", hourst);
        printf("Minute  = '%s'\n", minutest);
        printf("Second  = '%s'\n", secondsst);
        printf("--------------\n");
        printf("Total   = %li seconds\n", total);
        printf("\n");
        printf("Number of '0' = %i\n", digits[0]);
        printf("          '1' = %i\n", digits[1]);
        printf("          '2' = %i\n", digits[2]);
        printf("          '3' = %i\n", digits[3]);
        printf("          '4' = %i\n", digits[4]);
        printf("          '5' = %i\n", digits[5]);
        printf("          '6' = %i\n", digits[6]);
        printf("          '7' = %i\n", digits[7]);
        printf("          '8' = %i\n", digits[8]);
        printf("          '9' = %i\n", digits[9]);
        printf("\n");

        return 0;

}
