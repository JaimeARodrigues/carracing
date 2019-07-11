#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>

int FPS=10;
const int font1=(int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2=(int)GLUT_BITMAP_HELVETICA_18 ;
const int font3=(int)GLUT_BITMAP_8_BY_13;
GLfloat rotation = 90.0;
int limite=-150;
float posX = 0,posY=0, posZ = 0,vermelho,verde=0,azul=1.0;
int ruaDescCimaoir,ruaDescBaixo,ruaDescBaixo2,ruaDescCima,ruaDescMeio,novaA,ruaDescBaixo3,score,go,level,obstaculo1,posX1,posY2,posX2,posTotalX,posTotalY = 0;

void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}
void reshape(int width, int heigth){

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (width < heigth) {
        glOrtho(-1.0, 1.0, -1.0 * (GLfloat)heigth / (GLfloat)width, 2.0 * (GLfloat)heigth / (GLfloat)width, 1.0, 1.0);
    }
    else{
        glOrtho(-1.0, 1.0, -1.0 * (GLfloat)width / (GLfloat)heigth, 2.0 * (GLfloat)width / (GLfloat)heigth,1.0 , 1.0);
    }
    glViewport(0, 0, width, heigth);
}

bool colisao (int Ax, int Ay, int Acomp, int Aalt, int Bx, int By, int Bcomp, int Balt){
     if(Ay+Aalt < By){return false;
             }else if(Ay> By+Balt)return false;
             else if(Ax+Acomp<Bx) return false;
             else if(Ax > Bx+Bcomp) return false;
     return true;
     } 
void desenha(){
    glTranslatef(4.0f,-45.0f, 1.0f);
    glBegin(GL_POLYGON);
    glColor3f(vermelho,verde, azul);
    glVertex2f(-6,-27);
    glVertex2f(-6,-6);
    glVertex2f(6,-6);
    glVertex2f(6,-27);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-4.5,-15);
    glVertex2f(4.5,-15);
    glVertex2f(2.4,-18);
    glVertex2f(-2.4,-18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-4.5,-24);
    glVertex2f(4.5,-24);
    glVertex2f(2.4,-21);
    glVertex2f(-2.4,-21);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(2.4,-18.3);
    glVertex2f(2.4,-19.5);
    glVertex2f(4.5,-19.5);
    glVertex2f(4.5,-15.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(2.4,-20.7);
    glVertex2f(2.4,-19.8);
    glVertex2f(4.5,-19.8);
    glVertex2f(4.5,-23.7);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-2.4,-18.3);
    glVertex2f(-2.4,-19.5);
    glVertex2f(-4.5,-19.5);
    glVertex2f(-4.5,-15.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-2.4,-20.7);
    glVertex2f(-2.4,-19.8);
    glVertex2f(-4.5,-19.8);
    glVertex2f(-4.5,-23.7);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-6,-9.6);
    glVertex2f(-6,-6.9);
    glVertex2f(-7.5,-6.9);
    glVertex2f(-7.5,-9.6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(6,-9.6);
    glVertex2f(6,-6.9);
    glVertex2f(7.5,-6.9);
    glVertex2f(7.5,-9.6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(6,-26.4);
    glVertex2f(6,-23.7);
    glVertex2f(7.5,-23.7);
    glVertex2f(7.5,-26.4);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-6,-26.4);
    glVertex2f(-6,-23.7);
    glVertex2f(-7.5,-23.7);
    glVertex2f(-7.5,-26.4);
    glEnd();
   
}

void rua(){
    glBegin(GL_POLYGON);
    glColor3f(0.412, 0.412, 0.412);
    glVertex2f(-30,-100);
    glVertex2f(-30,100);
    glVertex2f(40,100);
    glVertex2f(40,-100);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-30,-100);
    glVertex2f(-30,100);
    glVertex2f(-33,100);
    glVertex2f(-33,-100);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(40,-100);
    glVertex2f(40,100);
    glVertex2f(43,100);
    glVertex2f(43,-100);
    glEnd();  
    
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(1.5,ruaDescCima+70);
    glVertex2f(1.5,ruaDescCima+90);
    glVertex2f(5.5,ruaDescCima+90);
    glVertex2f(5.5,ruaDescCima+70);
    glEnd();
   
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1.5,ruaDescMeio+30);
    glVertex2f(1.5,ruaDescMeio+50);
    glVertex2f(5.5,ruaDescMeio+50);
    glVertex2f(5.5,ruaDescMeio+30);
    glEnd();
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1.5,ruaDescBaixo+(-10));
    glVertex2f(1.5,ruaDescBaixo+10);
    glVertex2f(5.5,ruaDescBaixo+10);
    glVertex2f(5.5,ruaDescBaixo+(-10));
    glEnd();
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1.5,ruaDescBaixo2+(-50));
    glVertex2f(1.5,ruaDescBaixo2+(-30));
    glVertex2f(5.5,ruaDescBaixo2+(-30));
    glVertex2f(5.5,ruaDescBaixo2+(-50));
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(1.5,ruaDescBaixo3+(-90));
    glVertex2f(1.5,ruaDescBaixo3+(-70));
    glVertex2f(5.5,ruaDescBaixo3+(-70));
    glVertex2f(5.5,ruaDescBaixo3+(-90));
    glEnd();
     
     }
     void tela(){
       
    
     }
void arvore(){

glPushMatrix();
glScalef(1.9f, 1.7f, 1.0f);
glTranslatef(-50.1f,-1.0f, 1.0f);
    glColor3f(0.871, 0.722, 0.529);
    glBegin(GL_TRIANGLES);
    glVertex2f(11,ruaDescCima+55);
    glVertex2f(12,ruaDescCima+55-10);
    glVertex2f(10,ruaDescCima+55-10);
    glEnd();
    glColor3f(0.133, 0.545, 0.133);
    glBegin(GL_TRIANGLES);
    glVertex2f(11,ruaDescCima+55+3);
    glVertex2f(12+3,ruaDescCima+55-3);
    glVertex2f(10-3,ruaDescCima+55-3);
    glEnd();
    glPopMatrix();
   
    glPushMatrix();
    glScalef(2.0f, 1.6f, 1.0f);
    glTranslatef(-35.1f,-1.0f, 1.0f);
    glColor3f(0.871, 0.722, 0.529);
    glBegin(GL_TRIANGLES);
    glVertex2f(80,ruaDescMeio+30);
    glVertex2f(81,ruaDescMeio+30-10);
    glVertex2f(79,ruaDescMeio+30-10);
    glEnd();
    glColor3f(0.133, 0.545, 0.133);
    glBegin(GL_TRIANGLES);
    glVertex2f(80,ruaDescMeio+30+3);
    glVertex2f(81+3,ruaDescMeio+30-3);
    glVertex2f(79-3,ruaDescMeio+30-3);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glScalef(1.5f, 1.5f, 1.0f);
    glTranslatef(-50.1f,-1.0f, 1.0f);
    glColor3f(0.871, 0.722, 0.529);
    glBegin(GL_TRIANGLES);
    glVertex2f(89,ruaDescBaixo-10);
    glVertex2f(90,ruaDescBaixo-10-10);
    glVertex2f(88,ruaDescBaixo-10-10);
    glEnd();
    glColor3f(0.133, 0.545, 0.133);
    glBegin(GL_TRIANGLES);
    glVertex2f(89,ruaDescBaixo-10+3);
    glVertex2f(90+3,ruaDescBaixo-10-3);
    glVertex2f(88-3,ruaDescBaixo-10-3);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glScalef(1.5f, 1.5f, 1.0f);
    glTranslatef(-50.1f,-1.0f, 1.0f);
    glColor3f(0.871, 0.722, 0.529);
    glBegin(GL_TRIANGLES);
    glVertex2f(17,ruaDescBaixo+10);
    glVertex2f(18,ruaDescBaixo+10-10);
    glVertex2f(16,ruaDescBaixo+10-10);
    glEnd();
    glColor3f(0.133, 0.545, 0.133);
    glBegin(GL_TRIANGLES);
    glVertex2f(17,ruaDescBaixo+10+3);
    glVertex2f(18+3,ruaDescBaixo+10-3);
    glVertex2f(16-3,ruaDescBaixo+10-3);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glScalef(1.0f, 1.5f, 1.0f);
    glTranslatef(-50.1f,-1.0f, 1.0f);
      glColor3f(0.871, 0.722, 0.529);
    glBegin(GL_TRIANGLES);
    glVertex2f(7,ruaDescBaixo3-30);
    glVertex2f(8,ruaDescBaixo3-30-10);
    glVertex2f(6,ruaDescBaixo3-30-10);
    glEnd();
    glColor3f(0.133, 0.545, 0.133);
    glBegin(GL_TRIANGLES);
    glVertex2f(7,ruaDescBaixo3-30+3);
    glVertex2f(8+3,ruaDescBaixo3-30-3);
    glVertex2f(6-3,ruaDescBaixo3-30-3);
    glEnd();  
    glPopMatrix();
    
    glPushMatrix();
    glScalef(2.5f, 1.5f, 1.0f);
    glTranslatef(-50.1f,-1.0f, 1.0f);
    glColor3f(0.871, 0.722, 0.529);
    glBegin(GL_TRIANGLES);
    glVertex2f(17,ruaDescCima+100);
    glVertex2f(18,ruaDescCima+100-10);
    glVertex2f(16,ruaDescCima+100-10);
    glEnd();
    glColor3f(0.133, 0.545, 0.133);
    glBegin(GL_TRIANGLES);
    glVertex2f(17,ruaDescCima+100+3);
    glVertex2f(18+3,ruaDescCima+100-3);
    glVertex2f(16-3,ruaDescCima+100-3);
    glEnd();
    glPushMatrix();
    
    glPopMatrix();
    glScalef(1.5f, 1.3f, 1.0f);
    glTranslatef(-30.1f,-1.0f, 1.0f);
    glColor3f(0.871, 0.722, 0.529);
    glBegin(GL_TRIANGLES);
    glVertex2f(93,ruaDescCima+130);
    glVertex2f(94,ruaDescCima+130-10);
    glVertex2f(92,ruaDescCima+130-10);
    glEnd();
    glColor3f(0.133, 0.545, 0.133);
    glBegin(GL_TRIANGLES);
    glVertex2f(93,ruaDescCima+130+3);
    glVertex2f(94+3,ruaDescCima+130-3);
    glVertex2f(92-3,ruaDescCima+130-3);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glScalef(1.5f, 1.5f, 1.0f);
    glTranslatef(-40.1f,-1.0f, 1.0f);
     glColor3f(0.871, 0.722, 0.529);
    glBegin(GL_TRIANGLES);
    glVertex2f(79,ruaDescCima+85);
    glVertex2f(80,ruaDescCima+85-10);
    glVertex2f(78,ruaDescCima+85-10);
    glEnd();
    glColor3f(0.133, 0.545, 0.133);
    glBegin(GL_TRIANGLES);
    glVertex2f(79,ruaDescCima+85+3);
    glVertex2f(80+3,ruaDescCima+85-3);
    glVertex2f(78-3,ruaDescCima+85-3);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-40.0f,-1.0f, 1.0f);
    glColor3f(1.0,0.5,0.0);
     glBegin(GL_TRIANGLES);
    glVertex2f(posX1+20,ruaDescMeio+60);
    glVertex2f(posX1+22,ruaDescMeio+70);
    glVertex2f(posTotalX=posX1+24,posTotalY=ruaDescMeio+60);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glLineWidth(5.0);
     glBegin(GL_LINES);
    glVertex2f(posX1+21,ruaDescMeio+66);
    glVertex2f(posX1+22.8,ruaDescMeio+66);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(posX1+20.4,ruaDescMeio+62.5);
    glVertex2f(posX1+23.4,ruaDescMeio+62.5);
    glEnd();
    glColor3f(1.0,0.5,0.0);
     glBegin(GL_TRIANGLES);
    glVertex2f(posX1+60,ruaDescCima+80);
    glVertex2f(posX1+62,ruaDescCima+90);
    glVertex2f(posTotalX=posX1+64,posTotalY=ruaDescCima+80);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glLineWidth(5.0);
     glBegin(GL_LINES);
    glVertex2f(posX1+61,ruaDescCima+86);
    glVertex2f(posX1+62.8,ruaDescCima+86);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(posX1+60.4,ruaDescCima+82.5);
    glVertex2f(posX1+63.4,ruaDescCima+82.5);
    glEnd();
    glPopMatrix();
    
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(75,5);
    glVertex2f(100,5);
    glVertex2f(100,5-10);
    glVertex2f(75,5-10);
    glEnd();
     
    char buffer [50];
    sprintf (buffer, "SCORE: %d", score);
    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(75.5,2,(void *)font3,buffer);
    
    char buffer1 [50];
    sprintf (buffer1, "SPEED:%dKm/h", FPS);
    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(75.5,1-2,(void *)font3,buffer1);
     char buffer2 [50];
    sprintf (buffer2, "POSICAO: %d", posY2);
    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(-13,0,(void *)font3,buffer2);
     
    
    char level_buffer [50];
    sprintf (level_buffer, "LEVEL: %d", level);
    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(75.5,0-4,(void *)font3,level_buffer);
    if(go==1){
         glClear(GL_COLOR_BUFFER_BIT); 
       glColor3f(0.0, 0.0, 0.0);
       renderBitmapString(-13,5,(void *)font1,"GAME OVER");
       glColor3f(1.000, 0.000, 0.000);
        char buffer2 [50];
        sprintf (buffer2, "Seu Score é : %d", score);
        renderBitmapString(-13,0,(void *)font1,buffer2);
        
        }


}

void anima(int p){
      ruaDescCima-=2;
    if(ruaDescCima<-180){
        ruaDescCima =20;
        posX1=posX2;
        if (go==0){
            score++;
            if(colisao(posX2,posY2,12,15,posTotalX,posTotalY,4,10)==true){
            go=0;

    }

    }

}

    ruaDescMeio-=2;
    if(ruaDescMeio<-140){
        ruaDescMeio =60;
        if (go==0){
            score++;
}
    }
    ruaDescBaixo-=2;
    if(ruaDescBaixo<-100){
        ruaDescBaixo =100;
        if (go==0){
            score++;
}
    }
    ruaDescBaixo2-=2;
    if(ruaDescBaixo2<-60){
        ruaDescBaixo2 =140;
        if (go==0){
            score++;
}
    }
    ruaDescBaixo3-=2;
    if(ruaDescBaixo3<-20){
        ruaDescBaixo3 =180;
        if (go==0){
            score++;
}
    }
    if(score > 0 && score <=30){
    ruaDescCima-=1;
    ruaDescMeio-=1;
    ruaDescBaixo-=1;
    ruaDescBaixo2-=1;
    ruaDescBaixo3-=1;
    level=1;
    if(FPS>=0 && FPS<=50){
    FPS=FPS+1;
}
}
    if(score > 30 && score <=60){
    ruaDescCima-=2;
    ruaDescMeio-=2;
    ruaDescBaixo-=2;
    ruaDescBaixo2-=2;
    ruaDescBaixo3-=2;
    level=2;
   if(FPS>50 && FPS<=100){
    FPS=FPS+1;
}
}
 if(score > 60 && score <=90){
    ruaDescCima-=3;
    ruaDescMeio-=3;
    ruaDescBaixo-=3;
    ruaDescBaixo2-=3;
    ruaDescBaixo3-=3;
    level=3;
   if(FPS>100 && FPS<=120){
    FPS=FPS+1;
}
}
 if(score > 90 && score <=120){
    ruaDescCima-=4;
    ruaDescMeio-=4;
    ruaDescBaixo-=4;
    ruaDescBaixo2-=4;
    ruaDescBaixo3-=4;
    level=4;
   if(FPS>120 && FPS<=140){
    FPS=FPS+1;
}
}
 if(score > 120 && score <=150){
    ruaDescCima-=5;
    ruaDescMeio-=5;
    ruaDescBaixo-=5;
    ruaDescBaixo2-=5;
    ruaDescBaixo3-=5;
    level=5;
   if(FPS>140 && FPS<=170){
    FPS=FPS+1;
}
}
 if(score >150 && score <=180){
    ruaDescCima-=6;
    ruaDescMeio-=6;
    ruaDescBaixo-=6;
    ruaDescBaixo2-=6;
    ruaDescBaixo3-=6;
    level=6;
   if(FPS>170 && FPS<=200){
    FPS=FPS+1;
}
}
 if(score > 180 && score<=210){
    ruaDescCima-=7;
    ruaDescMeio-=7;
    ruaDescBaixo-=7;
    ruaDescBaixo2-=7;
    ruaDescBaixo3-=7;
    level=7;
   if(FPS>200 && FPS<=230){
    FPS=FPS+1;
}
}
 if(score > 210 && score<=240){
    ruaDescCima-=8;
    ruaDescMeio-=8;
    ruaDescBaixo-=8;
    ruaDescBaixo2-=8;
    ruaDescBaixo3-=8;
    level=8;
     if(FPS>230 && FPS<=245){
    FPS=FPS+1;
}
}
 if(score > 240 && score<=270){
    ruaDescCima-=9;
    ruaDescMeio-=9;
    ruaDescBaixo-=9;
    ruaDescBaixo2-=9;
    ruaDescBaixo3-=9;
    level=9;
}
 if(score > 270 && score<=300){
    ruaDescCima-=10;
    ruaDescMeio-=10;
    ruaDescBaixo-=10;
    ruaDescBaixo2-=10;
    ruaDescBaixo3-=10;
    level=10;
}


    if(posX2>30||posX2<-29){
            go=1;
            

}
    glutPostRedisplay();
	glutTimerFunc(50,anima,1);

     }
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    rua();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(posX,posY,posZ);
    desenha();
    glPopMatrix();
    glPushMatrix();
    arvore();
    glPopMatrix();
    glFlush();
}


void init(){
    glClearColor(0.184, 1.0, 0.310,1);

    glColor3f(1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0);

}

void teclar(unsigned char teclas, int x, int y)
{
     switch(teclas){
                    case 27:
                         exit(0);
                         break;
                     case 55:{
                        
                         azul=0.0;
                         verde=0.0;
                         vermelho=1.0;
                        }
                        break;
                    case 56:{
                         azul=1.0;
                         verde=0.0;
                         vermelho=0.0;
                        }
                        break;
                    case 57:{
                         azul=0.0;
                         verde=1.0;
                         vermelho=0.0;
                        }
                         break;
                         default:
                         break;
                         }
}
void teclado(int tecla, int x, int y)
{
    switch (tecla){
     case GLUT_KEY_DOWN:{
            if(FPS>(10+(level*2)) && posY>-(25)){
            posY=posY-2;
            posY2=posY;
            FPS=FPS-2;
            }
        }
            break;
        case GLUT_KEY_UP:{
        if(posY<120 && FPS<250){
            posY=posY+2;
            posY2=posY;
            FPS=FPS+1;
        }
        }
            break;

        case GLUT_KEY_LEFT:{
        
                    posX=posX-2;
                    posX2=posX;
            }
            break;


        case GLUT_KEY_RIGHT:{
          posX=posX+2;
          posX2=posX;
            }
            
        default:
         break;
    }
    glutPostRedisplay();
}


int main(int argc, char* argv[]){


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Joguinho");
    glutDisplayFunc(display);
    init();
    glutSpecialFunc(teclado);
    glutKeyboardFunc(teclar);
    glutTimerFunc(1, anima, 1);
    glutMainLoop();

}
