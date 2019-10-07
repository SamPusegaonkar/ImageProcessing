#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define CHANNEL_NUM 3
#include <stdint.h>
#include<stdlib.h>
#include<string.h>
#include "internal/stb_image.h"
#include "internal/stb_image_write.h"
#define max 600 
const size_t NUM_PIXELS_TO_PRINT = 10U;
 
int main() {
    int width, height, comp,bits=8,x,y;
    size_t i,j;
    char buffer[100]={'0'};
    int des[max][max],src[max][max];
    unsigned bytePerPixel = 1;
    unsigned char* pixelOffset;
    unsigned char *data = stbi_load("../images/a.jpeg", &width, &height, &comp, 0);
    if (data) {
	        printf("width = %d, height = %d, comp = %d (channels)\n", width, height, comp);
	uint8_t* rgb_image1={0};
	uint8_t* rgb_image2={0};
	uint8_t* rgb_image3={0};
	int value,k;
    rgb_image1 = malloc(width*height*CHANNEL_NUM);
    rgb_image2 = malloc(width*height*CHANNEL_NUM);
    rgb_image3 = malloc(width*height*CHANNEL_NUM);
	int counter=0,length;
	int temp, t1,t2;
	
	for(i=0;i<width;i++){    //Get Pixel data and store in source 
		for(j=0;j<height;j++){
			pixelOffset = data + (i + height * j) * bytePerPixel;
			src[i][j]=pixelOffset[0];
			//printf("%d ",src[i][j]);		
		}
	}
	
	for(x=0;x<width;x++){ //Convolute in y
		for(y=0;y<height;y++){
			value=src[y][x];
			if (value>=0){
			temp=value%2;
			t1=(value/8)%2;
			t2=(value/128)%2;
            		if (temp==1)
            			rgb_image1[counter]=255;
			if (t1==1)
            			rgb_image2[counter]=255;
            		if (t2==1)
            			rgb_image3[counter]=255;
			++counter;
           
        		}
    
		}
	}	
	printf("Check the images folder for 8BIT_SLICE_LOW.png, 8BIT_SLICE_MID.png and 8BIT_SLICE_HIGH.png\n");
    	stbi_write_png("../images/8BIT_SLICE_LOW.png", width, height, 1, rgb_image1, width);
    	stbi_write_png("../images/8BIT_SLICE_MID.png", width, height, 1, rgb_image2, width);
    	stbi_write_png("../images/8BIT_SLICE_HIGH.png", width, height, 1, rgb_image3, width);
    }
    return 0;
}
