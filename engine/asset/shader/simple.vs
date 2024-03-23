#version 330 core
layout (location = 0) in vec3 aPos;

// uniform mat4 uViewProjection;

out vec3 vPosition;
void main() {
    vPosition = aPos;
    // gl_Position = uViewProjection * vec4(aPos, 1.0);
    gl_Position = vec4(aPos, 1.0);
}