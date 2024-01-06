#ifndef FEEDER_SERVICE_H
#define FEEDER_SERVICE_H

#include "controllers/flight_controller.h"
#include "controllers/general_controller.h"
#include "controllers/passenger_controller.h"
#include "controllers/reservation_controller.h"
#include "controllers/user_controller.h"
#include "models/flight.h"
#include "models/passenger.h"
#include "models/reservation.h"
#include "models/user.h"
#include "services/parser_service.h"

#define NUM_FILES 4

#define FLIGHTS_FILENAME "/flights.csv"
#define FLIGHTS_ERROR_FILENAME "/flights_errors.csv"
#define PASSENGERS_FILENAME "/passengers.csv"
#define PASSENGERS_ERROR_FILENAME "/passengers_errors.csv"
#define RESERVATIONS_FILENAME "/reservations.csv"
#define RESERVATIONS_ERROR_FILENAME "/reservations_errors.csv"
#define USERS_FILENAME "/users.csv"
#define USERS_ERROR_FILENAME "/users_errors.csv"

/**
 * @brief Creates a filename.
 *
 * @param data_folder Data folder of type 'char*'.
 * @param input_file Input file of type 'char*'.
 *
 * @returns A string of type 'char*' with the name of the file.
 *
 */
char* create_filename(const char* data_folder, const char* name);

/**
 * @brief Frees the memory allocated for the filename.
 *
 * @param filename Filename of type 'char*'.
 *
 */
void free_filename(char* filename);

/**
 * @brief Opens the csv files.
 *
 * @param filenames Filenames of type 'char**'.
 * @param num_files Number of files of type 'int'.
 *
 * @returns An array of type 'FILE**' with the opened files.
 */
FILE** open_csv_files_read(char* filenames[], int num_files);

/**
 * @brief Opens the csv files.
 *
 * @param filenames Filenames of type 'char**'.
 * @param num_files Number of files of type 'int'.
 *
 * @returns An array of type 'FILE**' with the opened files.
 */
FILE** open_csv_files_write(char* filenames[], int num_files);

/**
 * @brief Closes the csv files.
 *
 * @param files Files of type 'FILE**'.
 * @param num_files Number of files of type 'int'.
 */
void close_csv_files(FILE** files, int num_files);

/**
 * @brief Feeds the data structures with the data from the input file.
 *
 * @param data_folder Data folder of type 'char*'.
 * @param flights_data Flights data of type 'FlightsData*'.
 * @param general_data General data of type 'GeneralData*'.
 * @param passengers_data Passengers data of type 'PassengersData*'.
 * @param reservations_data Reservations data of type 'ReservationsData*'.
 * @param users_data Users data of type 'UsersData*'.
 * @param users_stats Users stats of type 'StatsUserInfo*'.
 *
 */
void feeder(char* data_folder, FlightsData* flights_data,
            GeneralData* general_data, PassengersData* passengers_data,
            ReservationsData* reservations_data, UsersData* users_data,
            StatsUserInfo* users_stats);

#endif
