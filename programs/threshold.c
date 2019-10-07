#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define CHANNEL_NUM 1
#include <stdint.h>
#include "internal/stb_image.h"
#include "internal/stb_image_write.h"
#define max 1000 
 
int main() {
    int width, height, comp;

        unsigned bytePerPixel = 1;
    unsigned char* pixelOffset;
    int T;
    int src[max][max],des[max][max],k,i,j;
    printf("Enter Threshold Value: ");
    scanf("%d",&T);
    unsigned char *data = stbi_load("../images/a.jpeg", &width, &height, &comp, 0);
    if (data) {
        printf("width = %d, height = %d, comp = %d (channels)\n", width, height, comp);
	for(i=0;i<width;i++){  //Get Pixel data 
		for(j=0;j<height;j++){
			pixelOffset = data + (i + height * j) * bytePerPixel;
			src[i][j]=pixelOffset[0];		
		}
		
	}
	uint8_t* rgb_image;
    	rgb_image = malloc(width*height*CHANNEL_NUM);
	int counter=0;
	for(i=0;i<width;i++){
		for(j=0;j<height;j++){
			if (src[j][i] < T)
					src[j][i]=0;
			else
            			src[j][i]=255;

		}

	}
	for(i=0;i<width;i++){ 
		for(j=0;j<height;j++){

			rgb_image[counter]=src[j][i];		
			counter++;
		}
		
	}
        printf("\n");
	printf("Check the images folder for OutputThreshold.png\n");
    	stbi_write_png("../images/OutputThreshold.png", width, height, CHANNEL_NUM, rgb_image, width*CHANNEL_NUM);
    }
    return 0;
}
