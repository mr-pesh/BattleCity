import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    id: panel
    // Should be binded to player.lives property
    property int livesCount
    // Should be set by a scene
    property int enemiesLeft

    Column {

        anchors.fill: parent

        Text {
            anchors.top: parent.top
            anchors.topMargin: parent.height / 8
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Lives x" + panel.livesCount
            color: "#fbe323"
            font.pixelSize: 22
        }

        Grid {
            anchors.centerIn: parent

            PanelEnemyImage { number:  0; spawnValue: panel.enemiesLeft }
            PanelEnemyImage { number:  1; spawnValue: panel.enemiesLeft }
            PanelEnemyImage { number:  2; spawnValue: panel.enemiesLeft }
            PanelEnemyImage { number:  3; spawnValue: panel.enemiesLeft }
            PanelEnemyImage { number:  4; spawnValue: panel.enemiesLeft }
            PanelEnemyImage { number:  5; spawnValue: panel.enemiesLeft }
            PanelEnemyImage { number:  6; spawnValue: panel.enemiesLeft }
            PanelEnemyImage { number:  7; spawnValue: panel.enemiesLeft }
            PanelEnemyImage { number:  8; spawnValue: panel.enemiesLeft }
            PanelEnemyImage { number:  9; spawnValue: panel.enemiesLeft }
            PanelEnemyImage { number: 10; spawnValue: panel.enemiesLeft }
            PanelEnemyImage { number: 11; spawnValue: panel.enemiesLeft }
            PanelEnemyImage { number: 12; spawnValue: panel.enemiesLeft }
            PanelEnemyImage { number: 13; spawnValue: panel.enemiesLeft }
            PanelEnemyImage { number: 14; spawnValue: panel.enemiesLeft }
            PanelEnemyImage { number: 15; spawnValue: panel.enemiesLeft }
            PanelEnemyImage { number: 16; spawnValue: panel.enemiesLeft }
            PanelEnemyImage { number: 17; spawnValue: panel.enemiesLeft }
            PanelEnemyImage { number: 18; spawnValue: panel.enemiesLeft }
            PanelEnemyImage { number: 19; spawnValue: panel.enemiesLeft }
        }
    }
}
