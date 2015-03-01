#ifndef  DIY_INFORMATION_H 
#define  DIY_INFORMATION_H 
#include <list>
#include <string>
#include <vector>
#include <map>
#include "baseclass.h"
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
#define INFRESETTIME -20558//ˢ��ʱ����� 


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
    unsigned char uc;
    char c;
    int i;
    float f;
    double d;
    void* v;
    operator int(){return i;}
    operator bool(){return b;}
    operator char(){return c;}
    operator float(){return f;}
    operator double(){return d;}
    operator void*(){return v;}
    operator unsigned int(){return ui;}
    operator unsigned char(){return uc;}
    void operator= (unsigned char Tem){uc=Tem;}
    void operator= (char Tem){c=Tem;}
    void operator= (unsigned int Tem){ui=Tem;}
    void operator= (int Tem){i=Tem;}
    void operator= (float Tem){f=Tem;}
    void operator= (bool Tem){b=Tem;}
    void operator= (double Tem){d=Tem;}
    void operator= (void* Tem){v=Tem;}
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
}


















Information InfEmpty(0);
Information InfNext;
#endif
