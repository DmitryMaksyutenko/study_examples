import QtQuick 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    id: mainWindow
    width: 640
    height: 480
    visible: true

    property real startX;
    property real startY;

    Canvas {
        id: drawingCanvas
        anchors.fill: parent

        onPaint: {
            var ctx = getContext("2d")
            ctx.fillStyle = "red"

            ctx.lineWidth = 5;
            ctx.strokeStyle = "red"
            ctx.beginPath()
            ctx.ellipse(mainWindow.startX, mainWindow.startY, 10, 10).fill()
            ctx.stroke()
        }

        MultiPointTouchArea {
            id: touchArea
            anchors.fill: parent
            minimumTouchPoints: 1
            maximumTouchPoints: 1
            touchPoints: TouchPoint {

                function setStartPositions() {
                    mainWindow.startX = x
                    mainWindow.startY = y
                }

                function paintOnCanvas() {
                    setStartPositions()
                    drawingCanvas.requestPaint()
                }

                onXChanged: {
                    paintOnCanvas()
                }

                onYChanged: {
                    paintOnCanvas()
                }
            }
        }
    }

}
