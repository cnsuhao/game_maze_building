#ifndef DIY_CUDE_H
#define DIY_CUDE_H
#include "baseclass.h"
#include "glsimplify.h"
class Cude
{
    bool Ready;
    float angleX;
    float angleY;
    float angleZ;
    int List;
    float A;
    float B;
    float C;
    XYZF Color;
    float Apl;
    public:
        void SetAngle(float A,float B,float C)//³¯Ïò
        {
            angleX=A;
            angleY=B;
            angleZ=C;
        }
        void Set(float a,float b,float c)
        {
            A=a/2;
            B=b/2;
            C=c/2;
        }
        void Init(void)
        {
            List=glGenLists(1);
                    glNewList(List,GL_COMPILE);
                        glBegin(GL_QUADS);
                            glNormal3f(0,0,-1.0f);
                            glVertex3f(A,+B,-C);
                            glVertex3f(A,-B,-C);
                            glVertex3f(-A,-B,-C);
                            glVertex3f(-A,+B,-C);
                        glEnd();
                        glBegin(GL_QUADS);
                            glNormal3f(0,0,1.0f);
                            glVertex3f(+A,+B,+C);
                            glVertex3f(-A,+B,+C);
                            glVertex3f(-A,-B,+C);
                            glVertex3f(+A,-B,+C);
                        glEnd();
                        glBegin(GL_QUADS);
                            glNormal3f(0,1.0f,0);
                            glVertex3f(+A,+B,+C);
                            glVertex3f(+A,+B,-C);
                            glVertex3f(-A,+B,-C);
                            glVertex3f(-A,+B,+C);
                        glEnd();
                        glBegin(GL_QUADS);
                            glNormal3f(0,-1.0f,0);
                            glVertex3f(+A,-B,+C);
                            glVertex3f(-A,-B,+C);
                            glVertex3f(-A,-B,-C);
                            glVertex3f(+A,-B,-C);
                        glEnd();
                        glBegin(GL_QUADS);
                            glNormal3f(-1.0f,0,0);
                            glVertex3f(-A,+B,+C);
                            glVertex3f(-A,+B,-C);
                            glVertex3f(-A,-B,-C);
                            glVertex3f(-A,-B,+C);
                        glEnd();
                        glBegin(GL_QUADS);
                            glNormal3f(1.0f,0,0);
                            glVertex3f(+A,+B,+C);
                            glVertex3f(+A,-B,+C);
                            glVertex3f(+A,-B,-C);
                            glVertex3f(+A,+B,-C);
                        glEnd();
                    glEndList();
        }
        void Show(XYZF Location)
        {
            glColor3f(Color.X,Color.Y,Color.Z);
            glPushMatrix();
            glTranslatef(Location.X,Location.Y,Location.Z);
            if(List!=0)   glCallList(List);
            glPopMatrix();
        }
        Cude(float A,float B,float C):Color(1.0,1.0,1.0)
        {
            Set(A,B,C);
            Ready=false;
        }
};
#endif
