//
// Created by Chehak Malhotra on 21/10/22.
//

#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* inputs[]){
    /*if(inputs[3]!=NULL){
        printf("Too many arguments\n");
    }*/


    if (inputs[1]==NULL){
        struct dirent *d;
        DIR *dh=opendir(".");

        while ((d = readdir(dh)) != NULL) {

            if (d->d_name[0] == '.')
                continue;
            printf("%s  ", d->d_name);
        }


    }

    else if(strcmp(inputs[1],"-a")==0){
        //if(strcmp(inputs[2],"/0")
        struct dirent *d;
        DIR *dh=opendir(".");
        while ((d = readdir(dh)) != NULL){

            printf("%s  ", d->d_name);
        }



    }
    else if(strcmp(inputs[1],"-1")==0){
        struct dirent *d;
        DIR *dh=opendir(".");
        while ((d = readdir(dh)) != NULL) {

            if (d->d_name[0] == '.')
                continue;
            printf("%s\n  ", d->d_name);
        }





    }

    else if(strcmp(inputs[1],"-l")==0){
        printf("Invalid, try -1 or -a\n");
    }


    else {
        struct dirent *d;
        DIR *dh=opendir(".");
        while ((d = readdir(dh)) != NULL) {
            if (d->d_name[0] == '.')
                continue;
            printf("%s  ", d->d_name);
        }
    }
    return 0;
}



