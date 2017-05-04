#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>

void bresenhamLine(int x1,int y1,int x2,int y2){
int dx,dy,x,y,xinc,yinc,e;
dx=abs(x2-x1);
dy=abs(y2-y1);
if(x1<=x2)
	xinc=1;
else
	xinc=-1;
if(y1<=y2)
	yinc=1;
else
	yinc=-1;
x=x1;
y=y1;
putpixel(x,y,WHITE);
if(dx>=dy){
	e=(2*dy)-dx;
	while(x!=x2){
	if(e<0)
		e+=(2*dy);
	else
		{e+=2*(dy-dx);
		y+=yinc;}
	x+=xinc;
	putpixel(x,y,WHITE);
	}
}
else{
	e=(2*dx)-dy;
	while(y!=y2){
	if(e<0)
		e+=(2*dx);
	else
		{e+=2*(dx-dy);
		x+=xinc;}
	y+=yinc;
	putpixel(x,y,WHITE);
	}
}
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

void main(){
int gd=DETECT,gm;
int i,x=50,y=50,x1=50,y1=50,j;
initgraph(&gd,&gm,"");
for(i=0;i<9;i++){
	bresenhamLine(x,y,x+240,y);
	y+=30;    delay(100);
	}
for(i=0;i<9;i++){
	bresenhamLine(x1,y1,x1,y1+240);
	x1+=30;           delay(100);
	}
for(i=0;i<4;i++){
	for(j=0;j<4;j++){
	ffill(60+(i*60),60+(j*60),BLACK,WHITE); delay(100);
	ffill(90+(i*60),90+(j*60),BLACK,WHITE); delay(100);
       }
}
getch();
closegraph();
restorecrtmode();
}