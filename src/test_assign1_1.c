
#include <stdio.h>
#include "storage_mgr.h"
int main(){

    if(createPageFile("../data/database.txt") == RC_OK){
        printf("createPageFile test success\n");
    }
    else{
        printf("createPageFile test fail\n");
    }

    SM_FileHandle fHandle;
    if(openPageFile("../data/database.txt", &fHandle) == RC_OK){
        printf("openPageFile test success\n");
    }
    else{
        printf("openPageFile test fail\n");
    }

    if(closePageFile(&fHandle) == RC_OK){
        printf("closePageFile test success\n");
    }
    else{
        printf("closePageFile test fail\n");
    }

    return 0;
}