#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

void midptcircle(float xc,float yc,float r){
float x,y,p;
p=(5/4)-r;
x=0;
y=r;
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
		p+=(2*x)+3;}
	else{
		p+=2*(x-y)+5;
		y--;}
	x++;
}while(x<=y);
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
//	ffill(x+1,y+1,ocolor,fcolor);
//	ffill(x+1,y-1,ocolor,fcolor);
  //	ffill(x-1,y+1,ocolor,fcolor);
    //	ffill(x-1,y-1,ocolor,fcolor);
	}
}
void main(){
int gd=DETECT,gm;
initgraph(&gd,&gm,"");

midptcircle(320,240,10); delay(150);
midptcircle(320,240,20); delay(150);

ffill(320,240,BLACK,YELLOW);delay(150);
ffill(320,225,BLACK,BLUE);delay(150);

getch();
closegraph();
restorecrtmode();
}