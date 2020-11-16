import QtQuick 2.12
import QtQuick.Window 2.12
import BlueRect 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    BlueRect {
        id: blueRect
        anchors.centerIn: parent
        width: 300
        height: 300
    }
}
