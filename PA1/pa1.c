#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "shell_array.h"
#include "shell_list.h"
#include "list_of_list.h"

int main(int argc, char * argv[])
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
    if(strcmp(argv[1],"-a") == 0)
    {
        char* inputfile = argv[2];
        char* outputfile = argv[3];
        long* array;
        int size;
        int sizecheck;
        long n_comp;
        array = Array_Load_From_File(inputfile, &size); //read input file into array, update size
        Array_Shellsort(array, size, &n_comp);
        sizecheck = Array_Save_To_File(outputfile, array, size);
        if (size != sizecheck)
        {
            printf("different input/output sizes!\n");
			printf("Total number of comparisons: %ld\n", n_comp);
        }
		free(array);


    }


    return EXIT_SUCCESS;
}
