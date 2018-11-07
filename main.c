/*
* Fun project to re-make a minimal python programming language
* Me on social networks: @amiremohamadi
* It feels good when you report a bug :)
*/

#include <getopt.h>
#include "headers/parser/parser.h"

int main(int argc, char **argv) {
    int next_option;

    // switches
    const char* const short_options = "h";
    const struct option long_options[] = {
        {"help", 0, NULL, 'h'},
        {NULL, 0, NULL, 0}
    };

    do {
        next_option = getopt_long(argc, argv, short_options, 
        long_options, NULL);

        switch(next_option)
        {
            case 'h':
                printf("rePython v1.0.0.0\nThis project is under heavy development!\n");
                return 0;
            
            case '?':
                printf("oh!use -h to get help or run repython without argumans\n");
                return -1;

            case -1:
                break;
            
            default:
                abort();
        }
    } while(next_option != -1);

    handler(); // call parser handler
    return 0;
}