#ifndef DIY_NUMBEROUT_H
#define DIY_NUMBEROUT_H
#include <stdio.h>
#include <string>
#include <list>
#include <map>
#include "sgprint.h"
#include "stdio.h"
#define NUM_FLOAT 1
#define NUM_INT 2
class NumberOut:public Sentence3D
{
    int Mode;
    void* Point;
    Sentence3D Perfix;
    public:
        bool Inable;
        void Set(void* Poi,const int Mode2);
        void Set(const std::string rr);
        void Off(void);
        void In(void);
        XYZF Show(const float X,const float Y,const ControlCenter* CC,const float Size2);
        void Reflesh();
        NumberOut();
};



class Number
{
    std::list<NumberOut> Data;
    std::map<int , std::list<NumberOut>::iterator > List;
    int NowUsing;
    ControlCenter* CC;
    public:
        Number();
        int Set(void* P,int Mode,std::string Perfix);
        XYZF Show(int Number, float X,float Y);
        void Init(ControlCenter* re);
        void Reflesh(int Number);
        void Reflesh(const int* ty,int Number);
        void In(int Number);
        void In(const int* ty,int Number);
        void Off(int Number);
        void Off(const int* ty,int Number);
};



void NumberOut::Set(void* Poi,const int Mode2)
{
    switch(Mode2)
    {
        case NUM_FLOAT:
            Point=Poi;
            Mode=Mode2;
            break;
        case NUM_INT:
            Point=Poi;
            Mode=Mode2;
    }
    Reflesh();
}
void NumberOut::Set(const std::string rr)
{
    Perfix.Delete();
    Perfix.Add(rr);
}
void NumberOut::Off(void)
{
    Inable=false;
}
void NumberOut::In(void)
{
    Inable=true;
}
XYZF NumberOut::Show(const float X,const float Y,const ControlCenter* CC,const float Size2=0.1)
{
    if(Inable)
    {
        return Sentence3D::Show(Perfix.Show(XYZF(X*(CC->NX),Y*(CC->NY),-(CC->Near)-0.0108),XYZF(0.0,-1.0,0.0),XYZF(0.0,0.0,1.0),1.0f,1.0f,1.0f,Size2*CC->NX),
                                                                                                   XYZF(0.0,-1.0,0.0),
                                                                                                    XYZF(0.0,0.0,1.0),1.0f,1.0f,1.0f,Size2*CC->NX);                                                     
    }
    return XYZF(0.0,0.0,0.0);
}
void NumberOut::Reflesh()
{
    if(Inable)
    {
        float* F=static_cast<float*>(Point);
        int* I=static_cast<int*>(Point);
        char Tem[20];
        std::string St;
        switch(Mode)
        {
            case NUM_FLOAT:
                sprintf(Tem, "%.4f",*F);
                St=Tem;
                Delete();
                Add(St);
                break;
            case NUM_INT:
                sprintf(Tem, "%d",*I);
                St=Tem;
                Delete();
                Add(St);
                break;
        }
    }
}
NumberOut::NumberOut()
{
    Inable=true;
    Mode=0;
}










Number::Number()
{
    NowUsing=0;
}
int Number::Set(void* P,int Mode,std::string Perfix="")
{
    NumberOut Tr;
    Tr.Set(P,Mode);
    Tr.Set(Perfix);
    Tr.Off();
    Data.push_back(Tr);
    std::list<NumberOut>::iterator Tty=Data.end();
    Tty--;
    ++NowUsing;
    List.insert(make_pair(NowUsing,Tty));
    return NowUsing;
}
XYZF Number::Show(int Number, float X,float Y)
{
    if(List.count(Number)>0)
    {
        if(List[Number]->Inable)
        {
            return (List[Number])->Show(X,Y,CC);
        }else{
            return XYZF(0.0,0.0,0.0);
        }
    }else{
        return XYZF(0.0,0.0,0.0);
    }
}
void Number::Init(ControlCenter* re)
{
    CC=re;
}
void Number::Reflesh(int Number)
{
    if(List.count(Number)>0)
    {
        List[Number]->Reflesh();
    }
}
void Number::Reflesh(const int* ty,int Number)
{
    for(int i=0;i<Number;++i)
    {
        Reflesh(ty[i]);
    }
}


void Number::In(int Number)
{
    if(List.count(Number)>0)
    {
        List[Number]->In();
    }
}
void Number::In(const int* ty,int Number)
{
    for(int i=0;i<Number;++i)
    {
        In(ty[i]);
    }
}
void Number::Off(int Number)
{
    if(List.count(Number)>0)
    {
        List[Number]->Off();
    }
}
void Number::Off(const int* ty,int Number)
{
    for(int i=0;i<Number;++i)
    {
        Off(ty[i]);
    }
}

#endif
