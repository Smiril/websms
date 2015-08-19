NAME := Smiril-websms
MAJOR2 := 1
MINOR2 := 3
MAJOR1 := 1
MINOR1 := 2
CODENAME := Devloper-DDOS
LIBNAME := $(NAME)
VERSION1 := $(LIBNAME) $(MAJOR1).$(MINOR1) $(CODENAME)
VERSION2 := $(LIBNAME) $(MAJOR2).$(MINOR2) $(CODENAME)
LIBS := -lwebsms -lcurl -ljansson
PREFIX := /bin
CXX := g++
CXXFLAGS1 := -Wall -Wextra -pedantic \
        -Wno-variadic-macros \
        -DVERSION="\"$(VERSION1)\""
CXXFLAGS2 := -Wall -Wextra -pedantic \
        -Wno-variadic-macros \
        -DVERSION="\"$(VERSION2)\""

all: websms websms-console install clean
websms: main.cc	
	$(CXX) main.cc $(CXXFLAGS1) -o websms `pkg-config gtk+-2.0 --cflags --libs` $(LIBS)
websms-console: main-c.cc	
	$(CXX) main-c.cc $(CXXFLAGS2) -o websms-console $(LIBS)
debug-websms: CXXFLAGS1 += -g -DDEBUG
debug-websms: main.cc
	$(CXX) $(CXXFLAGS2) main.cc -o websms /bin/websms `pkg-config gtk+-2.0 --cflags --libs` $(LIBS)
debug-websms-console: CXXFLAGS2 += -g -DDEBUG
debug-websms-console: main-c.cc
	$(CXX) $(CXXFLAGS2) main-c.cc -o websms-console /bin/websms-console $(LIBS) 
version:
	@echo $(VERSION1)
	@echo $(VERSION2)

install: 
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
	
.PHONY: all websms websms-console debug-websms debug-websms-console install uninstall clean version
