
#ifndef _BRKS_INTF_CHANNEL_H_
#define _BRKS_INTF_CHANNEL_H_

#include "glo_def.h"
#include "brks_socket.h"

#include <unistd.h>

#define MAX_CHANNEL_DATA_LEN 1024

#define BRKS_CMD_OPEN_CHANNEL   1
#define BRKS_CMD_CLOSE_CHANNEL  2
#define BRKS_CMD_QUIT           3
#define BRKS_CMD_TERMINATE      4
#define BRKS_CMD_REOPEN         5
#define BRKS_CMD_SERVICE        6

typedef struct {
    u32              command;  /* ������ */
    pid_t            pid;      /* ���ͷ��Ľ���ID */
    u32              slot;     /* ��process�����е�index */
    brks_socket_t    fd;       /* ���ͷ�ͨ�ŵ�д����ļ���� */
    u32              len;      /* data��ĳ��� */
    char             data[MAX_CHANNEL_DATA_LEN];
} brks_channel_t;


#define CHANNEL_WITHOUT_SPECIAl_SIZE (sizeof(brks_channel_t) - MAX_CHANNEL_DATA_LEN - sizeof(uint32_t))


i32  brks_write_channel(brks_socket_t s, brks_channel_t *ch, size_t size);
i32  brks_read_channel(brks_socket_t s, brks_channel_t *ch, size_t size);
void brks_close_channel(brks_socket_t* fd);


#endif

