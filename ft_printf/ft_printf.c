#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_putchar(char c) {
    return write(1, &c, 1);
}

int ft_putstr(char *s) {
    int i = 0;
    while (s[i]) {
        ft_putchar(s[i]);
        i++;
    }
    return i;
}
char *pointer_to_hex2(char *buffer)
{
    char *start_ptr = &buffer[2];
    while (*start_ptr == '0' && *(start_ptr + 1) != '\0') {
        start_ptr++;
    }

    // Décalez les caractères significatifs pour conserver le préfixe "0x"
    int offset = start_ptr - &buffer[2];
    for (int j = 2; j < 16 - offset; j++) {
        buffer[j] = buffer[j + offset];
    }
    buffer[16 - offset] = '\0';
    return buffer;

}
int pointer_to_hex(void *ptr, char *buffer) {
    const char *hex_digits = "0123456789abcdef";
    unsigned long address = (unsigned long)ptr;
    int i = 15; // Commencez par la fin du buffer

    // Remplissez le buffer de droite à gauche
    while (i >= 2) { // Laissez de la place pour "0x"
        unsigned int current_hex_value = address % 16;
        buffer[i] = hex_digits[current_hex_value];
        address = address / 16;
        i--;
    }

    buffer[1] = 'x';
    buffer[0] = '0';
    buffer[16] = '\0';

    pointer_to_hex2(buffer);
    ft_putstr(buffer);
    return 0;
    // Cette fonction doit être améliorée pour retourner le nombre de caractères imprimés
}
int ft_unsigned_putnbr(unsigned int n)
{
    if (n >= 10) {
        ft_unsigned_putnbr(n / 10);
        ft_unsigned_putnbr(n % 10);
    } else {
        ft_putchar(n + '0');
    }
    return 0;
}
int ft_putnbr(int n) {
    if (n == -2147483648) {
        ft_putstr("-2147483648");
        return 11;
    }
    if (n < 0) {
        ft_putchar('-');
        n = -n;
    }
    if (n >= 10) {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    } else {
        ft_putchar(n + '0');
    }
    return 0; // Cette fonction doit être améliorée pour retourner le nombre de caractères imprimés
}

int ft_putnbr_hex(unsigned int n, char format) {
    const char *hex_digits_lowercase = "0123456789abcdef";
    const char *hex_digits_uppercase = "0123456789ABCDEF";
    const char *chosen_digits = (format == 'x') ? hex_digits_lowercase : hex_digits_uppercase;

    if (n >= 16) {
        ft_putnbr_hex(n / 16, format);
        ft_putnbr_hex(n % 16, format);
    } else {
        ft_putchar(chosen_digits[n]);
    }
    return 0; // Cette fonction doit être améliorée pour retourner le nombre de caractères imprimés
}


int handle_conversion(char format, va_list args) {
    char hex_buffer[17];
    
    if (format == 'c') {
        return ft_putchar(va_arg(args, int));
    } else if (format == 's') {
        return ft_putstr(va_arg(args, char *));
    } else if (format == 'd' || format == 'i') {
        return ft_putnbr(va_arg(args, int));
    } else if (format == 'p') {
        return pointer_to_hex(va_arg(args, void *), hex_buffer);
    } else if(format == 'x' || format == 'X') {
        return ft_putnbr_hex(va_arg(args, unsigned int), format);
    }
    else if(format == 'u')
        return ft_unsigned_putnbr(va_arg(args, unsigned int));
    else if(format == '%')
        ft_putchar('%');
    else {
        return ft_putchar(format);
    }
    return 0;
}

int ft_printf(const char *format, ...) {
    va_list args;
    int count = 0;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;
            count += handle_conversion(*format, args);
        } else {
            count += ft_putchar(*format);
        }
        format++;
    }

    va_end(args);
    return count;
}

int main() {
    ft_printf(" %x\n", 123456);
    printf(" %x\n", 123456);
    return 0;
}
