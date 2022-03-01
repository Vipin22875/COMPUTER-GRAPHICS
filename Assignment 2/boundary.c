#include <stdio.h>
#include <graphics.h>

void boundary(int,int,int,int);
   
//driver code
int main()
{
    //declaration of variables
    int gd = DETECT, gm;
    int x, y, radius;
   
    //taking input for the position of circle
    printf("\n\n\tEnter the coordinates of center :");
    scanf("%d%d",&x,&y);
    printf("\n\n\tEnter the radius of circle :");
    scanf("%d",&radius);
    
    //initialzing the graphic system
    initgraph(&gd, &gm,NULL);
    
    // circle function
    circle(x, y, radius);
   
    //function calling for the filling
    boundary(x, y, 6, 15);
   
    delay(5000);
   
    //needs user to press any key to end the program
    getch();

    //this function closes graphics mode and deallocates the memory
    closegraph();
   
    return 0;
}


void boundary(int x, int y, int fill_color,int boundary_color)
{   
    //introduced delay to make the filling clear
    delay(0.2);

    //checking the prerequisite conditions
    if(getpixel(x, y) != boundary_color &&
       getpixel(x, y) != fill_color)
    {
        //function uses 4 connected pixels
        putpixel(x, y, fill_color);
        boundary(x + 1, y, fill_color, boundary_color);
        boundary(x, y + 1, fill_color, boundary_color);
        boundary(x - 1, y, fill_color, boundary_color);
        boundary(x, y - 1, fill_color, boundary_color);
    }
}