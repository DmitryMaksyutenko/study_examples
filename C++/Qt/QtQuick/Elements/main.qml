import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: main;
    width: 640;
    height: 480;
    visible: true;
    title: qsTr("Elements");

    Row {
        id: row
        anchors.fill: parent;
        spacing: 10;

        Rectangle {
            visible: true;
            color: "red";
            width: (parent.width / 4) - parent.spacing;
            height: parent.height / 4;
        }

        Rectangle {
            visible: true;
            color: "green";
            width: (parent.width / 4) - parent.spacing;
            height: parent.height / 4;
        }

        Rectangle {
            visible: true;
            color: "blue";
            width: (parent.width / 4) - parent.spacing;
            height: parent.height / 4;
        }

        Rectangle {
            visible: true;
            color: "yellow";
            width: (parent.width / 4) - parent.spacing;
            height: parent.height / 4;
        }

    }

        MyRect {
            x: 250;
            y: 200;
        }

}
