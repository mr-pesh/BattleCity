import QtQuick 2.0

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

    Wall {
        id: left_wall
        anchors.top: parent.top
        anchors.left: parent.left
        width: player.width / 4
        height: parent.height
    }

    Wall {
        id: bot_wall
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        width: parent.width
        height: player.height / 4
    }

    Wall {
        id: right_wall
        anchors.right: parent.right
        anchors.top: parent.top
        width: player.width / 4
        height: parent.height
    }

    Wall {
        id: top_wall
        anchors.top: parent.top
        anchors.right: parent.right
        width: parent.width
        height: player.height / 4
    }

    Wall {
        width: 200; height: 100
        x: 730
        y: 161
    }
}
