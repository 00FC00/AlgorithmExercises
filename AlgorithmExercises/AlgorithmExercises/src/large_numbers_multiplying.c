//
//  large_numbers_multiplying.c
//  AlgorithmExercises
//
//  Created by 哲思 on 2024/7/26.
//

#include "large_numbers_multiplying.h"
#include <stdlib.h>
#include <string.h>

/**
 *【分治算法】
 *
 * @brief 7、大数相乘
 *
 * 问题：大数相乘，分解数值，求解，合并，运用分治解决思路
 */
char *result;
int pr = 1;

void get_fill(char *a, char *b, int ia, int ja, int ib, int jb, int tbool, int move) {
    int r,m,n,s,j,t;
    char *stack;
    
    m = a[ia] - 48;
    if (tbool) {// 直接将结果数组的标志位填入，这里用了堆栈思想
        r = (jb-ib > ja-ia) ? (jb-ib) : (ja-ia);
        stack = (char *)malloc(r+4);
        
        for (r=j=0, s=jb; s>=ib; r++,s--) {
            n = b[s] - 48;
            stack[r] = (m*n+j)%10;
            j = (m*n+j)/10;
        }
        
        if (j) {
            stack[r] = j;
            r++;
        }
        
        for (r--; r>=0; r--,pr++)
            result[pr] = stack[r];
        
        free(stack);
        
        for (move = move +pr; pr<move; pr++)
            result[pr] = '\0';
    } else {// 与结果的某几位相加，这里不改变标志位pr值
        r = pr - move - 1;
        
        for (s=jb,j=0; s>=ib; r--,s--) {
            n = b[s] - 48;
            t = m * n + j + result[r];
            result[r] = t%10;
            j = t/10;
        }
        
        for (; j; r--) {
            t = j + result[r];
            result[r] = t%10;
            j = t/10;
        }
    }
}

int get(char *a, char *b,int ia, int ja, int ib, int jb, int t, int move) {
    int m,n,s,j;
    if (ia==ja) {
        get_fill(a, b, ia, ja, ib, jb, t, move);
        return 1;
    } else if (ib==jb) {
        get_fill(b, a, ib, jb, ia, ja, t, move);
        return 1;
    } else {
        m = (ja + ia)/2;
        n = (jb + ib)/2;
        s = ja - m;
        j = jb - n;
        get(a, b, ia, m, ib, n, t, s+j+move);
        get(a, b, ia, m, n+1, jb, 0, s+move);
        get(a, b, m+1, ja, ib, n, 0, j+move);
        get(a, b, m+1, ja, n+1, jb, 0, 0+move);
    }
    return 0;
}

void large_numbers_multiplying(void) {
    char *a,*b;
    int n,flag;
    
    a = (char *)malloc(1000);
    b = (char *)malloc(1000);
    
    printf("这个程序会使用堆栈思路分治运算出大数乘积 a*b=？\n");
    printf("Enter a b:");
    scanf("%s %s", a, b);
    
    result = (char *)malloc(strlen(a) + strlen(b) + 2);
    flag = pr = 1;
    result[0] = '\0';
    
    if (a[0]=='-' && b[0]=='-')
        get(a, b, 1, (int)strlen(a)-1, 1, (int)strlen(b)-1, 1, 0);
    
    if (a[0]=='-' && b[0]!='-') {
        flag = 0;
        get(a, b, 1, (int)strlen(a)-1, 0, (int)strlen(b)-1, 1, 0);
    }
    
    if (a[0]!='-' && b[0]=='-') {
        flag = 0;
        get(a, b, 0, (int)strlen(a)-1, 1, (int)strlen(b)-1, 1, 0);
    }
    
    if (a[0]!='-' && b[0]!='-')
        get(a, b, 0, (int)strlen(a)-1, 0, (int)strlen(b)-1, 1, 0);
    
    if (!flag) printf("-");
    
    if (result[0]) printf("%d", result[0]);
    
    for (n=1; n<pr; n++)
        printf("%d", result[n]);
    
    printf("\n");
    free(a);
    free(b);
    free(result);
}
