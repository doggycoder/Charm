#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include "QOpenGLItem.h"
#include "EffectRenderer.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterType<QOpenGLItem>("wuwang.QOpenGLItem", 1, 0, "QOpenGLItem");
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    QObject *pRoot = engine.rootObjects().first();
    auto glItem = dynamic_cast<QOpenGLItem *>(pRoot->findChild<QObject *>("engineViewItem"));
    if( glItem ) {
        std::shared_ptr<Render> render = std::make_shared<EffectRenderer>();
        glItem->setRenderer(render);
    }

    return QGuiApplication::exec();
}
