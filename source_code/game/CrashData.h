#ifndef DIY_CRASHDATA_H
#define DIY_CRASHDATA_H
#include <list>
#include <vector>
#include "information.h"
#include "baseclass.h"
#include "crashbase.h"
class CrashFeekback
{
    friend class CrashData;
    CrashData* Poi;
    XYZF Vector;
    XYZF SpeedVector;
    bool Mode;//TRUE表示主动； 
    operator CrashData*(){return Poi;}
    CrashFeekback(CrashData* P,XYZF& V,XYZF& V2,bool S):Poi(P),Vector(V),SpeedVector(V2),Mode(S){}
    void Set(CrashData* P,XYZF& V,XYZF& V2,bool S){Poi=P;Vector=V;SpeedVector=V2;Mode=S;}
};
class CrashData
{
    protected:
    public:
        unsigned int ID;
        CrashMode Mode;
        CrashStyle Style;
        std::vector<CrashSingleData> ValueData;
        std::list<CrashSingleData> ValueDataE;
        std::list<CrashFace> FaceData;
        XYZF Up;
        XYZF Front;
        XYZF Location;
        
        bool Crash;
        std::list<CrashFeekback> FeekbackData;
        
        bool (*Function)(const XYZF& Location, float Distance);
        bool (*RegeditFunction)(const XYZF& Location);
        void Set(const float* Point,int number,std::vector<CrashSingleData>& ValueData,std::list<CrashSingleData>& ValueDataE);
        inline void Set(const float* Poi,int number){Set(Poi,number,ValueData,ValueDataE);}
        bool Check(const XYF& Location,std::vector<CrashSingleData>& ValueData,std::list<CrashSingleData>& ValueDataE);
        bool Check(CrashData*);
        inline bool Check(const XYF& Location){return Check(Location,ValueData,ValueDataE);}
        void FaceAdd(const float* Data,int number);
        bool CheckFace(CrashData* Tem,XYZF& Vector);
        Information Regedit();
        CrashData(const CrashStyle& Tem):Style(Tem),Front(0.0,0.0,1.0),Up(0.0,1.0,0.0){}
        bool FeekAction(void);
        //virtual void Action(void);
        Information (*Action)(CrashData*);
        virtual bool CrashAction(XYZF&);
        inline void SetFunction(void (*action)(CrashData*)){Action=action;}
        void Feekback(CrashData* P,XYZF& V,XYZF& V2,bool S);
        bool Check(CrashData* Tem,const XYZF& Vector);
        /*void CheckTT()
        {
            glColor3f(0.0,1.0,0.0);
            glBegin(GL_LINE_LOOP);
			for(std::vector<CrashSingleData>::iterator Poi=ValueData.begin();Poi!=ValueData.end();++Poi)
			{
				error<<"("<<Poi->Data.X<<","<<Poi->Data.Y<<")"<<" ";
				if(Poi->PE!=NULL) error<<"*";
				glVertex2f(Poi->Data.Y/4.0,Poi->Data.X/4.0);
			}
			error<<"End"<<endl;
			glEnd();
			glColor3f(0.0,1.0,0.0);
            glBegin(GL_POINTS);
			for(std::list<CrashSingleData>::iterator Poi=ValueDataE.begin();Poi!=ValueDataE.end();++Poi)
			{
				error<<"("<<Poi->Data.X<<","<<Poi->Data.Y<<")"<<" ";
				glVertex2f(Poi->Data.Y/4.0,Poi->Data.X/4.0);
			}
			error<<"End"<<endl;
			glEnd();
        }*/
        void CheckFace()
        {
            int i=FaceData.size();
            error<<"当前面数："<<FaceData.size()<<endl;
            std::list<CrashFace>::iterator Poi=FaceData.begin();
            for(int k=0;k<i;++k)
            {
                error<<"Face:"<<k+1<<endl;
                error<<"Location :("<<Poi->Location.X<<","<<Poi->Location.Y<<","<<Poi->Location.Z<<")"<<endl;
                error<<"向量  ("<<Poi->Vector.X<<","<<Poi->Vector.Y<<","<<Poi->Vector.Z<<")"<<endl;
                error<<"向量2  ("<<Poi->AuxiliaryVector.X<<","<<Poi->AuxiliaryVector.Y<<","<<Poi->AuxiliaryVector.Z<<")"<<endl;
                
            }
        } 
};
#include "Crashdata.cpp"
#endif
