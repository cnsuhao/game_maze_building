//还需要增加BLOCK的应用，绘画函数里边对自定函数的支持，还有分析函数的返回值 

#ifndef  DIY_BUTTON_H 
#define  DIY_BUTTON_H 
#include "information.h"
#include "sgprint.h"
#include "ControlCenter.h"
#define BUTABO 1
#define BUTPUC 2
#define BUTNOR 0
#define BUTAFT 3
#define BUTUSE 4
#define BUTUNU 5
#define BUTOFF -1
class ButtonF
{
    public:
        
    std::vector<float> Occupy;//储存按钮所占的位置，这里依据OPENGL默认屏幕的设置，并且按逆时针圈定按钮的位置。既线的“左边”为里边 
    float Heart[2];//按键的中心 
    std::string Description;//储存按钮的命名，默认以此名字输出到屏幕 
    unsigned int TexturePoint;
    int LocalPoint;
    int Aspect;
    int Block;
    int State;
    Print* Tex;
    
    bool (*Use)(ButtonF& now );
    bool UseReady;
    
    bool (*UnUse)(ButtonF& now );
    bool UnUseReady;
    
    bool (*Normal)(ButtonF& now);//画图函数，当按钮处于平常状态下 
    bool NormalReady;

    bool (*Above)(ButtonF& now);//画图函数，鼠标在按钮上边 
    bool AboveReady;
    
    bool (*Puch)(ButtonF& now);//画图函数，按钮被按下 
    bool PuchReady;
    
    bool (*After)(ButtonF& now);//画图函数，按钮被按下后并持续发生作用 
    bool AfterReady;    

    bool (*Move)(ButtonF& now);//画图函数，按钮的动画动作 
    bool MoveReady;
    void ChangeLocation(float x1,float y1)
    {
        Heart[0]=x1;
        Heart[1]=y1;
        Tex->ChangeLocation(LocalPoint,Heart[0]-Description.size()*Tex->Size*0.3,Heart[1]+(Tex->Size)/2);
    }
    
    Information Analyze(Information& Tem);//分析函数，分析鼠标位置，状态，用以决定按键的事件，并且启动链表 
    void Show(void);
    
    ButtonF(std::string name_it, float x=0, float y=0, unsigned int  aspect):
    Description(name_it)
    {
        Heart[0]=x;
        Heart[1]=y;
        Aspect=aspect;
        UnUseReady=false;
        UseReady=false;
        NormalReady=false;
        PuchReady=false;
        AfterReady=false;
        AboveReady=false;
        MoveReady=false;
        State=BUTNOR;
    }
};
class ButtonFControl
{
    public:
        std::vector<ButtonF> Data;
        Print ForButton;
        int Add(std::string name, float x, float y, std::vector< float > Occupy , float Size, unsigned int Aspect=1)
        {
            ButtonF temporary(name,x,y,Aspect);
            std::vector<float>::iterator Point=Occupy.begin();
            for(int i=1;Point!=Occupy.end();++Point,++i)
            {
                (*Point)*=Size;
            }
            temporary.Occupy=Occupy;
            temporary.LocalPoint=ForButton.Add(temporary.Description,x-temporary.Description.size()*ForButton.Size*0.3,y+(ForButton.Size)/2);
            temporary.Tex=&ForButton;
            Data.push_back(temporary);
            return Data.size();
        }
        void Setfunction(int Location,bool (*Function)(ButtonF& now),int size)
        {
            std::vector< ButtonF >::iterator Point = Data.begin()+Location-1;
            if(Point>=Data.begin()&&Point<Data.end())
            {
                switch(size)
                {
                    case BUTNOR:
                        Point->Normal=(Function);
                        Point->NormalReady=true;    
                        break;
                    case BUTABO:
                        Point->Above=Function;
                        Point->AboveReady=true;
                        break;
                    case BUTPUC:
                        Point->Puch=Function;
                        Point->PuchReady=true;
                        break;
                    case BUTAFT:
                        Point->After=Function;
                        Point->AfterReady=true;
                        break;
                    case BUTUSE:
                        Point->Use=Function;
                        Point->UseReady=true;
                        break;
                    case BUTUNU:
                        Point->UnUse=Function;
                        Point->UnUseReady=true;
                        break;               
                }
            }
        }
        void Show()
        {
            std::vector<ButtonF>::iterator Poi;
            if(!Data.empty())
            {
                for(Poi=Data.begin();Poi!=Data.end();++Poi)
                {
                    Poi->Analyze();
                }
            }
        }
        ButtonFControl(std::string file):ForButton(file){}
};
Information ButtonF::Analyze(Information& Tem)//分析函数，分析鼠标位置，状态，用以决定按键的事件，并且启动链表 
{
    if(Aspect==Tem.Aspect)
    {
        if(true)
        {
            if(true)
            {
                if(State!=BUTAFT)
                {
                    std::vector< float >::iterator Point=Occupy.begin();
                    float x1,x2,y1,y2;
                    bool down(true);
                    if(Point!=Occupy.end()&&(Point+1)!=Occupy.end())
                    {
                        for(;(Point+2)!=Occupy.end()&&(Point+3)!=Occupy.end()&&down;Point+=2)
                        {
                            x1=*(Point+2)-*(Point);
                            y1=*(Point+3)-*(Point+1);
                            x2=Tem.Dataf3-*(Point)-Heart[0];
                            y2=Tem.Dataf4-*(Point+1)-Heart[1];
                            if((y2*x1-x2*y1)<=0)
                            {
                                down=false;
                            }
                        }
                    }else
                        down=false;
                    if(State==BUTPUC&&(!down))
                    {
                        State=BUTNOR;
                    }
                    if(down)
                    {
                        State=BUTABO;
                        if(Tem.Category3==MOUSEBUTTONDOWN&&Tem.Category4==LEFT)
                        {
                            State=BUTUSE;
                        }
                    }
                }else if(Tem.Category3==MOUSEBUTTONUP&&Tem.Category4==RIGHT)
                {
                    State=BUTNOR;
                }
            }
        }
        switch(State)
        {
            case BUTNOR:
                if(!NormalReady)
                {
                    glColor3f(0.2,1.0,0.2);
                    Show();
                }
                break;
            case BUTAFT:
                if(!AfterReady)
                {
                    glColor3f(0.2,1.0,0.2);
                    Show();
                }
                break;
            case BUTPUC:
                if(!PuchReady)
                {
                    glColor3f(0.2,1.0,0.2);
                    Show();
                }
                break;
            case BUTABO:
                if(!AboveReady)
                {
                    glColor3f(0.2,1.0,0.2);
                    Show();
                }
                break;
        }
        return EMPTY;
    }
}
void ButtonF::Show(void)
{
    std::vector< float >::iterator Point=Occupy.begin();
    if(Point+1!=Occupy.end())
    {
        (Tex)->Show(LocalPoint);
        glBegin(GL_LINES);
        for(;(Point+2)!=Occupy.end()&&(Point+3)!=Occupy.end();Point+=2)
        {
            glVertex2f(*Point+Heart[0],*(Point+1)+Heart[1]);
            glVertex2f(*(Point+2)+Heart[0],*(Point+3)+Heart[1]);
        }
        glEnd();
    }
}
#endif
