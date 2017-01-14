import QtQuick 2.0

Rectangle {
    width: 915
    height: 768

    color: "black"

    Player {
        id: player
        x: 360
        y: 650
        width: 40
        height: 40
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
        x: 75
        y: 75
        width: player.width
        height: 250
    }

    Wall {
        x: 185
        y: 75
        width: player.width
        height: 250
    }

    Wall {
        x: 295
        y: 75
        width: player.width
        height: 200
    }

    Wall {
        x: 425
        y: 75
        width: player.width
        height: 200
    }

    Wall {
        x: 535
        y: 75
        width: player.width
        height: 250
    }

    Wall {
        x: 645
        y: 75
        width: player.width
        height: 250
    }

    Wall {
        x: 75
        y: 490
        width: player.width
        height: 200
    }

    Wall {
        x: 185
        y: 490
        width: player.width
        height: 200
    }

    Wall {
        x: 535
        y: 490
        width: player.width
        height: 200
    }

    Wall {
        x: 645
        y: 490
        width: player.width
        height: 200
    }

    Wall {
        y: 390
        anchors.left: left_wall.right
        width: 60
        height: player.height
    }

    Wall {
        x: 140
        y: 390

        width: 90
        height: player.height
    }

    Wall {
        id: top_base_wall
        x: 335
        anchors.bottom: left_base_wall.top
        width: 90
        height: player.height / 2.5
        anchors.bottomMargin: 1
    }

    Wall {
        id: left_base_wall
        x: 335
        anchors.bottom: bot_wall.top
        width: player.width / 2.5
        height: player.height
    }

    Wall {
        id: right_base_wall
        x: 409
        anchors.bottom: bot_wall.top
        width: player.width / 2.5
        height: player.height
    }

    Wall {
        x: 535
        y: 390
        width: 80
        height: player.height
    }

    Wall {
        x: 685
        y: 390
        width: 60
        height: player.height
    }

    Wall {
        x: 295
        y: 345
        width: 40
        height: player.height
    }

    Wall {
        x: 425
        y: 345
        width: 40
        height: player.height
    }

    Wall {
        x: 295
        y: 455
        width: 40
        height: 176
    }

    Wall {
        x: 425
        y: 455
        width: 40
        height: 176
    }

    Wall {
        x: 335
        y: 475
        width: 90
        height: player.height
    }

    Wall {
        anchors.top: top_wall.bottom
        anchors.right: right_wall.left
        width: player.width / 4
        height: parent.height - (top_wall.height * 2)
        anchors.rightMargin: 150
    }

    Wall {
        x: 335
        y: 215
        width: 90
        height: player.height
    }
}
