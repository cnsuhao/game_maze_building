/*
数据结构
9个CHAR类型，表示版本与编号
1个INT类型，表示所有面的个数


    ---------------
    1个INT类型，表示模式
    1个INT类型，表示总行数

    1个INT类型，表示该行所占有的空间 
    1个INIT类型，看看还有什么要用的~ 
         --------------------
         详细内容，前3个FLOAT类型表示颜色，后三个FLOAT类型表示位置
         --------------------
    --------------- 



    ---------------
    1个INT类型，表示模式
    1个INT类型，表示总行数

    1个INT类型，表示该行所占有的空间 
    1个INIT类型，看看还有什么要用的~ 
         --------------------
         详细内容，前3个FLOAT类型表示颜色，后三个FLOAT类型表示位置
         --------------------
    --------------- 

*/
#ifndef DIY_OBJECT_H
#define DIY_OBJECT_H
#include <fstream>
#include <list>
#include <vector>
#include "Information.h"
#include "baseclass.h"
#include "glsimplify.h"
char EDITION[]="20120219";
class FaceOfObject
{
    int Size;
    int Face;
    int Picture;
    public:
        char* Turn(float* TY)
        {
            void* Tem;
            char* Tem2;
            Tem=static_cast<void*>(TY);
            Tem2=static_cast<char*>(Tem);
            return Tem2;
        }
        char* Turn(int* TY)
        {
            void* Tem;
            char* Tem2;
            Tem=static_cast<void*>(TY);
            Tem2=static_cast<char*>(Tem);
            return Tem2;
        }
        bool Init(int Mode,std::vector< std::list<XYZF> >& Tem2,std::vector< std::list<XYZF> >& Tem3)
        {
            std::vector< std::list<XYZF> >::iterator Point1=Tem2.begin();
            std::vector< std::list<XYZF> >::iterator Point2=Point1+1;
            std::vector< std::list<XYZF> >::iterator Point3=Tem3.begin();
            std::vector< std::list<XYZF> >::iterator Point4=Point3+1;
            
            std::list<XYZF>::iterator LisPoint1;
            std::list<XYZF>::iterator LisPoint2;
            
            std::list<XYZF>::iterator LisPoint3;
            std::list<XYZF>::iterator LisPoint4;
            
            
            
            std::list<XYZF>::iterator LisPointE;
            std::list<XYZF>::iterator LisPointE2;
            Face=glGenLists(1);
            glNewList(Face,GL_COMPILE);
            for(;Point1!=Tem2.end()&&Point2!=Tem2.end();Point1=Point2,Point2++,Point3=Point4,Point4++)
            {
                LisPoint1=Point1->begin();
                LisPoint2=Point2->begin();
                LisPoint3=Point3->begin();
                LisPoint4=Point4->begin();
                
                
                
                ++LisPoint1;
                ++LisPoint2;
                
                ++LisPoint3;
                ++LisPoint4;
                bool Tem=true;
                for(int i=0;!(LisPoint1==Point1->end()&&LisPoint2==Point2->end());++i,++LisPoint1,++LisPoint2,++LisPoint3,++LisPoint4)
                {
                    --LisPoint1;
                    --LisPoint2;
                    --LisPoint3;
                    --LisPoint4;
                    
                    switch(i%2)
                    {
                        case 1:
                            LisPointE=LisPoint2;
                            LisPointE2=LisPoint4;
                            LisPointE++;
                            LisPointE2++;
                            if(LisPointE==Point2->end())    continue;
                            break;
                        case 0:
                            LisPointE=LisPoint1;
                            LisPointE++;
                            LisPointE2=LisPoint3;
                            LisPointE2++;
                            if(LisPointE==Point1->end())    continue;
                            break;
                    }
                   // error<<"Init:"<<"("<<LisPoint1->X<<" "<<LisPoint1->Y<<" "<<LisPoint1->Z<<")"<<endl; 
                    //error<<"Init:"<<"("<<LisPoint2->X<<" "<<LisPoint2->Y<<" "<<LisPoint2->Z<<")"<<endl; 
                    //error<<"Init:"<<"("<<LisPointE->X<<" "<<LisPointE->Y<<" "<<LisPointE->Z<<")"<<endl;
                    error<<Face<<endl;
                    glBegin(GL_TRIANGLES);
                    glNormal(((*LisPoint1-*LisPoint2)&(*LisPointE-*LisPoint1)).Uint());
                    glColor(*LisPoint3);
                    glVertex(*LisPoint1);
                    glColor(*LisPoint4);
                    glVertex(*LisPoint2);
                    glColor(*LisPointE2);
                    glVertex(*LisPointE);
                    glEnd();
                    if(i%2==1)
                    {
                        LisPoint2=LisPointE;
                        LisPoint4=LisPointE2;
                    }else if(i%2==0)
                    {
                        LisPoint1=LisPointE;
                        LisPoint3=LisPointE2;
                    }
                }
            }
            glEndList();
        }
        bool Draw()
        {
            if(Face!=0)
            {
                glColor3f(1.0,1.0,1.0);
                glCallList(Face);
            }
        }
        FaceOfObject(){}
        FaceOfObject(int Mode, std::vector< std::list<XYZF> >& Point, std::vector< std::list<XYZF> >& Point2)
        {
            Init(Mode,Point,Point2);
        }

};
class Object
{
    std::vector<FaceOfObject> Data;
    public:
        bool compare(char* T1,char* T2)
        {
            for(;*T1!='\0'&&*T2!='\0';++T1,++T2)
            {
                if(*T1!=*T2) return false;
            }
            return true;
        }
        char* Turn(int* TY)
        {
            void* Tem;
            char* Tem2;
            Tem=static_cast<void*>(TY);
            Tem2=static_cast<char*>(Tem);
            return Tem2;
        }
        char* Turn(float* TY)
        {
            void* Tem;
            char* Tem2;
            Tem=static_cast<void*>(TY);
            Tem2=static_cast<char*>(Tem);
            return Tem2;
        }
        char* Turn(void* TY)
        {
            char* Tem2;
            Tem2=static_cast<char*>(TY);
            return Tem2;
        }
       /* bool Read(std::string Name)
        {
            fstream File;
            char Edition[9];
            int FaceNumber;
            int SizeOfFace;
            void* Data2;
            File.open(Name.c_str(),ios::in);
            if(File==NULL)
            {
                error<<"jiushizheyang"<<endl;
                return false;
            }
            File.read(Edition,9);
            if(!compare(Edition,EDITION))
            {
                error<<"jiushizheyang"<<endl;
                return false;
            }
            File.read(Turn(&FaceNumber),sizeof(int));
            if(FaceNumber<0) return false;
            for(int i=1;i<=FaceNumber;++i)
            {
                File.read(Turn(&SizeOfFace),sizeof(int));
                Data2=operator new[](SizeOfFace);
                if(Data2==NULL) return false;
                float* Data3=static_cast<float*> (Data2);
                File.read(Turn(Data3),SizeOfFace);
                FaceOfObject Ty(SizeOfFace,Data3);
                Data.push_back(Ty);
                operator delete[](Data2);
                Data2=NULL;
            }
            File.close();
            File.open("tryyy.txt",ios::out);
            File<<Edition<<endl;
            //File<<AllSize<<std::endl;
            File.close();
            return true;
        }*/
        bool Read(std::string Name)//测试版本 
        {
            fstream File;
            char Edition[9];
            int FaceNumber;
            int SizeOfFace;
            int Mode;
            int Line;
            void* Data2;
            File.open(Name.c_str(),ios::in|ios::binary);
            if(File==NULL) return false;
            File.read(Edition,9);
            if(!compare(Edition,EDITION))return false;
            File.read(Turn(&FaceNumber),sizeof(int));
            if(FaceNumber<0) return false;
            //error<<"版本"<<Edition<<endl;
            //error<<"面数"<<FaceNumber<<endl;
            for(int i=1;i<=FaceNumber;++i)
            {
                std::vector< std::list<XYZF> > Point;
                std::vector< std::list<XYZF> > Color;
                error<<endl;
                //File.read(Turn(&SizeOfFace),sizeof(int));
                File.read(Turn(&Mode),sizeof(int));
                File.read(Turn(&Line),sizeof(int));
                //error<<"行数"<<Line<<endl; 
                for(int k=1;k<=Line;++k)
                {
                    int SizeofLine;
                    int Nouse;
                    std::list<XYZF> ColorLine;
                    std::list<XYZF> PoiLine;
                    File.read(Turn(&SizeofLine),sizeof(int));
                    //error<<"行大小"<<SizeofLine<<endl;
                    File.read(Turn(&Nouse),sizeof(int));
                    Data2=operator new[](SizeofLine);
                    float* Data3=static_cast<float*> (Data2);
                    if(Data2==NULL) return false;
                    File.read(Turn(Data3),SizeofLine);
                    float* Poi=static_cast<float*>(Data2);
                    for(int i=0;i<SizeofLine/sizeof(float);i+=6)
                    {
                        ColorLine.push_back(XYZF(*(Poi+i),*(Poi+1+i),*(Poi+2+i)));
                        PoiLine.push_back(XYZF(*(Poi+i+3),*(Poi+4+i),*(Poi+5+i)));
                        //error<<"("<<*(Poi+i)<<" "<<*(Poi+1+i)<<" "<<*(Poi+2+i)<<")"; 
                    }
                    error<<endl;
                    Point.push_back(PoiLine);
                    Color.push_back(ColorLine);
                    operator delete[](Data2);
                }
                FaceOfObject ty(Mode,Point,Color);
                Data.push_back(ty);
                //面的初始化 
            }
            File.close();
            return true;
        }
        void Show()
        {
            for(std::vector<FaceOfObject>::iterator Ty=Data.begin();Ty!=Data.end();++Ty)
            {
                //error<<"Show()"<<endl; 
                Ty->Draw();
            }
            //error<<"完了"<<endl;
        }
};

#endif
