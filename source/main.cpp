#include"render.hpp"

int main()
{
    auto room = new Object();
    room = createRoom();
    visualisation::render render(room);
    return 0;
}

