#include <avr/io.h>

#include "usart.h"

int main()
{
    UBRR0H = (UBRR_VAL & 0xFF00) >> 8;
    UBRR0L = (UBRR_VAL & 0x00FF);

    write_usart_byte('a');

    while (1)
    {
    }
}