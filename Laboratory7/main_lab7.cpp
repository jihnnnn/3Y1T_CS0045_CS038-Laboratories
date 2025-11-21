#define GLEW_STATIC

#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>

using namespace std;

void drawHexagon(short axis, short orientation);
void writeText(char* text, float xpos, float ypos);


void display(){
	drawHexagon(1,1);
	drawHexagon(-1,-1);
	
	writeText("Jed L. Hizon | AN31", -0.2, 0.45);
	writeText("Lab7 -- Converted to VBO", -0.3, 0.35);
	
	glFlush();
}

int main(int argc, char** argv){
	
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 900);
	glutCreateWindow("Laboratory 7 | Jed Hizon | AN31");
	glutDisplayFunc(display);
	GLenum err = glewInit();
	if (err == GLEW_OK){
		glutMainLoop();
	}

return 0;
}

void drawHexagon(short x, short y){
	glColor3f(0.25, 0.2, 0.75);
	
	GLfloat points_vertices[] = {
		x*-0.35, y*0.0, 0.0f,
		x*-0.25, y*-0.25, 0.0f,
		x*0.25, y*-0.25, 0.0f,
		x*0.35, y*0.0, 0.0f,
	};
	
	GLuint VBOid;
	glGenBuffers(1, &VBOid);
	glBindBuffer(GL_ARRAY_BUFFER, VBOid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*12, points_vertices, GL_STATIC_DRAW);
	
	glEnableClientState(GL_VERTEX_ARRAY);
	
	glVertexPointer(3, GL_FLOAT, 0,0);
	glDrawArrays(GL_POLYGON,0,6);
	
	glDisableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1,&VBOid);
	
}

void writeText(char* text, float xpos, float ypos){
	glColor3f(0.7, 0.7, 0.7);
	glRasterPos2f(xpos, ypos);
	const char* name = text;
	for(int i=0; name[i] != '\0'; i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, name[i]);
	}
}
