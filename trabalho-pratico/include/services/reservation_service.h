#ifndef RESERVATION_SERVICE_H
#define RESERVATION_SERVICE_H

#include "controllers/general_controller.h"
#include "controllers/reservation_controller.h"
#include "controllers/user_controller.h"
#include "models/reservation.h"
#include "stats/user_stats.h"
#include "utils/utils.h"
#include "utils/validation.h"

/**
 * @brief Verifies if the input is valid.
 *
 * @param parameters Parameters of type 'char**'.
 * @param users_data Pointer to the UsersData struct.
 *
 * @returns 1 if the input is valid, 0 otherwise.
 *
 */
int verify_reservation_input(char **parameters, UsersData *users_data);

/**
 * @brief Constructs a reservation.
 *
 * @param parameters Parameters of type 'char**'.
 * @param reservations_data Pointer to the ReservationsData struct.
 * @param users_data Pointer to the UsersData struct.
 * @param errors_file The file to put the wrong lines.
 *
 */
void construct_reservation(char **parameters,
                           ReservationsData *reservations_data,
                           UsersData *users_data, GeneralData *general_data,
                           FILE *errors_file);

#endif
