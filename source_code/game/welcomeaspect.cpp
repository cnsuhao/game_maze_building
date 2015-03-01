#ifndef DIY_WELCOMEASPECT_CPP
#define DIY_WELCOMEASPECT_CPP
#include "Plugin_Base.h"
#include "numberout.h"
#include "ControlCenter.h"
#include "baseclass.h"
#include "picture.h"
#include "sgprint.h"
//extern HardControl yd;
class WelcomeAspect:public Plugin_Base
{
    Picture3D TY;
    int Cul;
    Sentence3D Min;
    Sentence3D Zi;
    public:
    WelcomeAspect():Plugin_Base("WelcomeAspect"){}
    void LookAt(XYZF LocPoi,float,float);
    void Init(ControlCenter* CC)
    {
        TY.Load("fleed4.jpg",0,0,0);
        LookAt(XYZF(0.5143,0.7984,0.6372),-0.5667,-0.9422);
        Min.Add("P.O玛丽战争");
        Zi.Add("之板栗的逆袭"); 
    }
    void Show(ControlCenter* CC)
    {
        if(CC->Time(5000,20000))//波纹 
        {
            glColor3f(1.0,1.0,1.0);
            if(CC->Time(7100,8000))
            {
                glBegin(GL_LINE_LOOP);
                for(int i=0;i<41;++i)
                {
                    glVertex3f(CC->Time(7100)*0.002*sin(i*0.157),0.0,CC->Time(7100)*0.002*cos(i*0.157));
                }
                glEnd();
            }
            if(CC->Time(7300,9200))
            {
                glBegin(GL_LINE_LOOP);
                for(int i=0;i<41;++i)
                {
                    glVertex3f(CC->Time(7300)*0.002*sin(i*0.157),0.0,CC->Time(7300)*0.002*cos(i*0.157));
                    
                }
                glEnd();
            }
            if(CC->Time(7500,9400))
            {
                glBegin(GL_LINE_LOOP);
                for(int i=0;i<41;++i)
                {
                    glVertex3f(CC->Time(7500)*0.002*sin(i*0.157),0.0,CC->Time(7500)*0.002*cos(i*0.157));
                }
                glEnd();
                
            }
            if(CC->Time(5000,6500))
            {
                glBegin(GL_LINE_LOOP);
                for(int i=0;i<41;++i)
                {
                    glVertex3f(CC->Time(5000)*0.002*sin(i*0.157),0.0,CC->Time(5000)*0.002*cos(i*0.157));
                }
                glEnd();
            }
            if(CC->Time(12000,13500))
            {
                glBegin(GL_LINE_LOOP);
                for(int i=0;i<41;++i)
                {
                    glVertex3f(CC->Time(12000)*0.002*sin(i*0.157),0.0,CC->Time(12000)*0.002*cos(i*0.157));
                }
                glEnd();
            }
            if(CC->Time(12200,13700))
            {
                glBegin(GL_LINE_LOOP);
                for(int i=0;i<41;++i)
                {
                    glVertex3f(CC->Time(12200)*0.002*sin(i*0.157),0.0,CC->Time(12200)*0.002*cos(i*0.157));
                }
                glEnd();
            }
            if(CC->Time(12400,13900))
            {
                glBegin(GL_LINE_LOOP);
                for(int i=0;i<41;++i)
                {
                    glVertex3f(CC->Time(12400)*0.002*sin(i*0.157),0.0,CC->Time(12400)*0.002*cos(i*0.157));
                }
                glEnd();
            }
            if(CC->Time(17400,20000))
            {
                glBegin(GL_LINE_LOOP);
                for(int i=0;i<41;++i)
                {
                    glVertex3f(CC->Time(17400)*0.002*sin(i*0.157),0.0,CC->Time(17400)*0.002*cos(i*0.157));
                }
                glEnd();
            }
            if(CC->Time(17600,20000))
            {
                glBegin(GL_LINE_LOOP);
                for(int i=0;i<41;++i)
                {
                    glVertex3f(CC->Time(17600)*0.002*sin(i*0.157),0.0,CC->Time(17600)*0.002*cos(i*0.157)+0.2);
                }
                glEnd();
            }
            if(CC->Time(17800,20000))
            {
                glBegin(GL_LINE_LOOP);
                for(int i=0;i<41;++i)
                {
                    glVertex3f(CC->Time(17800)*0.002*sin(i*0.157),0.0,CC->Time(17800)*0.002*cos(i*0.157)+0.4);
                }
                glEnd();
            }
        }
        
        if(CC->Time(8071,12300)||CC->Time(12600,17500))//文字 
        {
            if(CC->Time(12200,12300))
            {
                Min.Delete();
                Min.Add("吞薯条倾力奉献");
                Zi.Add("微博@卡神-凛龘"); 
            }else if(CC->Time(8071,12000)||CC->Time(12600,1400000049))
            {
                Min.Show(XYZF(-1.01,0.0,0.08),XYZF(0.6824,0.0,0.4961).Uint(),XYZF(0.0,1.0,0.0),1.0,1.0,1.0,0.2);
                Zi.Show(XYZF(-0.77,0.0,0.28),XYZF(0.6824,0.0,0.4961).Uint(),XYZF(0.0,1.0,0.0),1.0,1.0,1.0,0.2);
            }
        }
        glPushMatrix();
        if(CC->Time(17400,20000))//被风吹走 
        {
             glTranslatef(0.0,0.05+CC->Time(17400)*0.0001,CC->Time(17400)*0.001);
             glRotatef(-(CC->Time(17400)*0.25),1.0,0.0,0.0);
             glTranslatef(0.0,-0.05,0.0);
        }
        
        
        if(CC->Time(7100,7500)||CC->Time(12000,12400)) //被风原地转动 
        {
            if(CC->Time(7100)<=199)
            {
                glRotatef((CC->Time(7100))*0.025,0.0,1.0,0.0);
            }else if(CC->Time(7100)<=400)
            {
                glRotatef(10-(CC->Time(7100))*0.025,0.0,1.0,0.0);
            }else if(CC->Time(12000)<=199)
            {
                glRotatef((CC->Time(12000))*0.025,0.0,1.0,0.0);
            }else if(CC->Time(12000)<=400)
            {
                glRotatef(10-(CC->Time(12000))*0.025,0.0,1.0,0.0);
            }
        }
        
        if(CC->Time(4900,17400))  glTranslatef(0.0,0.012*sin(CC->Time(4900)*0.003),0.0);//上下略微浮动 
        
        
        if(CC->Time(0,5000))    glTranslatef(0.0,1.6-CC->Time(0)*0.00012,-0.12);  //往下飘 
        else   glTranslatef(0.0,1.0,-0.12);
        if(CC->Time(0,5000))    glRotatef(100+20*sin(CC->Time(0)*0.0012566),-1.0,0.0,0.0);
        else   glRotatef(100,-1.0,0.0,0.0);
        
        
        
        if(CC->Time(0,20000))
        {
            for(int z=0;z<10;++z) //画出羽毛的弯度 
            {
                TY.Cutting(0.0,(z+1)*0.1,1.0,z*0.1);
                TY.Show( XYZF(-0.05,0.5*sin(0.0553*z+2.748),cos(0.0553*z+2.748)) , XYZF(0.0,0.5*(sin(0.0553*(z+1)+2.748)-sin(0.0553*z+2.748)),cos(0.0553*(z+1)+2.748)-cos(0.0553*z+2.748))  ,  XYZF(0.1,0.0,0.0));
            }
        }
        glPopMatrix();
        
        if(CC->Time(20000)>0)
        {
            Kill();
            Min.Delete();
            Zi.Delete();
            TY.Delete();
        } 
    }
};
void WelcomeAspect::LookAt(XYZF LocPoi,float AngleUp,float AngleRight)
{
                    Information Te=NewInformation(Call("View"),VIEWLOCATION);
                    Te.Data1.f=LocPoi.X;
                    Te.Data2.f=LocPoi.Y;
                    Te.Data3.f=LocPoi.Z;
                    OutLibrary.push_back(Te);
                    Te=NewInformation(Call("View"),VIEWANGLE);
                    Te.Data1.f=AngleUp;
                    Te.Data2.f=AngleRight;
                    OutLibrary.push_back(Te);
}


#endif
