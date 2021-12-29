#include "star.h"
#include "math.h"
#include <GL/glew.h>
class Foo
{
public:
    static int __st_init;
private:
    static int static_init(){
                int M_IN_DEGREE = 370;
int N_IN_DEGREE = 100;
int nCount = 1;
float stVertexArray[2*360];
stVertexArray[0] = 0.0;
stVertexArray[1] = 0.0;
for( int nR =N_IN_DEGREE; nR < M_IN_DEGREE; nR++ )
{
    float fX = sin((float)nR * 3 ) ;
    float fY = cos((float)nR * 3 );
    stVertexArray[nCount*2] = fX;
    stVertexArray[nCount*2 + 1] = fY;
    nCount++;
}
nCount = 1;
        return 42;
    }
};
int Foo::__st_init = Foo::static_init();




void Star::Initialize(){
    const GLfloat kVertices[] = {

     stVertexArray[nCount*2], stVertexArray[nCount*2 + 1], 0.0f, 1.0f,
     stVertexArray[(nCount+1)*2 + 1], stVertexArray[nCount*2 + 1], 0.0f, 1.0f,
     stVertexArray[(nCount+1)*2 + 1], stVertexArray[nCount*2 + 1], 0.0f, 1.0f,
     stVertexArray[(nCount+1)*2 + 1], stVertexArray[nCount*2 + 1], 0.0f, 1.0f
    };

    const GLfloat kColors[] = {
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,

        1.0f, 0.0f, 1.0f, 1.0f,
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

Star::~Star(){
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glDeleteBuffers(1, &color_buffer_);
    glDeleteBuffers(1, &vertex_buffer_);

    glBindVertexArray(0);
    glDeleteVertexArrays(1, &vao_);
}

void Star::Draw(const Program &program){

    glUseProgram(program);
    glBindVertexArray(vao_);

glEnableClientState( GL_VERTEX_ARRAY );
glVertexPointer( 2, GL_FLOAT, 0, stVertexArray );
glDrawArrays( GL_LINE_LOOP, 0, nCount );


    glBindVertexArray(0);
    glUseProgram(0);


}
