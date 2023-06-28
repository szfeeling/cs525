CC = gcc
CFLAGS = -g -Wall 
INCS = -I./
LINK =  $(CC) -fPIC 


SOURCE_CODES = ./storage_mgr.c ./dberror.c ./test_assign1_1.c 
		   
TARGET = ../bin/test_assign1_1
	
all : $(TARGET)

$(TARGET):
	  $(CC)  $(CFLAGS) $(INCS) $(THIRD_INCS) $(SOURCE_CODES) $(LIB) $(LDLIBRARY)  $(THIRD_LIB) -o $(TARGET)
clean:
    ifeq ($(TARGET),$(wildcard $(TARGET)))		
		rm $(TARGET)	
    endif
rebuild:
    ifeq ($(TARGET),$(wildcard $(TARGET)))		
		rm $(TARGET)	
    endif
	  $(CC)  $(CFLAGS) $(INCS) $(THIRD_INCS) $(SOURCE_CODES) $(LIB) $(LDLIBRARY)  $(THIRD_LIB) -o $(TARGET)