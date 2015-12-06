#include <gtk/gtk.h>

void quit (GtkWidget *window, gpointer data)
{
 gtk_main_quit();
}

typedef struct
{
 GtkWidget *aname_entry, *name_entry, *date_entry, *phone_entry;
 GtkWidget *textview;
} Widgets;

static void insert_text (GtkButton *button, Widgets *w)
{
     GtkTextBuffer *buffer;
     GtkTextMark *mark;
     GtkTextIter iter;
     const gchar *a_text, *n_text, *d_text, *p_text;
     GtkWidget *r_window;
     GtkWidget *r_ok, *r_label, *r_fixed;

     buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (w->textview));

     a_text = gtk_entry_get_text (GTK_ENTRY (w->aname_entry));
     n_text = gtk_entry_get_text (GTK_ENTRY (w->name_entry));
     d_text = gtk_entry_get_text (GTK_ENTRY (w->date_entry));
     p_text = gtk_entry_get_text (GTK_ENTRY (w->phone_entry));

     mark = gtk_text_buffer_get_insert (buffer);
     gtk_text_buffer_get_iter_at_mark (buffer, &iter, mark);

     if (gtk_text_buffer_get_char_count(buffer)){
       gtk_text_buffer_insert (buffer, &iter, "\n", 1);
     }

     gtk_text_buffer_insert (buffer, &iter, a_text, -1);
     gtk_text_buffer_insert (buffer, &iter, n_text, -1);
     gtk_text_buffer_insert (buffer, &iter, d_text, -1);
     gtk_text_buffer_insert (buffer, &iter, p_text, -1);

     mark= gtk_text_buffer_get_insert (buffer);
     gtk_text_view_scroll_mark_onscreen (GTK_TEXT_VIEW (w->textview) , mark);

     r_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
     gtk_window_set_title(GTK_WINDOW(r_window), "확인" );
     gtk_window_set_position(GTK_WINDOW(r_window), GTK_WIN_POS_CENTER);
     gtk_window_set_default_size(GTK_WINDOW(r_window), 120, 80);
    // g_signal_connect(r_window, "destroy", G_CALLBACK(quit), NULL);

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

static void ch(GtkButton *button, gpointer data){
     GtkWidget *window, *scrolled_win, *vbox, *hbox;
     Widgets *w = g_slice_new (Widgets);

     window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
     gtk_window_set_title (GTK_WINDOW (window), "입양 예약 기록창");
     gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
     gtk_widget_set_size_request (window, 300, 300);

     w->textview = gtk_text_view_new ();
  
     scrolled_win = gtk_scrolled_window_new (NULL, NULL);
     gtk_container_add (GTK_CONTAINER (scrolled_win), w->textview);

     hbox= gtk_box_new ( GTK_ORIENTATION_HORIZONTAL, 5 );

     vbox= gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
     gtk_box_pack_start(GTK_BOX(vbox), scrolled_win, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, TRUE, 0);
     gtk_container_add(GTK_CONTAINER(window), vbox);
     gtk_widget_show_all (window); 
}

int main(int argc, char *argv[])
{
     GtkWidget *window;
     Widgets *w = g_slice_new(Widgets);
     GtkWidget *aname_label, *name_label, *date_label, *phone_label;
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

     aname_label = gtk_label_new("입양 동물 이름 :");
     gtk_fixed_put(GTK_FIXED(fixed), aname_label, 50,70);

     name_label = gtk_label_new("입양자 이름 :");
     gtk_fixed_put(GTK_FIXED(fixed), name_label, 50,120);

     date_label = gtk_label_new("입양날짜 :");
     gtk_fixed_put(GTK_FIXED(fixed), date_label, 50,170);

     phone_label = gtk_label_new("입양자 전화번호 :");
     gtk_fixed_put(GTK_FIXED(fixed), phone_label, 50,220);

     w->aname_entry = gtk_entry_new();
     gtk_fixed_put(GTK_FIXED(fixed), w->aname_entry, 200,70);
     gtk_widget_set_size_request(w->aname_entry, 20, 10);

     w->name_entry = gtk_entry_new();
     gtk_fixed_put(GTK_FIXED(fixed), w->name_entry, 200,120);
     gtk_widget_set_size_request(w->name_entry, 20, 10);

     w->date_entry = gtk_entry_new();
     gtk_fixed_put(GTK_FIXED(fixed), w->date_entry, 200,170);
     gtk_widget_set_size_request(w->date_entry, 20, 10);

     w->phone_entry = gtk_entry_new();
     gtk_fixed_put(GTK_FIXED(fixed), w->phone_entry, 200,220);
     gtk_widget_set_size_request(w->phone_entry, 20, 10);

     message_label= gtk_label_new("입력하세요.");
     gtk_fixed_put(GTK_FIXED(fixed), message_label, 170,20);

     g_signal_connect(button1, "clicked", G_CALLBACK(insert_text), (gpointer) w);
     g_signal_connect(button2, "clicked", G_CALLBACK(ch), (gpointer) w);

     gtk_widget_show_all(window);
     gtk_main ();

     return 0;
}
