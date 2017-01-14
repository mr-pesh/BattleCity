import QtQuick 2.0
import BattleSceneObjects 1.0
import QtGraphicalEffects 1.0

Unit {
    id: player
    objectName: "player"
    direction: 0
    lives: 3

    // Handled by a scene
    signal playerIsDead

    Image {
        id: img
        anchors.fill: parent
        source: "qrc:/res/battle.png"
        rotation: player.direction
    }
    // The glow effect that appears while the player spawns
    Glow
    {
        // Used for smooth glow animation
        property double opacityFactor: 0

        id: respawnGlow
        anchors.fill: img
        opacity: opacityFactor * 0.1
        radius: 10
        samples: 21
        color: "white"
        source: img
        rotation: player.direction

        // Applies pulse animation effect on glow effect
        Behavior on opacityFactor { NumberAnimation {} }
    }

    Timer {
        // A glow pulse counter
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
    onLiveStateChanged: {
        if (!alive)
            playerIsDead();
    }
}
