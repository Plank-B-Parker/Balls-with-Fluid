#version 330 core
layout (location = 0) in vec2 vertTexCoord;

out vec2 textureCoord;

void main()
{
    gl_Position = vec4(0,0,0,0);
    textureCoord =  vertTexCoord; 
}