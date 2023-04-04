#include <stdio.h>

int main()
{
    int i;
    int j;
    int A[6][6];
    int user_input, digit;
    int counter = 0; //Колко елемента сме написали в нашия масив C
    int c[100][3]; //Да кажем, че можем да въведем 100 елемента тук

    printf("Menu: \n");
    printf("1  Print task content \n");
    printf("2   Print program author \n");
    printf("3   Input values for array \n");
    printf("4   Output values for array \n");
    printf("5   Null elements from A, that are less then the average of B for the same row \n");
    printf("6   Print values moved to new array \n");
    printf("7   Exit program \n");


    while (1) {
        scanf("%d", &user_input);
        switch (user_input) {
        case 1:
            printf("Task content: Da se sustavi programa za obrabotka na masiva A[6,6] sustaveni ot realni chisla sus stoinosti v intervala[0;99.99].\n");
            break;
        case 2:
            printf(" Izgotveno ot Mert Sergeev Kyuchukov fac.no. 361222025 \n");
            break;
        case 3:
            for (i = 0; i < 6; i++) {
                for (j = 0; j < 6; j++) {
                    printf("Enter data for element of array A on position: [%d][%d]:", i, j);
                    scanf("%d", &A[i][j]);
                    if(A[i][j] > 99 || A[i][j] < 0){
                        printf("Value must be in range (0 - 99)");
                        exit(1);
                    }
                }
            }
            break;
        case 4:
            for (i = 0; i < 6; i++) {
                for (j = 0; j < 6; j++) {
                    printf("%d ", A[i][j]);
                }
                printf("\n");
            }
            break;
        case 5:
            for (i = 0; i < 6; i++) {
                for (j = 1; j < 5; j++) { //Пробваме от 1 до 5, защото нямаме с какво да сравним първия и последния елемент
                    if (A[i][j] == A[i][j - 1] && A[i][j] == A[i][j + 1]) {
                        digit = A[i][j];
                        c[counter][0] = digit; //Елемента
                        c[counter][1] = i;     //Реда
                        c[counter][2] = j;     //Позицията в реда
                        counter++; //Преброяваме колко елемента сме добавили досега
                    }
                }
            }
            printf("Array modified \n");
            break;
        case 6:
            for (i = 0; i < counter; i++) {
                printf("Element: [%d] ", c[i][0], "\n" );
                printf("Row: [%d] ", c[i][1], "\n");
                printf("Index: [%d] ", c[i][2], "\n");
                printf("\n");
            }
            break;
        case 7:
            exit(0);
            break;
        }
    }
}