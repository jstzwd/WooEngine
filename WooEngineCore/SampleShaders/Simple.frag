#version 450

layout (location=0) out vec4 color;

uniform vec4 colour;
uniform vec2 light_pos;

in vec4 myPosition;
in vec2 myUV;
in vec4 myColor;
in float myTextureNumber;

uniform sampler2D myTextures[32];

void main(){
    float intensity=1.0/length(myPosition.xy-light_pos);
	vec4 baseColor=myColor;
	if(myTextureNumber>0){
	    int number=int(myTextureNumber-0.5);
		baseColor=myColor*texture(myTextures[number],myUV);
	}
	color=baseColor*intensity;
}