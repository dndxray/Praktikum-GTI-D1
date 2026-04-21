#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

static int shoulder = 0, elbow = 0;
static int shoulder_y = 0;
// Sudut jari: [Jari][Ruas]
static float fingerAngles[5][2] = { {0,0}, {0,0}, {0,0}, {0,0}, {0,0} };

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void drawFingerPart(float x, float y, float z) {
    glPushMatrix();
    glScalef(x, y, z);
    glutWireCube(1.0);
    glPopMatrix();
}

void drawFullFinger(int fIdx, float x, float y, float z, float spreadAngle) {
    float len = 0.5;   
    float thick = 0.2; 

    glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(spreadAngle, 0.0, 1.0, 0.0); 

        // RUAS 1
        glRotatef(fingerAngles[fIdx][0], 0.0, 0.0, 1.0);
        glTranslatef(len/2.0, 0.0, 0.0);
        drawFingerPart(len, thick, thick);

        //RUAS 2 
        glTranslatef(len/2.0, 0.0, 0.0); 
        glRotatef(fingerAngles[fIdx][1], 0.0, 0.0, 1.0);
        glTranslatef(len/2.0, 0.0, 0.0);
        drawFingerPart(len, thick, thick);
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        
        // -shoulder
        glTranslatef(-1.0, 0.0, 0.0);
        glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0);
        glRotatef((GLfloat) shoulder_y, 0.0, 1.0, 0.0);
        glTranslatef(1.0, 0.0, 0.0); 

        glPushMatrix(); 
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix(); 

        // elbow
        glTranslatef(1.0, 0.0, 0.0); 
        glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0); 

        glPushMatrix(); 
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix(); 
        
        float tip = 1.0;

// JEMPOL
glPushMatrix();
  
    glTranslatef(tip - 0.2, -0.10, 0.45);
    glRotatef((GLfloat) fingerAngles[0][0], 0.0, 0.0, 1.0); 
    glTranslatef(0.25, 0.0, 0.0);
    glPushMatrix();
        glScalef(0.5, 0.2, 0.2);
        glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.25, 0.0, 0.0);
    glRotatef((GLfloat) fingerAngles[0][1], 0.0, 0.0, 1.0); 
    glTranslatef(0.25, 0.0, 0.0); 
    glPushMatrix();
        glScalef(0.5, 0.2, 0.2);
        glutWireCube(1.0);
    glPopMatrix();
glPopMatrix();

//  TELUNJUK
glPushMatrix();
    glTranslatef(tip, 0.0, 0.25);
    glRotatef((GLfloat) fingerAngles[1][0], 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.0);
   
    glPushMatrix();
        glScalef(0.5, 0.2, 0.2);
        glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.25, 0.0, 0.0);
    glRotatef((GLfloat) fingerAngles[1][1], 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.0);
    glPushMatrix();
        glScalef(0.5, 0.2, 0.2);
        glutWireCube(1.0);
    glPopMatrix();
glPopMatrix();

// JARI TENGAH 
glPushMatrix();
    glTranslatef(tip, 0.0, 0.0); 
    glRotatef((GLfloat) fingerAngles[2][0], 0.0, 0.0, 1.0);
    glTranslatef(0.3, 0.0, 0.0); 
    glPushMatrix();
        glScalef(0.6, 0.2, 0.2); 
        glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.3, 0.0, 0.0);
    glRotatef((GLfloat) fingerAngles[2][1], 0.0, 0.0, 1.0);
    glTranslatef(0.3, 0.0, 0.0);
    glPushMatrix();
        glScalef(0.6, 0.2, 0.2);
        glutWireCube(1.0);
    glPopMatrix();
glPopMatrix();

// JARI MANIS 
glPushMatrix();
    glTranslatef(tip, 0.0, -0.25);
    glRotatef((GLfloat) fingerAngles[3][0], 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.0);
    glPushMatrix();
        glScalef(0.5, 0.2, 0.2);
        glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.25, 0.0, 0.0);
    glRotatef((GLfloat) fingerAngles[3][1], 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.0);
    glPushMatrix();
        glScalef(0.5, 0.2, 0.2);
        glutWireCube(1.0);
    glPopMatrix();
glPopMatrix();

// KELINGKING
glPushMatrix();
    glTranslatef(tip, 0.0, -0.45);
    glRotatef((GLfloat) fingerAngles[4][0], 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    glPushMatrix();
        glScalef(0.4, 0.18, 0.18); 
        glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.2, 0.0, 0.0);
    glRotatef((GLfloat) fingerAngles[4][1], 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    glPushMatrix();
        glScalef(0.4, 0.18, 0.18);
        glutWireCube(1.0);
    glPopMatrix();
glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION); 
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();
    glTranslatef (0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    float maxFold = 140.0; 
    
    switch (key) {
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5) % 360; break;
        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5) % 360; break;

        // Kontrol Menekuk 
        case '1': for(int i=0; i<2; i++) { 
			fingerAngles[0][i] += 10.0; 
			if(fingerAngles[0][i] > maxFold) 
			fingerAngles[0][i] = maxFold; } break;
        case '2': for(int i=0; i<2; i++) { fingerAngles[1][i] += 10.0; if(fingerAngles[1][i] > maxFold) fingerAngles[1][i] = maxFold; } break;
        case '3': for(int i=0; i<2; i++) { fingerAngles[2][i] += 10.0; if(fingerAngles[2][i] > maxFold) fingerAngles[2][i] = maxFold; } break;
        case '4': for(int i=0; i<2; i++) { fingerAngles[3][i] += 10.0; if(fingerAngles[3][i] > maxFold) fingerAngles[3][i] = maxFold; } break;
        case '5': for(int i=0; i<2; i++) { fingerAngles[4][i] += 10.0; if(fingerAngles[4][i] > maxFold) fingerAngles[4][i] = maxFold; } break;

        // Kontrol Meluruskan 
        case 'q': for(int i=0; i<2; i++) { fingerAngles[0][i] -= 10.0; if(fingerAngles[0][i] < 0) fingerAngles[0][i] = 0; } break;
        case 'w': for(int i=0; i<2; i++) { fingerAngles[1][i] -= 10.0; if(fingerAngles[1][i] < 0) fingerAngles[1][i] = 0; } break;
        case 'r': for(int i=0; i<2; i++) { fingerAngles[2][i] -= 10.0; if(fingerAngles[2][i] < 0) fingerAngles[2][i] = 0; } break;
        case 't': for(int i=0; i<2; i++) { fingerAngles[3][i] -= 10.0; if(fingerAngles[3][i] < 0) fingerAngles[3][i] = 0; } break;
        case 'y': for(int i=0; i<2; i++) { fingerAngles[4][i] -= 10.0; if(fingerAngles[4][i] < 0) fingerAngles[4][i] = 0; } break;

        case 'R': // Reset All
            for(int i=0; i<5; i++) for(int j=0; j<2; j++) fingerAngles[i][j] = 0;
            break;

		case 'z': shoulder_y = (shoulder_y + 5) % 360; break;
		case 'Z': shoulder_y = (shoulder_y - 5) % 360; break;
        case 27: exit(0); break;
    }
    glutPostRedisplay(); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("tugas 03");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

