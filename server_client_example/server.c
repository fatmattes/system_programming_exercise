#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main() {
    int s = socket(AF_UNIX, SOCK_STREAM, 0);
    struct sockaddr_un a;
    int stock = 100;
    char cmd;

    memset(&a, 0, sizeof(a));
    a.sun_family = AF_UNIX;
    strcpy(a.sun_path, "/tmp/stock");

    bind(s, (struct sockaddr*)&a, sizeof(a));
    listen(s, 5);

    while(1) {
        int c = accept(s, NULL, NULL);
        read(c, &cmd, 1);

        if(cmd == '+') stock++;
        if(cmd == '-') stock--;
        if(cmd == '=') ;
        write(c, &stock, sizeof(stock));

        printf("Stock: %d\n", stock);
        close(c);
    }

    close(s);
    return 0;
}
