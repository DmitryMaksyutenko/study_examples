import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: rect
        color: "green"
        width: 300
        height: 300
        border.color: "black"
        anchors.centerIn: parent

        Image {
            id: img
            source: "https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcQN-15Oy-jzO65YIgGMzDS2-qJ6wdbKG2TLXw&usqp=CAU"
            x: 1
            y: 1
            height: 200
            width: 200

            property var endSize: 50
        }

        PropertyAnimation {
            target: img
            properties: "x, y"
            running: true
            from: 1
            to: rect.height - img.endSize
            duration: 2000
            loops: Animation.Infinite
            easing.type: Easing.InOutSine
        }

        PropertyAnimation {
            target: img
            properties: "width, height"
            running: true
            from: img.width
            to: img.endSize
            duration: 2000
            loops: Animation.Infinite
            easing.type: Easing.InOutSine
        }
    }
}
