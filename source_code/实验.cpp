#define s(xx) er<<xx<<endl;
#include <fstream> 
using namespace std;
ofstream er;
int angel;
int dance;
#include "controlcenter.h"
#include "physics.h"
#include "music.h"
#include "partylycontrol.h"
#include "aspect.h"
#include "error.h"
#include "light.h"
ControlCenter CC;
MusicControl MC;
Picture TT;
KeyControl KC;
AspectFor3D AD;
PhysicsControl PC;
Light Ti;
Error ERR("ee.txt");
float t[10];
void GLInit(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_SMOOTH);//�趨��ɫģʽ��SMOOTH��ƽ����ɫ��FLAT�ǹ̶���ɫ��ʹ��ĳһ������ɫ��ɫ�� 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
    //gluPerspective(40,640/480,0.01,50);
    //glMatrixMode(GL_MODELVIEW);
    glLineWidth(10.0);
    glEnable (GL_POLYGON_SMOOTH);
    glHint (GL_POLYGON_SMOOTH, GL_NICEST);
                //glEnable(GL_DEPTH_TEST); // ������Ȳ���
            //glDepthFunc(GL_LESS); // ������Ȳ��Ե�����
    glClearDepth(50.0f); // ������Ȼ���
    glEnable(GL_DEPTH_TEST); // ������Ȳ���
    glDepthFunc(GL_LESS); // ������Ȳ��Ե�����
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPointSize(40);
}
int main(int argc, _TCHAR* argv[])
{
    er.open("tt.txt");
    angel=MC.Load("Music//angle_music.mp3");
    dance=MC.Load("Music//death_music.mp3");
        er<<angel<<endl;
    //CC.Regedit(MC.Regedit());
    //CC.Regedit(&Ti);
    CC.Regedit(&KC);
    CC.Regedit(&PC);
    CC.Regedit(&AD);
    CC.Regedit(&MC);
    CC.Regedit(&ERR);
    //er<<"sssssdddd"<<endl;
    //CC.Regedit(AD.Regedit());
    //CC.AimAt("Mouse",INFEVENT,INFMOUSE);
    CC.RegFinish();
    CC.Init(800,640);
    GLInit(); 
    while(CC.Running)
    {
        CC.Run();
        //PP.Show(-1.0,1.0,1.0,-1.0,0.5);
        //T.Show(-1.0,1.0,1.0,1.0,1.0,0.2); 
        //K.Show(-1.0,0.8,1.0,1.0,1.0,0.2);
        //P.Show(-0.8,0.0,0.0,0.0,0.0,0.2);
        CC.Finish();
        er<<"��"<<CC.Calculate<<"������"<<endl;
    }
    //er<<t[10]<<endl;
    //er<<sizeof(int)<<endl;
    //er<<MC.RegeditID<<endl;
    //er<<sizeof(SDL_Event)<<endl;
    //er<<sizeof(SDLKey)<<endl;
    //er<<sizeof(int)<<endl;
    er.close();
}
