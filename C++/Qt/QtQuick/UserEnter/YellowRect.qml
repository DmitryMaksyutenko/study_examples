import QtQuick 2.0

Rectangle {
    id: yellowRect;
    width: parent.width / 2;
    height: parent.height / 2;
    x: parent.x + width;
    y: parent.y + height;
    color: "yellow";
    border.color: "black";


    signal mySignal(int x, int y);

    MouseArea {
        id: yellowRectMouseArea;
        anchors.fill: parent;
        hoverEnabled: true;
        onMouseXChanged: yellowRect.mySignal(mouseX, mouseY);
        onMouseYChanged: yellowRect.mySignal(mouseX, mouseY);
    }

    TextEdit {
        id: userMessage;
        width: parent.width;
        anchors.centerIn: parent;
        color: "red";
        font.pixelSize: 24;
        focus: true;
        wrapMode: TextEdit.WordWrap;

        property var placeholderText: "Enter some text here.";

        Text {
            id: placeholder;
            text: parent.placeholderText;
            visible: !parent.text;
        }
    }
}
