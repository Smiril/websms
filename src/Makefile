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
LIBX := SDK/win32/lib/libwebsms.lib SDK/win32/lib/jansson.lib SDK/win32/lib/libcurl.lib GTKWIN32/lib/gtk-win32-2.0.lib
LIBC := SDK/win32/lib/libwebsms.lib SDK/win32/lib/jansson.lib SDK/win32/lib/libcurl.lib 
PREFIX := /bin
CXX := g++
CX1 := i686-w64-mingw32-g++
CX2 := i686-w64-mingw32-g++
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
	$(CX1) main.cc -I GTKWIN32/include/gtk-2.0 -I SDK/include -I GLIBWIN32/include/glib-2.0 $(CXXFLAGS1) -o websms-W32.exe -m32 -mwindows `pkg-config gtk+-2.0 --cflags --libs` $(LIBX)
websms-exe-x64: main.cc	
	$(CX2) main.cc -I GTKWIN32/include/gtk-2.0 -I SDK/include -I GLIBWIN32/include/glib-2.0 $(CXXFLAGS1) -o websms-x64.exe -m64 -mwindows `pkg-config gtk+-2.0 --cflags --libs` $(LIBX)
websms-console-exe-W32: main-c.cc	
	$(CX1) main-c.cc -I SDK/include $(CXXFLAGS2) -o websms-console-W32.exe -m32 -mwindows $(LIBC)
websms-console-exe-x64: main-c.cc	
	$(CX2) main-c.cc -I SDK/include $(CXXFLAGS2) -o websms-console-x64.exe -m64 -mwindows $(LIBC)
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
