#ifndef  DIY_INFORMATION_H 
#define  DIY_INFORMATION_H 
#include <list>
#include <string>
#include <vector>
#include <map>
#include <GL/gl.h>
#include <SDL/SDL.H>
#include <SDL/SDL_opengl.h>
#include <GL/GLU.h>
#include "baseclass.h"
#include "glsimplify.h"
#define INFNULL 0 //初始化值，为空 
//注册ID
#define INFNOID 2 //未被给予的初始ID 
#define INFCONID  3 //控制中心的默认ID
 
//信息目标 
#define INFALL 2//全体可读 
#define INFNOTAR 0 //空信息，无目标 
#define INFRETURN 1 //返回信息类型 

//信息种类
#define INFCONREG -10 //从控制中心传来的注册信息 
#define INFREGEDIT -99 //插件传来的注册信息
#define INFUNREGEDIT -100 //从插件传来的反注册信息 
#define INFUNABLEEXITIMI -124577//取消立马退出反抛 
#define INFDESTORY -1477855//注销注册函数
#define INFCREATE -1457955//新建注册函数 



#define INFREFLASH -1235 //刷新信息 
#define INFEVENT -9 //事件信息 
#define INFEXIT -11 //退出 
#define INFMOUSE -8 //鼠标事件信息
  #define MOUSEMOTION -2 //鼠标移动
  #define MOUSEBUTTONDOWN -1 //鼠标健按下
  #define MOUSEBUTTONUP 0 //鼠标松开
    #define LEFT 1 //鼠标左键
    #define MIDDLE 2 //鼠标中键
    #define RIGHT 3 //鼠标右键 

#define INFKEY   -7 //键盘事件信息 
  #define INFKEYDOWN -98
  #define INFKEYUP -77
  
#define INFCONZJ -4567
#define INFCONTS -148
#define INFDELETE -6 //信息已经使用，删除 
#define INFNEXT   -5 //信息未被使用，继续下一轮询 
#define INFEMPTY  -3 //信息为空，不用删除 
#define INFASPECT 154

#define EMPTY InfEmpty //空信息，用于初始化信息类 
#define NEXT InfNext
union DataForInformation
{
    unsigned int ui;
    bool b;
    char c;
    int i;
    float f;
    double d;
    void* v;
};
class Information
{
    public:
    int Resource; //来源 
    int Target;
    int Category1;
    int Category2;
    int Category3;
    int Category4;
    std::string Inf;
    int Aspect;
    int Block;
    unsigned int Location;
    
    DataForInformation Data1;
    DataForInformation Data2;
    DataForInformation Data3;
    DataForInformation Data4;
    DataForInformation Data5;
    DataForInformation Data6;
    DataForInformation Data7;
    DataForInformation Data8;
    bool Is(const char* name)
    {
        const char* Point=Inf.c_str();
        for(;;++Point,++name)
        {
            if(*Point=='\0'&&*name=='\0')
            {
                return true;
            }else{ 
                if((*Point!=*name))
                {
                    return false;
                }
                if(*Point=='\0'||*name=='\0')
                {
                    return false;
                }
            }
        }
    }
    Information():Resource(INFNULL),Target(INFRETURN),Category1(INFNEXT),Category2(INFNULL),Category3(INFNULL),Category4(INFNULL),Inf("NULL"),Aspect(INFNULL),Block(INFNULL),Location(INFNULL)
    {
    }   
    Information(int mode):Resource(INFNULL),Target(INFNOTAR),Category1(INFNULL),Category2(INFNULL),Category3(INFNULL),Category4(INFNULL),Inf("NULL"),Aspect(INFNULL),Block(INFNULL),Location(INFNULL)
    {
        if(mode==0)
        {
        }
    }
    /*void operator=(Information& A,Information& B)
    {
        A.Resource=B.Resource;
        A.Target=B.Target;
        A.Category1=B.Category1;
        A.Category2=B.Category2;
        A.Category3=B.Category3;
        A.Category4=B.Category4;
        A.Inf=B.Inf;
        A.Aspect=B.Aspect;
        A.Block=B.Block;
        A.Location=B.Location;
        A.Data1=B.Data1;
        A.Data2=B.Data2;
        A.Data3=B.Data3;
        A.Data4=B.Data4;
        A.Data5=B.Data5;
        A.Data6=B.Data6;
        A.Data7=B.Data7;
        A.Data8=B.Data8;
        A.Data9=B.Data9;
        A.Data10=B.Data10;
    }*/
};
/*void check(std::string Name , Information& tt)
{
    while(Name.size()<=16)
        Name+=' ';
    er<<"**"<<Name<<"Resource:";
    if(tt.Resource==INFCONID)
        er<<"控制中心";
    else
        er<<tt.Resource;
    er<<",Target:";
    if(tt.Target==INFALL)
        er<<"全体  ";
    else if(tt.Target==INFNOTAR)
        er<<"无目标";
    else if(tt.Target==INFRETURN)
        er<<"返回  ";
    else if(tt.Target==INFCONID)
        er<<"控制中心  ";
    else
        er<<tt.Target;
    er<<",Category1:";
    if(tt.Category1==INFCONREG)
        er<<"注册";
    else if(tt.Category1==INFEVENT)
        er<<"事件";
    else if(tt.Category1==INFNEXT)
        er<<"下个";
    else if(tt.Category1==INFDELETE)
        er<<"删除";
    else if(tt.Category1==INFEMPTY)
        er<<"  空";
        else if(tt.Category1==INFNULL)
        er<<"  空"; 
        else
        er<<tt.Category1;
    er<<",Category2:";
    switch(tt.Category2)
    {
        case INFKEY:
            er<<"键盘";
            break;
        case INFMOUSE:
            er<<"鼠标";
            break; 
        default:
            er<<tt.Category2;
    }
    er<<" ,Category3:"<<tt.Category3<<endl;
    if(tt.Category3==INFKEYDOWN)
       er<<tt.Data1.i<<endl;
    er<<"End**"<<endl;
}*/
void GetData(Information& T1,Information& T2)
{
    T1.Data1=T2.Data1;
    T1.Data2=T2.Data2;
    T1.Data3=T2.Data3;
    T1.Data4=T2.Data4;
    T1.Data5=T2.Data5;
    T1.Data6=T2.Data6;
    T1.Data7=T2.Data7;
    T1.Data8=T2.Data8;
}
/*void Check(std::string tte,XYZF ty)
{
    er<<tte<<"   "<<"  X: "<<ty.X<<"  Y:  "<<ty.Y<<"  Z:  "<<ty.Z<<" END "<<endl;
}*/
Information InfEmpty(0);
Information InfNext;
#endif
