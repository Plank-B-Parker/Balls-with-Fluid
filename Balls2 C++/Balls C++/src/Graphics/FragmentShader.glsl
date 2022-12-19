#version 330 core
out vec4 FragColor;
  
in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)  
in vec2 pos;

uniform float radius;
uniform vec2 vel;

void main()
{


	FragColor += vec4(0,0,1,1) + (dot(vel,vel))/(dot(vel,vel) + 1) * ( vec4(1,0,0,1) - vec4(0,0,1,1)) ;

    if(dot(pos,pos) > radius*radius)
		discard;

    //FragColor = vec4(pos, 0, 0);
} 