import QtQuick 2.12
import QtQuick.Controls 2.12

import "./QmlSource" as QmlSource

ApplicationWindow {
    width: 640;
    height: 480;
    visible: true;

    header: QmlSource.Information {
        id: info;
        rectAngle: "0";
        rectScale: green.scale;
    }

    QmlSource.GreenRect {
        id: green;
        onAngleChanged: info.rectAngle = Number(angle).toFixed(3);
        onScaleChanged: info.rectScale = Number(scale).toFixed(3);
    }
}
