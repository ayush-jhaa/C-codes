#include "header.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage:- %s n\n", argv[0]);
        return 0;
    }


    int n = atoi(argv[1]);

    for (int i = 0; i < n; i++) {
        if (fork() == 0) {
            // child
            srand(getpid());
            int delay = rand() % 10;
            printf("in child %d with delay %d and pid %d\n", i, delay, getpid());
            sleep(delay);
            exit(i);
        }
    }

    // parent
    int r, s;
    printf("in parent\n");

    while ((r = wait(&s)) != -1) {
        printf("in parent child pid=%d and exit status %d\n", r, (s >> 8));
    }

    printf("done\n");
    return 0;
}
