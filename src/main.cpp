#include"render.hpp"

int main()
{
     auto roomObjects = new Object("roomObj");
        roomObjects->setPosition(0.0f,0.0,0.0f);
        roomObjects->setScale(3.0f,3.0f,3.0f);
        roomObjects->setRotationVector(0,1,0);
        roomObjects->setAngle(0);
        roomObjects->setModelName("../resources/models/Room/room4walls.obj");

        auto door = new Object("door");
        door->setPosition(0.0f,0.0,0.0f);
        door->setScale(3.0f,3.0f,3.0f);
        door->setRotationVector(0,1,0);
        door->setAngle(0);
        door->setModelName("../resources/models/Door/door.obj");

        auto blueCard = new Object("blueCard");
        blueCard->setPosition(-3.58f,0.02f,-3.28f);
        blueCard->setScale(3.0f,3.0f,3.0f);
        blueCard->setRotationVector(0,1,0);
        blueCard->setAngle(35);
        blueCard->setModelName("../resources/models/Room/blueC.obj");

        auto redCard = new Object("redCard");
        redCard->setPosition(3.69f,1.10f,-4.17f);
        redCard->setScale(3.0f,3.0f,3.0f);
        redCard->setRotationVector(0,1,0);
        redCard->setAngle(0);
        redCard->setModelName("../resources/models/Room/redC.obj");

       auto greenCard = new Object("greenCard");
       greenCard->setPosition(-3.36f,4.79f,-4.86f);
       greenCard->setScale(3.0f,3.0f,3.0f);
       greenCard->setRotationVector(0,1,0);
       greenCard->setAngle(0);
       greenCard->setModelName("../resources/models/Room/greenC.obj");

       auto yellowCard = new Object("yellowCard");
       yellowCard->setPosition(2.30f,0.93f,2.87f);
       yellowCard->setScale(3.0f,3.0f,3.0f);
       yellowCard->setRotationVector(0,1,0);
       yellowCard->setAngle(0);
       yellowCard->setModelName("../resources/models/Room/yellowC.obj");

        auto room =new Object;
        room->addObject(roomObjects);
        room->addObject(door);
       room->addObject(blueCard);
       room->addObject(redCard);
       room->addObject(greenCard);
       room->addObject(yellowCard);

    visualisation::render render(room);
    return 0;
}

// #includes<iostream>
// #includes <matrix.hpp>
// #includes<cmath>

// #includes <glm/glm.hpp>
// #includes <glm/gtc/matrix_transform.hpp>
// #includes <glm/gtc/type_ptr.hpp>


// int main()
// {
//    //   auto roomObjects = new Object("roomObj");
//    //      roomObjects->setPosition(0.0f,0.0,0.0f);
//    //      roomObjects->setScale(3.0f,3.0f,3.0f);
//    //      roomObjects->setRotationVector(0,1,0);
//    //      roomObjects->setAngle(0);
//    //      roomObjects->setModelName("../resources/models/Room/room2.obj");

//    //      auto door = new Object("door");
//    //      door->setPosition(0.0f,0.0,0.0f);
//    //      door->setScale(3.0f,3.0f,3.0f);
//    //      door->setRotationVector(0,1,0);
//    //      door->setAngle(0);
//    //      door->setModelName("../resources/models/Door/door.obj");

//    //     auto blueCard = new Object("blueCard");
//    //     blueCard->setPosition(0.0f,-7.5,0.0f);
//    //     blueCard->setScale(3.0f,3.0f,3.0f);
//    //     blueCard->setRotationVector(0,1,0);
//    //     blueCard->setAngle(0);
//    //     blueCard->setModelName("../resources/Room/windw.obj");

//    //     auto redCard = new Object("blueCard");
//    //     redCard->setPosition(0.0f,-7.5,0.0f);
//    //     redCard->setScale(2.0f,2.0f,2.0f);
//    //     redCard->setRotationVector(0,1,0);
//    //     redCard->setAngle(0);
//    //     redCard->setModelName("../resources/door/door.obj");

//    //     auto greenCard = new Object("blueCard");
//    //     greenCard->setPosition(0.0f,-7.5,0.0f);
//    //     greenCard->setScale(2.0f,2.0f,2.0f);
//    //     greenCard->setRotationVector(0,1,0);
//    //     greenCard->setAngle(0);
//    //     greenCard->setModelName("../resources/door/door.obj");

//    //     auto yellowCard = new Object("blueCard");
//    //     yellowCard->setPosition(0.0f,-7.5,0.0f);
//    //     yellowCard->setScale(2.0f,2.0f,2.0f);
//    //     yellowCard->setRotationVector(0,1,0);
//    //     yellowCard->setAngle(0);
//    //     yellowCard->setModelName("../resources/door/door.obj");

//    //      auto room =new Object;
//    //      room->addObject(roomObjects);
//    //      room->addObject(door);
//    //     room->addObject(blueCard);
//    //     room->addObject(redCard);
//    //     room->addObject(greenCard);
//    //     room->addObject(yellowCard);

//    //  visualisation::render render(room);
//             glm::mat4 p(1);
//             p = glm::perspective(glm::radians(45.0f), (float)1920/(float)400, 0.1f, 100.0f);
//    VecMat::mat4 projection = VecMat::perspective(45, (float)1920/(float)400, 0.1f, 100.0f);
   
//    p = glm::rotate(p, glm::radians((float) 45), glm::vec3(0.0f, 1.0f, 0.0f));
//     projection = VecMat::rotate(projection, VecMat::vec3(0.0f, 1.0f, 0.0f), (float) 45);
//     p = glm::scale(p,  glm::vec3(7.0f, 9.0f, 5.0f));
//     projection = VecMat::scale(projection,  VecMat::vec3(7.0f, 9.0f, 5.0f));

//     for(int x=0;x<4;x++)  // loop 3 times for three lines
//     {
//         for(int y=0;y<4;y++)  // loop for the three elements on the line
//         {
//             std::cout<<projection[x][y];  // display the current element out of the array
//             std::cout<<" ";
//         }
//     std::cout<<std::endl;  // when the inner loop is done, go to a new line
//     }
// std::cout<<std::endl;
//     for(int x=0;x<4;x++)  // loop 3 times for three lines
//     {
//         for(int y=0;y<4;y++)  // loop for the three elements on the line
//         {
//             std::cout<<p[x][y];  // display the current element out of the array
//             std::cout<<" ";
//         }
//     std::cout<<std::endl;  // when the inner loop is done, go to a new line
//     }
//     return 0;
// }

