void AspectFor3D::ExitAspect(ControlCenter* C,unsigned int& Block,unsigned int& Cul)
{
    Information Tem;
    Tem.Resource=RegeditID;
    Tem.Target=INFCONID;
    Tem.Category1=INFEVENT;
    Tem.Category2=INFEXIT;
    OutLibrary.push_back(Tem);
}
