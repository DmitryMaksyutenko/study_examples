import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: mainWindow;
    width: 640;
    height: 480;
    visible: true;
    color: "#523a3a"
    title: qsTr("Hello World");

    Image {
        id: centerImg;
        visible: true;
        anchors.centerIn: parent;
        source: "https://wallpapercave.com/wp/EQAEzcs.jpg"
        sourceSize.height: 120;
        sourceSize.width: 120;
        scale: 3.50;
        rotation: 90;
        smooth: true;

        Column {
            id: centerColumn;
            anchors.centerIn: parent;
            visible: centerImg.status == Image.Loading ? true : false;
            rotation: -90;

            Text {
                id: loadingText;
                text: "Loading...";
                anchors.horizontalCenter: parent.horizontalCenter;
            }

            BusyIndicator {
                id: indicator;
                anchors.horizontalCenter: parent.horizontalCenter;
            }
        }
    }
}
