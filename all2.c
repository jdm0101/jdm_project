#include <gtk/gtk.h>
GtkWidget *frame;
void quit( GtkWidget *window, gpointer data)
{
  gtk_main_quit();
}

typedef struct  //입양 절차 입력 entry
{
 GtkWidget *aname_entry, *name_entry, *date_entry, *phone_entry;
 GtkWidget *textview;
} Widgets;


void add_widget_with_label (GtkContainer *box, GtkWidget * widget){
GtkWidget *hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 10);
gtk_container_add(GTK_CONTAINER (hbox), widget);
gtk_container_add(box, hbox);
}
void s_chat(GtkWidget *widget, gpointer data)
{
 char* address;

unsigned short port;
/*
if(argc<2)

address=strdup(defaultAddr);

else

address=strdup(argv[1]);

if(argc<3)

port=defaultPort;

else

port=(unsigned short)atoi(argv[2]);
*/
//csock=connect_chat(address, port);

GtkWidget *window;
GtkWidget *label_chat;
GtkWidget *butt_chat;
GtkWidget *entry_chat;
GtkWidget *vbox;
GtkWidget *hbox_1,*hbox_2;
//gtk_init(&argc, &argv);
window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(window), "채팅" );
gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
gtk_window_set_default_size(GTK_WINDOW(window), 200, 150);
g_signal_connect (G_OBJECT (window), "destroy",G_CALLBACK (quit), NULL);

label_chat = gtk_label_new("글 입력");
entry_chat = gtk_entry_new();
butt_chat = gtk_button_new_with_label ("입력");

hbox_1 = gtk_box_new ( TRUE, 5 );
hbox_2 = gtk_box_new ( TRUE, 5 );
vbox = gtk_box_new ( FALSE, 10);

gtk_box_pack_start(GTK_BOX(hbox_2), label_chat, TRUE, FALSE, 5);
gtk_box_pack_start(GTK_BOX(hbox_2), entry_chat, TRUE, FALSE, 5);
gtk_box_pack_start(GTK_BOX(hbox_2), butt_chat, TRUE, FALSE, 5);

gtk_box_pack_start(GTK_BOX(vbox),hbox_1,FALSE, FALSE, 10);
gtk_box_pack_start(GTK_BOX(vbox),hbox_2,FALSE, FALSE, 10);

gtk_container_add(GTK_CONTAINER(window), vbox);
//g_signal_connect(G_OBJECT(butt_chat),"clicked",G_CALLBACK(button_clicked),NULL);

//start_chat(csock);
//close(csock);
gtk_widget_show_all(window);
}
void c_chat(GtkWidget *widget, gpointer data)
{
char* address;

unsigned short port;
/*
if(argc<2)

address=strdup(defaultAddr);

else
address=strdup(argv[1]);

if(argc<3)

port=defaultPort;

else

port=(unsigned short)atoi(argv[2]);

*/
//csock=connect_chat(address, port);

GtkWidget *window;
GtkWidget *label_chat;
GtkWidget *butt_chat;
GtkWidget *entry_chat;
GtkWidget *vbox;
GtkWidget *hbox_1,*hbox_2;
//gtk_init(&argc, &argv);
window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(window), "채팅" );
gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
gtk_window_set_default_size(GTK_WINDOW(window), 200, 150);
g_signal_connect (G_OBJECT (window), "destroy",G_CALLBACK (quit), NULL);

label_chat = gtk_label_new("글 입력");
entry_chat = gtk_entry_new();
butt_chat = gtk_button_new_with_label ("입력");

hbox_1 = gtk_box_new ( TRUE, 5 );
hbox_2 = gtk_box_new ( TRUE, 5 );
vbox = gtk_box_new ( FALSE, 10);

gtk_box_pack_start(GTK_BOX(hbox_2), label_chat, TRUE, FALSE, 5);
gtk_box_pack_start(GTK_BOX(hbox_2), entry_chat, TRUE, FALSE, 5);
gtk_box_pack_start(GTK_BOX(hbox_2), butt_chat, TRUE, FALSE, 5);

gtk_box_pack_start(GTK_BOX(vbox),hbox_1,FALSE, FALSE, 10);
gtk_box_pack_start(GTK_BOX(vbox),hbox_2,FALSE, FALSE, 10);
gtk_container_add(GTK_CONTAINER(window), vbox);
//g_signal_connect(G_OBJECT(butt_chat),"clicked",G_CALLBACK(button_clicked),NULL);

//start_chat(csock);
//close(csock);
gtk_widget_show_all(window);
}

void Inquiry(GtkWidget *widget, gpointer data){

  GtkWidget *window;
  GtkWidget *button1;
  GtkWidget *fixed;

  window= gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_window_set_title(GTK_WINDOW(window), "입양 동물 조회창" );
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 410, 350);
  g_signal_connect (window, "destroy", G_CALLBACK (quit), NULL);
 fixed = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window), fixed);

  button1 = gtk_button_new_with_label("나가기");
  gtk_fixed_put(GTK_FIXED(fixed), button1, 130, 280);
  gtk_widget_set_size_request(button1, 150, 40);

  g_signal_connect(G_OBJECT(button1), "clicked", G_CALLBACK(quit), NULL);

  gtk_widget_show_all(window);
}
void register22(GtkWidget *widget, gpointer data){

   GtkWidget *window;
   GtkWidget *button1, *label, *fixed;

   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(window), "확인창");
   gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
   gtk_window_set_default_size(GTK_WINDOW(window), 120, 80);
   g_signal_connect(window, "destroy", G_CALLBACK(quit), NULL);
  fixed = gtk_fixed_new();
   gtk_container_add(GTK_CONTAINER(window),fixed);

   button1 = gtk_button_new_with_label("확인");
   gtk_fixed_put(GTK_FIXED(fixed), button1, 70, 40);
   gtk_widget_set_size_request(button1, 20, 20);

   label = gtk_label_new("등록되었습니다.");
   gtk_fixed_put(GTK_FIXED(fixed), label, 10, 15);
   g_signal_connect(G_OBJECT(button1), "clicked", G_CALLBACK(quit), NULL);

  gtk_widget_show_all(window);

}
void register2(GtkWidget *button, gpointer data)
{
 GtkWidget *window;
 GtkWidget *name_label, *age_label, *sex_label;
 GtkWidget *name_entry, *age_entry, *sex_entry;
 GtkWidget *message_label;
 GtkWidget *name_hbox, *age_hbox, *sex_hbox;
 GtkWidget *button1, *button2;
 GtkWidget *fixed;

 window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 gtk_window_set_title(GTK_WINDOW(window), "입양 동물 입력창" );
 gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
 gtk_window_set_default_size(GTK_WINDOW(window), 410, 350);

 g_signal_connect(window, "destroy", G_CALLBACK(quit), NULL);

 fixed = gtk_fixed_new();

 gtk_container_add(GTK_CONTAINER(window),fixed);

 button1 = gtk_button_new_with_label("등록");
 gtk_fixed_put(GTK_FIXED(fixed), button1, 80,250);
 gtk_widget_set_size_request(button1, 70, 50);

 button2 = gtk_button_new_with_label("취소");
 gtk_fixed_put(GTK_FIXED(fixed), button2, 300,250);
gtk_widget_set_size_request(button2, 70, 50);
 g_signal_connect(button2, "clicked", G_CALLBACK(quit), NULL);

 name_label = gtk_label_new("이름 : ");
 gtk_fixed_put(GTK_FIXED(fixed), name_label, 50,70);

 age_label = gtk_label_new("나이 : ");
 gtk_fixed_put(GTK_FIXED(fixed), age_label, 50,120);

 sex_label = gtk_label_new("성별 : ");
 gtk_fixed_put(GTK_FIXED(fixed), sex_label, 50,170);

 name_entry = gtk_entry_new();
 gtk_fixed_put(GTK_FIXED(fixed), name_entry, 200,70);
 gtk_widget_set_size_request(name_entry, 20, 10);

 age_entry = gtk_entry_new();
 gtk_fixed_put(GTK_FIXED(fixed), age_entry, 200,120);
 gtk_widget_set_size_request(age_entry, 20, 10);

 sex_entry = gtk_entry_new();
 gtk_fixed_put(GTK_FIXED(fixed), sex_entry, 200,170);
 gtk_widget_set_size_request(sex_entry, 20, 10);

 message_label= gtk_label_new("등록할 동물 이름과 나이 성별을 입력하세요.");
 gtk_fixed_put(GTK_FIXED(fixed), message_label, 70,20);

 g_signal_connect(button1, "clicked", G_CALLBACK(register22), NULL);

 gtk_widget_show_all(window);

}

static void insert_record (GtkButton *button, Widgets *w)   //입양 절차 기록 (버퍼에 저장)
{
     GtkTextBuffer *buffer;
     GtkTextMark *mark;
     GtkTextIter iter;
     const gchar *a_text, *n_text, *d_text, *p_text;
     GtkWidget *r_window;
     GtkWidget *r_ok, *r_label, *r_fixed;

     r_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
     gtk_window_set_title(GTK_WINDOW(r_window), "확인" );
     gtk_window_set_position(GTK_WINDOW(r_window), GTK_WIN_POS_CENTER);
     gtk_window_set_default_size(GTK_WINDOW(r_window), 120, 80);

     r_fixed = gtk_fixed_new();
     gtk_container_add(GTK_CONTAINER(r_window),r_fixed);

     buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (w->textview));

     a_text = gtk_entry_get_text (GTK_ENTRY (w->aname_entry));
     n_text = gtk_entry_get_text (GTK_ENTRY (w->name_entry));
     d_text = gtk_entry_get_text (GTK_ENTRY (w->date_entry));
     p_text = gtk_entry_get_text (GTK_ENTRY (w->phone_entry));

     mark = gtk_text_buffer_get_insert (buffer);
     gtk_text_buffer_get_iter_at_mark (buffer, &iter, mark);

     if (gtk_text_buffer_get_char_count(buffer))
       gtk_text_buffer_insert (buffer, &iter, "\n", 1);
  
     gtk_text_buffer_insert (buffer, &iter, a_text, -1);
     gtk_text_buffer_insert (buffer, &iter, n_text, -1);
     gtk_text_buffer_insert (buffer, &iter, d_text, -1);
     gtk_text_buffer_insert (buffer, &iter, p_text, -1);

     mark= gtk_text_buffer_get_insert (buffer);
     gtk_text_view_scroll_mark_onscreen (GTK_TEXT_VIEW (w->textview) , mark);

     r_ok = gtk_button_new_with_label("확인");
     gtk_fixed_put(GTK_FIXED(r_fixed), r_ok, 70, 40);
     gtk_widget_set_size_request(r_ok, 20, 20);
 
     r_label = gtk_label_new("기록되었습니다.");
     gtk_fixed_put(GTK_FIXED(r_fixed), r_label, 10, 15);

     g_signal_connect(r_ok, "clicked", G_CALLBACK(quit), NULL);

     gtk_widget_show_all(r_window);
}

void mrecord(GtkButton *button, gpointer data)   //버퍼에 저장된 text 보여주기
{
     GtkWidget *window, *scrolled_win, *vbox, *hbox;
     Widgets *w = g_slice_new (Widgets);

     window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
     gtk_window_set_title (GTK_WINDOW (window), "입양 예약 기록창");
     gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
     gtk_widget_set_size_request (window, 350, 300);

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

void record(GtkWidget *button, gpointer data)   //입양 예약 절차 입력창
{
    GtkWidget *window;
    Widgets *w = g_slice_new(Widgets);
    GtkWidget *aname_label, *name_label, *date_label, *phone_label;
    GtkWidget *message_label;
    GtkWidget *button1, *button2, *fixed;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "입양 예약 절차 입력창" );
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 410, 350);

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

    date_label = gtk_label_new("입양 예약 날짜 :");
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
  
    gtk_widget_show_all(window);

    g_signal_connect(button1, "clicked", G_CALLBACK(insert_record), (gpointer) w);

}

void ani_process_explain(GtkWidget *widget, gpointer data)
{
  enum
  {
      COLUMN_ORDER,
      COLUMN_PROCESS,
      N_COLUMNS
   };

  GtkWidget *window;
  GtkTreeStore *store;
  GtkWidget *view;
  GtkTreeIter parent_iter, child_iter;
  GtkCellRenderer *renderer;

  window= gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "입양과정");
  gtk_window_set_default_size ( GTK_WINDOW(window), 300, 300);
  g_signal_connect (window, "destroy", G_CALLBACK (quit), NULL);
  store= gtk_tree_store_new (N_COLUMNS, G_TYPE_STRING, G_TYPE_STRING);

  gtk_tree_store_append (store, &parent_iter, NULL);
  gtk_tree_store_set (store, &parent_iter, COLUMN_ORDER, "첫번째",-1);
  gtk_tree_store_append (store, &child_iter, &parent_iter);
  gtk_tree_store_set (store, &child_iter, COLUMN_PROCESS, "입양할 동물 정하기", -1);

  gtk_tree_store_append (store, &parent_iter, NULL);
  gtk_tree_store_set (store, &parent_iter, COLUMN_ORDER, "두번째",-1);
  gtk_tree_store_append (store, &child_iter, &parent_iter);
  gtk_tree_store_set (store, &child_iter, COLUMN_PROCESS, "입양 예약 절차대로 작성후 예약", -1);

  gtk_tree_store_append (store, &parent_iter, NULL);
  gtk_tree_store_set (store, &parent_iter, COLUMN_ORDER, "세번째",-1);
  gtk_tree_store_append (store, &child_iter, &parent_iter);
  gtk_tree_store_set (store, &child_iter, COLUMN_PROCESS, "방문하여 입양확정 후 서류작성하기", -1);

  gtk_tree_store_append (store, &parent_iter, NULL);
  gtk_tree_store_set (store, &parent_iter, COLUMN_ORDER, "네번째",-1);
  gtk_tree_store_append (store, &child_iter, &parent_iter);
  gtk_tree_store_set (store, &child_iter, COLUMN_PROCESS, "유기동물에게 칩 삽입", -1);
  gtk_tree_store_append (store, &parent_iter, NULL);
  gtk_tree_store_set (store, &parent_iter, COLUMN_ORDER, "다섯번째",-1);
  gtk_tree_store_append (store, &child_iter, &parent_iter);
  gtk_tree_store_set (store, &child_iter, COLUMN_PROCESS, "시/군청에 방문해 동물등록증 발급", -1);

  gtk_tree_store_append (store, &parent_iter, NULL);
  gtk_tree_store_set (store, &parent_iter, COLUMN_ORDER, "칩 삽입 Tip ",-1);
  gtk_tree_store_append (store, &child_iter, &parent_iter);
  gtk_tree_store_set (store, &child_iter, COLUMN_PROCESS, "내장형 무선식별장치, 외장형 무선식별장치, 등록인식표 세가지 방법 중 하나를 선택", -1);

  gtk_tree_store_append (store, &parent_iter, NULL);
  gtk_tree_store_set (store, &parent_iter, COLUMN_ORDER, "Tip",-1);
  gtk_tree_store_append (store, &child_iter, &parent_iter);
  gtk_tree_store_set (store, &child_iter, COLUMN_PROCESS, "입양시 예방접종을 위한 비용 등은 개별문의 ", -1);

  view= gtk_tree_view_new_with_model (GTK_TREE_MODEL (store));
  renderer= gtk_cell_renderer_text_new ();
  gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW(view), COLUMN_ORDER, "순서", renderer, "text", COLUMN_ORDER, NULL);
gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW(view), COLUMN_PROCESS, "과정", renderer, "text", COLUMN_PROCESS, NULL);
  gtk_container_add(GTK_CONTAINER(window), view);
  gtk_widget_show_all(window);
}

void customer(GtkWidget *widget, gpointer data)
{
//  GtkWidget *dialog;
  GtkWidget *window;
  GtkWidget *inquiry,*process_explain,
                *adoption_process, *c_one_to_one;
//  GtkWidget *ok,*cancle;
  GtkWidget *message_label;
  gint result;

 window= gtk_window_new(GTK_WINDOW_TOPLEVEL);
 gtk_window_set_title(GTK_WINDOW(window), "Customer" );
 gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
 gtk_window_set_default_size(GTK_WINDOW(window), 200, 250);
 g_signal_connect (window, "destroy",
                     G_CALLBACK(quit), NULL);
  frame = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window),frame);
  inquiry = gtk_button_new_with_label("조회");
  gtk_fixed_put(GTK_FIXED(frame), inquiry,75, 30);
  gtk_widget_set_size_request(inquiry, 50, 30);

  process_explain = gtk_button_new_with_label("입양 과정 설명");
  gtk_fixed_put(GTK_FIXED(frame), process_explain, 50, 80);
  gtk_widget_set_size_request(process_explain, 50, 30);

  adoption_process = gtk_button_new_with_label("입양 예약 절차");
  gtk_fixed_put(GTK_FIXED(frame), adoption_process, 50, 130);
  gtk_widget_set_size_request(adoption_process, 50, 30);

  c_one_to_one  = gtk_button_new_with_label("1:1문의");
  gtk_fixed_put(GTK_FIXED(frame), c_one_to_one, 70, 180);
  gtk_widget_set_size_request(c_one_to_one, 50, 30);

  gtk_widget_show_all(window);
  g_signal_connect(G_OBJECT(inquiry),"clicked",G_CALLBACK(Inquiry),NULL);
  g_signal_connect(G_OBJECT(process_explain),"clicked",G_CALLBACK(ani_process_explain),NULL);
  g_signal_connect(G_OBJECT(adoption_process),"clicked",G_CALLBACK(record),NULL);
  g_signal_connect(G_OBJECT(c_one_to_one),"clicked",G_CALLBACK(c_chat),NULL);
}

void manager(GtkWidget *widget, gpointer data)
{
//  GtkWidget *dialog;
  GtkWidget *window;
  GtkWidget *ani_register,*adoption_recode,*s_one_to_one;
//  GtkWidget *ok,*cancle;
  GtkWidget *message_label;
  gint result;

  window= gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Manager" );
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
  g_signal_connect (window, "destroy",
                     G_CALLBACK(quit), NULL);

 frame = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window),frame);
  ani_register = gtk_button_new_with_label("등록");
  gtk_fixed_put(GTK_FIXED(frame), ani_register,75, 30);
  gtk_widget_set_size_request(ani_register, 50, 30);

  adoption_recode = gtk_button_new_with_label("입양 예약 기록 보기");
  gtk_fixed_put(GTK_FIXED(frame), adoption_recode, 40, 80);
  gtk_widget_set_size_request(adoption_recode, 50, 30);

  s_one_to_one = gtk_button_new_with_label("1:1문의");
  gtk_fixed_put(GTK_FIXED(frame), s_one_to_one, 65, 130);
  gtk_widget_set_size_request(s_one_to_one, 50, 30);

  gtk_widget_show_all(window);
  g_signal_connect(G_OBJECT(ani_register),"clicked",G_CALLBACK(register2), NULL);
  g_signal_connect(G_OBJECT(s_one_to_one),"clicked",G_CALLBACK(s_chat),NULL);
  g_signal_connect(G_OBJECT(adoption_recode),"clicked",G_CALLBACK(mrecord),NULL);
}


int main(int argc, char*argv[])
{
  GtkWidget *window;
  GtkWidget *label, *label2;
//  GtkWidget *fixed;
  GtkWidget *bt_customer, *bt_manager;

  gtk_init(&argc, &argv);
  window= gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW(window), "Pure");
 gtk_window_set_position (GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size (GTK_WINDOW (window), 250, 130);
  g_signal_connect ( window, "destroy", G_CALLBACK (quit), NULL);

  frame = gtk_fixed_new();
  gtk_container_add (GTK_CONTAINER(window), frame);

  label = gtk_label_new("어서오세요.");
  gtk_fixed_put(GTK_FIXED(frame), label, 90, 20);
  label2 = gtk_label_new(" Pure에 오신걸 환영합니다.");
  gtk_fixed_put(GTK_FIXED(frame), label2, 40, 40);
  bt_customer = gtk_button_new_with_label("고객");
  gtk_fixed_put(GTK_FIXED(frame), bt_customer, 25, 70);
  gtk_widget_set_size_request(bt_customer, 90, 50);
  bt_manager = gtk_button_new_with_label("관리자");
  gtk_fixed_put(GTK_FIXED(frame), bt_manager, 135, 70);
  gtk_widget_set_size_request(bt_manager, 90, 50);

  g_signal_connect(bt_customer,"clicked", G_CALLBACK(customer),NULL);
  g_signal_connect(bt_manager,"clicked",G_CALLBACK(manager),NULL);

  gtk_widget_show_all(window);
  gtk_main ();
  return 0;
}
