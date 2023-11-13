#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <stdio.h>

typedef void (*file_output_function_pointer)(FILE *file, void *result);

/**
 * @brief Wrapper function that writes the given query result of a query to a
 * file
 *
 * @param output_file - The file of type `FILE *` where the result will be
 * written
 * @param result - The result of type `void *` that will be written to the file
 * @param query_type - The query type of type `char` that will be written to the
 * file
 */
void write_query_result(FILE *output_file, void *result, char query_type);

/**
 * @brief Function that writes the result of the query one result to a file
 *
 * @param output_file - The file of type `FILE *` where the result will be
 * written
 * @param result - The result of type `void *` that will be written to the file
 */
void write_query1_result(FILE *output_file, void *result);

/**
 * @brief Function that writes the result of the query one result to a file
 *
 * @param output_file - The file of type `FILE *` where the result will be
 * written
 * @param result - The result of type `void *` that will be written to the file
 */
void write_query2_result(FILE *output_file, void *result);

/**
 * @brief Function that writes the result of the query one result to a file
 *
 * @param output_file - The file of type `FILE *` where the result will be
 * written
 * @param result - The result of type `void *` that will be written to the file
 */
void write_query3_result(FILE *output_file, void *result);

/**
 * @brief Function that writes the result of the query one result to a file
 *
 * @param output_file - The file of type `FILE *` where the result will be
 * written
 * @param result - The result of type `void *` that will be written to the file
 */
void write_query4_result(FILE *output_file, void *result);

/**
 * @brief Function that writes the result of the query one result to a file
 *
 * @param output_file - The file of type `FILE *` where the result will be
 * written
 * @param result - The result of type `void *` that will be written to the file
 */
void write_query5_result(FILE *output_file, void *result);

/**
 * @brief Function that writes the result of the query one result to a file
 *
 * @param output_file - The file of type `FILE *` where the result will be
 * written
 * @param result - The result of type `void *` that will be written to the file
 */
void write_query6_result(FILE *output_file, void *result);

/**
 * @brief Function that writes the result of the query one result to a file
 *
 * @param output_file - The file of type `FILE *` where the result will be
 * written
 * @param result - The result of type `void *` that will be written to the file
 */
void write_query7_result(FILE *output_file, void *result);

/**
 * @brief Function that writes the result of the query one result to a file
 *
 * @param output_file - The file of type `FILE *` where the result will be
 * written
 * @param result - The result of type `void *` that will be written to the file
 */
void write_query8_result(FILE *output_file, void *result);

/**
 * @brief Function that writes the result of the query one result to a file
 *
 * @param output_file - The file of type `FILE *` where the result will be
 * written
 * @param result - The result of type `void *` that will be written to the file
 */
void write_query9_result(FILE *output_file, void *result);

/**
 * @brief Function that writes the result of the query one result to a file
 *
 * @param output_file - The file of type `FILE *` where the result will be
 * written
 * @param result - The result of type `void *` that will be written to the file
 */
void write_query10_result(FILE *output_file, void *result);

#endif
