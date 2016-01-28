#version 450

layout (location=0) out vec4 color;

uniform vec4 colour;
uniform vec2 light_pos;

in vec4 myPosition;
in vec2 myUV;
in vec4 myColor;

uniform sampler2D myTexture;

void main(){
    float intensity=1.0/length(myPosition.xy-light_pos);
	color=myColor*intensity;
	color=texture(myTexture,myUV)*intensity;
	
}