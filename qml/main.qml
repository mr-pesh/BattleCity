import QtQuick 2.0
import QtMultimedia 5.5

BattleScene {
    visible: true
    width: 920
    height: 768
    objectName: "scene"

    Audio {
        id: introMusic
        objectName: "introSound"
        autoPlay: true
        loops: 1
        source: "qrc:/res/audio/battle_city_stage_intro.mp3"
    }

}
