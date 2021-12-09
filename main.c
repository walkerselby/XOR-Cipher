//Walker Selby - 7 December 2021
//This program uses XOR to cipher or decrypt a file and export the encrypted values as a new file.
//Program arguments: ./project.out <key> <file1> <file2> [Debug Messages? true/false]
//Key is a value from 0 to 255

#include "header.h"

int main(int argc, char *argv[]) {
    debugMode = false; //initialization of debugMode to false

    if (argc <= 2){ //If too few arguments
        error("Too few arguments provided! Please provide a keyInt and two file names.");
        return -1;

    } else if(argc >= 5){ //5 to check if there is the debug flag

        if(strcmp(argv[4],"true") == 0){ //Debug mode
            debugMode = true;
            debug("Debug Mode Enabled");
        } else { //Else too many arguments provided
            error("Too many arguments provided! Please provide a keyInt and two file names. ");
            return -2;
        }

    }

    keyC = *argv[1]; //Saving the char for use in XOR
    int keyInt = atoi(argv[1]); //setting keyInt to value; could use strtol to prevent conversion errors
    debugInt("Key is", keyInt);

    if(keyInt > 255 || keyInt < 0){ //Making sure the key is within 0 and 255, so it is only 1 byte
        error("Key out of range! Use a keyInt between 0 and 255");
        return -3;
    }


    file1 = argv[2]; //saving file 1 name
    debugStr("File 1:",file1);
    file2 = argv[3]; //saving file 2 name
    debugStr("File 2:",file2);

    FILE *fp = fopen(file1, "rb"); //seeing if file is there but NOT creating
    if(fp == NULL){
        error("The original file does not exist.");
        return -4;
    }
    fclose(fp);

    return cipher(); //Returns an error value if it does not run properly.
}