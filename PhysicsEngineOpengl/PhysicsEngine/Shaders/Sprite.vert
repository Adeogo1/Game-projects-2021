#version 330

// Uniforms for world transform and view-proj
uniform mat4 u_WorldTransform;
uniform mat4 u_ViewProj;

// Attribute 0 is position, 1 is tex coords.
layout(location=0) in vec3 inPosition;
layout(location=1) in vec2 inTexCoord;

out vec2 fragTexCoord;


void main()
{
	vec4 pos = vec4(inPosition, 1.0);
	gl_Position = pos * u_WorldTransform * u_ViewProj;

	fragTexCoord = inTexCoord;
}