import QtQuick 2.0

Text {
    id: info;
    anchors.centerIn: parent;
    text: "Scale: " + rectScale + "<br>Angle: " + rectAngle;

    property var rectScale: "0";
    property var rectAngle: "0";
}
