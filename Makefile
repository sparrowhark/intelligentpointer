TARGET = intelligentpointer
SUBDIRS = src

SRCS = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp,%.o,$(SRCS))
OBJECTSPATH = $(patsubst %.cpp, $(OBJPATH)%.o, $(SRCS))

LINTFILE = $(shell find -regex '.*\.\(h\|cpp\)')

PATH  := "$(PATH):$(PWD)/bin:/my/other/path"
ALL: subdirs $(OBJECTS)
	${CC} -o ${TARGET} $$(find ${OBJPATH} -name '*.o') ${CFLAGS} ${LDFLAGS} $(LIBS) ${INCLUDES}

.PHONY: ALL cpplint

cpplint:
	@python /home/stone/github/styleguide/cpplint/cpplint.py ${LINTFILE}



export PROJECTPATH=$(PWD)
export INCLUDES=-I${PROJECTPATH}/inc/
export OBJPATH=${PROJECTPATH}/obj/
export MAKEINCLUDE=${PROJECTPATH}/makemacro
#load libcppunit-1.13.so.0
#or you can
#edit /etc/ld.so.conf and add the line
#/usr/local/lib
#then, run the 'ldconfig' program (you need to do these things as root).
export LD_LIBRARY_PATH=/usr/local/lib
include ${MAKEINCLUDE} 

