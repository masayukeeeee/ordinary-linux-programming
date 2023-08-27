#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[]){
    if (argc < 3) {
        printf("Insufficient arguments");
        return 1;
    }

    // printf("%d", strcmp(argv[1], argv[2]));
    // printf("\n");
    
    char *result = strchr(argv[1], argv[2][0]);
    if (result) {
        printf("Character found at position: %ld\n", result - argv[1]);
    } else {
        printf("Character not found\n");
    }
    

    return 0;
}

