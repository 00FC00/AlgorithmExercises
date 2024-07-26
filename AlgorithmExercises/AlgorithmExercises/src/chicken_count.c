//
//  chicken_count.c
//  AlgorithmExercises
//
//  Created by 哲思 on 2024/7/23.
//

#include "chicken_count.h"

/**
 *【枚举法】
 *
 * @brief 1、百元买百鸡
 *
 * 问题："鸡翁一，值钱五；鸡母一，值钱三；鸡雏三，值钱一。百钱买百鸡，问鸡翁，母，雏各几何？"
 */
void chicken_count(void) {
    // x: 公鸡, y: 母鸡, z: 小鸡
    int x, y, z;
    for (x = 0; x <= 20; x++) {
        for (y = 0; y <= 33; y++) {
            z = 100 - x - y;
            if (z % 3 == 0 && x * 5 + y * 3 + z / 3 == 100) {
                printf("公鸡：%d，母鸡：%d，小鸡：%d。\n", x, y, z);
            }
        }
    }
}
