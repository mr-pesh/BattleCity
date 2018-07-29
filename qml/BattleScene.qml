import QtQuick 2.0
import BattleSceneObjects 1.0

Rectangle {
    width: 915
    height: 768
    color: "black"

    Player {
        id: player
        x: 360
        y: 540
        width: 40
        height: 40
        direction: Direction.South
        onPlayerIsDead: {
            game_over_screen.visible = true;
        }
    }

    Base {
        anchors.left: left_base_wall.right
        anchors.bottom: bot_wall.top
        anchors.leftMargin: 4
        width: height
        height: left_base_wall.height
    }

    property int wallSpaceFactor: (player.width + ((player.width / 4) * 3))

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
        id: top_left_aligned_wall
        anchors.left: left_wall.right
        anchors.leftMargin: (wallSpaceFactor - (player.width / 8))
        anchors.top: top_wall.bottom
        anchors.topMargin: (wallSpaceFactor - (player.height / 8))
        width: player.width
        height: 250
    }

    Wall {
        id: second_top_left_aligned_wall
        anchors.left: top_left_aligned_wall.right
        anchors.leftMargin: wallSpaceFactor
        anchors.top: top_wall.bottom
        width: player.width
        height: 268
    }

    Wall {
        anchors.right: top_spawn_wall.left
        y: 75
        width: player.width
        height: 200
    }

    Wall {
        anchors.left: top_spawn_wall.right
        y: 75
        width: player.width
        height: 200
    }

    Wall {
        id: second_top_right_aligned_wall
        anchors.right: top_right_aligned_wall.left
        anchors.rightMargin: wallSpaceFactor
        anchors.top: top_wall.bottom
        width: player.width
        height: 268
    }

    Wall {
        id: top_right_aligned_wall
        anchors.right: barrier_wall.left
        anchors.rightMargin: (wallSpaceFactor - (player.width / 8))
        anchors.top: top_wall.bottom
        anchors.topMargin: (wallSpaceFactor - (player.height / 8))
        width: player.width
        height: 250
    }

    Wall {
        id: bot_left_aligned_wall
        anchors.left: left_wall.right
        anchors.leftMargin: (wallSpaceFactor - (player.width / 8))
        anchors.bottom: bot_wall.top
        anchors.bottomMargin: (wallSpaceFactor - (player.height / 8))
        width: player.width
        height: 200
    }

    Wall {
        id: second_bot_left_aligned_wall
        anchors.left: bot_left_aligned_wall.right
        anchors.leftMargin: wallSpaceFactor
        anchors.bottom: bot_wall.top
        width: player.width
        height: 268
    }

    Wall {
        id: second_bot_right_aligned_wall
        anchors.right: bot_right_aligned_wall.left
        anchors.rightMargin: wallSpaceFactor
        anchors.bottom: bot_wall.top
        width: player.width
        height: 268
    }

    Wall {
        id: bot_right_aligned_wall
        anchors.right: barrier_wall.left
        anchors.rightMargin: (wallSpaceFactor - (player.width / 8))
        anchors.bottom: bot_wall.top
        anchors.bottomMargin: (wallSpaceFactor - (player.height / 8))
        width: player.width
        height: 200
    }

    Wall {
        id: center_left_aligned_wall
        y: 390
        anchors.left: left_wall.right
        width: 60
        height: player.height
    }

    Wall {
        anchors.right: second_top_left_aligned_wall.right
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
    }

    Wall {
        id: left_base_wall
        x: 335
        anchors.bottom: bot_wall.top
        width: player.width / 2.5
        height: player.height + player.height / 4
    }

    Wall {
        id: right_base_wall
        x: 409
        anchors.bottom: bot_wall.top
        width: player.width / 2.5
        height: player.height + player.height / 4
    }

    Wall {
        anchors.left: second_top_right_aligned_wall.left
        y: 390
        width: 80
        height: player.height
    }

    Wall {
        id: center_right_aligned_wall
        anchors.right: barrier_wall.left
        y: 390
        width: 60
        height: player.height
    }

    Wall {
        anchors.right: top_spawn_wall.left
        y: 345
        width: player.width
        height: 40
    }

    Wall {
        anchors.left: top_spawn_wall.right
        y: 345
        width: player.width
        height: 40
    }

    Wall {
        id: left_bottom_spawn_wall
        anchors.right: bottom_spawn_wall.left
        y: 455
        width: player.width
        height: 176
    }

    Wall {
        id: right_bottom_spawn_wall
        anchors.left: bottom_spawn_wall.right
        y: 455
        width: player.width
        height: 176
    }

    Wall {
        id: bottom_spawn_wall
        x: 335
        y: 475
        width: 90
        height: player.height
    }

    Wall {
        id: barrier_wall
        anchors.top: top_wall.bottom
        anchors.right: right_wall.left
        width: player.width / 4
        height: parent.height - (top_wall.height * 2)
        anchors.rightMargin: parent.width / 6
    }

    Wall {
        id: top_spawn_wall
        x: 335
        y: 215
        width: 90
        height: player.height
    }

    GameOverScreen {
        id: game_over_screen
        width: 300
        height: 300
        visible: false
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: left_wall.right
        anchors.leftMargin: ((barrier_wall.x - left_wall.x) / 2) - width / 2
    }

    StatusPanel {
        objectName: "statusPanel"
        livesCount: player.lives
        visible: true
        width: right_wall.x - (barrier_wall.x + barrier_wall.width)
        height: bot_wall.y - (top_wall.y + top_wall.height)
        anchors.top: top_wall.bottom
        anchors.left: barrier_wall.right
    }
}
