//
//  hanoi_tower.c
//  AlgorithmExercises
//
//  Created by 哲思 on 2024/7/26.
//

#include "hanoi_tower.h"
#include <stdlib.h>

/**
 *【递归法】
 *
 * @brief 5、汉诺塔问题
 *
 * 问题：寺院里有3根柱子，第一根有64个盘子，从上往下盘子越来越大，方丈要求小和尚A把这64个盘子全部移动到第三根柱子上。要求始终只能小盘子压着大盘子，且每次只能移动一个。
 */
void pause_program(void) {
    #ifdef _WIN32
        // Windows 系统
        system("pause");
    #elif __APPLE__
        // macOS 系统
        system("read -p 'Press Enter to continue...'");
    #elif __linux__
        // Linux 系统
        printf("Press Enter to continue...");
        getchar();
    #else
        #error "Unsupported platform"
    #endif
}

void move_tower(int n, int x, int y, int z) {
    if (n==1) {
        printf("%c-->%c\n", x, z);
    } else {
        move_tower(n-1, x, z, y);
        printf("%c-->%c\n", x, z);
        
        pause_program();
        
        move_tower(n-1, y, x, z);
    }
}

void hanoi_tower(void) {
    int h;
    
    printf("输入盘子个数：");
    scanf("%d", &h);
    printf("移动%02d个盘子的步骤如下(A.柱一、B.柱二、C.柱三。点击Enter键可以继续执行步骤显示。)：\n", h);
    
    move_tower(h, 'A', 'B', 'C');
}
