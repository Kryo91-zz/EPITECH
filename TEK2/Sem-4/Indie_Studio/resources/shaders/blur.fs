#version 330

in vec2 fragTexCoord;
in vec4 fragColor;

uniform sampler2D texture0;

out vec4 finalColor;

uniform int horizontal;


uniform float weight[5] = float[] (0.227027, 0.1945946, 0.1216216, 0.054054, 0.016216);

void main()
{
	vec2 tex_offset = (1.0 / textureSize(texture0, 0)); // gets size of single texel
	vec3 result = texture(texture0, fragTexCoord).rgb * weight[0]; // current fragment's contribution

	if (horizontal == 0)
	{
		for (int i = 1; i < 5; ++i)
		{
			result += texture(texture0, fragTexCoord + vec2(tex_offset.x * i, 0.0)).rgb * weight[i];
			result += texture(texture0, fragTexCoord - vec2(tex_offset.x * i, 0.0)).rgb * weight[i];
		}
	}
	else
	{
		for (int i = 1; i < 5; ++i)
		{
			result += texture(texture0, fragTexCoord + vec2(0.0, tex_offset.y * i)).rgb * weight[i];
			result += texture(texture0, fragTexCoord - vec2(0.0, tex_offset.y * i)).rgb * weight[i];
		}
	}
	finalColor = vec4(result, 1.0);
}


// uniform float offset[3] = float[](0.0, 1.3846153846, 3.2307692308);
// uniform float weight[3] = float[](0.2270270270, 0.3162162162, 0.0702702703);

// void main(void) {
//     vec3 result = texture2D(texture0, vec2(fragTexCoord) / 1024.0).rgb * weight[0];

//     for (int i=1; i<3; i++) {
//         result +=
//             texture2D(texture0, (vec2(fragTexCoord) + vec2(0.0, offset[i])) / 1024.0).rgb
//                 * weight[i];
//         result +=
//             texture2D(texture0, (vec2(fragTexCoord) - vec2(0.0, offset[i])) / 1024.0).rgb
//                 * weight[i];
//     }

//     finalColor = vec4(result, 1.0);
// }