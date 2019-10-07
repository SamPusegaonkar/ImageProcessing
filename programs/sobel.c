#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "internal/stb_image.h"
#include "internal/stb_image_write.h"
#define max 600 
#include<math.h>
#include<stdio.h>
int main(void) {
    int width, height, comp,i,j,x,y;
    int desx[max][max],desy[max][max],src[max][max],desz[max][max];
    unsigned bytePerPixel = 1;
    unsigned char* pixelOffset;
    unsigned char *data = stbi_load("../images/a.jpeg", &width, &height, &comp, 0);
    int filter1[9]={-1,-2,-1,0,0,0,1,2,1};
    int filter2[9]={-1,0,1,-2,0,2,-1,0,1};
if(data){
	        printf("width = %d, height = %d, comp = %d (channels)\n", width, height, comp);
	for(i=0;i<width;i++){    //Get Pixel data and store in source 
		for(j=0;j<height;j++){
			pixelOffset = data + (i + height * j) * bytePerPixel;
			src[i][j]=pixelOffset[0];		
		}
	}

	for(x=1;x<width;x++){  //Convolute in x
		for(y=1;y<height;y++){
			desx[x][y]=filter1[0]*src[x-1][y-1]+filter1[1]*src[x-1][y]+filter1[2]*src[x-1][y+1]+filter1[3]*src[x][y-1]+filter1[4]*src[x][y]+filter1[5]*src[x][y+1]+filter1[6]*src[x+1][y-1]+filter1[7]*src[x+1][y]+filter1[8]*src[x+1][y+1];
		}
	}

	for(x=0;x<width;x++){ //Convolute in y
		for(y=0;y<height;y++){
			desy[x][y]=filter2[0]*src[x-1][y-1]+filter2[1]*src[x-1][y]+filter2[2]*src[x-1][y+1]+filter2[3]*src[x][y-1]+filter2[4]*src[x][y]+filter2[5]*src[x][y+1]+filter2[6]*src[x+1][y-1]+filter2[7]*src[x+1][y]+filter2[8]*src[x+1][y+1];
		}
	}
	for(x=0;x<width;x++){ //Adding both
		for(y=0;y<height;y++){
			desz[x][y]=desx[x][y]+desy[x][y];
		}
	}
	uint8_t* rgb_imagex = malloc(width*height*1);
	uint8_t* rgb_imagey = malloc(width*height*1);
	uint8_t* rgb_imagez = malloc(width*height*1);
	int counter=0;
	for(j=0;j<width;j++){
		for(i=0;i<height;i++){
			if(desx[i][j]<=0)
				rgb_imagex[counter]=0;
			else
				rgb_imagex[counter]=(desx[i][j]);		 //Add x and y 

                        if(desy[i][j]<=0)
				rgb_imagey[counter]=0;
			else
				rgb_imagey[counter]=(desy[i][j]);
			if(desz[i][j]<=0)
				rgb_imagez[counter]=0;
			else
				rgb_imagez[counter]=(desz[i][j]);
		
			counter++;
		}
	}
	printf("Check the images folder for sobel_x.png, sobel_y.png and Final_sobel.png\n");
	stbi_write_png("../images/sobel_x.png", width, height, 1, rgb_imagex, width*1);
	stbi_write_png("../images/sobel_y.png", width, height, 1, rgb_imagey, width*1);
	stbi_write_png("../images/Final_sobel.png", width, height, 1, rgb_imagez, width*1);

    }
    return 0;
}
