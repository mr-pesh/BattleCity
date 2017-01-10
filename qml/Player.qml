import QtQuick 2.0
import BattleSceneObjects 1.0

Unit {
    id: player
    lives: 3
    direction: 0
    moveSpeed: 8
    objectName: "player"


    Image {
        id: img
        anchors.fill: parent
        source: "qrc:/res/battle.png"
        rotation: player.direction
    }
}
