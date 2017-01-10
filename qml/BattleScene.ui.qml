import QtQuick 2.7

Rectangle {
    width: 1024
    height: 768

    color: "black"

    Player {
        id: player
        x: 500
        y: 500
        width: 50
        height: 50
    }

    Rectangle {
        id: left_wall
        anchors.top: parent.top
        anchors.left: parent.left
        width: player.width / 4
        height: parent.height
        color: "#3f2525"
    }

    Rectangle {
        id: bot_wall
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        width: parent.width
        height: player.height / 4
        color: "#3f2525"
    }

    Rectangle {
        id: right_wall
        anchors.right: parent.right
        anchors.top: parent.top
        width: player.width / 4
        height: parent.height
        color: "#3f2525"
    }

    Rectangle {
        id: top_wall
        anchors.top: parent.top
        anchors.right: parent.right
        width: parent.width
        height: player.height / 4
        color: "#3f2525"
    }

    Rectangle {
        //id: right_wall
        x: 730
        y: 161
        width: 95
        height: 111
        color: "#ecc58a"
    }
}
