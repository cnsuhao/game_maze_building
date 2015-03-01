class wall
{
    public:
        void* Data;
        XYZF Loc;
        XYZF Front;
        XYZF Up;
        XYZF Wide;
        float wide;
    Picture3D P;
    void Setting(std::string name)
    {
        P.Load(name.c_str());
    }
    void Setting(XYZF Tr,XYZF te,XYZF ui,float wwide)
    {
        Loc=Tr;
        Front=te;
        Up=ui;
        wide=wide;
        Wide=Up&Front;
        Wide.Uint(wwide);
        Data=operator new[] (sizeof(OccData)*(5+2));
        OccData* Poi=static_cast<OccData*>(Data);
        *Poi=OccData(OCCDATABEGIN,0.0,0.0,0.0);
        ++Poi;
        Poi->Get(Loc+Wide,OCCPBEGIN);
        ++Poi;
        Poi->Get(Loc+Wide+Front,OCCPMIDDLE);
        ++Poi;
        Poi->Get(Loc-Wide+Front,OCCPMIDDLE);
        ++Poi;
        Poi->Get(Loc-Wide,OCCPMIDDLE);
        ++Poi;
        Poi->Get(Loc+Wide,OCCPEND);
        ++Poi;
        Poi->Get(XYZF(0.0,0.0,0.0),OCCDATAEND);
    }
    void Show()
    {
        P.Show(Loc+Up+Front+Wide,Up*(-1),Front*(-1));
        P.Show(Loc+Up-Wide,Up*(-1),Front);
        P.Show(Loc+Wide+Up,Up*(-1),Wide*(-2));
        P.Show(Loc-Wide+Up+Front,Up*(-1),Wide*(2));
        P.Show(Loc-Wide+Up,Front,Wide*(2));
    }
};
