#include "shell_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long *Array_Load_From_File(char *filename, int *size)
{
    /* Open binary input file, dynamically allocate array of longs, put input file in array of longs
     * return array of longs, *filename is input file, *size is number of integers in array, fed from pa1.c
     */
    FILE* fp = fopen(filename,"rb"); //filepointer reads binary file
    long *array = NULL;

    if(fp == NULL) //if file cannot be opened
    {
        fclose(fp);
        *size = 0;
        return NULL;
    }

    fseek(fp, 0, SEEK_END); //go to end of binary file
    *size = ftell(fp); //find total size of file

    if(*size == 0) //if file is empty
    {
        fclose(fp);
        return array;
    }

    fseek(fp, 0, SEEK_SET); //back to beginning of file
    *size = *size / sizeof(long); //find number of longs
    array = (long*)malloc(*size * sizeof(long)); //dynamically allocate array of longs

    if(array == NULL) //if malloc fails
    {
        fclose(fp);
        *size = 0;
        return NULL;
    }

  
    fread(array, sizeof *array, *size, fp); //read file 1 long at a time into array
    

    fclose(fp);
    return array;
}

int Array_Save_To_File(char *filename, long *array, int size)
{
    /* saves array to filename, filename is output file
     * array is array, size is how many longs much be saved
     * return how many longs were saved in file
     */
    FILE* fp = fopen(filename, "wb");
    if(array == NULL || size == 0) //if array is NULL or size is 0
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

int helper_Generate_Seq(int seq_start, int size)
{
    while (seq_start < size)
    {
        seq_start = seq_start * 3 + 1;
        helper_Generate_Seq(seq_start, size);
    }
    return seq_start;
}

void Array_Shellsort(long *array, int size, long *n_comp) {
    /* generate sorting sequence, loop through array, swap the values
     * array is the array to be sorted, size is number of longs to be sorted, *n_comp stores number of comparisons
     */
    int temp; //holds temp number for swaps
    *n_comp = 0;
    int seq_start = 1;
    int gap = helper_Generate_Seq(seq_start, size); //this will overshoot the sequence by 1
    gap = gap - 1;
    gap = gap / 3; //manually reduces the sequence by 1
    for(int i = 0; i < (size - gap); i++)
    {
        temp = array[i];
        if(array[i + gap] < array[i]) //if you need to swap (bubble sort) THIS LINE IS A COMPARISON
        {
            array[i] = array[i + gap];
            array[i + gap] = temp;
        }
        *n_comp = *n_comp + 1; //increment n_comp because of if statement
    }
}

