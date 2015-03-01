#ifndef DIY_ERROR_CPP
#define DIY_ERROR_CPP
#include "Error.h"

Error::Error(bool use=true):Plugin_Base("ERROR")
{
    Use=use;
    Adress="Error.txt";
    if(Use)
    {
        File.open("Error.txt",std::fstream::out);
        er<<"Yes"<<endl;
        File<<"**********You have run the error check!!**********"<<std::endl;
        //File.close();
        //File.clear();
    }
}
Error::Error(char* file):Plugin_Base("ERROR")
{
    Use=true;
    Adress=file;
    if(Use)
    {
        File.open(Adress.c_str(),std::fstream::out);
        if(!File)
        {
            File.close();
            //File.clear();
            File.open("Error.txt",std::fstream::out);
            File<<"!!Can not find the adress!!"<<std::endl;
            Adress="Error.txt";
        }
        File<<"**********You have run the error check!!**********"<<std::endl;
        File<<"***Your file adress is:"<<Adress<<"***"<<std::endl;
        //File.close();
        //File.clear();
    }
}
void Error::Analyze(void* CC)
{
    Information Tem;
    while(!Library.empty())
    {
        Tem=GetInformation();
    }
}
void Error::Check(Information Tem)
{
    File<<"Resource:"<<Tem.Resource<<std::endl;
    File<<"Target:"<<Tem.Target<<std::endl;
    File<<"  Category1:"<<Tem.Category1<<"  Category2:"<<Tem.Category2<<"  Category3:"<<Tem.Category3<<"  Category4:"<<Tem.Category4<<std::endl;
}
#endif


