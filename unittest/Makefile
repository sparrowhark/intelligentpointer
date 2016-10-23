#subdir and objects in current dir   
SUBDIRS = 
SRCS = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, %.o, $(SRCS))                                       
OBJECTSPATH = $(patsubst %.cpp, ${OBJPATH}%.o, $(SRCS)) 

all: subdirs ${OBJECTS}


include ${MAKEINCLUDE}
