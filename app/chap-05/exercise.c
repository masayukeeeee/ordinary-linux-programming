#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// コマンドライン引数でファイル名が渡されなかったら標準入力を読むようにする
// バッファ中の \n を数え上げてファイルの行数を出力するコマンドを書け 

static void do_cat(const char *path);
static void die(const char *s);

int main(int argc, char *argv[]){
    int i;
    if (argc < 2) {
        fprintf(stderr, "%s: file name not given\n", argv[0]);
        exit(1);
    }
    for (i=1; i < argc; i++) {
        do_cat(argv[i]);
    }
    exit(0);
}

#define BUFFER_SIZE 2048

static void do_cat(const char *path){
    int fd;
    unsigned char buf[BUFFER_SIZE];
    int n;
    int count_line_breaks = 0;

    fd = open(path, O_RDONLY);
    if (fd < 0) die(path);
    for (;;) {
        n = read(fd, buf, sizeof buf);
        if (n < 0) die(path);
        if (n == 0) break;

        for (int i=0; i < strlen(buf); i++) {
            if (buf[i] == '\n') {
                count_line_breaks++;
            }
        }

        if (write(STDOUT_FILENO, buf, n) < 0) die(path);
    }
    printf("line break: %d\n", count_line_breaks);
    if (close(fd) < 0) die(path);
}

static void die(const char *s){
    perror(s);
    exit(1);
}