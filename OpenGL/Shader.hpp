//
//  Shader.hpp
//  OpenGL
//
//  Created by ifuwo on 2018/11/7.
//  Copyright © 2018 ifuwo. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include "../Link/Include/glad/glad.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

#include "../Link/Include/glm/glm.hpp"
#include "../Link/Include/glm/gtc/matrix_transform.hpp"
#include "../Link/Include/glm/gtc/type_ptr.hpp"

class Shader
{
public:
    // 程序id
    unsigned int ID;
    // 构造器读取并构建着色器
    Shader(const GLchar *vertexPath, const GLchar *fragmentPath);
    // 使用/激活程序
    void use();
    // uniform工具函数
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVec2(const std::string &name, const glm::vec2 &value) const;
    void setVec2(const std::string &name, float x, float y) const;
    void setVec3(const std::string &name, const glm::vec3 &value) const;
    void setVec3(const std::string &name, float x, float y, float z) const;
    void setVec4(const std::string &name, const glm::vec4 &value) const;
    void setVec4(const std::string &name, float x, float y, float z, float w) const;
    void setMat2(const std::string &name, const glm::mat2 &mat) const;
    void setMat3(const std::string &name, const glm::mat3 &mat) const;
    void setMat4(const std::string &name, const glm::mat4 &mat) const;
};

#endif /* Shader_hpp */
