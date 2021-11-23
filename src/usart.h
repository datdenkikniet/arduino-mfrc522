#include <stdint.h>

#define UART_RATE 38400
#define UBRR_VAL 25

void write_usart_byte(uint8_t);
void write_usart_bytes(uint8_t *, uint8_t);
void print_hex_byte(uint8_t);