
#include "vertexArray.hpp"

//LINKING VERTEX ATTRIBUTES

//tell OpenGL how it should interpret the vertex data
//(per vertex attribute) using glVertexAttribPointer:

//Core OpenGL requires that we use a VAO so it knows what to do
//with our vertex inputs. If we fail to bind a VAO, OpenGL
//will most likely refuse to draw anything.
VertexArray::VertexArray()
{
    glGenVertexArrays(1, &ID) ;
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &ID);
}

void VertexArray::AddBuffer(GLuint index,GLint size,GLenum type,GLboolean normalized, GLsizei stride, const GLvoid * pointer)
{
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    glEnableVertexAttribArray(index);
}


//we want to draw an object, we simply bind the VAO with the
//preferred settings before drawing the object and that is it.
void VertexArray::Bind() const
{
    glBindVertexArray(ID);
}

void VertexArray::Unbind() const
{
    glBindVertexArray(0);
};
