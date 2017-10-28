#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <dirent.h>

void dots(int x, int t)
{
    srand(time(0));
    for(; x > 0; x--)
    {
        Sleep(rand()%t+1);
        printf(".");
    }
}

int main()
{
    int f;
    char scan[1], install[1];
    
    srand(time(0));
    
    start:
    printf("Do you want to perform scan for availble updates now? (Y/n): ");
    gets(scan);
    
    if((strcmp(scan , "N") == 0)  || (strcmp(scan , "n") == 0))
    {
        printf("Press any key to exit . . . ");
        getch();
        return 0;
    }
    else if((strcmp(scan, "Y") != 0)  && (strcmp(scan , "y") != 0)) goto start;
    
    printf("\nInitialising, please wait.");
    dots(20, 1500);
    printf("\nConnecting to the server");
    dots(13, 500);
    printf("\nSecure connection to update server estabilished");
    printf("\nScanning");
    dots(3, 500);
    
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("c:\\windows\\system32\\")) != NULL)
    {
        f = 73;
        while ((ent = readdir (dir)) != NULL)
        {
            printf ("%s\n", ent->d_name);
            Sleep(1 + (rand() % 200));
            f--;
            if(f == 0)break;
        }
        f = 7;
        while ((ent = readdir (dir)) != NULL)
        {
            printf ("%s\n", ent->d_name);
            Sleep(1 + (rand() % 2000));
            f--;
            if(f == 0)break;
        }
        f = 51;
        while ((ent = readdir (dir)) != NULL)
        {
            printf ("%s\n", ent->d_name);
            Sleep(1 + (rand() % 500));
            f--;
            if(f == 0)break;
        }
        f = 107;
        while ((ent = readdir (dir)) != NULL)
        {
            printf ("%s\n", ent->d_name);
            Sleep(1 + (rand() % 150));
            f--;
            if(f == 0)break;
        }
        f = 4;
        while ((ent = readdir (dir)) != NULL)
        {
            printf ("%s\n", ent->d_name);
            Sleep(1 + (rand() % 5000));
            f--;
            if(f == 0)break;
        }
        f = 2500;
        while ((ent = readdir (dir)) != NULL)
        {
            printf ("%s\n", ent->d_name);
            Sleep(1 + (rand() % 10));
            f--;
            if(f == 0)break;
        }
        while ((ent = readdir (dir)) != NULL)
        {
            printf ("%s\n", ent->d_name);
            Sleep(1 + (rand() % 100));
        }
        closedir(dir);
    }
        
    printf("\n\nScan has been successfuly completed and found 73 non-installed updates.");
    
    install:
    printf("\nDo you want to install all updates now? (Y/n): ");
    gets(install);
    
    if((strcmp(install , "N") == 0)  || (strcmp(install , "n") == 0))
    {
        printf("Press any key to exit . . . ");
        getch();
        return 0;
    }
    else if((strcmp(install , "Y") != 0)  && (strcmp(install , "y") != 0)) goto install;
    
    printf("\n\nIn the scan were also found 11.84GB of porn, it will be deleted during updating process");
    dots(3, 500);
    Sleep(500);
    
    printf("\n\n\t\t\t!!! IMPORTANT WARNING !!!");
    printf("\n\nDon't turn off the computer during the update process.");
    printf("\n\nIf the update process fail, don't turn off the computer and search for help from the WinUpdater developers or your WinUpdater distributor.");
    printf("\n\nContinue only if you have just read and understood this warning!!!\n\n");
    system("pause");
    printf("\n\n\nStarting update process");
    dots(20, 500);
    
    printf("\n\nDownloading all remaining files. [0%%]");
    
    for(f = 1; f <= 100; f++)
    {
        Sleep(1 + (rand() % 5000));
        if(f > 10) printf("\b");
        printf("\b\b\b\b[%d%%]",f);
    }
    printf("\nAll files has been successfully downloaded.\n");
    
    printf("\nDeleting old files");
    dots(150, 3000);
    printf("\nAll files successfully deleted.\n");
    
    for(f = 1; f <= 69; f++)
    {
        printf("\nInstalling %d. update", f);
        dots(rand()%50+5, 1500);
    }
    
    printf("\n\nERROR: system update failed");
    printf("\n\nThere is dangerous virus in your PC: Trojan.Win32/Fisa:Agent7.UXZQ");
    printf("\nYour system has to be reinstalled, your data will be saved.");
    printf("\n\nPlease close all your programs and close explorer.exe process using task manager.");
    printf("\nCTRL + SHIFT + ESC > processes > explorer.exe > Stop task (WIN XP/Vista/7)");
    printf("\nCTRL + SHIFT + ESC > more details > details > explorer.exe > Stop task (WIN 8/8.1/10)");
    printf("\n\nPress ENTER to start backup and reinstallation process . . .");
    getchar();
    printf("\n\nCreating backup of your data");
    dots(1000, 2000);
    printf("\n\nPrepairing for system reinstallation");
    dots(30, 1000);
    getch();
    f = 5/0;
}
