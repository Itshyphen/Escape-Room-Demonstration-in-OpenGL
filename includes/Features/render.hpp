// GLFW - glad
#include <glad/glad.h>
#include<GLFW/glfw3.h>

// // GLM Mathemtics
// #includes <glm/glm.hpp>
// #includes <glm/gtc/matrix_transform.hpp>
// #includes <glm/gtc/type_ptr.hpp>

#include "camera.hpp"
#include "model.hpp"
#include "object.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

namespace visualisation
{


    class render
    {
    private:
        GLFWwindow *window;
        GLuint cubemapTexture;
        Object *room;
        GLuint cubeVBO, cubeVAO, lightVAO, skyboxVAO, skyboxVBO;
        vector<VecMat::vec3> modelPosition;
        vector<VecMat::vec3> modelRotationVector;
        vector<VecMat::vec3> modelScale;
        vector<string> modelname;
        vector<double> modelAngle;
        vector<Model> models;
        vector<VecMat::vec3> lampPosition;
        vector<VecMat::vec3> lightPosition;

        double w;
        double l;
        double h;

    public:
        render(Object *room);
        ~render();
        void getSize();
        void visualise();
        GLuint loadCubemap(vector<std::string> faces);
        void initializeVertex();
        void setLampPosition();
        void setLightPosition();
        void initializeGlfw();
        void getModels();
    };
} // namespace visualisation

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void mouse_callback(GLFWwindow *window, double xpos, double ypos);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

bool opendoor = false;

// camera
Camera camera(VecMat::vec3(4.0f, 6.0f, 4.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f; // time between current frame and last frame
float lastFrame = 0.0f;

visualisation::render::render(Object *room)
{
    this->room = room;
    visualise();
}

visualisation::render::~render()
{
}

void visualisation::render::getModels()
{
    for (int i = 0; i < room->children.size(); ++i)
    {
        modelPosition.push_back(room->children[i]->getPosition());
        modelScale.push_back(room->children[i]->getScale());
        modelAngle.push_back(room->children[i]->getAngle());
        modelRotationVector.push_back(room->children[i]->getRotationVector());
        modelname.push_back(room->children[i]->getName());
        Model model(room->children[i]->getModelName());
        models.push_back(model);
    }
}

//Vertices
float vertices[] = {
    // positions          // normals           // texture coords
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
    0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
    0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
    0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
    -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,

    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
    0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
    0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
    0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
    -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,

    -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
    -0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
    -0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

    0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
    0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
    0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
    0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
    0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
    0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
    0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
    0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
    -0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,

    -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
    0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
    0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
    0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
    -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
    -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f};

float skyboxVertices[] = {
    // positions
    -1.0f, 1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
    1.0f, -1.0f, -1.0f,
    1.0f, -1.0f, -1.0f,
    1.0f, 1.0f, -1.0f,
    -1.0f, 1.0f, -1.0f,

    -1.0f, -1.0f, 1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f, 1.0f, -1.0f,
    -1.0f, 1.0f, -1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f,

    1.0f, -1.0f, -1.0f,
    1.0f, -1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, -1.0f,
    1.0f, -1.0f, -1.0f,

    -1.0f, -1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, -1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f,

    -1.0f, 1.0f, -1.0f,
    1.0f, 1.0f, -1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, -1.0f,

    -1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f, 1.0f,
    1.0f, -1.0f, -1.0f,
    1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f, 1.0f,
    1.0f, -1.0f, 1.0f};
 vector<std::string> faces{
     "../resources/skybox/right.jpg",
     "../resources/skybox/left.jpg",
     "../resources/skybox/top.jpg",
     "../resources/skybox/bottom.jpg",
     "../resources/skybox/back.jpg",
     "../resources/skybox/front.jpg"};

 VecMat::vec3 propPosition;
 bool nightmode =  true;
 bool yellowcard = false;
 bool bluecard =  true ;
 bool  redcard =  true ;
 bool  greencard =  true ;
 bool displaycard =true;

void visualisation::render::initializeGlfw()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Create glfw window
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Escape Room Demonstration in OpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    // tell GLFW to capture our mouse
    //once the application has focus, the mouse cursor stays within the center of the window
    //        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    glEnable(GL_DEPTH_TEST);
//    glDepthMask(GL_FALSE);


    cout << "WINDOW CREATED!" << endl;
}

void visualisation::render::initializeVertex()
{
    // send vertices as input to the first process of the graphics pipeline:
    //the vertex shader and we manage this memory by VBO and it has an unique ID
    //using the glGenBuffers
    //LINKING VERTEX ATTRIBUTES

    //tell OpenGL how it should interpret the vertex data
    //(per vertex attribute) using glVertexAttribPointer:

    //Core OpenGL requires that we use a VAO so it knows what to do
    //with our vertex inputs. If we fail to bind a VAO, OpenGL
    //will most likely refuse to draw anything.
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &cubeVBO);

    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenVertexArrays(1, &lightVAO);
    glBindVertexArray(lightVAO);
    // we only need to bind to the cubeVBO, the container's cubeVBO's data already contains the correct data.
    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    // set the vertex attributes (only position data for our lamp)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glGenVertexArrays(1, &skyboxVAO);
    glGenBuffers(1, &skyboxVBO);
    glBindVertexArray(skyboxVAO);
    glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);

    // we can make a call to the glBufferData function that copies the
    //previously defined vertex data into the buffer's memory:
    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    cout << "Successfully initialized vertexes" << endl;
}

void visualisation::render::setLightPosition()
{
    if(nightmode){
        VecMat::vec3 candlePos=camera.Position+VecMat::normalize(camera.Front)*0.1;
        lightPosition.push_back(VecMat::vec3(50, 6, -5.1));
        lightPosition.push_back(VecMat::vec3(-50, 6, -5.1));

        lightPosition.push_back(candlePos);
        lightPosition.push_back(VecMat::vec3(55, 40, 0));
    }
    else {
        lightPosition.push_back(VecMat::vec3(0.8, 6, -5.1));
        lightPosition.push_back(VecMat::vec3(-0.8, 6, -5.1));

        lightPosition.push_back(VecMat::vec3(3.55, 2.1, -4.6));
        lightPosition.push_back(VecMat::vec3(0, 40, 0));
    }

    camera.setPropPosition(VecMat::vec3(2,2.,2.));
}
void visualisation::render::visualise()
{

    initializeGlfw();

    // build and compile shaders
    // -------------------------
    Shader ourShader("../resources/shaders/mainvertex.vs", "../resources/shaders/mainfragment.fs");    //Lightning Shader
    Shader lampShader("../resources/shaders/lightvertex.vs", "../resources/shaders/lightfragment.fs"); //Light Shader
    Shader skyboxShader("../resources/shaders/skybox.vs", "../resources/shaders/skybox.fs");           //CubeMap Shader

    //initiliaze vertex
    initializeVertex();

    // setLampPosition();
    setLightPosition();

    //Get the models
    getModels();

    //load cubemap faces
    Texture::loadCubemap(faces);

    ourShader.Bind();
    ourShader.setInt("material.diffuse", 0);
    ourShader.setInt("material.specular", 1);
    skyboxShader.Bind();
    skyboxShader.setInt("skybox", 0);

    Model model("../resources/models/Room/candle.obj");


    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {

        // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = 2 * (currentFrame - lastFrame);
        lastFrame = currentFrame;

        // input
        // -----
        glfwPollEvents();
        processInput(window);


        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        ourShader.Bind();
        ourShader.setVec3("viewPos", camera.Position);
        ourShader.setFloat("material.shininess", 32.0f);
        // light properties
        ourShader.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
        ourShader.setVec3("dirLight.ambient", 0.00001f, 0.00001f, 0.001f);
        ourShader.setVec3("dirLight.diffuse", 0.0f, 0.0f, 0.0f);
        ourShader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);

        if (nightmode){
            // point light 1
            ourShader.setVec3("pointLights[0].position", lightPosition[0]);
            ourShader.setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
            ourShader.setVec3("pointLights[0].diffuse", cos(time(nullptr)), 0.8f, sin(time(nullptr)));
            ourShader.setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
            ourShader.setFloat("pointLights[0].constant", 1.0f);
            ourShader.setFloat("pointLights[0].linear", 0.09);
            ourShader.setFloat("pointLights[0].quadratic", 0.032);
            // point light 2
            ourShader.setVec3("pointLights[1].position", lightPosition[1]);
            ourShader.setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
            ourShader.setVec3("pointLights[1].diffuse", sin(time(nullptr)), 0.8f, cos(time(nullptr)));
            ourShader.setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
            ourShader.setFloat("pointLights[1].constant", 1.0f);
            ourShader.setFloat("pointLights[1].linear", 0.09);
            ourShader.setFloat("pointLights[1].quadratic", 0.032);
            // // point light 2
            VecMat::vec3 candlePos =camera.Position+VecMat::normalize(camera.Front)*0.1;
            ourShader.setVec3("pointLights[2].position",VecMat::vec3(candlePos.x,candlePos.y+0.02,candlePos.z));
            ourShader.setVec3("pointLights[2].ambient", 0.00005f, 0.00005f, 0.00005f);
            ourShader.setVec3("pointLights[2].diffuse", 1.0f, 1.0f, 0.5f);
            ourShader.setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
            ourShader.setFloat("pointLights[2].constant", 1.0f);
            ourShader.setFloat("pointLights[2].linear", 0.009);
            ourShader.setFloat("pointLights[2].quadratic", 0.032);
            // // point light 3
            ourShader.setVec3("pointLights[3].position", lightPosition[3]);
            ourShader.setVec3("pointLights[3].ambient", 0.15f, 0.15f, 0.15f);
            ourShader.setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
            ourShader.setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
            ourShader.setFloat("pointLights[3].constant", 0.01f);
            ourShader.setFloat("pointLights[3].linear", 0.0004);
            ourShader.setFloat("pointLights[3].quadratic", 0.0013);
        }
        else { // point light 1
            ourShader.setVec3("pointLights[0].position", VecMat::vec3(0.8, 6, -5.1));
            ourShader.setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
            ourShader.setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
            ourShader.setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
            ourShader.setFloat("pointLights[0].constant", 1.0f);
            ourShader.setFloat("pointLights[0].linear", 0.09);
            ourShader.setFloat("pointLights[0].quadratic", 0.032);
            // point light 2
            ourShader.setVec3("pointLights[1].position", VecMat::vec3(-0.8, 6, -5.1));
            ourShader.setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
            ourShader.setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
            ourShader.setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
            ourShader.setFloat("pointLights[1].constant", 1.0f);
            ourShader.setFloat("pointLights[1].linear", 0.09);
            ourShader.setFloat("pointLights[1].quadratic", 0.032);
            // // point light 2
            ourShader.setVec3("pointLights[2].position", VecMat::vec3(3.55, 2.1, -4.6));
            ourShader.setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
            ourShader.setVec3("pointLights[2].diffuse", 1.0f, 1.0f, 0.5f);
            ourShader.setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
            ourShader.setFloat("pointLights[2].constant", 1.0f);
            ourShader.setFloat("pointLights[2].linear", 0.09);
            ourShader.setFloat("pointLights[2].quadratic", 0.032);
            // // point light 3
            ourShader.setVec3("pointLights[3].position", VecMat::vec3(0, 40, 0));
            ourShader.setVec3("pointLights[3].ambient", 0.15f, 0.15f, 0.15f);
            ourShader.setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
            ourShader.setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
            ourShader.setFloat("pointLights[3].constant", 0.01f);
            ourShader.setFloat("pointLights[3].linear", 0.0004);
            ourShader.setFloat("pointLights[3].quadratic", 0.0013);
        }

        ourShader.Bind();

        // Transformation matrices
        // -----------------------
        // glm::mat4 projection(1);
        // projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 1000.0f);
        // glm::mat4 view(1);
        // view = camera.GetViewMatrix();
        // ourShader.setMat4("projection", projection);
        // ourShader.setMat4("view", view);

        VecMat::mat4 projection;
        projection = VecMat::perspective(camera.Zoom, (float)SCR_WIDTH / (float)SCR_HEIGHT);
        VecMat::mat4 view(1);
        view = camera.GetViewMatrix();
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);


        //Draw the models
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);
        for (int i = 0; i < models.size(); ++i)
        {
            VecMat::mat4 modelObject = VecMat::mat4(1.0f);
            if (modelname[i] == "door" && opendoor)
            {
                modelObject = VecMat::translate(modelObject, VecMat::vec3(-4.5,0.0,0.75)); // Translate it down a bit so it's at the center of the scene
                modelObject = VecMat::rotate(modelObject, to_radians(80.0f), VecMat::vec3(0.0f, 1.0f, 0.0f));
                modelObject = VecMat::scale(modelObject, modelScale[i]); 
            }
            else
            {
                if (modelname[i] == "redCard" && redcard)
                {
//                    modelObject = VecMat::translate(modelObject, modelPosition[i]);
                    modelPosition[i] = VecMat::vec3(-4.32, 3.66, 3.29);
                    modelAngle[i]=90.0f;
//                    modelScale[i]=VecMat::vec3(6, 6, 3);

                }
                if (modelname[i] == "yellowCard" && yellowcard)
                {
                    modelPosition[i] = VecMat::vec3(-4.32, 3.11, 3.29);
                    modelAngle[i]=90.0f;
                }
                if (modelname[i] == "blueCard" && bluecard)
                {
                    modelPosition[i] = VecMat::vec3(-4.32, 3.70, 4.42);
                    modelAngle[i]=90.0f;
                }
                if (modelname[i] == "greenCard" && greencard)
                {
                    modelPosition[i] = VecMat::vec3(-4.32, 3.09, 4.40);
                    modelAngle[i]=90.0f;
                }

                    modelObject = VecMat::translate(modelObject, modelPosition[i]); // Translate it down a bit so it's at the center of the scene
                    modelObject = VecMat::rotate(modelObject, to_radians((float)modelAngle[i]), VecMat::vec3(0.0f, 1.0f, 0.0f));
                    modelObject = VecMat::rotate(modelObject, to_radians((float)modelAngle[i]), VecMat::vec3(1.0f, 0.0f, 0.0f));
                    modelObject = VecMat::scale(modelObject, modelScale[i]);



            }

            // It's a bit too big for our scene, so scale it down
            ourShader.setMat4("model", modelObject);
            models[i].Draw(ourShader);
//            cout << "Drawing Objects in the room" << endl;
        }

        VecMat::mat4 candle(1.0);
//        candle = VecMat::translate(candle,camera.Position+VecMat::normalize(camera.Front)*0.1);
        VecMat::vec3 candlePos=camera.Position+VecMat::normalize(camera.Front)*0.1;
        candle = VecMat::translate(candle,VecMat::vec3(candlePos.x,candlePos.y-0.02,candlePos.z));

        candle = VecMat::scale(candle,VecMat::vec3(0.01,0.01,0.01));
        ourShader.setMat4("model", candle);
        model.Draw(ourShader);

        camera.setPropPosition(propPosition);
        std::cout<<candlePos.x<<","<<candlePos.y-0.02<<","<<candlePos.z<<std::endl;

        //light objects
        for (unsigned int i = 0; i < 2; i++)
        {
            VecMat::mat4 model(1.0);
            model = VecMat::translate(model, lightPosition[i]);
            model = VecMat::rotate(model, to_radians(90.0f), VecMat::vec3(0.0f, 1.0f, 0.0f));
            model = VecMat::scale(model, VecMat::vec3(0.03f, 0.05f, 1.8f)); // a smaller cube
            lampShader.setMat4("model", model);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        for (unsigned int i = 2; i < 4; i++)
        {
            VecMat::mat4 model(1.0);
            model = VecMat::translate(model, lightPosition[i]);
            model = VecMat::rotate(model, to_radians(90.0f), VecMat::vec3(1.0f, 0.0f, 0.0f));
            model = VecMat::scale(model, VecMat::vec3(0.1f, 0.15f, 0.15f)); // a smaller cube
            lampShader.setMat4("model", model);

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        // draw skybox as last
        glDepthFunc(GL_LEQUAL); // change depth function so depth test passes when values are equal to depth buffer's content
        skyboxShader.Bind();
        view = VecMat::mat4(VecMat::mat3(camera.GetViewMatrix())); // remove translation from the view matrix
        skyboxShader.setMat4("view", view);
        skyboxShader.setMat4("projection", projection);
        // skybox cube
        glBindVertexArray(skyboxVAO);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);
        glDepthFunc(GL_LESS); // set depth function back to default

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    //All the buffers are deleted in destructor
    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteVertexArrays(1, &lightVAO);
    glDeleteVertexArrays(1, &skyboxVAO);
    glDeleteBuffers(1, &skyboxVBO);
    glDeleteBuffers(1, &cubeVBO);
    cout << "Successfully deleted Buffers" << endl;

    glfwTerminate();
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        camera.ProcessKeyboard(FORWARD, deltaTime);
        propPosition = propPosition+VecMat::vec3(0,0,-0.1);
    }

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        camera.ProcessKeyboard(BACKWARD, deltaTime);
        propPosition = propPosition + VecMat::vec3(0, 0, 0.1);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        camera.ProcessKeyboard(LEFT, deltaTime);
        propPosition = propPosition + VecMat::vec3(-0.1, 0, 0);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        camera.ProcessKeyboard(RIGHT, deltaTime);
        propPosition = propPosition + VecMat::vec3(0.1, 0, 0);
    }
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
        camera.ProcessKeyboard(UP, deltaTime);
        propPosition = propPosition + VecMat::vec3(0, 0.1, 0);
    }
    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
        camera.ProcessKeyboard(DOWN, deltaTime);
        propPosition = propPosition + VecMat::vec3(0, -0.1, 0);
    }
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
        opendoor=true;
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_RELEASE)
        opendoor = false;
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
    {
        //greencard = !greencard;
        VecMat::vec3 candlePos = camera.Position + VecMat::normalize(camera.Front) * 0.1;

        if ((-3.74 < candlePos.x && candlePos.x < -3.3) && ((0.16 < (candlePos.y - 0.02)) && ((candlePos.y - 0.02) < 0.38)) && (-3.56 < candlePos.z) && (candlePos.z < -3.2))
        {
            cout<<"Test"<<endl;
            bluecard = true;
        }
        if ((3.3 < candlePos.x && candlePos.x < 3.9) && ((0.9 < (candlePos.y - 0.02)) && ((candlePos.y - 0.02) < 1.2)) && (-4.4 < candlePos.z) && (candlePos.z < -3.9))
        {
            redcard = true;
        }
        if ((-3.6 < candlePos.x && candlePos.x < -3.0) && ((4.4 < (candlePos.y - 0.02)) && ((candlePos.y - 0.02) < 5.2)) && (-5.2 < candlePos.z && candlePos.z < -4.4))
        {
            greencard = true;
        }
        if ((2.0 < candlePos.x && candlePos.x < 2.8) && ((0.6 < (candlePos.y - 0.02)) && ((candlePos.y - 0.02) < 1.2)) && (2.5 < candlePos.z && candlePos.z < 3.2))
        {
            yellowcard = true;
        }
//        if(bluecard && redcard && greencard && yellowcard)
//        {
//            nightmode=false;
//            opendoor = true;
//
//        }
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE){
        if(bluecard && redcard && greencard && yellowcard)
        {
            nightmode=false;
            opendoor = true;
            displaycard =false;
//            camera.Front=VecMat::vec3(2.40302,3.35561,2.98072);

        }
    }
}


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        double mouse_x, mouse_y;
        //getting cursor position
        glfwGetCursorPos(window, &mouse_x, &mouse_y);
        cout << "Cursor Position at (" << mouse_x << " : " << mouse_y << ")"<<endl;

        //3D normalized device coordinates
        float x = (2.0f * mouse_x) / SCR_WIDTH - 1.0f;
        float y = 1.0f - (2.0f * mouse_y) / SCR_HEIGHT;
        float z = 1.0f;
        VecMat::vec3 ray_nds = VecMat::vec3(x, y, z);

        //4d Homogeneous Clip Coordinates
//        vec4 ray_clip = vec4(ray_nds.xy, -1.0, 1.0);
    }
}
