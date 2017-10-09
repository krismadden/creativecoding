#version 120

uniform vec2 u_resolution1;
uniform float u_time1;
float floaty1;

void main(){

    floaty1 = abs(sin(u_time1)) - 0;
    vec2 st = gl_FragCoord.xy/u_resolution1 - floaty1;

    
    float y = pow(st.y,500.0);
    
    vec2 color = vec2(y);
    color.x = pow(cos(color.x), 3);
//    color.x = color.x + .9;
//    color.y = color.y + .25;
    //color.z = color.z + .1;
    gl_FragColor = vec4(color,1, 1.0);
}
