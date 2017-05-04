#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>

void midptcircle(int xc,int yc,int r){
float x,y,p;
x=0;
y=r;
p=(5/4)-r;
do{
	putpixel((int)xc+x,(int)yc+y,WHITE);
	putpixel((int)xc+x,(int)yc-y,WHITE);
	putpixel((int)xc-x,(int)yc+y,WHITE);
	putpixel((int)xc-x,(int)yc-y,WHITE);
	putpixel((int)xc+y,(int)yc+x,WHITE);
	putpixel((int)xc+y,(int)yc-x,WHITE);
	putpixel((int)xc-y,(int)yc+x,WHITE);
	putpixel((int)xc-y,(int)yc-x,WHITE);
	if(p<0){
		p+=(2*x)+3;}
	else{
		p+=(2*(x-y))+5;
		y--;}
	x++;
	}while(x<y);
}
void main(){
int xc,yc,r;
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
cleardevice();
printf("Mid-Point Circle Drawing Algorithm");
printf("\nEnter the center coordinates: ");
scanf("%d %d",&xc,&yc);
printf("\nEnter the radius: ");
scanf("%d",&r);
midptcircle(xc,yc,r);
getch();
closegraph();
restorecrtmode();
}