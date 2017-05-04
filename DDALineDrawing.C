#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<stdlib.h>

void ddaLD(int x1,int y1,int x2,int y2){
float dy,dx,length,x,y,xinc,yinc,i;
dy=y2-y1;
dx=x2-x1;
if(abs(dy)>=abs(dx)){
	length=abs(dy);}
else{
	length=abs(dx);}
xinc=dx/length;
yinc=dy/length;
x=x1;
y=y1;
putpixel((int)x,(int)y,WHITE);
i=0;
while(i<=length){
	x+=xinc;
	y+=yinc;
	putpixel((int)x,(int)y,WHITE);
	i++;
	}
}


void main(){
int x1,y1,x2,y2,x,y;
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
cleardevice();
printf("DDA Line Drawing Algorithm");
printf("\nEnter first coordinate: ");
scanf("%d %d",&x1,&y1);
printf("\nEnter second coordinate: ");
scanf("%d %d",&x2,&y2);
x=x1;
y=y1;
putpixel((int)x,(int)y,WHITE);
ddaLD(x1,y1,x2,y2);
getch();
}
