class Aspect:public Plugin_Base
{
    Cude Te;
    Cude Te2;
    Cude Te3;
    Cude Te4;
    Cude Te5;
    Cude Te6;
    public:
        Aspect():Plugin_Base("Aspect11"),Te(1.0,0.2,1.4),Te2(0.1,2.0,0.1),Te3(0.1,2.0,0.1),Te4(0.1,2.0,0.1),Te5(0.1,2.0,0.1),Te6(1.0,0.1,0.1)
        {
            
        }
        void Show(ControlCenter* Data)
        {
            Perspective();
            while(!Library.empty())
            {
                GetInformation();
            }
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_LINES);
            glVertex3f(1.0,0.0,-2.0);
            glVertex3f(-1.0,0.0,-2.0);
            glEnd();
            Te.Show(XYZF(0.0f,0.0f,-5.0f));
            Te2.Show(XYZF(0.3f,1.1f,-5.5f));
            Te3.Show(XYZF(-0.3f,1.1f,-5.5f));
            Te4.Show(XYZF(0.3f,1.3f,-5.65f));
            Te5.Show(XYZF(-0.3f,1.3f,-5.65f));
            Te6.Show(XYZF(0.0f,2.3f,-5.65f));
            /*glBegin(GL_QUADS);
            glNormal3f(0.0,0.0,-1.0);
            glVertex3f(-0.2f,-0.2f,-0.6f);
            glVertex3f(-0.2f,+0.2f,-0.6f);
            glVertex3f(+0.2f,+0.2f,-0.6f);
            glVertex3f(+0.2f,-0.2f,-0.6f);
            glEnd();*/
            
        }
        void Init(ControlCenter* Data)
        {
            Te.Init();
            Te2.Init();
            Te3.Init();
            Te4.Init();
            Te5.Init();
            Te6.Init();
        }
            
};
