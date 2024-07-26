//
//  factorial.c
//  AlgorithmExercises
//
//  Created by 哲思 on 2024/7/26.
//

#include "factorial.h"

/**
 *【递归法】
 *
 * @brief 6、递归阶乘算法
 *
 * 问题：算术模型阶乘转换成递归问题
 */
int fact(int n) {
    if (n<=1)
        return n;
    else {
        return n*fact(n-1);
    }
}

void factorial(void) {
    int i;
    
    printf("输入要计算阶乘的一个整数：");
    scanf("%d", &i);
    printf("%d的阶乘结果为：%d\n", i, fact(i));
}
