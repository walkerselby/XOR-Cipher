//Walker Selby - 7 December 2021
//Helper functions for easy debug and error messages with color.

#include "header.h"

void debug(const char* message){ //General Debug
    if(debugMode != true ) return;
    printf("\033[1;35m"); //Set the text to the color (Bold Purple)
    printf("Debug: %s\n",message); //Display text
    printf("\033[0m"); //Resets the text to default color
}

void debugInt(const char* message, int val){ //debug for messages with an int
    if(debugMode != true) return;
    printf("\033[1;35m"); //bold purple
    printf("Debug: %s %d\n",message, val);
    printf("\033[0m");
}

void debugStr(const char* message, const char *str){ //debug for messages with a string
    if(debugMode != true) return;
    printf("\033[1;35m");
    printf("Debug: %s %s\n",message, str); //bold purple
    printf("\033[0m");
}

void error(const char* message){ //Error message builder
    printf("\033[1;31m"); //bold red
    printf("Error: %s\n",message);
    printf("\033[0m");
}
