#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int pp2c[2], pc2p[2];
    char buf;

    pipe(pp2c);
    pipe(pc2p);

    int pid = fork();

    if (pid != 0) {
        write(pp2c[1], "1", 1);
        read(pc2p[0], &buf, 1);
        printf("%d: received pong\n", getpid());
    } else {
        read(pp2c[0], &buf, 1);
        printf("%d: received ping\n", getpid());
        write(pc2p[1], "1", 1);
    }
    exit(0);
    
}