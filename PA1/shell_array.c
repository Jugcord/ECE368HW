#include "shell_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long *Array_Load_From_File(char *filename, int *size)
{
    /* Open binary input file, dynamically allocate array of longs, put input file in array of longs
     * return array of longs, *filename is input file, *size is number of integers in array, fed from pa1.c
     */
    FILE* fp = fopen(filename,"r"); //filepointer reads binary file
    long *array = NULL;

    if(fp == NULL) //if file cannot be opened
    {
        fclose(fp);
        *size = 0;
        return NULL;
    }

    fseek(fp, 0, SEEK_END); //go to end of binary file
    *size = ftell(fp); //find total size of file

    if(size == 0) //if file is empty
    {
        fclose(fp);
        return array;
    }

    fseek(fp, 0, SEEK_SET); //back to beginning of file
    *size = *size / sizeof(long); //find number of longs
    array = (long*)malloc(*size * sizeof(long)); //dynamically allocate array of longs

    if(arr == NULL) //if malloc fails
    {
        fclose(fp);
        *size = 0;
        return NULL;
    }

    for(int i = 0; i < *size; i++)
    {
        fscanf(fp, "%ld", &array[i]); //read file 1 long at a time into array
    }

    fclose(fp);
    return array;
}

int Array_Save_To_File(char *filename, long *array, int size)
{
    /* saves array to filename, filename is output file
     * array is array, size is how many longs much be saved
     * return how many longs were saved in file
     */
    FILE* fp = fopen(filename, "w");
    if(*array == NULL || size == 0) //if array is NULL or size is 0
    {
        fclose(fp);
        return 0;
    }
    int i; //how many longs were saved in file
    for(i = 0; i < size; i++)
    {
        fprintf(fp, "%ld", array[i]); //print into output file
    }
    fclose(fp);
    return i;
}

void Array_Shellsort(long *array, int size, long *n_comp)
{

}