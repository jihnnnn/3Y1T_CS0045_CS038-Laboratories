#include <iostream>
#include <GL/glut.h>

using namespace std;

void display();
void drawFace();
void writeText(char* text, float xpos, float ypos);
void keyboardInput(unsigned char key, int posX, int posY);
void mouseInput(int button, int state, int x, int y);

class Creeper {
	public:
		float headPosX;
		float headPosY;
		bool leftEyeColor;
		bool rightEyeColor;
		
		Creeper(){
			headPosX = 0.0f;
			headPosY = 0.0f;
			leftEyeColor = false;
			rightEyeColor = false;
		}
		
		void creeperHead(float headPosX, float headPosY, bool leftEyeColor, bool rightEyeColor){
			drawHead();
			drawEyes();
			drawPupil(1, leftEyeColor); //Left Pupil
			drawPupil(-1, rightEyeColor); //Right Pupil
			drawMouth();
		}
	
	private:
		void drawHead(){
			glBegin(GL_QUADS);
			glColor3f(0.0, 0.5, 0.0);
			
			glVertex2f(0.5 + headPosX, 0.5 + headPosY); // p1
			glVertex2f(0.5 + headPosX, -0.5 + headPosY); //p2
			glVertex2f(-0.5 + headPosX, -0.5 + headPosY); // p3
			glVertex2f(-0.5 + headPosX, 0.5 + headPosY); // p4
			
			glEnd();
		}
		
		void drawEyes(){
			glBegin(GL_QUADS);
			glColor3f(0.0, 0.0, 0.0);

			//Left Eye
			glVertex2f(-0.35 + headPosX, 0.35 + headPosY); // p1
			glVertex2f(-0.35 + headPosX, 0.1 + headPosY); //p2
			glVertex2f(-0.1 + headPosX, 0.1 + headPosY); // p3
			glVertex2f(-0.1 + headPosX, 0.35 + headPosY); // p4 
			
			//Right Eye
			glVertex2f(0.35 + headPosX, 0.35 + headPosY); // p1
			glVertex2f(0.35 + headPosX, 0.1 + headPosY); //p2
			glVertex2f(0.1 + headPosX, 0.1 + headPosY); // p3
			glVertex2f(0.1 + headPosX, 0.35 + headPosY); // p4 
			
			glEnd();
		}
		
		void drawPupil(int axis, bool eyeColor){
			glBegin(GL_QUADS);

			if(!eyeColor){
				glColor3f(0.2, 0.2, 0.2);			
			} else {
				glColor3f(0.8, 0.1, 0.1);

			}
			
			glVertex2f((-0.2 * axis) + headPosX, 0.2 + headPosY); // p1
			glVertex2f((-0.2 * axis) + headPosX, 0.1 + headPosY); //p2
			glVertex2f((-0.1 * axis) + headPosX, 0.1 + headPosY); // p3
			glVertex2f((-0.1 * axis) + headPosX, 0.2 + headPosY); // p4
			
			glEnd();
		}
		
		void drawMouth(){
			glBegin(GL_QUADS);
			glColor3f(0,0,0);
			
			//Left Vertical
			glVertex2f(-0.225 + headPosX, -0.1 + headPosY); 
			glVertex2f(-0.225 + headPosX, -0.45 + headPosY);
			glVertex2f(-0.1 + headPosX, -0.45 + headPosY);
			glVertex2f(-0.1 + headPosX, -0.1 + headPosY);
			
			//Right Vertical
			glVertex2f(0.1 + headPosX, -0.1 + headPosY);
			glVertex2f(0.1 + headPosX, -0.45 + headPosY);
			glVertex2f(0.225 + headPosX, -0.45 + headPosY);
			glVertex2f(0.225 + headPosX, -0.1 + headPosY);
			
			//Middle Square
			glVertex2f(-0.1 + headPosX, 0 + headPosY);
			glVertex2f(-0.1 + headPosX, -0.3 + headPosY);
			glVertex2f(0.1 + headPosX, -0.3 + headPosY);
			glVertex2f(0.1 + headPosX, 0 + headPosY);

			glEnd();
		}
		
};

//GLOBAL DECLARATION
Creeper creeper;

int main(int argc, char** argv){
	
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 900);
	glutCreateWindow("Laboratory 5 | Jed Hizon | AN31");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardInput);
	glutMouseFunc(mouseInput);
	glutMainLoop();

	return 0;
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	float headPosX;
	float headPosY;
	bool leftEyeColor;
	bool rightEyeColor;
		
	creeper.creeperHead(creeper.headPosX, creeper.headPosY, creeper.leftEyeColor, creeper.rightEyeColor);
	
	writeText("Jed L. Hizon | AN31", -0.2, 0.7);
	writeText("Lab5 -- CREATING FACE", -0.2, 0.65);
	
	glFlush();
}

void keyboardInput(unsigned char key, int posX, int posY){
	
	cout << "PRESSED KEY: " << key << endl;
	
	switch(key){
	
		case 'a':
			creeper.headPosX -= 0.02f;
			break;
		
		case 'd':
			creeper.headPosX += 0.02f;
			break;
		
		case 'w':
			creeper.headPosY += 0.02f;
			break;
		
		case 's':
			creeper.headPosY -= 0.02f;
			break;
		
		case 27: // 27 = Escape Button
			exit(0);
			break;
		
		default:
			creeper.headPosY = 0.0f;
	}
	
	glutPostRedisplay();
}

void mouseInput(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		cout << "MOUSE BUTTON: LMB" << endl;
		creeper.leftEyeColor = !creeper.leftEyeColor;
	}
	
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
		cout << "MOUSE BUTTON: RMB" << endl;
		creeper.rightEyeColor = !creeper.rightEyeColor;
	}
	glutPostRedisplay();

}

void writeText(char* text, float xpos, float ypos){

	glColor3f(0.7, 0.7, 0.7);
	glRasterPos2f(xpos, ypos);
	const char* name = text;
	for(int i=0; name[i] != '\0'; i++){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, name[i]);
	}
}

