import QtQuick 2.7
import BattleSceneObjects 1.0

BattleSceneImpl {

    readonly property var configuration: JSON.parse(configFile)

    Player {
        id: player
        x: 360
        y: 540
        width: 40
        height: 40
        direction: Direction.South
        onPlayerIsDead: {
            game_over_screen.visible = true;
        }
    }

    Base {
        x: configuration.base.x
        y: configuration.base.y
        width: configuration.base.width
        height: configuration.base.height
    }

    Repeater {
      model: configuration.walls
      delegate: Wall {
          objectName: modelData.name
          x: modelData.x
          y: modelData.y
          width: modelData.width
          height: modelData.height
      }
    }

    GameOverScreen {
        id: game_over_screen
        width: configuration.gameOverPanel.width
        height: configuration.gameOverPanel.height
        visible: false
        anchors.verticalCenter: parent.verticalCenter
        x: configuration.gameOverPanel.x
        //y: configuration.gameOverPanel.y
    }

    StatusPanel {
        objectName: configuration.statusPanel.name
        x: configuration.statusPanel.x
        y: configuration.statusPanel.y
        width: configuration.statusPanel.width
        height: configuration.statusPanel.height
        livesCount: player.lives
    }
}
