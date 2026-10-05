#version 450
layout(push_constant) uniform Fill { vec4 rgba; } fill;
layout(location = 0) out vec4 color;
void main() { color = fill.rgba; }
