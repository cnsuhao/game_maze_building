#ifndef DIY_CRASHDATA_CPP
#define DIY_CRASHDATA_CPP
#include "Crashdata.h"
void CrashData::Set(const float* Point,int number,std::vector<CrashSingleData>& ValueData,std::list<CrashSingleData>& ValueDataE)
{
    if(number>=3)
    {
        bool Cricle2=false;
        ValueData.clear();
        ValueDataE.clear();
        if(Point[0]==Point[2*(number-1)]&&Point[1]==Point[2*(number-1)+1])    Cricle2=true;
        void* Memory=NULL;
        float* Temp;
        error<<"1"<<endl;
        //选取离质心最远点为开始点。 
        int k=number;
        if(Cricle2) k-=1;
        float X=0.0;
        float Z=0.0;
        for(int i=0;i<k;++i)
        {
            X+=Point[i*2];
            Z+=Point[i*2+1];
        }
        X/=k;
        Z/=k;
        float TemDistance=0.0;
        int Num;
        for(int i=0;i<k;++i)
        {
            float Tem=XYF(X,Z).Distance(XYF(Point[i*2],Point[i*2+1]));
            if(Tem>TemDistance)
            {
                Num=i;
                TemDistance=Tem;
            }
        }
        //error<<"2"<<endl;
        //重建数组 
        Memory=operator new[](sizeof(float)*(k+1)*2);
        Temp=static_cast<float*>(Memory);
        for(int p=0,i=Num;p<k;++i,++p)
        {
            if(i>=k) i=0;
            Temp[p*2]=Point[i*2];
            Temp[p*2+1]=Point[i*2+1];
        }
            Temp[k*2]=Point[Num*2];
            Temp[k*2+1]=Point[Num*2+1];
        //error<<"3"<<endl;
        //凹多边形凸化 
        std::vector<CrashSingleData> TemData;
        for(int i=0;i<=k;++i)
        {
            CrashSingleData Tem;
            Tem.Data.Set(Temp[i*2],Temp[i*2+1]);
            TemData.push_back(Tem);
        }
        std::vector<CrashSingleData>::iterator P1,P2,P3;
        P1=TemData.begin();
        P2=P1+1;
        P3=P2+1;
        bool Contiunation=false; 
        //error<<"4"<<endl;
        for(;P3!=TemData.end();)
        {
            //error<<"dfsdf"<<endl;
            if((*ConcaveCheck)(*P1,*P2,*P3))
            {
                CrashSingleData Temcc;
                if(!Contiunation)
                {
                    Temcc=*P1;
                    ValueDataE.push_back(Temcc);
                    P1->PE=ValueDataE.end();
                    --P1->PE;
                }
                Temcc=*P2;
                ValueDataE.push_back(Temcc);
                P3->PE=ValueDataE.end();
                --P3->PE;
                Contiunation=true;
                P2=P3;
                ++P3;
            }else{
                CrashSingleData Temcc;
                if(Contiunation)
                {
                    Temcc=*P2;
                    ValueDataE.push_back(Temcc);
                    P2->PE=ValueDataE.end();
                    --P2->PE;
                }
                Contiunation=false;
                if(P1==TemData.begin())  P1->Mode=CRASHBEGIN;
                else P1->Mode=CRASHMIDDLE;
                //P2->Mode=CRASHMIDDLE;
                ValueData.push_back(*P1);
                //ValueData.push_back(*P2);
                P1=P2;
                P2=P3;
                ++P3;
            }
        }
        //error<<"5"<<endl;
        if(P3==TemData.end())
        {
            P1->Mode=CRASHMIDDLE;
            P2->Mode=CRASHEND;
            ValueData.push_back(*P1);
            ValueData.push_back(*P2);
            error<<"Just a try"<<endl;
        }
        //进行数据的插入什么的东西目测已完成，等待检测。 检测完成 
        //CheckTT();
        error<<"dddddd"<<ValueData.size()<<endl;
        error<<"ccccc"<<ValueDataE.size()<<endl;
        //删除掉数组 
        operator delete[](Memory);
    }
}
//已测试 
bool CrashData::Check(const XYF& Point,std::vector<CrashSingleData>& ValueData,std::list<CrashSingleData>& ValueDataE)
{
    /*glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2f(Point.Y/4.0,Point.X/4.0);
    glEnd();*/
    std::vector<CrashSingleData>::iterator P1;
    std::vector<CrashSingleData>::iterator P2;
    if(!ValueData.empty())
    {
        bool Inside=true;
        float Dis=0.0;
        for(P1=ValueData.begin(),P2=ValueData.begin()+1;P2!=ValueData.end();P1=P2,++P2)
        {
            XYF PP1=*P2-*P1;
            XYF PP2=Point-*P1;
            XYF PP3(PP1.Y,-PP1.X);
            //error<<PP3.X<<" "<<PP3.Y<<"     X     "<<PP2.X<<" "<<PP2.Y<<" "<<endl;
            if(PP3*PP2<0)   Inside=false;
            else{
                //error<<"第二次判断啊"<<endl;
                if(P1->PE!=NULL&&P2->PE!=NULL)
                {
                    bool OutSide=true;
                    std::list<CrashSingleData>::iterator I=P2->PE;
                    //if(!Inside) error<<"zheli jiu meiyou le"<<endl;
                    //if(!OutSide) error<<"woshiegSB"<<endl;
                    //error<<"sdfsdf"<<endl;
                    while(I!=P1->PE)
                    {
                        if(!OutSide) break;
                        //error<<"12213212"<<endl;
                        XYF T1=*I;
                        I--;
                        XYF P2=*I-T1;
                        XYF P3=Point-T1;
                        XYF P4(P2.Y,-P2.X);
                        if(P4*P3<0) OutSide=false;
                    }
                    if(OutSide) Inside=false;
                }
                //if(Inside) error<<"jiushuoyige"<<endl;
                //else error<<"zhenshiwa"<<endl;
            }
            if(!Inside) break;    
        }
        //if(!Inside) error<<"dasfdfhfghghghjfgesfa"<<endl;
        return Inside;
    }
    return false;
}
//已测试 
bool CrashData::CheckFace(CrashData* Tem,XYZF& Vector)//未完，未测试 
{
    std::list<CrashFace>::iterator P1 =FaceData.begin();
    std::list<CrashFace>::iterator P2 = Tem->FaceData.begin();
    std::list< std::list<CrashFace>::iterator  > Face1;
    std::list< std::list<CrashFace>::iterator  > Face2;
    XYZF Left = (Up&Front).Uint();
    XYZF Left2 = (Tem->Up&Tem->Front).Uint();
    for(;P1!=FaceData.end();++P1)
    {
        XYZF V1(P1->Vector*Left,P1->Vector*Up,P1->Vector*Front); 
        if(V1* Vector>0)
        {
            Face1.push_back(P1);
            error<<"有一个落网"<<endl;
        }
    }
    for(;P2!=Tem->FaceData.end(); ++P2)
    {
        XYZF V2(P2->Vector*Left2,P2->Vector*Tem->Up,P2->Vector*Tem->Front);
        if(V2*Vector<0)
        {
            Face2.push_back(P2);
            error<<"OtherSide"<<endl;                    
        }                                                                                         
    }
    std::list< std::list<CrashFace>::iterator  >::iterator Face11=Face1.begin();
    std::list< std::list<CrashFace>::iterator  >::iterator Face22;
    for(;Face11!=Face1.end();++Face11)
    {
        std::list< CrashFace >::iterator Tem1=*Face11;
        XYZF AVector2(Tem1->Vector&Tem1->AuxiliaryVector);
        XYZF V=Tem1->Vector.FromCoordinate(Left,Up,Front);
        XYZF AV=Tem1->AuxiliaryVector.FromCoordinate(Left,Up,Front);
        XYZF AV1=AVector2.FromCoordinate(Left,Up,Front);
        XYZF Loc=Tem1->Location.FromCoordinate(Left,Up,Front);
        for(Face22=Face2.begin();Face22!=Face2.end();++Face22)
        {
            std::list< CrashFace >::iterator Tem2=*Face22;
            XYZF AVector22(Tem2->Vector&Tem2->AuxiliaryVector);
            XYZF V2=Tem2->Vector.FromCoordinate(Left2,Tem->Up,Tem->Front);
            XYZF AV2=Tem2->AuxiliaryVector.FromCoordinate(Left2,Tem->Up,Tem->Front);
            XYZF AV22=AVector22.FromCoordinate(Left2,Tem->Up,Tem->Front);
            XYZF Loc2=Tem2->Location.FromCoordinate(Left2,Tem->Up,Tem->Front);
            
            std::vector<CrashSingleData>::iterator P1=Tem1->Data.begin();
            std::vector<CrashSingleData>::iterator P2=Tem2->Data.begin();
            error<<Tem1->Data.size()<<endl;
            bool Right=true;
            for(;P1!=Tem1->Data.end();++P1)
            {
                XYZF Tee=P1->Data.X*AV1+P1->Data.Y*AV+Loc+Location-Tem->Location+Vector-Loc2;
                error<<"<"<<Tee.X<<","<<Tee.Y<<","<<Tee.Z<<")";
                XYZF er=Tee.ToCoordinate(AV22,AV2,V2);
                error<<"<"<<er.X<<","<<er.Y<<","<<er.Z<<")"<<endl;
                XYF Te2(er.X,er.Y);
                if(Check(Te2,Tem2->Data,Tem2->DataE))
                {
                    Right=false;
                    error<<"sdhkfksdf"<<er.Z<<endl;
                    if(er.Z<=0)
                    {
                        Feekback(Tem,V2,Vector,true);
                        Tem->Feekback(this,V,Vector,true);
                        return true;//这个时候表示碰撞了，要返回碰撞面的向量； 
                    }
                }
            }
            for(;P2!=Tem2->Data.end();++P2)
            {
                XYZF Tee=P2->Data.X*AV22+P2->Data.Y*AV2+Loc2+Tem->Location-Location-Vector-Loc;
                XYZF er=Tee.ToCoordinate(AV1,AV,V);
                XYF Te2(er.X,er.Y);
                if(Check(Te2,Tem1->Data,Tem1->DataE))
                {
                    if(er.Z<=0)
                    {
                        Feekback(Tem,V2,Vector,true);
                        Tem->Feekback(this,V,Vector,true);
                        return true;//这个时候表示碰撞了，要返回碰撞面的向量； 
                    }
                }
            }
            error<<"**NoCrash"<<endl;
        }
        //数据空缺 
    }
    return false;
    //数据空缺                                                                      
}
void CrashData::FaceAdd(const float* Data,int number)
{
    if(number>=3)
    {
        CrashFace Tem;
        std::list<XYZF> Te;
        for(int i=0;i<number;++i)
        {
            XYZF De(Data[i*3],Data[i*3+1],Data[i*3+2]);
            Te.push_back(De);
        }
        std::list<XYZF>::iterator Ty=Te.begin();
        std::list<XYZF>::iterator Td=Te.begin();
        ++Td;
        Tem.Location=*Ty;
        XYZF AV=(*Td-*Ty).Uint();
        Tem.AuxiliaryVector=AV;
        ++Td;++Ty;
        XYZF AV2=(*Td-*Ty).Uint();
        Tem.Vector=(AV&AV2).Uint();
        AV2=(Tem.Vector&AV).Uint();
        void* Data=operator new[](sizeof(float)*3*number);
        float* Point=static_cast<float*>(Data);
        Ty=Te.begin();
        for(int i=0;Ty!=Te.end()&&i<number;++Ty,++i)
        {
            XYZF Trr=*Ty-Tem.Location;
            Trr.Set(Trr*AV2,Trr*AV,0.0);
            Point[i*2]=Trr.X;
            Point[i*2+1]=Trr.Y;
            error<<"<"<<Point[i*2]<<","<<Point[i*2+1]<<">"<<endl;
        }
        Set(Point,number,Tem.Data,Tem.DataE);
        FaceData.push_back(Tem);
        operator delete[](Data);
    }
}
void CrashData::Feekback(CrashData* P,XYZF& V,XYZF& V2,bool S)
{
    Crash=true;
    CrashFeekback Feekback(P,V,V2,S);
    FeekbackData.push_front(Feekback);
}
bool CrashData::FeekAction(void)
{
    switch(this->Style)
    {
        case Dead:
        case DeadTem:
            /*if(Action!=NULL)
            {
                
            }else{
                return false;
            }*/
            break;
        case Live:
            break;
        case Limited:
            break;
        case Map:
            break;
    }
}
bool CrashData::Check(CrashData* Tem,const XYZF& Vector)//判断两个DATA是否相遇 
{
    XYZF Left=(Up&Front).Uint();
    XYZF Left2=(Tem->Up&Tem->Front).Uint();
    if(!ValueData.empty())
    {
        for(std::vector<CrashSingleData>::iterator Te=ValueData.begin();Te!=ValueData.begin();++Te)
        {
            XYZF Tecc(Te->Data.X,0.0,Te->Data.Y);
            Tecc.FromCoordinate(Left,Up,Front);
            Tecc=Tecc+Location-Tem->Location+Vector;
            Tecc.ToCoordinate(Left2,Tem->Up,Tem->Front);
            XYF Ter(Tecc.X,Tecc.Z);
            if(Tem->Check(Ter)) return true;
        }
        for(std::vector<CrashSingleData>::iterator Te=Tem->ValueData.begin();Te!=Tem->ValueData.end();++Te)
        {
            XYZF Tecc(Te->Data.X,0.0,Te->Data.Y);
            Tecc.FromCoordinate(Left2,Tem->Up,Tem->Front);
            Tecc=Tecc-Location+Tem->Location-Vector;
            Tecc.ToCoordinate(Left,Up,Front);
            XYF Ter(Tecc.X,Tecc.Z);
            if(Check(Ter)) return true;
        }
        return false;
    }
    return false;
}
#endif
