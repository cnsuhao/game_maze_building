#include <stdio.h>
#include <fstream>
using namespace std;
fstream error("总之是个测试.txt",ios::out);
#include "ControlCenter.h"
#include "sgprint.h"
#include "Light.h"
#include "View.cpp"
#include "Cude.h"
#include "AspectForGameStart.cpp"
//#include "ControlForGame.cpp"
#include "HardControl.cpp"
#include "WelcomeAspect.cpp"
#include "Object.h"
#include "NumberOut.h"
using namespace std;
ControlCenter CC;
Light Li;
Aspect ty;
View yu;
//ControlForGame CFG;
//HardControl yd;
//WelcomeAspect WA;
void GLInit(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_SMOOTH);//设定着色模式，SMOOTH是平滑着色，FLAT是固定着色（使用某一定点颜色着色） 
        //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //gluOrtho2D(-1.0,1.0,-1.0,1.0);
    //gluPerspective(80,640/480,0.01,50);
    //glMatrixMode(GL_MODELVIEW);
    //glMatrixMode(GL_PROJECTION);
    //gluPerspective(60,static_cast<float>(640)/480,0.1,20);
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    //gluOrtho2D(-1.0,1.0,-1.0,1.0);
    //gluPerspective(40,640/480,0.01,50);
    //glMatrixMode(GL_MODELVIEW);
    glLineWidth(2.0);
    glEnable (GL_POLYGON_SMOOTH);
    glHint (GL_POLYGON_SMOOTH, GL_NICEST);
                //glEnable(GL_DEPTH_TEST); // 启用深度测试
            //glDepthFunc(GL_LESS); // 所作深度测试的类型
    glClearDepth(1.0f); // 设置深度缓存
    glEnable(GL_DEPTH_TEST); // 启用深度测试
    glDepthFunc(GL_LEQUAL); // 所作深度测试的类型fffffffff
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    //glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glLoadIdentity();
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPointSize(40);
    glShadeModel(GL_SMOOTH);
}
int main(int argc, _TCHAR* argv[])
{
    //error.open("总之是个测试.txt",ios::out);
    Object trrr;
    CC.Regedit(&yu);
    //CC.Regedit(&WA);
    CC.Regedit(&Li);
    CC.Regedit(&ty);
    //CC.Regedit(&CFG);
    //CC.Regedit(&yd);
    CC.Ready();
    CC.Init(3);
    trrr.Read("Textforface.bib");
    GLInit();
    while(CC.Running)
    {
        CC.Run();
        //trrr.Show();
        CC.Finish();
    }
}
