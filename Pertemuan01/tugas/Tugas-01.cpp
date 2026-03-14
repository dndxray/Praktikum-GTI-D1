#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>


void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	glColor3f(1.0f, 0.0f, 0.0f); // warna titik
	glLineWidth(5.0f);
	glBegin(GL_LINES);
    float x = 0.0f, y = 0.0f;
    float delta = 0.01f; // jarak

    glVertex2f(x, y);
    glVertex2f(x + delta, y + delta);

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("nomor 1");

    glClearColor(1.0f, 0.8f, 0.9f, 1.0f); // warna bacground
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------//
//void drawCircle(float x, float y, float radius, int segments) {
//    glBegin(GL_TRIANGLE_FAN);
//        glVertex2f(x, y); // Pusat
//        for (int i = 0; i <= segments; i++) {
//            float angle = 2.0f * 3.1415926f * (float)i / (float)segments;
//            glVertex2f(x + (cos(angle) * radius), y + (sin(angle) * radius));
//        }
//    glEnd();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    //(GL_QUADS)
//    glColor3f(1.0f, 1.0f, 0.6f); // Abu-abu muda
//    glBegin(GL_QUADS);
//        glVertex2f(-0.5f, -0.5f); // Kiri Bawah
//        glVertex2f( 0.5f, -0.5f); // Kanan Bawah
//        glVertex2f( 0.5f,  0.2f); // Kanan Atas
//        glVertex2f(-0.5f,  0.2f); // Kiri Atas
//    glEnd();
//
//    // (GL_TRIANGLE_STRIP)
//    glColor3f(0.8f, 0.2f, 0.2f); // Merah Bata
//    glBegin(GL_TRIANGLE_STRIP);
//        glVertex2f(-0.6f,  0.2f); // Titik 1 (Kiri Luar)
//        glVertex2f( 0.0f,  0.6f); // Titik 2 (Puncak)
//        glVertex2f( 0.6f,  0.2f); // Titik 3 (Kanan Luar)
//    glEnd();
//
//	// (GL_TRIANGLE_FAN) 
//    glColor3f(1.0f, 1.0f, 0.0f); // matahari
//    drawCircle(-0.75f, 0.75f, 0.15f, 30); 
//    
//    // (GL_QUAD_STRIP)
//	glColor3f(0.2f, 0.2f, 0.2f);    glBegin(GL_QUAD_STRIP);
//	glVertex2f(-0.3f, -1.7f);  // Kiri atas, lebih lebar
//	glVertex2f( 0.3f, -1.7f);  // Kanan atas, lebih lebar
//    glVertex2f(-0.1f, -0.5f); // Kiri Bawah Pintu
//    glVertex2f( 0.1f, -0.5f); // Kanan Bawah Pintu
//    glEnd();
//
//	// (GL_LINE_LOOP)
//    glColor3f(0.0f, 0.5f, 0.0f); // warna pintu
//    glLineWidth(3.0f); // Kusennya dibuat agak tebal
//    
//    glBegin(GL_LINE_LOOP);
//        glVertex2f(-0.1f, -0.5f); // Kiri Bawah Pintu
//        glVertex2f( 0.1f, -0.5f); // Kanan Bawah Pintu
//        glVertex2f( 0.1f,  0.0f); // Kanan Atas Pintu
//        glVertex2f(-0.1f,  0.0f); // Kiri Atas Pintu
//    glEnd();
//
//    // (GL_POINTS)
//    glColor3f(0.0f, 0.5f, 0.0f); // Hitam
//    glPointSize(5.0f);
//    glBegin(GL_POINTS);
//        glVertex2f(0.06f, -0.25f); // Posisi gagang pintu
//    glEnd();
//
//
//    // (GL_LINE_STRIP)
//    glColor3f(0.0f, 0.0f, 0.0f); // Hitam
//    glBegin(GL_LINE_STRIP);
//        glVertex2f(-0.3f, 0.0f);
//		glVertex2f(-0.2f, 0.1f);
//        glVertex2f(-0.2f, 0.0f);
//    glEnd();
//    glFlush();
//    
//    glColor3f(0.0f, 0.0f, 0.0f); // Hitam
//    glBegin(GL_LINE_STRIP);
//        glVertex2f(0.3f, 0.0f);
//		glVertex2f(0.2f, 0.1f);
//        glVertex2f(0.2f, 0.0f);
//    glEnd();
//    glFlush();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitWindowSize(600, 600);
//    glutCreateWindow("nomor 2");
//
//    glClearColor(0.6f, 0.8f, 1.0f, 1.0f); // background biru muda
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}

//--------------------------------------------------------------------------------------------------------------------------------------------------------//

//void drawCreativeSquare(float x, float y, float size, float r, float g, float b) {
//    glColor3f(r, g, b);
//    glBegin(GL_QUADS);
//        glVertex2f(x, y);
//        glVertex2f(x + size, y);
//        glVertex2f(x + size, y + size);
//        glVertex2f(x, y + size);
//    glEnd();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    float s = 0.15f; // ukuran kotak
//
//    // --- Huruf I ---
//    drawCreativeSquare(-0.8f, 0.5f, s, 0.81f, 0.87f, 0.91f); 
//    drawCreativeSquare(-0.65f, 0.5f, s, 0.66f, 0.62f, 0.58f); // tengah atas
//    drawCreativeSquare(-0.5f, 0.5f, s, 0.98f, 0.97f, 0.88f);
//    drawCreativeSquare(-0.65f, 0.35f, s, 0.24f, 0.22f, 0.20f);
//    
//    drawCreativeSquare(-0.65f, 0.2f, s, 0.81f, 0.87f, 0.91f);
//    drawCreativeSquare(-0.65f, 0.05f, s, 0.66f, 0.62f, 0.58f);
//    drawCreativeSquare(-0.8f, -0.1f, s, 0.98f, 0.97f, 0.88f);
//    drawCreativeSquare(-0.65f, -0.1f, s, 0.24f, 0.22f, 0.20f);
//    
//    drawCreativeSquare(-0.5f, -0.1f, s, 0.81f, 0.87f, 0.91f);
//
//    // --- Huruf F ---
//	drawCreativeSquare(0.0f, 0.5f, s, 0.81f, 0.87f, 0.91f);
//    drawCreativeSquare(0.15f, 0.5f, s,0.66f, 0.62f, 0.58f);
//    drawCreativeSquare(0.3f, 0.5f, s,0.98f, 0.97f, 0.88f);
//    drawCreativeSquare(0.0f, 0.35f, s, 0.24f, 0.22f, 0.20f);
//    
//    drawCreativeSquare(0.0f, 0.2f, s, 0.81f, 0.87f, 0.91f);    
//    drawCreativeSquare(0.0f, 0.05f, s, 0.66f, 0.62f, 0.58f); // biru
//    drawCreativeSquare(0.0f, -0.10f, s,0.98f, 0.97f, 0.88f); //oren 
//    drawCreativeSquare(0.15f, 0.2f, s,0.24f, 0.22f, 0.20f); // abu abu
//
//    glFlush();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("nomor 3");
//
//    glClearColor(1.0f, 0.8f, 0.9f, 1.0f);
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}
