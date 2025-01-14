#define N 9



#include<stdio.h>




/* draw borad */
void drawBoard(int table[N][N]){
   for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", table[i][j]);
        printf("\n");
    }
}

/* check for valid homes */

int is_valid(int table[N][N], int row, int cols, int num){
    

    for(int x=0; x<=8; x++)
        if (table[row][x] == num) return 0;

    for(int x=0; x<=8; x++)    
        if (table[x][cols] == num) return 0;




    int startRow = row - row%3 ;
    int startCols = cols - cols%3;
    for (int i= 0; i<3 ; i++)
        for (int j = 0; j<3; j++)
            if (table[i + startRow][j + startCols] == num)
                return 0;
    return 1;        

}
int solver(int table[N][N], int row, int cols){
    if (row == N -1 && cols == N)
        return 1; 

    if (cols == N){
        row++;
        cols = 0;
    }

    if (table[row][cols] > 0)
        return solver(table, row, cols + 1);

    for (int num = 1; num <= N; num++) {  
        if (is_valid(table, row, cols, num) == 1){
            table[row][cols] = num;  
            if (solver(table, row, cols + 1) == 1)
                return 1;
            table[row][cols] = 0;  
        }
    }
    return 0; 
}





/* fill the valid homes */
int main(){
        int table[N][N] = { 
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};


    if (solver(table, 0,0) == 1)
        drawBoard(table);
    else
        printf("wtf is this . . . ");

    return 0;
}