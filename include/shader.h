#ifndef SHADER_H
#define SHADER_H

#include "utilities.h"

class Shader {
private:
    GLuint programID;
public:
    Shader() {
        programID = 0;
    }
    ~Shader() {
        if (programID) glDeleteProgram(programID);
    }
    void use();
    void setBool(const string &name, bool value);
    void setInt(const string &name, int32_t value);
    void setFloat(const string &name, float value);
    void setVec2(const string &name, const vec2 &value);
    void setVec2(const string &name, float x, float y);
    void setVec3(const string &name, const vec3 &value);
    void setVec3(const string &name, float x, float y, float z);
    void setVec4(const string &name, const vec4 &value);
    void setVec4(const string &name, float x, float y, float z, float w);
    void setMat2(const string &name, const mat2 &mat);
    void setMat3(const string &name, const mat3 &mat);
    void setMat4(const string &name, const mat4 &mat);
    bool loadFromFile(string vertexShaderPath, string fragmentShaderPath, string geometryShaderPath = "");
    bool loadFromString(string vertexShaderCode, string fragmentShaderCode, string geometryShaderCode = "");
};

extern const string meshVertexShaderCode;

extern const string meshFragmentShaderCode;

extern const string depthVertexShaderCode;

extern const string depthFragmentShaderCode;

extern const string depthGeometryShaderCode;

extern const string skyboxVertexShaderCode;

extern const string skyboxFragmentShaderCode;

#endif
