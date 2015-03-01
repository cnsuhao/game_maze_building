#ifndef DIY_BASECLASS_H
#define DIY_BASECLASS_H
#include <math.h>
#define FACEXZ 1
#define FACEXY 2
#define FACEYZ 3
class XYF
{
    public:
        float X;
        float Y;
        float Set(const float& x,const float& y)
        {
            X=x;
            Y=y;
        }
        float Distance(const XYF& Tem)
        {
            return sqrt((X-Tem.X)*(X-Tem.X)+(Y-Tem.Y)*(Y-Tem.Y));
        }
        float Distance(const XYF& T1,const XYF& T2)
        {
            
        }
        float Long(void)
        {
            return sqrt(X*X+Y*Y);
        }
        float Long2(void)
        {
            return X*X+Y*Y;
        }
        void Uint(const float Multiply)
        {
            float Line=Long();
            if(Line!=0)
            {
                X=X/Line*Multiply;
                Y=Y/Line*Multiply;
            }
        }
        XYF(float x=0.0 , float y=0.0 ):X(x),Y(y){}
};




class XYZF
{
    public:
        float X;
        float Y;
        float Z;
        void Turn(float x,float y,float z)//�����ƣ��Ը��Ḻ����Ϊ��������ʱ����ת 
        {
            XYZF Tem(X,Y,Z);
            XYZF RT=Tem;
            Tem.Set(RT.X,RT.Y*cos(x)-RT.Z*sin(x),RT.Z*cos(x)+RT.Y*sin(x));
            RT=Tem;
            Tem.Set(RT.X*cos(y)+RT.Z*sin(y),RT.Y,RT.Z*cos(y)-RT.X*sin(y));
            RT=Tem;
            Tem.Set(RT.X*cos(z)-RT.Y*sin(z),RT.Y*cos(z)+RT.X*sin(z),RT.Z);
            X=Tem.X;
            Y=Tem.Y;
            Z=Tem.Z;
        }
        void Turn(float d,char Mode)
        {
            float Long;
            XYZF Tem;
            switch(Mode)
            {
                case FACEXY:
                    Long=sqrt(X*X+Y*Y);
                    Tem.Set((cos(d)-Z/Long*sin(d))*X,(cos(d)-Z/Long*sin(d))*Y,Long*sin(d)+Z*cos(d));
                    *this=Tem;
                    break;
                case FACEXZ:
                    Long=sqrt(X*X+Z*Z);
                    Tem.Set((cos(d)-Y/Long*sin(d))*X,Long*sin(d)+Y*cos(d),(cos(d)-Y/Long*sin(d))*Z);
                    *this=Tem;
                    break;
                case FACEYZ:
                    Long=sqrt(Y*Y+Z*Z);
                    Tem.Set(Long*sin(d)+X*cos(d),(cos(d)-X/Long*sin(d))*Y,(cos(d)-X/Long*sin(d))*Z);
                    *this=Tem;
                    break;
            }
        }
        void Set(float x,float y,float z)
        {
            X=x;
            Y=y;
            Z=z;
        }
        float Distance(XYZF& Tem)
        {
            return sqrt((X-Tem.X)*(X-Tem.X)+(Y-Tem.Y)*(Y-Tem.Y)+(Z-Tem.Z)*(Z-Tem.Z));
        }
        float Long(void)
        {
            return sqrt(X*X+Y*Y+Z*Z);
        }
        float Long2(void)
        {
            return X*X+Y*Y+Z*Z;
        }
        XYZF Uint(float Multiple=1.0) const
        {
            float Line=sqrt(X*X+Y*Y+Z*Z);
            if(Line!=0)
            {
                XYZF Tem;
                Tem.X=X/Line*Multiple;
                Tem.Y=Y/Line*Multiple;
                Tem.Z=Z/Line*Multiple;
                return Tem;
            }else{
                XYZF Tem(0.0,0.0,0.0);
                return Tem;
            }
        }
        XYZF(const XYZF& T)
        {
            X=T.X;
            Y=T.Y;
            Z=T.Z;
        }
        XYZF Change(int Mode,float Tem,int Mode2=0,float Tem2=1.0,int Mode3=0, float Tem3=1.0)
        {
            XYZF Te(*this);
            switch(Mode)
            {
                case 1:
                    Te.X*=Tem;
                    break;
                case 2:
                    Te.Y*=Tem;
                    break;
                case 3:
                    Te.Z*=Tem;
                    break;
            }
            switch(Mode2)
            {
                case 1:
                    Te.X*=Tem2;
                    break;
                case 2:
                    Te.Y*=Tem2;
                    break;
                case 3:
                    Te.Z*=Tem2;
                    break;
            }
            switch(Mode3)
            {
                case 1:
                    Te.X*=Tem3;
                    break;
                case 2:
                    Te.Y*=Tem3;
                    break;
                case 3:
                    Te.Z*=Tem3;
                    break;
            }
            return Te;
        }
        XYZF Change(int Mode=0,int Mode2=0,int Mode3=0)
        {
            XYZF Te(*this);
            switch(Mode)
            {
                case 1:
                    Te.X*=-1;
                    break;
                case 2:
                    Te.Y*=-1;
                    break;
                case 3:
                    Te.Z*=-1;
                    break;
            }
            switch(Mode2)
            {
                case 1:
                    Te.X*=-1;
                    break;
                case 2:
                    Te.Y*=-1;
                    break;
                case 3:
                    Te.Z*=-1;
                    break;
            }
            switch(Mode3)
            {
                case 1:
                    Te.X*=-1;
                    break;
                case 2:
                    Te.Y*=-1;
                    break;
                case 3:
                    Te.Z*=-1;
                    break;
            }
            return Te;
        }
        XYZF ToCoordinate(const XYZF& x,const XYZF& y,const XYZF& z)const//��ԭʼ����ϵ�еĵ������ת����Ŀ������ϵ�е����� 
        {
            XYZF Tem2((*this)*x,(*this)*y,(*this)*z);
            return Tem2;
        }
        XYZF FromCoordinate(const XYZF& x,const XYZF& y,const XYZF& z)const//��Ŀ������ϵ�еĵ������ת����ԭʼ����ϵ�е����� 
        {
            XYZF Tr=x+y+z;
            XYZF Tem(Tr.X*X,Tr.Y*Y,Tr.Z*Z);
            return Tem;
        }
        XYZF(float x=0.0,float y=0.0,float z=0.0):X(x),Y(y),Z(z)
        {
        }
        float operator* (const XYZF& Temp)const
        {
            return X*Temp.X+Y*Temp.Y+Z*Temp.Z;
        }
        XYZF operator* (const float t)const
        {
            XYZF tem(X*t,Y*t,Z*t);
            return tem;
        }
        XYZF operator+ (const XYZF& b)const
        {
            XYZF tem(X+b.X , Y+b.Y , Z+b.Z);
            return tem;
        }
        XYZF operator- (const XYZF& b)const
        {
            XYZF tem(X-b.X , Y-b.Y , Z-b.Z);
            return tem;
        }
        XYZF operator& (const XYZF& b)const 
        {
            XYZF tem(Y*b.Z-Z*b.Y,Z*b.X-X*b.Z,X*b.Y-Y*b.X);
            return tem;
        }
};
XYZF operator* (const float t,const XYZF& a)
{
    XYZF tem(a.X*t,a.Y*t,a.Z*t);
    return tem;
}
float operator* (const XYF& Tem,const XYF& Temp)
{
    return Tem.X*Temp.X+Tem.Y*Temp.Y;
}
XYF operator* (const XYF& a,const float t)
{
    XYF tem(a.X*t,a.Y*t);
    return tem;
}
XYF operator* (const float t,const XYF& a)
{
    XYF tem(a.X*t,a.Y*t);
    return tem;
}
XYF operator+ (const XYF& a,const XYF& b)
{
    XYF tem(a.X+b.X , a.Y+b.Y);
    return tem;
}
XYF operator- (const XYF& a,const XYF& b)
{
    XYF tem(a.X-b.X , a.Y-b.Y);
    return tem;
}
float Distance(XYF T1,XYF T2,XYF T3)
{
    XYF V1=T3-T2;
    XYF V2=T1-T2;
    float Te=V1*V2/V1.Long();
    V1.Uint(Te);
    V2=V2-V1;
    return V2.Long();
}
float Distance(XYZF& T1,XYZF& T2,XYZF& T3)
{
    XYZF V1=T3-T2;
    XYZF V2=T1-T2;
    float Te=V1*V2/V1.Long();
    V1.Uint(Te);
    V2=V2-V1;
    return V2.Long();
}
#endif
