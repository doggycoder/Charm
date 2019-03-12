#include <iostream>
#include "ui_mainwindow.h"
#include "camera/QtCameraDrawer.h"


int main(int argc, char *argv[]){

    std::cout << "Hello World!" <<std::endl;
    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::RenderableType::OpenGLES);
    QSurfaceFormat::setDefaultFormat(format);
    QApplication a(argc, argv);
    QMainWindow w;
    w.setWindowFlags(Qt::WindowFlags::enum_type::Dialog);
    Ui::MainWindow window;
    std::string pa = "/home/wuwang/Desktop/801__360P.mp4";
    auto * drawTest = new QtCameraDrawer(0);
    window.setupUi(&w);
    window.openGLWidget->setGlFunction(drawTest);
    w.show();

    return QApplication::exec();
}
