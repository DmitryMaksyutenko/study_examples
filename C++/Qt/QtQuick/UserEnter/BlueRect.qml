import QtQuick 2.8

Rectangle {
    id: blueRect;
    width: parent.width / 2;
    height: parent.height / 2;
    x: parent.x;
    y: parent.y + height;
    color: baseColor;
    border.color: borderColor;

    property var baseColor: "blue";
    property var borderColor: "blue";
    property alias text: message.text;

    signal mySignal(int x, int y);

    Text {
        id: message;
        anchors.centerIn: parent;
        text: "Mouse position";
    }

    MouseArea {
        id: redRectMouseArea;
        anchors.fill: parent;
        hoverEnabled: true;

        onMouseXChanged: blueRect.mySignal(mouseX, mouseY);
        onMouseYChanged: blueRect.mySignal(mouseX, mouseY);
    }

}
