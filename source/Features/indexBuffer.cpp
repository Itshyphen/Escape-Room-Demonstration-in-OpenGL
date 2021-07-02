#include"indexBuffer.hpp"

 //An indexBuffer is a buffer, just like a vertex buffer object, that stores
    //indices that OpenGL uses to decide what vertices to draw. This so
    //called indexed drawing is exactly the solution to our problem
IndexBuffer::IndexBuffer(const void *data, unsigned int count)
{
    //copy our index array in a element buffer for OpenGL to use
    glGenBuffers(1, &ID);

    //We can bind the newly created buffer to the GL_ARRAY_BUFFER target with
    //the glBindBuffer function:
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);

    // we can make a call to the glBufferData function that copies the
    //previously defined vertex data into the buffer's memory:
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*sizeof(GLuint), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &ID);
}

void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void IndexBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}