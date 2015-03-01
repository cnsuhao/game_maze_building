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
#define INFNULL 0 //��ʼ��ֵ��Ϊ�� 
//ע��ID
#define INFNOID 2 //δ������ĳ�ʼID 
#define INFCONID  3 //�������ĵ�Ĭ��ID
 
//��ϢĿ�� 
#define INFALL 2//ȫ��ɶ� 
#define INFNOTAR 0 //����Ϣ����Ŀ�� 
#define INFRETURN 1 //������Ϣ���� 

//��Ϣ����
#define INFCONREG -10 //�ӿ������Ĵ�����ע����Ϣ 
#define INFREGEDIT -99 //���������ע����Ϣ
#define INFUNREGEDIT -100 //�Ӳ�������ķ�ע����Ϣ 
#define INFUNABLEEXITIMI -124577//ȡ�������˳����� 
#define INFDESTORY -1477855//ע��ע�ắ��
#define INFCREATE -1457955//�½�ע�ắ�� 



#define INFREFLASH -1235 //ˢ����Ϣ 
#define INFEVENT -9 //�¼���Ϣ 
#define INFEXIT -11 //�˳� 
#define INFMOUSE -8 //����¼���Ϣ
  #define MOUSEMOTION -2 //����ƶ�
  #define MOUSEBUTTONDOWN -1 //��꽡����
  #define MOUSEBUTTONUP 0 //����ɿ�
    #define LEFT 1 //������
    #define MIDDLE 2 //����м�
    #define RIGHT 3 //����Ҽ� 

#define INFKEY   -7 //�����¼���Ϣ 
  #define INFKEYDOWN -98
  #define INFKEYUP -77
  
#define INFCONZJ -4567
#define INFCONTS -148
#define INFDELETE -6 //��Ϣ�Ѿ�ʹ�ã�ɾ�� 
#define INFNEXT   -5 //��Ϣδ��ʹ�ã�������һ��ѯ 
#define INFEMPTY  -3 //��ϢΪ�գ�����ɾ�� 
#define INFASPECT 154

#define EMPTY InfEmpty //����Ϣ�����ڳ�ʼ����Ϣ�� 
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
    int Resource; //��Դ 
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
        er<<"��������";
    else
        er<<tt.Resource;
    er<<",Target:";
    if(tt.Target==INFALL)
        er<<"ȫ��  ";
    else if(tt.Target==INFNOTAR)
        er<<"��Ŀ��";
    else if(tt.Target==INFRETURN)
        er<<"����  ";
    else if(tt.Target==INFCONID)
        er<<"��������  ";
    else
        er<<tt.Target;
    er<<",Category1:";
    if(tt.Category1==INFCONREG)
        er<<"ע��";
    else if(tt.Category1==INFEVENT)
        er<<"�¼�";
    else if(tt.Category1==INFNEXT)
        er<<"�¸�";
    else if(tt.Category1==INFDELETE)
        er<<"ɾ��";
    else if(tt.Category1==INFEMPTY)
        er<<"  ��";
        else if(tt.Category1==INFNULL)
        er<<"  ��"; 
        else
        er<<tt.Category1;
    er<<",Category2:";
    switch(tt.Category2)
    {
        case INFKEY:
            er<<"����";
            break;
        case INFMOUSE:
            er<<"���";
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
