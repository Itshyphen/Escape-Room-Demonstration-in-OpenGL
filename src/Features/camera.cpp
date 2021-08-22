#include"camera.hpp"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//  Camera::Camera(glm::vec3 position , glm::vec3 up , float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
//     {
//         Position = position;
//         WorldUp = up;
//         Yaw = yaw;
//         Pitch = pitch;
//         updateCameraVectors();
//     }
//COnstructor with VecMat library
     Camera::Camera(VecMat::vec3 position , VecMat::vec3 up , float yaw, float pitch) : Front(VecMat::vec3(-20.0f, -20.0f, -20.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
    {
        Position = position;
        WorldUp = up;
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }
    // constructor with scalar values
    Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(VecMat::vec3(-4.0f, -4.0f, -4.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
    {
        Position = VecMat::vec3(posX, posY, posZ);
        WorldUp = VecMat::vec3(upX, upY, upZ);
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }

    // returns the view matrix calculated using Euler Angles and the LookAt Matrix
     VecMat::mat4 Camera:: GetViewMatrix()
     {
    VecMat::mat4 viewMatrix(1);
//    viewMatrix = VecMat::translate(viewMatrix, VecMat::vec3(0)-2);
//    viewMatrix = VecMat::rotate(viewMatrix, to_radians(Pitch), VecMat::vec3(1.0f, 0.0f, 0.0f));
//    viewMatrix = VecMat::rotate(viewMatrix, to_radians(Yaw), VecMat::vec3(0.0f, 1.0f, 0.0f));
//    viewMatrix = VecMat::translate(viewMatrix, VecMat::vec3(-Position.x,0,-Position.z));
//    return viewMatrix;
VecMat::vec3 candlePos =Position + Front;
if(Pitch<0){
    return VecMat::lookAt(Position,VecMat::vec3(candlePos.x,candlePos.y+Pitch/450,candlePos.z) , Up);
}else{
    return VecMat::lookAt(Position,VecMat::vec3(candlePos.x,candlePos.y+0.5,candlePos.z) , Up);
}
     }

//    VecMat::mat4 Camera:: GetViewMatrix()
//    {
//        return VecMat::lookAt(Position+propPosition-1, propPosition, Up);
//    }

    void Camera::setPropPosition(VecMat::vec3 pos) {
    propPosition = pos;
}

VecMat::vec3 Camera::getPropPosition() {
    return propPosition;
}

//     processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
    void Camera:: ProcessKeyboard(Camera_Movement direction, float deltaTime)
    {
//        float velocity = -0.05;
//        if(Position+Front<=VecMat::vec3(4.4,7.0,5.2) and Position+Front>VecMat::vec3(-4.0,1.5,-4.9)) {
            float velocity = 0.5 * deltaTime;
//        }
            if (direction == FORWARD) {
                Position += Front * velocity;
                propPosition += Front * velocity;
            }
            if (direction == BACKWARD) {
                Position -= Front * velocity;
                propPosition -= Front * velocity;
            }
            if (direction == LEFT) {
                Position -= Right * velocity;
                propPosition -= Right * velocity;
            }
            if (direction == RIGHT) {
                Position += Right * velocity;
                propPosition += Right * velocity;

            }
            if (direction == UP) {
                Position += WorldUp * velocity;
                propPosition += WorldUp * velocity;

            }
            if (direction == DOWN) {
                Position -= WorldUp * velocity;
                propPosition -= WorldUp * velocity;

            }

        propPosition.display();
    }
//
//void Camera:: ProcessKeyboard(Camera_Movement direction, float deltaTime)
//{
//    float velocity = MovementSpeed * deltaTime;
//    std::cout<<MovementSpeed<<std::endl;
//    if (direction == FORWARD)
//        Position += VecMat::vec3(0,0,-0.1) ;
//    if (direction == BACKWARD)
//        Position = VecMat::vec3(0,0,0.1) ;
//    if (direction == LEFT)
//        Position = VecMat::vec3(-0.1,0,0.0);
//    if (direction == RIGHT)
//        Position = VecMat::vec3(0.1,0,0) ;
//    if (direction == UP)
//        Position = VecMat::vec3(0,0.1,0) ;
//    if (direction == DOWN)
//        Position = VecMat::vec3(0,-0.1,0) ;
//}

    // processes input received from a mouse input system provided the offset value in both the x and y direction.
    void Camera:: ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
    {
        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        Yaw   += xoffset;
        Pitch += yoffset;

        // make sure that when pitch is out of bounds, screen doesn't get flipped
       
            if (Pitch > 89.0f)
                Pitch = 89.0f;
            if (Pitch < -89.0f)
                Pitch = -89.0f;
        

        // update Front, Right and Up Vectors using the updated Euler angles
        updateCameraVectors();
    }

    // processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
    void Camera :: ProcessMouseScroll(float yoffset)
    {
        Zoom -= (float)yoffset;
        if (Zoom < 1.0f)
            Zoom = 1.0f;
        if (Zoom > 45.0f)
            Zoom = 45.0f; 
    }

    // Calculates the front vector from the Camera's (updated) Eular Angles
    // void Camera:: updateCameraVectors()
    // {
    //     // calculate the new Front vector
    //     glm::vec3 front;
    //     front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    //     front.y = sin(glm::radians(Pitch));
    //     front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    //     Front = glm::normalize(front);
        
    //     Right = glm::normalize(glm::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    //     Up    = glm::normalize(glm::cross(Right, Front));
    // }

        void Camera:: updateCameraVectors()
    {
        // calculate the new Front vector


        VecMat::vec3 front;
        front.x = cos(to_radians(Yaw)) * cos(to_radians(Pitch));
        front.y = sin(to_radians(Pitch));
        front.z = sin(to_radians(Yaw)) * cos(to_radians(Pitch));
//        if(Position+VecMat::normalize(front)<=VecMat::vec3(4.4,7.0,5.2) and Position+VecMat::normalize(front)>VecMat::vec3(-4.0,1.5,-4.64))
//        {
//
//        }
        Front = VecMat::normalize(front);
        
        Right = VecMat::normalize(VecMat::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        Up    = VecMat::normalize(VecMat::cross(Right, Front));
    }