#include <stdio.h>
int main()
{
    int p,c1,c2,c3,c4,c5,c6,min=0,max=0;
    float prum=0;
    
    printf("Zadej pocet cisel: ");
    scanf("%d",&p);
    
    if(p<0 || p>6){
        printf("Zadej pocet cisel: ");
        scanf("%d",&p);
    }
    
    if(p==1){
        printf("Zadej cislo: ");
        scanf("%d",&c1);
        min=c1;
        max=c1;
        prum=(float)c1;
    }
    
    if(p==2){
        printf("Zadej 2 cisla: ");
        scanf("%d%d",&c1,&c2);
        min=c1;
        if(min>c2)min=c2;
        max=c1;
        if(max<c2)max=c2;
        prum=(float)(c1+c2)/2;
    }
    
    if(p==3){
        printf("Zadej 3 cisla: ");
        scanf("%d%d%d",&c1,&c2,&c3);
        min=c1;
        if(min>c2)min=c2;
        if(min>c3)min=c3;
        max=c1;
        if(max<c2)max=c2;
        if(max<c3)max=c3;
        prum=(float)(c1+c2+c3)/3;
    }
    
    if(p==4){
        printf("Zadej 4 cisla: ");
        scanf("%d%d%d%d",&c1,&c2,&c3,&c4);
        min=c1;
        if(min>c2)min=c2;
        if(min>c3)min=c3;
        if(min>c4)min=c4;
        max=c1;
        if(max<c2)max=c2;
        if(max<c3)max=c3;
        if(max<c4)max=c4;
        prum=(float)(c1+c2+c3+c4)/4;
    }
    
    if(p==5){
        printf("Zadej 5 cisel: ");
        scanf("%d%d%d%d%d",&c1,&c2,&c3,&c4,&c5);
        min=c1;
        if(min>c2)min=c2;
        if(min>c3)min=c3;
        if(min>c4)min=c4;
        if(min>c5)min=c5;
        max=c1;
        if(max<c2)max=c2;
        if(max<c3)max=c3;
        if(max<c4)max=c4;
        if(max<c5)max=c5;
        prum=(float)(c1+c2+c3+c4+c5)/5;
    }
    
    if(p==6){
        printf("Zadej 6 cisel: ");
        scanf("%d%d%d%d%d%d",&c1,&c2,&c3,&c4,&c5,&c6);
        min=c1;
        if(min>c2)min=c2;
        if(min>c3)min=c3;
        if(min>c4)min=c4;
        if(min>c5)min=c5;
        if(min>c6)min=c6;
        max=c1;
        if(max<c2)max=c2;
        if(max<c3)max=c3;
        if(max<c4)max=c4;
        if(max<c5)max=c5;
        if(max<c6)max=c6;
        prum=(float)(c1+c2+c3+c4+c5+c6)/6;
    }
    
    printf("min: %d\nmax: %d\nprum: %.2f",min,max,prum);
    getchar();getchar();
}
