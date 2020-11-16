import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import BackEndClass 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    BackEndClass {
        id: backend
    }

    TextField {
        id: mainTextField
        text: backend.user_name
        anchors.centerIn: parent

        onTextChanged: {
            backend.user_name = text
            backend.slot_name_changed()
        }
    }
}
