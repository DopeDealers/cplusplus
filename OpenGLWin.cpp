#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string.h>


// window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

GLuint VAO, VBO, shader;

// Vertex Shader
static const char* vShader = "                                      \n\
#version 330                                                        \n\
                                                                    \n\
layout (location = 0) in vec3 pos;                                  \n\
                                                                    \n\
void main()                                                         \n\
{                                                                   \n\
    gl_Position = vec4(0.4 * pos.x, 0.4 * pos.y, pos.z, 1.0);       \n\
}";
// Fragment Shader
static const char* fShader = "                                      \n\
#version 330                                                        \n\
                                                                    \n\
out vec4 colour;                                                    \n\
                                                                    \n\
void main()                                                         \n\
{                                                                   \n\
    colour = vec4(1.0, 0.8, 0.0, 1.0);                              \n\
}";

// Triangle Shader
void createTriangle()
{
    GLfloat vertices[] = {
        -1.0f, -1.0f, 0.0f,
        -1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    };
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    // Bind array
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
    // Unbind array 
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

};

void addShaders(GLuint program, const char* shaderCode, GLenum shaderType) 
{
    GLuint theShader = glCreateShader(shaderType);

    const GLchar* theCode[1];
    theCode[0] = shaderCode;

    GLint codeLength[1];
    codeLength[0] = strlen(shaderCode);

    glShaderSource(theShader, 1, theCode, codeLength);
    glCompileShader(theShader);

    GLint result = 0;
    GLchar shaderLog[1024] = { 0 };

    
    glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
    if (!result)
    {
        glGetShaderInfoLog(theShader, sizeof(shaderLog), NULL, shaderLog);
        printf("Error compile the %d shader: '%s'\n", shaderType, shaderLog);
        return;
    }

    glAttachShader(program, theShader);

}

void compileShaders() 
{
    shader = glCreateProgram();

    if (!shader) {
        printf("Error creating shader\n");
        return;
    }
    addShaders(shader, vShader, GL_VERTEX_SHADER);
    addShaders(shader, fShader, GL_FRAGMENT_SHADER);

    GLint result = 0;
    GLchar shaderLog[1024] = { 0 };

    glLinkProgram(shader);
    glGetProgramiv(shader, GL_LINK_STATUS, &result);
    if (!result)
    {
        glGetProgramInfoLog(shader, sizeof(shaderLog), NULL, shaderLog);
        printf("Error linking shader: '%s'\n", shaderLog);
        return;
    }
    glValidateProgram(shader);
    glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);
    if (!result)
    {
        glGetProgramInfoLog(shader, sizeof(shaderLog), NULL, shaderLog);
        printf("Error validating shader: '%s'\n", shaderLog);
        return;
    }
}

int main()
{
    // Initialize GLFW
    if (!glfwInit()) {
     
        printf("GLFW Init failed.");
        glfwTerminate();
        return 1;
    }

    // Setup GLFW window properties
    // OpenGL Version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // End version
    // OpenGL backwards compatibility check
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // End properties

    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Graphics testing", NULL, NULL);
    if (!mainWindow) {
        printf("GLFWWindow creation failed.");
        glfwTerminate();
        return 1;
    }

    // Get buffer size information
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    // Set GLEW context
    glfwMakeContextCurrent(mainWindow);

    // Allow modern extension features
    glewExperimental = GL_TRUE;

    // Initalize GLEW
    if (glewInit() != GLEW_OK) {
        printf("GLEW Initialization failed");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    // Setup Viewport size
    glViewport(0, 0, bufferWidth, bufferHeight);
    createTriangle();
    compileShaders();

    // Loop until process close
    while (!glfwWindowShouldClose(mainWindow)) {
        // Get and Hanlde UI Events
        glfwPollEvents();

        // Clear window
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader);

        // hehe!
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
 

        glUseProgram(0);

        glfwSwapBuffers(mainWindow);
    }

    return 0;
}
