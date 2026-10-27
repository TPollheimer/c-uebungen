#include <stdio.h>
#include <stdint.h>
void print_bin(uint8_t x);
void set_bit(uint8_t *x, uint8_t t);
void clear_bit(uint8_t *x, uint8_t t);
void toggle_bit(uint8_t *x, uint8_t t);
uint8_t check_bit(uint8_t x, uint8_t t);
// set_bit, clear_bit, toggle_bit, check_bit uint8_t
int main() {
    uint8_t x = 251;
    print_bin(x);
    set_bit(&x,2);
    print_bin(x);
    clear_bit(&x,7);
    print_bin(x);
    toggle_bit(&x,2);
    set_bit(&x,7);
    print_bin(x); 
    printf("Bit 4: %d\n", check_bit(x, 4));
    if (check_bit(x, 7)) { /* Bit 7 ist gesetzt */ }
    return 0;
}

void print_bin(uint8_t x){
    for (int i = 7; i >= 0;i--){
        printf("%d", (x >> i) & 1);
    }
    printf("\n");
    /*   00000011   (3)
       & 00000001   (1)
       ----------
         00000001   → nur das letzte Bit bleibt

         Ohne & 1 gibst du die Spalte “als Zahl” aus: 0 0 0 0 0 0 1 3, 
         also 00000013. Bei i = 0 ist nichts verschoben, und die Zahl ist noch 3, 
         nicht 1. printf("%d") gibt immer die ganze Zahl aus.

  */
}
void set_bit(uint8_t *x,uint8_t t){
    if (t > 7) return;
    *x |= (1u << t); //1u << n baut eine Maske: nur Bit n ist 1, alle anderen sind 0
    // Bit n setzen (auf 1)
}
void clear_bit(uint8_t *x,uint8_t t){
    if (t > 7) return;
    *x &= ~(1u << t); // Weil | ein Bit nur auf 1 setzen kann, nie auf 0.
    //// Bit n löschen (auf 0)
}
void toggle_bit(uint8_t *x,uint8_t t){
    if (t > 7) return;
    *x ^= (1u << t);
    // Bit n umschalten
}
uint8_t check_bit(uint8_t x, uint8_t t){
       return (x >> t) & 1u;
}