#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>
#include <string>
#include <fstream>
class character_f
{
    unsigned long size;
    std::vector< std::vector<float> > data;//储存人物数据的二维容器，第一维是该任务的状态，如站立，行动等，第二维为具体数据，画图函数调用此数据 
    std::string name;//为该人物命名，以后用到 
    float* face[3];//人物的朝向 
    std::vector< float > occupy;//人物的占地，用以判断接触等事件 
    bool through;//用以表示人物是否可被穿过 
    int state_of_character;//用以表示人物现在的状态 
    bool data_ready;//用以表示数据是否录入完成 
    bool draw_function_ready;//用以表示函数设定是否完毕 
    bool draw_function_from_data_ready;
    bool move_function_ready;
    bool move_function_from_data_ready;
    bool (* draw_function)(const character_f& now_drawing);//画画函数指针，指向所用函数 
    bool (* move_function)(const character_f& now_drawing);//运动函数指针，指向设定的运动 
    bool (* happening )(const character_f& now_facing);
    bool happen_ready;
    
    public:
    
    void change_size(float size)//改变人物的大小，以（0，0，0）为中心等距放大缩小 
    {
        std::vector< std::vector<float> > :: iterator points_vf=data.begin();
        std::vector< float > :: iterator points_f=points_vf->begin();
        for(;points_vf != data.end();++points_vf)
        {
            for(points_f=points_vf->begin();points_f != points_vf->end(); ++points_f)
            {
                *points_f *= size;
            }
        }
    }
    void set_move_function(bool (* setting_move_function)(const character_f& now_drawing))//设定函数 
    {
        move_function=setting_move_function;
        move_function_ready=true;
    }
    void set_draw_function(bool (* setting_draw_function)(const character_f& now_drawing))//设定函数 
    {
        draw_function=setting_draw_function;
        draw_function_ready=true;
    }
    bool draw(void)//调用画画函数 
    {
        if(data_ready&&(draw_function_ready||draw_function_from_data_ready)&&(move_function_ready||move_function_from_data_ready))
        {
            if(draw_function_from_data_ready)
            {
            }else{
                (*draw_function)(*this);
            }
        }
    }
    bool read_data_of_character(std::string file)//录入数据 
    {
    }
    bool change_name(const std::string& name_now)//改变名字 
    {
        name=name_now;
    }
    
    
    character_f::character_f(std::string name_of_this)//构造函数    
         {
             through=true;
             int state_of_character=1;
             data_ready=false;
             draw_function_ready=false;
             draw_function_from_data_ready=false;
             move_function_ready=false;
             move_function_from_data_ready=false;
             draw_function=NULL;
             move_function=NULL;
        }
};
#endif
