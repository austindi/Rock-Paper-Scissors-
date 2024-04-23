#include <random>
#include <QString>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <cstdlib>
#include <cmath>
#include <cstdlib> 
#include <iostream> 
#include <QTimer>
#include <vector>
#include <memory>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPixmap>

class Object {
public:
    QPixmap image;
    int pos_x;
    int pos_y;
    int vx;
    int  vy; 
    std::string  ob_type;
    QLabel label;
         Object(QWidget &parent, int start_x, int start_y, QPixmap temp_image, int o_w, int o_h,int v_x, int v_y,std::string type )
        : image(temp_image.scaled(o_w, o_h, Qt::KeepAspectRatio)), pos_x(start_x), pos_y(start_y),vx( v_x ) , vy( v_y ), ob_type( type ) ,  
          label(&parent) { // Assign to the member label
        label.setPixmap(image);
        label.setGeometry(pos_x, pos_y, o_w, o_h);
        label.show();
    }
    void changeImage( QPixmap new_image, std::string new_type, int o_w, int o_h ) {
       ob_type = new_type;
       image = new_image.scaled(o_w, o_h, Qt::KeepAspectRatio);
       label.setPixmap(image);
    };
    void move( ){
        int new_x = pos_x + vx ;
        int new_y = pos_y + vy ; 
        /*
        if ( new_x < 0 )
        {   pos_x = new_x + 400; }
        else if ( new_x > 400 )
           { pos_x = new_x - 400 ; }
        else { pos_x = new_x; } 
        if ( new_y < 0 )
         {   pos_y = new_y + 400; }
         else if ( new_y > 400 )
           { pos_y = new_y - 400 ; }
         else { pos_y = new_y; }*/
        if ( new_x < 0 || new_x > 380 ){ vx = -1 * vx; }
        if ( new_y < 100 || new_y > 380 ){ vy = -1 * vy; } 
        pos_x = pos_x + vx ;
        pos_y = pos_y + vy ;
        label.move(pos_x, pos_y);
    };

};
int distanceBetweenPoints(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    std::vector<std::unique_ptr<Object>> vector;
    // Create a QWidget to hold the QLabel
    int num_ob = 120;
    QWidget window;
    window.setWindowTitle("PNG Image Example");
    window.setGeometry(100, 100, 400, 500);
    window.setStyleSheet("background-color: white;");


          QLabel *textLabel = new QLabel("Scissors", &window);
         textLabel->setStyleSheet("color: black;");
    // Move the text label to a new location
    textLabel->move(100, 30);

           QLabel *textLabela = new QLabel( QString::number(1000), &window);
           textLabela->setStyleSheet("color: black;");
      // Move the text label to a new location
      textLabela->move(100, 45);
     textLabela -> setText( QString::number(num_ob/3) );
           QLabel *textLabel2 = new QLabel("Rock", &window);
          textLabel2->setStyleSheet("color: black;");
     // Move the text label to a new location
     textLabel2->move(200, 30); 

             QLabel *textLabel2a = new QLabel( QString::number(1000), &window);
            textLabel2a->setStyleSheet("color: black;");
       // Move the text label to a new location
       textLabel2a ->move(200, 45);
textLabel2a -> setText( QString::number(num_ob/3) );
     QLabel *textLabel3 = new QLabel("Paper", &window);
          textLabel3->setStyleSheet("color: black;");
     // Move the text label to a new location
     textLabel3->move(300, 30);
    
      QLabel *textLabel3a = new QLabel( QString::number(1000), &window);
           textLabel3a->setStyleSheet("color: black;");
      // Move the text label to a new location
      textLabel3a->move(300, 45);
textLabel3a -> setText( QString::number(num_ob/3) );


    // Load the PNG image using QPixmap
    QPixmap image_rock("rock.png");
    QPixmap image_paper( "paper.png"); 
    QPixmap image_scissors( "scissors.png");
    // Create Object dynamically
    //Object *rock1 = new Object(window, 50, 50, image, 20, 20);
    int i;
    double angle ;
    int x;
    int y; 
    int rc = 0 ;
    int sc = 0;
    int pc = 0; 
    for ( i = 0 ; i <num_ob ; i ++ )
    {
            std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister pseudo-random number generator
    std::uniform_real_distribution<double> dis(0.0, 2 * M_PI);
    double angle = dis(gen);
         x = static_cast<int>((std::cos(angle) + 1) * 5); // Map [-1, 1] to [0, 10]
         y = static_cast<int>((std::sin(angle) + 1) * 5);
         if ( x == 0 ){ x = 1 ;}
         if ( y == 0 ) { y =1 ; }
     if ( i%3 == 0 ){
      rc = rc + 1;
     vector.push_back(std::make_unique<Object>(window,  10  , 110 , image_rock, 20, 20, x, y, "rock"));
     }
     else if ( i%3 ==1 ){ 
      pc = pc + 1;
     vector.push_back(std::make_unique<Object>(window,  10  , 370 , image_paper, 20 , 20 , x, y, "paper")); 
     }
     else if ( i %3 == 2 ) 
     {    sc = sc + 1;
     vector.push_back(std::make_unique<Object>(window,  370  , 370 , image_scissors, 30 , 30, x, y, "scissors"));
     }
     }
     //Object  Object(window,  10  , 10 , image, 20, 20);
     //Object paper1 = Object(window, 40  , 40 ,image2,  20, 20);
     //Object sicssors1 = Object(window,  80  , 80 , image3, 30, 30);
    // Show the window
    window.show();
     QTimer timer;
     timer.start(100); // Start the timer with a 10-second interval

    // Connect a lambda function to the timeout signal of the timer
    int moveCount = 0;
    std::size_t j = 0; 
    std::size_t k = 0;
    int p1_x ;
    int p1_y;
    int p2_x; 
    int p2_y; 
    std::string p1_t;
    std::string p2_t;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
          //  std::cout << nt << '\n';
            for ( j= 0 ; j < vector.size() ; j++ ){ 
               vector[j]->move();} // First move
            for  ( j= 0 ; j < vector.size() ; j++ ){
             for  ( k= 0 ; k < vector.size() ; k++ ){
                 p1_x = vector[ j ] -> pos_x;
                 p1_y = vector[ j ] -> pos_y;
                 p2_x = vector[ k ] -> pos_x;
                 p2_y = vector[ k ] -> pos_y;
                 p1_t = vector[ j ] -> ob_type;
                 p2_t = vector[ k ] -> ob_type; 
                 if ( j != k &&  distanceBetweenPoints(p1_x, p1_y, p2_x, p2_y) < 10 ){  
                 if ( p1_t == "scissors" && p2_t == "paper" ) { vector[ k ] -> changeImage( image_scissors, "scissors", 30,30); pc = pc -1 ; sc = sc +1;  }
                 else if  ( p2_t == "scissors" && p1_t == "paper" ) { vector[ j ] -> changeImage( image_scissors, "scissors", 30,30); pc = pc - 1 ; sc = sc + 1; }
                 else if ( p1_t == "rock" && p2_t == "paper" ) { vector[ j ] -> changeImage( image_paper, "paper", 20,20) ; pc = pc + 1; rc = rc - 1;}
                 else if ( p2_t == "rock" && p1_t == "paper" ) {   vector[ k ] -> changeImage( image_paper, "paper", 20,20);pc = pc + 1; rc = rc - 1;}
                 else if ( p1_t == "scissors" && p2_t == "rock" ) {  vector[ j ] -> changeImage( image_rock, "rock", 20,20) ;rc = rc + 1; sc = sc -1; }
                 else if ( p2_t == "scissors" && p1_t == "rock" ) { vector[ k ] -> changeImage( image_rock, "rock", 20,20) ; rc = rc + 1; sc = sc -1;}
                 }
               textLabela-> setText(QString::number( sc ) ) ;
               textLabel2a-> setText(QString::number(rc ) ) ;
              textLabel3a-> setText(QString::number( pc ) ) ;    
             }}
            moveCount++;
        if (rc == 0 || sc == 0 || pc == 0) {
            timer.stop(); // Stop the timer after the second move
            }
    });

    timer.start();
    return app.exec();
}

