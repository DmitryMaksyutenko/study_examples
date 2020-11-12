import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: mainWindow
    visible: true
    visibility: Window.Maximized

    Rectangle{
        anchors.fill: parent

        Image {
            id: img
            source: "https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcQN-15Oy-jzO65YIgGMzDS2-qJ6wdbKG2TLXw&usqp=CAU"
            width: 100
            height: 100
            x: mainWindow.width / 2
            y: mainWindow.height / 2
            smooth: true

            Behavior on x {
                NumberAnimation {
                    duration: 1000
                    easing.type: easing.OutBounce
                }
            }

            Behavior on y {
                NumberAnimation {
                    duration: 1000
                    easing.type: easing.OutBounce
                }
            }
        }

        MouseArea {
            id: mainWindowMouseArea
            anchors.fill: parent
            hoverEnabled: true
            onMouseXChanged: img.x = mouseX - img.width / 2
            onMouseYChanged: img.y = mouseY - img.height / 2
        }
    }

}
