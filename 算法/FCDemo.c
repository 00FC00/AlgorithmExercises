//
//  FCDemo.c
//  算法
//
//  Created by 冯宣超 on 2020/9/3.
//  Copyright © 2020 FC. All rights reserved.
//

#include "FCDemo.h"
#include <stdlib.h>

/**
 【枚举法】
 
 问题："鸡翁一，值钱五；鸡母一，值钱三；鸡雏三，值钱一。百钱买百鸡，问鸡翁，母，雏各几何？"
 */
void chickenCount() {
    // x:公鸡 y:母鸡 z:小鸡
    int x,y,z;
    for (x=0; x<=20; x++) {
        for (y=0; y<=33; y++) {
            z = 100-x-y;
            if (z%3==0 && x*5+y*3+z/3==100) {
                printf("公鸡：%d，母鸡：%d，小鸡：%d。\n", x, y, z);
            }
        }
    }
}



/**
 【枚举法】
 
 问题：在下面的算式中，添加“+”、“-”、“*”、“/” 4个运算符，使等式成立
      5  5  5  5  5 = 5
 */
void arithmeticSymbol(void) {
    int j,i[5];                        // 循环变量，数组i用来表示4个运算符
    int sign;                          // 累加运算时的符号
    int result;                        // 保存运算式的结果值
    int count=0;                       // 计数器，统计符合条件的方案
    int num[6];                        // 保存操作数
    float left,right;                  // 保存中间结果
    char oper[5]={' ','+','-','*','/'};// 运算符

    printf("输入5个数，之间用空格键隔开：\n");
    for (j=1; j<=5; j++)
        scanf("%d", &num[j]);
    printf("输入结果：\n");
    scanf("%d", &result);

    for (i[1]=1; i[1]<=4; i[1]++) {//循环4种运算符，1.+   2.-   3.*   4./
        if (i[1]<4 || num[2]!=0) {//运算符若是/，则第二个运算数不能为0
            for (i[2]=1; i[2]<=4; i[2]++) {
                if (i[2]<4 || num[3]!=0) {
                    for (i[3]=1; i[3]<=4; i[3]++) {
                        if (i[3]<4 || num[4]!=0) {
                            for (i[4]=1; i[4]<=4; i[4]++) {
                                if (i[4]<4 || num[5]!=0) {
                                    left = 0;
                                    right = num[1];
                                    sign = 1;
                                    //使用case语句，将四种运算符填到对应的空格位置，并进行运算
                                    for (j=1; j<=4; j++) {
                                        switch (oper[i[j]]) {
                                            case '+':
                                                left = left + sign*right;
                                                sign = 1;
                                                right = num[j+1];
                                                break;

                                            case '-':
                                                left = left + sign*right;
                                                sign = -1;
                                                right = num[j+1];
                                                break;

                                            case '*':
                                                right = right * num[j+1];
                                                break;

                                            case '/':
                                                right = right / num[j+1];;
                                                break;

                                            default:
                                                break;
                                        }
                                    }
                                    //开始判断，如果运算式的结果和输入的结果相同，则表示找到一种算法，并输出这个解
                                    if (left+sign*right == result) {
                                        count++;
                                        printf("%3d: ", count);
                                        for (j=1; j<=4; j++)
                                            printf("%d%c", num[j], oper[i[j]]);
                                        printf("%d=%d\n", num[5], result);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (count==0)
        printf("没有符合要求的方法！\n");
}



/**
 【递推法】
 
 问题：兔子在出生两个月后，就有繁殖能力，一对兔子每月能生一对小兔子，如果所有兔子都不死，那么一年后可以繁殖多少对兔子？
 */
#define NUM 13
void rabbitReproduction(void) {
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



/**
 【逆推法】
 
 问题：母亲为儿子存4年大学生活费，要求整存零取，每月底取，每月取1000，银行年利率为1.71%，则至少需要存入多少
 */
#define FETCH 1000
#define RATE 0.0171
void bankCash(void) {
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



/**
 【递归法】
 
 问题：寺院里有3根柱子，第一根有64个盘子，从上往下盘子越来越大，方丈要求小和尚A把这64个盘子全部移动到第三根柱子上。要求始终只能小盘子压着大盘子，且每次只能移动一个。
 */
void moveTower(int n, int x, int y, int z) {
    if (n==1) {
        printf("%c-->%c\n", x, z);
    } else {
        moveTower(n-1, x, z, y);
        printf("%c-->%c\n", x, z);
        {
            getchar();
        }
        moveTower(n-1, y, x, z);
    }
}

void hannuoTowers(void) {
    int h;
    
    printf("输入盘子个数：");
    scanf("%d", &h);
    printf("移动%02d个盘子的步骤如下(enter键可以继续执行步骤显示)：\n", h);
    
    moveTower(h, 'A', 'B', 'C');
    
    //system("pause");
}



/**
 【递归法】
 
 问题：算术模型阶乘转换成递归问题
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



/**
 【分治算法】
 
 问题：大数相乘，分解数值，求解，合并，运用分治解决思路
 */
char *result = '\0';
int pr = 1;

void getFill(char *a, char *b, int ia, int ja, int ib, int jb, int tbool, int move) {
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
            <#statements#>
        }
        
    }
}


void largeNumbersMultiply(void) {
    
}
