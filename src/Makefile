NAME := Smiril-websms
MAJOR2 := 1
MINOR2 := 4
MAJOR1 := 1
MINOR1 := 4
CODENAME1 := TED - The Enemy Dail
CODENAME2 := TED - The Enemy Dail
LIBNAME := $(NAME)
VERSION1 := $(LIBNAME) $(MAJOR1).$(MINOR1) $(CODENAME1)
VERSION2 := $(LIBNAME) $(MAJOR2).$(MINOR2) $(CODENAME2)
LIBS := -lwebsms -lcurl -ljansson
LIBX := -llibwebsms -ljansson -llibcurl 
LIBC := -llibwebsms -ljansson -llibcurl 
LIBD := -llibwebsms -ljansson -llibcurl 
PREFIX := /bin
CXX := g++
CX1 := i686-w64-mingw32-g++
CX2 := i686-darwin-mingw32-g++
CXXFLAGS1 := -Wall -Wextra -pedantic \
        -Wno-variadic-macros \
        -DVERSION="\"$(VERSION1)\""
CXXFLAGS2 := -Wall -Wextra -pedantic \
        -Wno-variadic-macros \
        -DVERSION="\"$(VERSION2)\""

.PHONY: all websms websms-console websms-exe-W32 websms-exe-x64 websms-console-exe-W32 websms-console-exe-x64 debug-websms debug-websms-exe-W32 debug-websms-exe-x64 debug-websms-console debug-websms-console-exe-W32 debug-websms-console-exe-x64 install uninstall clean version

all: websms websms-console
websms: main.cc	
	$(CXX) main.cc -I SDK/include $(CXXFLAGS1) -o websms `pkg-config gtk+-2.0 --cflags --libs` $(LIBS)
websms-exe-W32: main.cc	
	$(CX1) main.cc -I SDK/win32/lib -I SDK/include  $(CXXFLAGS1) -o websms-W32.exe -m32 -mwindows `pkg-config gtk+-2.0 --cflags --libs` $(LIBX)
websms-exe-x64: main.cc	
	$(CX1) main.cc -I SDK/win64/lib -I SDK/include  $(CXXFLAGS1) -o websms-x64.exe -m64 -mwindows $(LIBC)
websms-console: main-c.cc	
	$(CXX) main-c.cc -I SDK/include $(CXXFLAGS2) -o websms-console $(LIBS)
websms-console-exe-W32: main-c.cc	
	$(CX1) main-c.cc -I /usr/lib64 -I SDK/win32/lib -I SDK/include $(CXXFLAGS2) -o websms-console-W32.exe -m32 -mwindows $(LIBD)
websms-console-exe-x64: main-c.cc	
	$(CX1) main-c.cc -I /usr/lib64 -I SDK/win64/lib -I SDK/include $(CXXFLAGS2) -o websms-console-x64.exe -m64 -mwindows $(LIBD)
debug-websms: CXXFLAGS1 += -g -DDEBUG
debug-websms: main.cc
	$(CXX) $(CXXFLAGS2) main.cc -o debug-websms websms `pkg-config gtk+-2.0 --cflags --libs` $(LIBS)
debug-websms-exe-W32 : CXXFLAGS1 += -g -DDEBUG
debug-websms-exe-W32: main.cc	
	$(CX1) main.cc -I SDK/win32/lib -I GTKWIN32/include/gtk-2.0 -I SDK/include -I GLIBWIN32/include/glib-2.0 -I GTKWIN32/lib -I GLIBWIN32/lib $(CXXFLAGS1) -o debug-websms-W32.exe websms-W32.exe -m32 -mwindows `pkg-config gtk+-2.0 --cflags --libs` $(LIBX)
debug-websms-exe-x64 : CXXFLAGS1 += -g -DDEBUG
debug-websms-exe-x64: main.cc	
	$(CX1) main.cc -I SDK/win64/lib -I GTKWIN64/include/gtk-3.0 -I SDK/include -I GLIBWIN64/include/glib-2.0 -I GTKWIN64/lib -I GLIBWIN64/lib $(CXXFLAGS1) -o debug-websms-x64.exe websms-x64.exe -m64 -mwindows $(LIBC)
debug-websms-console: CXXFLAGS2 += -g -DDEBUG
debug-websms-console: main-c.cc
	$(CXX) $(CXXFLAGS2) main-c.cc -o debug-websms-console websms-console $(LIBS) 
debug-websms-console-exe-W32: CXXFLAGS2 += -g -DDEBUG
debug-websms-console-exe-W32: main-c.cc	
	$(CX1) main-c.cc -I SDK/win32/lib -I SDK/include $(CXXFLAGS2) -o debug-websms-console-W32.exe websms-console-W32.exe -m32 -mwindows $(LIBD)
debug-websms-console-exe-x64: CXXFLAGS2 += -g -DDEBUG
debug-websms-console-exe-x64: main-c.cc	
	$(CX1) main-c.cc -I SDK/win64/lib -I SDK/include $(CXXFLAGS2) -o debug-websms-console-x64.exe websms-console-x64.exe -m64 -mwindows $(LIBD)
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
	
