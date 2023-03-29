#pragma once

//
// Created by 64432 on 2023/3/22.
//

#ifndef DATASTRUCTURE_LINEAR_LIST_H
#define DATASTRUCTURE_LINEAR_LIST_H

#endif //DATASTRUCTURE_LINEAR_LIST_H

#define InitLength 10
#include <stdlib.h>
#include "stdio.h"

typedef struct LinearList {
    int* data;
    int length;
    int max_length;
} LinearList;

// ��ʼ��
void InitList(LinearList* L)
{
    int i;
    (*L).data = (int*)malloc(sizeof(int) * (InitLength));
    for (i = 0; i < InitLength; i++)
    {
        (*L).data[i] = 0;
    }
    (*L).length = 0;
    (*L).max_length = InitLength;
}

//ĩβ׷��
int add_num(LinearList* L, int i)
{
    if ((*L).length == (*L).max_length)
        return -1;
    (*L).data[(*L).length] = i;
    (*L).length++;
    return (*L).length;
}

//ĩβ����
int pop_num(LinearList* L)
{
    int pop_num;
    if ((*L).length == 0)
        return -1;
    pop_num = (*L).data[(*L).length - 1];
    (*L).data[(*L).length - 1] = 0;
    (*L).length--;
    return pop_num;
}

//��ӡ���Ա�
void print_list(LinearList L)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
    printf("length:%d\tmax_length:%d\n", L.length, L.max_length);
}

//��չ�������
void extern_list(LinearList* L, int size) {
    int* p;
    int i;
    p = (*L).data;
    (*L).data = (int*)malloc(sizeof(int) * ((*L).max_length + size));
    for (i = 0; i < (*L).length; i++) {
        (*L).data[i] = p[i];
    }
    (*L).max_length = (*L).max_length + size;
    free(p);
}

//ָ��λ�ò���
int insert_num(LinearList* L, int index, int num)
{
    int i;
    if (index > (*L).length + 1 || (*L).length == (*L).max_length)
        return -1;
    for (i = (*L).length - 1; i > index - 2; i--)
    {
        (*L).data[i + 1] = (*L).data[i];
    }
    (*L).length++;
    (*L).data[index - 1] = num;
    return index;
}

//��λ������
int search_bit(LinearList L, int bit)
{
    if (bit > L.length)
        return -1;
    return L.data[bit - 1];
}

//��ֵ����
int search_num(LinearList L, int num)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == num)
            return i + 1;
    }
    return -1;
}

//��λ�Ƴ�
int remove_bit(LinearList* L, int bit)
{
    int i;
    int rm_num;
    if (bit > (*L).length)
        return -1;
    rm_num = (*L).data[bit - 1];
    for (i = bit; i < (*L).length; i++)
    {
        (*L).data[i - 1] = (*L).data[i];
    }
    (*L).length--;
    (*L).data[(*L).length] = 0;
    return rm_num;
}

//��ֵ�Ƴ�
int remove_num(LinearList* L, int num)
{
    int loc = search_num(*L, num);
    if (loc == -1)
        return -1;
    remove_bit(L, loc);
    return loc;
}

//��λ����
int update_bit(LinearList* L, int bit, int num)
{
    if (bit > (*L).length)
        return -1;
    (*L).data[bit - 1] = num;
    return num;
}

//��ֵ����
int update_num(LinearList* L, int num1, int num2)
{
    int loc = search_num(*L, num1);
    if (loc == -1)
        return -1;
    update_bit(L, loc, num2);
    return loc;
}











