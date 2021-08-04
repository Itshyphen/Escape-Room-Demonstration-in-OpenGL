// GLFW - glad
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// GLM Mathemtics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "camera.hpp"
#include "model.hpp"
#include "object.hpp"

#include <iostream>
#include <string>
#include <vector>

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
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

bool opendoor = false;

// camera
Camera camera(VecMat::vec3(0.0f, 5.0f, 20.0f));
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
    "../resources/skybox/front.jpg",
    "../resources/skybox/back.jpg"};

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

    // tell GLFW to capture our mouse
    //once the application has focus, the mouse cursor stays within the center of the window
    //        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    glEnable(GL_DEPTH_TEST);

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
    lightPosition.push_back(VecMat::vec3(0.8, 6, -5.1));
    lightPosition.push_back(VecMat::vec3(-0.8, 6, -5.1));

    lightPosition.push_back(VecMat::vec3(3.55, 2.1, -4.6));
    lightPosition.push_back(VecMat::vec3(0, 40, 0));
}
void visualisation::render::visualise()
{

    initializeGlfw();

    // build and compile shaders
    // -------------------------
    Shader ourShader("../resources/shaders/mainvertex.vs", "../resources/shaders/mainfragment.fs");    //Lightning Shader
    Shader lampShader("../resources/shaders/lightvertex.vs", "../resources/shaders/lightfragment.fs"); //Light Shader
    Shader skyboxShader("../resources/shaders/skybox.vs", "../resources/shaders/skybox.fs");           //CubeMap Shader

    // setLampPosition();
    setLightPosition();

    //initiliaze vertex
    initializeVertex();

    //Get the models
    getModels();

    //load cubemap faces
    Texture::loadCubemap(faces);

    ourShader.Bind();
    ourShader.setInt("material.diffuse", 0);
    ourShader.setInt("material.specular", 1);
    skyboxShader.Bind();
    skyboxShader.setInt("skybox", 0);

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
        ourShader.setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
        ourShader.setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
        ourShader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
        // point light 1
        ourShader.setVec3("pointLights[0].position", lightPosition[0]);
        ourShader.setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
        ourShader.setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
        ourShader.setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
        ourShader.setFloat("pointLights[0].constant", 1.0f);
        ourShader.setFloat("pointLights[0].linear", 0.09);
        ourShader.setFloat("pointLights[0].quadratic", 0.032);
        // point light 2
        ourShader.setVec3("pointLights[1].position", lightPosition[1]);
        ourShader.setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
        ourShader.setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
        ourShader.setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
        ourShader.setFloat("pointLights[1].constant", 1.0f);
        ourShader.setFloat("pointLights[1].linear", 0.09);
        ourShader.setFloat("pointLights[1].quadratic", 0.032);
        // // point light 2
        ourShader.setVec3("pointLights[2].position", lightPosition[2]);
        ourShader.setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
        ourShader.setVec3("pointLights[2].diffuse", 1.0f, 1.0f, 0.5f);
        ourShader.setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
        ourShader.setFloat("pointLights[2].constant", 1.0f);
        ourShader.setFloat("pointLights[2].linear", 0.09);
        ourShader.setFloat("pointLights[2].quadratic", 0.032);
        // // point light 3
        ourShader.setVec3("pointLights[3].position", lightPosition[3]);
        ourShader.setVec3("pointLights[3].ambient", 0.15f, 0.15f, 0.15f);
        ourShader.setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
        ourShader.setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
        ourShader.setFloat("pointLights[3].constant", 0.01f);
        ourShader.setFloat("pointLights[3].linear", 0.0004);
        ourShader.setFloat("pointLights[3].quadratic", 0.0013);

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
            modelObject = VecMat::translate(modelObject, modelPosition[i]); // Translate it down a bit so it's at the center of the scene
            modelObject = VecMat::rotate(modelObject, to_radians((float)modelAngle[i]), VecMat::vec3(0.0f, 1.0f, 0.0f));
            modelObject = VecMat::scale(modelObject, modelScale[i]); // It's a bit too big for our scene, so scale it down
            ourShader.setMat4("model", modelObject);
            models[i].Draw(ourShader);
            cout << "Drawing Objects in the room" << endl;
        }

        //light objects
        for (unsigned int i = 0; i < 2; i++)
        {
            VecMat::mat4 model(1.0);
            model = VecMat::translate(model, lightPosition[i]);
            model = VecMat::rotate(model, to_radians(90.0f), VecMat::vec3(0.0f, 1.0f, 0.0f));
            model = VecMat::scale(model, VecMat::vec3(0.03f, 0.05f, 1.8f)); // a smaller cube
            lampShader.setMat4("model", model);
            //    glm::vec3 ml(model);
            //    glm::mat4 m = glm::translate(camera.Position,ml)
            //    printf("%s\n", (camera.Position).c_str());
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
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
        camera.ProcessKeyboard(UP, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
        camera.ProcessKeyboard(DOWN, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
        opendoor = true;
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
