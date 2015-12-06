#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quit (GtkWidget *window, gpointer data)
{
 gtk_main_quit();
}

/*void in_record (GtkWidget *a_entry, GtkWidget *n_entry, GtkWidget *d_entry, GtkWidget *p_entry, gpointer a_data, gpointer n_data, gpointer d_data, gpointer p_data)
{
 const char *a_text = gtk_entry_get_text(GTK_ENTRY( (GtkWidget *) a_entry));
 const char *n_text = gtk_entry_get_text(GTK_ENTRY( (GtkWidget *) n_entry));
 const char *d_text = gtk_entry_get_text(GTK_ENTRY( (GtkWidget *) a_entry));
 const char *p_text = gtk_entry_get_text(GTK_ENTRY( (GtkWidget *) a_entry));

 if (a_data == NULL)
   gtk_label_set_text (GTK_LABEL( (GtkWidget *) data), "로긴이허용됩니다!\n");
 else
   gtk_label_set_text (GTK_LABEL( (GtkWidget *) data), "입력오류입니다!\n");
 
}*/

void record(GtkWidget *button, gpointer data)
{
 GtkWidget *r_window;
 GtkWidget *r_ok, *r_label, *r_fixed;
 /*  char  *temp = "forum, falinux.comn";
   int    fd;
 
   (text->fd)

   if ( 0 < ( fd = creat( "./test.txt", 0644)))
   { 
     write( fd, temp, strlen(temp));
     close( fd);
   }
   else
   {
     printf( "파일 생성에 실패했습니다.n");
   }*/

 r_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 gtk_window_set_title(GTK_WINDOW(r_window), "확인" );
 gtk_window_set_position(GTK_WINDOW(r_window), GTK_WIN_POS_CENTER);
 gtk_window_set_default_size(GTK_WINDOW(r_window), 120, 80);
 g_signal_connect(r_window, "destroy", G_CALLBACK(quit), NULL);

 r_fixed = gtk_fixed_new();
 gtk_container_add(GTK_CONTAINER(r_window),r_fixed);

 r_ok = gtk_button_new_with_label("확인");
 gtk_fixed_put(GTK_FIXED(r_fixed), r_ok, 70, 40);
 gtk_widget_set_size_request(r_ok, 20, 20);

 r_label = gtk_label_new("기록되었습니다.");
 gtk_fixed_put(GTK_FIXED(r_fixed), r_label, 10, 15);

 g_signal_connect(r_ok, "clicked", G_CALLBACK(quit), NULL);
 
 gtk_widget_show_all(r_window);
}

int main(int argc, char *argv[])
{
 GtkWidget *window;
 GtkWidget *aname_label, *name_label, *date_label, *phone_label;
 GtkWidget *aname_entry, *name_entry, *date_entry, *phone_entry; 
 GtkWidget *message_label;
 GtkWidget *button1, *button2, *fixed;

 gtk_init(&argc, &argv);

 window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 gtk_window_set_title(GTK_WINDOW(window), "입양 절차 입력창" );
 gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
 gtk_window_set_default_size(GTK_WINDOW(window), 400, 350);

 g_signal_connect(window, "destroy", G_CALLBACK(quit), NULL);

 fixed = gtk_fixed_new();
 gtk_container_add(GTK_CONTAINER(window),fixed);

 button1 = gtk_button_new_with_label("기록");
 gtk_fixed_put(GTK_FIXED(fixed), button1, 80,300);
 gtk_widget_set_size_request(button1, 30, 30);

 button2 = gtk_button_new_with_label("취소");
 gtk_fixed_put(GTK_FIXED(fixed), button2, 300,300);
 gtk_widget_set_size_request(button2, 30, 30);
 
 g_signal_connect(button2, "clicked", G_CALLBACK(quit), NULL);

 aname_label = gtk_label_new("입양 동물 이름 :");
 gtk_fixed_put(GTK_FIXED(fixed), aname_label, 50,70);

 name_label = gtk_label_new("입양자 이름 :");
 gtk_fixed_put(GTK_FIXED(fixed), name_label, 50,120);

 date_label = gtk_label_new("입양날짜 :");
 gtk_fixed_put(GTK_FIXED(fixed), date_label, 50,170);

 phone_label = gtk_label_new("입양자 전화번호 :");
 gtk_fixed_put(GTK_FIXED(fixed), phone_label, 50,220);
 
 aname_entry = gtk_entry_new();
 gtk_fixed_put(GTK_FIXED(fixed), aname_entry, 200,70);
 gtk_widget_set_size_request(aname_entry, 20, 10);

 name_entry = gtk_entry_new();
 gtk_fixed_put(GTK_FIXED(fixed), name_entry, 200,120);
 gtk_widget_set_size_request(name_entry, 20, 10);

 date_entry = gtk_entry_new();
 gtk_fixed_put(GTK_FIXED(fixed), date_entry, 200,170);
 gtk_widget_set_size_request(date_entry, 20, 10);

 phone_entry = gtk_entry_new();
 gtk_fixed_put(GTK_FIXED(fixed), phone_entry, 200,220);
 gtk_widget_set_size_request(phone_entry, 20, 10);

 message_label= gtk_label_new("입력하세요.");
 gtk_fixed_put(GTK_FIXED(fixed), message_label, 170,20);

 g_signal_connect(button1, "clicked", G_CALLBACK(record), NULL);

 gtk_widget_show_all(window);
 gtk_main ();
 
 return 0;
}
