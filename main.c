#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PRG_NAME "strcmp"

void exit_w_msg(char *msg, int exit_code) {
    printf("%s", msg);
    exit(exit_code);
}

char *usage_msg = (
        "usage: " PRG_NAME " [-s | -v] <\"original str\"> <\"str to test\">\n"
        " "PRG_NAME" conpares 2 strings char by char and returns the diference\n"
        " of the first char not present in the str to test\n"
        "\t-s --silent : returns the value of "PRG_NAME" instead of printing it\n"
        "\t              (echo $? will only print unsigned char)\n"
        "\t-v --visual : highlights the characters present/not present in\n"
        "\t              one string but not the other\n");

char *def_help_msg = "usage: "PRG_NAME" -h [-s | -v]\n";

char *silent_help_msg = (
        "usage: "PRG_NAME" -s <\"original str\"> <\"str to test\">\n"
        "\treturns the result of "PRG_NAME" as the programs return code\n"
        "\tkeep in mind that when using echo $? to see the return code\n"
        "\tis the result was supposed to be -1 echo will display 255\n");

char *visual_help_msg = (
        "usage: "PRG_NAME" -v <\"original str\"> <\"str to test\">\n"
        "\twill highlight in red mistyped characters and will\n"
        "\thighlight in blue missing or superfluous characters\n");

int main(int argc, char** argv) {
    if(argc < 3 || argc > 4) {
        exit_w_msg(usage_msg, 0);
    }

    if(strcmp("-h", argv[1]) == 0 || strcmp("--help", argv[1]) == 0) {
        if(strcmp("-s", argv[2]) == 0 || strcmp("--silent", argv[1]) == 0)
            exit_w_msg(silent_help_msg, 0);
        else if(strcmp("-v", argv[2]) == 0 || strcmp("--visual", argv[1]) == 0)
            exit_w_msg(visual_help_msg, 0);
        else exit_w_msg(def_help_msg, 0);
    }

    if(strcmp("-s", argv[1]) == 0 || strcmp("--silent", argv[1]) == 0) {
        return strcmp(argv[2], argv[3]);
    }

    /* blue: character missing, red: wrong character*/
    if(strcmp("-v", argv[1]) == 0 || strcmp("--visual", argv[1]) == 0) {
        char *s1 = argv[2], *s2 = argv[3];
        for(;;) {
            if(*s1 == *s2) putchar(*s2);
            else if(strlen(s1) > strlen(s2)) {
                printf("\033[0;34m%c\033[0m", *s1);
                s2--;
            }
            else if(strlen(s1) < strlen(s2)) {
                printf("\033[0;34m%c\033[0m", *s2);
                s1--;
            }
            else if(*s1 != *s2) {
                printf("\033[0;31m%c\033[0m", *s2);
            }

            
            if(*s1 != '\0')s1++;
            if(*s2 != '\0')s2++;
            if(*s1 == '\0' && *s2 == '\0') break;
        }
        putchar('\n');
        return 0;
    }

    printf("%d\n", strcmp(argv[1], argv[2]));

    return 0;
}
