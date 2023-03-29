#pragma once

//
// Created by 64432 on 2023/3/26.
//

#ifndef DATASTRUCTURE_LINK_LIST_H
#define DATASTRUCTURE_LINK_LIST_H

#endif //DATASTRUCTURE_LINK_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * Linklist;

typedef struct node_loc
{
    int loc;
    LNode node;
}node_loc;


//�����ʼ��
void InitLink(Linklist L)
{
    (*L).data = 0;
    (*L).next = NULL;
}


//��ĩβ��ӽڵ�
int add_num_Link(Linklist L, int num)
{
    LNode* added_node;
    added_node = (LNode*)malloc(sizeof(LNode));
    (*added_node).data = num;
    (*added_node).next = NULL;
    while (1)
    {
        if ((*L).next == NULL)
        {
            (*L).next = added_node;
            break;
        }
        L = (*L).next;
    }
    return num;
}


//��ӡ����
void print_link(LNode L)
{
    while (1)
    {
        printf("%d  ", L.data);
        if (L.next == NULL)
            break;
        L = *(L.next);
    }
    printf("\n");

}

//����ڵ�
int insert_link(Linklist L, int loc, int num)
{
    int i;
    LNode* added_node;
    added_node = (LNode*)malloc(sizeof(LNode));
    (*added_node).data = num;
    (*added_node).next = NULL;
    if (loc == 1)
    {
        (*added_node).data = (*L).data;
        (*L).data = num;
        (*added_node).next = (*L).next;
        (*L).next = added_node;
        return loc;
    }
    else
    {
        for (i = 1; i < loc - 1; i++)
        {
            L = (*L).next;
            if ((*L).next == NULL)
            {
                i++;
                break;
            }
        }
        if (i == loc - 1)
        {
            (*added_node).next = (*L).next;
            (*L).next = added_node;
            return loc;
        }
        else
            return -1;
    }
}

//��ֵɾ���ڵ�
int del_num_link(Linklist L, int num)
{
    LNode* former = NULL, * p;
    while (1)
    {
        if ((*L).data == num)
            break;
        if ((*L).next == NULL)
            return -1;
        former = L;
        L = (*L).next;

    }
    if (former == NULL)
    {
        p = (*L).next;
        (*L).data = (*p).data;
        (*L).next = (*p).next;
    }
    else
        (*former).next = (*L).next;
    return num;
}

//��λɾ���ڵ�
int del_loc_link(Linklist L, int loc)
{
    int i;
    LNode* former=NULL, * p;
    if (loc == 1)
    {
        p = (*L).next;
        (*L).data = (*p).data;
        (*L).next = (*p).next;
    }
    else
    {
        for (i = 1; i < loc; i++)
        {
            former = L;
            L = (*L).next;
            if ((*L).next == NULL)
            {
                i++;
                break;
            }

        }
        if (i == loc)
        {
            (*former).next = (*L).next;
            return (*L).data;
        }
        else
            return -1;
    }
}

//��ĩβ�����ڵ�
int pop_link(Linklist L)
{
    LNode* former = NULL;
    while (1)
    {
        if ((*L).next == NULL)
        {
            break;
        }
        former = L;
        L = (*L).next;
    }
    if (former == NULL)
    {
        return -1;
    }
    (*former).next = NULL;
    return (*L).data;
}


//��ֵ���ҽ��
node_loc search_num_link(LNode L, int num)
{
    int i = 1;
    node_loc nl;
    LNode naNode;
    naNode.data = NULL;
    naNode.next = NULL;
    while (1)
    {
        if (L.data == num)
            break;
        if (L.next == NULL)
        {
            nl.node = naNode;
            nl.loc = 0;
            return nl;
        }

        i++;
        L = *(L.next);
    }
    nl.node = L;
    nl.loc = i;
    return nl;
}

//��ӡ�ڵ�
void print_node(LNode node)
{
    printf("data:%d\nnext_addr:%d\n", node.data, node.next);
}

//��ӡ�ڵ������Ϣ
void print_nl(node_loc nl)
{
    printf("loc:%d\ndata:%d\nnext_addr:%d\n", nl.loc, nl.node.data, nl.node.next);
}

//��λ���ҽ�㣬�����ظýڵ�
LNode search_loc_link(LNode L, int loc)
{
    int i;
    LNode naNode;
    naNode.data = NULL;
    naNode.next = NULL;
    for (i = 1; i < loc; i++)
    {
        if (L.next == NULL)
            break;
        L = *(L.next);
    }
    if (i == loc)
        return L;
    else
        return naNode;
}

//��ֵ���½ڵ�
int update_num_link(Linklist L, int num1, int num2)
{
    while (1)
    {
        if ((*L).data == num1)
            break;
        if ((*L).next == NULL)
        {
            return -1;
        }
        L = (*L).next;
    }
    (*L).data = num2;
    return num2;
}

//��λ���½ڵ�
int update_loc_link(Linklist L, int loc, int num)
{
    int i;
    for (i = 1; i < loc; i++)
    {
        if ((*L).next == NULL)
            break;
        L = (*L).next;
    }
    if (i == loc)
        (*L).data = num;
    else
        return -1;
}


