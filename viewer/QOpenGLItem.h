#include <utility>

//
// Created by wuwang on 19-10-7.
//

#pragma once

#include <QtQuick>

class Render{
public:
    virtual void onInit() = 0;
    virtual void onSizeChanged(int width,int height) = 0;
    virtual void onDrawFrame() = 0;
};

class QOpenGLItem : public QQuickItem {
    Q_OBJECT
public:
    QOpenGLItem();

    void setRenderer(std::shared_ptr<Render> render){
        this->render = std::move(render);
    };
public slots:
    void sync();
    void cleanup();
protected:
    void timerEvent(QTimerEvent *event) override;

private:
    QBasicTimer timer;
    std::shared_ptr<Render> render;
};


