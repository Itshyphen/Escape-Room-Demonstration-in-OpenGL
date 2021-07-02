#include<glad/glad.h>


class VertexBuffer{

    private:
        unsigned int ID;


    public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void Bind();
    void Unbind();
};