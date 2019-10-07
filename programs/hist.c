#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "internal/stb_image.h"
#include "internal/stb_image_write.h"
#define max 500 
#include<math.h>
#include<stdio.h>

int main(void) {
	
   FILE *fptr,*ptr_g;
    int width, height, comp,i,j,x,y,sum=0,total;
	int curr=0;
    int src[max][max];
    unsigned bytePerPixel = 1;
    unsigned char* pixelOffset;
    unsigned char *data = stbi_load("../images/a.jpeg", &width, &height, &comp, 0);
     int hist[256] = { 0 },pdf[256]={0}; 
int new_gray_level[256] = { 0 };
if(data){
	for(i=0;i<width;i++){    //Get Pixel data and store in source 
		for(j=0;j<height;j++){
			pixelOffset = data + (i + height * j) * bytePerPixel;
			src[i][j]=pixelOffset[0];		
		}
	}
	for(i=0;i<width;i++){    
		for(j=0;j<height;j++){	
			hist[src[i][j]]+=1;
		}
	}
	int sum=0;
	for(i=0;i<256;i++){
		sum+=hist[i];
		
	}

    //curr = 0.0; 
    int x;
    // calculating cumulative frequency and new gray levels 
    for (i = 0; i < 256; i++) { 
        // cumulative frequency 
        curr += hist[i]; 
  	
        // calculating new gray level after multiplying by 
        // maximum gray count which is 255 and dividing by 
        // total number of pixels 
       
        new_gray_level[i] = round((float)curr*255 / sum); 
        
    }  
    int final[256]={0},k=0;
	for(i=0;i<256;i++){
		x=hist[i];
		for(j=i+1;j<256;j++){
			if (new_gray_level[i]==new_gray_level[j])
				x+=hist[j];
			else
				break;
		}
		for(k=i;k<j;k++)
			final[new_gray_level[i]]=x;
	}
	uint8_t* rgb_image = malloc(width*height*1);
	for(i=0;i<256;i++)
		
	fptr=fopen("hist.txt","w");
	ptr_g=fopen("gray.txt","w");
	for(i=0;i<256;i++)
		fprintf(fptr,"%d ",hist[i]),fprintf(ptr_g,"%d ",final[i]);
	fclose(fptr);
	fclose(ptr_g);
	int counter=0;
	for(i=0;i<total;i++){
			rgb_image[counter]=final[i];
			counter++;
			
	}
	printf("Check the txt files hist.txt and gray.txt\n");
	printf("Now run the hist_graph.c to display the histogram \n");
	
	
    }
    //printf("h");
    return 0;
}
