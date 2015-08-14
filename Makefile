all: websms
websms: main.cc	
	g++ main.cc -Wall -o websms `pkg-config gtk+-2.0 --cflags --libs` -lwebsms -lcurl -ljansson
install: websms
	mkdir -p /bin
	cp websms /bin
	chmod +x /bin/websms
	chmod 755 /bin/websms
uninstall: websms
	rm -rf /bin/websms
