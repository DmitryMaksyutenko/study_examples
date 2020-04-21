#ifndef OGLQUAD_H
#define OGLQUAD_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class OGLQuad : public QOpenGLWidget
{
public:
    OGLQuad(QWidget *obj = nullptr);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};

#endif // OGLQUAD_H
