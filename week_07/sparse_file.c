#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define ONE_GIGABYTE 1000000000

int main(void)
{
    char *start = "start";
    char *end = "end";

    /* Assume everything succeeds */
    int fd = open("test_file.txt", O_RDWR | O_CREAT | O_TRUNC);

    write(fd, start, strlen(start) + 1);
    lseek(fd, ONE_GIGABYTE, SEEK_CUR);
    write(fd, end, strlen(end) + 1);

    return 0;
}
