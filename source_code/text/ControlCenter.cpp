#ifndef DIY_CONTROLCENTER_CPP
#define DIY_CONTROLCENTER_CPP
#include "ControlCenter.h"
bool ControlCenter::SetView(int Mode)
{
    switch(Mode)
    {
        case 1:
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluOrtho2D(-1.0,1.0,-1.0,1.0);
            return true;
            break;
        case 2:
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(-1,1,-1,1,1,-1);
            glMatrixMode(GL_MODELVIEW);
            return true;
            break;
        case 3:
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(Angle,static_cast<float>(WindowW)/WindowH,NearSize,FarSize);
            glMatrixMode(GL_MODELVIEW);
            return true;
            break;
    }
    return false;
}
unsigned int ControlCenter::Asp(void)
{
    return Aspect;
}

bool ControlCenter::Init(int Mode=1)
{
    if(RegeditReady)
    {
        SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );//�趨GL�ĳ�ʼ���ԣ���ʹ��GL�Ļ���������������в����Լ��ٶ�
        Screen = SDL_SetVideoMode( WindowW, WindowH, 32, SDL_OPENGL); // ͬ�ϣ��趨���Ե���һ��������Ҫ��������Լ��ٶ�
        if(!FunctionLibrary.empty())
        {
            for(std::vector<Plugin_Base*>::iterator Poi=FunctionLibrary.begin();Poi!=FunctionLibrary.end();++Poi)
            {
                (*Poi)->Init(this);
            }
        }
        Thread1=SDL_CreateThread(Thread_1_Function,(void*) this);
        if(!SetView(Mode))    SetView(1);
    }
}

void ControlCenter::GetReady(void (*Temporary)(ControlCenter& This))
{
    (*Temporary)(*this);
}

int ControlCenter::CheckInf(Information& Temp)
{
    std::vector< Information >::const_iterator Poi;
    if(!FastShoot.empty())
    {
        for(Poi=FastShoot.begin();Poi!=FastShoot.end();++Poi)
        {
            if( Poi->Target==Temp.Target && Call(Temp.Target)!=NULL)
            {
                if( (Poi->Category1==Temp.Category1||Poi->Category1==-999)
                  &&(Poi->Category2==Temp.Category2||Poi->Category2==-999)
                  &&(Poi->Category3==Temp.Category3||Poi->Category3==-999))
                {
                    if(NaTarIP.count(Temp.Target)!=0)
                    {
                        Call(Temp.Target)->Library.push_back(Temp);
                        return 1;
                    }
                }
            }
        }
    }
    DeliverLibrary.push_back(Temp);
    return 2;
}

void ControlCenter::Finish(void)
{
    SDL_Delay( Delay );//��ͣ~~~~
    SDL_GL_SwapBuffers();//ǿ�������ˢ����
    Calculate+=1;
    if(Calculate>=100000)
        Calculate=0;
    glLoadIdentity();
}
        
void ControlCenter::Run(int number=0)
{
    if(Running)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        while(!MainLibrary.empty())
        {
                    //er<<"Win!!!"<<endl;
            Information Tempp=*MainLibrary.begin();
                    //check("sss",Tempp);
            MainLibrary.pop_front();
                if(Tempp.Category1==INFCONZJ)
                {
                    SetView(2);
                }else if(Tempp.Category1==INFCONTS)
                {
                    SetView(3);
                }
                if(Tempp.Category1==INFUNABLEEXITIMI)
                {
                    ExitImi=false;
                }
                    
            if(Tempp.Category2==INFEXIT&&Tempp.Category1==INFEVENT)
            {
                Running=false;
                SDL_KillThread(Thread1);
                //exit(0);
            }
        }
        while( SDL_PollEvent( &Event) ) 
        {
            Information Temporary;
            Temporary.Resource=INFCONID;
            Temporary.Target=INFALL;
            Temporary.Category1=INFEVENT;
            float Temporary2[1];
            switch(Event.type)
            {
                case SDL_QUIT:
                    //Running = false;
                    Temporary.Category2=INFEXIT;
                    break;
                case SDL_KEYDOWN:
                    Temporary.Category2=INFKEY;
                    Temporary.Category3=INFKEYDOWN;
                    Temporary.Data1.ui=Event.key.keysym.sym;
                    //er<<Event.key.keysym.sym<<endl;
                    break;
                case SDL_KEYUP:
                    Temporary.Category2=INFKEY;
                    Temporary.Category3=INFKEYUP;
                    Temporary.Data1.ui=Event.key.keysym.sym;
                    break;
                case SDL_MOUSEMOTION:
                    Temporary.Category2=INFMOUSE;
                    Temporary.Category3=MOUSEMOTION;
                    Temporary.Data1.f=(float)(2*Event.motion.x-(WindowW))/(float)(WindowW);
                    Temporary.Data2.f=-(float)(2*Event.motion.y-(WindowH))/(float)(WindowH);
                    //glReadPixels(Event.motion.x,WindowH-Event.motion.y,1,1,GL_DEPTH_COMPONENT,GL_FLOAT,Temporary2);
                    //Temporary.Data3.f=Temporary2[0];
                    Temporary.Data4.i=Event.motion.x;
                    Temporary.Data5.i=Event.motion.y;
                    Temporary.Data6.i=Event.motion.xrel;
                    Temporary.Data7.i=Event.motion.yrel;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    Temporary.Category2=INFMOUSE;
                    Temporary.Category3=MOUSEBUTTONDOWN;
                    Temporary.Data1.f=(float)(2*Event.button.x-(WindowW))/(float)(WindowW);
                    Temporary.Data2.f=-(float)(2*Event.button.y-(WindowH))/(float)(WindowH);
                    //glReadPixels(Event.button.x,WindowH-Event.button.y,1,1,GL_DEPTH_COMPONENT,GL_FLOAT,Temporary2);
                    //Temporary.Data3.f=Temporary2[0];
                    Temporary.Data4.i=Event.button.x;
                    Temporary.Data5.i=Event.button.y;
                    //kk<<"����"<<Temporary.Data3.f<<endl;
                    //kk<<"���"<<Event.button.x<<" "<<Event.button.y<<endl; 
                    break;
                case SDL_MOUSEBUTTONUP:
                    Temporary.Category2=INFMOUSE;
                    Temporary.Category3=MOUSEBUTTONUP;
                    Temporary.Data1.f=(float)(2*Event.button.x-(WindowW))/(float)(WindowW);
                    Temporary.Data2.f=-(float)(2*Event.button.y-(WindowH))/(float)(WindowH);
                    glReadPixels(Event.button.x,WindowH-Event.button.y,1,1,GL_DEPTH_COMPONENT,GL_FLOAT,Temporary2);
                    Temporary.Data3.f=Temporary2[0];
                    Temporary.Data4.i=Event.button.x;
                    Temporary.Data5.i=Event.button.y;
                    break;
            }
            CheckInf(Temporary);
            //check("  �������¼�",Temporary);
                    
        }
        std::vector<Plugin_Base*>::iterator Poi;
        while(HaveToChange){}
        FunctionInUse=true;
        if(!FunctionLibrary.empty())
        {
            for(Poi=FunctionLibrary.begin();Poi!=FunctionLibrary.end();++Poi)
            {
                if((*Poi)->FunSho)
                {
                    (*Poi)->Show(this);
                }
            }
        }
        FunctionInUse=false;
                //check("  ����������",Tem);
    }
}

void ControlCenter::Regedit(Plugin_Base* Temporary)
{
    if(!RegeditReady)
    {
        if(NaTarSI.count(Temporary->Name)==0)
        {
            RegeditID+=1;
            Temporary->RegeditID=RegeditID;
            NaTarIP.insert(std::make_pair(RegeditID , Temporary));
            NaTarSI.insert(std::make_pair(Temporary->Name , RegeditID));
            NaTarIS.insert(std::make_pair(RegeditID,Temporary->Name  ));
            FunctionLibrary.push_back(Temporary);
            Information Tem;
            Tem.Resource=INFCONID;
            Tem.Target=RegeditID;
            Tem.Category1=INFCONREG;
            DeliverLibrary.push_back(Tem);
            Temporary->Init(this);
        }
    }
}

ControlCenter::ControlCenter():ThreadReady(false),Running(true),RegeditReady(false),ExitImi(true),HaveToChange(false),FunctionInUse(false)
{
    RegeditID=INFCONID;
    Aspect=1;
    Delay=5;
    Calculate=0;
    CalculateBlock=0;
    WindowW=640;
    WindowH=480;
    Angle=40;
    FarSize=20;
    NearSize=0.1;
    if(SDL_Init(SDL_INIT_VIDEO) < 0) //SDL��ʼ��ʧ��
    {
    }
    atexit(SDL_Quit);//ע���˳����� 
}

void ControlCenter::Ready()
{
    RegeditReady=true;
}

void ControlCenter::AimAt(std::string Name , int Category1=-999  , int Category2=-999 , int Category3=-999 )
{
    Information Temp;
    Temp.Resource = INFCONID;
    if( NaTarSI.count(Name) )
    {
        Temp.Target = NaTarSI[Name];
        Temp.Category1=Category1;
        Temp.Category2=Category2;
        Temp.Category3=Category3;
        FastShoot.push_back(Temp);
    }
}

unsigned int ControlCenter::Cal(unsigned int Number)
{
    if((Calculate-Number)<0)
    {
        return 100000+Calculate-Number;
    }else{
        return Calculate-Number;
    }
}
int Thread_1_Function(void* Data) //�����ݵķ��� 
{
    ControlCenter* CC = static_cast< ControlCenter* > (Data);
    std::vector<Plugin_Base*>::iterator FunPoi;
    Information Tem;
    if(CC->RegeditReady)
    {
        while(CC->Running)
        {
            do
            {
                Information Temp;
                //er<<"Library����"<<CC->DeliverLibrary.size()<<endl;
                if(!CC->DeliverLibrary.empty())
                {
                    Tem = *(CC->DeliverLibrary.begin());
                    CC->DeliverLibrary.pop_front();
                }else
                    Tem = NEXT;
                //check("  ����������2",Tem);
                while(Tem.Resource!=INFCONID&&(Tem.Target==INFALL||Tem.Target==INFCONID))
                {
                    //check("  ����������",Tem);
                    if(Tem.Target==INFALL)
                    {
                        
                    }else if(Tem.Target == INFCONID)
                    {
                        switch(Tem.Category1)
                        {
                            case INFEVENT:
                                if(Tem.Category2==INFEXIT)
                                    CC->MainLibrary.push_back(Tem);
                                break;
                            case INFCONTS:
                            case INFCONZJ:
                                CC->MainLibrary.push_back(Tem);
                                break;
                            case INFASPECT:
                                CC->Aspect=Tem.Data1.ui;
                                break;
                            case INFDESTORY:
                                while(CC->FunctionInUse){}
                                CC->HaveToChange=true;
                                Plugin_Base* Point=static_cast<Plugin_Base*>(Tem.Data1.v);
                                for(std::vector<Plugin_Base*>::iterator Poi=CC->FunctionLibrary.begin();Poi<CC->FunctionLibrary.end();++Poi)
                                {
                                    if((*Poi)==Point)
                                    {
                                        (*Poi)->Destory(CC);
                                        *Poi=NULL;
                                        break;
                                    }
                                }
                                for(std::map<std::string , int >::iterator Poi=NaTarSI.begin();Poi!=NaTarSI.end();++Poi)
                                {
                                    if(Poi->first==Point->Name)
                                        NaTarSI.erase(Poi);
                                }
                                for(std::map<int , Plugin_Base* >::iterator Poi=NaTarIP.begin();Poi!=NaTarIP.end();++Poi)
                                {
                                    if(Poi->first==Point->RegeditID)
                                        NaTarIP.erase(Poi);
                                }
                                for(std::map<int , std::string >::iterator Poi=NaTarIS.begin();Poi!=NaTarIS.end();++Poi)
                                {
                                    if(Poi->first==Point->RegeditID)
                                        NaTarIS.erase(Poi);
                                }
                                CC->HaveToChange=false;
                                break;
                            case INFCREATE:
                                while(CC->FunctionInUse){}
                                CC->HaveToChange=true;
                                for(std::vector<Plugin_Base*>::iterator Poi=CC->FunctionLibrary.begin();Poi<CC->FunctionLibrary.end();++Poi)
                                {
                                    if(NaTarSI.count((*Poi)->Name)==0)
                                    {
                                        if((*Poi)==NULL)
                                        {
                                            *Poi=static_cast<Plugin_Base*>(Tem.Data1.v);
                                            break;
                                        }else if(Poi==CC->FunctionLibrary.end()-1&&(!CC->FunctionLibrary.empty()))
                                        {
                                            CC->FunctionLibrary.push_back(static_cast<Plugin_Base*>(Tem.Data1.v));
                                        }
                                        CC->RegeditID+=1;
                                        (*Poi)->RegeditID=CC->RegeditID;
                                        NaTarIP.insert(std::make_pair((*Poi)->RegeditID , *Poi));
                                        NaTarSI.insert(std::make_pair((*Poi)->Name , (*Poi)->RegeditID));
                                        NaTarIS.insert(std::make_pair((*Poi)->RegeditID , (*Poi)->Name));
                                        (*Poi)->Init(CC);
                                    }
                                }
                                CC->HaveToChange=false;
                                break;
                        }
                        if(!CC->DeliverLibrary.empty())
                        {
                            Tem=*(CC->DeliverLibrary.begin());
                            CC->DeliverLibrary.pop_front();
                        }else{
                            Tem=EMPTY;
                            break;
                        }
                    }
                }
                if(!CC->FunctionLibrary.empty())
                {
                    //er<<"OK"<<endl;
                    for(FunPoi=CC->FunctionLibrary.begin();FunPoi!=CC->FunctionLibrary.end();++FunPoi)
                    {
                        
                        if((*FunPoi)->FunDel)
                        {
                            do
                            {
                                //er<<"too"<<endl;
                                Temp=(*FunPoi)->Deliver(Tem);
                                if(Temp.Target!=INFRETURN)
                                {
                                    //er<<"OK~"<<endl;
                                    CC->DeliverLibrary.push_back(Temp);
                                }
                            }while(Temp.Target!=INFRETURN);
                            if(Temp.Target==INFRETURN&&Temp.Category1==INFDELETE)
                            {
                                break;
                            }
                        }
                    }
                    if(CC->ExitImi)
                    {
                        if(Tem.Resource==INFCONID&&Tem.Target==INFALL&&Tem.Category1==INFEVENT&&Tem.Category2==INFEXIT)
                        {
                            CC->MainLibrary.push_back(Tem);
                        }
                    }
                }else if(Tem.Resource==INFCONID&&Tem.Target==INFALL&&Tem.Category1==INFEVENT&&Tem.Category2==INFEXIT)
                {
                    CC->MainLibrary.push_back(Tem);
                }
                /*if(Temp.Target==INFRETURN&&Temp.Category1==INFNEXT&&(!CC->DeliverLibrary.empty())&&Tem.Target!=INFNOTAR&&Tem.Category1!=INFNULL)
                {
                    er<<"cao!"<<endl;
                    CC->DeliverLibrary.pop_front();
                }*/
                //er<<"finish!!!"<<endl;
            }while(!CC->DeliverLibrary.empty());
            //er<<"gogo"<<endl;
            if(!CC->FunctionLibrary.empty())
            {
                FunPoi=CC->FunctionLibrary.begin();
                for(;FunPoi!=CC->FunctionLibrary.end();++FunPoi)
                {
                    if((*FunPoi)->FunAna)
                    {
                        (*FunPoi)->Analyze(CC);
                    }
                }
            }
            SDL_Delay( CC->Delay );
            //er<<"������MainLibrary:"<<CC->MainLibrary.size();
            //er<<"������DeliverLibrary:"<<CC->DeliverLibrary.size(); 
        }
        
    }
}
#endif
