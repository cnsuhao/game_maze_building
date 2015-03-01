#ifndef WORD_H
#define WORD_H
#include <map>
#define W_LIST_END 99999
#define W_LINE 99998
#define W_LOOP 99997
#define W_POINT 99996
#define NOTLIMITED -1
inline void draw_f_v(float* points, float x, float y, float z, float size)
{
    glVertex3f((*points)*size+x, (*(points+1))*size+y, (*(points+2))*size+z);
}
float face_of_the_word[3];
float size_of_the_word=0.1;
float width_of_the_line=4.0;
bool WORD_READY_TO_USE=false;
int number_of_a_line=NOTLIMITED;
std::map < char, float* > word_map_f;
std::map < char, int > word_map_i;
float word_A[]={-0.5, -1.0, 0,
                   0,  1.0, 0,
                 0.5, -1.0, 0,
                W_LINE,
                0.25,    0, 0,
               -0.25,    0, 0,
                 W_LIST_END};
float word_a[]={-0.3, -0.1, 0,
                -0.2,  0.0, 0,
                 0.2,  0.0, 0,
                 0.3, -0.1, 0,
                 0.3, -1.0, 0,
                -0.2, -1.0, 0,
                -0.3, -0.8, 0,
                -0.3, -0.6, 0,
                -0.2, -0.4, 0,
                 0.2, -0.4, 0,
                 0.3, -0.6, 0,
                 W_LIST_END};
float word_B[]={-0.4,  1.0, 0,
                 0.3,  1.0, 0,
                 0.4,  0.8, 0,
                 0.4,  0.2, 0,
                 0.1,    0, 0,
                -0.4,    0, 0,
                 0.1,    0, 0,
                 0.4, -0.2, 0,
                 0.4, -0.8, 0,
                 0.3, -1.0, 0,
                -0.4, -1.0, 0,
                -0.4,  1.0, 0,
                 W_LIST_END};                 
float word_b[]={-0.3,  1.0, 0,
                -0.3, -1.0, 0,
                 0.2, -1.0, 0,
                 0.3, -0.8, 0,
                 0.3, -0.2, 0,
                 0.2,    0, 0,
                -0.3,    0, 0,
                 W_LIST_END};
float word_C[]={ 0.4,  0.8, 0,
                 0.2,  1.0, 0,
                -0.2,  1.0, 0,
                -0.4,  0.7, 0,
                -0.4, -0.7, 0,
                -0.2, -1.0, 0,
                 0.2, -1.0, 0,
                 0.4, -0.8, 0,
                 W_LIST_END};
float word_c[]={ 0.3,  -0.2, 0,
                 0.2,  0, 0,
                -0.2,  0, 0,
                -0.3,  -0.3, 0,
                -0.3, -0.7, 0,
                -0.2, -1.0, 0,
                 0.2, -1.0, 0,
                 0.3, -0.8, 0,
                 W_LIST_END};
float word_D[]={-0.4,  1.0, 0,
                -0.4, -1.0, 0,
                 0.3, -1.0, 0,
                 0.4, -0.8, 0,
                 0.4,  0.8, 0,
                 0.3,  1.0, 0,
                -0.4,  1.0, 0,
                 W_LIST_END};
float word_d[]={ 0.3,  1.0, 0,
                 0.3, -1.0, 0,
                -0.2, -1.0, 0,
                -0.3, -0.8, 0,
                -0.3, -0.2, 0,
                -0.2,    0, 0,
                 0.3,    0, 0,
                 W_LIST_END};
float word_E[]={ 0.4,  1.0, 0,
                -0.4,  1.0, 0,
                -0.4,    0, 0,
                 0.3,    0, 0,
                -0.4,    0, 0,
                -0.4, -1.0, 0,
                 0.4, -1.0, 0,
                 W_LIST_END};
float word_e[]={-0.3, -0.5, 0,
                 0.3, -0.5, 0,
                 0.3, -0.1, 0,
                 0.2,    0, 0,
                -0.2,    0, 0,
                -0.3, -0.1, 0,
                -0.3, -1.0, 0,
                 0.2, -1.0, 0,
                 0.3, -0.8, 0,
                 W_LIST_END};
float word_F[]={ 0.4,  1.0, 0,
                -0.4,  1.0, 0,
                -0.4,    0, 0,
                 0.4,    0, 0,
                -0.4,    0, 0,
                -0.4, -1.0, 0,
                 W_LIST_END};
float word_f[]={ 0.4,  0.8, 0,
                 0.3,  1.0, 0,
                 0.1,  1.0, 0,
                   0,  0.8, 0,
                   0, -1.8, 0,
                -0.1, -2.0, 0,
                -0.3, -2.0, 0,
                -0.4, -1.8, 0,
                 W_LINE,
                -0.3,    0, 0,
                 0.3,    0, 0,
                 W_LIST_END};
float word_G[]={ 0.4,  0.8, 0,
                 0.3,  1.0, 0,
                -0.3,  1.0, 0,
                -0.4,  0.8, 0,
                -0.4, -0.8, 0,
                -0.3, -1.0, 0,
                 0.3, -1.0, 0,
                 0.4, -0.8, 0,
                 0.4,    0, 0,
                 0.1,    0, 0,
                 W_LIST_END};
float word_g[]={ 0.3, -1.0, 0,
                 0.3,    0, 0,
                -0.2,    0, 0,
                -0.3, -0.2, 0,
                -0.3, -0.8, 0,
                -0.2, -1.0, 0,
                 0.3, -1.0, 0,
                 0.3, -1.8, 0,
                 0.2, -2.0, 0,
                -0.2, -2.0, 0,
                -0.3, -1.8, 0,
                 W_LIST_END};
float word_H[]={ 0.4,  1.0, 0,
                 0.4, -1.0, 0,
                 0.4,    0, 0,
                -0.4,    0, 0,
                -0.4,  1.0, 0,
                -0.4, -1.0, 0,
                 W_LIST_END};
float word_h[]={-0.3,  1.0, 0,
                -0.3, -1.0, 0,
                -0.3, -0.2, 0,
                -0.2,    0, 0,
                 0.2,    0, 0,
                 0.3, -0.2, 0,
                 0.3, -1.0, 0,
                 W_LIST_END};
float word_I[]={ 0.3,  1.0, 0,
                -0.3,  1.0, 0,
                   0,  1.0, 0,
                   0, -1.0, 0,
                -0.3, -1.0, 0,
                 0.3, -1.0, 0,
                 W_LIST_END};
float word_i[]={-0.1,  0.5, 0,
                 0.1,  0.4, 0,
                -0.3, -0.3, 0,
                   0, -0.1, 0,
                   0, -1.0, 0,
                 0.2, -0.8, 0,
                 W_LIST_END};
float word_J[]={ 0.4,  1.0, 0,
                -0.4,  1.0, 0,
                   0,  1.0, 0,
                   0, -0.8, 0,
                -0.1, -1.0, 0,
                -0.3, -1.0, 0,
                -0.4, -1.0, 0,
                 W_LIST_END};
float word_j[]={-0.1,  0.5, 0,
                 0.1,  0.4, 0,
                -0.3, -0.3, 0,
                   0, -0.1, 0,
                   0, -1.8, 0,
                -0.1, -2.0, 0,
                -0.2, -2.0, 0,
                -0.4, -1.8, 0,
                 W_LIST_END};
float word_K[]={-0.4,  1.0, 0,
                -0.4, -1.0, 0,
                -0.4,    0, 0,
                 0.3,  1.0, 0,
                -0.4,    0, 0,
                   0, -0.8, 0,
                 0.3, -1.0, 0,
                 W_LIST_END};
float word_k[]={-0.3,  1.0, 0,
                -0.3, -1.0, 0,
                -0.3, -0.5, 0,
                 0.3,    0, 0,
                -0.3, -0.5, 0,
                 0.3, -1.0, 0,
                 W_LIST_END};
float word_L[]={-0.3,  1.0, 0,
                -0.3, -1.0, 0,
                 0.3, -1.0, 0,
                 W_LIST_END};
float word_l[]={-0.2,  0.7, 0,
                 0.1,  1.0, 0,
                -0.1, -1.0, 0,
                 0.1, -1.0, 0,
                 0.3, -0.8, 0,
                 W_LIST_END};
float word_N[]={-0.4, -1.0, 0,
                -0.4,  1.0, 0,
                 0.4, -1.0, 0,
                 0.4,  1.0, 0,
                 W_LIST_END};
float word_n[]={-0.3, -1.0, 0,
                -0.3, -0.2, 0,
                -0.2,    0, 0,
                 0.2,    0, 0,
                 0.3, -0.2, 0,
                 0.3, -1.0, 0,
                 W_LIST_END};
float word_M[]={-0.4, -1.0, 0,
                -0.4,  1.0, 0,
                   0, -0.8, 0,
                 0.4,  1.0, 0,
                 0.4, -1.0, 0,
                 W_LIST_END};
float word_m[]={-0.3, -1.0, 0,
                -0.3, -0.2, 0,
                -0.2,    0, 0,
                   0,    0, 0,
                   0, -1.0, 0,
                   0,    0, 0,
                 0.2,    0, 0,
                 0.3, -0.2, 0,
                 0.3, -1.0, 0,
                W_LIST_END};
float word_O[]={ 0.4,  0.8, 0,
                 0.3,  1.0, 0,
                -0.3,  1.0, 0,
                -0.4,  0.8, 0,
                -0.4, -0.8, 0,
                -0.3, -1.0, 0,
                 0.3, -1.0, 0,
                 0.4, -0.8, 0,
                 0.4,  0.8, 0,
                 W_LIST_END};
float word_o[]={ 0.3, -0.2, 0,
                 0.2,    0, 0,
                -0.2,    0, 0,
                -0.3, -0.2, 0,
                -0.3, -0.8, 0,
                -0.2, -1.0, 0,
                 0.2, -1.0, 0,
                 0.3, -0.8, 0,
                 0.3, -0.2, 0,
                 W_LIST_END};
float word_P[]={-0.3, -1.0, 0,
                -0.3,  0.8, 0,
                -0.2,  1.0, 0,
                 0.2,  1.0, 0,
                 0.3,  0.8, 0,
                 0.3,  0.2, 0,
                 0.2,    0, 0,
                -0.3,    0, 0,
                 W_LIST_END};
float word_p[]={-0.4, -0.4, 0,
                -0.2,    0, 0,
                -0.2, -2.0, 0,
                -0.2, -0.2, 0,
                -0.1,    0, 0,
                 0.1,    0, 0,
                 0.2, -0.2, 0,
                 0.2, -0.8, 0,
                 0.1, -1.0, 0,
                -0.2, -1.0, 0,
                 W_LIST_END};
float word_Q[]={-0.4,    0, 0,
                -0.3,  0.7, 0,
                -0.2,  0.9, 0,
                -0.1, 0.97, 0,
               -0.05, 0.99, 0,
               -0.03, 0.99, 0,
                   0,  1.0, 0, 
                0.03, 0.99, 0,   
                0.05, 0.99, 0,
                 0.1, 0.97, 0,
                 0.2,  0.9, 0,
                 0.3,  0.7, 0,
                 0.4,    0, 0,
                 0.3, -0.7, 0,
                0.35, -0.8, 0,
                 0.5, -0.9, 0, 
                0.35, -0.8, 0,
                 0.3, -0.7, 0,
                0.25, -0.6, 0,
                 0.1, -0.5, 0,
                0.25, -0.6, 0,
                 0.3, -0.7, 0,
                 0.2, -0.9, 0,
                 0.1,-0.97, 0,
                0.05,-0.99, 0,
                0.03,-0.99, 0,
                   0, -1.0, 0,
               -0.03,-0.99, 0,
               -0.05,-0.99, 0,
                -0.1,-0.97, 0,
                -0.2, -0.9, 0,
                -0.3, -0.7, 0,
                -0.4,    0, 0,        
                 W_LIST_END};
float word_q[]={ 0.3,    0, 0,
                 0.3, -1.0, 0,
                 0.3,-0.15, 0,
                 0.2, -0.3, 0,    
                 0.1, -0.4, 0,
                   0, -0.5, 0,
                -0.1, -0.4, 0,
                -0.2, -0.3, 0,
               -0.25, -0.1, 0,
                -0.2,  0.2, 0,
                -0.1,  0.3, 0,
                   0,  0.4, 0,
                 0.1,  0.3, 0,
                 0.2, 0.25, 0,
                 0.3,    0, 0,
                 0.4,  0.2, 0,                      
                 W_LIST_END};
float word_R[]={-0.4, -1.05, 0,
                -0.4,    1, 0,
                -0.4,  0.8, 0,
                -0.3, 0.79, 0,
                -0.2, 0.77, 0,
                -0.1, 0.72, 0,
                   0, 0.60, 0,
                 0.1, 0.50, 0,
                 0.2, 0.35, 0,
                 0.3, 0.15, 0,
                0.35,  0.1, 0,
                 0.4, -0.3, 0,
                 0.3, -0.34, 0, 
                 0.2,-0.40, 0,
                 0.1,-0.44, 0,
                   0,-0.46, 0,
                -0.1,-0.48, 0,
                -0.2,-0.49, 0,
                -0.3,-0.49, 0, 
                 0.4, -1.0, 0,                           
                 W_LIST_END};
float word_r[]={-0.3, -0.2, 0,
                -0.2,-0.08, 0,
                -0.1,-0.04, 0,
               -0.05,    0, 0,
                0.02, -0.2, 0,
                0.02, -1.0, 0,
                0.02, -0.3, 0,
                 0.1, -0.1, 0,
                 0.2,-0.05, 0,   
                 0.3,    0, 0,
                 W_LIST_END};
float word_S[]={ 0.4,  0.8, 0,
                 0.4,  0.4, 0,
                 0.3,  0.7, 0,
                 0.2, 0.82, 0,
                 0.1, 0.95, 0,
                   0,  1.0, 0,
                -0.1, 0.95, 0,
                -0.2, 0.86, 0,
                -0.3,  0.7, 0,
                -0.4, 0.45, 0,
                -0.3, 0.25, 0,
                -0.2,  0.1, 0,
                -0.1, 0.01, 0,
                   0,    0, 0,
                 0.1,-0.01, 0,
                 0.2, -0.1, 0,
                 0.3,-0.25, 0,
                 0.4,-0.45, 0,
                 0.3, -0.7, 0,
                 0.2,-0.86, 0,
                 0.1,-0.95, 0,
                   0, -1.0, 0,
                -0.1,-0.95, 0,
                -0.2,-0.82, 0,
                -0.3, -0.7, 0,
                -0.4, -0.4, 0,
                -0.4, -0.8, 0,      
                 W_LIST_END};
float word_s[]={0.3, -0.2, 0,
                0.3, -0.1, 0,
                0.2,-0.09, 0,
                0.1,-0.02, 0,
                  0,    0, 0,
               -0.1,-0.02, 0,
               -0.2, -0.1, 0,
               -0.3, -0.2, 0,
               -0.2,-0.32, 0,
               -0.1,-0.42, 0,
                  0, -0.5, 0,
                0.1,-0.58, 0,
                0.2,-0.68, 0,
                0.3, -0.8, 0,
                0.2, -0.9, 0,
                0.1,-0.98, 0,
                  0,   -1, 0,
               -0.1,-0.98, 0,
               -0.2,-0.91, 0,
               -0.3, -0.9, 0,
               -0.3, -0.8, 0,         
                 W_LIST_END};
float word_T[]={-0.4,  0.8, 0, 
               -0.42,  1.0, 0,
                0.42,  1.0, 0,
                 0.4,  0.8, 0,
                0.42,  1.0, 0,
                   0,  1.0, 0,
                   0, -1.0, 0,          
                 W_LIST_END};    
float word_t[]={-0.3, -0.2, 0,
                 0.2, -0.2, 0,
                -0.1, -0.2, 0,
                -0.1,  0.1, 0,
                -0.1, -1.0, 0,
                 0.3, -1.0, 0,
                 0.3, -0.7, 0,
                 W_LIST_END};   
float word_U[]={-0.4,   1.0, 0,
                -0.4,  -0.7, 0, 
                -0.3,  -1.0, 0,
                 0.3,  -1.0, 0,
                 0.4,  -0.7, 0,
                 0.4,   1.0, 0,
                 W_LIST_END};
float word_u[]={-0.3,     0, 0, 
                -0.3,  -0.8, 0,
                -0.2,  -1.0, 0,
                 0.2,  -1.0, 0,
                 0.3,  -0.8, 0,  
                 0.3,     0, 0, 
                 0.3,  -0.8, 0,
                 0.4, -1.0,0,                  
                 W_LIST_END}; 
float word_V[]={-0.4,  1.0, 0,
                   0, -1.0, 0,
                 0.4,  1.0, 0,
                W_LIST_END};   
float word_v[]={-0.3,    0, 0,
                   0, -1.0, 0,
                 0.3,    0, 0,  
                W_LIST_END}; 
float word_W[]={-0.5,  1.0, 0,
               -0.25, -1.0, 0,
                   0, 0.65, 0,
                0.25, -1.0, 0,
                 0.5,  1.0, 0,
                W_LIST_END}; 
float word_w[]={-0.3,  0.1, 0,
               -0.15, -1.0, 0,
                   0,-0.285, 0,
                0.15, -1.0, 0,
                 0.3,  0.1, 0,
                W_LIST_END};                      
float word_X[]={-0.4,  1.0, 0,
                 0.4, -1.0, 0,
                   0,    0, 0,
                 0.4,  1.0, 0,
                -0.4, -1.0, 0,
                W_LIST_END};
float word_x[]={-0.3,    0, 0,
                 0.3, -1.0, 0,
                   0, -0.5, 0,
                 0.3,    0, 0,
                -0.3, -1.0, 0,
                 W_LIST_END};          
float word_Y[]={-0.4,  1.0, 0,
                   0,    0, 0,
                   0, -1.0, 0,
                   0,    0, 0,
                 0.4,  1.0, 0,
                 W_LIST_END};
float word_y[]={-0.27,  0.2, 0,
                   0,-0.45, 0,
                 0.27,  0.2, 0,
                -0.27, -1.1, 0,
                 W_LIST_END};        
float word_Z[]={-0.4,  0.9, 0,
                 0.4,  0.9, 0,
                -0.4, -0.9, 0,
                 0.4, -0.9, 0,
                  W_LIST_END};
float word_z[]={-0.3,    0, 0,
                 0.3,    0, 0,
                -0.3, -1.0, 0,
                 0.3, -1.0, 0,    
                  W_LIST_END};                  
void getmap()
{
word_map_f.insert(std::pair<char, float*>('A', word_A));
word_map_f.insert(std::pair<char, float*>('a', word_a));
word_map_f.insert(std::pair<char, float*>('B', word_B));
word_map_f.insert(std::pair<char, float*>('b', word_b));
word_map_f.insert(std::pair<char, float*>('C', word_C));
word_map_f.insert(std::pair<char, float*>('c', word_c));
word_map_f.insert(std::pair<char, float*>('D', word_D));
word_map_f.insert(std::pair<char, float*>('d', word_d));
word_map_f.insert(std::pair<char, float*>('E', word_E));
word_map_f.insert(std::pair<char, float*>('e', word_e));
word_map_f.insert(std::pair<char, float*>('F', word_F));
word_map_f.insert(std::pair<char, float*>('f', word_f));
word_map_f.insert(std::pair<char, float*>('G', word_G));
word_map_f.insert(std::pair<char, float*>('g', word_g));
word_map_f.insert(std::pair<char, float*>('H', word_H));
word_map_f.insert(std::pair<char, float*>('h', word_h));
word_map_f.insert(std::pair<char, float*>('I', word_I));
word_map_f.insert(std::pair<char, float*>('i', word_i));
word_map_f.insert(std::pair<char, float*>('J', word_J));
word_map_f.insert(std::pair<char, float*>('j', word_j));
word_map_f.insert(std::pair<char, float*>('K', word_K));
word_map_f.insert(std::pair<char, float*>('k', word_k));
word_map_f.insert(std::pair<char, float*>('L', word_L));
word_map_f.insert(std::pair<char, float*>('l', word_l));
word_map_f.insert(std::pair<char, float*>('N', word_N));
word_map_f.insert(std::pair<char, float*>('n', word_n));
word_map_f.insert(std::pair<char, float*>('M', word_M));
word_map_f.insert(std::pair<char, float*>('m', word_m));
word_map_f.insert(std::pair<char, float*>('O', word_O));
word_map_f.insert(std::pair<char, float*>('o', word_o));
word_map_f.insert(std::pair<char, float*>('P', word_P));
word_map_f.insert(std::pair<char, float*>('p', word_p));
word_map_f.insert(std::pair<char, float*>('Q', word_Q));
word_map_f.insert(std::pair<char, float*>('q', word_q));
word_map_f.insert(std::pair<char, float*>('R', word_R));
word_map_f.insert(std::pair<char, float*>('r', word_r));
word_map_f.insert(std::pair<char, float*>('S', word_S));
word_map_f.insert(std::pair<char, float*>('s', word_s));
word_map_f.insert(std::pair<char, float*>('T', word_T));
word_map_f.insert(std::pair<char, float*>('t', word_t));
word_map_f.insert(std::pair<char, float*>('U', word_U));
word_map_f.insert(std::pair<char, float*>('u', word_u));
word_map_f.insert(std::pair<char, float*>('V', word_V));
word_map_f.insert(std::pair<char, float*>('v', word_v));
word_map_f.insert(std::pair<char, float*>('W', word_W));
word_map_f.insert(std::pair<char, float*>('w', word_w));
word_map_f.insert(std::pair<char, float*>('X', word_X));
word_map_f.insert(std::pair<char, float*>('x', word_x));
word_map_f.insert(std::pair<char, float*>('Y', word_Y));
word_map_f.insert(std::pair<char, float*>('y', word_y));
word_map_f.insert(std::pair<char, float*>('Z', word_Z));
word_map_f.insert(std::pair<char, float*>('z', word_z));
WORD_READY_TO_USE=true;
}
void word_mode(float size=0.1, float width=4.0, int number=NOTLIMITED, float* face=face_of_the_word)
{
    if(size>0)
        size_of_the_word=size;
    if(width>0)
        width_of_the_line=width;
    if(number<=0&&number!=NOTLIMITED)
         number_of_a_line=NOTLIMITED;
    else
         number_of_a_line=number;
    if(face_of_the_word!=face)
    {
        float* points=face;
        for(int i=0;i<3;++i,++points)
        {
            face_of_the_word[i]=*points;
        }
    }
}
void drawaword_f(const char* sentence, float x=0, float y=0, float z=0)
{
    if( WORD_READY_TO_USE )
    {
        x+=0.5*size_of_the_word;
        glLineWidth(width_of_the_line);
        int xtimes(0);
        int ytimes(0);
        for(int i=0; *(sentence+i)!='\0' ;++i,++xtimes)
        {
            if(number_of_a_line!=NOTLIMITED)
            {
                if(xtimes>=number_of_a_line)
                {
                    ++ytimes;
                    xtimes=0;
                }
            }
            if(word_map_f.count(*(sentence+i)))
            {
                glBegin(GL_LINE_STRIP);
                for(float* wordf=word_map_f[*(sentence+i)]; *wordf!= W_LIST_END ; wordf+=3)
                {
                    if( *wordf==W_LINE )
                    {
                        glEnd();
                        glBegin(GL_LINES);
                        ++wordf;
                    }
                    if( *wordf==W_POINT )
                    {
                        glEnd();
                        glBegin(GL_POINTS);
                        ++wordf;
                    }
                    if( *wordf==W_LOOP)
                    {
                        glEnd();
                        glBegin(GL_LINE_STRIP);
                        ++wordf;
                    }
                    draw_f_v(wordf, x+xtimes*size_of_the_word*1, y-ytimes*size_of_the_word*4.5, z, size_of_the_word);
                }
                glEnd();
           }    
        }
   }
}
#endif
