#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <memory>
#include <errno.h>
#include <sstream>
#include <gtk/gtk.h>

  #ifdef __linux__
  #include <unistd.h>
  #include <websms/websms.h> // <<< Websms.at SDK
  #define PATH_MAX        4096    /* # chars in a path name including nul */
  #include <linux/limits.h>
  #elif _WIN32
  #include <websms/websms.h> // <<< Websms.at SDK
  #include <unistd.h>
  #include <windows.h>
  //#pragma comment(SDK/win32/lib/libcurl.lib, "libcurl")
  //#pragma comment(SDK/win32/lib/jansson.lib, "jansson")
  //#pragma comment(SDK/win32/lib/libwebsms.lib, "libwebsms")
  #elif _WIN64
  #include <websms/websms.h> // <<< Websms.at SDK
  #include <unistd.h>
  #include <windows.h>
  //#pragma comment(SDK/win64/lib/libcurl.lib, "libcurl")
  //#pragma comment(SDK/win64/lib/jansson.lib, "jansson")
  //#pragma comment(SDK/win64/lib/libwebsms.lib, "libwebsms")
  #else 
  #error "OS not supported!"
  #endif

using namespace std;
using namespace websms; // <<< Websms.at SDK namespace

char *text = NULL;

std::string a = "";
std::string b = "";
std::string c = "";
std::string d = "";
std::string dx = "";
std::string dd = "";
std::string aa = "Send as Flash SMS";
std::string bb = "Send with Priority";

GtkWidget *CreateCheckBox (GtkWidget *box, char *szLabel)
{
    GtkWidget *check;

    /* --- Get the check button --- */
    check = gtk_check_button_new_with_label (szLabel);

    /* --- Pack the checkbox into the vertical box (box). --- */
    gtk_box_pack_start (GTK_BOX (box), check, FALSE, FALSE, 2);

    /* --- Show the widget --- */
    gtk_widget_show (check);

    return (check);
}

void flashsms(GtkWidget *, gpointer *)
{
  dx = (char *)"y";
}

void prioritysms(GtkWidget *, gpointer *)
{
  dd = (char *)"y";
}

void getnumberx(GtkButton *,gpointer dash11)
{
  a = gtk_entry_get_text(GTK_ENTRY(dash11));
}

void getmsgx(GtkButton *,gpointer dash22)
{
  b = gtk_entry_get_text(GTK_ENTRY(dash22));
}

void getuserx(GtkButton *,gpointer dash33)
{
  c = gtk_entry_get_text(GTK_ENTRY(dash33));
}

void getpassx(GtkButton *,gpointer dash44)
{
  d = gtk_entry_get_text(GTK_ENTRY(dash44));
}
void change_label(GtkButton *,gpointer label)
{
    gtk_label_set_text(GTK_LABEL(label), text);
}
 
void change_text(GtkButton *,gpointer numberx)
{	 
      g_free(text);
      text = g_strdup(gtk_entry_get_text(GTK_ENTRY(numberx)));
}  

void sendsms()
{
      const char *pch;
      int value = 0;
      pch = strtok ((char *)a.c_str(),",");
      // 4096 phonenumbers max per sms sending sequence
      #ifdef __linux__
      for(int f = 0;f < PATH_MAX;f++){
      #elif _WIN32 || _WIN64
      for(int f = 0;f < MAX_PATH;f++){
      #else 
      #error "OS not supported!"
      #endif
	
      while (pch != NULL)
      {
      SmsClient client(c.c_str(), d.c_str(), "https://api.websms.com/json"); // <<< Websms.at specific SDK Client
      #ifdef __linux__
      TextMessage message(strtol(pch,NULL,value), UTF8((char *)b.c_str())); // <<< Websms.at specific SDK Transmission Format
        #elif _WIN32 || _WIN64
      TextMessage message(strtol(pch,NULL,value), b.c_str()); // <<< Websms.at specific SDK Transmission Format
        #else 
	#error "OS not supported!"
	#endif
      printf("Outgoing SMS ... %lu\n",strtol(pch,NULL,value));
      
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
               false);  // Test message?
	GtkWidget *msgboxxx;
	char *wexx = NULL;
	wexx = g_strdup_printf("Message: %s \n\nTo Number: %lu \n\nStatus message: %s\nStatus code: %d\n",b.c_str(),strtol(pch,NULL,value),response.status_message(),response.status_code());
        msgboxxx = gtk_message_dialog_new_with_markup(NULL,GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, wexx );
	gtk_window_set_title(GTK_WINDOW(msgboxxx), "INFO");
	gtk_dialog_run(GTK_DIALOG(msgboxxx));
	gtk_widget_destroy( GTK_WIDGET(msgboxxx) );
	fprintf(stderr,"Message: %s \n\nTo Number: %lu \n\n%s \n",b.c_str(),strtol(pch,NULL,value),response.status_message());
    
      }catch (const Exception& e) {
        // Handle exceptions.	
	GtkWidget *msgbox;
	char *wex = NULL;
	wex = g_strdup_printf("Message: %s \n\nTo Number: %lu \n\n%s ",b.c_str(),strtol(pch,NULL,value),e.What());
        msgbox = gtk_message_dialog_new_with_markup(NULL,GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, wex );
	gtk_window_set_title(GTK_WINDOW(msgbox), "INFO");
	gtk_dialog_run(GTK_DIALOG(msgbox));
	gtk_widget_destroy( GTK_WIDGET(msgbox) );
	fprintf(stderr,"Message: %s \n\nTo Number: %lu \n\n%s \n",b.c_str(),strtol(pch,NULL,value),e.What());
      }
	pch = strtok (NULL, ",");
      } // while end
      } // for end
}

int main(int argc, char *argv[]) {
    //freopen( "/var/log/Smiril-websms-error.log", "a+", stderr );
    
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *label,*label1,*label2,*label3,*label4;
    GtkWidget *button,*buttonx;//,*button2;
    GtkWidget *user;
    GtkWidget *pass;
    GtkWidget *number;
    GtkWidget *msg;
    GtkWidget *check1;
    GtkWidget *check2;
    gtk_init(&argc, &argv);
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Smiril-websms 1.3");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    //gtk_window_set_icon(GTK_WINDOW(window), gtk_xpm);
    gtk_window_has_toplevel_focus(GTK_WINDOW(window));
    
    vbox = gtk_vbox_new(FALSE, 2);
    gtk_container_add(GTK_CONTAINER(window), vbox);
 
    label = gtk_label_new("Give me Data!");
    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
    
    label1 = gtk_label_new("Number");
    gtk_box_pack_start(GTK_BOX(vbox), label1, FALSE, FALSE, 0);
    number = gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(number),1024);
    gtk_box_pack_start(GTK_BOX(vbox), number, FALSE, FALSE, 0);
    
    label2 = gtk_label_new("Text Message");
    gtk_box_pack_start(GTK_BOX(vbox), label2, FALSE, FALSE, 0);
    msg = gtk_entry_new_with_max_length(155);
    gtk_box_pack_start(GTK_BOX(vbox), msg, FALSE, FALSE, 0);
    
    label3 = gtk_label_new("Username");
    gtk_box_pack_start(GTK_BOX(vbox), label3, FALSE, FALSE, 0);
    user = gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(user),50);
    gtk_box_pack_start(GTK_BOX(vbox), user, FALSE, FALSE, 0);
    
    label4 = gtk_label_new("Password");
    gtk_box_pack_start(GTK_BOX(vbox), label4, FALSE, FALSE, 0);
    pass = gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(pass),50);
    gtk_entry_set_visibility(GTK_ENTRY(pass),false);
    gtk_entry_set_invisible_char(GTK_ENTRY(pass),'*');
    gtk_box_pack_start(GTK_BOX(vbox), pass, FALSE, FALSE, 0);
    
    check1 = CreateCheckBox (vbox, (char *)aa.c_str());
    gtk_box_pack_start(GTK_BOX(vbox), check1, FALSE, FALSE, 0);
    gtk_toggle_button_set_state (GTK_TOGGLE_BUTTON (check1), TRUE);
    g_signal_connect(GTK_OBJECT(check1), "clicked", GTK_SIGNAL_FUNC(flashsms), NULL);
    check2 = CreateCheckBox (vbox, (char *)bb.c_str());
    gtk_box_pack_start(GTK_BOX(vbox), check2, FALSE, FALSE, 0);
    gtk_toggle_button_set_state (GTK_TOGGLE_BUTTON (check2), TRUE);
    g_signal_connect(GTK_OBJECT(check2), "clicked", GTK_SIGNAL_FUNC(prioritysms), NULL);
    
    button = gtk_button_new_with_label("Send");
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);
    //button2 = gtk_button_new_with_label("Reset");
    //gtk_box_pack_start(GTK_BOX(vbox), button2, FALSE, FALSE, 0);
    
    buttonx = gtk_link_button_new_with_label("https://websms.at/websms-testen","Visit the SMS Provider");
    gtk_box_pack_start(GTK_BOX(vbox), buttonx, FALSE, FALSE, 0);
     
    fprintf(stderr,"Status message: %s \n", strerror(errno));
    
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(button, "clicked", G_CALLBACK(change_text), number);
    g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
    g_signal_connect(button, "clicked", G_CALLBACK(getnumberx), number);
    g_signal_connect(button, "clicked", G_CALLBACK(getmsgx), msg);
    g_signal_connect(button, "clicked", G_CALLBACK(getuserx), user);
    g_signal_connect(button, "clicked", G_CALLBACK(getpassx), pass);
    g_signal_connect(button, "clicked", G_CALLBACK(flashsms), NULL);
    g_signal_connect(button, "clicked", G_CALLBACK(prioritysms), NULL);
    g_signal_connect(button, "clicked", G_CALLBACK(sendsms), NULL);
    
    gtk_widget_show_all(window);
 
    gtk_main();
    
    g_free(text);
    
    return 0;
} 
