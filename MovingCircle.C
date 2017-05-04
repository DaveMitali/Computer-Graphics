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
int i;
initgraph(&gd,&gm,"");
for(i=0;i<=400;i+=25){
midptcircle(50+i,240,50,WHITE);
delay(150);
midptcircle(50+i,240,50,BLACK);
}

getch();
closegraph();
restorecrtmode();
}