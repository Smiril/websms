NAME := Smiril-websms
MAJOR2 := 1
MINOR2 := 3
MAJOR1 := 1
MINOR1 := 3
CODENAME := Rasputin
LIBNAME := $(NAME)
VERSION1 := $(LIBNAME) $(MAJOR1).$(MINOR1) $(CODENAME)
VERSION2 := $(LIBNAME) $(MAJOR2).$(MINOR2) $(CODENAME)
LIBS := -lwebsms -lcurl -ljansson
PREFIX := /bin
CXX := g++
CXXW32 := cross-g++
CXXW64 := cross-g++
CXXFLAGS1 := -Wall -Wextra -pedantic \
        -Wno-variadic-macros \
        -DVERSION="\"$(VERSION1)\""
CXXFLAGS2 := -Wall -Wextra -pedantic \
        -Wno-variadic-macros \
        -DVERSION="\"$(VERSION2)\""

all: websms websms-console
websms: main.cc	
	$(CXX) main.cc $(CXXFLAGS1) -o websms `pkg-config gtk+-2.0 --cflags --libs` $(LIBS)
websms-console: main-c.cc	
	$(CXX) main-c.cc $(CXXFLAGS2) -o websms-console $(LIBS)
websms-exe-W32: main.cc	
	$(CXXw32) main.cc $(CXXFLAGS1) -o websms-W32.exe `pkg-config gtk+-3.0 --cflags --libs` $(LIBS)
websms-exe-x64: main.cc	
	$(CXXw64) main.cc $(CXXFLAGS1) -o websms-x64.exe `pkg-config gtk+-3.0 --cflags --libs` $(LIBS)
websms-console-exe-W32: main-c.cc	
	$(CXXW32) main-c.cc $(CXXFLAGS2) -o websms-console-W32.exe $(LIBS)
websms-console-exe-x64: main-c.cc	
	$(CXXW64) main-c.cc $(CXXFLAGS2) -o websms-console-x64.exe $(LIBS)
debug-websms: CXXFLAGS1 += -g -DDEBUG
debug-websms: main.cc
	$(CXX) $(CXXFLAGS2) main.cc -o websms /bin/websms `pkg-config gtk+-2.0 --cflags --libs` $(LIBS)
debug-websms-console: CXXFLAGS2 += -g -DDEBUG
debug-websms-console: main-c.cc
	$(CXX) $(CXXFLAGS2) main-c.cc -o websms-console /bin/websms-console $(LIBS) 
version:
	@echo $(VERSION1)
	@echo $(VERSION2)

install: websms websms-console
	mkdir -p $(PREFIX)
	cp websms $(PREFIX)
	chmod +x $(PREFIX)/websms
	cp websms-console $(PREFIX)
	chmod +x $(PREFIX)/websms-console
uninstall: 
	rm -rf $(PREFIX)/websms
	rm -rf $(PREFIX)/websms-console
clean: 
	rm -rf websms
	rm -rf websms-console
	rm -rf websms-W32.exe
	rm -rf websms-x64.exe
	rm -rf websms-console-W32.exe
	rm -rf websms-console-x64.exe
	
.PHONY: all websms websms-console websms-exe-W32 websms-exe-x64 websms-console-exe-W32 websms-console-exe-x64 debug-websms debug-websms-console install uninstall clean version
