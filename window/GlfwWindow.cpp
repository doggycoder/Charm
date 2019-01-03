//
// Created by wuwang on 18-12-24.
//

#include "GlfwWindow.h"
#include <iostream>
#include <GLFW/glfw3.h>

GlfwWindow::GlfwWindow() {

}

//输入控制，检查用户是否按下了返回键(Esc)
void GlfwWindow::callbackProcessInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// 当用户改变窗口的大小的时候，视口也应该被调整
void GlfwWindow::callbackFramebufferSizeChanged(GLFWwindow* window, int width, int height)
{
    // 注意：对于视网膜(Retina)显示屏，width和height都会明显比原输入值更高一点。
    glViewport(0, 0, width, height);
}

void GlfwWindow::callbackMouseButton(GLFWwindow * window, int button, int action, int bit){
//    std::cout<<"mouse: button="<<button<<", action="<<action<<", bit="<<bit<<std::endl;
//    if(action == GLFW_RELEASE && button == GLFW_MOUSE_BUTTON_LEFT){
//        std::cout<<"left button release"<<std::endl;
//    }else if(action == GLFW_PRESS && button == GLFW_MOUSE_BUTTON_LEFT){
//        std::cout<<"left button press"<<std::endl;
//    }else if(action == GLFW_RELEASE && button == GLFW_MOUSE_BUTTON_RIGHT){
//        std::cout<<"right button release"<<std::endl;
//    }else if(action == GLFW_PRESS && button == GLFW_MOUSE_BUTTON_RIGHT){
//        std::cout<<"right button press"<<std::endl;
//    }
}

void GlfwWindow::callbackCursorPos(GLFWwindow * window, double x, double y){
//    std::cout<<"cursor pos:"<<x << ","<<y<<std::endl;
}


void GlfwWindow::setSize(int width, int height) {
    this->width = width;
    this->height = height;
}

void GlfwWindow::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

void GlfwWindow::startLoop() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    GLFWwindow* window = glfwCreateWindow(width, height, "Window", NULL, NULL);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    int monitorCount = 0;
    GLFWmonitor ** monitors = glfwGetMonitors(&monitorCount);
    std::cout << "Now, Screen number is " << monitorCount << std::endl;
    int screenWidth = 1920;
    int screenHeight = 1080;
    for(int i=0; i<monitorCount; i++){
        const GLFWvidmode * mode = glfwGetVideoMode(monitors[i]);
        screenWidth = mode->width;
        screenHeight = mode->height;
        std::cout << "Screen size is X = " << mode->width << ", Y = " << mode->height << std::endl;
        break;
    }
    glfwSetWindowPos(window, (screenWidth - width)/2, (screenHeight - height)/2);
    //通知GLFW将我们窗口的上下文设置为当前线程的主上下文
    glfwMakeContextCurrent(window);
    //对窗口注册一个回调函数,每当窗口改变大小，GLFW会调用这个函数并填充相应的参数供你处理
    glfwSetFramebufferSizeCallback(window, callbackFramebufferSizeChanged);
    //注册鼠标点击事件
    glfwSetMouseButtonCallback(window, callbackMouseButton);
    //注册鼠标光标事件
    glfwSetCursorPosCallback(window,callbackCursorPos);

    if(init!=nullptr){
        init(width,height);
    }

    glEnable(GL_DEPTH_TEST);
    //渲染循环
    while(!glfwWindowShouldClose(window))
    {
        // 渲染指令
        glClearColor(0.8f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        if(draw != nullptr){
            draw();
        }
        // 检查并调用事件，交换缓冲
        glfwSwapBuffers(window);//检查触发事件
        glfwPollEvents();    //交换颜色缓冲
    }

    //释放/删除之前的分配的所有资源
    glfwTerminate();
}

