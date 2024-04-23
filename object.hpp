#include <QLabel>
 #include <QLabel>
 #include <QWidget>
 #include <QPixmap>
Class Object  { 

    QPixmap image;// = image.scaled(h, w,  Qt::KeepAspectRatio);    
    int pos_x; 
    int pos_y; 
   Object( Qwidget window,  int start_x, int start_y, QPixmap temp_image, int o_w, int o_h ){ 
       pos_x = start_x;
       post_y = start_y; 
       image = temp_image.scaled(o_h, o_w,  Qt::KeepAspectRatio);
       QLabel label(&window);
       label.setPixmap(rock_image);
       label.setGeometry(pos_x, pos_y, o_h, o_w);
   }
};  

