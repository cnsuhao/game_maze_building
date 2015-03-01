#define UINTS 3
void AspectFor3D::MainAspect(ControlCenter* C,unsigned int& Block,unsigned int& Cul)
{        static Robot Rob;
    static Map Ma;
    static wall waa;
    Information Tre;
                switch(Block)
                {
                    case 0:
                        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                        Perspective();
                        waa.Setting("Texture//wall.jpg");
                        waa.Setting(XYZF(-1.0,-1.0,0.0),XYZF(-10.0,0.0,0.0),XYZF(0.0,2.0,0.0),0.2);
                        Block+=1;
                        Rob.Creat(RHuman,0.0,-1.0);
                        rrr.Show();
                        //rrr.Creat(RHuman,0.5,-0.5);
                        glEnable(GL_DEPTH_TEST); // 启用深度测试
                        glDepthFunc(GL_LESS); // 所作深度测试的类型
                        Tre=NewInformation(Call("Physics"),PHYADDMAP);
                        Tre.Data1.v=Ma.Push();
                        OutLibrary.push_back(Tre);
                        Tre=NewInformation(Call("Physics"),PHYADDDEAD);
                        Tre.Data1.v=waa.Data;
                        OutLibrary.push_back(Tre);
                        break;
                    case 1:
                        //Rob.Show();
                        glPushMatrix();
                        glRotatef(20,1.0,0.0,0.0);
                        glRotatef(Angle,0.0,1.0,0.0);
                        glTranslatef(-Lx+UINTS*sin(Angle*0.017453292),-Ly,-Lz-UINTS*cos(Angle*0.017453292));
                        //glTranslatef(0.0,0.0,-25.0);
                        //glTranslatef(-2.0*sin(Angle*0.017453292),0.0,-2.0*cos(Angle*0.017453292));
                        Ma.Show();
                        waa.Show();
                        glColor3f(1.0,1.0,1.0);
                        glBegin(GL_LINES);
                        glVertex3f(Lx,0.0,Lz);
                        glVertex3f(Lx,-1.0,Lz);
                        glVertex3f(Lx,-1.0,Lz);
                        glVertex3f(Lx+sin(Angle*0.017453292),-1.0,Lz-cos(Angle*0.017453292));
                        //glVertex3f(Lx,1.0,Lz);
                        //glVertex3f(Lx+WX,1.0,Lz+Wz);
                        glEnd();
                        glPopMatrix();
                        break;
                 }
}
