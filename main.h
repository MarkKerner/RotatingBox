//
// Created by mark on 3.01.16.
//
#ifndef MAIN_H
#define MAIN_H

#include "inc/SOIL.h"
#include "inc/glew.h"
#include "inc/glfw3.h"
#include "assert.h"

#include "matrix.h"
#include "util.h"


//Calbacks
void keyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods);

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);


//Initializing
GLFWwindow* initGlfwWindow();

void initGlew();

void initCallbacks(GLFWwindow* window);

//Shaders
const GLchar* mainVertexSource =
        "#version 130\n"

                "in vec3 position;"
                "in vec3 color;"
                "in vec2 texcoord;"

                "out vec3 Color;"
                "out vec2 Texcoord;"

                "uniform mat4 transf;"
                "uniform vec3 overrideColor;"

                "void main() {"
                "	Texcoord = texcoord;"
                "	Color = overrideColor * color;"
                "	gl_Position = transf * vec4(position, 1.0);"
                "}";

const GLchar* mainFragmentSource =
        "#version 130\n"
                "in vec3 Color;"
                "in vec2 Texcoord;"
                "out vec4 outColor;"
                "uniform sampler2D texBox;"
                "void main() {"
                "		vec4 texColor = texture(texBox, Texcoord);"
                "		outColor = vec4(Color, 1.0) * texColor;"
                "}";

const GLchar* gridVertexSource =
        "#version 130\n"

                "in vec3 position;"
                "in vec3 color;"

                "out vec3 Color;"

                "uniform mat4 transf;"
                "uniform vec3 overrideColor;"

                "void main() {"
                "	Color = overrideColor * color;"
                "	gl_Position = transf * vec4(position, 1.0);"
                "}";

const GLchar* gridFragmentSource =
        "#version 130\n"
                "in vec3 Color;"
                "out vec4 outColor;"
                "void main() {"
                "		outColor = vec4(Color, 1.0);"
                "}";

const GLfloat boxVertices[] = {
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        -0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

        -0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

        -0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

        0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

        -0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f
};

const GLfloat floorVertices[] = {
        -1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        1.0f, 1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        -1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f
};


GLuint createShader(GLenum shaderType, const GLchar* shaderSrcString);

GLuint createShaderProgram(GLuint vertexShader, GLuint fragmentShader);

void createMainBufferObjects(GLuint boxVao, GLuint floorVao, GLuint mainShaderProgram);

void createMainBufferObject(GLuint vao, const GLfloat* vertices, GLint numVertices, GLuint shaderProgram);

void createGridBufferObject(GLuint vao, const GLfloat* vertices, GLint numVertices, GLuint shaderProgram);

typedef struct TransformationMatrix {
    mat4 model;
    mat4 view;
    mat4 projection;
    mat4 modelView;
    mat4 transf;
} TransformationMatrix;

void setupTransformationMatrix(TransformationMatrix* tm);

void calculateTransformationMatrix(TransformationMatrix* transformationMatrix);

void mainloop(GLFWwindow* window, TransformationMatrix tm, GLuint shaderProgram);

#endif //MAIN_H
