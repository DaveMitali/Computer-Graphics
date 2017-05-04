#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>

void main(){
	int gd=DETECT,gm;
	float t,x1=100,y1=250,x2=400,y2=200,x3=400,y3=300,c1=200,d1=75,c2=200,d2=400;
	float a,b,c,d;
	initgraph(&gd,&gm,"");
	for(t=0;t<=1;t+=0.000005){
		a=x1*pow(1-t,2)+2*c1*t*(1-t)+x3*pow(t,2);
		b=y1*pow(1-t,2)+2*d1*t*(1-t)+y3*pow(t,2);
		c=x1*pow(1-t,2)+2*c2*t*(1-t)+x2*pow(t,2);
		d=y1*pow(1-t,2)+2*d2*t*(1-t)+y2*pow(t,2);
		putpixel(a,b,YELLOW);
		putpixel(c,d,YELLOW);
	}
	setcolor(YELLOW);
	line(400,200,400,300);
	setcolor(BLUE);
	circle(150,225,10);
	setcolor(GREEN);
	circle(145,225,5);
	getch();
	closegraph();
	restorecrtmode();
}