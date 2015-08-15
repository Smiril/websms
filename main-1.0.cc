#include <stdio.h>
#include <gtk/gtk.h>
#include <websms/websms.h>
#include <iostream>
#include <cstring>
#include <memory>

using namespace std;
using namespace websms;

char *text = NULL;

const char *a,*b,*c,*d;

void sendsms(GtkButton *trigger3, gpointer labelx);
void change_text(GtkButton *trigger2, gpointer numberx);
void change_label(GtkButton *trigger1, gpointer label);
void getnumberx(GtkButton *dash1,gpointer dash11);
void getmsgx(GtkButton *dash2,gpointer dash22);
void getuserx(GtkButton *dash3,gpointer dash33);
void getpassx(GtkButton *dash4,gpointer dash44);

int main(int argc, char *argv[]) {
    //freopen( "error.log", "a+", stderr );
    
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *label,*label1,*label2,*label3,*label4;
    GtkWidget *button,*buttonx;//,*button2;
    GtkWidget *user;
    GtkWidget *pass;
    GtkWidget *number;
    GtkWidget *msg;
    gtk_init(&argc, &argv);
 
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "websms 1.0.1.5");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    //gtk_window_set_icon(GTK_WINDOW(window), gtk_xpm);
    gtk_window_has_toplevel_focus(GTK_WINDOW(window));
    
    vbox = gtk_vbox_new(FALSE, 5);
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
    
    
    button = gtk_button_new_with_label("Send");
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);
    //button2 = gtk_button_new_with_label("Reset");
    //gtk_box_pack_start(GTK_BOX(vbox), button2, FALSE, FALSE, 0);
    
    buttonx = gtk_link_button_new_with_label("https://websms.at/websms-testen","Visit the SMS Provider");
    gtk_box_pack_start(GTK_BOX(vbox), buttonx, FALSE, FALSE, 0);
     
    //fprintf(stderr,"Status message: %s \n", gtk_getlasterror());
    
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(button, "clicked", G_CALLBACK(change_text), number);
    g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
    g_signal_connect(button, "clicked", G_CALLBACK(getnumberx), number);
    g_signal_connect(button, "clicked", G_CALLBACK(getmsgx), msg);
    g_signal_connect(button, "clicked", G_CALLBACK(getuserx), user);
    g_signal_connect(button, "clicked", G_CALLBACK(getpassx), pass);
    g_signal_connect(button, "clicked", G_CALLBACK(sendsms), NULL);
    
    
    gtk_widget_show_all(window);
 
    gtk_main();
    
    g_free(text);
    
    return 0;
} 

void getnumberx(GtkButton *dash1,gpointer dash11)
{
  a = gtk_entry_get_text(GTK_ENTRY(dash11));
}

void getmsgx(GtkButton *dash2,gpointer dash22)
{
  b = gtk_entry_get_text(GTK_ENTRY(dash22));
}

void getuserx(GtkButton *dash3,gpointer dash33)
{
  c = gtk_entry_get_text(GTK_ENTRY(dash33));
}

void getpassx(GtkButton *dash4,gpointer dash44)
{
  d = gtk_entry_get_text(GTK_ENTRY(dash44));
}
void change_label(GtkButton *trigger1, gpointer label)
{
    gtk_label_set_text(GTK_LABEL(label), text);
}
 
void change_text(GtkButton *trigger2, gpointer numberx)
{	 
      g_free(text);
      text = g_strdup(gtk_entry_get_text(GTK_ENTRY(numberx)));
}  

void sendsms(GtkButton *trigger3, gpointer labelx)
{     
      SmsClient client(c, d, "https://api.websms.com");
      TextMessage message((int64_t)a, UTF8((char *)b));
      
      try {
        // Send the message.
        MessageResponse response = client.Send(message,
               1,      // Max. sms per message
               false);  // Test message?
	
      }catch (const Exception& e) {
        // Handle exceptions.	
	GtkWidget *msgbox;
	char *wex = NULL;
	wex = g_strdup_printf("Message: %s \n\nTo Number: %s \n\n%s ",(char *)b,(char *)a,e.What());
        msgbox = gtk_message_dialog_new_with_markup(NULL,GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, wex );
	gtk_window_set_title(GTK_WINDOW(msgbox), "INFO");
	gtk_dialog_run(GTK_DIALOG(msgbox));
	gtk_widget_destroy( GTK_WIDGET(msgbox) );
	
	fprintf(stderr,"Status message: %s \n", e.What());
      }
      
}
