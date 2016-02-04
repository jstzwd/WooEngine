#version 450

layout (location = 0) in vec4 position;
layout (location = 1) in vec2 uv;
layout (location = 2) in vec4 color;
layout (location = 3) in float textureNumber;

uniform mat4 pr_matrix;
uniform mat4 vw_matrix=mat4(1.0);
uniform mat4 ml_matrix=mat4(1.0);

out vec4 myPosition;
out vec2 myUV;
out vec4 myColor;
out float myTextureNumber;

void main(){
    gl_Position=pr_matrix*vw_matrix*ml_matrix*position;
	myPosition=ml_matrix*position;
	myUV=uv;
	myColor=color;
	myTextureNumber=textureNumber;
}