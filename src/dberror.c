#include "dberror.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *RC_message;

/* print a message to standard out describing the error */
void 
printError (RC error)
{
	if (RC_message != NULL)
		printf("EC (%i), \"%s\"\n", error, RC_message);
	else
		printf("EC (%i)\n", error);
}

char *
errorMessage (RC error)
{
	char *message;

	if (RC_message != NULL)
	{
		message = (char *) malloc(strlen(RC_message) + 30);
		sprintf(message, "EC (%i), \"%s\"\n", error, RC_message);
	}
	else
	{
		message = (char *) malloc(30);
		sprintf(message, "EC (%i)\n", error);
	}

	return message;
}

void RC_message(int errorCode){

    switch(errorCode){
        case RC_OK:
            printf("success\n");
            break;
        case RC_READ_NON_EXISTING_PAGE:
            printf("the page read does not exis");
            break;
    }

}