#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node *next;
}  Node;

// typedef struct {
//     Node *head;
//     Node *tail;
// } List;


// 创建一个List，其中的head和tail都是零
List list_create()
{
    List ls;
    ls.head = NULL;
    ls.tail = NULL;

    return ls;
}

//释放整个链表中全部的结点，list的head和tail置零。
void list_free(List *list)
{
    Node *p, *q;
    for (p=list->head; p; p=q){
        q = p->next;
        free(p);
    }
    list->head = NULL;
    list->tail = NULL;
}

//用v制作新的结点加到链表的最后。
void list_append(List *list, int v)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->value = v;
    p->next = NULL;

    if (list->tail){
        list->tail->next = p;
    }else{
        list->head = p;
    }
    list->tail = p;
}


// 用v制作新的结点加到链表的最前面。
void list_insert(List *list, int v)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->value = v;
    p->next = list->head;

    list->head = p;
    
}

//将链表中第index个结点的值置为v，链表结点从零开始编号。
void list_set(List *list, int index, int v)
{
    int cnt;
    Node *p;
    for (cnt=0, p=list->head; p; cnt++, p=p->next){
        if (cnt==index){
            p->value = v;
            break;
        }
    }
}

//获得链表中第index个结点的值，第一个结点的index为零。
int list_get(List *list, int index)
{
    int ret, cnt;
    Node *p;
    for (cnt=0, p=list->head; p; cnt++, p=p->next){
        if (cnt==index){
            ret = p->value;
            break;
        }
    }

    return ret;
}

int list_size(List *list)
{
    int cnt = 0;
    Node *p;
    for (p = list->head; p; p=p->next){
        cnt++;
    }

    return cnt;
}

//在链表中寻找值为v的结点，返回结点的编号，结点的编号从零开始；如果找不到，返回-1。
int list_find(List *list, int v)
{
    int ret = -1;

    int cnt;
    Node *p;
    for (cnt=0, p=list->head; p; cnt++, p=p->next){
        if (p->value==v){
            ret = cnt;
            break;
        }
    }

    return ret;

}

//删除链表中值为v的结点。
void list_remove(List *list, int v)
{
    Node *p, *q;
    q=NULL;
    p=list->head;
    for (; p; q=p, p=p->next){
        if (p->value==v){
            if (q){
                q->next = p->next;

                // printf("del_value = %d\n",p->value);
                // printf("//%d//\n", list->tail->value);
                if (q->next==NULL){  //del the tail
                    list->tail = q;
                }
            }else{
                list->head = p->next;
            }
            
            free(p);
            //printf("tail = %d\n", list->tail->value);
            break;
        }
    }

    
}

//遍历链表，依次对每一个结点中的值做func函数。
void list_iterate(List *list, void (*func)(int v))
{
    Node *p;
    for (p = list->head; p; p=p->next){
        func(p->value);
    }
}