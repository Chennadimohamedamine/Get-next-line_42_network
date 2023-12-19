 #include "get_next_line.h"
int main() {
   
    int f = open("file2.txt", O_RDONLY);

    char *s  = get_next_line(f);
    char *s1  = get_next_line(f);
    char *s2  = get_next_line(f);
    //char *s3  = get_next_line(f);
    //char *s4  = get_next_line(f);
  // char *s6  = get_next_line(f);
   // char *s3  = get_next_line(f);
   // printf("%s\n%s\n",s,s1);
    printf("%s\n%s\n%s\n",s,s1,s2);
    return 0;
}



