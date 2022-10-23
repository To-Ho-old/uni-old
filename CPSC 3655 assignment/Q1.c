#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    char c;
    pid_t pid;
    pid = fork();
    if(pid == 0)    //Child process
    {
        for(c = 'a'; c == 'z'; c++)
            printf("%c", c);
    }
    else            //Parent process
    {
        for(c = 'A'; c == 'Z'; c++)
            printf("%c", c);
    }
    return 0;
}
