// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

#include "init.h"
#include "axes.h"
#include "ppm.h"
#include "VM_init.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdbool.h>

GLfloat xrot = 0.0f;
GLfloat yrot = 0.0f;
GLfloat z = -80.0f;

extern GLuint blend;
extern GLuint light;
GLfloat rotation_corp=30.0f;
static float difference;
static int activeblend=1;
// P=Patte AV=AVant AR=ARriere G=Gauche D=Droite

GLfloat angle_PAVG1 = -135.0f ;
GLfloat angle_PAVG2 = 45.0f ;
GLfloat angle_PAVG3 = 45.0f ;

GLfloat angle_PAVD1 = -135.0f ;
GLfloat angle_PAVD2 = 45.0f ;
GLfloat angle_PAVD3 = 45.0f ;

GLfloat angle_PARG1 = -135.0f ;
GLfloat angle_PARG2 = 0.0f ;
GLfloat angle_PARG3 = 45.0f ;

GLfloat angle_PARD1 = -135.0f ;
GLfloat angle_PARD2 = 0.0f ;
GLfloat angle_PARD3 = 45.0f ;

GLfloat mouvementx = 0.0f;
GLfloat mouvementz = 0.0f;
GLfloat hauteur = 11.0f;
GLfloat pencher = 0.0f;
GLfloat pivot = 0.0f;


void patte_avant(GLfloat x , GLfloat y , GLfloat z , GLfloat angle1 ,GLfloat angle2,GLfloat angle3 ){

    glPushMatrix();
    {
            GLUquadricObj *cuisse;
            cuisse = gluNewQuadric();
            gluQuadricNormals(cuisse, GLU_SMOOTH);
            glTranslatef(x,y,z);
            glRotatef(angle1+difference,1.0f,0.0f,0.0f);
            glScalef(1.0f,1.0f,2.0f);
            glColor3f(0,0,1);
            gluSphere (cuisse, 1.0f, 5, 5);

            //ANNULATION
            glScalef(1.0f,1.0f,1.0f/2.0f);
            //


            GLUquadricObj *rotule;
            rotule = gluNewQuadric();
            gluQuadricNormals(rotule, GLU_SMOOTH);
            glTranslatef(0.0f,0.0f,-2.0f);
            glRotatef(-angle1,1.0f,0.0f,0.0f);
            glColor3f(0,1,0);
            gluSphere (rotule, 0.5f, 32, 32);



            glRotatef(angle2,1.0f,0.0f,0.0f);
            glTranslatef(0.0f,0.0f,2.5f);
            glScalef(1.0f,1.0f,4.3f);
            glColor3f(1,0,0);
            glutSolidCube(1.0f);

            //ANNULATION
            glScalef(1.0f,1.0f,1.0f/4.3f);
            //

            GLUquadricObj *rotule2;
            rotule2 = gluNewQuadric();
            gluQuadricNormals(rotule2, GLU_SMOOTH);
            glTranslatef(0.0f,0.0f,2.3f);
            glRotatef(-angle2,1.0f,0.0f,0.0f);
            glColor3f(0,1,0);
            gluSphere (rotule2, 0.5f, 32, 32);

            glRotatef(angle3,1.0f,0.0f,0.0f);
            glTranslatef(0.0f,0.0f,2.5f);
            glScalef(1.0f,1.0f,4.3f);
            glColor3f(1,0,0);
            glutSolidCube(1.0f);

            //ANNULATION
            glScalef(1.0f,1.0f,1.0f/4.3f);
            //

            glColor3f(0,1,0);
            glTranslatef(0.0f,0.0f,2.5f);
            glRotatef(180.0f,1.0f,0.0f,0.0f);
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
        glTranslatef(x,y,z);
        glRotatef(angle1+difference,1.0f,0.0f,0.0f);
        glScalef(1.0f,1.0f,2.0f);
        glColor3f(0,0,1);
        gluSphere (cuisse, 1.3f, 3, 3);

        //ANNULATION
        glScalef(1.0f,1.0f,1.0f/2.0f);
        //

        GLUquadricObj *rotule;
        rotule = gluNewQuadric();
        gluQuadricNormals(rotule, GLU_SMOOTH);
        glTranslatef(0.0f,0.0f,-2.0f);
        glRotatef(-angle1,1.0,0.0f,0.0f);
        glColor3f(0,1,0);
        gluSphere (rotule, 0.5f, 32, 32);

        glRotatef(angle2,1.0f,0.0f,0.0f);
        glTranslatef(0.0f,0.0f,2.0f);
        glScalef(1.0f,1.0f,3.0f);
        glColor3f(1,0,0);
        glutSolidCube(1.0f);

        //ANNULATION
        glScalef(1.0f,1.0f,1.0f/3.0f);
        //

        GLUquadricObj *rotule2;
        rotule2 = gluNewQuadric();
        gluQuadricNormals(rotule2, GLU_SMOOTH);
        glTranslatef(0.0f,0.0f,1.8f);
        glRotatef(-angle2,1.0f,0.0f,0.0f);
        glColor3f(0,1,0);
        gluSphere (rotule2, 0.5f, 32, 32);

        glRotatef(angle3,1.0f,0.0f,0.0f);
        glTranslatef(0.0f,0.0f,2.0f);
        glScalef(1.0f,1.0f,3.0f);
        glColor3f(1,0,0);
        glutSolidCube(1.0f);

        //ANNULATION
        glScalef(1.0f,1.0f,1.0f/3.0f);
        //

        glColor3f(0,1,0);
        glRotatef(180.0f,1.0f,0.0f,0.0f);
        glTranslatef(0.0f,0.0f,-2.0f);
        glutSolidCone(1.0f,1.5f,32,32);

    }
    glPopMatrix();
}

void pattes(){
        patte_avant(-2.1f,0.0f,-3.0f,angle_PAVG1,angle_PAVG2,angle_PAVG3);
        patte_arriere(-2.1f,0.0f,4.0f,angle_PARG1,angle_PARG2,angle_PARG3);
        patte_avant(2.1f,0.0f,-3.0f,angle_PAVD1,angle_PAVD2,angle_PAVD3);
        patte_arriere(2.1f,0.0f,4.0f,angle_PARD1,angle_PARD2,angle_PARD3);
}


void cou(){
    glTranslatef(0,0.0f,-4.0f);
    glRotatef(90.0f-rotation_corp,1.0f,0.0f,0.0f);
    glColor3f(0,1,0);
    glutSolidCube(0.5);
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glTranslatef(0.0f,0.0f,-10.0f);
    glColor3f(0,1,1);
    gluCylinder(pObj,0.8f,0.8f,10.0f,32,32);
    gluDeleteQuadric(pObj);
}

void tete(){

    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
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
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    glTranslatef(mouvementx,hauteur,mouvementz);
    glRotatef(pivot,0.0f,1.0f,0.0f);

    glRotatef(pencher,0.0f,0.0f,1.0f);
    glRotatef(rotation_corp,1.0f,0.0f,0.0f);

    glScalef(1.0f,1.0f,-2.0f);
    glColor3f(1,1,0);
    gluSphere (pObj, 3.0f, 5, 5);

    glScalef(1.0f,1.0f,1.0f/-2.0f);
}

void rocher(){
   // readPpm("rocher.ppm");
    glTranslatef(40.0f,-5.0f,0.0f);
    glScalef(5.0f,5.0f,5.0f);
    glColor3f(0.3f,0.3f,0.3f);
    glutSolidDodecahedron();
}

GLvoid Modelisation()
{
  VM_init();
  glPushMatrix();
  {
      if(activeblend==1){
          blend=switch_blend(blend);
          activeblend=0;
      }
      glPushMatrix();
      {
        rocher();
      }
      glPopMatrix();


      //printf("movx=%f hauteur=%f movz=%f \n",mouvementx, hauteur ,mouvementz );
      difference=45.0f-rotation_corp;
      glTranslatef(0.0f,-10.0f,0.0f);
      glScalef(500.0f,0.1f,500.0f);
      glColor3f(0.0f, 0.6f, 0.2f);
      glutSolidCube(4);
      glScalef(1.0f/500.0f,1.0f/0.1f,1.0f/500.0f);
      glColor3f(0,0,0);
      for(int i = -500 ; i<500 ;i+=10){
      glBegin(GL_LINES);
          glVertex3f(-500, 1 , i);
          glVertex3f(500, 1 , i);
      glEnd();
      glBegin(GL_LINES);
          glVertex3f(i, 1 , -500);
          glVertex3f(i, 1 , 500);
      glEnd();
      }
      glPushMatrix();
      {
      corp();
      cou_tete();
      pattes();
      }
      glPopMatrix();
  }
  glPopMatrix();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
