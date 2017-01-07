import QtQuick 2.0
import BattleSceneObjects 1.0

Item {
    Unit {
        id: player
        lives: 3
        direction: 0
        objectName: "player"

        width: 80
        height: 80

        Image {
            id: img
            anchors.fill: parent
            source: "qrc:/textures/battle.png"
            transform: Rotation {
                origin.x: player.width % 2 == 0 ? player.width / 2 : player.width / 2 + 1
                origin.y: player.height % 2 == 0 ? player.height / 2 : player.height / 2 + 1
                angle: player.direction
            }
        }
    }
}
