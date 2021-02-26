#include <GL/glut.h>
#include <cmath>
GLfloat pi = 3.141592654, xRot = 0.0, yRot = 0.0, zRot = 0.0;
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	glRotatef(zRot, 0.0f, 0.0f, 1.0f);
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINE_STRIP);
	double r = 0;
	for (GLfloat az = 0, a = 0; az <= pi / 2; az += pi / 800, a += pi / 20) {
		GLfloat z = cos(az) * 400;
		r = sqrt(pow(400, 2) - pow(z, 2));
		glVertex3f(r * cos(a), r * sin(a), z);
	}
	for (GLfloat az = pi / 2, a = 0; az >= 0; az -= pi / 800, a += pi / 20) {
		GLfloat z = cos(az) * 400;
		r = sqrt(pow(400, 2) - pow(z, 2));
		glVertex3f(r * cos(a), r * sin(a), -z);
	}
	glEnd();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}
void reshape(GLint w, GLint h) {
	if (h == 0)h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-800.0, 800.0, -800.0, 800.0, -800.0, 800.0);

}
void SpecialKeys(int key, int x, int y) {
	if (key == GLUT_KEY_UP) xRot += 5.0f;
	if (key == GLUT_KEY_DOWN) xRot -= 5.0f;
	if (key == GLUT_KEY_LEFT) yRot -= 5.0f;
	if (key == GLUT_KEY_RIGHT) yRot += 5.0f;
	if (key == GLUT_KEY_F1) zRot -= 5.0f;
	if (key == GLUT_KEY_F2) zRot += 5.0f;
	if (xRot > 356.0f) xRot = 0.0f;
	if (xRot < -1.0f) xRot = 355.0f;
	if (yRot > 356.0f) yRot = 0.0f;
	if (yRot < -1.0f) yRot = 355.0f;
	glutPostRedisplay();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1080, 1080);
	glutCreateWindow("sun");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(SpecialKeys);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}