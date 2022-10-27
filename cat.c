#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    if (argv[1] == NULL) {
        printf("No arguments given\n");
        exit(1);
    }



    else if (strcmp(argv[1],"-E")==0) {
        FILE *fp;

        char *line = malloc(300);
        ssize_t read;
        size_t len = 0;



        fp = fopen(argv[2], "r");
        if (fp == NULL) {
            printf("No such file or directory\n");
            // Program exits if file pointer returns NULL.
            exit(1);
        }


            //printf("%ld",size);


            while ((read = getline(&line, &len, fp)) != -1) {
                printf("%s$", line);}





        fclose(fp);
    }
    else if (strcmp(argv[1],"-n")==0) {
        FILE *fp;

        char *line = malloc(300);
        ssize_t read;
        size_t len = 0;

        fp = fopen(argv[2], "r");
        if (fp == NULL) {
            printf("No such file or directory\n");
            // Program exits if file pointer returns NULL.
            exit(1);
        }
        int i=1;


        while ((read = getline(&line, &len, fp)) != -1) {

            printf("%d%s", i, line);
            i++;
        }


        fclose(fp);
    }
    else if(strcmp(argv[1],"-N")==0){
        printf("Invalid command entered, try -n\n");

    }
    else{
            FILE *fp;

            char *line = malloc(300);
            ssize_t read;
            size_t len = 0;

            fp = fopen(argv[1], "r");
        if (fp == NULL) {
            printf("No such file or directory\n");
            // Program exits if file pointer returns NULL.
            exit(1);

        }


            while ((read = getline(&line, &len, fp)) != -1) {
                printf("%s", line);
            }


            fclose(fp);
        }







    return 0;
}