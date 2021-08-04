// #include"render.hpp"

// int main()
// {
//      auto roomObjects = new Object("roomObj");
//         roomObjects->setPosition(0.0f,0.0,0.0f);
//         roomObjects->setScale(3.0f,3.0f,3.0f);
//         roomObjects->setRotationVector(0,1,0);
//         roomObjects->setAngle(0);
//         roomObjects->setModelName("../resources/models/Room/room2.obj");

//         auto door = new Object("door");
//         door->setPosition(0.0f,0.0,0.0f);
//         door->setScale(3.0f,3.0f,3.0f);
//         door->setRotationVector(0,1,0);
//         door->setAngle(0);
//         door->setModelName("../resources/models/Door/door.obj");

//        auto card1 = new Object("card1");
//        card1->setPosition(0.0f,-7.5,0.0f);
//        card1->setScale(3.0f,3.0f,3.0f);
//        card1->setRotationVector(0,1,0);
//        card1->setAngle(0);
//        card1->setModelName("../resources/Room/windw.obj");

//        auto card2 = new Object("card1");
//        card2->setPosition(0.0f,-7.5,0.0f);
//        card2->setScale(2.0f,2.0f,2.0f);
//        card2->setRotationVector(0,1,0);
//        card2->setAngle(0);
//        card2->setModelName("../resources/door/door.obj");

//        auto card3 = new Object("card1");
//        card3->setPosition(0.0f,-7.5,0.0f);
//        card3->setScale(2.0f,2.0f,2.0f);
//        card3->setRotationVector(0,1,0);
//        card3->setAngle(0);
//        card3->setModelName("../resources/door/door.obj");

//        auto card4 = new Object("card1");
//        card4->setPosition(0.0f,-7.5,0.0f);
//        card4->setScale(2.0f,2.0f,2.0f);
//        card4->setRotationVector(0,1,0);
//        card4->setAngle(0);
//        card4->setModelName("../resources/door/door.obj");

//         auto room =new Object;
//         room->addObject(roomObjects);
//         room->addObject(door);
//        room->addObject(card1);
//        room->addObject(card2);
//        room->addObject(card3);
//        room->addObject(card4);

//     visualisation::render render(room);
//     return 0;
// }

#include<iostream>
#include <arithmetic.hpp>
#include<cmath>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


int main()
{
   //   auto roomObjects = new Object("roomObj");
   //      roomObjects->setPosition(0.0f,0.0,0.0f);
   //      roomObjects->setScale(3.0f,3.0f,3.0f);
   //      roomObjects->setRotationVector(0,1,0);
   //      roomObjects->setAngle(0);
   //      roomObjects->setModelName("../resources/models/Room/room2.obj");

   //      auto door = new Object("door");
   //      door->setPosition(0.0f,0.0,0.0f);
   //      door->setScale(3.0f,3.0f,3.0f);
   //      door->setRotationVector(0,1,0);
   //      door->setAngle(0);
   //      door->setModelName("../resources/models/Door/door.obj");

   //     auto card1 = new Object("card1");
   //     card1->setPosition(0.0f,-7.5,0.0f);
   //     card1->setScale(3.0f,3.0f,3.0f);
   //     card1->setRotationVector(0,1,0);
   //     card1->setAngle(0);
   //     card1->setModelName("../resources/Room/windw.obj");

   //     auto card2 = new Object("card1");
   //     card2->setPosition(0.0f,-7.5,0.0f);
   //     card2->setScale(2.0f,2.0f,2.0f);
   //     card2->setRotationVector(0,1,0);
   //     card2->setAngle(0);
   //     card2->setModelName("../resources/door/door.obj");

   //     auto card3 = new Object("card1");
   //     card3->setPosition(0.0f,-7.5,0.0f);
   //     card3->setScale(2.0f,2.0f,2.0f);
   //     card3->setRotationVector(0,1,0);
   //     card3->setAngle(0);
   //     card3->setModelName("../resources/door/door.obj");

   //     auto card4 = new Object("card1");
   //     card4->setPosition(0.0f,-7.5,0.0f);
   //     card4->setScale(2.0f,2.0f,2.0f);
   //     card4->setRotationVector(0,1,0);
   //     card4->setAngle(0);
   //     card4->setModelName("../resources/door/door.obj");

   //      auto room =new Object;
   //      room->addObject(roomObjects);
   //      room->addObject(door);
   //     room->addObject(card1);
   //     room->addObject(card2);
   //     room->addObject(card3);
   //     room->addObject(card4);

   //  visualisation::render render(room);
            glm::mat4 p(1);
            p = glm::perspective(glm::radians(45.0f), (float)1920/(float)400, 0.1f, 100.0f);
   VecMat::mat4 projection = VecMat::perspective(45, (float)1920/(float)400, 0.1f, 100.0f);
   std::cout<<tan(glm::radians(45.0f)/2)<<std::endl;
   std::cout<<tan(45/2*3.14/180)<<std::endl;

    for(int x=0;x<4;x++)  // loop 3 times for three lines
    {
        for(int y=0;y<4;y++)  // loop for the three elements on the line
        {
            std::cout<<projection[x][y];  // display the current element out of the array
            std::cout<<" ";
        }
    std::cout<<std::endl;  // when the inner loop is done, go to a new line
    }
std::cout<<std::endl;
    for(int x=0;x<4;x++)  // loop 3 times for three lines
    {
        for(int y=0;y<4;y++)  // loop for the three elements on the line
        {
            std::cout<<p[x][y];  // display the current element out of the array
            std::cout<<" ";
        }
    std::cout<<std::endl;  // when the inner loop is done, go to a new line
    }
    return 0;
}

