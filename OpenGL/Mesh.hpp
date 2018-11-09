//
//  Mesh.hpp
//  OpenGL
//
//  Created by ifuwo on 2018/11/9.
//  Copyright © 2018 ifuwo. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include <stdio.h>
#include "Shader.hpp"
#include <string>
#include <vector>

using namespace std;

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    glm::vec3 Tangent;
    glm::vec3 Bitangent;
};

struct Texture {
    unsigned int id;
    string type;
    string path;
};

class Mesh {
public:
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    vector<Texture> textures;
    unsigned int VAO;
    
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> texture);
    void Draw(Shader shader);
private:
    unsigned int VBO, EBO;
    
    void setupMesh();
};




#endif /* Mesh_hpp */
