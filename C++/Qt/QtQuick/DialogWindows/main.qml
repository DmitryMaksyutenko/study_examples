import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Dialogs 1.2
import QtQuick.Controls 2.12

Window {
    id: mainWindow;
    width: 640;
    height: 480;
    visible: true;
    property alias mainWindow: mainWindow
    title: qsTr("Dialog Windows");

    Repeater {
        id: repeater;
        model: [colorDialog, fontDialog, fileDialog];

        Button {
            y: index * (parent.height / repeater.count);
            height: parent.height / repeater.count;
            width: parent.width;
            text: modelData.title;

            background: Rectangle {
                border.color: "black";
            }

            onClicked: {
                messageDialog.visible = false;
                modelData.visible = true;
            }
        }

    }

    ColorDialog {
        id: colorDialog;
        visible: false;
        modality: Qt.WindowModal;
        title: "Select Color";
        color: "blue";

        onAccepted: {
            messageDialog.informativeText = "Selected color:" + color;
            messageDialog.visible = true;
        }
    }

    FontDialog {
        id: fontDialog;
        visible: false;
        modality: Qt.WindowModal;
        title: "Select Font";

        onAccepted: {
            messageDialog.informativeText = "Selected font:" + font;
            messageDialog.visible = true;
        }
    }

    FileDialog {
        id: fileDialog;
        visible: false;
        modality: Qt.WindowModal;
        title: "Select file";
        nameFilters: ["Doc {*.txt *html}", "All files {*}"];

        onAccepted: {
            messageDialog.informativeText = "Selected file:" + fileUrls;
            messageDialog.visible = true;
        }
    }

    MessageDialog {
        id: messageDialog;
        visible: false;
        modality: Qt.NonModal;
        title: "Message";
    }

}
