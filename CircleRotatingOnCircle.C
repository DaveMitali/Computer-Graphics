#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

void midptcircle(float xc,float yc,float r,float dcolor){
float p,x,y;
p=(5/4)-r;
x=0;
y=r;
do{
	putpixel(xc+x,yc+y,dcolor);
	putpixel(xc+x,yc-y,dcolor);
	putpixel(xc-x,yc+y,dcolor);
	putpixel(xc-x,yc-y,dcolor);
	putpixel(xc+y,yc+x,dcolor);
	putpixel(xc+y,yc-x,dcolor);
	putpixel(xc-y,yc+x,dcolor);
	putpixel(xc-y,yc-x,dcolor);
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
int theta;
initgraph(&gd,&gm,"");
midptcircle(315,220,75,YELLOW);
for(theta=0;theta<3600;theta++){
midptcircle(315,220,75,YELLOW);
midptcircle(315+((75+30)*cos(theta)),220+((75+30)*sin(theta)),30,WHITE);
delay(200);
midptcircle(315+((75+30)*cos(theta)),220+((75+30)*sin(theta)),30,BLACK);
}
getch();
closegraph();
restorecrtmode();
}