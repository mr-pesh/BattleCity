import QtQuick 2.7

Item {

    id: screen
    objectName: "g_o_screen"

    property alias text: txtItem.text

    Text {
        id: txtItem
        smooth: true
        visible: true
        anchors.centerIn: parent
        text: "Game Over"
        color: "#ecc58a"
        font.pixelSize: 48
    }
}
