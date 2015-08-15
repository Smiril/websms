#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <memory>
#include <errno.h>
#include <sstream>
#include <websms/websms.h> // <<< Websms.at SDK

using namespace std;
using namespace websms; // <<< Websms.at SDK namespace

string a = "";
string b = "";
string c = "";
string d = "";


void sendsms(std::string a1,std::string b1,std::string c1,std::string d1);

int getch() {
    int ch;
    struct termios t_old, t_new;

    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    return ch;
}

string getpass(const char *prompt, bool show_asterisk=true)
{
  const char BACKSPACE=127;
  const char RETURN=10;

  string password;
  unsigned char ch=0;

  cout <<prompt;

  while((ch=getch())!=RETURN)
    {
       if(ch==BACKSPACE)
         {
            if(password.length()!=0)
              {
                 if(show_asterisk)
                 cout <<"\b \b";
                 password.resize(password.length()-1);
              }
         }
       else
         {
             password+=ch;
             if(show_asterisk)
                 cout <<'*';
         }
    }
  cout <<endl;
  return password;
}


int main(int argc, char *argv[]) {
	//freopen( "error.log", "a+", stderr );
	printf("Using %s ...\n",Version());
	int x = 0;  // Don't forget to declare variables
	printf("\e[033;3432mLoading...");
	while ( x < 11 ) { // While x is less than 11 
	cout<< x;
	x++;             // Update x so the condition can be met eventually
	}
	sleep(1);
	printf(" \e[033;32mFinished\e[033;39m\n");
	// Uncomment version you want!
  // v.1.0
  /* 
	printf("Number\n");
	cin >> a;
	printf("Message\n");
	cin >> b;
	printf("Username\n");
	cin >> c;
	printf("Password\n");
	cin >> d;
  */
  // v.1.1
  /* 
	if(argc < 4) {
        printf("Usage: %s number message_with_no_spaces username password\n",argv[0]);
        exit(0);
	}
	a = argv[1];
	b = argv[2];
	c = argv[3];
	d = argv[4];
  */
  // v.1.2
  
	printf("Number: ");
	getline(cin,a);
	printf("Message: ");
	getline(cin,b);
	c=getpass("Username: ",true); // Show asterisks
	d=getpass("Password: ",true); // Show asterisks
 
	sendsms(a,b,c,d);
	
	return 0;
}

void sendsms(std::string a1,std::string b1,std::string c1,std::string d1)
{     
      SmsClient client(c1.c_str(), d1.c_str(), "https://api.websms.com"); // <<< Websms.at specific SDK Client
      TextMessage message((int64_t)a1.c_str(), UTF8((char *)b1.c_str())); // <<< Websms.at specific SDK Transmission Format
      
      try {
        // Send the message.
        MessageResponse response = client.Send(message, // <<< Websms.at specific SDK Transmission
               1,      	// Max. sms per message just Message count
               false);  // Test message? false means NO a true Message not a Test!
      }catch (const Exception& e) {
        // Handle exceptions.
	switch((int64_t)e.What()) 
	      {
	      case (2000): 
			{
			fprintf(stderr,"\n\nMessage: %s \nTo Number: %s\n\e[033;32m%s\n\e[033;39m \n",(char *)b1.c_str(),(char *)a1.c_str(),e.What());
			fprintf(stderr,"Status message: \e[033;32m %s\n\e[033;39m  \n", e.What());
			break;
			}
	      case (2001): 
			{
			fprintf(stderr,"\n\nMessage: %s \nTo Number: %s\n\e[033;3432m%s\n\e[033;39m \n",(char *)b1.c_str(),(char *)a1.c_str(),e.What());
			fprintf(stderr,"Status message: \e[033;3432m %s\n\e[033;39m  \n", e.What());
			break;
			}
			
	default:
		{
		fprintf(stderr,"\n\nMessage: %s \nTo Number: %s\n\e[033;31m%s\n\e[033;39m \n",(char *)b1.c_str(),(char *)a1.c_str(),e.What());
		fprintf(stderr,"Status message: \e[033;31m %s\n\e[033;39m  \n", e.What());
		}
	      }
	}
      
}
