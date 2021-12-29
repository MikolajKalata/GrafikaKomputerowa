#include "circleContur.h"
#include <math.h>

#include <GL/glew.h>

void CircleContur::Initialize(){
    
    const GLfloat kVertices[] = {
    
         0.83f,  0.00f, 0.0f, 1.0f,
////
         0.81f,  0.18f, 0.0f, 1.0f,
         0.76f,  0.33f, 0.0f, 1.0f,
         0.69f,  0.47f, 0.0f, 1.0f,
         0.59f,  0.59f, 0.0f, 1.0f,
         0.47f,  0.69f, 0.0f, 1.0f,
         0.33f,  0.76f, 0.0f, 1.0f,
         0.18f,  0.81f, 0.0f, 1.0f,
         0.03f,  0.83f, 0.0f, 1.0f,
////
        -0.18f,  0.81f, 0.0f, 1.0f,
        -0.33f,  0.76f, 0.0f, 1.0f,
        -0.47f,  0.69f, 0.0f, 1.0f,
        -0.59f,  0.59f, 0.0f, 1.0f,
        -0.69f,  0.47f, 0.0f, 1.0f,
        -0.76f,  0.33f, 0.0f, 1.0f,
        -0.81f,  0.18f, 0.0f, 1.0f,
        -0.83f,  0.03f, 0.0f, 1.0f,
////
        -0.81f, -0.18f, 0.0f, 1.0f,
        -0.76f, -0.33f, 0.0f, 1.0f,
        -0.69f, -0.47f, 0.0f, 1.0f,
        -0.59f, -0.59f, 0.0f, 1.0f,
        -0.47f, -0.69f, 0.0f, 1.0f,
        -0.33f, -0.76f, 0.0f, 1.0f,
        -0.18f, -0.81f, 0.0f, 1.0f,
        -0.03f, -0.83f, 0.0f, 1.0f,
////
         0.18f, -0.78f, 0.0f, 1.0f,
         0.33f, -0.73f, 0.0f, 1.0f,
         0.47f, -0.66f, 0.0f, 1.0f,
         0.59f, -0.56f, 0.0f, 1.0f,
         0.69f, -0.44f, 0.0f, 1.0f,
         0.76f, -0.30f, 0.0f, 1.0f,
         0.81f, -0.15f, 0.0f, 1.0f,
         0.83f, -0.00f, 0.0f, 1.0f 
    };

    const GLfloat kColors[] = {
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f
    };
    

    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);

    glGenBuffers(1, &vertex_buffer_);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(kVertices), kVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &color_buffer_);
    glBindBuffer(GL_ARRAY_BUFFER, color_buffer_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(kColors), kColors, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

CircleContur::~CircleContur(){
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glDeleteBuffers(1, &color_buffer_);
    glDeleteBuffers(1, &vertex_buffer_);

    glBindVertexArray(0);
    glDeleteVertexArrays(1, &vao_);
}

void CircleContur::Draw(const Program &program){

    glUseProgram(program);
    glBindVertexArray(vao_);

    glDrawArrays(GL_LINE_LOOP, 0, 33);

    glBindVertexArray(0);
    glUseProgram(0);
}
