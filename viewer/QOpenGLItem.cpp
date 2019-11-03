//
// Created by wuwang on 19-10-7.
//

#include "QOpenGLItem.h"

QOpenGLItem::QOpenGLItem() {
    timer.start(12, this);
    connect(this, &QQuickItem::windowChanged, this, [this](QQuickWindow *window)
    {
        if (window)
        {
            connect(window, &QQuickWindow::beforeSynchronizing, this, &QOpenGLItem::sync,
                    Qt::DirectConnection);
            connect(window, &QQuickWindow::sceneGraphInvalidated, this, &QOpenGLItem::cleanup,
                    Qt::DirectConnection);

            window->setClearBeforeRendering(false);
        }
        else return;
    });
}

void QOpenGLItem::sync() {
    if (render) {
        render->onInit();   //可以放在Render的构造函数中
        render->onSizeChanged(window()->width(), window()->height());
        connect(window(), &QQuickWindow::beforeRendering, this, [this]()
        {
            //window()->resetOpenGLState();
            render->onDrawFrame();
        }, Qt::DirectConnection);
        connect(window(), &QQuickWindow::afterRendering, this, [this]()
        {
            //渲染后调用，计算fps
        }, Qt::DirectConnection);
        connect(window(), &QQuickWindow::widthChanged, this, [this]()
        {
            render->onSizeChanged(window()->width(), window()->height());
        });
        connect(window(), &QQuickWindow::heightChanged, this, [this]()
        {
            render->onSizeChanged(window()->width(), window()->height());
        });
    }
}

void QOpenGLItem::cleanup() {

}

void QOpenGLItem::timerEvent(QTimerEvent *event) {
    Q_UNUSED(event);
    window()->update();
}