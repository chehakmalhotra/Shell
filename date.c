
#include <time.h>
#include <printf.h>
#include <string.h>


int main(int argc, char* argv[]) {
    //printf("hellooooo");
    time_t t;
    t = time(NULL);
    struct tm *timeid;
    #define BUF_LEN 256
    char buf[BUF_LEN] = {0};




     if(argv[1]==NULL){
        //printf("hello1");
        timeid = localtime(&t);
        printf("%s", asctime(timeid));




     }

     else if (strcmp(argv[1], "-u") == 0) {

        timeid = gmtime(&t);
        //printf("hellna");
        printf("%s", asctime(timeid));
        //printf("hellna");
    } else if (strcmp(argv[1], "-R") == 0) {
        timeid = localtime(&t);
        strftime(buf, BUF_LEN, "%a, %d %b %G %X ", timeid);
        puts(buf);


    }
     else if (strcmp(argv[1], "-r") == 0) {
         printf("Try -R instead of -r\n");


     }






     else  if (strcmp(argv[1], "") == 0)  {
       timeid = localtime(&t);
       printf("%s", asctime(timeid));
    }

     else{
         printf("Invalid arguments");
     }
     return 0;


}
