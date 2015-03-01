#ifndef DIY_MUSIC_H
#define DIY_MUSIC_H
#include <SDL/SDL_mixer.h>
#include <map>
#include <list>
#include "Information.h"
#include "ControlCenter.h"
#define MUSICPLAY 45789
#define MUSICSTOP 45221
class MusicControl:public Plugin_Base
{
    static int Number;
    std::map<int , Mix_Music*> Music;
    bool Yes;
    public:
        int Load(std::string Name)
        {
            Mix_Music* Mu;
            Mu=Mix_LoadMUS(Name.c_str());
            if(Mu==NULL)
            {
                return -1;
            }else{
                ++Number;
                Music.insert(make_pair(Number,Mu));
                return Number;
            }
        }
        void Delete(int Number)
        {
        }
        void Analyze(void* Data)
        {
            while(!Library.empty())
            {
                Information Tem=GetInformation();
                if(Tem.Target==RegeditID)
                {
                    if(Tem.Category1==MUSICPLAY)
                    {
                        if(Music.count(Tem.Data1.i)!=0)
                        {
                            Mix_PlayMusic(Music[Tem.Data1.i],-1);
                        }
                    }else if(Tem.Category1==MUSICSTOP)
                    {
                        Mix_HaltMusic();
                    }
                }
            }
        }
        MusicControl():Plugin_Base("Music")
        {
            Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,2,512);
        }
        ~MusicControl()
        {
            Mix_CloseAudio();
        }
};
int MusicControl::Number=0;
#endif
