


#define RC_OK   0

#define RC_FILE_NOT_FOUND 1

#define RC_READ_NON_EXISTING_PAGE 2

#define PAGE_SIZE 1024

typedef int  RC;


void RC_message(int errorCode);