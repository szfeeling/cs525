
#include <stdio.h>
#include "dberror.h"

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