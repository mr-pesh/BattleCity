import QtQuick 2.7
import QtMultimedia 5.5
import BattleSceneObjects 1.0
import QtGraphicalEffects 1.0

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
    // The glow effect that appears on player spawn
    Glow
    {
        id: respawnGlow
        anchors.fill: img
        radius: 10
        samples: 21
        color: "white"
        source: img
        rotation: player.direction
        opacity: 0

        // Applies pulse animation effect
        Behavior on opacity {
          NumberAnimation {
            duration: 250; easing: Easing.InOutCubic
          }
        }
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
                respawnGlow.opacity = 0;
            }
            else {
                respawnGlow.opacity = respawnGlow.opacity ? 0 : 1;
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
            respawnGlow.opacity = 1;
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
