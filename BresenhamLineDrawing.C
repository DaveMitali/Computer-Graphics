#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>

void bresenhamLD(float x1,float y1,float x2,float y2){
float dx,dy,x,y,steps,e,i;
dx=abs(x2-x1);
dy=abs(y2-y1);
x=x1;
y=y1;
putpixel(x,y,WHITE);
if(dx>=dy){		//m<=1
	steps=abs(dx);
	e=(2*dy)-dx;
	for(i=0;i<steps;i++){
		if(e<0){
			x1+=(dx/abs(dx));
			e+=(2*dy);}
		else{
			x1+=(dx/abs(dx));
			y1+=(dy/abs(dy));
			e+=(2*(dy-dx));
			}
		putpixel(x,y,WHITE);}

}
else{			//m>1
	steps=abs(dy);
	e=(2*dx)-dy;
	for(i=0;i<steps;i++){
		if(e<0){
			y1+=(dy/abs(dy));
			e+=(2*dx);}
		else{
			x1+=(dx/abs(dx));
			y1+=(dy/abs(dy));
			e+=(2*(dx-dy));}

			putpixel(x,y,WHITE);}
	}
}

void main(){
float x1,y1,x2,y2,x,y;
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
cleardevice();
printf("Bresenham Line Drawing Algorithm");
printf("\nEnter the first coordinate: ");
scanf("%f %f",&x1,&y1);
printf("\nEnter the second coordinate: ");
scanf("%f %f",&x2,&y2);
x=x1;
y=y1;
putpixel(x,y,WHITE);
bresenhamLD(x1,y1,x2,y2);
getch();
}
