#include<stdio.h>  
#include<graphics.h>  


void flood(int x,int y,int fillColor, int defaultColor)  
{  
    //checking the prerequisite condition
    if(getpixel(x,y)==defaultColor)  
    {  
        delay(0.3);  
        putpixel(x,y,fillColor);  
        flood(x+1,y,fillColor,defaultColor);  
        flood(x-1,y,fillColor,defaultColor);  
        flood(x,y+1,fillColor,defaultColor);  
        flood(x,y-1,fillColor,defaultColor);  
    }  
}


void main()  
{   
    //declaration of variables  
    int gd=DETECT,gm;  
    int left, top, right, bottom;
    
    //taking user input
    printf("Enter the coordinates of rectangle :");
    scanf("%d%d%d%d",&left,&top,&right,&bottom);
    
    //initialisation of graphics
    initgraph(&gd,&gm,NULL);  
    
    //making of the polygon
    rectangle(left,top,right,bottom);  
    
    //filling function
    flood(left+5,top+5,10,0);  
    
    getch();
    
    //deallocation of memory
    closegraph();  
}  

  