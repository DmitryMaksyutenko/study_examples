import QtQuick 2.12
import QtQuick.Controls 2.12
import QtPositioning 5.12


ApplicationWindow {
    width: 640
    height: 480
    visible: true

    header: Text {
        id: headerText
        anchors.centerIn: parent
        text: "Latitude - if minus then south.<br>Longitude - if minus then west."
    }

    Text {
        id: positionText
        anchors.centerIn: parent

        /* switch permissions on.
          Include default permissions for Qt modules.
          in AndroidManifest.xml
        */
        PositionSource {
            id: src
            updateInterval: 1000
            active: true

            onPositionChanged: {
                positionText.text =
                        "Latitude: " + src.position.coordinate.latitude +
                        "<br>Longtitude: " + src.position.coordinate.longitude
            }
        }
    }
}
