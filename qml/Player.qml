import QtQuick 2.0
import BattleSceneObjects 1.0
import QtGraphicalEffects 1.0
import QtMultimedia 5.5

Unit {
    lives: 3
    id: player
    objectName: "player"   

    // Emit when the player lives count falls to zero
    signal playerIsDead

    Image {
        id: img
        anchors.fill: parent
        source: "qrc:/res/img/battle.png"
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
        running: false
        interval: 700

        onTriggered: {
            if (ticks > 6) {
                ticks = 0;
                glowTimer.stop();
                respawnGlow.opacityFactor = 0;
            }
            else {
                respawnGlow.opacityFactor = respawnGlow.opacityFactor > 0 ? 0 : 10
                ticks++;
            }
        }
    }

    SoundEffect {
        id: fireSound
        source: "qrc:/res/audio/battle_city_shot.wav"
    }

    SoundEffect {
        id: explSound
        source: "qrc:/res/audio/battle_city_explode.wav"
    }

    onLivesCountChanged: {
        explSound.play();
        if (value > 0) {
            respawnGlow.opacityFactor = 10;
            glowTimer.start();
        } else {
            visible = false;
            moving = false;
            playerIsDead();
        }
    }
    onFired: {
        fireSound.play();
    }
}
