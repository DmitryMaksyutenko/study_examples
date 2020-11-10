import QtQuick 2.0

Rectangle {
    id: redRect;
    width: parent.width / 2;
    height: parent.height / 2;
    x: parent.x;
    y: parent.y;
    color: baseColor;
    border.color: borderColor;

    property var baseColor: "red";
    property var clickColor: "white";
    property var borderColor: "red";
    property var leftMouseMessage: "Click left mouse button on me.";
    property var rightMouseMessage: "Click right mouse button on me.";

    signal mySignal(int x, int y);

    MouseArea {
        id: redRectMouseArea;
        anchors.fill: parent;
        hoverEnabled: true;
        acceptedButtons: Qt.LeftButton | Qt.RightButton;

        onPressed: {
            mouse.button == Qt.LeftButton ? leftButton() :
                            mouse.button == Qt.RightButton ? rigthButton(): 0;
        }
        function leftButton() {
           parent.color = clickColor;
           message.text = rightMouseMessage;
        }
        function rigthButton() {
            parent.color = baseColor;
            message.text = leftMouseMessage;
        }
        onMouseXChanged: redRect.mySignal(mouseX, mouseY);
        onMouseYChanged: redRect.mySignal(mouseX, mouseY);
    }

    Text {
        id: message;
        text: leftMouseMessage;
        anchors.centerIn: parent;
    }
}
