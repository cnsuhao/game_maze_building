#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>
#include <string>
#include <fstream>
class character_f
{
    unsigned long size;
    std::vector< std::vector<float> > data;//�����������ݵĶ�ά��������һά�Ǹ������״̬����վ�����ж��ȣ��ڶ�άΪ�������ݣ���ͼ�������ô����� 
    std::string name;//Ϊ�������������Ժ��õ� 
    float* face[3];//����ĳ��� 
    std::vector< float > occupy;//�����ռ�أ������жϽӴ����¼� 
    bool through;//���Ա�ʾ�����Ƿ�ɱ����� 
    int state_of_character;//���Ա�ʾ�������ڵ�״̬ 
    bool data_ready;//���Ա�ʾ�����Ƿ�¼����� 
    bool draw_function_ready;//���Ա�ʾ�����趨�Ƿ���� 
    bool draw_function_from_data_ready;
    bool move_function_ready;
    bool move_function_from_data_ready;
    bool (* draw_function)(const character_f& now_drawing);//��������ָ�룬ָ�����ú��� 
    bool (* move_function)(const character_f& now_drawing);//�˶�����ָ�룬ָ���趨���˶� 
    bool (* happening )(const character_f& now_facing);
    bool happen_ready;
    
    public:
    
    void change_size(float size)//�ı�����Ĵ�С���ԣ�0��0��0��Ϊ���ĵȾ�Ŵ���С 
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
    void set_move_function(bool (* setting_move_function)(const character_f& now_drawing))//�趨���� 
    {
        move_function=setting_move_function;
        move_function_ready=true;
    }
    void set_draw_function(bool (* setting_draw_function)(const character_f& now_drawing))//�趨���� 
    {
        draw_function=setting_draw_function;
        draw_function_ready=true;
    }
    bool draw(void)//���û������� 
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
    bool read_data_of_character(std::string file)//¼������ 
    {
    }
    bool change_name(const std::string& name_now)//�ı����� 
    {
        name=name_now;
    }
    
    
    character_f::character_f(std::string name_of_this)//���캯��    
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
