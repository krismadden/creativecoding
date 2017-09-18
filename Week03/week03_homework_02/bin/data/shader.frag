#version 120

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_smoothX;
uniform float u_smoothY;

void main(){
//    vec2 st = gl_FragCoord.xy / 1024.0;
//    
//    //gl_FragColor = vec4(1.0,0.4,0.6,1.0);
//    gl_FragColor = vec4(st.x,0.4,0.6,1.0);
    
//gl_FragColor = vec4(st.x,st.y,u_mouse.y/768,u_smoothX/1028);
    
    vec2 st = gl_FragCoord.xy / u_resolution;
    gl_FragColor = vec4(st.x,st.y,u_smoothY/768,u_smoothX/1028);
}
