#ifndef DIY_MAP_H
#define DIY_MAP_H
#include "Picture.h"
class Map:public OccDeadMap
{
    Picture3D tt;
    bool te;
    public:
        void Show()
        {
            if(!te)
            {
                    tt.Load("Texture//diban.jpg");
                    te=true;
                }
                tt.Show(XYZF(-20,-1.0,-20),XYZF(0,0,40),XYZF(40,0,0));
            /*glBegin(GL_QUADS);
              glColor3f(1.0,1.0,0.0);
              glVertex3f(20.0,-1.0,-20.0);
              glColor3f(1.0,1.0,0.0);
              glVertex3f(-20.0,-1.0,-20.0);
              glColor3f(0.0,1.0,1.0);
              glVertex3f(-20.0,-1.0,20.0);
              glColor3f(0.0,1.0,1.0);
              glVertex3f(20.0,-1.0,20.0);
            glEnd();*/
        }
        Map()
        {
            te=false;
            float Tr[]={20.0,-1.0,-20.0,
                       -20.0,-1.0,-20.0,
                       -20.0,-1.0,20.0,
                       20.0,-1.0,20.0,
                       20.0,-1.0,-20.0};
            Add(Tr,5);
        }
};
#endif
