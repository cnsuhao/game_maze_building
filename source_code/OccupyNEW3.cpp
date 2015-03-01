

#include "Occupynew2.h"
void OccupyControl::ChangeMap(OccupyMap* Poi)//传入的应该是类型为OccypuMap类型的指针 
{
    Clean();
    BlockX=Poi->X;BlockZ=Poi->Z;
    float MX=(Poi->MaxX-Poi->MinX)/BlockX;float MZ=(Poi->MaxZ-Poi->MinZ)/BlockZ; 
    for(int i=0;i<BlockX;++i)
    {
        for(int k=0;k<BlockZ;++k)
        {
            OccupyBlock Te(Poi->MinX+MX*i,Poi->MinX+MX*(i+1),Poi->MinZ+MZ*k,Poi->MinZ+MZ*(k+1));
            XZData.push_back(Te);
        }
    }
    for(int k=0;k<=BlockZ;++k)
    {
        Z.push_back(Poi->MinZ+MZ*k);
    }
    for(int i=0;i<=BlockX;++i)
    {
        X.push_back(Poi->MinX+MX*i);
    }
    for(int i=0;i<=BlockZ*BlockX;++i)
    {
        OccupyData Tet(OCCMARK);
        XZLimited.push_back(Tet);
        XZDead.push_back(Tet);
        std::list<OccupyData>::iterator PL=XZLimited.end();
        std::list<OccupyData>::iterator PD=XZDead.end();
        --PL;--PD;
        OccupyPoint yu(PL,PD);
        XZEnsample.push_back(yu);
    }
    OccupyLimited* Tem=static_cast<OccupyLimited*>(Poi)
    LimitedAdd(Tem);
}//完 
bool OccupyControl::AddToBlock(int z1,int x1,OccupyData* Te,int z2,int x2,OccupyData* Te2,int Mode,std::vector<bool>& Tank)//起始点位置，数据，结束点位置，数据，模式，1为LIMITED，2为DEAD，储存布尔值的容器 
{
    int Block;
    for(int i=1;i<=BlockX;++i)
    {
        for(int k=1;k<=BlockZ;++k)
        {
            std::vector< OccupyPoint >::iterator Poi=XZEnsample.begin()+(i-1)*BlockZ+k;
            Block=CheckBlock(i,k,Te->D2,Te->D1,Te2->D2,Te2->D1);
            if( ((k<=z1&&k>=z2)||(k<=z2&&k>=z1))&&((i<=x1&&i>=x2)||(i<=x2&&i>=x1)))
            {
                OccupyData Ty=*Te;
                OccupyData Ty2=*Te2;
                if((k==z1&&i==x1)||(k==z2&&i==x2))
                {
                    if(z1==z2&&x1==x2)
                    {
                        
                    }else{
                        if(k==z1&&i==x1)
                            Ty2.Mode=OCCPEND;
                        else if(k==z2&&i==x2)
                            Ty.Mode=OCCPBEGIN;
                    }
                }else if(Block==3)
                {
                    Ty.Mode=OCCPBEGIN;
                    Ty2.Mode=OCCPEND;
                }else{
                    Mode=4;
                }
                if(Mode==1)
                {
                    XZLimited.insert(Poi->PL,Ty);
                    XZLimited.insert(Poi->PL,Ty2);
                }else if(Mode==2)
                {
                    XZDead.insert(Poi->PD,Ty);
                    XZDead.insert(Poi->PD,Ty2);
                }
            }else{
                Mode=4;
            }
            if(Block==1)
                *(Tank.begin()+i*k-1)=(*(Tank.begin()+i*k-1))||true;
            if(Mode==1)
            {
                std::list<OccupyData>::iterator Iu=Poi->PL;
                OccupyData RT=*(--(--Iu));
                if(Iu!=XZLimited.begin())
                {
                    OccupyData RT2=*(--Iu);
                    if(RT.Mode==OCCPBEGIN&&RT2.Mode==OCCPEND)
                    {
                        if(RT==RT2)
                        {
                           XZLimited.eares(Iu);
                           Iu=Poi->PL;
                           --Iu;
                           Iu->Mode=OCCPMIDDLE;
                        }
                     }
                }
            }else if(Mode==2)
            {
                std::list<OccupyData>::iterator Iu=Poi->PD;
                OccupyData RT=*(--Iu);
                if(Iu!=XZDead.begin())
                {
                    OccupyData RT2=*(--Iu);
                    if(RT.Mode==OCCPBEGIN&&RT2.Mode==OCCPEND)
                    {
                        if(RT==RT2)
                        {
                           XZDead.earse(Iu);
                           Iu=Poi->PL;
                           --(--Iu);
                           Iu->Mode=OCCPMIDDLE;
                        }
                     }
                }
            }
        }
    }
    
}
void OccupyControl::LimitedAdd(OccupyLimited* Poi)//已完，未测试 
{
    int x1,z1,x2,z2;
    std::vector<bool> Tank(BlockZ*BlockX,false);
    for(std::list<OccupyData>::iterator P=Poi->ListXZ.begin();P->Mode!=OCCPEND&&P!=Poi->ListXZ.end();)
    {
        OccupyData D1=*P;
        OccupyData D2=*(++P);
        if(D1.Mode==OCCPBEGIN)
        {
            for(x2=0;x2<=BlockX;++x2)
            {
                std::vector<float>::iterator Bro=X.begin()+x2;
                if(D1.D2<*Bro)
                {
                    break;
                }
            } 
            for(z2=0;z2<=BlockZ;++z2)
            {
                std::vector<float>::iterator Bro=Z.begin()+z2;
                if(D1.D1<*Bro)
                {
                    break;
                }
            }
        }
        x1=x2;
        z1=z2;
        for(x2=0;x2<=BlockX;++x2)
        {
            std::vector<float>::iterator Bro=X.begin()+x2;
            if(D2.D2<*Bro)
            {
                break;
            }
        } 
        for(z2=0;z2<=BlockZ;++z2)
        {
            std::vector<float>::iterator Bro=Z.begin()+z2;
            if(D2.D1<*Bro)
            {
                break;
            }
        }
        AddToBlock(z1,x1,&D1,z2,x2,&D2,1,Tank);//目测应该完了…………………… 
    }
    for(int i=1;i<=BlockX;++i)
    {
        for(int k=1;k<=BlockZ;++k)
        {
            std::vector<bool>::iterator Yu=Tank.begin()+i*k-1;
            if(!(*Yu))
            {
                OccupyData Tu(OCCINCLUDE);
                XZLimited.insert((XZEnsample.begin()+(i-1)*BlockZ+k)->PL,Tu);
            }
        }
    }
}
void OccupyControl::DeadAdd(OccupyLimited* Poi)//直接从LIMITEDADD复制 
{
    int x1,z1,x2,z2;
    std::vector<bool> Tank(BlockZ*BlockX,false);
    for(std::list<OccupyData>::iterator P=Poi->ListXZ.begin();P->Mode!=OCCPEND&&P!=Poi->ListXZ.end();)
    {
        OccupyData D1=*P;
        OccupyData D2=*(++P);
        if(D1.Mode==OCCPBEGIN)
        {
            for(x2=0;x2<=BlockX;++x2)
            {
                std::vector<float>::iterator Bro=X.begin()+x2;
                if(D1.D2<*Bro)
                {
                    break;
                }
            } 
            for(z2=0;z2<=BlockZ;++z2)
            {
                std::vector<float>::iterator Bro=Z.begin()+z2;
                if(D1.D1<*Bro)
                {
                    break;
                }
            }
        }
        x1=x2;
        z1=z2;
        for(x2=0;x2<=BlockX;++x2)
        {
            std::vector<float>::iterator Bro=X.begin()+x2;
            if(D2.D2<*Bro)
            {
                break;
            }
        } 
        for(z2=0;z2<=BlockZ;++z2)
        {
            std::vector<float>::iterator Bro=Z.begin()+z2;
            if(D2.D1<*Bro)
            {
                break;
            }
        }
        AddToBlock(z1,x1,&D1,z2,x2,&D2,2,Tank);//目测应该完了…………………… 
    }
    for(int i=1;i<=BlockX;++i)
    {
        for(int k=1;k<=BlockZ;++k)
        {
            std::vector<bool>::iterator Yu=Tank.begin()+i*k-1;
            if(!(*Yu))
            {
                OccupyData Tu(OCCINCLUDE);
                XZDead.insert((XZEnsample.begin()+(i-1)*BlockZ+k)->PD,Tu);
            }
        }
    }
}
void OccupyControl::Clean(void)
{
    X.clear();
    Z.clear();
    XZEnsample.clear();
    XZData.clear();
    XZLive.clear();
    XZLimited.clear();
    XZDead.clear();
}
void OccupyDead::Print(std::list<OccupyData>& List,std::list<OccupyData>& ListE)
{
    std::list<OccupyData>::iterator y;
    for(y=List.begin();y!=List.end();++y)
    {
        if(y->Mode==OCCPBEGIN)
            ty<<"开始    ";
        else if(y->Mode==OCCPMIDDLE)
            ty<<"中间    ";
        else if(y->Mode==OCCPEND)
            ty<<"结尾    ";
        ty<<y->D1<<"    "<<y->D2<<endl;
        if(y->Point!=NULL)
        {
            std::list<OccupyData>::iterator yu=y->Point;
            //ty<<"youdongxi";
            for(;yu!=ListE.end();++yu)
            {
                ty<<"                      "<<yu->D1<<"    "<<yu->D2<<endl;
                if(yu->Point!=NULL)
                ty<<"haiy you"<<endl;
                if(yu->Mode==OCCPEND)
                {
                    break;
                }
            }
        }
    }
}
void OccupyDead::AddToList(float* DP,int Num,std::list<OccupyData> &List,std::list<OccupyData> & ListE)
{
    bool Ok;
    bool Cricle;
    float* Point;
    if(DP!=NULL&&Num!=0)
    {
        Ok=false;
        Cricle=false;
        if(DP[Num-2]==DP[0]&&DP[Num-1]==DP[1])
            Cricle=true;
        Point=DP;
        for(int i=1;i<=Num;i+=2,Point+=2)
        {
            if(i==1)
            {
                List.push_back(OccupyData(OCCPBEGIN,OCCNOUSE,*Point,*(Point+1),NULL));
            }else if(i==Num-1)
            {
                List.push_back(OccupyData(OCCPEND,OCCNOUSE,*Point,*(Point+1),NULL));
            }else{
                List.push_back(OccupyData(OCCPMIDDLE,OCCNOUSE,*Point,*(Point+1),NULL));
            }
        }
        std::list<OccupyData>::iterator P3=List.begin();
        std::list<OccupyData>::iterator P1=P3++;
        std::list<OccupyData>::iterator P2=P3++;            
        for(;;)
        {
                    //ty<<"jiance"<<endl;
            float X1=P2->D1 - P1->D1;              
            float Y1=P2->D2 - P1->D2;
            float X2=P3->D1 - P2->D1;
            float Y2=P3->D2 - P2->D2;
            if(X1*Y2-X2*Y1<0)
            {
                //ty<<"yige"<<endl;
                OccupyData D1=*P1;
                OccupyData D2=*P3;
                OccupyData D3=*P2;
                OccupyData D4=*P1;
                D1.Mode=OCCPBEGIN;
                D2.Mode=OCCPMIDDLE;
                D3.Mode=OCCPMIDDLE;
                D4.Mode=OCCPEND;
                ListE.push_back(D1);
                P1->Point=ListE.end();
                --(P1->Point);
                ListE.push_back(D2);
                ListE.push_back(D3);
                ListE.push_back(D4);
                List.erase(P2);
                P2=P3;
                P3++;
                if(P3==List.end())
                {
                    if(Cricle)
                    {
                        Ok=true;
                        P3=List.begin();
                        P3++;
                    }else{
                        break;
                    }
                }
            }else{
                P1=P2;
                P2=P3;
                P3++;
                if(Ok)
                {
                    break;
                }
                if(P3==List.end())
                {
                    if(Cricle)
                    {
                        Ok=true;
                        P3=List.begin();
                        P3++;
                    }else{
                        break;
                    }
                }
            }
        }
    }
}


bool OccupyControl::DeadCheck(float x,float y,float z,float dis)//在里面表示为TRUE 直接从原版复制，其正确性未知。 
{
    int xl=-1;
    int zl=-1;
    std::vector<float>::iterator Poi;
    if(!XZDead.empty())
    {
        for(Poi=X.begin();(Poi+1)!=X.end();++Poi)
        {
            if(x>*Poi&&x<=*(Poi+1))
            {
                xl=Poi-X.begin()+1;
                break;
            }
        }
        for(Poi=Z.begin();(Poi+1)!=Z.end();++Poi)
        {
            if(z>*Poi&&z<=*(Poi+1))
            {
                zl=Poi-Z.begin()+1;
                break;
            }
        }
        //er<<zl<<"  "<<xl<<endl;
        //er<<x<<" "<<z<<" END "<<endl;
        if(xl>=1&&zl>=1)
        {
            std::list<OccData>::iterator DP= * ((XZEnsample.begin()+(xl-1)*BlockZ+(zl-1))->PD) ;
            if(DP->Mode==OCCMARK)
            {
                float Tex=0.0;
                float Tez=0.0;
                bool Inside=true;
                std::list<OccData>::iterator Poi=DP;
                ++Poi;
                if(Poi->Mode==OCCMARK)
                    return false;
                for(++DP;DP->Mode!=OCCMARK;++DP)
                {
                    if(DP->Mode==OCCPBEGIN)
                    {
                    //Inside=true;
                        Tex=DP->X;
                        Tez=DP->Z;
                    }else if(DP->Mode==OCCPMIDDLE||DP->Mode==OCCPEND)
                    {
                        float Texx=DP->X-Tex;
                        float Tezz=DP->Z-Tez;
                        float Tex2=x-Tex;
                        float Tez2=z-Tez;
                        if(Tezz*Tex2-Texx*Tez2>0)
                        {
                            if(Distance(XYF (Tex2,Tez2),XYF (0.0,0.0),XYF (Texx,Tezz))>=dis)
                            {
                                //er<<"Yes!!!!"<<endl;
                                Inside=false;
                            }
                        }
                        Tex=DP->X;
                        Tez=DP->Z;
                    }else if(DP->Mode==OCCINCLUDE)
                    {
                        return true;
                    }
                    if(!Inside)
                    {
                         return false;
                    }
                }
                return true;
            }
        }
        //er<<"错误"<<endl; 
        return false;
    }
    return false;
    
}
int OccupyControl::CheckBlock(int x,int z,float x1,float z1,float x2,float z2)//1表示在右边，2表示在左边，3表示在方块内 
{
    std::vector<OccupyBlock>::iterator Poi;
    Poi=XZData.begin()+(x-1)*BlockZ+z-1;
    void* Check2=operator new[] (sizeof(int)*4);
    int* Check=static_cast<int*>(Check2);
    float X2=x2-x1;
    float Z2=z2-z1;
    int Tem;
    float X1=Poi->X1-x1;
    float Z1=Poi->Z1-z1;
    if(X1*Z2-Z1*X2<0)
        Tem=1;
    else if(X1*Z2-Z1*X2>0)
        Tem=2;
    else
        Tem=3;
    *Check=Tem;
    
    X1=Poi->X2-x1;
    Z1=Poi->Z1-z1;
    if(X1*Z2-Z1*X2<0)
        Tem=1;
    else if(X1*Z2-Z1*X2>0)
        Tem=2;
    else
        Tem=3;
    *(Check+1)=Tem;
    
    X1=Poi->X1-x1;
    Z1=Poi->Z2-z1;
    if(X1*Z2-Z1*X2<0)
        Tem=1;
    else if(X1*Z2-Z1*X2>0)
        Tem=2;
    else
        Tem=3;
    *(Check+2)=Tem;
    
    X1=Poi->X2-x1;
    Z1=Poi->Z2-z1;
    if(X1*Z2-Z1*X2<0)
        Tem=1;
    else if(X1*Z2-Z1*X2>0)
        Tem=2;
    else
        Tem=3;
    *(Check+3)=Tem;
    
    for(int i=0,Tem=*Check;i<4;++i)
    {
        if(Tem!=*(Check+i)&&Tem!=3)
        {
            operator delete[](Check);
            return 3;
        }else if(Tem==3&&Tem!=*(Check+i))
        {
            Tem=*(Check+i);
        }
        
    }
    operator delete[](Check2);
    if(Tem==1)
        return 1;
    else
        return 2;
}
