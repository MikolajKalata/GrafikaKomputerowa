#ifndef CIRCLECONTUR_H
#define CIRCLECONTUR_H

#include <GL/glew.h>

#include "program.h"

class CircleContur{
 public:
    void Initialize();
    ~CircleContur();
    void Draw(const Program & program);
 private:
    GLuint vao_;
    GLuint vertex_buffer_;
    GLuint color_buffer_;
};

#endif // CIRCLECONTUR_H
