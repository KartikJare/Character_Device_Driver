#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

#define DEVICE_PATH "/dev/marvellous_driver"
#define BUFFER_SIZE 1024

int main()
{
    int fd = 0;
    int iRet = 0;
    char read_buffer[BUFFER_SIZE];
    char write_buffer[BUFFER_SIZE];

    printf("Opening the marvellous device....\n");

    // cat /dev/marvllous_driver
    fd = open(DEVICE_PATH,O_RDWR);
    if(fd < 0)
    {
        printf("Error : Unable to open Marvellous device\n");
        return -1;
    }

    printf("Marvellous Device opened successfully...\n");

    printf("Enter the data for Marvellous driver\n");
    fgets(write_buffer,BUFFER_SIZE,stdin);

    write_buffer[strcspn(write_buffer,"\n")] = 0;

    printf("Wrirring to the Marvellous Device\n");
    
    // echo "Jay Ganesh..." > /dev/marvllous_driver
    iRet = write(fd,write_buffer,strlen(write_buffer));

    if(iRet < 0)
    {
        printf("Error : Unable to write into Marvellous Device\n");
        close(fd);
        return -1;
    }

    printf("Data succesfully written into Marvellous driver\n");

    printf("Reading the data from Marvellous driver...\n");

    // cat /dev/marvellous_driver
    iRet = read(fd,read_buffer,BUFFER_SIZE);

    if(iRet < 0)
    {
        printf("Erorr : Unable to read from Marvellous Device\n");
        close(fd);
        return -1;
    }

    read_buffer[iRet] ='\0';

    printf("Data received from marvellous driver : %s\n",read_buffer);

    printf("Closing the Marvellous driver\n");

    close(fd);

    return 0;
}