#include <fstream>
using namespace std;
fstream error;
#include "ControlCenter.h"
#include "View.cpp"
#include "Light.h"
#include "WelcomeAspect.cpp"
#include "Object.h"
using namespace std;
ControlCenter CC;
View Vi;
WelcomeAspect WA;
Light Li;
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
    glDepthFunc(GL_LEQUAL); // 所作深度测试的类型
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
    //glShadeModel(GL_SMOOTH);
}
int main(int argc, _TCHAR* argv[])
{
    error.open("总之是个测试.txt",ios::out);
    CC.Regedit(&Vi);
    CC.Regedit(&WA);
    CC.Regedit(&Li);
    CC.Ready();
    CC.Init(3);
    GLInit();
    while(CC.Running)
    {
        CC.Run();
        CC.Finish();
    }
}
