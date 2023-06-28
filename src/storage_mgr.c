
#include <stdio.h>
#include <stdlib.h>
#include "storage_mgr.h"



RC createPageFile(char * fileName){
    FILE *fp;
    fp = fopen(fileName, "w");
    if(fp == NULL){
        return RC_FILE_NOT_FOUND;
    }
    else{
        SM_PageHandle memPage = (SM_PageHandle)calloc(PAGE_SIZE, sizeof(char));
        fwrite(memPage, sizeof(char), PAGE_SIZE, fp);
        fclose(fp);
        free(memPage);
        return RC_OK;
    }
}

RC openPageFile(char * fileName, SM_FileHandle * fHandle){
    FILE *fp;
    fp = fopen(fileName, "r+");
    if(fp == NULL){
        return RC_FILE_NOT_FOUND;
    }
    else{
        fseek(fp, 0L, SEEK_END);
        int totalNumPages = ftell(fp)/PAGE_SIZE;
        fHandle->fileName = fileName;
        fHandle->totalNumPages = totalNumPages;
        fHandle->curPagePos = 0;
        fHandle->mgmtInfo = fp;
        return RC_OK;
    }
}

RC closePageFile(SM_FileHandle * fHandle ){
    if(fclose(fHandle->mgmtInfo) == 0){
        return RC_OK;
    }
    else{
        return RC_FILE_NOT_FOUND;
    }
}

RC readBlock(int pageNum, SM_FileHandle * fHandle, SM_PageHandle memPage){
    if(pageNum > fHandle->totalNumPages || pageNum < 0){
        return RC_READ_NON_EXISTING_PAGE;
    }
    else{
        fseek(fHandle->mgmtInfo, pageNum*PAGE_SIZE, SEEK_SET);
        fread(memPage, sizeof(char), PAGE_SIZE, fHandle->mgmtInfo);
        fHandle->curPagePos = pageNum;
        return RC_OK;
    }
}