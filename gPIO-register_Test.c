#include <stdio.h>
#include <stdint.h>
//gpio_set, gpio_clear, gpio_toggle und gpio_read
// GpioPort *p und uint8_t pin (0 bis 7)
typedef union {
    uint8_t reg;                 // der ganze Port auf einmal
    struct {
        uint8_t pin0 : 1;        // ": 1" heißt: genau 1 Bit breit
        uint8_t pin1 : 1;
        uint8_t pin2 : 1;
        uint8_t pin3 : 1;
        uint8_t pin4 : 1;
        uint8_t pin5 : 1;
        uint8_t pin6 : 1;
        uint8_t pin7 : 1;
    } bits;
} GpioPort;


void gpio_set(GpioPort *port, int pin);
void gpio_clear(GpioPort *port, int pin);
void gpio_toggle(GpioPort *port, int pin);
int gpio_read(GpioPort *port, int pin);

int main(){
    GpioPort port;
    port.reg = 0;

    gpio_set(&port, 0);
    gpio_set(&port, 3);
    printf("reg = 0x%02x\n", port.reg);   // erwartet: 0x09

    port.bits.pin5 = 1;                   // direkt über das Bitfeld
    printf("reg = 0x%02x\n", port.reg);   // erwartet: 0x29

    gpio_toggle(&port, 0);
    printf("pin0 = %d, pin3 = %d\n", gpio_read(&port, 0), gpio_read(&port, 3));

    port.reg = 0;
    port.bits.pin0 = 1;
    printf("pin0=1 -> reg = 0x%02x\n", port.reg);   // sollte 0x01 sein

    port.reg = 0;
    port.bits.pin7 = 1;
    printf("pin0=1 -> reg = 0x%02x\n", port.reg);   // sollte 0x80 sein
    return 0;
}

void gpio_set(GpioPort *port, int pin){
    port->reg |= (1u << pin);
}
void gpio_clear(GpioPort *port, int pin){
    port->reg &= ~(1u << pin);
}
void gpio_toggle(GpioPort *port, int pin){
    port->reg ^= (1u << pin);
}
int gpio_read(GpioPort *port, int pin){
    return (port->reg >> pin) & 1u;
}