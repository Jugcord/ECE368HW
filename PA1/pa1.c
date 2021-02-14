#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "shell_array.h"
#include "shell_list.h"
#include "list_of_list.h"

int main(int argc, char ** argv)
{
    // argv[2]: name of input file (binary)
    // argv[3]: name of output file (binary)
    if(argc != 4)
    {
        return EXIT_FAILURE;
    }
    //./pa1 -a input.b output.b should run the array functions
    //argv[1] should be "-a"
    //./pa1 -l input.b output.b should run the list functions
    //argv[1] should be "-l"
    if(argv[1] == "-a")
    {
        char* inputfile = argv[2];
        char* outputfile = argv[3];
        long* array;
        int size;
        int sizecheck;
        int n_comp = 0;
        array = Array_Load_From_File(inputfile, &size); //read input file into array, update size
        Array_Shellsort(array, size, &n_comp);
        sizecheck = Array_Save_To_File(outputfile, array, size);
        if (size != sizecheck)
        {
            System.out.println("different input/output sizes!\n");
        }

    }


    return EXIT_SUCCESS;
}