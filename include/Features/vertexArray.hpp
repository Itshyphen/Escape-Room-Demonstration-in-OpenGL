#include "vertexBuffer.hpp"

class VertexArray
{
    private:
        unsigned int ID;

    public:
        VertexArray();
        ~VertexArray();

        void AddBuffer(GLuint index,GLint size,GLenum type,GLboolean normalized,GLsizei stride,const GLvoid * pointer);
        void Bind() const;
        void Unbind() const;
};