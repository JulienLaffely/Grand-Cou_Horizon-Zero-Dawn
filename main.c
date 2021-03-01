// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include <math.h>

GLfloat xrot = 0.0f;
GLfloat yrot = 0.0f;
GLfloat z = -30.0f;

void patte_avant(GLfloat x , GLfloat y , GLfloat z){
    glPushMatrix();
    {
        glPushMatrix();
        {
            GLUquadricObj *pObj;
            pObj = gluNewQuadric();
            gluQuadricNormals(pObj, GLU_SMOOTH);
            glRotatef(90.0f,1.0f,0.0f,0.0f);
            glScalef(1.0f,1.0f,2.0f);
            glTranslatef(x,y,z);
            glColor3f(0,0,1);
            gluSphere (pObj, 1.0f, 5, 5);
        }
        glPopMatrix();

        glPushMatrix();
        {
            GLUquadricObj *pObj2;
            pObj2 = gluNewQuadric();
            gluQuadricNormals(pObj2, GLU_SMOOTH);
            glTranslatef(x,y,z-2.0f);
            glColor3f(0,1,0);
            gluSphere (pObj2, 0.5f, 32, 32);
        }
        glPopMatrix();

        glPushMatrix();
        {
            glRotatef(90.0f,1.0f,0.0f,0.0f);
            glScalef(1.0f,1.0f,3.8f);
            glTranslatef(x,y,z+1.1f);
            glColor3f(1,0,0);
            glutSolidCube(1.0f);
        }
        glPopMatrix();

        glPushMatrix();
        {
            GLUquadricObj *boule;
            boule = gluNewQuadric();
            gluQuadricNormals(boule, GLU_SMOOTH);
            glTranslatef(x,y-4.0f,z-2.0f);
            glColor3f(0,1,0);
            gluSphere (boule, 0.5f, 32, 32);
        }
        glPopMatrix();

        glPushMatrix();
        {
            glRotatef(90.0f,1.0f,0.0f,0.0f);
            glScalef(1.0f,1.0f,3.0f);
            glTranslatef(x,y,z+2.6f);
            glColor3f(1,0,0);
            glutSolidCube(1.0f);
        }
        glPopMatrix();

        glColor3f(0,1,0);
        glRotatef(-90.0f,1.0f,0.0f,0.0f);
        glTranslatef(x,y+4.0f,z-9.8f);
        glutSolidCone(1.0f,1.5f,32,32);

    }
    glPopMatrix();
}

void patte_arriere(GLfloat x , GLfloat y , GLfloat z){
    glPushMatrix();
    {

        glPushMatrix();
        {
            GLUquadricObj *pObj;
            pObj = gluNewQuadric();
            gluQuadricNormals(pObj, GLU_SMOOTH);
            glRotatef(90.0f,1.0f,0.0f,0.0f);
            glScalef(1.0f,1.0f,2.0f);
            glTranslatef(x,y,z);
            glColor3f(0,0,1);
            gluSphere (pObj, 1.3f, 3, 3);
        }
        glPopMatrix();

        glPushMatrix();
        {
            GLUquadricObj *pObj2;
            pObj2 = gluNewQuadric();
            gluQuadricNormals(pObj2, GLU_SMOOTH);
            glTranslatef(x,y-5.8f,z+0.8f);
            glColor3f(0,1,0);
            gluSphere (pObj2, 0.5f, 32, 32);
        }
        glPopMatrix();

        glPushMatrix();
        {
            glRotatef(45.0f,1.0f,0.0f,0.0f);
            glScalef(1.0f,1.0f,3.0f);
            glTranslatef(x,y-3.5f,z+1.0f);
            glColor3f(1,0,0);
            glutSolidCube(1.0f);
        }
        glPopMatrix();

        glPushMatrix();
        {
            GLUquadricObj *boule;
            boule = gluNewQuadric();
            gluQuadricNormals(boule, GLU_SMOOTH);
            glTranslatef(x,y-8.4f,z+3.2f);
            glColor3f(0,1,0);
            gluSphere (boule, 0.5f, 32, 32);
        }
        glPopMatrix();

        glPushMatrix();
        {
            glRotatef(90.0f,1.0f,0.0f,0.0f);
            glScalef(1.0f,1.0f,3.0f);
            glTranslatef(x,y+2.5f,z+1.8f);
            glColor3f(1,0,0);
            glutSolidCube(1.0f);
        }
        glPopMatrix();

        glColor3f(0,1,0);
        glRotatef(-90.0f,1.0f,0.0f,0.0f);
        glTranslatef(x,y-6.0f,z-11.0f);
        glutSolidCone(1.0f,1.5f,32,32);

    }
    glPopMatrix();
}

void pattes(){
        patte_avant(-1.6f,-2.0f,0.0f);
        patte_arriere(-1.6f,1.7f,1.0f);
        patte_avant(1.6f,-2.0f,0.0f);
        patte_arriere(1.6f,1.7f,1.0f);
}


void cou(){
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glTranslatef(0,9.0f,-2.0f);
    glRotatef(90.0f,1.0f,0.0f,0.0f);
    glColor3f(0,1,1);
    gluCylinder(pObj,0.8f,0.8f,8.0f,32,32);
    gluDeleteQuadric(pObj);
}

void tete(){
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glTranslatef(0.0f,0.0f,-0.5f);
    glScalef(1.0f,1.0f,45.0f);
    glColor3f(1,0,1);
    gluPartialDisk (pObj, 0.0f, 3.0f, 32, 32, 30, 300);
}

void cou_tete(){
    glPushMatrix();
    {
        cou();
        tete();
    }
    glPopMatrix();
}


void corp(){
    glPushMatrix();
    {
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glRotatef(45.0f,1.0f,0.0f,0.0f);
    glScalef(1.0f,1.0f,-2.0f);
    glColor3f(1,1,0);
    gluSphere (pObj, 2.0f, 5, 5);
    }
    glPopMatrix();
}

GLvoid Modelisation()
{
  VM_init();

  glPushMatrix();
  {
      corp();
      cou_tete();
      pattes();

      glTranslatef(0.0f,-30.0f,0.0f);
      glColor3f(0.5f, 0.35f, 0.05f);
      glScalef(100.0f,0.1f,100.0f);
      glutSolidCube(4);
  }
  glPopMatrix();


  axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
