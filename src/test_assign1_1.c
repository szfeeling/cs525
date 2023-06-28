
#include <stdio.h>
#include "storage_mgr.h"
int main(){

    if(createPageFile("../data/database.txt") == RC_OK){
        printf("success\n");
    }
    else{
        printf("fail\n");
    }

    SM_FileHandle fHandle;
    if(openPageFile("../data/database.txt", &fHandle) == RC_OK){
        printf("success\n");
    }
    else{
        printf("fail\n");
    }

    return 0;
}