#ifndef STARCONTUR_H
#define STARCONTUR_H

#include <GL/glew.h>

#include "program.h"

class StarContur{
 public:
    void Initialize();
    ~StarContur();
    void Draw(const Program & program);
 private:
    GLuint vao_;
    GLuint vertex_buffer_;
    GLuint color_buffer_;
};

#endif // STARCONTUR_H
