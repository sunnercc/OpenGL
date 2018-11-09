//
//  main.cpp
//  OpenGL
//
//  Created by ifuwo on 2018/11/6.
//  Copyright © 2018 ifuwo. All rights reserved.
//

#include <iostream>

#include "Shader.hpp"
#include "../Link/Include/GLFW/glfw3.h"
#include <math.h>
#include "std_image.h"
#include "../Link/Include/glm/glm.hpp"
#include "../Link/Include/glm/gtc/matrix_transform.hpp"
#include "../Link/Include/glm/gtc/type_ptr.hpp"
#include "Model.hpp"


const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow * window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

int main(int argc, const char * argv[]) {
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "learn open gl", NULL, NULL);
    if (window == NULL) {
        std::cout << "failed to create glfw window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "failed to initialize glad" << std::endl;
        return -1;
    }
    
    glEnable(GL_DEPTH_TEST);
    
    Shader ourShader("/Users/ifuwo/github/OpenGL/OpenGL/shaders/model.vs",
                     "/Users/ifuwo/github/OpenGL/OpenGL/shaders/model.fs");
    Model ourModel("/Users/ifuwo/github/OpenGL/OpenGL/nanosuit/nanosuit.obj");
    
    while (!glfwWindowShouldClose(window)) {
        // 输入
        processInput(window);
        // 清空颜色缓冲
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ourShader.use();
        
        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view;
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -4.8f));
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);
        
        // render the loaded model
        glm::mat4 model;
        model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // translate it down so it's at the center of the scene
        model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));    // it's a bit too big for our scene, so scale it down
        model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        ourShader.setMat4("model", model);
        ourModel.Draw(ourShader);

        
        // 交换缓冲并查询IO事件
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}


