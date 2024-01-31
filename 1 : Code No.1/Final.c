#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

long double sine(double x){ 
    double sum=x; 
    double up=x; 
    for (int i=1; i<500; i++){ 
        up=up*((-1.0)*x*x/((2*i+1)*(2*i))); 
        sum=sum+up;
    } 
    return sum;
}

long double cosine(double x){ 
    double sum=1; 
    double up=1; 
    for (int i=1; i<500; i++){ 
        up=up*((-1.0)*x*x/((2*i-1)*(2*i))); 
        sum=sum+up; 
    } 
    return sum;
}
    double G=9.8;

long double f(double t,double x,double y,double z,double w){
    long double resf=z;
    return resf;
}
long double g(double t,double x,double y,double z,double w){
    long double resg=w;
    return resg;
}
long double p(double t,double x,double y,double z,double w,double L1,double L2,double m1,double m2){
    long double num1=m2*L2*w*w*sine(x-y);
    long double num2=(m1+m2)*G*sine(x);
    long double num3=m2*L1*z*z*sine(x-y)*cosine(x-y);
    long double num4=G*m2*cosine(x-y)*sine(y);
    long double numm=L1*(m2+(m1*sine(x-y)*sine(x-y)));
    long double resp=-(num1+num2+num3-num4)/numm;
    return resp;
}
long double q(double t,double x,double y,double z,double w,double L1,double L2,double m1,double m2){
    long double num5=m2*L2*w*w*sine(x-y)*cosine(x-y);
    long double num6=(m1+m2)*((G*sine(x)*cosine(x-y))+(L1*z*z*sine(x-y))-(G*sine(y)));
    long double numn=L2*(m1+(m2*sine(x-y)*sine(x-y)));
    long double resq=(num5+num6)/numn;
    return resq;
}
 
int main(){
    double x0,z0,w0,y0,h,time;
    double L1,L2,m1,m2;
    long double t=0;
    printf("Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж\n");
    printf("Ж * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * Ж\n");
    printf("Ж * * * * * * * * * * * * * *                     * * * * * * * * * * * * * * Ж\n");
    printf("Ж * * * * * * * * * * * * * *   DOUBLE PENDULUM   * * * * * * * * * * * * * * Ж\n");
    printf("Ж * * * * * * * * * * * * * *                     * * * * * * * * * * * * * * Ж\n");
    printf("Ж * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * Ж\n");
    printf("Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж Ж\n\n");
    
    printf("Enter The Length of Rods (m):\n");
    printf("L1 = ");
    scanf("%lf",&L1);
    printf("L2 = ");
    scanf("%lf",&L2);
    printf("Enter The Masses (Kg):\n");
    printf("M1 = ");
    scanf("%lf",&m1);
    printf("M2 = ");
    scanf("%lf",&m2);
    printf("Enter Initial Angles (Radian):\n");
    printf("θ1 = ");
    scanf("%lf",&x0);
    printf("θ2 = ");
    scanf("%lf",&y0);
    printf("Enter Initial Angular Velocities (Radian/s):\n");
    printf("ω1 = ");
    scanf("%lf",&z0);
    printf("ω2 = ");
    scanf("%lf",&w0);
    printf("Enter The Final Time (s): ");
    scanf("%lf",&time);
    printf("Enter The Time Step Size [dt] : ");
    scanf("%lf",&h); printf("\n");
    printf("Differential Equation Solver Methods :\n");
    printf("[1] : Euler Method\t[2] : Heun Method\t[3] : Runge-Kutta 4th order\n\n");
    int method=0;
    printf("Enter The Number of Diff Eq Solver Method : ");
    scanf("%d",&method);
    printf("\n");
    
    long double X=x0;
    long double Y=y0;
    long double Z=z0;
    long double W=w0;
    if(method==1){
        printf("~ ~ ~ ~ ~ Using Euler Method ~ ~ ~ ~ ~ \n");
        printf("\n");
        printf("  Time   :        θ1         /         θ2        /         ω1         /         ω1       \n");
        printf("\n");
        while(t<=time){
            X+=h*f(t,X,Y,Z,W);
            Y+=h*g(t,X,Y,Z,W);
            Z+=h*p(t,X,Y,Z,W,L1,L2,m1,m2);
            W+=h*q(t,X,Y,Z,W,L1,L2,m1,m2);
            t+=h;
            
            printf("%Lf : %.15Lf / %.15Lf / %.15Lf / %.15Lf \n",t,X,Y,Z,W);
        }
    }
    if(method==2){
        printf("~ ~ ~ ~ ~ Using Heun Method ~ ~ ~ ~ ~ \n");
        printf("\n");
        printf("  Time   :        θ1         /         θ2        /         ω1         /         ω1       \n");
        printf("\n");
        while(t<=time){
            long double fn=f(t,X,Y,Z,W);
            long double gn=g(t,X,Y,Z,W);
            long double pn=p(t,X,Y,Z,W,L1,L2,m1,m2);
            long double qn=q(t,X,Y,Z,W,L1,L2,m1,m2);

            X+=0.5*h*(fn+f((t+h),(X+(h*fn)),(Y+(h*fn)),(Z+(h*fn)),(W+(h*fn))));
            Y+=0.5*h*(gn+g((t+h),(X+(h*gn)),(Y+(h*gn)),(Z+(h*gn)),(W+(h*gn))));
            Z+=0.5*h*(pn+p((t+h),(X+(h*pn)),(Y+(h*pn)),(Z+(h*pn)),(W+(h*pn)),L1,L2,m1,m2));
            W+=0.5*h*(qn+q((t+h),(X+(h*qn)),(Y+(h*qn)),(Z+(h*qn)),(W+(h*qn)),L1,L2,m1,m2));
            t+=h;

            printf("%Lf : %.15Lf / %.15Lf / %.15Lf / %.15Lf \n",t,X,Y,Z,W);
        }
    }
    if(method==3){
        printf("~ ~ ~ ~ ~ Using Runge-Kutta 4th Order Method ~ ~ ~ ~ ~ \n");
        printf("\n");
        printf("  Time   :        θ1         /         θ2        /         ω1         /         ω1       \n");
        printf("\n");
        while (t<=time){

            long double k1x=f(t,X,Y,Z,W);
            long double k2x=f((t+(0.5*h)),(X+(0.5*h*k1x)),(Y+(0.5*h*k1x)),(Z+(0.5*h*k1x)),(W+(0.5*h*k1x)));
            long double k3x=f((t+(0.5*h)),(X+(0.5*h*k2x)),(Y+(0.5*h*k2x)),(Z+(0.5*h*k2x)),(W+(0.5*h*k2x)));
            long double k4x=f((t+(h)),(X+(h*k3x)),(Y+(h*k3x)),(Z+(h*k3x)),(W+(h*k3x)));

            long double k1y=g(t,X,Y,Z,W);
            long double k2y=g((t+(0.5*h)),(X+(0.5*h*k1y)),(Y+(0.5*h*k1y)),(Z+(0.5*h*k1y)),(W+(0.5*h*k1y)));
            long double k3y=g((t+(0.5*h)),(X+(0.5*h*k2y)),(Y+(0.5*h*k2y)),(Z+(0.5*h*k2y)),(W+(0.5*h*k2y)));
            long double k4y=g((t+(h)),(X+(h*k3y)),(Y+(h*k3y)),(Z+(h*k3y)),(W+(h*k3y)));

            long double k1z=p(t,X,Y,Z,W,L1,L2,m1,m2);
            long double k2z=p((t+(0.5*h)),(X+(0.5*h*k1z)),Y+(0.5*h*k1z),(Z+(0.5*h*k1z)),(W+(0.5*h*k1z)),L1,L2,m1,m2);
            long double k3z=p((t+(0.5*h)),(X+(0.5*h*k2z)),(Y+(0.5*h*k2z)),(Z+(0.5*h*k2z)),(W+(0.5*h*k2z)),L1,L2,m1,m2);
            long double k4z=p((t+(h)),(X+(h*k3z)),(Y+(h*k3z)),(Z+(h*k3z)),(W+(h*k3z)),L1,L2,m1,m2);

            long double k1w=q(t,X,Y,Z,W,L1,L2,m1,m2);
            long double k2w=q((t+(0.5*h)),(X+(0.5*h*k1w)),(Y+(0.5*h*k1w)),(Z+(0.5*h*k1w)),(W+(0.5*h*k1w)),L1,L2,m1,m2);
            long double k3w=q((t+(0.5*h)),(X+(0.5*h*k2w)),(Y+(0.5*h*k2w)),(Z+(0.5*h*k2w)),(W+(0.5*h*k2w)),L1,L2,m1,m2);
            long double k4w=q((t+(h)),(X+(h*k3w)),(Y+(h*k3w)),(Z+(h*k3w)),(W+(h*k3w)),L1,L2,m1,m2);

            long double upx=(h/6)*(k1x+(2*k2x)+(2*k3x)+k4x);
            long double upy=(h/6)*(k1y+(2*k2y)+(2*k3y)+k4y);
            long double upz=(h/6)*(k1z+(2*k2z)+(2*k3z)+k4z);
            long double upw=(h/6)*(k1w+(2*k2w)+(2*k3w)+k4w);

            X=X+upx;
            Y=Y+upy;
            Z=Z+upz;
            W=W+upw;
            t=t+h;

            printf("%Lf : %.15Lf / %.15Lf / %.15Lf / %.15Lf \n",t,X,Y,Z,W);
    }}
    return 0; 
}