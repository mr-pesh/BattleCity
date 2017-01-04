import QtQuick 2.7

Rectangle {

    width: 360
    height: 360
    property alias item1: item1

    Item {
        id: item1
        x: 43
        y: 47
        width: 48
        height: 247
    }
}
