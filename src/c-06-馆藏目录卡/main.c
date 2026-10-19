#include <stdio.h>
#include <string.h>

struct Card {
    const char *code;
    int year;
    int copies;
};

int main(void) {
    int count = 0;
    if (scanf("%d", &count) != 1) return 1;

    struct Card cards[1000];
    char codes[1000][9];
    int total_copies = 0;
    int longest_idx = 0;

    for (int i = 0; i < count; i++) {
        int year = 0;
        int copies = 0;
        if (scanf("%8s %d %d", codes[i], &year, &copies) != 3) return 1;
        cards[i].code = codes[i];
        cards[i].year = year;
        cards[i].copies = copies;
        
        total_copies += copies;
        if (strlen(codes[i]) > strlen(codes[longest_idx])) {
            longest_idx = i;
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%s %d %d %d\n", cards[i].code,
               (int)strlen(cards[i].code), cards[i].year,
               cards[i].copies);
    }

    printf("records=%d\n", count);
    printf("longest=%s\n", cards[longest_idx].code);
    printf("totalCopies=%d\n", total_copies);
    
    return 0;
}
