// gcc VM_init.c -c -o VM_init.o

#include "VM_init.h"

extern GLfloat xrot;   // x rotation
extern GLfloat yrot;   // y rotation
extern GLfloat z; 
extern GLfloat mouvementx;
extern GLfloat mouvementz;

void VM_init()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f,0.0f,z);

    glRotatef(xrot,1.0f,0.0f,0.0f);
    glRotatef(yrot,0.0f,1.0f,0.0f);

}

