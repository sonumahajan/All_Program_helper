#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int chess_board[20], count;
int display(int);
void queen_function(int, int);
int placeholder(int, int);
void queen_function(int row_value, int limit) {
      int column_value;
      for(column_value = 1; column_value <= limit; column_value++) {
            if(placeholder(row_value, column_value))  {
                  chess_board[row_value] = column_value;
                  if(row_value == limit) {
                        display(limit); }
                  else {
                        queen_function(row_value + 1, limit);
                  }  }  } }
int placeholder(int row_value, int column_value) {
      int count;
      for(count = 1; count <= row_value - 1; count++) {
            if(chess_board[count] == column_value) {
                  return 0; }
            else  {
                  if(abs(chess_board[count] - column_value) == abs(count - row_value) 
                        return 0;  }  }
      return 1; }
int display(int limit) {
      int m, n;
      printf("\n\n\tPossible Solution %d:\n\n", ++count);
      for(m = 1; m <= limit; m++) {
            printf("\t[%d]", m); }
      for(m = 1; m <= limit; m++) {
            printf("\n\n[%d]", m);
            for(n = 1; n <= limit; n++) {
                  if(chess_board[m] == n) {
                        printf("\tQ"); }
                  else {
                        printf("\t*"); }  }  } }

void main()
{
      int limit;
      printf("\nEnter Number of Queens:\t");
      scanf("%d", &limit);
      if(limit <= 3)
      {
            printf("\nNumber should be greater than 3 to form a Matrix\n");
      }
      else
      {
            queen_function(1, limit);
      }
      printf("\n\n");
}
