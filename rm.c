//
// Created by Chehak Malhotra on 25/10/22.
//

#include <string.h>
#include <printf.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc, char *argv[]){






    if(strcmp(argv[1],"-i")==0){
        printf("remove %s ? (y/n)",argv[2]);
        char bool;
        scanf("%c",&bool);
        if(bool=='y'){

            DIR* dir=opendir(argv[2]);
            if(dir!=NULL){
                printf("Cant remove directory\n");
                exit(1);
            }
            int x=remove(argv[2]);
            if(x==0){
                printf("File removed\n");

            }
            else{
                perror(argv[2]);
            }
        }
        else{
            printf("File not removed\n");
        }
    }
    else if (strcmp(argv[1],"-v")==0){
        DIR* dir=opendir(argv[2]);
        if(dir!=NULL){
            printf("Cant remove directory\n");
            exit(1);
        }
        printf("%s\n",argv[2]);
        printf("File removed\n");
        int x=remove(argv[2]);
        if(x==0) {
            printf("File removed\n");
        }
        else{
            perror(argv[2]);
        }

    }
    else{
        DIR* dir=opendir(argv[1]);
        if(dir!=NULL){
            printf("Cant remove directory\n");
            exit(1);
        }

        int x=remove(argv[1]);

        if(x==0) {
            printf("File removed\n");
        }
        else{
            perror(argv[2]);
        }

    }
    return 0;
}