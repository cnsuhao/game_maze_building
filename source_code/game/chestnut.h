#ifndef DIY_CHESTNUT_H
#define DIY_CHESTNUT_H
#include "SDL/SDL.h"
#include <math.h>
#define WRange 1.0
#define WSpeed 0.001
#define WTime  400
enum ChState
{
    quiet=0,
    walk,
    running,
    jumpup,
    jumpdown,
    jumpstand,
    jumpstart,
    ruch,
    hiding
};
class Chestnut
{
    ChState LastMode;
    ChState NowMode;
    int StarTime;
    unsigned int Data;
    ControlCenter* CC;
    public:
        void Show(ChState State,XYZF Location, float Angle);
        void Init(ControlCenter*);
    
    
    
    
    
    
};
void Chestnut::Show(ChState State,XYZF Location, float Angle)
{
    if(NowMode!=State)
    {
        StarTime=CC->Time(0);
        LastMode=NowMode;
        NowMode=State;
    }
    if(NowMode==State)
    {
        //bool Rig=glIsEnabled(GL_COLOR_MATERIAL);
        //float TY[]={0.5};
        //glDisable(GL_COLOR_MATERIAL);
        glPushMatrix();
        //glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,0.5);
        glTranslatef(Location.X,Location.Y,Location.Z);
        glRotatef(Angle,0.0,1.0,0.0);
        glScalef(0.2,0.2,0.2);
        int Tem;
        switch(NowMode)
        {
            case walk:
                Tem=CC->Time(StarTime)%(WTime*2);
                if(Tem>=0&&Tem<WTime)
                {
                    error<<Tem<<"就开始了"<<endl;
                    glColor3ub(77,59,45);
                    glPushMatrix();
                        glTranslatef(-0.6,WRange*2*sin(Tem*1.047/WTime+1.04)-1.732*WRange,-WRange*2*cos(Tem*1.047/WTime+1.04));
                        glRotatef(-10,0.0,1.0,0.0);
                        glCallList(Data+2);
                        glCallList(Data+3);
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(0.6,0.0,WRange-(float)Tem/WTime*2.0*WRange);
                        glRotatef(10,0.0,1.0,0.0);
                        glCallList(Data+2);
                        glCallList(Data+3);
                    glPopMatrix();
                    
                    glPushMatrix();
                        glColor3ub(176,145,116);
                        glRotatef(10-Tem*20.0/WTime,0.0,0.0,1.0);
                        glRotatef(10,1.0,0.0,0.0);
                        glTranslatef(0.0,0.2,0.0);
                        glCallList(Data+1);
                    glPopMatrix();
                    glPushMatrix();
                        glColor3ub(115,67,40);
                        glRotatef(10-Tem*20.0/WTime,0.0,0.0,1.0);
                        glRotatef(10,1.0,0.0,0.0);
                        glTranslatef(0.0,1.2,0.0);
                        glCallList(Data);
                    glPopMatrix();
                }else if(Tem>=WTime){
                    Tem-=WTime;
                    glColor3ub(77,59,45);
                    glPushMatrix();
                    glTranslatef(0.6,WRange*2*sin(Tem*1.047/WTime+1.04)-1.732*WRange,-WRange*2*cos(Tem*1.047/WTime+1.04));
                    glRotatef(10,0.0,1.0,0.0);
                    glCallList(Data+2);
                    glCallList(Data+3);
                    glPopMatrix();
                    glPushMatrix();
                    glTranslatef(-0.6,0.0,WRange-(float)Tem/WTime*2.0*WRange);
                    glRotatef(-10,0.0,1.0,0.0);
                    glCallList(Data+2);
                    glCallList(Data+3);
                    glPopMatrix();
                    glPushMatrix();
                    glColor3ub(176,145,116);
                    glRotatef(Tem*20.0/WTime-10,0.0,0.0,1.0);
                    glRotatef(10,1.0,0.0,0.0);
                    glTranslatef(0.0,0.2,0.0);
                    glCallList(Data+1);
                    glPopMatrix();
                    glPushMatrix();
                    glColor3ub(115,67,40);
                    glRotatef(Tem*20.0/WTime-10,0.0,0.0,1.0);
                    glRotatef(10,1.0,0.0,0.0);
                    glTranslatef(0.0,1.2,0.0);
                    glCallList(Data);
                    glPopMatrix();
                }
                break;
            case jumpup:
            case jumpdown:
            case jumpstand:
            case jumpstart:
            case quiet:
                    glColor3ub(77,59,45);
                    glPushMatrix();
                    glTranslatef(-0.6,0.0,0.0);
                    glRotatef(-10,0.0,1.0,0.0);
                    glCallList(Data+2);
                    glCallList(Data+3);
                    glPopMatrix();
                    glPushMatrix();
                    glTranslatef(0.6,0.0,0.0);
                    glRotatef(10,0.0,1.0,0.0);
                    glCallList(Data+2);
                    glCallList(Data+3);
                    glPopMatrix();
                    
                    glPushMatrix();
                    glColor3ub(176,145,116);
                    glTranslatef(0.0,0.2,0.0);
                    glCallList(Data+1);
                    glPopMatrix();
                    glPushMatrix();
                    glColor3ub(115,67,40);
                    glTranslatef(0.0,1.2,0.0);
                    glCallList(Data);
                    glPopMatrix();
                    break;
                /*
                glPushMatrix();
                glScalef(0.2,0.2,0.2);
                glColor3f(0.9,0.8,0.2);
                glTranslatef(0.6,0.0,0.0);
                glRotatef(10,0.0,1.0,0.0);
                glCallList(Data+2);
                glCallList(Data+3);
                glPopMatrix();
                break;*/
        }
        glPopMatrix();
        //if(Rig)    glEnable(GL_COLOR_MATERIAL);
    }
    //glPushMatrix();
    /*
    glScalef(0.2,0.2,0.2);
    glColor3f(0.9,0.8,0.2);
    glTranslatef(-0.6,0.0,0.0);
    glRotatef(-10,0.0,1.0,0.0);
    glCallList(Data+2);
    glCallList(Data+3);
    glPopMatrix();
    
    glPushMatrix();
    glScalef(0.2,0.2,0.2);
    glColor3f(0.9,0.8,0.2);
    glTranslatef(0.6,0.0,0.0);
    glRotatef(10,0.0,1.0,0.0);
    glCallList(Data+2);
    glCallList(Data+3);
    glPopMatrix();*/
    /*
    glColor3f(0.2,0.2,0);
    glTranslatef(-0.5,0.25,0.0);
    glCallList(Data+1);
    
    glColor3f(0.9,0.4,0);
    glTranslatef(0.0,1.0,0.0);
    glCallList(Data);
    */
    //glPopMatrix();
}
void Chestnut::Init(ControlCenter* EE)
{
    CC=EE;
    Data=glGenLists(4);
    glNewList(Data,GL_COMPILE);
    for(int i=4;i<=15;++i)
    {
        float Tem=i*0.2;
        float Tem2=(i+1)*0.2;
        //glMaterialfv(GL_FRONT,GL_AMBIENT,Color);
        if(i==4)
        {
            glBegin(GL_TRIANGLE_FAN);
            glVertex3f(0.0,2.2,0.0);
            for(int k=0;k<21;++k)
            {
                glVertex3f(Tem2*tan(0.65)*sin(k*0.3145),3-Tem2,Tem2*tan(0.65)*cos(k*0.3145)*0.8);
            }
            glEnd();
        }else if(i>=12&&i<15)
        {
            glBegin(GL_TRIANGLE_STRIP);
            for(int k=0;k<21;++k)
            {
                glVertex3f((4.8-Tem)*tan(0.65)*sin(k*0.3145),3-Tem,(4.8-Tem)*tan(0.65)*cos(k*0.3145)*0.8);
                glVertex3f((4.8-Tem2)*tan(0.65)*sin(k*0.3145),3-Tem2,(4.8-Tem2)*tan(0.65)*cos(k*0.3145)*0.8);
            }
            glEnd();
        }else if(i==15)
        {
            glBegin(GL_TRIANGLE_FAN);
            glVertex3f(0.0,0.0,0.0);
            for(int k=0;k<21;++k)
            {
                glVertex3f((4.8-Tem)*tan(0.65)*cos(k*0.3145),3-Tem,(4.8-Tem)*tan(0.65)*sin(k*0.3145)*0.8);
            }
            glEnd();
        }else{
            glBegin(GL_TRIANGLE_STRIP);
            for(int k=0;k<21;++k)
            {
                glVertex3f(Tem*tan(0.65)*sin(k*0.3145),3-Tem,Tem*tan(0.65)*cos(k*0.3145)*0.8);
                glVertex3f(Tem2*tan(0.65)*sin(k*0.3145),3-Tem2,Tem2*tan(0.65)*cos(k*0.3145)*0.8);
            }
            glEnd();
        }
    }
    glEndList();//头 
    
    
    
    glNewList(Data+1,GL_COMPILE);//身体 
    for(int i=-1;i<=4;++i)
    {
        float Tem=i*0.25;
        float Tem2=(i+1)*0.25;
        if(i==3)
        {
            glBegin(GL_TRIANGLE_STRIP);
            for(int k=0;k<21;++k)
            {
                glVertex3f(0.5*sin(k*0.3145),1-Tem,0.5*cos(k*0.3145));
                glVertex3f(0.25*sin(k*0.3145),1-Tem2,cos(k*0.3145)*0.25);
            }
            glEnd();
        }else if(i==4)
        {
            glBegin(GL_TRIANGLE_FAN);
            glVertex3f(0.0,0.0,0.0);
            for(int k=0;k<21;++k)
            {
                glVertex3f(0.25*cos(k*0.3145),0.0,sin(k*0.3145)*0.25);
            }
            glEnd();
        }else if(i==-1)
        {
            glBegin(GL_TRIANGLE_FAN);
            glVertex3f(0.0,1.0,0.0);
            for(int k=0;k<21;++k)
            {
                glVertex3f(0.5*sin(k*0.3145),1.0,cos(k*0.3145)*0.5);
            }
            glEnd();
        }else{
            glBegin(GL_TRIANGLE_STRIP);
            for(int k=0;k<21;++k)
            {
                glVertex3f(0.5*sin(k*0.3145),1-Tem,0.5*cos(k*0.3145));
                glVertex3f(0.5*sin(k*0.3145),1-Tem2,cos(k*0.3145)*0.5);
            }
            glEnd();
        }
    }
    glEndList(); 

    glNewList(Data+2,GL_COMPILE);//脚尖
    glBegin(GL_QUADS);
    glVertex3f(-0.3,0.2,0.2);
    glVertex3f(0.3,0.2,0.2);
    glVertex3f(0.3,0.0,0.2);
    glVertex3f(-0.3,0.0,0.2);
    
    glVertex3f(-0.3,0.2,0.2);
    glVertex3f(-0.3,0.0,0.2);
    glVertex3f(0.0,0.0,0.6);
    glVertex3f(0.0,0.2,0.6);
    
    glVertex3f(0.0,0.2,0.6);
    glVertex3f(0.0,0.0,0.6);
    glVertex3f(0.3,0.0,0.2);
    glVertex3f(0.3,0.2,0.2);
    
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.3,0.2,0.2);
    glVertex3f(0.0,0.2,0.6);
    glVertex3f(0.3,0.2,0.2);
    
    glVertex3f(0.3,0.0,0.2);
    glVertex3f(0.0,0.0,0.6);
    glVertex3f(-0.3,0.0,0.2);
    glEnd();
    glEndList(); 
    
    glNewList(Data+3,GL_COMPILE);//脚gen
    glBegin(GL_QUADS);
    glVertex3f(-0.3,0.3,-0.4);
    glVertex3f(-0.3,0.3,0.2);
    glVertex3f(0.3,0.3,0.2);
    glVertex3f(0.3,0.3,-0.4);
    
    glVertex3f(-0.3,0.0,-0.4);
    glVertex3f(0.3,0.0,-0.4);
    glVertex3f(0.3,0.0,0.2);
    glVertex3f(-0.3,0.0,0.2);
    
    glVertex3f(-0.3,0.3,-0.4);
    glVertex3f(0.3,0.3,-0.4);
    glVertex3f(0.3,0.0,-0.4);
    glVertex3f(-0.3,0.0,-0.4);
    
    glVertex3f(0.3,0.3,0.2);
    glVertex3f(-0.3,0.3,0.2);
    glVertex3f(-0.3,0.0,0.2);
    glVertex3f(0.3,0.0,0.2);
    
    glVertex3f(0.3,0.3,-0.4);
    glVertex3f(0.3,0.3,0.2);
    glVertex3f(0.3,0.0,0.2);
    glVertex3f(0.3,0.0,-0.4);
    
    glVertex3f(-0.3,0.3,-0.4);
    glVertex3f(-0.3,0.0,-0.4);
    glVertex3f(-0.3,0.0,0.2);
    glVertex3f(-0.3,0.3,0.2);
    
    
    
    
    
    glEnd();
    glEndList(); 

}










#endif
