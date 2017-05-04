#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>

void ffill1(int x,int y,int ocolor,int fcolor){
int p=getpixel(x,y);
if(p==ocolor){
	putpixel(x,y,fcolor);
	ffill1(x+1,y,ocolor,fcolor);
	ffill1(x-1,y,ocolor,fcolor);
	ffill1(x,y+1,ocolor,fcolor);
	ffill1(x,y-1,ocolor,fcolor);
	}
}

void ffill2(int x, int y,int ocolor,int fcolor){
int p=getpixel(x,y);
if(p==ocolor){
	putpixel(x,y,fcolor);
	ffill2(x+1,y,ocolor,fcolor);
	ffill2(x-1,y,ocolor,fcolor);
	ffill2(x,y+1,ocolor,fcolor);
	ffill2(x,y-1,ocolor,fcolor);
	ffill2(x+1,y+1,ocolor,fcolor);
	ffill2(x-1,y-1,ocolor,fcolor);
	ffill2(x-1,y+1,ocolor,fcolor);
	ffill2(x+1,y-1,ocolor,fcolor);
	}
}

void main(){
int gd=DETECT,gm;
int a[]={50,65,25,115,50,90,75,115,50,65};
int ch;
initgraph(&gd,&gm,"");
cleardevice();
printf("Boundary Fill Algorithm");
printf("\n1. Concave Polygon \n2.Convex Polygon \nEnter choice: ");
scanf("%d",&ch);
switch(ch){
	case 1: rectangle(80,80,110,110);
		ffill2(90,90,BLACK,3);
		break;
	case 2: drawpoly(5,a);
		ffill1(50,75,BLACK,3);
		break;
	}
getch();
closegraph();
restorecrtmode();
}


