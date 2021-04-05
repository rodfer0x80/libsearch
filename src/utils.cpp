#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
/*
 * Greeting shell during startup as in clear screen and print welcome text
 *
 * @param :: void
*/
void greeting()
{
	clear();
    printf("\n\n\n\n\t******************"
           "************************");
    printf("\n\n\n\t         ***** LIBSEARCH *****       ");
    printf("\n\n\n\t        ***** Open Source  *****");
    printf("\n\n\n\n\t*******************"
           "***********************\n");
	//sleep(3);
	clear();
}

