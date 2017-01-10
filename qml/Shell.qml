import QtQuick 2.0
import BattleSceneObjects 1.0

Shell {
    Rectangle {
        color: "#ecc58a"
        radius: width / 2
        rotation: parent.direction
        anchors.fill: parent
    }
}
