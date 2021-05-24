#include"vertexBuffer.hpp"
//send verteces as input to the first process of the graphics pipeline: t
//the vertex shader and we manage this memory by vertexbuffer and it has an unique ID
//using the glGenBuffers
VertexBuffer::VertexBuffer(const void *data, unsigned int size)
{
    glGenBuffers(1, &ID);

    //We can bind the newly created buffer to the GL_ARRAY_BUFFER target with
    //the glBindBuffer function:
    glBindBuffer(GL_ARRAY_BUFFER, ID);

    // we can make a call to the glBufferData function that copies the
    //previously defined vertex data into the buffer's memory:
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &ID);
}

//We can bind the newly created buffer to the GL_ARRAY_BUFFER target with
//the glBindBuffer function:
void VertexBuffer::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VertexBuffer::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}