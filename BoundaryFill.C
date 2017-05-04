#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>

void bfill1(int x,int y,int ocolor,int fcolor){
int p=getpixel(x,y);
if(p!=ocolor && p!=fcolor){
	putpixel(x,y,fcolor);
	bfill1(x+1,y,ocolor,fcolor);
	bfill1(x-1,y,ocolor,fcolor);
	bfill1(x,y+1,ocolor,fcolor);
	bfill1(x,y-1,ocolor,fcolor);
	}
}

void bfill2(int x, int y,int ocolor,int fcolor){
int p=getpixel(x,y);
if(p!=ocolor && p!=fcolor){
	putpixel(x,y,fcolor);
	bfill2(x+1,y,ocolor,fcolor);
	bfill2(x-1,y,ocolor,fcolor);
	bfill2(x,y+1,ocolor,fcolor);
	bfill2(x,y-1,ocolor,fcolor);
	bfill2(x+1,y+1,ocolor,fcolor);
	bfill2(x-1,y-1,ocolor,fcolor);
	bfill2(x-1,y+1,ocolor,fcolor);
	bfill2(x+1,y-1,ocolor,fcolor);
	}
}

void main(){
int a[]={50,65,25,115,50,90,75,115,50,65};
int ch;
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
cleardevice();
printf("Boundary Fill Algorithm");
printf("\n1. Concave Polygon \n2.Convex Polygon \nEnter choice: ");
scanf("%d",&ch);
switch(ch){
	case 1: rectangle(80,80,110,110);
		bfill1(90,90,WHITE,3);
		break;
	case 2: drawpoly(5,a);
		printf("\n\n\n\n\n\n\nBoundary Fill doesn't work with a Convex Polygon.");
		bfill2(50,75,WHITE,3);
		break;
	}
getch();
closegraph();
restorecrtmode();
}


