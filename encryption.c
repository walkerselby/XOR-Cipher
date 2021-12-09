

#include "header.h"
#define READ_SIZE 100

int cipher(){
    FILE *fp1 = fopen(file1, "rb"); //open source file
    if(fp1 == NULL){
        error("The original file does not exist.");
        return -1;
    }
    FILE *fp2 = fopen(file2,"wb"); //open (or create) destination file

    if(fp2 == NULL){ //checking to make sure file was created.
        error("The destination file does not exist. Something went really wrong.");
        return -1;
    }

    int ret;
    char buffer[READ_SIZE] = {'\0'};//initialized to prevent garbage values
    char modified[READ_SIZE];
    while ((ret = (int) fread(buffer, sizeof(char),READ_SIZE, fp1)) > 0) {

        for (int i = 0; i < ret; i++) { //XOR the number of inputs from the buffer
            modified[i] = (char) (buffer[i] ^ keyC);
        }
        fwrite(modified,sizeof(char), ret, fp2);

    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
