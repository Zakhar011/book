#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
int main(int argc, char *argv [])
{
char *feeds[] = {"https://www.linux.org.ru/section-rss.jsp",
                "http://www.cnn.com/rss/celebs.xml",
    "http://www.rollingstone.com/rock.xml"};
int times = 3;
char *phrase = argv[1];
char var[255];
if (argc < 2) {
        printf("Использование: ./zad4 'слово для поиска'\n");
        return 1;
    }
for (int i = 0; i < times; i++) {
sprintf(var, "RSS_FEED=%s", feeds[i]);
char *vars [] = {var, NULL};

pid_t pid = fork();
    if (pid == -1)
    {
        fprintf(stderr, "Не могу клонировать процесс: %s\n", strerror(errno));
        return 1;
    }
if (!pid) 
{
if (execle("/usr/bin/python3", "/usr/bin/python3", "rssgossip.py", phrase, NULL, vars) == -1){
fprintf (stderr, "не могу запустить скрипт: %s \n", strerror(errno));
return 1;
}
}
}
sleep(5);
return 0;
}




