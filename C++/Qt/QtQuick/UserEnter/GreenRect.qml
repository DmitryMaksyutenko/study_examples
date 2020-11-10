import QtQuick 2.8

Rectangle {
    id: greenRect;
    width: parent.width / 2;
    height: parent.height / 2;
    x: parent.x + width;
    y: parent.y;
    color: baseColor;
    border.color: borderColor;

    property var borderColor : "green";
    property var baseColor : "green";
    property var colorOnHoverd : "white";
    property var baseMessage: "Hover me";
    property var hoverMessage: "Come out";

    signal mySignal(int x, int y);

    MouseArea {
        id: greenRectMouseArea;
        anchors.fill: parent;
        hoverEnabled: true;

        onEntered: {
            parent.color = colorOnHoverd
            message.text = hoverMessage;
        }
        onExited: {
            parent.color = baseColor;
            message.text = baseMessage;
        }
        onMouseXChanged: greenRect.mySignal(mouseX, mouseY);
        onMouseYChanged: greenRect.mySignal(mouseX, mouseY);
    }

    Text {
        id: message;
        text: baseMessage;
        anchors.centerIn: parent;
    }
}
