#version 330 core
out vec4 FragColor;
  
in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)  
in vec2 pos;

uniform vec2 centrePos;
uniform float radius;
uniform vec2 vel;

void main()
{

  vec4 Blue = vec4(0.0f, 0.0f, 1.0f, 1.0f);
  vec4 Red = vec4(1.0f, 0.0f, 0.0f, 1.0f);
  float t = dot(vel, vel)/(dot(vel, vel) + 1.0f);

	FragColor = Blue +  t * (Red - Blue);
    if(dot(pos,pos) > radius*radius)
		  discard;

    //FragColor = vec4(pos, 0, 0);
} 