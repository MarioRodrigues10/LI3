#ifndef UTILS_H
#define UTILS_H

/**
 * @brief Converts a string to an integer.
 * 
 * @param c The string to be converted.
 * 
 * @return The integer value of the string.
 * 
*/
int string_to_int(char* c);

/**
 * @brief Extracts a number from a string.
 * 
 * @param input The string to be extracted.
 * 
 * @return The number extracted from the string.
 * 
*/
int extract_number(char* input);
#endif