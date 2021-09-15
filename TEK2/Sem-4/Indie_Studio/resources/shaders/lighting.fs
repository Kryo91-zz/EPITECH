#version 330

// Input vertex attributes (from vertex shader)
in vec3 fragPosition;
in vec2 fragTexCoord;
in vec4 fragColor;
in vec3 fragNormal;

// Input uniform values
uniform sampler2D texture0;

// Output fragment color
out vec4 finalColor;

// NOTE: Add here your custom variables

#define     MAX_LIGHTS              4
#define     LIGHT_DIRECTIONAL       0
#define     LIGHT_POINT             1

struct MaterialProperty {
	vec3 color;
	int useSampler;
	sampler2D sampler;
};

struct Light {
	int enabled;
	int type;
	vec3 position;
	vec3 target;
	vec4 color;
};

// Input lighting values
uniform Light lights[MAX_LIGHTS];
uniform vec3 viewPos;

vec3 lightColors[] = vec3[] (
	vec3(242.0/255, 255.0/255, 124.0/255),
	vec3(106.0/255, 255.0/255, 255.0/255),
	vec3(255.0/255, 95.0/255, 0.0/255)
);

uvec3 getColor(vec3 color)
{
	return (uvec3(color.r*255, color.g*255, color.b*255));
}

float diffBetweenColors(vec3 c1, vec3 c2)
{
	vec3 c = vec3( abs(c2.x - c1.x), abs(c2.y - c1.y), abs(c2.z - c1.z) );

	return (c.x + c.y + c.z);
}

void main()
{
	// check if color is a light
	vec3 color = texture2D(texture0, fragTexCoord).rgb;
	for (int i = 0 ; i < 3 ; ++i) {
		if ( diffBetweenColors(color, lightColors[i]) < 0.1) {
			finalColor = texture2D(texture0, fragTexCoord);
			return;
		}
	}

	vec3 lightColor = vec3(1.0, 1.0, 1.0);
	const int shininess = 32;
	float ambientStrength = 0.1;
	vec3 ambient = ambientStrength * lightColor;

	vec3 lightPos = lights[0].position;

	// diff
	vec3 norm = normalize(fragNormal);
	vec3 lightDir = normalize(lightPos - fragPosition);

	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;

	// specular
	float specularStrength = 0.4;
	vec3 viewDir = normalize(viewPos - fragPosition);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
	vec3 specular = specularStrength * spec * lightColor;

	vec3 result = (ambient + diffuse + specular);
	finalColor = texture2D(texture0, fragTexCoord) * vec4(result, 1.0);
}

/*
void main()
{
	// Texel color fetching from texture sampler
	vec4 texelColor = texture(texture0, fragTexCoord);
	vec3 lightDot = vec3(0.0);
	vec3 normal = normalize(fragNormal);
	vec3 viewD = normalize(viewPos - fragPosition);
	vec3 specular = vec3(0.0);

	// NOTE: Implement here your fragment shader code

	for (int i = 0; i < MAX_LIGHTS; i++)
	{
		if (lights[i].enabled == 1)
		{
			vec3 light = vec3(0.0);

			if (lights[i].type == LIGHT_DIRECTIONAL)
				light = -normalize(lights[i].target - lights[i].position);

			if (lights[i].type == LIGHT_POINT)
				light = normalize(lights[i].position - fragPosition);

			float NdotL = max(dot(normal, light), 0.0);
			lightDot += lights[i].color.rgb*NdotL;

			float specCo = 0.0;
			if (NdotL > 0.0) specCo = pow(max(0.0, dot(viewD, reflect(-(light), normal))), 16.0); // 16 refers to shine
			specular += specCo;
		}
	}

	finalColor = (texelColor*((colDiffuse + vec4(specular, 1.0))*vec4(lightDot, 1.0)));
	finalColor += texelColor*(ambient/10.0)*colDiffuse;

	// Gamma correction
}
*/
