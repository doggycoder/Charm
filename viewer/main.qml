import QtQuick 2.12
import QtQuick.Window 2.12
import wuwang.QOpenGLItem 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    QOpenGLItem{
        objectName : "engineViewItem"
    }
}
