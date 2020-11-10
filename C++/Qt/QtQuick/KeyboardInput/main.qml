import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 1024;
    height: 680;
    visible: true
    title: qsTr("Hello World")

    Image {
        id: pikachu;
        focus: true;
        source: "https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcQN-15Oy-jzO65YIgGMzDS2-qJ6wdbKG2TLXw&usqp=CAU";
        scale:0.5;

        Keys.onPressed: {
            switch (event.key) {
                case Qt.Key_Left:
                    goLeft();
                break;
                case Qt.Key_Right:
                    goRight();
                break;
                case Qt.Key_Up:
                    goUp();
                break;
                case Qt.Key_Down:
                    goDown();
                break;
            }
        }

        function goLeft() {
            if (pikachu.x <= parent.x)
                return;
            pikachu.x -= 10;
        }
        function goRight() {
            if (pikachu.x + pikachu.width >= parent.width)
                return;
            pikachu.x += 10;
        }
        function goUp() {
            if (pikachu.y <= parent.y)
                return;
            pikachu.y -= 10;
        }
        function goDown() {
            if (pikachu.y + pikachu.height >= parent.height)
                return;
            pikachu.y += 10;
        }
    }

}
