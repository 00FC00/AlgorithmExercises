//
//  bank_cash.c
//  AlgorithmExercises
//
//  Created by 哲思 on 2024/7/26.
//

#include "bank_cash.h"

/**
 *【逆推法】
 *
 * @brief 4、银行存款问题
 *
 * 问题：母亲为儿子存4年大学生活费，要求整存零取，每月底取，每月取1000，银行年利率为1.71%，则至少需要存入多少？
 */
#define FETCH 1000
#define RATE 0.0171
void bank_cash(void) {
    double corpus[49];
    int i;
    
    corpus[48] = (double)FETCH;
    for (i=47; i>0; i--) {
        corpus[i] = corpus[i+1] + FETCH/(1+RATE/12);
    }
    
    for (i=48; i>0; i--) {
        printf("%d月月末本利共计：%.2f\n", i, corpus[i]);
    }
}
