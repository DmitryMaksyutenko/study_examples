import QtQuick 2.12
import QtQuick.Controls 2.12
import QtSensors 5.12

ApplicationWindow {
    id: mainWindow
    width: 320
    height: 480
    visible: true
    color: "black"

    Rectangle {
        id: round
        color: "white"
        x: parent.width / 2
        y: parent.height / 2
        width: parent.width / 6
        height: width
        radius: width / 2

        Accelerometer {
            dataRate: 1000
            skipDuplicates: true
            axesOrientationMode: Accelerometer.FixedOrientation
            active: Qt.application.state

            onReadingChanged: {
                round.x -= reading.x
                round.y += reading.y
                var maxX = mainWindow.width - round.width
                var maxY = mainWindow.height - round.height
                round.x = round.x > maxX ? maxX : round.x < 0 ? 0 : round.x
                round.y = round.y > maxY ? maxY : round.y < 0 ? 0 : round.y
            }
        }
    }
}
