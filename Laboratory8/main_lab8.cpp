#define GLEW_STATIC

#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <cmath>

using namespace std;

void drawHexagon(short axis, short orientation);
void writeText(char* text, float xpos, float ypos);
void display();
void initVBO();
void updateHexagon();
void drawHexagon();
void keyboard(int key, int x, int y);

GLuint VBOid;
float dx = 0.0f;
float dy = 0.0f;


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 900);
    glutCreateWindow("Laboratory 8 | Jed Hizon | AN31");

    glewInit();

    initVBO();

    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);

    glutMainLoop();
}


void drawHexagon() {
    glColor3f(0.25f, 0.2f, 0.75f);

    glBindBuffer(GL_ARRAY_BUFFER, VBOid);
    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, 0);

    glDrawArrays(GL_POLYGON, 0, 6);

    glDisableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}



void updateHexagon() {
    glBindBuffer(GL_ARRAY_BUFFER, VBOid);

    GLfloat* ptr = (GLfloat*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

    if (ptr) {
        for (int i = 0; i < 18; i += 3) {
            ptr[i] += dx;
            ptr[i+1] += dy;
        }
        glUnmapBuffer(GL_ARRAY_BUFFER);
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Reset movement so only moves once per keypress
    dx = 0.0f;
    dy = 0.0f;
}



void initVBO() {
    GLfloat hexagonVerts[] = {
        -0.35,  0.0, 0.0,
        -0.25, -0.25, 0.0,
         0.25, -0.25, 0.0,
         0.35,  0.0, 0.0,
         0.25,  0.25, 0.0,
        -0.25,  0.25, 0.0
    };

    glGenBuffers(1, &VBOid);
    glBindBuffer(GL_ARRAY_BUFFER, VBOid);

    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(hexagonVerts),
        hexagonVerts,
        GL_DYNAMIC_DRAW
    );

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    updateHexagon();
    drawHexagon();
	
	writeText("Jed L. Hizon | AN31", -0.2, 0.45);
	writeText("Lab8 -- VBO Moving", -0.3, 0.35);
	
    glutPostRedisplay();
    glFlush();
}

void keyboard(int key, int x, int y) {
    float speed = 0.02f;

    if (key == GLUT_KEY_LEFT){
    	dx = -speed;
    	cout << key + " PRESSED!" << endl;
	}
    if (key == GLUT_KEY_RIGHT) dx =  speed;
    if (key == GLUT_KEY_UP)    dy =  speed;
    if (key == GLUT_KEY_DOWN)  dy = -speed;

    glutPostRedisplay();
}


void writeText(char* text, float xpos, float ypos){
	glColor3f(0.7, 0.7, 0.7);
	glRasterPos2f(xpos, ypos);
	const char* name = text;
	for(int i=0; name[i] != '\0'; i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, name[i]);
	}
}
