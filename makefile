#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = %cd%

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = -I./include
CFLAGS = -Wno-deprecated-declarations
RESINC = 
LIBDIR =
LIB = 
LDFLAGS = -framework GLUT -framework OpenGL -framework Cocoa 


INC_RELEASE = $(INC) -Iinclude
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS)
OBJDIR_RELEASE = obj
OUT_RELEASE = project1

OBJ_RELEASE = $(OBJDIR_RELEASE)/main.o $(OBJDIR_RELEASE)/Model_OBJ.o

all: release

clean: 
	rm $(OBJDIR_RELEASE)/*.o
	rm $(OUT_RELEASE)

release: $(OBJ_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE)$(LIB_RELEASE)

$(OBJDIR_RELEASE)/main.o: main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c main.cpp -o $(OBJDIR_RELEASE)/main.o

$(OBJDIR_RELEASE)/Model_OBJ.o: src/Model_OBJ.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Model_OBJ.cpp -o $(OBJDIR_RELEASE)/Model_OBJ.o



