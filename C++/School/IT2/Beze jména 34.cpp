#include <stdio.h>
#include <windows.h>

char *tohex(const int COLOR)
{
    char hex[3];
    
    hex[1] = COLOR % 16;
    hex[0] = (COLOR / 16) % 16;
    hex[2] = '\0';
    
    if(hex[0] >= 10)
    {
        hex[0] += 'A' - 10;
    }
    else
    {
        hex[0] += '0';
    }
    
    if(hex[1] >= 10)
    {
        hex[1] += 'A' - 10;
    }
    else
    {
        hex[1] += '0';
    }
    
    return strdup(hex);
}

int main()
{
    int rgb[3];
    
    for(int i = 0; i < 3; i++)
    {
        do
        {
            printf(i == 0 ? "RED: " : (i == 1 ? "GREEN: " : "BLUE: "));
            scanf("%d", &rgb[i]);
            getchar();
        } while(rgb[i] < 0 || rgb[i] > 255);
    }
    
    char *r, *g, *b;
    
    r = tohex(rgb[0]);
    g = tohex(rgb[1]);
    b = tohex(rgb[2]);
    
    printf("\nrgb(%d, %d, %d) = #%s%s%s", rgb[0], rgb[1], rgb[2], r, g, b);
    
    printf("\n");
    system("pause");
    return 0;
}
