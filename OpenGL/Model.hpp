//
//  Model.hpp
//  OpenGL
//
//  Created by ifuwo on 2018/11/9.
//  Copyright © 2018 ifuwo. All rights reserved.
//

#ifndef Model_hpp
#define Model_hpp

#include "../Link/Include/assimp/Importer.hpp"
#include "../Link/Include/assimp/scene.h"
#include "../Link/Include/assimp/postprocess.h"
#include <stdio.h>
#include "Mesh.hpp"
#include "std_image.h"

class Model
{
public:
    Model(const GLchar *path);
    void Draw(Shader shader);
private:
    vector<Texture> textures_loaded;    // stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
    vector<Mesh> meshes;
    string directory;
    bool gammaCorrection;

    void loadModel(string path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    vector<Texture> loadMasterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
    unsigned int TextureFromFile(const char *path, const string &directory, bool gamma = false);
};

#endif /* Model_hpp */
