#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>

int main()
{
    char *str = "salut";
    char **ptr = &str;
    printf("%s\n%s", str, *ptr);
}

int pointer_to_hex(void *ptr, char *buffer) {
    const char *hex_digits = "0123456789abcdef";
    unsigned long address = (unsigned long)ptr;
    int i = 15; // Commencez par la fin du buffer
    int leading_zeros = 1; // Utilisé pour ignorer les zéros non significatifs

    while (i >= 2) { // Laissez de la place pour "0x"
        unsigned int current_hex_value = address % 16;
        
        // Si la valeur actuelle n'est pas un zéro, ou si nous avons déjà écrit des chiffres significatifs
        if (current_hex_value != 0 || !leading_zeros) {
            buffer[i] = hex_digits[current_hex_value];
            leading_zeros = 0; // Nous avons trouvé un chiffre significatif
        } else {
            buffer[i] = ' '; // Remplacez les zéros non significatifs par des espaces
        }
        
        address = address / 16;
        i--;
    }

    buffer[1] = 'x';
    buffer[0] = '0';
    buffer[16] = '\0';

    // Supprimez les espaces non désirés
    int start = 0;
    while (buffer[start] == ' ') {
        start++;
    }

    ft_putstr(&buffer[start]);
    return 0;
}