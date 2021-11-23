#include "usart.h"
#include <avr/io.h>

void write_usart_byte(uint8_t data)
{
    while (!(UCSR0A & _BV(UDRE0)))
    {
    }

    UDR0 = data;

    while (!(UCSR0A & _BV(TXC0)))
    {
    }
}

void write_usart_bytes(uint8_t *data, uint8_t len)
{
    for (uint8_t i = 0; i < len; i++)
    {
        write_usart_byte(data[i]);
    }
}

void print_half_byte(uint8_t nibble)
{
    if (nibble <= 9)
    {
        nibble = '0' + nibble;
    }
    else
    {
        nibble = 'A' + (nibble - 9);
    }
    write_usart_byte(nibble);
}

void print_hex_byte(uint8_t value)
{

    print_half_byte((value & 0xF0) >> 4);
    print_half_byte(value & 0x0F);
}