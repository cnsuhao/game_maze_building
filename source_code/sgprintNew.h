#ifndef  DIY_SGPRINT_H 
#define  DIY_SGPRINT_H 
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include "language.h"
#include "baseclass.h"
#include "information.h"
#include "SDL/SDL_ttf.h"
//#include "SDL/SDL_image.h"
//#include "picture.h"
#define PRINTFFRAME 1
bool PReadyToUse=false;
void SGTTF_Init ( )
{
    TTF_Init() ;
    atexit( TTF_Quit );
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    PReadyToUse=true;
}
class A
{
    unsigned int Point;
    std::string Data;
    static TTF_Font *font;
    float W;
    float H;
    public:
        void Add(std::string data , TTF_Font* Font=font )
        {
            Data=data;
            if(Point!=0)
            {
                Delete();
            }
            if(PReadyToUse)
            {
                SDL_Surface *Texture;
                SDL_Surface *Back;
                int w;
                int h;
                Texture = TTF_RenderUTF8_Blended( Font , GbToUTF(Data).c_str() , (SDL_Color){255,255,255} );
                w = static_cast<int>(pow(2,ceil(log(Texture->w)/log(2)))+0.5 );
                h = static_cast<int>(pow(2,ceil(log(Texture->h)/log(2)))+0.5 );
                W=static_cast<float>(Texture->w)/w;
                H=static_cast<float>(Texture->h)/h;
                Back=SDL_CreateRGBSurface(0,w,h,32,0x00ff0000,0x0000ff00,0x000000ff,0xff000000);
                SDL_BlitSurface(Texture,0,Back,0);
                void* PointForTexture= operator new[](sizeof(unsigned long*) * w*h*4);
                unsigned char* Poi= static_cast<unsigned char*> (PointForTexture);
                unsigned char* Poi2=static_cast<unsigned char*> (Back->pixels);
                for(int hh=0;hh< static_cast<int>(H*h*4);++hh)
                {
                    for(int ww=0;ww< static_cast<int>(W*w);++ww)
                    {
                        Poi[hh*w+ww*4]=Poi2[hh*w+ww*4];
                        Poi[hh*w+ww*4+1]=Poi2[hh*w+ww*4+1];
                        Poi[hh*w+ww*4+2]=Poi2[hh*w+ww*4+2];
                            float Tem=(Poi[hh*w+ww*4]+Poi[hh*w+ww*4+1]+Poi[hh*w+ww*4+2])/3.0;
                            Poi[hh*w+ww*4+3]=static_cast<unsigned int>(sqrt(Tem)*255);
                    }
                } 
                glGenTextures(1,&Point);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D,Point);
                glTexImage2D(GL_TEXTURE_2D,0,4,w,h,0,GL_BGRA,GL_UNSIGNED_BYTE,PointForTexture);
                glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
                SDL_FreeSurface(Texture);
                SDL_FreeSurface(Back);
                operator delete[] (PointForTexture);
            }
        }
        void Show( float X ,float Y , float R,float G,float B,float Size=0.2,TTF_Font* Font=font)
        {
            if(PReadyToUse)
            {
                //er<<"是的！"<<endl;
                bool Shendu=glIsEnabled(GL_ALPHA_TEST);
                glEnable(GL_ALPHA_TEST);  
                glAlphaFunc(GL_GEQUAL, 0.2f); 
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D,Point);
                glColor4f(R,G,B,1.0);
                glBegin(GL_QUADS);
                    glTexCoord2f(W,H);        glVertex2f(X+Data.size()*Size*0.4,Y-Size);  
                    glTexCoord2f(W,0.0);      glVertex2f(X+Data.size()*Size*0.4,Y);                  
                    glTexCoord2f(0.0,0.0);     glVertex2f(X,Y);
                    glTexCoord2f(0.0,H);       glVertex2f(X,Y-Size);
                glEnd();
                glDisable(GL_TEXTURE_2D);
                if(!Shendu)glDisable(GL_ALPHA_TEST);
            }
        }
        void Show( XYF Tem,float R,float G,float B,float Size=0.2,TTF_Font* Font=font)
        {
            Show(Tem.X,Tem.Y,R,G,B,Size,Font);
        }
        void Delete()
        {
            if(Point!=0)
            {
                glDeleteTextures(1,&Point);
                Point=0;
            }
        }
        A():Point(0)
        {
            if(!PReadyToUse)
            {
                SGTTF_Init();
                font=TTF_OpenFont("simhei.ttf",35);
                if(!font)
                {
                    font=TTF_OpenFont("c:\\WINDOWS\\Fonts\\SIMKAI.TTF",35);
                    if(!font)
                    {
                        font=TTF_OpenFont("d:\\WINDOWS\\Fonts\\SIMKAI.TTF",35);
                    }
                }
            }
        }
        ~A()
        {
            if(Point!=0)
            {
                glDeleteTextures(1,&Point);
            }
        }
};
class A3D
{
        unsigned int Point;
        std::string Data;
        static TTF_Font *font;
        float W;
        float H;
    public:
        void Add(std::string data , TTF_Font* Font=font )
        {
                Data=data;
                if(Point!=0)
                {
                    Delete();
                }
                if(PReadyToUse)
                {
                    SDL_Surface *Texture;
                    SDL_Surface *Back;
                    int w;
                    int h;
                    Texture = TTF_RenderUTF8_Blended( Font , GbToUTF(Data).c_str() , (SDL_Color){255,255,255} );
                    w = static_cast<int>(pow(2,ceil(log(Texture->w)/log(2)))+0.5 );
                    h = static_cast<int>(pow(2,ceil(log(Texture->h)/log(2)))+0.5 );
                    W=static_cast<float>(Texture->w)/w;
                    H=static_cast<float>(Texture->h)/h;
                    Back=SDL_CreateRGBSurface(0,w,h,32,0x00ff0000,0x0000ff00,0x000000ff,0xff000000);
                    SDL_BlitSurface(Texture,0,Back,0);
                    void* PointForTexture= operator new[](sizeof(unsigned long*) * w*h*4);
                    unsigned char* Poi= static_cast<unsigned char*> (PointForTexture);
                    unsigned char* Poi2=static_cast<unsigned char*> (Back->pixels);
                    for(int hh=0;hh< static_cast<int>(H*h*4);++hh)
                    {
                        for(int ww=0;ww< static_cast<int>(W*w);++ww)
                        {
                            Poi[hh*w+ww*4]=Poi2[hh*w+ww*4];
                            Poi[hh*w+ww*4+1]=Poi2[hh*w+ww*4+1];
                            Poi[hh*w+ww*4+2]=Poi2[hh*w+ww*4+2];
                            float Tem=(Poi[hh*w+ww*4]+Poi[hh*w+ww*4+1]+Poi[hh*w+ww*4+2])/3.0;
                            Poi[hh*w+ww*4+3]=static_cast<unsigned int>(sqrt(Tem)*255);
                        }
                    } 
                    glGenTextures(1,&Point);
                    glEnable(GL_TEXTURE_2D);
                    glBindTexture(GL_TEXTURE_2D,Point);
                    glTexImage2D(GL_TEXTURE_2D,0,4,w,h,0,GL_BGRA,GL_UNSIGNED_BYTE,PointForTexture);
                    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
                    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
                    SDL_FreeSurface(Texture);
                    SDL_FreeSurface(Back);
                    operator delete[] (PointForTexture);
                }
        }
        void Show( XYZF Local , XYZF Target , XYZF Face , int Mode=0,float R=1.0,float G=1.0,float B=1.0,float Size=0.02 ,TTF_Font* Font=font)//Target是指向下 
        {
            if(PReadyToUse)//&&Point!=0)
            {
                bool Shendu=glIsEnabled(GL_ALPHA_TEST);
                XYZF Crosswise=Face&Target;
                Crosswise.Uint(Size*0.4);
                Target.Uint(Size);
                glEnable(GL_ALPHA_TEST);  
                glAlphaFunc(GL_GEQUAL, 0.9f); 
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D,Point);
                glColor4f(R,G,B,1.0);
                glBegin(GL_QUADS);
                    glNormal(Face);
                    glTexCoord2f(W,H);        glVertex(Local+Crosswise*Data.size()+Target);  
                    glTexCoord2f(W,0.0);      glVertex(Local+Crosswise*Data.size());                   
                    glTexCoord2f(0.0,0.0);    glVertex(Local);
                    glTexCoord2f(0.0,H);      glVertex(Local+Target);

                glEnd();
                glDisable(GL_TEXTURE_2D);
                if(!Shendu) glDisable(GL_ALPHA_TEST);
            }
        }
        void Delete()
        {
            if(Point!=0)
            {
                glDeleteTextures(1,&Point);
                Point=0;
            }
        }
        A3D():Point(0)
        {
            if(!PReadyToUse)
            {
                SGTTF_Init();
                font=TTF_OpenFont("simkai.ttf",35);
                if(!font)
                {
                    font=TTF_OpenFont("c:\\WINDOWS\\Fonts\\SIMKAI.TTF",35);
                    if(!font)
                    {
                        font=TTF_OpenFont("d:\\WINDOWS\\Fonts\\SIMKAI.TTF",35);
                    }
                }
            }
        }
        ~A3D()
        {
            if(Point!=0)
            {
                glDeleteTextures(1,&Point);
            }
        }
};
TTF_Font* A::font=NULL;
TTF_Font* A3D::font=NULL;

class PrintFrame
{
    
};
#endif
