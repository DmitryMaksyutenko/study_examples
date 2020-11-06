import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

/*
    The root elememt.
*/
Window {
    // The properties.
    width: 640;	// The semicolon not necessary.
    height: 480;
    visible: true;
    title: qsTr("Hello World");
    color: "#b2d1ba";

    MouseArea {
        anchors.fill: parent;
        // JavaScript code.
        onClicked: {
            console.log("Clicked on background. Text: '" + textEdit.text + "'");
        }
    }

    TextEdit {
        id: textEdit;
        text: qsTr("Enter some text...");
        verticalAlignment: Text.AlignVCenter;
        anchors.top: parent.top;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.topMargin: parent.height / 2;

        Rectangle{
            anchors.fill: parent;
            anchors.topMargin: -10;
            color: "transparent";
            border.width: 1;
        }

    }

}
