import QtQuick 2.7

Rectangle
{
    Image {
        id: img
        visible: false
        sourceSize.width: 256
        sourceSize.height: 256
        source: "qrc:/res/img/brick_sml_red1.png"
    }
    ShaderEffect {
        anchors.fill: parent
        // Qt maps Image to sampler2D in shader program
        property variant texture: img
        // Properties for correct transform of texture coordinates
        property double xFct: 1 / img.sourceSize.width
        property double yFct: 1 / img.sourceSize.height

        vertexShader: "
            // Transofrm values for x and y texture coordinates
            uniform highp float xFct;
            uniform highp float yFct;
            // Combined transformation matrix (from root item
            // to this ShaderEffect) and an orthogonal projection
            uniform highp mat4 qt_Matrix;
            // Vertex position
            attribute highp vec4 qt_Vertex;
            // Vector to store texture coordinates for a fragment shader
            varying highp vec2 texCoord;

            void main() {
                gl_Position = qt_Matrix * qt_Vertex;
                texCoord = vec2(qt_Vertex.x * xFct, qt_Vertex.y * yFct);
            }"
        fragmentShader: "
            varying highp vec2 texCoord;
            uniform sampler2D texture;
            void main() {
                lowp float x = texCoord.x;
                lowp float y = texCoord.y;
                while (x > 1.0)
                    x = x - 1.0;
                while (y > 1.0)
                    y = y - 1.0;
                gl_FragColor = texture2D(texture, vec2(x, y));
            }"
        blending: false
    }
}
