#include<glad/glad.h>


class IndexBuffer{

    private:
        unsigned int ID;
        unsigned int count;


    public:
    IndexBuffer(const void* data, unsigned int count);
    ~IndexBuffer();

    void Bind() const;
    void Unbind() const;

    inline unsigned int getCount() const {
        return count;
    }
};