import QtQuick 2.0

Rectangle {
    id: central_rect;
    width: 1000;
    height: 1000;
    color: "yellow";

    Text {
        id: central_rect_text;
        anchors.centerIn: central_rect;
        text: qsTr("Hello!");
    }

}
