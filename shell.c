#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/wait.h>
#include <pthread.h>


void* usethread(void* f){
    char* func=(char*)f;
    system(func);
    return NULL;


}
char* currdir;

int main()

{
    int status=1;
    while(status) {
        printf("Chehak's shell>>>");

        currdir = (char *) malloc(sizeof(char) * 1000);
        getcwd(currdir, 1000);


        char input_args[50][50];
        for (int i = 0; i < 50; i++) {
            input_args[i][0] = '\0';
        }
        char string[999];
        fgets(string, 999, stdin);
        for(int i=0;i<999;i++){
            if(string[i]=='\n'){
                string[i]='\0';
                break;
            }
        }


        char *token = strtok(string, " ");
        strcpy(input_args[0], token);

        token = strtok(NULL, " ");
        int i = 1;


        while (token != NULL && i < 50) {


            strcpy(input_args[i], token);
            token = strtok(NULL, " ");
            i++;


        }


        if (strcmp(input_args[0], "echo") == 0) {


            if (strcmp(input_args[1], "--help") == 0) {
                printf("echo - Write arguments to the standard output.\n echo [-neE] [arg ...].\n Display the ARGs, separated by a single space character and followed by a newline, on the standard output.\n Options:-n \n do not append a newline");
            } else if (strcmp(input_args[1], "-n") == 0) {
                for (int j = 2; j < 50 && input_args[j][0] != '\0'; j++) {
                    printf("%s ", input_args[j]);
                }


            } else {
                for (int j = 1; j < 50 && input_args[j][0] != '\0'; j++) {
                    printf("%s ", input_args[j]);
                }
                printf("\n");


            }
        }

        if (strcmp(input_args[0], "cd") == 0) {


            if (strcmp(input_args[1], "..") == 0) {
                int x=chdir("..");
                if(x!=0){
                    perror("..");
                }
            }
            else if (strcmp(input_args[1], ".") == 0) {
                printf("Invalid input");
            }

            else if (strcmp(input_args[1], "~") == 0) {
                chdir(getenv("HOME"));
            } else if (strcmp(input_args[1], "/") == 0) {
                chdir("/");
            }
            else {
                int x=chdir(input_args[1]);
                if(x!=0){
                    perror(input_args[1]);
                }

            }

            printf("%s\n", getcwd(string, 999));
        }

        if (strcmp(input_args[0], "pwd") == 0) {
            if (strcmp(input_args[1], "-L") == 0 || strcmp(input_args[1], "-P") == 0) {
                printf("%s\n", getenv("PWD"));
            } else {
                printf("%s", getcwd(string, 999));
            }

        }

        if (strcmp(input_args[0], "&tls") == 0) {

            pthread_t pid;

            char *command = (char *) malloc((sizeof(char)) * 1000);
            strcat(command, currdir);
            strcat(command, "/");
            strcat(command, "ls");
            for (int j = 1; j < 50 && strcmp(input_args[j], "\0") != 0; j++) {
                strcat(command, " ");
                strcat(command, input_args[j]);
            }


            printf("%s", command);
            pthread_create(&pid, NULL, &usethread, command);
            pthread_join(pid, NULL);

        }

        if (strcmp(input_args[0], "ls") == 0) {
            if (fork() == 0) {
                execl("ls", input_args[0], input_args[1], NULL);


            } else {
                wait(NULL);
            }
        }
        if (strcmp(input_args[0], "&tmkdir") == 0) {

            pthread_t pid;

            char *command = (char *) malloc((sizeof(char)) * 1000);
            strcat(command, currdir);
            strcat(command, "/");
            strcat(command, "mkdir");
            for (int j = 1; j < 50 && strcmp(input_args[j], "\0") != 0; j++) {
                strcat(command, " ");
                strcat(command, input_args[j]);
            }


            printf("%s", command);
            pthread_create(&pid, NULL, &usethread, command);
            pthread_join(pid, NULL);

        }

        if (strcmp(input_args[0], "mkdir") == 0) {
            if (fork() == 0) {
                execl("mkdir", input_args[0], input_args[1], input_args[2], input_args[3], NULL);


            } else {
                wait(NULL);
            }


        }
        if (strcmp(input_args[0], "&tdate") == 0) {

            pthread_t pid;

            char *command = (char *) malloc((sizeof(char)) * 1000);
            strcat(command, currdir);
            strcat(command, "/");
            strcat(command, "date");
            for (int j = 1; j < 50 && strcmp(input_args[j], "\0") != 0; j++) {
                strcat(command, " ");
                strcat(command, input_args[j]);
            }


            printf("%s", command);
            pthread_create(&pid, NULL, &usethread, command);
            pthread_join(pid, NULL);

        }


        if (strcmp(input_args[0], "date") == 0) {
            //printf("loll");

            if (fork() == 0) {
                execl("date", input_args[0], input_args[1], NULL);


            } else {
                wait(NULL);
            }
        }

        if (strcmp(input_args[0], "&trm") == 0) {

            pthread_t pid;

            char *command = (char *) malloc((sizeof(char)) * 1000);
            strcat(command, currdir);
            strcat(command, "/");
            strcat(command, "rm");
            for (int j = 1; j < 50 && strcmp(input_args[j], "\0") != 0; j++) {
                strcat(command, " ");
                strcat(command, input_args[j]);
            }


            printf("%s", command);
            pthread_create(&pid, NULL, &usethread, command);
            pthread_join(pid, NULL);

        }


        if (strcmp(input_args[0], "rm") == 0) {
            if (fork() == 0) {
                execl("rm", input_args[0], input_args[1], input_args[2], NULL);


            } else {
                wait(NULL);
            }
        }

        if (strcmp(input_args[0], "&tcat") == 0) {

            pthread_t pid;

            char *command = (char *) malloc((sizeof(char)) * 1000);
            strcat(command, currdir);
            strcat(command, "/");
            strcat(command, "cat");
            for (int j = 1; j < 50 && strcmp(input_args[j], "\0") != 0; j++) {
                strcat(command, " ");
                strcat(command, input_args[j]);
            }


            printf("%s", command);
            pthread_create(&pid, NULL, &usethread, command);
            pthread_join(pid, NULL);

        }


        if (strcmp(input_args[0], "cat") == 0) {
            if (fork() == 0) {
                execl("cat", input_args[0], input_args[1], input_args[2], NULL);


            } else {
                wait(NULL);
            }
        }

        if (strcmp(input_args[0], "exit") == 0) {
            status = 0;
        }


    }

    return 0;
}
