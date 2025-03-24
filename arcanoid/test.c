#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 65
#define HEIGHT 25

char mas[HEIGHT][WIDTH + 1];

void init()
{
    // Заполняем первую строку символами '#'
    for (int i = 0; i < WIDTH; i++)
        mas[0][i] = '#';

    mas[0][WIDTH] = '\0'; // Завершаем строку

    strcpy(mas[1], mas[0]);
    for(int i=1; i<WIDTH-1; i++)
        mas[1][i] = ' ';

    // Копируем первую строку во все остальные
    for (int i = 2; i < HEIGHT; i++)
        strcpy(mas[i], mas[1]); // Используем strcpy вместо strncpy
}

void show()
{
    for (int i = 0; i < HEIGHT; i++)
        printf("%s\n", mas[i]); // Добавил перевод строки
}

int main()
{
    init();
    show();
    
    return 0;
}