#version 120

varying vec2 texCoord0;

uniform sampler2D diffuse;

void main()
{
	// Texture is resolution-independent
	gl_FragColor = texture2D(diffuse, texCoord0);
}