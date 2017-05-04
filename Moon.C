#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>
void ffill(int,int,int,int);
void moon();
void main(){
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
moon();
getch();
closegraph();
restorecrtmode();
}
void moon(){
int x1=50,y1=50,x2=165,y2=225,x3=200,y3=50;
int m1=50,n1=50,m2=195,n2=320,m3=200,n3=50;
double a,b,t,c,d;
for(t=0;t<=1;t+=0.00005){
	a=x1*pow(1-t,2)+x2*t*(1-t)+x3*pow(t,2);
	b=y1*pow(1-t,2)+y2*t*(1-t)+y3*pow(t,2);
	c=m1*pow(1-t,2)+m2*t*(1-t)+m3*pow(t,2);
	d=n1*pow(1-t,2)+n2*t*(1-t)+n3*pow(t,2);

putpixel(a,b,WHITE);
putpixel(c,d,WHITE);
}
ffill(125,90,BLACK,WHITE);
//putpixel(125,90,GREEN);
}

void ffill(int x,int y,int ocolor,int fcolor){
int p;
p=getpixel(x,y);
if(p==ocolor){
	putpixel(x,y,fcolor);
	ffill(x+1,y,ocolor,fcolor);
	ffill(x-1,y,ocolor,fcolor);
	ffill(x,y+1,ocolor,fcolor);
	ffill(x,y-1,ocolor,fcolor);
	}
}


