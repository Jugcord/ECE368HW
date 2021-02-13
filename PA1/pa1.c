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


    return EXIT_SUCCESS;
}