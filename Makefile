LIBS := -lwebsms -lcurl -ljansson
PREFIX := /bin
CXX := g++
CXXFLAGS := -Wall -Wextra -pedantic \
        -Wno-variadic-macros \
        -DVERSION="\"$(VERSION)\""

all: websms websms-console install clean
websms: main.cc	
	$(CXX) main.cc $(CXXFLAGS) -o websms `pkg-config gtk+-2.0 --cflags --libs` $(LIBS)
websms-console: main-c.cc	
	$(CXX) main-c.cc $(CXXFLAGS) -o websms-console $(LIBS)
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
	
.PHONY: all websms websms-console install uninstall clean
