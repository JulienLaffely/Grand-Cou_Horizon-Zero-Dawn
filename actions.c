#include "touches.h"
#include "actions.h"
#include <stdio.h>
#include <GL/glut.h>

extern GLfloat xrot;   
extern GLfloat yrot; 
extern GLfloat z;
extern GLuint blend;
extern GLuint light;


extern GLfloat angle_PAVG1 ;
extern GLfloat angle_PAVG2 ;
extern GLfloat angle_PAVG3 ;

extern GLfloat angle_PAVD1 ;
extern GLfloat angle_PAVD2 ;
extern GLfloat angle_PAVD3 ;

extern GLfloat angle_PARG1 ;
extern GLfloat angle_PARG2 ;
extern GLfloat angle_PARG3 ;

extern GLfloat angle_PARD1 ;
extern GLfloat angle_PARD2 ;
extern GLfloat angle_PARD3 ;




void touche_special(int touche, int x, int y) 
{
	switch (touche) {    
	case GLUT_KEY_PAGE_UP:
                z++;
		break;
	case GLUT_KEY_PAGE_DOWN:
                z--;
		break;
	case GLUT_KEY_UP:
                xrot += 10;
		break;
	case GLUT_KEY_DOWN:
		xrot -= 10;
		break;
	case GLUT_KEY_LEFT:
		yrot -= 10;
		break;
	case GLUT_KEY_RIGHT:
		yrot += 10;
		break;
    }	
}


void touche_pressee(unsigned char key, int x, int y) 
{
    usleep(100);

  switch (key) {    
    case ESCAPE: 
      exit(1);                   	
      break; 

    case ESPACE:
      xrot = 0.0f;
      yrot = 0.0f;
      break;

    case TOUCHE_MIN_B: 
    case TOUCHE_MAJ_B: 
     blend =  switch_blend(blend);
      break;

    case TOUCHE_MIN_L: 
    case TOUCHE_MAJ_L: 
      light = switch_light(light);
      break;

    case TOUCHE_MIN_Z:
    case TOUCHE_MAJ_Z:
        if(angle_PARG1<135.0f)angle_PARG1+=1.0f;

        break;

    case TOUCHE_MIN_Q:
    case TOUCHE_MAJ_Q:

        break;

    case TOUCHE_MIN_S:
    case TOUCHE_MAJ_S:

        break;

    case TOUCHE_MIN_D:
    case TOUCHE_MAJ_D:

        break;
      
    }	
}


