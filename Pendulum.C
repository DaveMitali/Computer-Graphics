#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

void midptcircle(float xc,float yc, float r){
float p,x,y;
x=0;
y=r;
p=(5/4)-r;
do{
	putpixel(xc+x,yc+y,WHITE);
	putpixel(xc+x,yc-y,WHITE);
	putpixel(xc-x,yc+y,WHITE);
	putpixel(xc-x,yc-y,WHITE);
	putpixel(xc+y,yc+x,WHITE);
	putpixel(xc+y,yc-x,WHITE);
	putpixel(xc-y,yc+x,WHITE);
	putpixel(xc-y,yc-x,WHITE);
	if(p<=0){
		p+=(2*x)+3;
		}
	else{
		p+=2*(x-y)+5;
		y--;
		}
	x++;
}while(x<=y);
}

void ddaline(float x1,float y1,float x2,float y2){
float x,y,dx,dy,length,xinc,yinc,i=0;
dy=y2-y1;
dx=x2-x1;
if(abs(dx)>abs(dy))
	length=abs(dx);
else
	length=abs(dy);
xinc=(dx/length);
yinc=(dy/length);
x=x1;
y=y1;
putpixel(x,y,WHITE);
while(i<=length){
	x+=xinc;
	y+=yinc;
	putpixel(x,y,WHITE);
	i++;
	}
}
void main(){
int gd=DETECT,gm;
float a,b,t,x1=145,y1=275,x2=300,y2=400,x3=455,y3=275,i;
initgraph(&gd,&gm,"");
ddaline(150,50,450,50);
i=0;
while(i!=2){
for(t=0;t<=1;t+=0.0005){
	a=x1*pow(1-t,2)+2*x2*t*(1-t)+x3*pow(t,2);
	b=y1*pow(1-t,2)+2*y2*t*(1-t)+y3*pow(t,2);
	putpixel(a,b,BLACK);
	midptcircle(a,b,20);
	ddaline(300,50,a,b);
	cleardevice();
}
for(t=0;t<=1;t+=0.0005){
	a=x3*pow(1-t,2)+2*x2*t*(1-t)+x1*pow(t,2);
	b=y3*pow(1-t,2)+2*y2*t*(1-t)+y1*pow(t,2);
	putpixel(a,b,BLACK);
	midptcircle(a,b,20);
	ddaline(300,50,a,b);
	cleardevice();
}      i++;     }

getch();
closegraph();
restorecrtmode();
}