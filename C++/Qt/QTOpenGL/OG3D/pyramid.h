#ifndef PYRAMID_H
#define PYRAMID_H

#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class Pyramid : public QOpenGLWidget
{
private:
    GLuint m_nPyramid;
    GLfloat m_xRotate;
    GLfloat m_yRotate;
    QPoint m_ptPosition;

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent * e) override;
    GLuint createPyramid(GLfloat fSize = 1.0f);

public:
    Pyramid(QWidget *obj = nullptr);
};

#endif // PYRAMID_H
