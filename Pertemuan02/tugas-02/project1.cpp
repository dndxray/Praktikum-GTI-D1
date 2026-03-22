// #include <GL/glut.h>
// #include <math.h>

// #define PI 3.1415926

// void drawCircleOutline(float x, float y, float radiusX, float radiusY, int segments) {
//     glBegin(GL_LINE_LOOP);
//     for (int i = 0; i < segments; i++) {
//         float theta = 2.0f * PI * i / segments;
//         glVertex2f(x + radiusX * cosf(theta),
//                    y + radiusY * sinf(theta));
//     }
//     glEnd();
// }

// void drawCircleFilled(float x, float y, float radiusX, float radiusY, int segments) {
//     glBegin(GL_POLYGON);
//     for (int i = 0; i < segments; i++) {
//         float theta = 2.0f * PI * i / segments;
//         glVertex2f(x + radiusX * cosf(theta),
//                    y + radiusY * sinf(theta));
//     }
//     glEnd();
// }

// void display() {
//     glClear(GL_COLOR_BUFFER_BIT);

//     // Kiri
//     glPushMatrix();
//     glTranslatef(-0.5, 0.0, 0.0);
//     glColor3f(1, 0, 0);
//     drawCircleOutline(0, 0, 0.3, 0.3, 100);
//     glPopMatrix();

//     // Kanan
//     glPushMatrix();
//     glTranslatef(0.5, 0.0, 0.0);
//     glColor3f(0, 0, 1);
//     drawCircleFilled(0, 0, 0.3, 0.3, 100);
//     glPopMatrix();

//     glFlush();
// }

// void init() {
//     glClearColor(1, 1, 1, 1);
//     gluOrtho2D(-1, 1, -1, 1);
// }

// int main(int argc, char** argv) {
//     glutInit(&argc, argv);
//     glutInitWindowSize(600, 600);
//     glutCreateWindow("nomor 01");

//     init();
//     glutDisplayFunc(display);

//     glutMainLoop();
//     return 0;
// }

// TUGAS MOBIL 2 D---------------------------------------------

#include <GL/glut.h>
#include <math.h>
#include <cstdio>

const float PI = 3.1415926535f;
float carX = -0.8f;        // Posisi horizontal mobil
float carSpeed = 0.005f;    // Kecepatan mobil
bool movingForward = true;  // Arah gerak mobil
float wheelAngle = 0.0f;    // Sudut rotasi roda

// membuat lingkaran/oval
void drawCircle(float x, float y, float radiusX, float radiusY, int segments) {
   glBegin(GL_POLYGON);
   for (int i = 0; i < segments; i++) {
       float theta = 2.0f * PI * float(i) / float(segments);
       glVertex2f(x + radiusX * cosf(theta), y + radiusY * sinf(theta));
   }
   glEnd();
}

//  kotak
void drawRect(float x, float y, float width, float height) {
   glBegin(GL_QUADS);
       glVertex2f(x, y);
       glVertex2f(x + width, y);
       glVertex2f(x + width, y + height);
       glVertex2f(x, y + height);
   glEnd();
}

// membuat awan
void drawCloud(float x, float y, float size) {
   glColor3f(1.0f, 1.0f, 1.0f);
   drawCircle(x + size * 0.6f, y + size * 0.2f, size * 0.7f, size * 0.5f, 20);
   drawCircle(x - size * 0.6f, y + size * 0.2f, size * 0.7f, size * 0.5f, 20);
}

// membuat pohon
void drawTree(float x, float y, float scale) {
   glPushMatrix();
   glTranslatef(x, y, 0.0f);
   glScalef(scale, scale, 1.0f);
   
   // Batang pohon 
   glBegin(GL_QUADS);
       glColor3f(0.5f, 0.25f, 0.05f);
       glVertex2f(-0.04f, 0.0f);
       glColor3f(0.4f, 0.2f, 0.0f);
       glVertex2f(0.04f, 0.0f);
       glColor3f(0.4f, 0.2f, 0.0f);
       glVertex2f(0.04f, 0.45f);
       glColor3f(0.5f, 0.25f, 0.05f);
       glVertex2f(-0.04f, 0.45f);
   glEnd();
   
   // Daun pohon
   glColor3f(0.0f, 0.7f, 0.2f);
   drawCircle(0.0f, 0.55f, 0.18f, 0.18f, 20);
   glColor3f(0.0f, 0.6f, 0.1f);
   drawCircle(0.1f, 0.47f, 0.14f, 0.14f, 20);
   drawCircle(-0.1f, 0.47f, 0.14f, 0.14f, 20);
   glColor3f(0.0f, 0.5f, 0.0f);
   drawCircle(0.14f, 0.4f, 0.12f, 0.12f, 20);
   drawCircle(-0.14f, 0.4f, 0.12f, 0.12f, 20);
   
   glPopMatrix();
}


// membuat jalan raya
void drawRoad() {
   // Jalan raya 
   glBegin(GL_QUADS);
       glColor3f(0.25f, 0.25f, 0.25f);
       glVertex2f(-1.0f, -0.8f);
       glVertex2f(1.0f, -0.8f);
       glColor3f(0.15f, 0.15f, 0.15f);
       glVertex2f(1.0f, -0.45f);
       glVertex2f(-1.0f, -0.45f);
   glEnd();
   
   // Garis tengah jalan (putus-putus)
   glColor3f(1.0f, 1.0f, 0.0f);
   for(float i = -1.0f; i < 1.0f; i += 0.3f) {
       drawRect(i, -0.62f, 0.15f, 0.02f);
   }
   
   // Tepi jalan (garis putih)
   glColor3f(1.0f, 1.0f, 1.0f);
   glLineWidth(2.0f);
   glBegin(GL_LINES);
       glVertex2f(-1.0f, -0.45f);
       glVertex2f(1.0f, -0.45f);
       glVertex2f(-1.0f, -0.8f);
       glVertex2f(1.0f, -0.8f);
   glEnd();
}


// ------------------------------ objek rumah
void drawWindow(float x, float y, float size) {
   // Bingkai Jendela
   glColor3f(0.8f, 0.4f, 0.0f); 
   drawRect(x - 0.01f, y - 0.01f, size + 0.02f, size + 0.02f);
   
   // Kaca Jendela
   glColor3f(0.9f, 0.95f, 1.0f);
   drawRect(x, y, size, size);
   
   // Garis Tengah Jendela 
   glColor3f(0.8f, 0.4f, 0.0f);
   glLineWidth(2.0f);
   glBegin(GL_LINES);
       glVertex2f(x + size/2, y);
       glVertex2f(x + size/2, y + size);
       glVertex2f(x, y + size/2);
       glVertex2f(x + size/2 * 2, y + size/2);
   glEnd();
}

void drawHouse(float x, float y, float scale) {
   glPushMatrix();
   glTranslatef(x, y, 0.0f);
   glScalef(scale, scale, 1.0f);
   
   // 1. Body rumah
   glBegin(GL_QUADS);
       glColor3f(1.0f, 0.8f, 0.0f); 
       glVertex2f(-0.5f, -0.4f);
       glVertex2f(0.5f, -0.4f);
       glVertex2f(0.5f, 0.2f);
       glVertex2f(-0.5f, 0.2f);
   glEnd();
   
   // 2. Atap 
   glBegin(GL_TRIANGLES);
       glColor3f(0.5f, 0.25f, 0.05f);  
       glVertex2f(-0.55f, 0.2f);  
       glVertex2f(0.55f, 0.2f);
       glVertex2f(0.0f, 0.6f);
   glEnd();
   
   // 3. Pintu  
   glColor3f(0.8f, 0.4f, 0.1f);
   drawRect(-0.12f, -0.4f, 0.24f, 0.35f);
   
   // 4. Jendela Kiri & Kanan
   drawWindow(-0.4f, -0.1f, 0.25f); 
   drawWindow(0.2f, -0.1f, 0.25f);  
   
   glPopMatrix();
}

//--------------------------------------------------------------------mobil-----------------------
void drawCar(float x, float y) {
   glPushMatrix();
   glTranslatef(x, y, 0.0f);
   glScalef(0.4f, 0.4f, 1.0f);  
   
   //  BADAN MOBIL
   glColor3ub(31, 107, 161);
   glPushMatrix();
       glTranslatef(-0.02, 0.0, 0);
       glBegin(GL_QUADS);
  		glVertex2f(-0.48f, 0.2f);                    // Kiri bawah
   	glVertex2f(-0.48f + 1.15f, 0.2f);             // Kanan bawah
   	glVertex2f(-0.48f + 1.0f, 0.2f + 0.49f);     // Kanan atas
   	glVertex2f(-0.48f + 0.1f, 0.2f + 0.49f);              // Kiri atas
		glEnd();
       
   	glPopMatrix();
   
   // JENDELA
   glColor3ub(203, 237, 248);
  
   drawRect(-0.4, 0.3, 0.35, 0.25); // Jendela depan
   drawRect(0.1, 0.3, 0.35, 0.25); // Jendela belakang
   glColor3ub(18, 62, 98);
   
   glPushMatrix();
       glTranslatef(0.02, -0.28, 0);
       drawRect(-0.6, 0.0, 1.3, 0.5);  
       // Bagian melengkung
       glTranslatef(0.78, 0.0, 0);
       drawCircle(-0.11, 0.24, 0.15, 0.26, 30);
     
       glTranslatef(-0.5, 0.1, 0);
       drawCircle(-0.8, 0.15, 0.15, 0.26, 30);
    
   glPopMatrix();
   
   // LAMPU
   glColor3ub(255, 235, 130);  
   glPushMatrix();
       glTranslatef(0.72, -0.15, 0);
       drawCircle(0, 0.2, 0.06, 0.1, 50);
   glPopMatrix();
   
   // lingkaran diluar ban
   glColor3ub(240, 240, 240);
   glPushMatrix();
       glTranslatef(-0.3, -0.3, 0);
       drawCircle(0, 0, 0.19, 0.18, 50);
   glPopMatrix();
   
   glPushMatrix();
       glTranslatef(0.45, -0.3, 0);
       drawCircle(0, 0, 0.19, 0.18, 50);
   glPopMatrix();
   
   // roda
   // Roda Belakang
   glPushMatrix();
       glTranslatef(-0.3, -0.35, 0);
       glRotatef(wheelAngle, 0, 0, 1);
       
       glColor3ub(40, 30, 20);
       drawCircle(0, 0, 0.18, 0.18, 50); // Ban
       
       glColor3ub(150, 150, 150);
       drawCircle(0, 0, 0.09, 0.09, 50); // Velg
       
       // Jari-jari roda
       glLineWidth(2.0f);
       glBegin(GL_LINES);
       glColor3ub(100, 100, 100);
       for(int i = 0; i < 8; i++) {
           float rad = i * PI / 4.0f;
           glVertex2f(0.0f, 0.0f);
           glVertex2f(0.15f * cosf(rad), 0.15f * sinf(rad));
       }
       glEnd();
   glPopMatrix();
   
   // Roda Depan
   glPushMatrix();
       glTranslatef(0.45, -0.35, 0);
       glRotatef(wheelAngle, 0, 0, 1);
       
       glColor3ub(40, 30, 20);
       drawCircle(0, 0, 0.18, 0.18, 50); // Ban
       
       glColor3ub(150, 150, 150);
       drawCircle(0, 0, 0.09, 0.09, 50); // Velg
       
       // Jari-jari roda
       glLineWidth(2.0f);
       glBegin(GL_LINES);
       glColor3ub(100, 100, 100);
       for(int i = 0; i < 8; i++) {
           float rad = i * PI / 4.0f;
           glVertex2f(0.0f, 0.0f);
           glVertex2f(0.15f * cosf(rad), 0.15f * sinf(rad));
       }
       glEnd();
   glPopMatrix();
   
   glPopMatrix(); 
   glPopMatrix(); 
}


void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
   
	glBegin(GL_QUADS);
   	// Biru tua di atas
   	glColor3f(0.2f, 0.4f, 0.9f);
   	glVertex2f(-1.0f, 1.0f);
   	glVertex2f(1.0f, 1.0f);
   
   	// Biru muda di bawah
   	glColor3f(0.7f, 0.9f, 1.0f);
   	glVertex2f(1.0f, -0.4f);
   	glVertex2f(-1.0f, -0.4f);
	glEnd();
   
   // Awan
   drawCloud(-0.7f, 0.8f, 0.2f);
   drawCloud(0.2f, 0.85f, 0.25f);
   drawCloud(0.6f, 0.75f, 0.2f);
   drawCloud(-0.2f, 0.7f, 0.18f);
   
	glPushMatrix();
	
	glTranslatef(0.8f, 0.8f, 0.0f);

	//	matahari 	
	glBegin(GL_TRIANGLE_FAN);
   	glColor3f(1.0f, 0.5f, 0.0f); // Oranye
   	glVertex2f(0.0f, 0.0f);
   
   	glColor3f(1.0f, 1.0f, 0.0f); // Kuning
   	for(int i = 0; i <= 360; i += 10) {
       	float rad = i * PI / 180.0f;
       	glVertex2f(0.15f * cosf(rad), 0.15f * sinf(rad));
   	}
   
	glEnd();
	glPopMatrix();
   
   glBegin(GL_QUADS);
       glColor3f(0.3f, 0.7f, 0.2f);
       glVertex2f(-1.0f, -0.4f);
       glVertex2f(1.0f, -0.4f);
       glColor3f(0.1f, 0.5f, 0.1f);
       glVertex2f(1.0f, -0.2f);
       glVertex2f(-1.0f, -0.2f);
   glEnd();
   
   // Jalan
   drawRoad();
   
   // Rumput 
   glBegin(GL_QUADS);
       glColor3f(0.2f, 0.6f, 0.2f);
     
       glColor3f(0.3f, 0.7f, 0.2f);
       glVertex2f(-1.0f, -0.45f);
       glVertex2f(1.0f, -0.45f);
       glVertex2f(1.0f, -0.35f);
       glVertex2f(-1.0f, -0.35f);
   glEnd();
   
   // Pohon
   drawTree(-0.85f, -0.25f, 0.7f);
   drawTree(-0.6f, -0.22f, 0.8f);
   drawTree(0.7f, -0.23f, 0.75f);
   drawTree(0.4f, -0.2f, 0.65f);
   
   // Rumah
   drawHouse(-0.1f, -0.10f, 0.8f);
   
   // pohon di depan rumah
   drawTree(0.55f, -0.27f, 0.65f);
   
   // Mobil	
   drawCar(carX, -0.6f);
   
   // rumuput segitiga
   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.6f, 0.1f); 
   
   float startX = -1.0f;
   float width = 0.2f; // Lebar tiap segitiga
   for(int i = 0; i < 10; i++) {
       float x = startX + (i * width);
       glVertex2f(x, -1.0f);           // Kiri bawah
       glVertex2f(x + width/2, -0.8f); // Puncak rumput
       glVertex2f(x + width, -1.0f);   // Kanan bawah
   }
   glEnd();
   
   glutSwapBuffers();
}

void timer(int) {
   // Update posisi mobil
   if(movingForward) {
       carX += carSpeed;
       if(carX > 0.8f) {
           movingForward = false;
       }
   } else {
       carX -= carSpeed;
       if(carX < -0.8f) {
           movingForward = true;
       }
   }
   
   // Update rotasi roda
   wheelAngle -= 5.0f;
   if(wheelAngle < -360.0f) {
       wheelAngle += 360.0f;
   }
   
   glutPostRedisplay();
   glutTimerFunc(16, timer, 0);
}

void init() {
   glClearColor(0.55f, 0.27f, 0.07f, 1.0f); 
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(1200, 900);
   glutCreateWindow("tugas 02 - mobil 2d");
   
   init();
   glutDisplayFunc(display);
   glutTimerFunc(0, timer, 0);
   
   glutMainLoop();
   return 0;
}
