#include"render.hpp"

int main()
{
     auto roomObjects = new Object("roomObj");
        roomObjects->setPosition(0.0f,0.0,0.0f);
        roomObjects->setScale(3.0f,3.0f,3.0f);
        roomObjects->setRotationVector(0,1,0);
        roomObjects->setAngle(0);
        roomObjects->setModelName("../resources/models/Room/room.obj");

        auto door = new Object("door");
        door->setPosition(0.0f,0.0,0.0f);
        door->setScale(3.0f,3.0f,3.0f);
        door->setRotationVector(0,1,0);
        door->setAngle(0);
        door->setModelName("../resources/models/Door/door.obj");

       auto card1 = new Object("card1");
       card1->setPosition(0.0f,-7.5,0.0f);
       card1->setScale(2.0f,2.0f,2.0f);
       card1->setRotationVector(0,1,0);
       card1->setAngle(0);
       card1->setModelName("../resources/door/door.obj");

       auto card2 = new Object("card1");
       card2->setPosition(0.0f,-7.5,0.0f);
       card2->setScale(2.0f,2.0f,2.0f);
       card2->setRotationVector(0,1,0);
       card2->setAngle(0);
       card2->setModelName("../resources/door/door.obj");

       auto card3 = new Object("card1");
       card3->setPosition(0.0f,-7.5,0.0f);
       card3->setScale(2.0f,2.0f,2.0f);
       card3->setRotationVector(0,1,0);
       card3->setAngle(0);
       card3->setModelName("../resources/door/door.obj");

       auto card4 = new Object("card1");
       card4->setPosition(0.0f,-7.5,0.0f);
       card4->setScale(2.0f,2.0f,2.0f);
       card4->setRotationVector(0,1,0);
       card4->setAngle(0);
       card4->setModelName("../resources/door/door.obj");

        auto room =new Object;
        room->addObject(roomObjects);
        room->addObject(door);
       room->addObject(card1);
       room->addObject(card2);
       room->addObject(card3);
       room->addObject(card4);

    visualisation::render render(room);
    return 0;
}

