
void PhysicsControl::Analyze(void* Data)
{
    while(!Library.empty())
    {
        Information Tem=GetInformation();
        {
            if(Tem.Target==RegeditID)
            {
                if(Tem.Category1==PHYCHECK)
                {
                    OC.Check();
                    if(!OC.Check(Tem.Data1.f,Tem.Data2.f,Tem.Data3.f,0.1))
                    {
                        er<<"cccccusiba"<<endl;
                        Information Tee=NewInformation(Tem.Resource,PHYOUTSIDE);
                        GetData(Tee,Tem);
                        OutLibrary.push_back(Tee);
                        //check("ss",Tee);
                    }else{
                        er<<"qunide"<<endl;
                        Information Tee=NewInformation(Tem.Resource,PHYINSIDE);
                        GetData(Tee,Tem);
                        OutLibrary.push_back(Tee);
                    }
                }
                if(Tem.Category1==PHYADDMAP)
                {
                    OC.ChangeMap(Tem.Data1.v);
                }
                if(Tem.Category1==PHYADDDEAD)
                {
                    OC.DeadAdd(Tem.Data1.v);
                }
            }
        }
    }
}
