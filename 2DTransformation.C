#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>

void draw_axis(){
line(0,240,640,240);
line(320,0,320,480);
}

void draw(int a[8]){
draw_axis();
line(320+a[0],240-a[1],320+a[2],240-a[3]);
line(320+a[2],240-a[3],320+a[4],240-a[5]);
line(320+a[4],240-a[5],320+a[6],240-a[7]);
line(320+a[6],240-a[7],320+a[0],240-a[1]);
}

void translate(int a[8],int tx,int ty){
int b[8],i;
for(i=0;i<4;i++){
	b[2*i]=a[2*i]+tx;
	b[2*i+1]=a[2*i+1]+ty;
	}
	cleardevice();
	draw(b);
}

void rotate(int a[8],float t){
int b[8],i;
t=t*3.14/180;
for(i=0;i<4;i++){
	b[2*i]=(int)(a[2*i]*cos(t)-a[2*i+1]*sin(t));
	b[2*i+1]=(int)(a[2*i]*sin(t)+a[2*i+1]*cos(t));
}
cleardevice();
draw(b);
}

void scale(int a[8],int sx,int sy){
int b[8],i;
for(i=0;i<4;i++){
	b[2*i]=(int)(a[2*i]*sx);
	b[2*i+1]=(int)(a[2*i+1]*sy);
	}
cleardevice();
draw(b);
}
void reflection(int a[8],int rch){
if(rch==1){
	scale(a,1,-1);}
else if(rch==2){
	scale(a,-1,1);}
else{
	scale(a,-1,-1);}
}
void shearing(int a[8],float lambda){
int b[8],i,choice;
printf("1.Shear along x-axis with lambda\n2.Shear along y-axis with lambda\n3.Shear along both axis with lambda\nEnter choice: ");
scanf("%d",&choice);
switch(choice){
	case 1:for(i=0;i<4;i++){
		b[2*i]=(a[2*i]+(a[2*i+1]*lambda));
		b[2*i+1]=a[2*i+1];
		}
	case 2:for(i=0;i<4;i++){
		b[2*i]=a[2*i];
		b[2*i+1]=(a[2*i+1]+(a[2*i]*lambda));
		}
	case 3:for(i=0;i<4;i++){
		b[2*i]=a[2*i]+(a[2*i+1]*lambda);
		b[2*i+1]=a[2*i+1]+(a[2*i]*lambda);
		}
	}
cleardevice();
draw(b);
}


void main(){
int gd=DETECT,gm,ch,a[]={0,0,50,0,50,50,0,50};
int tx,ty,sx,sy,rch,lambda;float t;
initgraph(&gd,&gm,"");
printf("1.Translation\n2.Rotation\n3.Scaling\n4.Reflection\n5.Shear");
printf("\nEnter choice: ");
scanf("%d",&ch);
switch(ch){
	case 1:cleardevice();
	       draw(a);
	       printf("Enter tx and ty: ");
	       scanf("%d %d",&tx,&ty);
	       translate(a,tx,ty);
	       break;
	case 2:cleardevice();
		draw(a);
		printf("Enter angle: ");
		scanf("%f",&t);
		rotate(a,t);
		break;

	case 3:cleardevice();
		draw(a);
		printf("Enter sx,sy: ");
		scanf("%d %d",&sx,&sy);
		scale(a,sx,sy);
		break;
	case 4:cleardevice();
		draw(a);
		printf("1.About x-axis\n2.About y-axis\n3.About origin\nEnter choice: ");
		scanf("%d",&rch);
		reflection(a,rch);
		break;
	case 5:cleardevice();
		draw(a);
		printf("Enter lambda(shear-factor): ");
		scanf("%d",&lambda);
		shearing(a,lambda);
		break;
	}
getch();
closegraph();
restorecrtmode();
}