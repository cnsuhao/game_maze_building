void AspectFor3D::WelcomeAspect(ControlCenter* C,unsigned int& Block, unsigned int & Cul)
{
    Information Tre;
    bool Yes=false;
    static Picture P1;
    static Picture P2;
    static Picture P3;
    static Picture P4;
    float X2,X3,Y2,Y3;
    switch(Block)
    {
        case 0:
            P1.Load("Texture//You Are Wanted.jpg");
            Block+=1;
            break;
        case 1:
            P1.Show(-1.0,1.0,1.0,-1.0);
            if((C->Cal(Cul)*0.01)<=1)
            {
                glColor4f(0.0,0.0,0.0,1-(C->Cal(Cul)*0.01));
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glEnable(GL_BLEND);
                glBegin(GL_QUADS);
                glVertex2f(-1.0,1.0);
                glVertex2f(-1.0,-1.0);
                glVertex2f(1.0,-1.0);
                glVertex2f(1.0,1.0);
                glEnd();
                glDisable(GL_BLEND);
            }else{
                Cul=C->Calculate;
                Block+=1;
            }
            break;
        case 2:
            P1.Show(-1.0,1.0,1.0,-1.0);
            if(C->Cal(Cul)>=50)
            {
                glColor4f(0.0,0.0,0.0,(C->Cal(Cul)-50)*0.01);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glEnable(GL_BLEND);
                glBegin(GL_QUADS);
                glVertex2f(-1.0,1.0);
                glVertex2f(-1.0,-1.0);
                glVertex2f(1.0,-1.0);
                glVertex2f(1.0,1.0);
                glEnd();
                glDisable(GL_BLEND);
                if((C->Cal(Cul)-50)*0.01>1)
                {
                    Block+=1;
                    Cul=C->Calculate;
                    P1.Delete();
                    P1.Load("Texture//A1Background.jpg");
                                                Tre=NewInformation(Call("Music"),MUSICPLAY);
            Tre.Data1.i=angel;
            Out(Tre);
            Yes=true;
                }
            }
            break;
        case 3:
            P1.Show(-1.0,1.0,1.0,-1.0);
            if((C->Cal(Cul)*0.1)<=1)
            {
                glColor4f(0.0,0.0,0.0,1-(C->Cal(Cul)*0.1));
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glEnable(GL_BLEND);
                glBegin(GL_QUADS);
                glVertex2f(-1.0,1.0);
                glVertex2f(-1.0,-1.0);
                glVertex2f(1.0,-1.0);
                glVertex2f(1.0,1.0);
                glEnd();
                glDisable(GL_BLEND);
            }else if(C->Cal(Cul)>=50)
            {
                P2.Load("Texture//walk.bmp",0,255,255);
                P3.Load("Texture//BOSS.bmp",0,0,255);
                P3.Turn(LEFTRIGHT);
                Block+=1;
                Cul=C->Calculate;
            }
            break;
        case 4:
            P1.Show(-1.0,1.0,1.0,-1.0);
            X2=3.5/300*(C->Cal(Cul)%300)-1.2;
            Y2=-0.43;
            X3=3.5/300*(C->Cal(Cul)%300)-1.8;
            Y3=-0.25;
                if(C->Cal(Cul)%16<=2)
                {
                    P2.Cutting(0.5f,1.0f,0.6f,0.0f);
                }else  if(C->Cal(Cul)%16<=4)
                {
                    P2.Cutting(0.6f,1.0f,0.7f,0.0f);
                }else  if(C->Cal(Cul)%16<=6)
                {
                    P2.Cutting(0.69f,1.0f,0.79f,0.0f);
                }else  if(C->Cal(Cul)%16<=8)
                {
                    P2.Cutting(0.78f,1.0f,0.88f,0.0f);
                }else if(C->Cal(Cul)%16<=10)
                {
                    P2.Cutting(0.89f,1.0f,0.99f,0.0f);
                }else  if(C->Cal(Cul)%16<=12)
                        {
                            P2.Cutting(0.78f,1.0f,0.88f,0.0f);
                        }else  if(C->Cal(Cul)%16<=14)
                        {
                            P2.Cutting(0.69f,1.0f,0.79f,0.0f);
                        }else
                        {
                            P2.Cutting(0.6f,1.0f,0.7f,0.0f);
                        }
                    
                    P2.Show(X2,Y2,X2+0.125,Y2-0.2);
                    P3.Show(X3,Y3,X3+0.4,Y3-0.4);
                    if(X3>=1.2)
                    {
                        Cul=C->Calculate;
                        Block+=1;
                        //P3.Delete();
                        P2.Turn(LEFTRIGHT);
                        P4.Load("Texture//peach.bmp",0,0,255);
                    }
                    break;
                case 5:
                    P1.Show(-1.0,1.0,1.0,-1.0);
                    X2=-3.5/300*(C->Cal(Cul)%300)+1.2;
                    Y2=-0.43;
                    X3=-3.5/300*(C->Cal(Cul)%300)+1.8;
                    Y3=-0.43;
                        if(C->Cal(Cul)%16<=2)
                        {
                            P2.Cutting(0.5f,1.0f,0.6f,0.0f);
                        }else  if(C->Cal(Cul)%16<=4)
                        {
                            P2.Cutting(0.6f,1.0f,0.7f,0.0f);
                        }else  if(C->Cal(Cul)%16<=6)
                        {
                            P2.Cutting(0.69f,1.0f,0.79f,0.0f);
                        }else  if(C->Cal(Cul)%16<=8)
                        {
                            P2.Cutting(0.78f,1.0f,0.88f,0.0f);
                        }else if(C->Cal(Cul)%16<=10)
                        {
                            P2.Cutting(0.89f,1.0f,0.99f,0.0f);
                        }else  if(C->Cal(Cul)%16<=12)
                        {
                            P2.Cutting(0.78f,1.0f,0.88f,0.0f);
                        }else  if(C->Cal(Cul)%16<=14)
                        {
                            P2.Cutting(0.69f,1.0f,0.79f,0.0f);
                        }else
                        {
                            P2.Cutting(0.6f,1.0f,0.7f,0.0f);
                        }
    
                    P2.Show(X2,Y2,X2+0.125,Y2-0.2);
                    P4.Show(X3,Y3,X3+0.125,Y3-0.2);
                    if(X3<=-1.2)
                    {
                        Block+=1;
                        P4.Turn(LEFTRIGHT);
                        P3.Turn(LEFTRIGHT);
                        P2.Delete();
                        P2.Load("Texture//wenhao.jpg",0,255,255);
                        Cul=C->Calculate;
                    }
                    break;
                case 6:
                    P1.Show(-1.0,1.0,1.0,-1.0);
                    X2=-3.5/300*(C->Cal(Cul)%300)+1.0;
                    Y2=-0.25;
                    X3=3.5/300*(C->Cal(Cul)%300)-1.2;
                    Y3=-0.43;
                    P3.Show(X2,Y2,X2+0.4,Y2-0.4);
                    P4.Show(X3,Y3,X3+0.125,Y3-0.2);
                    if(C->Cal(Cul)>=50)
                    {
                        Block+=1;
                    }
                    break;
                case 7:
                    X2=-3.5/300*50+1.0;
                    Y2=-0.25;
                    X3=3.5/300*50-1.2;
                    Y3=-0.43;
                    P1.Show(-1.0,1.0,1.0,-1.0);
                    P2.Show(0.317,-0.2,0.417,-0.4);
                    P3.Show(X2,Y2,X2+0.4,Y2-0.4);
                    P4.Show(X3,Y3,X3+0.125,Y3-0.2);
                    if(C->Cal(Cul)>=100)
                    {
                        Block+=1;
                        P3.Turn(LEFTRIGHT);
                        Cul=C->Calculate;
                    }
                    break;
                case 8:
                    X2=-3.5/300*50+1.0+3.5/300*(C->Cal(Cul)%300);
                    Y2=-0.25;
                    X3=3.5/300*50-1.2+3.5/300*(C->Cal(Cul)%300);
                    Y3=-0.43;
                    P1.Show(-1.0,1.0,1.0,-1.0);
                    P3.Show(X2,Y2,X2+0.4,Y2-0.4);
                    P4.Show(X3,Y3,X3+0.125,Y3-0.2);
                    if(X3>=1.2)
                    {
                        Block+=1;
                        P3.Turn(LEFTRIGHT);
                        P4.Turn(LEFTRIGHT);
                        P2.Load("Texture//walk.bmp",0,255,255);
                        P2.Turn(LEFTRIGHT);
                        Cul=C->Calculate;
                    }
                    break;
                case 9:
                        if(C->Cal(Cul)%16<=2)
                        {
                            P2.Cutting(0.5f,1.0f,0.6f,0.0f);
                        }else  if(C->Cal(Cul)%16<=4)
                        {
                            P2.Cutting(0.6f,1.0f,0.7f,0.0f);
                        }else  if(C->Cal(Cul)%16<=6)
                        {
                            P2.Cutting(0.69f,1.0f,0.79f,0.0f);
                        }else  if(C->Cal(Cul)%16<=8)
                        {
                            P2.Cutting(0.78f,1.0f,0.88f,0.0f);
                        }else if(C->Cal(Cul)%16<=10)
                        {
                            P2.Cutting(0.89f,1.0f,0.99f,0.0f);
                        }else  if(C->Cal(Cul)%16<=12)
                        {
                            P2.Cutting(0.78f,1.0f,0.88f,0.0f);
                        }else  if(C->Cal(Cul)%16<=14)
                        {
                            P2.Cutting(0.69f,1.0f,0.79f,0.0f);
                        }else
                        {
                            P2.Cutting(0.6f,1.0f,0.7f,0.0f);
                        }
                
                    X2=-3.5/300*(C->Cal(Cul)%300)+1.0;
                    Y2=-0.25;
                    X3=-3.5/300*(C->Cal(Cul)%300)+1.8;
                    Y3=-0.43;
                    P1.Show(-1.0,1.0,1.0,-1.0);
                    P2.Show(X3-0.4,Y3,X3+0.125-0.4,Y3-0.2);
                    P3.Show(X2,Y2,X2+0.4,Y2-0.4);
                    P4.Show(X3,Y3,X3+0.125,Y3-0.2);
                    if(X3<=-1.2)
                    {
                        Block+=1;
                        Cul=C->Calculate;
                    }
                    break;
                case 10:
                    P1.Show(-1.0,1.0,1.0,-1.0);
                    if(C->Cal(Cul)>=50)
                    {
                        glColor4f(0.0,0.0,0.0,(C->Cal(Cul)-50)*0.01);
                        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                        glEnable(GL_BLEND);
                        glBegin(GL_QUADS);
                        glVertex2f(-1.0,1.0);
                        glVertex2f(-1.0,-1.0);
                        glVertex2f(1.0,-1.0);
                        glVertex2f(1.0,1.0);
                        glEnd();
                        glDisable(GL_BLEND);
                        if((C->Cal(Cul)-50)*0.01>1)
                        {
                            Block=0;
                            Cul=C->Calculate;
                            P1.Delete();
                            P2.Delete();
                            P3.Delete();
                            P4.Delete();
                            ToAspect(2);
                            Choice=0;
                       }
                    }
                    break;
                case 20:
                    if(!Yes)
                    {
                  Tre=NewInformation(Call("Music"),MUSICPLAY);
            Tre.Data1.i=angel;
            Out(Tre);
                    }
                    Cul=C->Calculate;
                    Block=0;
                    Choice=0;
                    P1.Delete();
                    P2.Delete();
                    P3.Delete();
                    P4.Delete();
                    ToAspect(2);
                    break;
        }
}
