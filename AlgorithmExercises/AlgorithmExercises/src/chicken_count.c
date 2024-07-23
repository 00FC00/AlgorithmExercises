//
//  chicken_count.c
//  AlgorithmExercises
//
//  Created by 哲思 on 2024/7/23.
//

#include "chicken_count.h"

void chicken_count(void) {
    // x: 公鸡, y: 母鸡, z: 小鸡
    int x, y, z;
    for (x=0; x<=20; x++) {
        for (y=0; y<=33; y++) {
            z = 100-x-y;
            if (z%3==0 && x*5+y*3+z/3==100) {
                printf("公鸡：%d，母鸡：%d，小鸡：%d。\n", x, y, z);
            }
        }
    }
}
