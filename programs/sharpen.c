#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "internal/stb_image.h"
#include "internal/stb_image_write.h"
#define MAX 500
int main(void) {
    int Width, Height, Channel;
    int i, j, x, y, fc=0;
    int processedImg[MAX][MAX];
    int inputImage[MAX][MAX];
    int filter[9] = {-1, -1, -1, -1, 8, -1, -1, -1, -1};
    unsigned bytePerPixel = 1;
    unsigned char* pixelOffset;
    unsigned char *data = stbi_load("../images/a.jpeg", &Width, &Height, &Channel, 0);

	for(i = 0; i < Width; i++)
		for(j = 0; j < Height; j++){
			pixelOffset = data + (i + Height * j) * bytePerPixel;
		    inputImage[i][j]=pixelOffset[0];
		}

    for(x = 0; x < Width; x++)
		for(y = 0; y < Height; y++){
            processedImg[x][y] = 0;
            fc = 0;
            for(i = -1; i <= 1;i++)
                for(j = -1;j <= 1; j++)
                    if( (x+i > 0) && (x+i < Width) && (y+j > 0) && (y+j < Height))
    			        processedImg[x][y] += filter[fc++] * inputImage[x+i][y+j];
		}
	uint8_t* OPImg = malloc(Width * Height * 1);
	int c = 0;
	for(i = 0; i < Width; i++)
		for(j = 0; j < Height; j++){
			OPImg[c]=(int)(processedImg[j][i]/9);
			c++;
		}
	printf("Check the images folder for OutputSharpen.png\n");
	stbi_write_png("../images/outputSharpen.png", Width, Height, 1, OPImg, Width*1);
    return 0;
}
