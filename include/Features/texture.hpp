#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include"renderer.hpp"

class Texture
{
private:
    unsigned int ID;
    unsigned char* data;
    int width, height, nrChannels;

public:

    Texture(const char* path);
    ~Texture();

    void Bind(unsigned int slot = 0) const;
    void Unbind() const;

    inline int getWidth() const { return width; }
    inline int getHeight() const { return height; }
};

Texture::Texture(const char* path)
{
    //The glGenTextures function first takes as input how many textures we want to generate
   
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID) ; // Bind without slot selection

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_set_flip_vertically_on_load(1);
    int width, height, nrChannels;
    data = stbi_load(path, &width, &height, &nrChannels, 4);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    Unbind();

    if (data)
        stbi_image_free(data);
}

Texture::~Texture()
{
     glDeleteTextures(1, &ID);
}

void Texture::Bind(unsigned int slot) const
{
     glActiveTexture(GL_TEXTURE0 + slot);
     glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}