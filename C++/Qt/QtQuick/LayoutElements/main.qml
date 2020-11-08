import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: mainWindow;
    width: 640;
    height: 480;
    minimumHeight: 420;
    minimumWidth: 600;
    visible: true;
    title: qsTr("Hello World");

    Rectangle {
        id: mainRect;
        anchors.fill: parent;

        Rectangle {
            id: greenRect;
            width: 520;
            height: 400;
            anchors {
                top: parent.top;
                left: parent.left;
                right: parent.right;
                bottom: parent.bottom;
                topMargin: 30;
                leftMargin: 30;
                rightMargin: 30;
                bottomMargin: 30;
            }
            color: "green";

            Text {
                id: testTest;
                text: qsTr("Hello");
                font.pointSize: 100
                anchors.centerIn: parent;
            }

        }
    }
}
