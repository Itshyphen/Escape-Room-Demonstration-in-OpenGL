#include <glad/glad.h>
#include<string>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include"renderer.hpp"

class Texture
{
private:
    
    unsigned char* data;
    int width, height, nrChannels;

public:
   unsigned int ID;

    Texture(std::string path);
    ~Texture();

    void Bind(unsigned int slot = 0) const;
    void Unbind() const;

    inline int getWidth() const { return width; }
    inline int getHeight() const { return height; }

    static GLuint loadCubemap(vector<std::string> faces);
};

Texture::Texture(std::string path)
{
        //The glGenTextures function first takes as input how many textures we want to generate

    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID) ; // Bind without slot selection

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//    stbi_set_flip_vertically_on_load(1);
    int width, height, nrChannels;
    const char* ccpath = path.c_str();
    data = stbi_load(ccpath, &width, &height, &nrChannels, 4);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    Unbind();

    if (data)
        stbi_image_free(data);
}

Texture::~Texture()
{
    //  glDeleteTextures(1, &ID);
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

GLuint Texture::loadCubemap(vector<std::string> faces)
	{
        unsigned int textureID;
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
//        stbi_set_flip_vertically_on_load(1);
        int width, height, nrChannels;
        for (unsigned int i = 0; i < faces.size(); i++)
        {
            unsigned char *data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
            if (data)
            {
                glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
                             0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data
                );
                stbi_image_free(data);
            }
            else
            {
                std::cout << "Cubemap tex failed to load at path: " << faces[i] << std::endl;
                stbi_image_free(data);
            }
        }
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

        return textureID;
	}
