#include <iostream>
#include <GL/glut.h>

using namespace std;

void drawHexagon(short axis, short orientation);
void writeText(char* text, float xpos, float ypos);


void display(){
	drawHexagon(1,1);
	drawHexagon(-1,1);
	
	drawHexagon(1,-1);
	drawHexagon(-1,-1);
	
	writeText("Jed L. Hizon | AN31", -0.2, 0.45);
	writeText("Lab3 -- Using GL_TRIANGLES", -0.3, 0.35);
	
	glFlush();
}

int main(int argc, char** argv){
	
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 900);
	glutCreateWindow("Laboratory 3 | Jed Hizon | AN31");
	glutDisplayFunc(display);
	glutMainLoop();

return 0;
}

void drawHexagon(short axis, short orientation){
	glColor3f(0.25, 0.2, 0.75);
	
	glBegin(GL_TRIANGLES);
	glVertex2f(axis*-0.35, orientation*0.0); // p1
	glVertex2f(axis*-0.25, orientation*-0.25); //p2
	glVertex2f(axis*0.25, orientation*-0.25);//p3
	
	glVertex2f(axis*-0.35, orientation*0.0); // p1
	glVertex2f(axis*0.35, orientation*0.0); // p2
	glVertex2f(axis*-0.0, orientation*-0.15); // p3
	glEnd();
}

void writeText(char* text, float xpos, float ypos){
	glColor3f(0.7, 0.7, 0.7);
	glRasterPos2f(xpos, ypos);
	const char* name = text;
	for(int i=0; name[i] != '\0'; i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, name[i]);
	}
}
