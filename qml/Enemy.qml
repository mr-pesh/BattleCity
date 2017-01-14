import QtQuick 2.0
import BattleSceneObjects 1.0

Unit {
    id: enemy
    lives: 1
    moving: false

    Image {
        id: img
        visible: false
        anchors.fill: parent
        source: "qrc:/res/com.badlogic.androidgames.tank1990.png"
    }
    ShaderEffect {
        anchors.fill: parent
        // Qt maps Image to sampler2D in shader program
        property variant srcImg: img

        vertexShader: "
            uniform highp mat4 qt_Matrix;
            attribute highp vec4 qt_Vertex;
            attribute highp vec2 qt_MultiTexCoord0;
            varying highp vec2 coord;

            void main() {
                coord = qt_MultiTexCoord0;
                gl_Position = qt_Matrix * qt_Vertex;
            }"
        fragmentShader: "
            varying highp vec2 coord;
            uniform sampler2D srcImg;
            uniform lowp float qt_Opacity;
            void main() {
                lowp vec4 tex = texture2D(srcImg, coord);
                gl_FragColor = vec4(vec3(dot(tex.rgb, vec3(0.344, 0.5, 0.156))), tex.a) * qt_Opacity;
            }"
        rotation: enemy.direction
    }
}
