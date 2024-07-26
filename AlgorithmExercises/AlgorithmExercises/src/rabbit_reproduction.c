//
//  rabbit_reproduction.c
//  AlgorithmExercises
//
//  Created by 哲思 on 2024/7/26.
//

#include "rabbit_reproduction.h"

/**
 *【递推法】
 *
 * @brief 3、兔子繁殖问题
 *
 * 问题：兔子在出生两个月后，就有繁殖能力，一对兔子每月能生一对小兔子，如果所有兔子都不死，那么一年后可以繁殖多少对兔子？
 */
#define NUM 13
void rabbit_reproduction(void) {
    int i;
    long fib[NUM] = {1,1};//定义一个拥有13个元素的数组，用于保存兔子的初始数据和每月的总数
    
    //顺推每个月的总数
    for (i=2; i<NUM; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    for (i=0; i<NUM; i++) {
        printf("第%d月兔子总数：%ld\n", i, fib[i]);
    }
}
