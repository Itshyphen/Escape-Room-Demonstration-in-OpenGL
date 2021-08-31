### Demonstration of Escape Room in OpenGL

3D rendering of a room with simple escame room logic using the concept of computer graphics along with the implementation of camera, lighting, skybox and so on.\
\
Four different colour cards(model) are placed in different positions of the room.
The user needs to find all those cards, after which the door opens and ligh get turned on and the game is complete\
\


#### System Requirements
-  Operating System : Linux/ Windows
-  Programming Language : C/C++
-  Graphics API : OpenGL 4.6
-  Library : GLFW, ASSIMP
-  OpenGL Loader: GLAD
 
#### Building Instructions
Compiling is simple in itself, simply compile all the executables within the src/Features folder and the main.cpp in the root directory and link the following 
sfml flags with the compiler:\
\
`-lopengl32 -lgl -lglfw3 -lassimp`\
\

##### 1) Windows
You can use CMake if you are on Windows to build the executable through the
CMakeLists file included in the root directory. Make sure to build the assimp library on your own.\
\

##### 2) Linux
You need to clone the github repository of each library required and build it with cmake.
Then, you can simply use CMake to build the executable through the
CMakeLists file included in the root directory.

#### Developers:
**1.Ranju G.C. 075BCT064 ([@Itshyphen](https://github.com/Itshyphen))**
**2.Shreem Arjyal 075BCT084 ([@shreem011](https://github.com/shreem011))**\
**3.Supriya Khadka 075BCT090 ([@supriya090](https://github.com/supriya090))**
