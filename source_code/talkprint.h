#ifndef DIY_TALKPRINT_H
#define DIY_TALKPRINT_H
#include "sgprint.h"
#include "picture.h"
namespace TP
{
    class TalkPrintEnd
    {
        int t;
    }
    class TalkPrintClear
    {
        int t;
    }
}
class TalkPrint
{
        std::vector<std::string> Detail;
        std::vector< A > Data;
        float R;
        float G;
        float B;
        float XS;
        float XE;
        float YS;
        float YE;
        float TXS;
        float TYS;
        float TXE;
        float TYE;
        float Size;
        TTF_Font *font;
        int Order;
        
    public:
        bool HaveBack;
        Picture Background;
        void SetOrder(int OrderT)
        {
            if(OrderT>=1)
            {
                Order=OrderT;
            }
        }
        void Add(std::string Tem)
        {
            std::string::iterator Poi;
            std::string::iterator Poi2;
            for(Poi=Tem.begin(),Poi2=Poi;Poi2!=Tem.end();++Poi2)
            {
                if(*Poi=='\n')
                {
                    std::string Name(Poi,Poi2);
                    Detail.push_back(Name);
                    Poi=Poi2;
                }else if(Poi==Tem.end()-1)
                {
                    std::string Nam(Poi,Poi2);
                    Detail.push_back(Name);
                }
            }
        }
        void SetColor ( int r, int g, int b)
        {
            R=r;
            G=g;
            B=b;
        }
        void SetSize (float size)
        {
            Size = size;
        }
        TalkPrint(std::string Name):HaveBack(false)
        {
            if(!PReadyToUse)
            {
                SGTTF_Init();
            }
            R=1.0;
            G=1.0;
            B=1.0;
            Size = 0.1f;
            font=TTF_OpenFont(Name.c_str(),60);
            if(!font)
            {
                font=TTF_OpenFont("c:\\WINDOWS\\Fonts\\SIMKAI.TTF",60);
                if(!font)
                {
                    font=TTF_OpenFont("d:\\WINDOWS\\Fonts\\SIMKAI.TTF",60);
                }
            }
        }
};
#endif
