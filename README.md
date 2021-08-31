## Demonstration of Escape Room in OpenGL

3D rendering of a room with simple escape room logic using the concept of computer graphics along with the implementation of camera, lighting, skybox and so on.\
\
Four different colour cards(model) are placed in different positions of the room.
The user needs to find all those cards. After finding the cards, the door opens and light is turned on and the game is complete.

### Images

#### Initially Rendered Dark Room

![Initially Rendered Dark Room](/Screenshots/room_dark.png "Dark Room")

#### Room after Finding all the clues

![Room after Finding all the clues](/Screenshots/room_light.png "Bright Room")

#### Door Before and After Finding the Clues

![Door Before and After Finding the Clues](/Screenshots/door.png "Door Close and Open")

#### Room From Outside

![Room from Outside](/Screenshots/room_outer.png "Room from outside")

---

### System Requirements

- Operating System : Linux/ Windows
- Programming Language : C/C++
- Graphics API : OpenGL 4.6
- Library : GLFW, ASSIMP
- OpenGL Loader: GLAD

---

### Building Instructions

Compiling is simple in itself, simply compile all the executables within the src/Features folder and the main.cpp in the root directory and link the following
sfml flags with the compiler:\
\
`-lopengl32 -lgl -lglfw3 -lassimp`

#### 1) Windows

You can use CMake if you are on Windows to build the executable through the
CMakeLists file included in the root directory. Make sure to build the assimp library on your own.

#### 2) Linux

You need to clone the github repository of each library required and build it with cmake.
Then, you can simply use CMake to build the executable through the
CMakeLists file included in the root directory.

---

### Developers:

**1.Ranju G.C. 075BCT064 ([@Itshyphen](https://github.com/Itshyphen))**\
**2.Shreem Arjyal 075BCT084 ([@shreem011](https://github.com/shreem011))**\
**3.Supriya Khadka 075BCT090 ([@supriya090](https://github.com/supriya090))**
