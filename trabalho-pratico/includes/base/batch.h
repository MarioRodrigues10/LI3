#ifndef BATCH_H
#define BATCH_H

#include "base/query_manager.h"
#include "catalogs/flights_catalog.h"
#include "catalogs/passengers_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "catalogs/users_catalog.h"
#include "io/parser.h"
#include "utils/utils.h"

/**
 * @brief Function to execute batch mode
 *
 * @param argv the command line arguments
 *
 * @return 0 if success, -1 if fail
 */
int batch(char **argv);

#endif