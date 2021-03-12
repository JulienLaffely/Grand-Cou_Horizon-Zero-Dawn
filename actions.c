#include "touches.h"
#include "actions.h"
#include <stdio.h>
#include <GL/glut.h>
#include <stdbool.h>

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

extern GLfloat mouvementx ;
extern GLfloat mouvementz ;
extern GLfloat rotation_corp ;
extern GLfloat pencher ;
extern GLfloat hauteur;
extern GLfloat pivot;

static char axe[]="-z";


bool syncro = true ;
GLuint patte=0;
GLfloat temps=4.0f;



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
      if(patte==0){

      if((rotation_corp>=24.0f)&&(syncro)){
          if(axe[0]=='-' && axe[1]=='z')mouvementz-=1.0f/temps;
          if(axe[0]=='+' && axe[1]=='z')mouvementz+=1.0f/temps;
          if(axe[0]=='-' && axe[1]=='x')mouvementx-=1.0f/temps;
          if(axe[0]=='+' && axe[1]=='x')mouvementx+=1.0f/temps;

        angle_PAVD1-=5.0f/temps;
        angle_PAVD2-=5.0f/temps;
        angle_PAVD3-=5.0f/temps;

        angle_PARD1-=8.0f/temps;
        angle_PARD2+=8.0f/temps;
        angle_PARD3-=8.0f/temps;

        rotation_corp-=3.0f/temps;
        pencher -=3.0f/temps;

        if(angle_PAVG1<-90.0f){
            angle_PAVG1+=45.0f/temps;
        }
        else if (angle_PAVG2<90.0f){
            angle_PAVG2+=(45.0f/2.0f)/temps;
        }

        if((angle_PARG1<-90.0f)&&(angle_PARG2>-45.0f)){
              angle_PARG1+=15.0f/temps;
              angle_PARG2-=15.0f/temps;
        }

      }else{
          syncro=false;
          if(angle_PAVD1!=-135.0f){
              hauteur-=0.2f/temps;
              if(axe[0]=='-' && axe[1]=='z')mouvementz-=1.0f/temps;
              if(axe[0]=='+' && axe[1]=='z')mouvementz+=1.0f/temps;
              if(axe[0]=='-' && axe[1]=='x')mouvementx-=1.0f/temps;
              if(axe[0]=='+' && axe[1]=='x')mouvementx+=1.0f/temps;
            rotation_corp-=3.0f/temps;
            angle_PAVD1+=5.0f/temps;
            angle_PAVD2+=5.0f/temps;
            angle_PAVD3-=5.0f/temps;
           }else if (rotation_corp!=30){
              if(axe[0]=='-' && axe[1]=='z')mouvementz-=0.5f/temps;
              if(axe[0]=='+' && axe[1]=='z')mouvementz+=0.5f/temps;
              if(axe[0]=='-' && axe[1]=='x')mouvementx-=0.5f/temps;
              if(axe[0]=='+' && axe[1]=='x')mouvementx+=0.5f/temps;
                        rotation_corp+=3.0f/temps;
                        angle_PAVD3+=5.0f/temps;

                        if(hauteur!=15.0f)hauteur+=0.2f/temps;

                        if(pencher!=0.0f)  {
                            pencher +=3.0f/temps;
                            angle_PARD1+=8.0f/temps;
                            angle_PARD2-=8.0f/temps;
                            angle_PARD3+=8.0f/temps;

                        }
                        if((angle_PAVG1==-90.0f)&&(angle_PAVG2>45.0f)){
                            angle_PAVG2-=(45.0f/2.0f)/temps;
                        }
                        else if ((angle_PAVG1!=-135.0f)&&(angle_PAVG2==45.0f)){
                            angle_PAVG1-=45.0f/temps;
                        }

                        if((angle_PARG1!=-135.0f)&&(angle_PARG2!=-0.0f)){
                            angle_PARG1-=15.0f/temps;
                            angle_PARG2+=15.0f/temps;
                        }
                    }
                    else {
                            patte=1;
                            syncro=true;
          }
      }

      }
      else{
          if((rotation_corp>=24.0f)&&(syncro)){
              if(axe[0]=='-' && axe[1]=='z')mouvementz-=1.0f/temps;
              if(axe[0]=='+' && axe[1]=='z')mouvementz+=1.0f/temps;
              if(axe[0]=='-' && axe[1]=='x')mouvementx-=1.0f/temps;
              if(axe[0]=='+' && axe[1]=='x')mouvementx+=1.0f/temps;
            angle_PAVG1-=5.0f/temps;
            angle_PAVG2-=5.0f/temps;
            angle_PAVG3-=5.0f/temps;

            angle_PARG1-=8.0f/temps;
            angle_PARG2+=8.0f/temps;
            angle_PARG3-=8.0f/temps;

            rotation_corp-=3.0f/temps;
            pencher +=3.0f/temps;

            if(angle_PAVD1<-90.0f){
                angle_PAVD1+=45.0f/temps;
            }
            else if (angle_PAVD2<90.0f){
                angle_PAVD2+=(45.0f/2.0f)/temps;
            }

            if((angle_PARD1<-90.0f)&&(angle_PARD2>-45.0f)){
                  angle_PARD1+=15.0f/temps;
                  angle_PARD2-=15.0f/temps;
            }

          }else{
              syncro=false;
              if(angle_PAVG1!=-135.0f){
                  hauteur-=0.2f/temps;
                  if(axe[0]=='-' && axe[1]=='z')mouvementz-=1.0f/temps;
                  if(axe[0]=='+' && axe[1]=='z')mouvementz+=1.0f/temps;
                  if(axe[0]=='-' && axe[1]=='x')mouvementx-=1.0f/temps;
                  if(axe[0]=='+' && axe[1]=='x')mouvementx+=1.0f/temps;
                rotation_corp-=3.0f/temps;
                angle_PAVG1+=5.0f/temps;
                angle_PAVG2+=5.0f/temps;
                angle_PAVG3-=5.0f/temps;
               }else if (rotation_corp!=30){
                  if(axe[0]=='-' && axe[1]=='z')mouvementz-=0.5f/temps;
                  if(axe[0]=='+' && axe[1]=='z')mouvementz+=0.5f/temps;
                  if(axe[0]=='-' && axe[1]=='x')mouvementx-=0.5f/temps;
                  if(axe[0]=='+' && axe[1]=='x')mouvementx+=0.5f/temps;
                            rotation_corp+=3.0f/temps;
                            angle_PAVG3+=5.0f/temps;

                            if(hauteur!=15.0f)hauteur+=0.2f/temps;

                            if(pencher!=0.0f)  {
                                pencher -=3.0f/temps;
                                angle_PARG1+=8.0f/temps;
                                angle_PARG2-=8.0f/temps;
                                angle_PARG3+=8.0f/temps;

                            }
                            if((angle_PAVD1==-90.0f)&&(angle_PAVD2>45.0f)){
                                angle_PAVD2-=(45.0f/2.0f)/temps;
                            }
                            else if ((angle_PAVD1!=-135.0f)&&(angle_PAVD2==45.0f)){
                                angle_PAVD1-=45.0f/temps;
                            }

                            if((angle_PARD1!=-135.0f)&&(angle_PARD2!=-0.0f)){
                                angle_PARD1-=15.0f/temps;
                                angle_PARD2+=15.0f/temps;
                            }
                        }
                        else {
                                patte=0;
                                syncro=true;
              }
          }
      }




    break;

    case TOUCHE_MIN_Q:
    case TOUCHE_MAJ_Q:
      if(axe[0]=='+' && axe[1]=='z')axe[1]='x';
      else if(axe[0]=='-' && axe[1]=='z')axe[1]='x';
      else if(axe[0]=='+' && axe[1]=='x'){axe[0]='-' ; axe[1]='z';}
      else if(axe[0]=='-' && axe[1]=='x'){axe[0]='+' ; axe[1]='z';}
        pivot+=90.0f;
        break;
    case TOUCHE_MIN_S:
    case TOUCHE_MAJ_S:
      if(axe[0]=='+' && axe[1]=='z'){axe[0]='-' ; axe[1]='z';}
      else if(axe[0]=='-' && axe[1]=='z'){axe[0]='+' ; axe[1]='z';}
      else if(axe[0]=='+' && axe[1]=='x'){axe[0]='-' ; axe[1]='x';}
      else if(axe[0]=='-' && axe[1]=='x'){axe[0]='+' ; axe[1]='x';}
      pivot+=180.0f;
      break;

  case TOUCHE_MIN_D:
  case TOUCHE_MAJ_D:
      if(axe[0]=='+' && axe[1]=='z'){axe[0]='-' ; axe[1]='x';}
      else if(axe[0]=='-' && axe[1]=='z'){axe[0]='+' ; axe[1]='x';}
      else if(axe[0]=='+' && axe[1]=='x')axe[1]='z';
      else if(axe[0]=='-' && axe[1]=='x')axe[1]='z';
      pivot-=90.0f;
      break;

    }
}


