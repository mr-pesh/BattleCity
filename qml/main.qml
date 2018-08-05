import QtQuick 2.7
import QtMultimedia 5.5

Rectangle {
    objectName: "scene"
    width: 920
    height: 768
    color: "black"

    BattleScene {
      anchors.fill: parent
    }

    Audio {
        id: introMusic
        objectName: "introSound"
        autoPlay: true
        loops: 1
        source: "qrc:/res/audio/battle_city_stage_intro.mp3"
    }
}
