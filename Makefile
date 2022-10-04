CXX       := /usr/bin/g++
CXX_FLAGS := -std=c++17 -fdiagnostics-color=always -fno-elide-constructors 

AR_CMD    := /usr/bin/ar
AR_ARGS   := rvs
RM_CMD    := /bin/rm
RM_ARGS   := -rf

all: main

statusbar: statusbar.cpp
	${CXX} ${CXX_FLAGS} -c -I. $^
	${AR_CMD} ${AR_ARGS} lib$@.a $@.o
	${RM_CMD} ${RM_ARGS} $@.o

addlibmac:
	cp libstatusbar.a /usr/local/lib
	cp statusbar.hpp /usr/local/include

addlibwsl:
	cp libstatusbar.a /usr/lib
	cp statusbar.hpp /usr/include
	
main: statusbar main.cpp
	${CXX} ${CXX_FLAGS} $@.cpp -o $@.exe -L. -lstatusbar
