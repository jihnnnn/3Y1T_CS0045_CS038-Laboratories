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
			GLfloat headVertex[] = {
				0.5f + headPosX, 0.5f + headPosY, 0.0f,
				0.5f + headPosX, -0.5 + headPosY, 0.0f,
				-0.5f + headPosX, -0.5f + headPosY, 0.0f,
				-0.5f + headPosX, 0.5f + headPosY, 0.0f
			};
			
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(3, GL_FLOAT, 0, headVertex);
			glColor3f(0.0, 0.5, 0.0);
			glDrawArrays(GL_QUADS, 0, 4);
			glDisableClientState(GL_VERTEX_ARRAY);	
		}
		
		
		
		void drawEyes(){
			GLfloat eyeVertex[] = {
				-0.35 + headPosX, 0.35 + headPosY, 0.0f, // p1
				-0.35 + headPosX, 0.1 + headPosY, 0.0f, //p2
				-0.1 + headPosX, 0.1 + headPosY, 0.0f, // p3
				-0.1 + headPosX, 0.35 + headPosY, 0.0f, // p4 
				
				//Right Eye
				0.35 + headPosX, 0.35 + headPosY, 0.0f, // p1
				0.35 + headPosX, 0.1 + headPosY, 0.0f,//p2
				0.1 + headPosX, 0.1 + headPosY, 0.0f, // p3
				0.1 + headPosX, 0.35 + headPosY, 0.0f // p4 
			};
			
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(3, GL_FLOAT, 0, eyeVertex);
			glColor3f(0.0, 0.0, 0.0);
			glDrawArrays(GL_QUADS, 0, 8);
			glDisableClientState(GL_VERTEX_ARRAY);	
		}
		
		void drawPupil(int axis, bool eyeColor){
			if(!eyeColor){
				glColor3f(0.2, 0.2, 0.2);			
			} else {
				glColor3f(0.8, 0.1, 0.1);
			}
			
			GLfloat pupilVertex[] = {
				(-0.2 * axis) + headPosX, 0.2 + headPosY, 0.0f, // p1
				(-0.2 * axis) + headPosX, 0.1 + headPosY, 0.0f, //p2
				(-0.1 * axis) + headPosX, 0.1 + headPosY, 0.0f, // p3
				(-0.1 * axis) + headPosX, 0.2 + headPosY, 0.0f // p4	
			};
			
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(3, GL_FLOAT, 0, pupilVertex);
			glDrawArrays(GL_QUADS, 0, 4);
			glDisableClientState(GL_VERTEX_ARRAY);	
		}
		
		void drawMouth(){
			GLfloat mouthVertex[] = {
				//Left Vertical
				-0.225 + headPosX, -0.1 + headPosY, 0.0f,
				-0.225 + headPosX, -0.45 + headPosY, 0.0f,
				-0.1 + headPosX, -0.45 + headPosY, 0.0f,
				-0.1 + headPosX, -0.1 + headPosY, 0.0f,
				
				//Right Vertical
				0.1 + headPosX, -0.1 + headPosY, 0.0f,
				0.1 + headPosX, -0.45 + headPosY, 0.0f,
				0.225 + headPosX, -0.45 + headPosY, 0.0f,
				0.225 + headPosX, -0.1 + headPosY, 0.0f,
				
				//Middle Square
				-0.1 + headPosX, 0 + headPosY, 0.0f,
				-0.1 + headPosX, -0.3 + headPosY, 0.0f,
				0.1 + headPosX, -0.3 + headPosY, 0.0f,
				0.1 + headPosX, 0 + headPosY, 0.0f
			};
			
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(3, GL_FLOAT, 0, mouthVertex);
			glColor3f(0.0, 0.0, 0.0);
			glDrawArrays(GL_QUADS, 0, 12);
			glDisableClientState(GL_VERTEX_ARRAY);	
		}
		
};

//GLOBAL DECLARATION
Creeper creeper;

int main(int argc, char** argv){
	
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 900);
	glutCreateWindow("Laboratory 6 | Jed Hizon | AN31");
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
	writeText("Lab6 -- CREATING FACE using Vertex Arrays", -0.2, 0.65);
	
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


