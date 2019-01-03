//
// Created by wuwang on 18-12-24.
//

#ifndef CHARM_GLFWWINDOW_H
#define CHARM_GLFWWINDOW_H

class GLFWwindow;

class GlfwWindow {
private:
    int width{368};
    int height{640};
    int x{0};
    int y{0};
    static void callbackProcessInput(GLFWwindow *window);
    static void callbackFramebufferSizeChanged(GLFWwindow* window, int width, int height);
    static void callbackMouseButton(GLFWwindow * window, int button, int action, int bit);
    static void callbackCursorPos(GLFWwindow * window, double x, double y);

    void (*init)(int, int){nullptr};
    void (*draw)(){nullptr};
public:
    GlfwWindow();

    void setSize(int width,int height);
    void setPosition(int x,int y);
    void setGlInitCallback(void(*init)(int,int)){this->init = init;};
    void setGlDrawCallback(void(*draw)()){this->draw = draw;};
    void startLoop();
};

#endif //CHARM_GLFWWINDOW_H
