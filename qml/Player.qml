import QtQuick 2.0
import BattleSceneObjects 1.0
import QtGraphicalEffects 1.0

Unit {
    id: player
    lives: 3
    moving: false
    direction: 0
    moveSpeed: 6
    objectName: "player"


    Image {
        id: img
        anchors.fill: parent
        source: "qrc:/res/battle.png"
        rotation: player.direction
    }

    Glow {
        property double opacityFactor: 0

        id: respawnGlow
        anchors.fill: img
        opacity: opacityFactor * 0.1
        radius: 10
        samples: 21
        color: "white"
        source: img
        rotation: player.direction

        Behavior on opacityFactor { NumberAnimation {} }
    }

    Timer {
        property int ticks: 0

        id: glowTimer
        repeat: true
        running: true
        interval: 700
        triggeredOnStart: true

        onTriggered: {
            if (ticks > 6)
                glowTimer.stop();

            respawnGlow.opacityFactor = respawnGlow.opacityFactor > 0 ? 0 : 10
            ticks++;
        }
    }

    onLivesCountChanged: {
        glowTimer.start();
    }
}
