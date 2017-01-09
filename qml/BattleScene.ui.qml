import QtQuick 2.7

Rectangle {
    width: 1024
    height: 768

    color: "black"

    Player {
        x: 500
        y: 500
        width: 70
        height: 70
    }

    Rectangle {
        id: rectangle
        x: 313
        y: 145
        width: 139
        height: 109
        color: "#3f2525"
    }

    Rectangle {
        id: rectangle1
        x: 730
        y: 161
        width: 95
        height: 111
        color: "#d61212"
    }
}
