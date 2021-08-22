#version 330 core
out vec4 FragColor;

struct Material {
    sampler2D diffuse;
    sampler2D specular;    
    float shininess;
}; 

struct DirLight {
    vec3 direction;	
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct PointLight {
    vec3 position;
 
    float constant;
    float linear;
    float quadratic;
	
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

#define NR_POINT_LIGHTS 4

in vec3 FragPos;  
in vec3 Normal;  
in vec2 TexCoords;
  
uniform vec3 viewPos;
uniform Material material;
uniform DirLight dirLight;
uniform PointLight pointLights[NR_POINT_LIGHTS];

// function prototypes
vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{
        vec3 norm = normalize(Normal);
        vec3 viewDir = normalize(viewPos - FragPos);
		
		//directional light
		vec3 result = CalcDirLight(dirLight, norm, viewDir);
		//point lights 
		for(int i = 0; i < NR_POINT_LIGHTS; i++)
			result += CalcPointLight(pointLights[i], norm, FragPos, viewDir);    
		FragColor = vec4(result, 1.0);
}
// calculates the color when using a directional light.
vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
 		vec3 lightDir = normalize(-light.direction);
		// diffuse shading
		float diff = max(dot(normal, lightDir), 0.0);
        
        // specular
        vec3 reflectDir = reflect(-lightDir, normal);  
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
        // combine results
		vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
		vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
		vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));
		return (ambient + diffuse + specular);    
}
// calculates the color when using a point light.
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    // combine results
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}

//original code written by Ranju
// #version 330 core
//
// in vec2 TexCoords;
//
// out vec4 color;
//
// uniform sampler2D texture_diffuse1;
//
// void main()
// {
//     color = vec4(texture(texture_diffuse1, TexCoords));
// }

//implemented depth buffer
// #version 330 core

// Outputs colors in RGBA
//out vec4 FragColor;
//
// //****
// out vec4 color;
// uniform sampler2D texture_diffuse1;
//
// // Imports the current position from the Vertex Shader
// in vec3 crntPos;
// // Imports the normal from the Vertex Shader
// in vec3 Normal;
// // Imports the color from the Vertex Shader
// in vec3 color;
// // Imports the texture coordinates from the Vertex Shader
// in vec2 texCoord;
//
//
//
// // Gets the Texture Units from the main function
// uniform sampler2D diffuse0;
// uniform sampler2D specular0;
// // Gets the color of the light from the main function
// uniform vec4 lightColor;
// // Gets the position of the light from the main function
// uniform vec3 lightPos;
// // Gets the position of the camera from the main function
// uniform vec3 camPos;
//
//
// vec4 pointLight()
// {
// 	// used in two variables so I calculate it here to not have to do it twice
// 	vec3 lightVec = lightPos - crntPos;
//
// 	// intensity of light with respect to distance
// 	float dist = length(lightVec);
// 	float a = 3.0;
// 	float b = 0.7;
// 	float inten = 1.0f / (a * dist * dist + b * dist + 1.0f);
//
// 	// ambient lighting
// 	float ambient = 0.20f;
//
// 	// diffuse lighting
// 	vec3 normal = normalize(Normal);
// 	vec3 lightDirection = normalize(lightVec);
// 	float diffuse = max(dot(normal, lightDirection), 0.0f);
//
// 	// specular lighting
// 	float specularLight = 0.50f;
// 	vec3 viewDirection = normalize(camPos - crntPos);
// 	vec3 reflectionDirection = reflect(-lightDirection, normal);
// 	float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 16);
// 	float specular = specAmount * specularLight;
//
// 	return (texture(diffuse0, texCoord) * (diffuse * inten + ambient) + texture(specular0, texCoord).r * specular * inten) * lightColor;
// }
//
// vec4 direcLight()
// {
// 	// ambient lighting
// 	float ambient = 0.20f;
//
// 	// diffuse lighting
// 	vec3 normal = normalize(Normal);
// 	vec3 lightDirection = normalize(vec3(1.0f, 1.0f, 0.0f));
// 	float diffuse = max(dot(normal, lightDirection), 0.0f);
//
// 	// specular lighting
// 	float specularLight = 0.50f;
// 	vec3 viewDirection = normalize(camPos - crntPos);
// 	vec3 reflectionDirection = reflect(-lightDirection, normal);
// 	float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 16);
// 	float specular = specAmount * specularLight;
//
// 	return (texture(diffuse0, texCoord) * (diffuse + ambient) + texture(specular0, texCoord).r * specular) * lightColor;
// }
//
// vec4 spotLight()
// {
// 	// controls how big the area that is lit up is
// 	float outerCone = 0.90f;
// 	float innerCone = 0.95f;
//
// 	// ambient lighting
// 	float ambient = 0.20f;
//
// 	// diffuse lighting
// 	vec3 normal = normalize(Normal);
// 	vec3 lightDirection = normalize(lightPos - crntPos);
// 	float diffuse = max(dot(normal, lightDirection), 0.0f);
//
// 	// specular lighting
// 	float specularLight = 0.50f;
// 	vec3 viewDirection = normalize(camPos - crntPos);
// 	vec3 reflectionDirection = reflect(-lightDirection, normal);
// 	float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 16);
// 	float specular = specAmount * specularLight;
//
// 	// calculates the intensity of the crntPos based on its angle to the center of the light cone
// 	float angle = dot(vec3(0.0f, -1.0f, 0.0f), -lightDirection);
// 	float inten = clamp((angle - outerCone) / (innerCone - outerCone), 0.0f, 1.0f);
//
// 	return (texture(diffuse0, texCoord) * (diffuse * inten + ambient) + texture(specular0, texCoord).r * specular * inten) * lightColor;
// }
//
// float near = 0.1f;
// float far = 100.0f;
//
// float linearizeDepth(float depth)
// {
// 	return (2.0 * near * far) / (far + near - (depth * 2.0 - 1.0) * (far - near));
// }
//
// float logisticDepth(float depth, float steepness = 0.5f, float offset = 5.0f)
// {
// 	float zVal = linearizeDepth(depth);
// 	return (1 / (1 + exp(-steepness * (zVal - offset))));
// }
//
// void main()
// {
// 	// outputs final color
// 	//color = vec4(texture(texture_diffuse1, TexCoords));
// 	float depth = logisticDepth(gl_FragCoord.z);
// 	Color = direcLight() * (1.0f - depth) + vec4(depth * vec3(0.85f, 0.85f, 0.90f), 1.0f);
// }
