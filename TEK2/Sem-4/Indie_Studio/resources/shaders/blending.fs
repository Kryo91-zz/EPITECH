#version 430

in vec2 fragTexCoord;
in vec4 fragColor;

layout(location = 0) uniform sampler2D texture0;
layout(location = 1) uniform sampler2D texture1;

out vec4 finalColor;

const float exposure = 1.0;

void main()
{
	vec3 scene = texture(texture0, fragTexCoord).rgb;
	vec3 bloom = texture(texture1, fragTexCoord).rgb;

	vec3 result = clamp(scene + bloom, 0, 255);

	finalColor = vec4(result, 1.0);

}