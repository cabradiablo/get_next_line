#include "get_next_line.h"
/*int main(void)
{
    char **s = malloc(sizeof(char*) * 3);
    if (s == NULL)
        return 1;
    s[0] = "hola\nadios";
    char *line1 = ft_cutter(0, s);
    char *line = ft_updater(0, s);
    printf("%s\n", line1);
    printf("%s\n", line);
    free(line);
    free(line1);
    free(s);
    system("leaks a.out");
    return 0;
}*/
int main(void)
{
    char    *s;
    int     fd;
    
    fd = open("text.txt", O_RDONLY);
    if (fd < 0)
        return (-1);
    while ((s = get_next_line(fd)))
    {
        printf("POR CONSOLA-->%s", s);
        free(s);
    }
    printf("%s\n", get_next_line(fd));
    system("leaks a.out");
    close(fd);
    return (0);
}
/*int main(void)
{
    char **s = malloc(sizeof(char*) * 3);
    if (s == NULL)
        return 1;
    s[0] = "hola\nadios";
    char *line = ft_updater(0, s);
    printf("%s\n", line);
    free(line);
    free(s);
    system("leaks a.out");
    return 0;
}*/
/*int main(void)
{
    int     fd;
    
    fd = open("text.txt", O_RDONLY);
    
    char static **buff;
    buff = (char **)malloc(sizeof(char *) * (OPEN_MAX + 1));
    buff[fd] = malloc(10);
    buff[fd] = "mandarina";
    char    *_read = " adios";
    system("leaks a.out");
    return (0);
}*/