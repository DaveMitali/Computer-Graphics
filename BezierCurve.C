#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
void bezier();
void main(){
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
bezier();
getch();
closegraph();
restorecrtmode();
}
void bezier(){
int x1,x2,x3,x4,y1,y2,y3,y4;
double a,b,t;
printf("Enter the 4 control points: ");
scanf("%d %d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
for(t=0;t<=1;t+=0.0005){
	a=x1*pow(1-t,3)+3*x2*t*pow(1-t,2)+3*x3*pow(1-t,1)*pow(t,2)+x4*pow(t,3);
	b=y1*pow(1-t,3)+3*y2*t*pow(1-t,2)+3*y3*pow(1-t,1)*pow(t,2)+y4*pow(t,3);
putpixel(a,b,YELLOW);
}
putpixel(x1,y1,WHITE);
putpixel(x2,y2,WHITE);
putpixel(x3,y3,WHITE);
putpixel(x4,y4,WHITE);
}

