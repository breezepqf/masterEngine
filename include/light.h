#ifndef LIGHT_H
#define LIGHT_H

#include "utilities.h"
#include "shader.h"
#include "mesh.h"
#include "scene.h"

class Light : public Mesh {
private:
    vec3 color;
    float nearPlane, farPlane;
    uint32_t shadowResolution, depthMapFBO, depthCubeMap;
    void initDepthMap();
    void deleteDepthMap();
public:
    Light(vec3 color, btDiscreteDynamicsWorld *_dynamicsWorld);
    Light(const Light&);
    ~Light();
    void renderDepthMap(vector<Scene*> scenes, Shader& depthShader);
    void setColor(vec3 _color);
    vec3 getColor();
    uint32_t getDepthMap();
    float getFarPlane();
};

#endif
