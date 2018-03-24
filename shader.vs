#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texcoord;
//layout (location = 2) in vec2 texcoord;

out vec3 ourPosition;
out vec3 ourColor;
out vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(position.x,position.y,position.z, 1.0f);
    //ourColor = color;
	ourPosition = position;
	texCoord = vec2(texcoord.x, 1.0 - texcoord.y);
}