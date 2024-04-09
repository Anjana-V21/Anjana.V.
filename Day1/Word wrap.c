#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool searchWord(char grid[10][10], int rows, int cols, char *word, int row, int col, int dr, int dc) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != word[i]) {
            return false; 
        }
        row += dr; 
        col += dc;
    }
    return true; 
}


bool searchAllDirections(char grid[10][10], int rows, int cols, char *word, int row, int col) {
    
    int dirRow[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dirCol[] = {0, 0, -1, 1, -1, 1, -1, 1};

    for (int i = 0; i < 8; i++) {
        if (searchWord(grid, rows, cols, word, row, col, dirRow[i], dirCol[i])) {
            return true; 
        }
    }
    return false; 
}

bool findWord(char grid[10][10], int rows, int cols, char *word) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (searchAllDirections(grid, rows, cols, word, i, j)) {
                return true; 
            }
        }
    }
    return false; 
}

int main() {
    char grid[10][10];
    int rows, cols;
    char word[100];

    printf("Enter number of rows and columns (<=10): ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the grid:\n");
    for (int i = 0; i < rows; i++) {
        scanf("%s", grid[i]);
    }

    printf("Enter the word to search for: ");
    scanf("%s", word);

   if (findWord(grid, rows, cols, word)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
