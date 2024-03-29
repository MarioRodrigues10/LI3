#ifndef PARSER_SERVICE_H
#define PARSER_SERVICE_H

#include "controllers/flight_controller.h"
#include "controllers/general_controller.h"
#include "controllers/passenger_controller.h"
#include "controllers/reservation_controller.h"
#include "controllers/user_controller.h"
#include "services/flight_service.h"
#include "services/passenger_service.h"
#include "services/reservation_service.h"
#include "services/user_service.h"
#include "utils/maping.h"

#define SEPARATOR ";"
#define MAX_LINE_LENGTH 16384  // 16KB which means 16 * 1024

#define MAX_TOKENS 14

/**
 * @brief Parse a line into tokens.
 *
 * @param line The line to be parsed.
 * @param tokens The place where to place the tokens.
 * @param num_tokens The number of tokens to be parsed.
 *
 * @return The number of tokens.
 */
int parse_line(char* line, char* tokens[], int num_tokens);

/**
 * @brief Parses a file.
 *
 * @param file The file to be parsed.
 * @param errors_file The file to put wrong lines.
 * @param flights_data The flights data.
 * @param reservations_data The reservations data.
 * @param users_data The users data.
 * @param stats_user_info The stats user info.
 * @param type The type of the struct.
 * @param map Map of type 'Maping*'.
 *
 * @return The number of lines parsed.
 */
int parse_file(FILE* file, FILE* errors_file, FlightsData* flights_data,
               GeneralData* general_data, ReservationsData* reservations_data,
               UsersData* users_data, StatsUserInfo* stats_user_info,
               Maping* map, int type);

#endif
