#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
    double G=9.8;

 double f(double t,double a1,double a2,double av1,double av2){
     double resf=av1;
    return resf;
}
 double g(double t,double a1,double a2,double av1,double av2){
     double resg=av2;
    return resg;
}
 double p(double t,double a1,double a2,double av1,double av2,double L1,double L2,double m1,double m2){
     double num1=m2*L2*av2*av2*sin(a1-a2);
     double num2=(m1+m2)*G*sin(a1);
     double num3=m2*L1*av1*av1*sin(a1-a2)*cos(a1-a2);
     double num4=G*m2*cos(a1-a2)*sin(a2);
     double numm=L1*(m2+(m1*sin(a1-a2)*sin(a1-a2)));
     double resp=-(num1+num2+num3-num4)/numm;
    return resp;
}
 double q(double t,double a1,double a2,double av1,double av2,double L1,double L2,double m1,double m2){
     double num5=m2*L2*av2*av2*sin(a1-a2)*cos(a1-a2);
     double num6=(m1+m2)*((G*sin(a1)*cos(a1-a2))+(L1*av1*av1*sin(a1-a2))-(G*sin(a2)));
     double numn=L2*(m1+(m2*sin(a1-a2)*sin(a1-a2)));
     double resq=(num5+num6)/numn;
    return resq;
}

int main(){
    double A1,A2,Av1,Av2,h,time;
    double L1,L2,m1,m2;
    double t=0;
    printf("* * * * * DOUBLE PENDULUM * * * * *\n\n");
    printf("Enter Initial Angles :\n");
    printf("Angle 1 : ");
    scanf("%lf",&A1);
    printf("Angle 2 : ");
    scanf("%lf",&A2);
    printf("Enter Initial Anglular Velocities :\n");
    printf("Av 1 : ");
    scanf("%lf",&Av1);
    printf("Av 2 : ");
    scanf("%lf",&Av2);
    printf("Enter Final Time : ");
    scanf("%lf",&time);
  int x0=300,y0=200; //the origin coordinates
    L1=1.5;
    L2=1;
    m1=1.5;
    m2=1.5;
    h=0.001;
int gd,gm;
detectgraph(&gd,&gm);
initgraph(&gd,&gm,NULL);
setbkcolor(15);
cleardevice();
double x1,y1,x2,y2,x_1,y_1,x_2,y_2;
        while(t<=time){
        setcolor(0);
        setfillstyle(0,1);
        fillellipse(x0,y0,100*L1+100*L2+10*m2,100*L1+100*L2+10*m2);
            A1+=h*f(t,A1,A2,Av1,Av2);
            A2+=h*g(t,A1,A2,Av1,Av2);
            Av1+=h*p(t,A1,A2,Av1,Av2,L1,L2,m1,m2);
            Av2+=h*q(t,A1,A2,Av1,Av2,L1,L2,m1,m2);
                x_1=x0+100*L1*sin(A1);
                y_1=y0+100*L1*cos(A1);
                x_2=x_1+100*L2*sin(A2);
                y_2=y_1+100*L2*cos(A2);
     line(x0,y0,x_1,y_1);
     line(x_1,y_1,x_2,y_2);
     setfillstyle(1,1);
     fillellipse(x_1,y_1,5*m1,5*m1);
     fillellipse(x_2,y_2,5*m2,5*m2);
     setcolor(16);
     t+=h;
     Sleep(1);}
     getch();
     closegraph();
    return 0;
}

// Date : 28 . 4 . 1400
