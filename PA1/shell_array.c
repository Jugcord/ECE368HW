#include "shell_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long *Array_Load_From_File(char *filename, int *size)
{
    /*
     *
     *
     */
    FILE* fp = fopen(filename,"r"); //filepointer reads binary file
    fseek(fp, 0, SEEK_END); //go to end of binary file
    size = ftell(fp); //find total size of file
    fseek(fp, 0, SEEK_SET); //back to beginning of file
    size = size
}

int Array_Save_To_File(char *filename, long *array, int size)
{

}