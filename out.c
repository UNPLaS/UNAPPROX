/************************************
*****Code generated by UNAPPROX*****
************************************/
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#define MAX_IMAGESIZE  8192
#define MAX_BRIGHTNESS  255 /* Maximum gray level */
#define GRAYLEVEL       256 /* No. of gray levels */
#define MAX_FILENAME    256 /* Filename length limit */
#define MAX_BUFFERSIZE  256

unsigned char image1[MAX_IMAGESIZE]
[MAX_IMAGESIZE]
; 
unsigned char image2[MAX_IMAGESIZE]
[MAX_IMAGESIZE]
; 
int x_size1, y_size1, x_size2, y_size2; 
void load_image_data(const char *file_name)
; 
void save_image_data()
; 
void load_image_data(const char *file_name)
{
char buffer[MAX_BUFFERSIZE]
; 
FILE*fp;
int max_gray; 
int x, y; 
fp=fopen(file_name,"rb");
if (NULL==fp)
{
printf("     The file doesn't exist!\n\n");
exit(1);
}
fgets(buffer,MAX_BUFFERSIZE,fp);
if (buffer[0]!='P'||buffer[1]!='5')
{
printf("     Mistaken file format, not P5!\n\n");
exit(1);
}
x_size1=0;
y_size1=0;
while (x_size1==0||y_size1==0)
{
fgets(buffer,MAX_BUFFERSIZE,fp);
if (buffer[0]!='#')
{
sscanf(buffer,"%d %d",&x_size1,&y_size1);
}
}
max_gray=0;
while (max_gray==0)
{
fgets(buffer,MAX_BUFFERSIZE,fp);
if (buffer[0]!='#')
{
sscanf(buffer,"%d",&max_gray);
}
}
if (x_size1>MAX_IMAGESIZE||y_size1>MAX_IMAGESIZE)
{
printf("     Image size exceeds %d x %d\n\n",MAX_IMAGESIZE,MAX_IMAGESIZE);
printf("     Please use smaller images!\n\n");
exit(1);
}
if (max_gray!=MAX_BRIGHTNESS)
{
printf("     Invalid value of maximum gray level!\n\n");
exit(1);
}
for (y=0;y<y_size1;y=y+3)  /* <----------------For-loop 0 perfored! */
{
for (x=0;x<x_size1;x++)
{
image1[y][x]=( unsigned char  )fgetc(fp);
}
}
fclose(fp);
}
void save_image_data()
{
char *file_name="out.pgm"; 
FILE*fp;
int x, y; 
fp=fopen(file_name,"wb");
fputs("P5\n",fp);
fputs("# Created by Image Processing\n",fp);
fprintf(fp,"%d %d\n",x_size2,y_size2);
fprintf(fp,"%d\n",MAX_BRIGHTNESS);
for (y=0;y<y_size2;y++)
{
for (x=0;x<x_size2;x++)
{
fputc(image2[y][x],fp);
}
}
fclose(fp);
printf("out.pgm ");
}
void sobel_filtering()
{
int weight[3]
[3]
={{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}}; 
double pixel_value; 
double min, max; 
int x, y, i, j; 
min=DBL_MAX;
max=-DBL_MAX;
for (y=1;y<y_size1-1;y++)
{
for (x=1;x<x_size1-1;x++)
{
pixel_value=0.0;
for (j=-1;j<=1;j++)
{
for (i=-1;i<=1;i++)
{
pixel_value+=weight[j+1][i+1]*image1[y+j][x+i];
}
}
if (pixel_value<min)
min=pixel_value;
if (pixel_value>max)
max=pixel_value;
}
}
if (( int  )(max-min)==0)
{
printf("Nothing exists!!!\n\n");
exit(1);
}
int xa; 
int ya; 
double pixel_value_app; 
x_size2=x_size1;
y_size2=y_size1;
for (ya=0;ya<y_size2;ya++)
{
for (xa=0;xa<x_size2;xa++)
{
image2[ya][xa]=0;
}
}
for (ya=1;ya<y_size1-1;ya++)
{
for (xa=1;xa<x_size1-1;xa++)
{
pixel_value_app=0.0;
for (j=-1;j<=1;j++)
{
for (i=-1;i<=1;i++)
{
pixel_value_app+=weight[j+1][i+1]*image1[ya+j][xa+i];
}
}
pixel_value_app=MAX_BRIGHTNESS*(pixel_value_app-min)/(max-min);
image2[ya][xa]=( unsigned char  )pixel_value_app;
}
}
}
int main(int argc, const char **argv)
{
load_image_data(argv[1]);
sobel_filtering();
save_image_data();
return 0;
}
