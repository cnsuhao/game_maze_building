#ifndef DIY_CRASH_CPP
#define DIY_CRASH_CPP
#include "Crash.h"
void Crash::ChangeMap(CrashMap* Poi)//传入的应该是类型为OccypuMap类型的指针 
{
    if(Poi->X>=1&&Poi->Z>=1&&Poi->MaxX>Poi->MinX&&Poi->MaxZ>Poi->MinZ)
    {
        BlockData.clear();
        LiveData.clear();
        float X1=Poi->MaxX;
        float X2=Poi->MinX;
        float Z1=Poi->MaxZ;
        float Z2=Poi->MinZ;
        unsigned int x=Poi->X;
        unsigned int z=Poi->Z;
        float EachX=(X1-X2)/x;
        float EachZ=(Z1-Z2)/z;
        std::list<XYF> DX;
        std::list<XYF> DY;
        float TX=X1;
        for(int k=0;k<x;++k)
        {
            XYF Tr(TX,TX-EachX);
            DX.push_back(Tr);
            TX=TX-EachX;
        }
        DX.push_back(XYF(TX,X2));
        float TZ=Z1;
        for(int k=0;k<z;++k)
        {
            XYF Tr(TZ,TZ-EachZ);
            DZ.push_back(Tr);
            TZ=TZ-EachZ;
        }
        DZ.push_back(XYF(TZ,Z2));
        for(std::list<XYF>::iterator Poi=DX.begin();Poi!=DX.end();++Poi)
        {
            for(std::list<XYF>::iterator Poi2=DZ.begin();Poi!=DZ.end();++Poi)
            {
                CrashBlock Tc(Poi->Y,Poi2->Y,Poi->X,Poi2->X);
                BlockData.push_back(Tc);
            }
        }
        MapPoi=Poi;
    }
}
void CrashBlock::Text(CrashData* Poi)
{
    bool Chare=false;
    for(int i=1;i<=4&&(!Chare);++i)
    {
        XYF Te=Get(i);
        XYZF Tr(Te.X,0.0,Te.Y);
        XYZF Left=(Poi->Up&Poi->Front).Uint();
        Tr=Tr-Poi->Location;
        Tr=Tr.ToCoordinate(Left,Poi->Up,Poi->Front);
        Te.Set(Tr.X,Tr.Y);
        Chare=Poi->Check(Te);
    }
    if(Chare)  Point.push_back(Poi);
}
void CrashBlock(CrashData* Poi)
{
    if(!Point.empty())
    {
        std::list<CrashData*>::iterator Ty=Point.begin();
        for(;Ty!=Point.end();++Ty)
        {
            if(*Ty==Poi)
            {
                Point.earse(Ty);
                break;
            }
        }
    }
}
void Crash::Regedit(CrashData* Poi)
{
    switch(Style)
    {
        case Limited:
        case Dead:
            std::list<BlockData>::iterator Poi=BlockData.begin();
            for(;Poi!=Block.end();++Poi)    Poi->Text(*Poi);
            break;
        case Live:
            LiveData.push_back(Poi);
            break;
    }
}
Information Crash::Check(CrashData* Tem,const XYZF& Vector,CarshData* Tcc=NULL)
{
    if(MapPoi!=NULL)
    {
        if(!MapPoi->DataValue.empty()&&!Tem->ValueData.empty())
        {
            XYZF Left=(Tem->Up&Tem->Front).Uint();
            XYZF Left2=(MapPoi->Up&MapPoi->Front).Uint();
            for(std::list<SingleCrashData>::iterator Yt=Tem->ValueData.begin();Yt!=Tem->ValueData.end();++Yt)
            {
                XYZF Tr(Yt->Data.X,0.0,Yt->Data.Y);
                Tr=Tr.FromCoordinate(Left,Tem->Up,Tem->Front);
                Tr=Tr+Tem->Location-MapPoi->Location+Vector;
                Tr=Tr.ToCoordinate(Left2,MapPoi->Up,MapPoi->Front);
                XYF Tc(Tr.X,Tr.Z);
                if(!MapPoi->Check(Tc))
                {
                    Information Ter;
                    Tre.Category1=CRASHOUTMAP;
                    return Tre;
                }//输出，在地图外 
            }
            for(std::list<SingleCrashData>::iterator Yt=MapPoi->ValueData.begin();Yt!=MapPoi->ValueData.end();++Yt)
            {
                XYZF Tr(Yt->Data.X,0.0,Yt->Data.Y);
                Tr=Tr.FromCoordinate(Left2,MapPoi->Up,MapPoi->Front);
                Tr=Tr-Tem->Location+MapPoi->Location-Vector;
                Tr=Tr.ToCoordinate(Left,Tem->Up,Tem->Front);
                XYF Tc(Tr.X,Tr.Z);
                if(!Tem->Check(Tc))
                {
                    Information Ter;
                    Tre.Category1=CRASHOUTMAP;
                    return Tre;
                }//输出，在地图外 
            }
            for(std::list<CrashData*>::iterator Ty=LiveData.begin();Ty!=LiveData.end();++Ty)//判断自由物体 
            {
                if(*Ty!=Tcc&&*Ty!=Tem)
                {
                    if(Tem->Check(*Ty))
                    {
                        if(Tem->CheckFace(*Ty,Vector))
                        {
                            Information Ter;
                            Tre.Category1=CRASHFACE;
                            Tre.Category2=(*Ty)->Style;
                            Tre.Data1=static_cast<void*>(*Ty);
                            return Tre;
                        }//输出，面碰撞了 
                    }
                }
            }
            for(std::list<CrashData*>::iterator Ty=TemDeadData.begin();Ty!=TemDeadData.end();++Ty)//判断临时自由物体 
            {
                if(*Ty!=Tcc&&*Ty!=Tem)
                {
                    if(Tem->Check(*Ty))
                    {
                        if(Tem->CheckFace(*Ty,Vector))
                        {
                            Information Ter;
                            Tre.Category1=CRASHFACE;
                            Tre.Category2=(*Ty)->Style;
                            Tre.Data1=static_cast<void*>(*Ty);
                            return Tre;
                        }//输出，面碰撞了 
                    }
                }
            }
            for(std::list<CrashBlock>::iterator Tr=BlockData.begin();Tr!=BlockData.end();++Tr)//判断限制物体 
            {
                for(int i=1;i<=4;++i)
                {
                    XYF Re=Tr->Get(i);
                    XYZF Rc(Re.X,0.0,Re.Y);
                    Rc=Rc.FromCoordinate(Left2,MapPoi->Up,MapPoi->Front);
                    Rc=Rc+MapPoi->Location-Tem->Location-Vector;
                    Rc=Rc.ToCoordinate(Left,Tem->Up,Tem->Front);
                    Re.Set(Re.X,Re.Z);
                    if(Tem->Check(Re))
                    {
                        for(std::list<CrashData*>::iterator Ui=Tr->Point.begin();Ui!=Tr->Point.end();++Ui)
                        {
                            if(Tem-Check(*Ui))
                            {
                                if(Tem->CheckFace(*Ui,Vector))
                                {
                                    Information Ter;
                                    Tre.Category1=CRASHFACE;
                                    Tre.Category2=(*Ty)->Style;
                                    Tre.Data1=static_cast<void*>(*Ty);
                                    return Tre;
                                }//输出，碰撞了 
                            }
                        }
                    }
                }
            }
            Information Fr;
            Fr.Category1=CRASHNOCRASH;
            return Fr;
        }
    }
    Information Fr;
    Fr.Category1=CRASHNODATA;
    return Fr;
}
#endif
