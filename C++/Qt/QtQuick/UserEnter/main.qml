import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: mainWindow;
    width: 640;
    height: 480;
    visible: true;

    RedRect{
        onMySignal: blueRect.text = "X: " + x + " Y: " + y;
    }
    GreenRect{
        onMySignal: blueRect.text = "X: " + (x + parent.width / 2) +
                                    " Y: " + y;
    }
    BlueRect{
        id: blueRect;
        onMySignal: blueRect.text = "X: " + x +
                                    " Y: " + (y + parent.height / 2);
    }
    YellowRect {
        onMySignal: blueRect.text = "X: " + (x + parent.width / 2) +
                                    " Y: " + (y + parent.height / 2);
    }
}
