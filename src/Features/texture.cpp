// #includes <iostream>

// #includes "texture.hpp"
// #includes "stb_image.h"

// Texture::Texture(const std::string &path, const char *type)
// // {
//     //The glGenTextures function first takes as input how many textures we want to generate
//     glGenTextures(1, &texture);
//     glBindTexture(GL_TEXTURE_2D, texture);

//     // set the texture wrapping/filtering options (on the currently bound texture object)
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//     /*
//   load and generate the texture
//   NOTE: Last argument to force the number of channels, **0 to not force**
//   */

//     unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
//     if (data)
//     {
//         //target texture, minmap level 0 for base level,
//         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//         glGenerateMipmap(GL_TEXTURE_2D);
//     }
//     else
//     {
//         std::cout << "Failed to load texture" << std::endl;
//     }
//     stbi_image_free(data);
// }