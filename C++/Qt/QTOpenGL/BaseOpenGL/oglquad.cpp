#include "oglquad.h"

OGLQuad::OGLQuad(QWidget *obj) : QOpenGLWidget(obj)
{}

void OGLQuad::initializeGL()
{
    QOpenGLFunctions *pFunc = QOpenGLContext::currentContext()->functions();
    pFunc->glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void OGLQuad::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLint)w, (GLint)h);
    glOrtho(0, 100, 100, 0 , -1, 1);
}

void OGLQuad::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);

    glColor3f(1, 0, 0);
    glVertex2f(0, 100);

    glColor3f(0, 1, 0);
    glVertex2f(100, 100);

    glColor3f(0, 0, 1);
    glVertex2f(100, 0);

    glColor3f(1, 1, 1);
    glVertex2f(0, 0);

    glEnd();
}
