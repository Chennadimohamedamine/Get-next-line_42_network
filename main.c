 #include "get_next_line.h"
int main() {
   
    int f = open("file2.txt", O_RDONLY);

    char *s  = get_next_line(f);
    char *s1  = get_next_line(f);
   // char *s3  = get_next_line(f);
   // printf("%s\n%s\n",s,s1);
    printf("%s\n%s\n",s,s1);
    return 0;
}



