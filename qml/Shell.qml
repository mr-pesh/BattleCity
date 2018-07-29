import QtQuick 2.7
import BattleSceneObjects 1.0

Shell {
    id: shell
    moving: true

    Rectangle {
        color: "#ecc58a"
        radius: width / 2
        rotation: shell.direction
        anchors.fill: parent
    }
}
