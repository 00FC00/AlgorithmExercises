//
//  arithmetic_symbol.c
//  AlgorithmExercises
//
//  Created by 哲思 on 2024/7/24.
//

#include "arithmetic_symbol.h"

/**
 *【枚举法】
 *
 * @brief 2、填写运算符
 *
 * 问题：请先输入5个数字和一个算式结果，然后列出在“+”、“-”、“*”、“/” 4个运算符下，使等式成立的方案。
 * 例如：【5 + 5 - 5 - 5 + 5 = 5】  => 计算结果为32种组合方案
 */
#if 0
void arithmetic_symbol(void) {
    int num[5];                          // 保存操作数
    int result;                          // 保存运算式的结果值
    int count = 0;                       // 计数器，统计符合条件的方案
    double left, right;                  // 保存中间结果
    char oper[4] = {'+', '-', '*', '/'}; // 运算符
    
    printf("请依次输入5个操作数：\n");
    for (int j = 0; j < 5; j++) {
        scanf("%d", &num[j]);
    }
    printf("请输入等式的目标结果：\n");
    scanf("%d", &result);

    // 列出4种运算符的所有组合：0.+   1.-   2.*   3./
    for (int op0 = 0; op0 < 4; op0++) {
        for (int op1 = 0; op1 < 4; op1++) {
            for (int op2 = 0; op2 < 4; op2++) {
                for (int op3 = 0; op3 < 4; op3++) {
                    // 运算符若是 3./，则第二个运算数不能为 0
                    if ((op0 == 3 && num[1] == 0) || (op1 == 3 && num[2] == 0) || (op2 == 3 && num[3] == 0) || (op3 == 3 && num[4] == 0)) {
                        continue;
                    }
                    
                    int op[4] = {op0, op1, op2, op3};
                    left = 0;
                    right = num[0];
                    int sign = 1;
                    
                    // 使用case语句，将四种运算符填到对应的空格位置，并进行运算
                    for (int j = 0; j < 4; j++) {
                        switch (oper[op[j]]) {
                            case '+':
                                left += sign * right;
                                sign = 1;
                                right = num[j + 1];
                                break;

                            case '-':
                                left += sign * right;
                                sign = -1;
                                right = num[j + 1];
                                break;

                            case '*':
                                right *= num[j + 1];
                                break;

                            case '/':
                                right /= num[j + 1];
                                break;

                            default:
                                break;
                        }
                    }
                    
                    // 判断运算式的结果是否和输入的结果相同
                    if (left + sign * right == result) {
                        count++;
                        printf("%3d: ", count);
                        for (int j = 0; j < 4; j++) {
                            printf("%d%c", num[j], oper[op[j]]);
                        }
                        printf("%d=%d\n", num[4], result);
                    }
                }
            }
        }
    }

    if (count == 0) {
        printf("没有符合要求的方法！\n");
    }
}

#else

// MARK: - 函数拆分
/// 输入5个操作数
void input_numbers(int num[5]) {
    printf("请依次输入5个操作数：\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &num[i]);
    }
}

/// 输入目标结果
int input_result(void) {
    int result;
    printf("请输入等式的目标结果：\n");
    scanf("%d", &result);
    return result;
}

/// 表达式结果计算
void evaluate_expression_and_print_result(int num[5], int result, int operators[4], int* count) {
    double left = 0;
    double right = num[0];
    int sign = 1;
    char oper[4] = {'+', '-', '*', '/'}; // 运算符
    
    // 使用case语句，将四种运算符填到对应的空格位置，并进行运算
    for (int j = 0; j < 4; j++) {
        switch (oper[operators[j]]) {
            case '+':
                left += sign * right;
                sign = 1;
                right = num[j + 1];
                break;
                
            case '-':
                left += sign * right;
                sign = -1;
                right = num[j + 1];
                break;
                
            case '*':
                right *= num[j + 1];
                break;
                
            case '/':
                right /= num[j + 1];
                break;
                
            default:
                break;
        }
    }
    
    // 判断运算式的结果是否和输入的结果相同
    if (left + sign * right == result) {
        (*count)++;
        printf("%3d: ", *count);
        for (int j = 0; j < 4; j++) {
            printf("%d%c", num[j], oper[operators[j]]);
        }
        printf("%d=%d\n", num[4], result);
    }
}

/// 递归遍历所有组合
void try_combinations_recursive(int num[5], int result, int* count, int operators[4], int depth) {
    if (depth == 4) {
        evaluate_expression_and_print_result(num, result, operators, count);
        return;
    }

    for (operators[depth] = 0; operators[depth] < 4; operators[depth]++) {
        if (operators[depth] < 3 || num[depth + 1] != 0) { // 防止除零错误
            try_combinations_recursive(num, result, count, operators, depth + 1);
        }
    }
}

/// 遍历所有组合的主函数
void try_combinations(int num[5], int result) {
    int count = 0;          // 计数器，统计符合条件的方案
    int operators[4] = {0}; // 保存填入的数学算式符号

    try_combinations_recursive(num, result, &count, operators, 0);

    if (count == 0) {
        printf("没有符合要求的方法！\n");
    }
}

/// 主函数
void arithmetic_symbol(void) {
    int num[5];             // 保存操作数
    int result;             // 保存运算式的结果值
    
    input_numbers(num);
    result = input_result();
    try_combinations(num, result);
}

#endif
