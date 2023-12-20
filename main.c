 #include "get_next_line.h"

   
  #include <fcntl.h>
#include <stdio.h>


// You need to define the join_line function here

int main() {
    int fd = open("file5.txt", O_RDONLY);  // Replace "your_file.txt" with your actual file name

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Your test case
    char *line1 = get_next_line(fd);
    char *line2 = get_next_line(fd);
    char *line3 = get_next_line(fd);
    char *line4 = get_next_line(fd);
    char *line5 = get_next_line(fd);
    char *line6 = get_next_line(fd);
    char *line7 = get_next_line(fd);
    char *line8 = get_next_line(fd);
    char *line9 = get_next_line(fd);
    char *line10 = get_next_line(fd);

    // Process or print the lines as needed
    printf("line[1] = %s\n", line1);
    printf("line[2] = %s\n", line2);
    printf("line[3] = %s\n", line3);
    printf("line[4] = %s\n", line4);
    printf("line[5] = %s\n", line5);
    printf("line[6] = %s\n", line6);
    printf("line[7] = %s\n", line7);
    printf("line[8] = %s\n", line8);
    printf("line[9] = %s\n", line9);
    printf("line[10] = %s\n", line10);

    close(fd);  // Close the file descriptor

    // Free the allocated memory
    free(line1);
    free(line2);
    free(line3);
    free(line4);
    free(line5);
    free(line6);
    free(line7);
    free(line8);
    free(line9);
    free(line10);

    return 0;
}

// Implement your other functions (get_line_newline, get_line, read_line, join_line, etc.)





