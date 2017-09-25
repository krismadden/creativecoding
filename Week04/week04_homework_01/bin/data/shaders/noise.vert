#version 120

#pragma include <noise.glsl>

uniform float time;
uniform float u_avgSound;

float avgSound = u_avgSound * 100;
float avgSound_color = u_avgSound * 10;

float turbulence( vec3 p ) {
    
    float w = 100.0;
    float t = -.5;
    
    for (float f = 1.0 ; f <= 10.0 ; f++ ){
        float power = pow( 2.0, f );
        t += abs( pnoise( vec3( power * p ), vec3( 10.0, 10.0, 10.0 ) ) / power );
    }
    
    return t;
    
}

void main(){

	gl_TexCoord[0] = gl_MultiTexCoord0;
	
	//get our current vertex position so we can modify it
    vec4 position = gl_Vertex;//gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
    //vec3 normal = ((gl_NormalMatrix * gl_Normal * -7) * (gl_NormalMatrix * gl_Normal) * -10);
    vec3 normal = (gl_NormalMatrix * gl_Normal * -3);
    
    // get a turbulent 3d noise using the normal, normal to high freq
   // float noise = 50.0 *  -.10 * turbulence( .5 * normal.xyz );
    float noise = 50.0 *  -.20 * turbulence( .9 * normal.xyz );
    // get a 3d noise using the position, low frequency
    float b = 5.0 * pnoise( 0.05 * position.xyz, vec3( 10.0 ) );
    // compose both noises
    //float pct = (sin(time)+1.0)*.5;
    float pct = (cos(avgSound)+1.0)*.4;
    //float displacement = pct *( -20. * noise + b);
    float displacement = pct *( -15 * noise + b);
    
    // move the position along the normal and transform it
    vec3 newPosition = position.xyz + normal * displacement;
    
    //finally set the pos to be that actual position rendered
	gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * vec4(newPosition,1.0);
    
	//modify our color
    //gl_FrontColor =  vec4(normal,1.0);//col;
    //gl_FrontColor =  vec4(normal,avgSound_color);//col;
    
    gl_FrontColor = vec4(normal,avgSound_color);
    
}
