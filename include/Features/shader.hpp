#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h> // include glad to get all the required OpenGL headers
  
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <arithmetic.hpp>
  

class Shader
{
public:
  
    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);
    // use/activate the shader
    void use();
    // utility uniform functions
    void Bind() const;
    void Unbind() const;

    //set uniforms
    
    void setUniform4f(const std::string& name, float f0, float f1, float f2, float f3);
    // void setUniformMatrix4fv(const std::string& name ,GLsizei count,const GLfloat * value,GLboolean transpose);

    void setBool(const std::string &name, bool value) const;  
    void setInt(const std::string &name, int value) const;   
    void setFloat(const std::string &name, float value) const;
    void setMat4(const std::string &name, const glm::mat4 &mat) const;
    // void setMat3(const std::string &name, const glm::mat3 &mat) const;
    // void setMat2(const std::string &name, const glm::mat2 &mat) const;
    void setVec2(const std::string &name, const glm::vec2 &value) const;
    void setVec2(const std::string &name, float x, float y) const;
    void setVec3(const std::string &name, const glm::vec3 &value) const;
    void setVec3(const std::string &name, float x, float y, float z) const;
      void setMat2(const std::string &name, const glm::mat2 &mat) const;
    void setMat3(const std::string &name, const glm::mat3 &mat) const;

    //Using the VecMat Library
    void setMat4(const std::string &name, const VecMat::mat4 mat) const;
    void setVec2(const std::string &name, const VecMat::vec2 value) const;
    void setVec3(const std::string &name, const VecMat::vec3 value) const;
    void setMat3(const std::string &name, const VecMat::mat3 mat) const;
  


    

    private:
    // the program ID
    unsigned int ID;
    int GetUniformLocation(const std::string& name); 
    // utility function for checking shader compilation/linking errors.
    void checkCompileErrors(unsigned int shader, std::string type);
};
  
#endif