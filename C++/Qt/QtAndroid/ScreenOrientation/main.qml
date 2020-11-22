import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    id: mainWindow
    width: 480
    height: 640
    visible: true

    property var portraitText: "Portrait screen."
    property var landscapeText: "Landscape screen."

    property int orientation: Screen.primaryOrientation

    Text {
        id: mainText
        anchors.centerIn: parent
        text: portraitText
    }

    onOrientationChanged: {
        if (orientation === Qt.PortraitOrientation) {
            mainText.text = portraitText
        }
        if (orientation === Qt.LandscapeOrientation) {
            mainText.text = landscapeText
        }
    }

}
