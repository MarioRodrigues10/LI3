#!/bin/bash

# ANSI color codes
RED='\033[0;31m'
RESET='\033[0m'

# Check if the ./programa-principal file exists
if [ -e "./programa-principal" ]; then
    # Create the GLib leak suppression file
    cat <<EOF > /tmp/glib_leak_suppression.supp
{
    glib_leak_suppression
    Memcheck:Leak
    fun:g_malloc
    fun:g_free
    fun:g_hash_table_new
    fun:g_hash_table_insert
    fun:g_hash_table_lookup
    fun:strdup
    fun:GPOINTER_TO_INT
    fun:GINT_TO_POINTER
}

EOF

    # Run Valgrind only if ./programa-principal exists
    valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high \
        --suppressions=/tmp/glib_leak_suppression.supp --log-file=/tmp/valgrind ./programa-principal

    # Display Valgrind log using the 'less' command
    cat /tmp/valgrind | less
else
    # Display a message if ./programa-principal does not exist
   echo -e "${RED}[Error]${RESET} Please run 'DEBUG=1 make' or 'make' first."
fi
