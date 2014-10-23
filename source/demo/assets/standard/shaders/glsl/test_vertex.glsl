attribute vec4 a_vertex;
uniform mat4 u_mvp_matrix;

void main( void )
{
    gl_Position = u_mvp_matrix * a_vertex;
}