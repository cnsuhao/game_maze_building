#ifndef DIY_OCCUPY_H
#include "baseclass.h"
#include <vector>
#include <list>
//#include "Plugin_Base.h"
#define DIY_OCCUPY_H
#define LINE 1
#define OCCINCLUDE 80 //表示地图上这个“块”被包括，虽然没有任何数据 
#define OCCADDDEAD 89 //INFORMATION命令，表示加入DEAD数据 
#define OCCADDLIMITE 46 //同上，加入LIMITE数据 
#define OCCDATABEGIN 9  
#define OCCDATAEND 56
#define OCCMAPBEGIN 3
#define OCCMAPEND 4
#define OCCMARK 98  //DATA LIST容器里边分段用 
#define OCCDATANULL 0

#define OCCPBEGIN 45 //在OCCUPYDATA中表示点的开始 
#define OCCPMIDDLE 78//同上，表示中间点 
#define OCCPEND 1244 //同上，表示结尾点 
#define OCCNOUSE 0 //表示没用，不代表任何意义 



class OccupyData
{
    public:
        int Mode;
        int ModeE;
        float D1;
        float D2;
        std::list <OccupyData>::iterator Point;
        std::list <OccupyData>::iterator PointYZ;
        std::list <OccupyData>::iterator PointXY;
        OccupyData(int M=OCCNOUSE,int M2=OCCNOUSE,float d1=0,float d2=0,std::list<OccupyData>::iterator P=NULL):D1(d1),D2(d2),Mode(M),ModeE(M2),Point(P){}
        OccupyData(){}
        bool operator== (const OccupyData& Te)
        {
            if(Mode==Te.Mode && ModeE==Te.ModeE && D1==Te.D1 && D2==Te.D2 && Point==Te.Point && PointYZ==Te.PointYZ && PointXY==Te.PointXY)
                return true;
            else
                return false;
        }
};
class OccupyBlock
{
    public:
        float X1;
        float X2;
        float Z1;
        float Z2;
        OccupyBlock(float x1,float x2,float z1,float z2):X1(x1),X2(x2),Z1(z1),Z2(z2){}
};
class OccupyPoint
{
    public:
        std::list<OccupyData>::iterator PL;
        std::list<OccupyData>::iterator PD;
        std::list<OccupyData>::iterator NOW;
        void Set(int Mode)
        {
            if(Mode==1)
                NOW=PL;
            else if(Mode==2)
                NOW=PD;
        }
        OccupyPoint(std::list<OccupyData>::iterator p1,std::list<OccupyData>::iterator p2):PL(p1),PD(p2){}
};
class OccupyDead
{
    friend class OccupyControl;
    public:
        std::list<OccupyData>::iterator Poi;
        std::list<OccupyData> ListXZ;
        std::list<OccupyData> ListXY;
        std::list<OccupyData> ListZY;
        std::list<OccupyData> ListXZE;
        std::list<OccupyData> ListXYE;
        std::list<OccupyData> ListZYE;
        void Add(float* Te,int number)
        {
            AddToList(Te,number,ListXZ,ListXZE);
        }
        void Print(void)
        {
            Print(ListXZ,ListXZE);
        }
        void Print(std::list<OccupyData>& List,std::list<OccupyData>& ListE);//测试用 
        void AddToList(float* XZ,int numxz,std::list<OccupyData> &ListXZ,std::list<OccupyData> & ListXZE);//将数据装入LIST中，已经过优化。 
};
class OccupyLimited:public OccupyDead
{
    int tt;
    public:
};
class OccupyMap:public OccupyDead
{
    friend class OccupyControl;
    int X;
    int Z;
    float MaxX;
    float MinX;
    float MaxZ;
    float MinZ;
    public:
        void SetMapSize(int x,int z)
        {
            if(x>0&&z>0)
            {
                X=x;
                Z=z;
            }
        }
        void SetMapSize(float x1,float x2,float y1,float y2)
        {
            MaxX=x1;
            MinX=x2;
            MaxZ=y1;
            MinZ=y2;
        }
        OccupyMap():X(1),Z(1){}
};
class OccupyControl
{
    bool Check(float x,float y,float x2,float x3,int x,int z);
    void Clean(void);//清理所有数据用。 
    int CheckBlock(int x,int z,float x1,float z1,float x2,float z2);
    bool AddToBlock(int z1,int x1,OccupyData* Te,int z2,int x2,OccupyData* Te2,int Mode,std::vector<bool>& Tank);
    int BlockX;//X方向上的分块数 
    int BlockZ;//Y方向上的分块数 
    std::vector< OccupyBlock > XZData;//分快时块的四点坐标 
    
    std::vector< float > X;//记录下边界数据，用于判定 
    std::vector< float > Z;//同上 
    std::vector< OccupyPoint > XZEnsample;//记下指针 
    
    std::list< OccupyData > XZLive; 
    std::list< OccupyData > XZLimited;
    std::list< OccupyData > XZDead;
    
    public:
    
    bool CheckList(OccupyData& Message, std::list< OccupyData >& Tank);
    bool CheckXZList(OccupyData& Message, std::list< OccupyData >& Tank);

    void ChangeMap(OccupyMap* Data);
    void Check();
    bool Check(float x,float y,float z,float dis);
    bool Check(std::list< OccupyData >& XZ,float);
    bool DeadCheck(float x,float y,float z,float dis);
    bool LimitedCheck(float x,float y,float z,float dis);
    void LimitedAdd(OccupyDead* Data);
    void DeadAdd(OccupyDead* Data);
    OccupyControl(){}
};
#include "Occupy.cpp"
#endif
