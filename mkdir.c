//
// Created by Chehak Malhotra on 24/10/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

int isDirectoryExists(const char *path)
{
    struct stat stats;

    stat(path, &stats);

    // Check for file existence
    if (S_ISDIR(stats.st_mode))
        return 1;

    return 0;
}

int main(int argc, char *argv[]){

    /*if (argv[2]=="/0") {
        int check;
        check = mkdir(argv[1], 0777);
        if (!check) {
            printf("Directory made\n");
        } else {
            printf("Directory not made\n");

        }
    }*/


    if (argv[1]==NULL) {
        printf("Please enter a directory name\n");
    }
    else if( strcmp(argv[1],"-V")==0){
        printf("Invalid");
    }





    else if ( strcmp(argv[1],"-v")==0){

        int check;

        if(isDirectoryExists(argv[2])==1){
            printf("Directory name exists");
            exit(1);
        }
         check = mkdir(argv[2], 0777);
        //printf("%d",check);
        if (!check) {
            printf("Directory made\n");
            printf("mkdir: created directory %s",argv[2]);
        } else {
            printf("Directory not made\n");
        }


    }
    else if(strcmp(argv[1],"-m")==0) {
        int check;
         if(isDirectoryExists(argv[2])==1){
             printf("Directory name exists");
             exit(1);
         }


        check = mkdir(argv[3], (mode_t) argv[2]);
        if (!check) {
            printf("Directory made\n");
        } else {
            printf("Directory not made\n");


        }
    }
    /*else if(argc==3 && argv[1][2]=='p') {
        int check;
        check = mkdir(argv[2], 0777);
        if (!check) {
            printf("Directory made\n");
        } else {
            printf("Directory not made\n");
        }
    }*/

    else{

        int check;
         if(isDirectoryExists(argv[1])==1){
             printf("Directory name exists");
             exit(1);
         }
        check = mkdir(argv[1], 0777);
        if (!check) {
            printf("Directory made\n");
        } else {
            printf("Directory not made\n");

        }



    }




    /*0400
    Allow read by owner.

    0200
    Allow write by owner.

    0100
    Allow execute (search in directory) by owner.

    0700
    Allow read, write, and execute (search) by owner.

    0040
    Allow read by group.

    0020
    Allow write by group.

    0010
    Allow execute (search in directory) by group.

    0070
    Allow read, write, and execute (search) by group.

    0004
    Allow read by others.

    0002
    Allow write by others.

    0001
    Allow execute (search in directory) by others.

    0007
    Allow read, write, and execute (search) by others.
*/
    return 0;
}

