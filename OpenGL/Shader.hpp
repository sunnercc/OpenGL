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
};

#endif /* Shader_hpp */
