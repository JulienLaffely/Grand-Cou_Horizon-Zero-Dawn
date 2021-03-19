// gcc VM_init.c -c -o VM_init.o

#include "VM_init.h"

extern GLfloat xrot;   // x rotation
extern GLfloat yrot;   // y rotation
extern GLfloat z; 
extern GLfloat mouvementx;
extern GLfloat mouvementz;
extern GLfloat pivot;

GLuint camera = 1 ;

void VM_init()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    if(camera==1){
        glTranslatef(0.0f,0.0f,z);
        glRotatef(xrot,1.0f,0.0f,0.0f);
        glRotatef(yrot,0.0f,1.0f,0.0f);
    }
    if(camera==2){
        glTranslatef(-mouvementx,0.0f,z-mouvementz);
        //glRotatef(xrot,1.0f,0.0f,0.0f);
        //glRotatef(yrot,0.0f,1.0f,0.0f);
    }
    if(camera==3){
        glTranslatef(0.0f,0.0f,z);
        glRotatef(xrot,1.0f,0.0f,0.0f);
        glRotatef(yrot,0.0f,1.0f,0.0f);
    }
}

