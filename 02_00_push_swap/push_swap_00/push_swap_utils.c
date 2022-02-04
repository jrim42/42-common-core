#include "push_swap.h"

void    stk_init(t_stack **stk);
t_node  *nd_init(int num);
void    stk_push(t_stack *stk, t_node *new_top);
t_node  *stk_pop(t_stack *stk);

void    stk_init(t_stack **stk)
{
    *stk = (t_stack *)malloc(sizeof(t_stack));
    (*stk)->top = NULL;
    (*stk)->name = 0;
    (*stk)->size = 0;
}

t_node  *nd_init(int num)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    new_node->data = num;
    // 순환구조
    new_node->next = new_node;
    new_node->prev = new_node;
    return (new_node);
}

void    stk_push(t_stack *stk, t_node *new_top)
{
    t_node  *cur_top;

    if(stk->size == 0)
        stk->top = new_top;
    else
    {
        cur_top = stk->top;
        // 새로운 노드의 앞뒤 연결 
        new_top->prev = cur_top->prev;
        new_top->next = cur_top;
        // 기존 노드의 앞뒤 연결 해제
        cur_top->prev->next = new_top;
        cur_top->prev = new_top;
        stk->top = new_top; 
    }
    stk->size++;
}

t_node  *stk_pop(t_stack *stk)
{
    t_node  *cur_top;
    t_node  *new_top;

    cur_top = stk->top;
    if (stk->size == 1)
        stk->top = NULL;
    else
    {
        new_top = stk->top->next;
        new_top->prev = cur_top->prev;
        cur_top->prev->next = new_top;
        stk->top = new_top;  
        // 다른 노드와의 연결 끊기
        cur_top->prev = cur_top;
        cur_top->next = cur_top;
    }
    stk->size--; 
    return (cur_top);
}    
