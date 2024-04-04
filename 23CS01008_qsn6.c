#include <stdio.h>

struct control_message
{
    int opcode,status_code;
};

union Packet
{
    struct control_message c_msg;
    char payload[100];
};

struct DataPacket
{
    int flag;
    union Packet p1;
};

int main()
{
    struct DataPacket d1[10];
    for (int i = 0; i < 10; i++)
    {
        printf("Option:\n1-Control Message\n2-Payload\n");
        scanf("%d", &d1[i].flag);
        switch(d1[i].flag)
        {
            case 1:
                printf("Enter the opcode :");
                scanf("%d", &d1[i].p1.c_msg.opcode);

                printf("Enter the statuscode :");
                scanf("%d", &d1[i].p1.c_msg.status_code);

                printf("opcode : %d\n", d1[i].p1.c_msg.opcode);
                printf("Status code : %d\n", d1[i].p1.c_msg.status_code);
                break;

            case 2:
                printf("Enter the payload :");
                
                scanf(" %s",d1[i].p1.payload);
                printf("Payload : %s",d1[i].p1.payload);
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}