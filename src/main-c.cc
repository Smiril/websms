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
string e = "n";
string f = "n";
string h = "n";
string hh = "y";

void sendsms(std::string a1,std::string b1,std::string c1,std::string d1,std::string dx,std::string dd);

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


int main(/*int argc, char *argv[]*/) {
	//freopen( "error.log", "a+", stderr );
	printf("Using %s ...\n",Version());
	int x = 0;  // Don't forget to declare variables
	printf("\x1B[33mLoading...");
	while ( x < 11 ) { // While x is less than 11 
	printf("%d",x);
	x++;             // Update x so the condition can be met eventually
	}
	//sleep(1);
	printf(" \x1B[32mFinished\x1B[39m\n");
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
	Again:
	printf("Number: \x1B[32m");
	getline(cin,a);
	printf("\x1B[39mMessage: \x1B[33m");
	getline(cin,b);
	c=getpass("\x1B[39mUsername: \x1B[31m",true); // Show asterisks
	d=getpass("\x1B[39mPassword: \x1B[31m",true); // Show asterisks
	printf("\x1B[32mSend as Flash SMS? (y/n) Default n : \x1B[39m");
	getline(cin,e);
	printf("\x1B[32mSend as Priority SMS? (y/n) Default n : \x1B[39m");
	getline(cin,f);
	
	sendsms(a,b,c,d,e,f);
	
	printf("\x1B[32mSend again SMS? (y/n) Default n : \x1B[39m");
	getline(cin,h);
	
	if(h.c_str() == hh.c_str())
	{
	  goto Again;
	}
	else{
	exit(0);
	}
	return 0;
}

void sendsms(std::string a1,std::string b1,std::string c1,std::string d1,std::string dx,std::string dd)
{     
      SmsClient client(c1.c_str(), d1.c_str(), "https://api.websms.com/json"); // <<< Websms.at specific SDK Client
      TextMessage message((int64_t)a1.c_str(), UTF8((char *)b1.c_str())); // <<< Websms.at specific SDK Transmission Format
      // TextMessage recipient_address_list();
      // God's will welcome but User vote and got some Sympathy with the Devil ...
      std::string god = "y";
      std::string devil = "y";
      if(dx.c_str() == god && dd.c_str() != devil)
      {
      TextMessage send_as_flash_sms();
      printf("\x1B[32mSending as \x1B[33mFlash\x1B[32m SMS with \x1B[33mLow Priority!\x1B[39m\n");
      }
      else if(dx.c_str() == god && dd.c_str() == devil){
      TextMessage send_as_flash_sms();
      printf("\x1B[32mSending as \x1B[33mFlash\x1B[32m SMS with \x1B[33mHigh Priority!\x1B[39m\n");
      TextMessage set_priority();
      }
      else if(dx.c_str() != god && dd.c_str() == devil){
      printf("\x1B[32mSending as \x1B[33mRegular\x1B[32m SMS with \x1B[33mHigh Priority!\x1B[39m\n");
      TextMessage set_priority();
      }
      else{
      printf("\x1B[32mSending as \x1B[33mRegular\x1B[32m SMS with \x1B[33mLow Priority!\x1B[39m\n");
      }
      
      try {
        // Send the message.
        MessageResponse response = client.Send(message, // <<< Websms.at specific SDK Transmission
               1,      	// Max. sms per message just Message count
               false);  // Test message? false means NO a true Message not a Test!
	    // Print the response.
	printf("\x1B[39mStatus message: \x1B[32m%s\x1B[39m\nStatus code: \x1B[32m%d\x1B[39m\n",
           response.status_message(),
           response.status_code());
    
      }catch (const Exception& e) {
        // Handle exceptions.
	fprintf(stderr,"\a\x1B[39m\n			-=[ ERROR ]=-\n		Message: %s \n		To Number: %s\n		 -=[ \x1B[31m%s\x1B[39m]=- \n",(char *)b1.c_str(),(char *)a1.c_str(),e.What());
	//fprintf(stderr,"Status message: \x1B[31m %s\n\x1B[39m  \n", e.What());
	}
      
}