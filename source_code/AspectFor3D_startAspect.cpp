void AspectFor3D::StartAspect(ControlCenter* C , unsigned int& Block,unsigned int& Cul)
{
    Information Tre;
    static Picture P1;
    switch(Block)
    {
        case 0:
            P1.Load("Texture//start.jpg");
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
                T1.Add("开始");
                T2.Add("读取");
                T3.Add("离开");
                Cul=C->Calculate;
                Block+=1;
                Choice=0;
            }
            break;
        case 2:
            P1.Show(-1.0,1.0,1.0,-1.0);
            if(Choice==0)
            {
                T1.Show(-0.2,0.0,1.0,1.0,0.0);
            }else
                T1.Show(-0.2,0.0,1.0,1.0,1.0);
            if(Choice==1)
            {
                T2.Show(-0.2,-0.2,1.0,1.0,0.0);
            }else
                T2.Show(-0.2,-0.2,1.0,1.0,1.0);
            if(Choice==2)
            {
                T3.Show(-0.2,-0.4,1.0,1.0,0.0);
            }else
                T3.Show(-0.2,-0.4,1.0,1.0,1.0);
            if(Choice==50)
            {
                Tre=NewInformation(Call("Music"),MUSICSTOP);
                Out(Tre);
                Tre=NewInformation(Call("Music"),MUSICPLAY);
                Tre.Data1.i=dance;
                Out(Tre);
                T1.Delete();
                T2.Delete();
                T3.Delete();
                P1.Delete();
                Block=0;
                Cul=C->Calculate;
                ToAspect(4);
            }else if(Choice==51)
            {
                T1.Delete();
                T2.Delete();
                T3.Delete();
                Block=0;
                ToAspect(3);
                Cul=C->Calculate;
                P1.Delete(); 
            }else if(Choice==52)
            {
                T1.Delete();
                T2.Delete();
                T3.Delete();
                ToAspect(80);
            } 
            break;
    }
}
