#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    DIR *d;
    struct dirent *dir;

    d = opendir(".");
    FILE *fptr;
    fptr = fopen("dir.txt","w");
    if(fptr == NULL)
    {
        printf("Error!");   
        exit(1);             
    }
    if (d)
    {
        while ((dir = readdir(d)) != NULL)

        {
            fprintf(fptr,"%s\n",dir->d_name);
        }
        closedir(d);
    }
    fclose(fptr);
    puts("[1]done...");
    return(0);
}
