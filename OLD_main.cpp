#include <iostream>
#include <QPainter>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPixmap>


int main(int argc, char *argv[]) {
    // Create a QWidget to hold the QLabel
    QWidget window;
    window.setWindowTitle("PNG Image Example");
    window.setGeometry(100, 100, 400,400);
    window.setStyleSheet("background-color: white;");
    // Load the PNG image using QPixmap
    QPixmap image("rock.png");
    int h = 20;
    int w = 20; 
    QPixmap rock_image = image.scaled(h, w,  Qt::KeepAspectRatio);   
    // Create a QLabel to display the image
    QLabel label(&window);
    label.setPixmap(rock_image);
    label.setGeometry(50, 50, h, w);

    QPixmap image2("paper.png"); // Replace "example.png" with the path to your PNG image
    QPixmap paper_image = image2.scaled(h, w,  Qt::KeepAspectRatio);
    // Create a QLabel to display the image
    QLabel label2(&window);
    label2.setPixmap(paper_image);
    label2.setGeometry(70, 70, h,w  );//image.width(), image.height());

    // Show the window
    window.show();

    return app.exec();
}
