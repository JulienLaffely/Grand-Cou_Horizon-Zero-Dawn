// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

GLfloat xrot = 0.0f;
GLfloat yrot = 0.0f;
GLfloat z = -30.0f;
static float test = 90.0f ;
// P=Patte AV=AVant AR=ARriere G=Gauche D=Droite

GLfloat angle_PAVG1 = 90.0f ;
GLfloat angle_PAVG2 = 90.0f ;
GLfloat angle_PAVG3 = 90.0f ;

GLfloat angle_PAVD1 = 90.0f ;
GLfloat angle_PAVD2 = 90.0f ;
GLfloat angle_PAVD3 = 90.0f ;

GLfloat angle_PARG1 = 90.0f ;
GLfloat angle_PARG2 = 45.0f ;
GLfloat angle_PARG3 = 90.0f ;

GLfloat angle_PARD1 = 90.0f ;
GLfloat angle_PARD2 = 45.0f ;
GLfloat angle_PARD3 = 90.0f ;


void patte_avant(GLfloat x , GLfloat y , GLfloat z , GLfloat angle1 ,GLfloat angle2,GLfloat angle3 ){

    glPushMatrix();
    {
            GLUquadricObj *cuisse;
            cuisse = gluNewQuadric();
            gluQuadricNormals(cuisse, GLU_SMOOTH);
            glRotatef(angle1,1.0f,0.0f,0.0f);
            glTranslatef(x,y,z);
            glScalef(1.0f,1.0f,2.0f);
            glColor3f(0,0,1);
            gluSphere (cuisse, 1.0f, 5, 5);

            //ANNULATION
            glScalef(1.0f,1.0f,1.0f/2.0f);
            glTranslatef(-x,-y,-z);
            glRotatef(-angle1,1.0f,0.0f,0.0f);
            //


            GLUquadricObj *rotule;
            rotule = gluNewQuadric();
            gluQuadricNormals(rotule, GLU_SMOOTH);
            glTranslatef(x,y,z-2.0f);
            glColor3f(0,1,0);
            gluSphere (rotule, 0.5f, 32, 32);

            //ANNULATION
            glTranslatef(-x,-y,-(z-2.0f));
            //

            glRotatef(angle2,1.0f,0.0f,0.0f);
            glTranslatef(x,y,z+4.0f);
            glScalef(1.0f,1.0f,3.8f);
            glColor3f(1,0,0);
            glutSolidCube(1.0f);

            //ANNULATION
            glScalef(1.0f,1.0f,1.0f/3.8f);
            glTranslatef(-x,-y,-(z+4.0f));
            glRotatef(-angle2,1.0f,0.0f,0.0f);
            //

            GLUquadricObj *rotule2;
            rotule2 = gluNewQuadric();
            gluQuadricNormals(rotule2, GLU_SMOOTH);
            glTranslatef(x,y-4.0f,z-2.0f);
            glColor3f(0,1,0);
            gluSphere (rotule2, 0.5f, 32, 32);

            //ANNULATION
            glTranslatef(-x,-(y-4.0f),-(z-2.0f));
            //

            glRotatef(angle3,1.0f,0.0f,0.0f);
            glTranslatef(x,y,z+7.6f);
            glScalef(1.0f,1.0f,3.0f);
            glColor3f(1,0,0);
            glutSolidCube(1.0f);

            //ANNULATION
            glScalef(1.0f,1.0f,1.0f/3.0f);
            glTranslatef(-x,-y,-(z+7.6f));
            glRotatef(-angle3,1.0f,0.0f,0.0f);
            //

            glColor3f(0,1,0);
            glRotatef(-90.0f,1.0f,0.0f,0.0f);
            glTranslatef(x,y+4.0f,z-9.8f);
            glutSolidCone(1.0f,1.5f,32,32);

    }
    glPopMatrix();
}

void patte_arriere(GLfloat x , GLfloat y , GLfloat z , GLfloat angle1 ,GLfloat angle2,GLfloat angle3 ){

    glPushMatrix();
    {
        GLUquadricObj *cuisse;
        cuisse = gluNewQuadric();
        gluQuadricNormals(cuisse, GLU_SMOOTH);
        glRotatef(angle1,1.0f,0.0f,0.0f);
        glTranslatef(x,y,z+1.0f);
        glScalef(1.0f,1.0f,2.0f);
        glColor3f(0,0,1);
        gluSphere (cuisse, 1.3f, 3, 3);

        //ANNULATION
        glScalef(1.0f,1.0f,1.0f/2.0f);
        glTranslatef(-x,-y,-(z+1.0f));
        glRotatef(-angle1,1.0f,0.0f,0.0f);
        //

        GLUquadricObj *rotule;
        rotule = gluNewQuadric();
        gluQuadricNormals(rotule, GLU_SMOOTH);
        glTranslatef(x,y-5.8f,z+0.8f);
        glColor3f(0,1,0);
        gluSphere (rotule, 0.5f, 32, 32);

        //ANNULATION
        glTranslatef(-x,-(y-5.8f),-(z+0.8f));
        //

        glRotatef(angle2,1.0f,0.0f,0.0f);
        glTranslatef(x,y-3.4f,z+4.8f);
        glScalef(1.0f,1.0f,3.0f);
        glColor3f(1,0,0);
        glutSolidCube(1.0f);

        //ANNULATION
        glScalef(1.0f,1.0f,1.0f/3.0f);
        glTranslatef(-x,-(y-3.4f),-(z+4.8f));
        glRotatef(-angle2,1.0f,0.0f,0.0f);
        //

        GLUquadricObj *rotule2;
        rotule2 = gluNewQuadric();
        gluQuadricNormals(rotule2, GLU_SMOOTH);
        glTranslatef(x,y-8.3f,z+3.1f);
        glColor3f(0,1,0);
        gluSphere (rotule2, 0.5f, 32, 32);

        //ANNULATION
        glTranslatef(-x,-(y-8.3f),-(z+3.1f));
        //

        glRotatef(angle3,1.0f,0.0f,0.0f);
        glTranslatef(x,y+2.5f,z+7.2f);
        glScalef(1.0f,1.0f,3.0f);
        glColor3f(1,0,0);
        glutSolidCube(1.0f);

        //ANNULATION
        glScalef(1.0f,1.0f,1.0f/3.0f);
        glTranslatef(-x,-(y+2.5f),-(z+7.2f));
        glRotatef(-angle3,1.0f,0.0f,0.0f);
        //


        glColor3f(0,1,0);
        glRotatef(-90.0f,1.0f,0.0f,0.0f);
        glTranslatef(x,y-5.9f,z-11.0f);
        glutSolidCone(1.0f,1.5f,32,32);




    }
    glPopMatrix();
}

void pattes(){
        patte_avant(-1.6f,-2.0f,0.0f,angle_PAVG1,angle_PAVG2,angle_PAVG3);
        patte_arriere(-1.6f,1.7f,1.0f,angle_PARG1,angle_PARG2,angle_PARG3);
        patte_avant(1.6f,-2.0f,0.0f,angle_PAVD1,angle_PAVD2,angle_PAVD3);
        patte_arriere(1.6f,1.7f,1.0f,angle_PARD1,angle_PARD2,angle_PARD3);
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
    //glTranslatef(0.0f,0.0f,-0.5f);
    //glScalef(1.0f,1.0f,45.0f);
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
    //glTranslatef(0.0f,0.0f,test);
    //test-=0.5f;
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
      glPushMatrix();
      {
      corp();
      cou_tete();
      pattes();
      }
      glPopMatrix();
      glPushMatrix();
      {
        glTranslatef(0.0f,-30.0f,0.0f);
        glColor3f(0.5f, 0.35f, 0.05f);
        glScalef(100.0f,0.1f,100.0f);
        glutSolidCube(4);
      }
      glPopMatrix();
  }
  glPopMatrix();


  axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
