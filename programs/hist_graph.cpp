#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include <fcntl.h>


int graph(int n,int y[]){
	
	int xmax=getmaxx(),ymid=getmaxy(),scale=0,i,sum;
	int mag;int inc;
	char ch[20];
	//graph
	
	setcolor(15);
	line(10,ymid+150,xmax-10,ymid+150);//X-axis
	outtextxy(xmax-15,ymid+165,"");
	//arrows
	line(10,ymid+150,20,ymid+140);
	line(10,ymid+150,20,ymid+160);
	//line(xmax-10,ymid+150,xmax-20,ymid+140);
	//line(xmax-10,ymid+150,xmax-20,ymid+160);
	
	
	
	sum=50;
	int temp=100;
	line(sum,ymid+200,sum,temp);//Y-axis
	outtextxy(sum+15,ymid-105,"");
	//arrows for Y-axis
	line(sum,temp,sum-10,temp+10);
	line(sum,temp,sum+10,temp+10);
	line(sum,ymid+200,sum-10,ymid+190);
	line(sum,ymid+200,sum+10,ymid+190);
	scale=10;inc=5;
	for(i=0;i<n;i++){
		mag=y[i]/10;
		line(sum+i*inc,ymid+150,sum+i*inc,ymid+150-mag*scale);
		//floodfill(sum+i*inc,ymid+150-mag*scale,15);
		circle(sum+i*inc,ymid+150-mag*scale,2);
		//line(sum-5+i*inc,ymid+150-mag*scale,sum+5+i*inc,ymid+150-mag*scale);
		if(i%25==0)
			sprintf(ch,"%d",i),outtextxy(sum-5+i*inc,ymid+160,ch),line(sum+i*inc,ymid+150,sum+i*inc,ymid+158);
		//sprintf(ch,"%d",mag);
        //outtextxy(sum + (i * inc) , ymid+125 - mag * scale, ch);
	}

	getch();
//	closegraph();
	return 1;
} 

int main() {
   	int i,gdriver = DETECT, gmode, errorcode;
    initgraph( &gdriver, & gmode, "C:\TURBOC\BGI");
	settextstyle(8,0,1);
	FILE *fptr,*ptr_g;
	int hist[256],new_gray_level[256];
	fptr=fopen("hist.txt","r");
	ptr_g=fopen("gray.txt","r");
	for(i=0;i<256;i++)
		fscanf(fptr,"%d",&hist[i]),fscanf(ptr_g,"%d ",&new_gray_level[i]);
	fclose(fptr);
	fclose(ptr_g);
	graph(256,hist);
	cleardevice();
	graph(256,new_gray_level);
   
    return 1;
}
