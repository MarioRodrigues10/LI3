#ifndef PARSER_SERVICE_H
#define PARSER_SERVICE_H

#include <stdio.h>

#include "controllers/flight_controller.h"
#include "controllers/passenger_controller.h"
#include "controllers/reservation_controller.h"
#include "controllers/user_controller.h"
#include "services/flight_service.h"
#include "services/passenger_service.h"
#include "services/reservation_service.h"
#include "services/user_service.h"

#define SEPARATOR ";"
#define MAX_LINE_LENGTH 16384  // 16KB which means 16 * 1024

/**
 * @brief Parse a line into tokens.
 *
 * @param line The line to be parsed.
 * @param num_tokens The number of tokens to be parsed.
 *
 * @return The tokens.
 */
char** parse_line(char* line, int num_tokens);

/**
 * @brief Free the tokens.
 *
 * @param tokens The tokens to be freed.
 * @param num_tokens The number of tokens to be freed.
 */
void free_tokens(char** tokens, int num_tokens);

/**
 * @brief Parses a file.
 *
 * @param file The file to be parsed.
 * @param errors_file The file to put wrong lines.
 * @param flights_data The flights data.
 * @param passengers_data The passengers data.
 * @param reservations_data The reservations data.
 * @param users_data The users data.
 * @param stats_user_info The stats user info.
 * @param type The type of the struct.
 * @param num_tokens The number of tokens to be parsed.
 *
 * @return The number of lines parsed.
 */
int parse_file(FILE* file, FILE* errors_file, FlightsData* flights_data,
               PassengersData* passengers_data,
               ReservationsData* reservations_data, UsersData* users_data,
               StatsUserInfo* stats_user_info, int type, int num_tokens);

#endif
