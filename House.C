#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>

void bresenhamLine(int x1,int y1,int x2,int y2,int color){
int dx,dy,e,xinc,yinc,x,y;
dx=abs(x2-x1);
dy=abs(y2-y1);
if(x1<x2)
	xinc=1;
else
	xinc=-1;
if(y1<y2)
	yinc=1;
else
	yinc=-1;
x=x1;
y=y1;
putpixel(x,y,color);
if(dx>=dy){
	e=(2*dy)-dx;
	while(x!=x2){
		if(e<0){
			e+=(2*dy);}
		else{
			y+=yinc;
			e+=2*(dy-dx);}
	x+=xinc;
	putpixel(x,y,color);
}   }
if(dx<dy){
	e=(2*dx)-dy;
	while(y!=y2){
		if(e<0){
			e+=(2*dx);}
		else{
			x+=xinc;
			e+=2*(dx-dy);}
	y+=yinc;
	putpixel(x,y,color);
}  }
}

void main(){
	int gd=DETECT,gm;
	int wx1=50,wx2=590,wy1=50,wy2=430;
	initgraph(&gd,&gm,"");

	bresenhamLine(wx1,wy1,wx2,wy1,WHITE);     //outer box
	bresenhamLine(wx2,wy1,wx2,wy2,WHITE);     //outer box
	bresenhamLine(wx1,wy1,wx1,wy2,WHITE);     //outer box
	bresenhamLine(wx1,wy2,wx2,wy2,WHITE);     //outer box

	bresenhamLine(wx1+200,wy2-50,wx2-200,wy2-50,YELLOW);	//lower rectangle
	bresenhamLine(wx1+200,wy2-250,wx2-200,wy2-250,YELLOW);	//lower rectangle
	bresenhamLine(wx1+200,wy2-50,wx1+200,wy2-250,YELLOW); 	//lower rectangle
	bresenhamLine(wx2-200,wy2-50,wx2-200,wy2-250,YELLOW); 	//lower rectangle

	bresenhamLine(wx1+200,wy2-250,(wx1+wx2)/2,wy2-330,CYAN);	//upper triangle
	bresenhamLine(wx2-200,wy2-250,(wx1+wx2)/2,wy2-330,CYAN);     //upper triangle

	bresenhamLine(wx1+250,wy2-50,wx1+250,wy2-150,BLUE);	//door
	bresenhamLine(wx2-250,wy2-50,wx2-250,wy2-150,BLUE);  //door
	bresenhamLine(wx1+250,wy2-150,wx2-250,wy2-150,BLUE); //door

	circle(wx2-260,wy2-100,4);	//knob

	bresenhamLine(wx1+220,wy2-175,wx1+220,wy2-200,GREEN);	//window
	bresenhamLine(wx1+220,wy2-200,wx1+260,wy2-200,GREEN); //window
	bresenhamLine(wx1+260,wy2-200,wx1+260,wy2-175,GREEN); //window
	bresenhamLine(wx1+220,wy2-175,wx1+260,wy2-175,GREEN); //window
	bresenhamLine(wx2-220,wy2-175,wx2-220,wy2-200,GREEN);	//window
	bresenhamLine(wx2-220,wy2-200,wx2-260,wy2-200,GREEN); //window
	bresenhamLine(wx2-260,wy2-200,wx2-260,wy2-175,GREEN); //window
	bresenhamLine(wx2-220,wy2-175,wx2-260,wy2-175,GREEN); //window
	getch();
	closegraph();
	restorecrtmode();
	}