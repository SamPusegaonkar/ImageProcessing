#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "internal/stb_image.h"
#include "internal/stb_image_write.h"
#define max 1000 
#include <stdint.h>
#include<math.h>
#include<stdio.h>
int main(void) {
    int width, height, comp,k,i,j,x,y;
    int des[max][max],src[max][max];
    unsigned bytePerPixel = 1;
    unsigned char* pixelOffset;
    unsigned char *data = stbi_load("../images/a.jpeg", &width, &height, &comp, 0);
    int filter[9]={1,1,1,1,1,1,1,1,1};
    if (data) {
        printf("width = %d, height = %d, comp = %d (channels)\n", width, height, comp);
	for(i=0;i<width;i++){
		for(j=0;j<height;j++){
			pixelOffset = data + (i + height * j) * bytePerPixel;
			src[i][j]=pixelOffset[0];		
		}

	}
        //printf("\n");

	for(x=0;x<width;x++){
		for(y=0;y<height;y++){
			if (src[x][y]>50 && src[x][y]<150)
				des[x][y]=255;
			else
				des[x][y]=src[x][y];
		}
	}
	printf("OUTPUT\n");
	uint8_t* rgb_image = malloc(width*height*1);
		int counter=0;
	for(i=0;i<width;i++){
		for(j=0;j<height;j++){
			rgb_image[counter]=(des[j][i]);		
			counter++;
		}
	}
		printf("Check the images folder for grey_bg.png\n");
	stbi_write_png("../images/grey_bg.png", width, height, 1, rgb_image, width*1);

    }
    return 0;
}
