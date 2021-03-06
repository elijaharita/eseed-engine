#version 450

layout (location = 0) in vec2 position;
layout (location = 1) in vec3 color;

layout (location = 0) out vec3 vertColor;
layout (location = 1) out vec2 vertPosition;

void main() {
    vertPosition = position;
    gl_Position = vec4(position, 0.0, 1.0);
    vertColor = color;
}