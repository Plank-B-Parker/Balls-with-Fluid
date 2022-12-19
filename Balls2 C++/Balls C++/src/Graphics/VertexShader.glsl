#version 330 core
layout (location = 0) in vec2 aPos; // the position variable has attribute position 0. Triangle vertices.
  
out vec4 vertexColor; // specify a color output to the fragment shader
out vec2 pos;

uniform vec2 centrePos;
uniform float radius;

void main()
{
    gl_Position = vec4(radius*aPos + centrePos, 0, 1.0);
    pos = radius*aPos;
    vertexColor = vec4(0.0, 0.5, 0.0, 1.0); // set the output variable to a dark-red color
}