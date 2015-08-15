all: websms websms-console
websms: main.cc	
	g++ main.cc -Wall -o websms `pkg-config gtk+-2.0 --cflags --libs` -lwebsms -lcurl -ljansson
websms-console: main-c.cc	
	g++ main-c.cc -Wall -o websms-console -lwebsms -lcurl -ljansson
install: websms websms-console
	mkdir -p /bin
	cp websms /bin
	chmod +x /bin/websms
	cp websms-console /bin
	chmod +x /bin/websms-console
uninstall: websms websms-console
	rm -rf /bin/websms
	rm -rf /bin/websms-console
clean: websms websms-console
        rm -rf websms
        rm -rf websms-console
