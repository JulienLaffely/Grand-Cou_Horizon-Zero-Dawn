// gcc init.c -c -o init.o

#include "init.h"

int window; 

extern GLfloat z;
extern GLfloat xrot;   
extern GLfloat yrot; 

GLuint blend = 1;
GLuint light = 1 ;

GLvoid Redimensionne(GLsizei Width, GLsizei Height) {
        glViewport(0, 0, Width, Height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f, (GLdouble)Width/(GLdouble)Height, 1, 300);
        glMatrixMode(GL_MODELVIEW);
}


int notre_init(int argc, char** argv, void (*Modelisation)()) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

        glutInitWindowSize(680, 400);
        glutInitWindowPosition(0, 0);

        glutCreateWindow("Grand Cou");

        glutDisplayFunc(Modelisation);
        glutIdleFunc(Modelisation);

        glutReshapeFunc(&Redimensionne);

        glutKeyboardFunc(&touche_pressee);
        glutSpecialFunc(&touche_special);

        glClearColor(0, 0, 0, 0);
        glShadeModel(GL_SMOOTH);
        glEnable(GL_DEPTH);

        glutMainLoop();

        return 1;
}


