#include "my_lib.h"
/*
En la función my_strlen pasamos un puntero por parámetro que apunta a una
cadena de carácteres, incrementamos el valor del puntero y de la variable
"size" de tipo "size_t" (que se ajusta a la arquitectura que estemos usando)
hasta que se encuentre el carácter que indica el fin de la secuencia.
*/
size_t my_strlen(const char *str)
{
    size_t size = 0;
    while (*str != '\0')
    {
        size++;
        str++;
    }
    return size;
}
/*
La función my_strcmp compara dos cadenas de caracteres apuntadas por los punteros
"str1" y "str2". Itera sobre cada par de caracteres correspondientes de ambas cadenas,
incrementando los punteros hasta que encuentra un par de caracteres que no coinciden
o hasta que se llega al final de alguna de las cadenas.
Hace un return de la diferencia entre los dos primeros carácteres que no coinciden. 
Si las cadenas son iguales, la función devuelve 0. 
La comparación se hace usando "unsigned char" porque si no se pueden interpretar
los carácteres que empiezan por "1" como un número negativo al hacer el casting. 
*/
int my_strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return ((unsigned char)*str1 - (unsigned char)*str2);
}
/*
La función my_strcpy copia la cadena de caracteres apuntada por "src" a la ubicación 
apuntada por "dest". El puntero original a "dest" se guarda para retornarlo al final, 
permitiendo encadenar esta operación con otras. El bucle copia carácter por carácter 
hasta encontrar el carácter nulo '\0' que indica el final de "src". 
Posteriormente, se añade un carácter nulo al final de "dest".
*/
char *my_strcpy(char *dest, const char *src)
{
    char *og_dest = dest;
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return og_dest;
}
/*
La función my_strncpy copia hasta "n" caracteres de la cadena "src" a "dest",
asegurándose de que "dest" es una cadena de caracteres terminada en nulo. 
Si la longitud de "src" es menor a "n", "dest" se rellena con caracteres nulos 
hasta alcanzar "n" caracteres en total. La posición original de "dest" se guarda
para poder retornarla, permitiendo operaciones encadenadas. 
*/
char *my_strncpy(char *dest, const char *src, size_t n)
{
    char *og_dest = dest;
    while (n && *src)
    {
        *dest = *src;
        src++;
        dest++;
        n--;
    }
    while (n)
    {
        *dest = '\0';
        dest++;
        n--;
    }
    return og_dest;
}
/*
La función my_strcat concatena la cadena "src" al final de la cadena "dest". 
Primero, encuentra el final de "dest" avanzando el puntero hasta el carácter nulo '\0'. 
Luego, copia los carácteres de "src" a "dest", incluyendo el carácter nulo final de "src". 
El puntero original a "dest" se guarda y se retorna..
*/
char *my_strcat(char *dest, const char *src)
{
    char *og_dest = dest;
    while (*dest)
    {
        dest++; 
    }
    while (*src)
    {
        *dest = *src; 
        dest++;
        src++; 
    }
    *dest = '\0';
    return og_dest; 
}
/*
La función my_strchr busca la primera ocurrencia del carácter "c" en la cadena "str". 
Convierte "c" a tipo char para asegurar una comparación adecuada. Itera sobre "str", 
comparando cada carácter con "c" hasta encontrar una coincidencia o llegar al final de 
la cadena. Si encuentra "c", retorna un puntero al carácter coincidente en "str". 
Si "c" es el carácter nulo '\0', verifica si ha llegado al final de "str" y, de ser así,
 retorna un puntero a este carácter nulo. Si no encuentra "c", retorna NULL.
*/
char *my_strchr(const char *str, int c) {
    // Convertir c a char para la comparación
    char ch = (char)c;
    
    while (*str) {
        if (*str == ch) {
            return (char *)str;
        }
        str++;
    }
    
    // Verificar si c es '\0'
    if (ch == '\0') {
        return (char *)str;
    }

    return NULL;
}
