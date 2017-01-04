#include "wallrenderer.h"

WallRenderer::WallRenderer(QObject *parent) : QObject(parent)
{

}

WallRenderer::~WallRenderer()
{
    delete p_shader;
}

void WallRenderer::paint()
{
    if (!p_shader)
    {
        initializeOpenGLFunctions();

        p_shader = new QOpenGLShaderProgram();
        p_shader->addShaderFromSourceCode(QOpenGLShader::Fragment, QStringLiteral(
                                              ""
                                              "void main() {"
                                              "}"));
        p_shader->addShaderFromSourceCode(QOpenGLShader::Vertex, QStringLiteral(
                                              ""
                                              "void main() {"
                                              "}"));
    }
}
