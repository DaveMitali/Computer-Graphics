#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

void midptcircle(float xc,float yc, float r,float ocolor){
float p,x,y;
p=(5/4)-r;
x=0;
y=r;
do{
	putpixel(xc+x,yc+y,ocolor);
	putpixel(xc+x,yc-y,ocolor);
	putpixel(xc-x,yc+y,ocolor);
	putpixel(xc-x,yc-y,ocolor);
	putpixel(xc+y,yc+x,ocolor);
	putpixel(xc+y,yc-x,ocolor);
	putpixel(xc-y,yc+x,ocolor);
	putpixel(xc-y,yc-x,ocolor);
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
void main(){
int gd=DETECT,gm;
int x1=50,y1=350,x2=250,y2=350,x3=450,y3=350;
int c1=220,d1=50,c2=500,d2=200;
double a,b,c,d,e,f,t;
initgraph(&gd,&gm,"");
for(t=0;t<=1;t+=0.0005){
	a=x1*pow(1-t,2)+c1*t*(1-t)+x2*pow(t,2);
	b=y1*pow(1-t,2)+d1*t*(1-t)+y2*pow(t,2);

	midptcircle(a,b,30,WHITE);
	cleardevice();
	}
for(t=0;t<=1;t+=0.0005){
	c=x2*pow(1-t,2)+c2*t*(1-t)+x3*pow(t,2);
	d=y2*pow(1-t,2)+d2*t*(1-t)+y3*pow(t,2);
	midptcircle(c,d,30,WHITE);
	cleardevice();
	}
getch();
closegraph();
restorecrtmode();
}
