#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define RB_SIZE 8

typedef struct {
    uint8_t data[RB_SIZE];
    uint8_t head;
    uint8_t tail;
    uint8_t count;     // wie viele Werte gerade drin sind
} RingBuffer;

void rb_init(RingBuffer *rb);                 // alles auf 0
bool rb_push(RingBuffer *rb, uint8_t value);  // false, wenn voll
bool rb_pop(RingBuffer *rb, uint8_t *value);  // false, wenn leer
bool rb_is_empty(const RingBuffer *rb);
bool rb_is_full(const RingBuffer *rb);
void rb_see_rb(RingBuffer *rb);

int main(){
    RingBuffer rb;
    uint8_t x;
    rb_init(&rb);
    rb_see_rb(&rb);
    //Test empty
    rb_pop(&rb,&x);

    // Test 3 pushes 3 pops
    rb_push(&rb,1);
    rb_push(&rb,2);
    rb_push(&rb,3);
    rb_see_rb(&rb);

    rb_pop(&rb,&x);
    printf("POP: %d\n",x);
    rb_pop(&rb,&x);
    printf("POP: %d\n",x);
    rb_pop(&rb,&x);
    printf("POP: %d\n",x);
    rb_see_rb(&rb);

    // Test: 9 Werte füllen
    rb_init(&rb);
    for(int i= 0; i <= RB_SIZE; i++){
        printf("Gib eine integer Zahl ein: ");
        scanf("%hhu", &x);
        rb_push(&rb,x);
        rb_see_rb(&rb);
    }
    // Test: umbruch
    rb_pop(&rb,&x);
    printf("POP: %d\n",x);
    rb_pop(&rb,&x);
    printf("POP: %d\n",x);
    rb_pop(&rb,&x);
    printf("POP: %d\n",x);
    rb_see_rb(&rb);

    rb_push(&rb,9);
    rb_push(&rb,9);
    rb_see_rb(&rb);

    return 0;
}

void rb_init(RingBuffer *rb){
    for(int i = 0; i < RB_SIZE; i++) rb->data[i] = 0;
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}     
bool rb_push(RingBuffer *rb, uint8_t value){
    if(rb_is_full(rb)) return false;

    rb->data[rb->head] = value;
    rb->count ++;

    if(rb->head == RB_SIZE-1) rb->head = 0;
    else rb->head++;

    return true;
}
bool rb_pop(RingBuffer *rb, uint8_t *value){
    if(rb_is_empty(rb)) return false;

    *value  = rb->data[rb->tail];
    rb->count --;

    if(rb->tail == RB_SIZE-1) rb->tail = 0;
    else rb->tail++;
    return true;
}
bool rb_is_empty(const RingBuffer *rb){
    if(rb->count == 0){
        printf("Ringbuffer ist leer: 0/%d erreicht\n", RB_SIZE);
        return true;
    } 
    return false;
}
bool rb_is_full(const RingBuffer *rb){
    if(rb->count == RB_SIZE){
        printf("Ringbuffer ist voll: %d/%d erreicht\n", RB_SIZE,RB_SIZE);
        return true;
    } 
    return false;
}

void rb_see_rb(RingBuffer *rb){
    printf("Ringbuffer: ");
    for(int i = 0;i < RB_SIZE; i++){
        printf("%d",rb->data[i]);
    }
    printf("\n");
}