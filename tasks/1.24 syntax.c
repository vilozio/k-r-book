#include <stdio.h>

#define PROGRAM 0

#define COMMENT_BLOCK 100
#define SLASH         101
#define COMMENT       102
#define COMMENT_LINE  103
#define STAR          104

#define QUOTE_BLOCK  200
#define QUOTE_SINGLE 201
#define QUOTE_DOUBLE 202
#define LITERAL      203

#define BRACKETS_BLOCK 300
#define CURLY_BRACKETS 301
#define ROUND_BRACKETS 302

#define NO_BLOCK -1
#define BLOCKS_MAX_NUM 1000

int check_block(int block_num);
int check_safe_state();
int comments_block(int c, int line_n);
int quotes_block(int c, int line_n);
void brackets_block(int c);
void unmark_brackets(int i);

int blocks[BLOCKS_MAX_NUM];
int block_idx = 0;

int main()
{
    int c;
    int line_n = 0;
    blocks[block_idx] = PROGRAM;
    for (int i = block_idx + 1; i < BLOCKS_MAX_NUM; ++i) {
        blocks[i] = NO_BLOCK;
    }

    while ((c = getchar()) != EOF) {
        comments_block(c, line_n);
        quotes_block(c, line_n);
        brackets_block(c);
    }

    if (blocks[block_idx] != PROGRAM && blocks[block_idx] != COMMENT_LINE) {
        printf("Error, code %d", blocks[block_idx]);
    }
    return 0;
}

int check_block(int block_num)
{
    if (blocks[block_idx] >= 0 && blocks[block_idx] - block_num < 100 && blocks[block_idx] - block_num >= 0)
        return 1;
    return 0;
}

int check_safe_state()
{
    return (check_block(PROGRAM) == 1 || check_block(BRACKETS_BLOCK) == 1);
}

int comments_block(int c, int line_n)
{
    int block_start_line = -1;
    if (c == '/' && blocks[block_idx] == SLASH) {
        blocks[block_idx] = COMMENT_LINE;
    }
    if (c == '/' && check_safe_state()) { // PROGRAM
        blocks[++block_idx] = SLASH;
    }
    if (blocks[block_idx] == SLASH) {
        if (c == '*') {
            blocks[block_idx] = COMMENT;
            block_start_line = line_n;
        } else if (c != '/') {
            printf("Line %d: unexpected slash", line_n);
        }
    }
    if (blocks[block_idx] == COMMENT && c == '*') {
        blocks[block_idx] = STAR;
    }
    if (blocks[block_idx] == STAR && c == '/') {
        blocks[block_idx--] = NO_BLOCK; // PROGRAM
    }
    if (blocks[block_idx] == COMMENT_LINE && c == '\n') {
        blocks[block_idx--] = NO_BLOCK; // PROGRAM
    }
    return block_start_line;
}

int quotes_block(int c, int line_n)
{
    int block_start_line = -1;
    if (c == '\'') {
        if (check_safe_state()) {
            blocks[++block_idx] = QUOTE_SINGLE;
            block_start_line = line_n;
        } else if (blocks[block_idx] == QUOTE_SINGLE) {
            blocks[block_idx--] = NO_BLOCK;
        }
    }
    if (c == '"') {
        if (check_safe_state()) {
            blocks[++block_idx] = QUOTE_DOUBLE;
            block_start_line = line_n;
        } else if (blocks[block_idx] == QUOTE_DOUBLE) {
            blocks[block_idx--] = NO_BLOCK;
        }
    }
    if (blocks[block_idx] == LITERAL) {
        blocks[block_idx--] = NO_BLOCK;
    }
    if (c == '\\' && (blocks[block_idx] == QUOTE_SINGLE || blocks[block_idx] == QUOTE_DOUBLE)) {
        blocks[++block_idx] = LITERAL;
    }
    return block_start_line;
}

void brackets_block(int c)
{
    int i;
    if (c == '{' && check_safe_state()) {
        blocks[++block_idx] = CURLY_BRACKETS;
    }
    if (c == '}' && check_block(BRACKETS_BLOCK) == 1) {
        for (i = block_idx; i > 0; --i) {
            if (blocks[i] == CURLY_BRACKETS) {
                unmark_brackets(i);
                break;
            }
        }
    }
    if (c == '(' && check_safe_state()) {
        blocks[++block_idx] = ROUND_BRACKETS;
    }
    if (c == ')' && check_block(BRACKETS_BLOCK) == 1) {
        for (i = block_idx; i > 0; --i) {
            if (blocks[i] == ROUND_BRACKETS) {
                unmark_brackets(i);
                break;
            }
        }
    }
}

void unmark_brackets(int i)
{
    int j;
    for (j = i + 1; j <= block_idx; ++j) {
        blocks[j - 1] = blocks[j];
    }
    blocks[block_idx--] = NO_BLOCK;
}
