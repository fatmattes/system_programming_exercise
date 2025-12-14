#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if(argc < 2) return 1;
    
    int s = socket(AF_UNIX, SOCK_STREAM, 0);
    struct sockaddr_un a;
    
    memset(&a, 0, sizeof(a));
    a.sun_family = AF_UNIX;
    strcpy(a.sun_path, "/tmp/stock");
    
    connect(s, (struct sockaddr*)&a, sizeof(a));
    send(s, &argv[1][0], 1, 0);  
    
    if(argv[1][0] == '+') {
        int stock;
        recv(s, &stock, sizeof(stock), 0);  
        printf("%d\n", stock);
    }
    
    close(s);
    return 0;
}