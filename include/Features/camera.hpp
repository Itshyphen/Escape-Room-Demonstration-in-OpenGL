//...
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "matrix.hpp"
#include <vector>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

// Default camera values
const float YAW         = -90.0f;
const float PITCH       =  0.0f;
const float SPEED       =  2.5f;
const float SENSITIVITY =  0.1f;
const float ZOOM        =  45.0f;


// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class Camera
{
public:
    // camera Attributes
    // glm::vec3 Position;
    // glm::vec3 Front;
    // glm::vec3 Up;
    // glm::vec3 Right;
    // glm::vec3 WorldUp;

    //Camera Attributes in VecMat
    VecMat::vec3 Position;
    VecMat::vec3 Front;
    VecMat::vec3 Up;
    VecMat::vec3 Right;
    VecMat::vec3 WorldUp;
    VecMat::vec3 propPosition;

    // euler Angles
    float Yaw;
    float Pitch;
    // camera options
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    // constructor with vectors
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);

    //Constructor with VecMat Library
    Camera(VecMat::vec3 position = VecMat::vec3(0.0f, 0.0f, 0.0f), VecMat::vec3 up = VecMat::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);

    // constructor with scalar values
    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

    // returns the view matrix calculated using Euler Angles and the LookAt Matrix
    // glm::mat4 GetViewMatrix();

    VecMat::mat4 GetViewMatrix();

    void setPropPosition(VecMat::vec3 pos);

    // processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
    void ProcessKeyboard(Camera_Movement direction, float deltaTime);

    // processes input received from a mouse input system. Expects the offset value in both the x and y direction.
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);

    // processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
    void ProcessMouseScroll(float yoffset);

private:
    // calculates the front vector from the Camera's (updated) Euler Angles
    void updateCameraVectors();
};

// //...
// #include <glad/glad.h>
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>

// #include <arithmetic.hpp>
// #include <vector>

// // Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
// enum Camera_Movement {
//     FORWARD,
//     BACKWARD,
//     LEFT,
//     RIGHT,
//     UP,
//     DOWN
// };

// // Default camera values
// const float YAW         = -90.0f;
// const float PITCH       =  0.0f;
// const float SPEED       =  2.5f;
// const float SENSITIVITY =  0.1f;
// const float ZOOM        =  45.0f;


// // An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
// class Camera
// {
// public:
//     // camera Attributes
//     VecMat::vec3 Position;
//     VecMat::vec3 Front;
//     VecMat::vec3 Up;
//     VecMat::vec3 Right;
//     VecMat::vec3 WorldUp;
//     // euler Angles
//     float Yaw;
//     float Pitch;
//     // camera options
//     float MovementSpeed;
//     float MouseSensitivity;
//     float Zoom;

//     // constructor with vectors
//     Camera(VecMat::vec3 position = VecMat::vec3(0.0f, 0.0f, 0.0f), VecMat::vec3 up = VecMat::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
//     // constructor with scalar values
//     Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

//     // returns the view matrix calculated using Euler Angles and the LookAt Matrix
//     VecMat::mat4 GetViewMatrix();

//     // processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
//     void ProcessKeyboard(Camera_Movement direction, float deltaTime);

//     // processes input received from a mouse input system. Expects the offset value in both the x and y direction.
//     void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);

//     // processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
//     void ProcessMouseScroll(float yoffset);

// private:
//     // calculates the front vector from the Camera's (updated) Euler Angles
//     void updateCameraVectors();
// };
