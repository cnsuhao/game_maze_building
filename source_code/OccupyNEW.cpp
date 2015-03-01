bool OccupyControl::DeadCheck(float x,float y,float z,float dis)
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
            std::list<OccData>::iterator DP= * (XZEnsample.begin()+(xl-1)*BlockZ+(zl-1)) ;
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
                    }
                    if(!Inside)
                    {
                         return false;
                    }
                }
                return true;
            }
        }
        er<<"错误"<<endl; 
        return false;
    }
    return false;
    
}
bool OccupyControl::LimitedCheck(float x,float y,float z,float dis)
{
    std::list< OccData >::iterator DP;
    bool Inside=true;
    float Tex,Tez;
    if(!XZLimited.empty())
    {
        DP=XZLimited.begin();
        for(;DP!=XZLimited.end();++DP)
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
                if(Tezz*Tex2-Texx*Tez2<0)
                {
                    er<<"我日啊"<<endl;
                    return false;
                }else{ er<<Distance(XYF (x,z),XYF (Tex,Tez),XYF (DP->X,DP->Z))<<endl;
                       er<<Texx<<" "<<Tezz<<" "<<Tex2<<" "<<Tez2<<endl; 
                if(Distance(XYF (Tex2,Tez2),XYF (0.0,0.0),XYF (Texx,Tezz))<dis)
                {
                    er<<"NOYes!!!!"<<endl;
                    return false;
                }}
                Tex=DP->X;
                Tez=DP->Z;
                er<<"艹！"<<endl; 
            }
            if(!Inside)
            {
                return false;
            }
        }
        return true;
    }
    return  true; 
}
void OccupyControl::ChangeMap(void* Data)
{
    OccData* Tem=static_cast<OccData*>(Data);
    OccData* Temp=Tem;
    if(Temp->Mode==OCCMAPBEGIN)
    {
        float XMin=0.0;
        float XMax=0.0;
        float ZMin=0.0;
        float ZMax=0.0;
        XZDead.clear();
        XZLimited.clear();
        X.clear();
        Z.clear();
        BlockX=(int)(Tem->X);
        BlockZ=(int)(Tem->Y);
        Aspect=(int)(Tem->Z);
        ++Temp;
        XMax=Temp->X;
        XMin=Temp->X;
        ZMax=Temp->Z;
        ZMin=Temp->Z;
        for(;Temp->Mode!=OCCMAPEND;++Temp)
        {
            if(XMin>Temp->X)
                XMin=Temp->X;
            if(XMax<Temp->X)
                XMax=Temp->X;
            if(ZMin>Temp->Z)
                ZMin=Temp->Z;
            if(ZMax<Temp->Z)
                ZMax=Temp->Z;
        }
        if(BlockX>=1&&BlockZ>=1)
        {
            XZEnsample.resize(1+BlockX*BlockZ);
            X.resize(BlockX+1,0.0);
            std::vector< float >::iterator PoiX=X.begin();
            Z.resize(BlockZ+1,0.0);
            std::vector< float >::iterator PoiZ=Z.begin();
            XMax+=1.0;
            XMin-=1.0;
            float Each=(XMax-XMin)/BlockX;
            for(int Number=0;Number<=BlockX;++Number,++PoiX)
            {
                if(Number==BlockX)
                {
                    *(PoiX) = XMax;
                }else{
                    *(PoiX) = XMin+Each*(Number);
                }
            }
            ZMax+=1.0;
            ZMin-=1.0;
            Each=(ZMax-ZMin)/BlockZ;
            for(int Number=0;Number<=BlockZ;++Number,++PoiZ)
            {
                if(Number==BlockZ)
                {
                    *(PoiZ) = ZMax;
                }else{
                    *(PoiZ) = ZMin+Each*(Number);
                }
            }
            XZDead.resize(1+BlockX*BlockZ,OccData(OCCMARK,0.0,0.0,0.0));
            std::list<OccData>::iterator Poi=XZDead.begin();
            for(int i=0;Poi!=XZDead.end()&&i<XZEnsample.size();++Poi,++i)
            {
                *(XZEnsample.begin()+i)=Poi;
            }
            LimitedAdd(Data);
        }
    }
}
/*void OccupyControl::AddData(OccData* Data)
{
    if(!XYEnsample.empty())
    ;
}*/
void OccupyControl::DeadAdd(void* Data)
{
    OccData* Tem=static_cast<OccData*>(Data);
    OccData* Te=Tem;
    bool Finish(false);
    int x=0;
    int z=0;
    do
    {
        if(Te->Mode!=OCCMAPBEGIN&&Te->Mode!=OCCMAPEND)
        {
            float XD=Te->X;
            float YD=Te->Y;
            float ZD=Te->Z;
            er<<"X: "<<XD<<" Z: "<<ZD<<endl;
            if(Te->Mode==OCCPBEGIN)
            {
                for(std::vector<float>::iterator Poi=X.begin();(Poi+1)!=X.end();++Poi)
                {
                    if(XD>*Poi&&XD<=*(Poi+1))
                    {
                        x=Poi-X.begin()+1;
                    }
                }
                for(std::vector<float>::iterator Poi=Z.begin();(Poi+1)!=Z.end();++Poi)
                {
                    if(ZD>*Poi&&ZD<=*(Poi+1))
                    {
                        z=Poi-Z.begin()+1;
                    }
                }
                if(x>=1&&z>=1)
                {
                    XZDead.insert(*(XZEnsample.begin()+(x-1)*BlockZ+z),*Te);
                }
               // er<<x<<" "<<z<<endl;
            }else if(Te->Mode==OCCPMIDDLE||Te->Mode==OCCPEND)
            {
                int xn=0;
                int zn=0;
                for(std::vector<float>::iterator Poi=X.begin();Poi!=X.end();++Poi)
                {
                    if(XD>*Poi&&XD<=*(Poi+1))
                    {
                        xn=Poi-X.begin()+1;
                    }
                }
                for(std::vector<float>::iterator Poi=Z.begin();Poi!=Z.end();++Poi)
                {
                    if(ZD>*Poi&&ZD<=*(Poi+1))
                    {
                        zn=Poi-Z.begin()+1;
                    }
                }
                er<<xn<<" "<<zn<<" "<<x<<" "<<z<<endl;
                if(zn==z&&xn==x)
                {
                    XZDead.insert(*(XZEnsample.begin()+(x-1)*BlockZ+z),*Te);
                }else if(zn>=1&&xn>=1)
                {
                    //这里加东西 
                    OccData Tr=*Te;
                    --Te;
                    OccData Ty=*Te;
                    ++Te;
                    int X1=xn-x;
                    int Z1=zn-z;
                    int XS=x;
                    int ZS=z;
                    int E;
                    int T;
                    if(X1<0)
                    {
                        E=-1;
                    }else{
                        E=1;
                    }
                    if(Z1<0)
                    {
                        T=-1;
                    }else{
                        T=1;
                    }
                    for(int Q=x;;Q+=E)
                    {
                        for(int R=z;;R+=T)
                        {
                            if(Check(Tr.X,Tr.Z,Ty.X,Ty.Z,Q,R))
                            {
                                if(Q==x&&R==z)
                                {
                                        Tr.Mode=OCCPEND;
                                        XZDead.insert(*(XZEnsample.begin()+(x-1)*BlockZ+z),Tr);
                                }else if(Q==xn&&R==zn)
                                {
                                    Ty.Mode=OCCPBEGIN;
                                    XZDead.insert(*(XZEnsample.begin()+(xn-1)*BlockZ+zn),Ty);
                                    XZDead.insert(*(XZEnsample.begin()+(xn-1)*BlockZ+zn),*Te);
                                    z=zn;
                                    x=xn;
                                }else{
                                    Ty.Mode=OCCPBEGIN;
                                    Tr.Mode=OCCPEND;
                                    XZDead.insert(*(XZEnsample.begin()+(Q-1)*BlockZ+R),Ty);
                                    XZDead.insert(*(XZEnsample.begin()+(Q-1)*BlockZ+R),Tr);
                                }
                                
                            }
                            if(R==zn)
                                break;
                        }
                        if(Q==xn)
                            break;
                    }
                }
            }
                
            
        }
        if(Te->Mode==OCCDATAEND)
        {
           // er<<"结束"<<Te->Mode<<endl;
            Finish=true;
        }
        ++Te;
    }while(!Finish);
}
void OccupyControl::LimitedAdd(void* Data)
{
    OccData* Poi=static_cast<OccData*>(Data);
    if(Poi->Mode==OCCMAPBEGIN||Poi->Mode==OCCDATABEGIN)
    {
        for(++Poi;Poi->Mode!=OCCMAPEND&&Poi->Mode!=OCCDATAEND;++Poi)
        {
            //er<<"something wrong!"<<endl;
            XZLimited.push_back(*Poi);
        }
    }
}
void OccupyControl::Check()
{
    for(std::list<OccData>::iterator Te=XZDead.begin();Te!=XZDead.end();++Te)
    {
        switch(Te->Mode)
        {
            case OCCPBEGIN:
                er<<"开始"<<endl;
                break;
            case OCCPMIDDLE:
                er<<"中间"<<endl;
                break;
            case OCCPEND:
                er<<"结尾"<<endl;
                break;
            case OCCMARK :
                er<<"****标记****"<<endl; 
                break;
        }
        er<<"X :"<<Te->X<<"  Z ： "<<Te->Z<<endl; 
    }
    er<<"分类"<<endl;
    for(std::vector<float>::iterator Poi=X.begin();Poi!=X.end();++Poi)
    {
        er<<*Poi<<endl;
    }
    for(std::vector<float>::iterator Poi=Z.begin();Poi!=Z.end();++Poi)
    {
        er<<*Poi<<endl;
    }
}

inline bool OccupyControl::Check(float x,float y,float z,float dis)
{
    if(LimitedCheck(x,y,z,dis))
    {
        if(!DeadCheck(x,y,z,dis))
        {
            return false;
        }else{
            return true;
        }
    }else{
       return true;
    }
}
inline bool OccupyControl::Check(float x,float z,float x2,float z2,int t,int s)
{
    float X1=*(X.begin()+t);
    float X2=*(X.begin()+t-1);
    float Z1=*(Z.begin()+s);
    float Z2=*(Z.begin()+s-1);
    float T1X=x2-x;
    float T1Z=z2-z;
    float T2X;
    float T2Z;
    bool Tem;
    bool Ter;
    T2X=X1-x;
    T2Z=Z1-z;
    if(T2X*T1Z-T2Z*T1X<0)
    {
        Tem=true;
    }else{
        Tem=false;
    }
    T2X=X1-x;
    T2Z=Z2-z;
    if(T2X*T1Z-T2Z*T1X<0)
    {
        Ter=true;
    }else{
        Ter=false;
    }
    if(!((Ter&&Tem)||(!Ter&&!Tem)))
    {
        return true;
    }
    T2X=X2-x;
    T2Z=Z1-z;
    if(T2X*T1Z-T2Z*T1X<0)
    {
        Ter=true;
    }else{
    }
        Ter=false;
    if(!((Ter&&Tem)||(!Ter&&!Tem)))
    {
        return true;
    }
    T2X=X2-x;
    T2Z=Z2-z;
    if(T2X*T1Z-T2Z*T1X<0)
    {
        Ter=true;
    }else{
        Ter=false;
    }
    if(!((Ter&&Tem)||(!Ter&&!Tem)))
    {
        return true;
    }else{
        return false;
    }
}
