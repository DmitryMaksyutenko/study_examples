#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <QtMath>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class Primitives : public QOpenGLWidget
{
public:
    Primitives(QWidget *obj = nullptr);
    void draw(int xOffset, int yOffset, GLenum type);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};

#endif // PRIMITIVES_H
