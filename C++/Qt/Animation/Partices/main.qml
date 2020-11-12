import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Particles 2.12

Window {
    id: mainWindow
    visible: true
    visibility: Window.Maximized

    Rectangle {
        id: mainRect
        anchors.fill: parent


        ParticleSystem {
            anchors.fill: parent

            ItemParticle {
                id: greenRect
                property var newColor: "green"
                delegate: Rectangle {id: gr; width: 5; height: 5; color: greenRect.newColor}
            }


            Emitter {
                id: em
                width: parent.width
                height: parent.height
                anchors.bottom: parent.bottom
                lifeSpan: 2000
                sizeVariation: 2000
                emitRate: 50
                velocity:
                    AngleDirection {
                        angle: 90
                        angleVariation: 10
                        magnitude: 100
                    }
            }
        }
    }
}
