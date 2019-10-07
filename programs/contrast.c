#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "internal/stb_image.h"
#include "internal/stb_image_write.h"
#define max 1000 
#include <stdint.h>
#include<stdio.h>
int main(void) {
    int width, height, comp,k,i,j,x,y;
    int src[max][max];
    float des[max][max];
    unsigned bytePerPixel = 1;
    unsigned char* pixelOffset;
    unsigned char *data = stbi_load("../images/a.jpeg", &width, &height, &comp, 0);
    if (data) {
        printf("width = %d, height = %d, comp = %d (channels)\n", width, height, comp);
	for(i=0;i<width;i++){
		for(j=0;j<height;j++){
			pixelOffset = data + (i + height * j) * bytePerPixel;
			src[i][j]=pixelOffset[0];		
		}
	}
	int UT,LT;
        printf("Enter the upper threshold ");
	scanf("%d", &UT);
	printf("Enter the lower threshold ");
	scanf("%d", &LT);
	for(x=0;x<width;x++){
		for(y=0;y<height;y++){
			if(src[x][y]<=LT){
				des[x][y]=0.5*src[x][y];
			}
			else if(src[x][y]<=UT){
				des[x][y]=2*(src[x][y]-LT)+0.5*LT;
			}
			else{
				des[x][y]=0.5*(src[x][y]-UT)+0.5*LT+2*(UT-LT);
			}
		}
	}
	uint8_t* rgb_image = malloc(width*height*1);
		int counter=0;
	for(i=0;i<width;i++){
		for(j=0;j<height;j++){
			rgb_image[counter]=(int)(des[j][i]);		
			counter++;
		}
	}
		printf("Check the images folder for OutputContrast.png\n");
	stbi_write_png("../images/OutputContrast.png", width, height, 1, rgb_image, width*1);

    }
    return 0;
}
