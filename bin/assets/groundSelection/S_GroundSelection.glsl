#vertex
#version 450

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 uv;
layout (location = 2) in vec3 normal;

layout (std140, binding = 0) uniform Matrices
{
  mat4 view;
  mat4 projection;
  mat4 pixel;
  vec3 viewPos;
};

uniform mat4 model;

out VS_OUT
{
  vec2 TexCoords;
} vs_out;

void main()
{
  gl_Position = projection * view * model * vec4(position, 1.0);
  vs_out.TexCoords = uv;
}

#tessControl

#tessEvaluation

#geometry

#fragment
#version 450

layout (location = 0) out vec4 o_Color;

in VS_OUT
{
    vec2 TexCoords;
} fs_in;

layout(binding = 0) uniform sampler2D baseTexture;

void main()
{
  o_Color = texture(baseTexture, fs_in.TexCoords);
}