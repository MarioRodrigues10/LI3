#ifndef MAPING_H
#define MAPING_H

typedef struct maping Maping;

/**
 * @brief Function that initializes the maping structure.
 *
 * @return Maping* structure initialized.
 */
Maping *maping_init();

/**
 * @brief Function that converts a string to a char using a hash table.
 *
 * @param map Maping* structure.
 * @param str String to be converted.
 *
 * @return char converted.
 */
char string_to_char(Maping *map, const char *str);

/**
 * @brief Function that converts a char back to a string using a hash table.
 *
 * @param map Maping* structure.
 * @param ch Char to be converted.
 *
 * @return const char* converted.
 */
char *char_to_string(Maping *map, char ch);

/**
 * @brief Function that frees the memory of the maping structure.
 *
 * @param map Maping* structure.
 */
void maping_free(Maping *map);

#endif
