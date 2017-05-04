#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
void midptellipse(float xc,float yc,float a,float b){
float p1,p2,x,y;
p1=(b*b)-(a*a*b)-(a*a/4);
x=0;y=b;
do{
	putpixel(xc+x,yc+y,WHITE);
	putpixel(xc+x,yc-y,WHITE);
	putpixel(xc-x,yc+y,WHITE);
	putpixel(xc-x,yc-y,WHITE);
	if(p1<0){
		
		p1+=(2*b*b*x)+(b*b);
	}
	else{
		
		y--;
		p1+=(2*b*b*x)-(2*a*a*y)+(b*b);
	}x++;
}while((2*b*b*x)<(2*a*a*y));

p2=(b*b*(x+0.5)*(x+0.5))+(a*a*(y-1)*(y-1))-(a*a*b*b);
do{
	putpixel(xc+x,yc+y,WHITE);
	putpixel(xc+x,yc-y,WHITE);
	putpixel(xc-x,yc+y,WHITE);
	putpixel(xc-x,yc-y,WHITE);
	if(p2>0){
		y--;
		p2=p2-(2*a*a*y)+(a*a);
	}
	else{
		x++;
		y--;
		p2=p2-(2*a*a*y)+(2*b*b*x)+(a*a);
	}
}while(y!=0);
}

void main(){
int gd=DETECT,gm;
float xc,yc,a,b;
initgraph(&gd,&gm,"");
printf("Mid-Point Ellipse Algorithm");
printf("\nEnter the center coordinates: ");
scanf("%f %f",&xc,&yc);
printf("\nEnter the radii: ");
scanf("%f %f",&a,&b);
midptellipse(xc,yc,a,b);
getch();
closegraph();
restorecrtmode();
}

