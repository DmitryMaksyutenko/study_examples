import QtQuick 2.0

import "./pinchUpdate.js" as Up

Rectangle {
    id: greenRect
    width: Math.min(parent.width, parent.height) / 2;
    height: width;
    anchors.centerIn: parent;
    color: "green";

    signal angleChanged(var angle);
    signal scaleChanged(var scale);

    PinchArea {
        id: pinchArea;
        anchors.fill: parent;
        pinch.minimumRotation: -360;
        pinch.maximumRotation: 360;
        pinch.minimumScale: 0.5;
        pinch.maximumScale: 2;
        onPinchStarted: print("PinchStarted\n");
        onPinchUpdated: {
            Up.update(pinch.angle, pinch.scale);
            parent.angleChanged(pinch.angle);
            parent.scaleChanged(pinch.scale);
        }
        onPinchFinished: print("PinchFinished\n")
    }
}
