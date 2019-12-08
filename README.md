# ImageProcessing
Basic image processing programs in C

**The above code is written in C/C++ Language.**

**Description**: This repo consists of basic image processing programs.
A list of all the programs is given below.
- Negative of an image- negative.c 
- Thresholding -threshold.c
- Contrast Stretching - contrast.c
- 8 bit plane slicing - 8bit.c
- Slicing with background - grey_bg.c
- Slicing without background - grey_wo_bg.c
- Histogram equalization - hist.c & hist_graph.cpp
- Edge Detection - prewitt.c & sobel.c
- Low pass & high pass - smooth.c & sharpen.c
<br/>

  **Instructions**: 
  To run the programs, open terminal and type:

    1. gcc file_name.c -o file_name -lm
    2. ./file_name
  
For example:

    1. gcc 8bit.c -o 8bit -lm
    2. ./8bit

**Special Instructions for histogram program**

First run the hist.c file.<br>
A text file will be generated in the programs folder.<br>
Now run the hist_graph.cpp<br>
This is a c++ file. It needs the graphics.h and conio.h library.<br>

**Few tips**<br>
A few input images are already present in this repo.<br>
Although if you want to use your images, make sure they are greyscale images.<br>
You can check this by using the linux command 'identify' command.<br>
<br>
For example<br>
`identify input_image.jpeg`

Programs by:<br>
Sameer <br>
Piyush <br>
Aayush <br>
Nitesh <br>
Rohan <br>
