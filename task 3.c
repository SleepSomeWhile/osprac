#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define MSG_LEN 100

int main() {
    int msqid;

    char pathname[] = "task 3.c";

    key_t key;

    int len, maxlen;

    struct clientmsgbuf {
        long mtype;
        struct {
            pid_t pid;
            char message[MSG_LEN];
        } info;
    } clientbuf;

    struct sermsgbuf {
        long mtype;
        struct {
            char message[MSG_LEN];
        } info;
    } serverbuf;

    if ((key = ftok(pathname, 0)) < 0) {
        printf("Key error\n");
        exit(-1);
    }

    if ((msqid = msgget(key, 0666 | IPC_CREAT)) < 0) {
        printf("Msg Error\n");
        exit(-1);
    }

    while (1) {
        maxlen = sizeof(clientbuf.info);
        if (len = msgrcv(msqid, (struct clientmsgbuf *) &clientbuf, maxlen, 1, 0) < 0) {
            printf("Queue Error\n");
            exit(-1);
        }

        printf("User %d - %s\n", clientbuf.info.pid, clientbuf.info.message);

        serverbuf.mtype = clientbuf.info.pid;

        strcpy(serverbuf.info.message, clientbuf.info.message);
        len = sizeof(serverbuf.info);

        if (msgsnd(msqid, (struct sermsgbuf *) &serverbuf, len, 0) < 0) {
            printf("Sending error\n");
            msgctl(msqid, IPC_RMID, (struct msqid_ds *) NULL);
            exit(-1);
        }
        printf("Sent response\n");
    }
    return 0;
}
