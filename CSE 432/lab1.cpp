#include<graphics.h>
#include<conio.h>
int main()
{
    initwindow(300,300,"test");
    for(int i=0;i<300;i++)
    {
        for(int j=0;j<300;j++)
        {
            putpixel(i,j,5);
        }
    }
    for(int i=0;i<300;i++)
    {
        putpixel(i,150,15);
    }
    for(int i=0;i<300;i++)
    {
        putpixel(150,i,15);
    }
    getch();
    closegraph();
    return 0;
}
