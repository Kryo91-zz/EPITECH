#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;

// Output fragment color
out vec4 finalColor;

const float minimum_brightness = 0.7;

float brightness(vec3 color)
{
	const vec3 v = vec3(0.2126, 0.7152, 0.0722);

	return (dot(color, v));
}

void main()
{
	vec3 source = texture(texture0, fragTexCoord).rgb;
	vec3 color = vec3(0.0, 0.0, 0.0);

	if (brightness(source) > minimum_brightness)
		color = source;

	finalColor = vec4(color, 1.0);
}