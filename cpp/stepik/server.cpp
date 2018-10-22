#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char * argv []){
    
    int MainSocket = socket(
            AF_INET,
            SOCK_STREAM,
            0);
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(12345);
    sa.sin_addr.s_addr = htonl(INADDR_ANY);// INADDR_ANY (0.0.0.0) говорит о том что ждем подключения  с любого айпишника, а так можно задать конкретный адрес и будет такой приватный сервак, точнее, индивидуальный
    
    bind(MainSocket,(struct sockaddr *)(&sa), sizeof(sa));
    
    listen(MainSocket, SOMAXCONN);
    
    /* Теперь когда все настроено можем считывать сообщения от клиентов */
    while(true) {
    
        int SlaveSocket = accept(MainSocket, 0, 0);
        int buf [5] = {0};

        recv(SlaveSocket, buf, 20, MSG_NOSIGNAL);// Приняли данные, тут скорее свего еще фишка в том что recv сам дописывает '\n' в конец строки. Иначе, как обьяснить тот факт что printf как-то печатает не выходя за пределы массива?(???????????)
        shutdown(SlaveSocket, SHUT_RDWR);       // Разорвали соединение с клиентом
        close(SlaveSocket);                     // Освободили сокет
        printf("%s\n",buf);          // Распечатали то что пришло
    }
   return 0;
    
}
