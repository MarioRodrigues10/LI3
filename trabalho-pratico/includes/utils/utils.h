#ifndef UTILS_H
#define UTILS_H

/**
 * @brief The function will transform a string to int
 * 
 * @param c - The string to be transformed
 * 
 * @return int - The int value of the string
*/
int string_to_int(char*c);

/**
 * @brief The function will extract the number from a string
 * 
 * @param input - The string to be extracted
 * 
 * @return int - The number extracted from the string
*/
int extract_number(const char* input);
#endif