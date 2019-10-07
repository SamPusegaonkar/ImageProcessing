#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "internal/stb_image.h"
#include "internal/stb_image_write.h"
#define max 1000 
#include <stdint.h>
int main() {
    int width, height, comp, src[max][max],des[max][max],k,i,j;
    unsigned bytePerPixel = 1;
    unsigned char* pixelOffset;
    unsigned char *data = stbi_load("../images/a.jpeg", &width, &height, &comp, 0);
    printf("h");
    if (data) {
        printf("width = %d, height = %d, comp = %d (channels)\n", width, height, comp);
	for(i=0;i<width;i++){  //Get Pixel data and calculate 255-data
		for(j=0;j<height;j++){
			pixelOffset = data + (i + height * j) * bytePerPixel;
			src[i][j]=255-pixelOffset[0];		
		}
		//printf("\n");
	}

	int counter=0;
	uint8_t* rgb_image = malloc(width*height*1);  //Convert 2D array to 1D
	for(i=0;i<width;i++){
		for(j=0;j<height;j++){
			rgb_image[counter]=src[j][i];		
			counter++;
		}
		//printf("\n");
	}
	printf("Check the images folder for OutputNegative.png\n");
	stbi_write_png("..//images/OutputNegative.png", width, height, 1, rgb_image, width*1);
	
    }
    return 0;
}
