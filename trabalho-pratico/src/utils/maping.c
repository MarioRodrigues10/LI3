#include "utils/maping.h"

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct maping {
  GHashTable *string_to_char;
  GHashTable *char_to_string;
};

Maping *maping_init() {
  Maping *map = malloc(sizeof(Maping));

  map->string_to_char =
      g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);
  map->char_to_string =
      g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, g_free);

  return map;
}

char string_to_char(Maping *map, const char *str) {
  gpointer char_value = g_hash_table_lookup(map->string_to_char, str);

  if (char_value != NULL) {
    return GPOINTER_TO_INT(char_value);
  }

  char new_char = g_hash_table_size(map->char_to_string);

  g_hash_table_insert(map->string_to_char, g_strdup(str),
                      GINT_TO_POINTER(new_char));
  g_hash_table_insert(map->char_to_string, GINT_TO_POINTER(new_char),
                      g_strdup(str));

  return new_char;
}

char *char_to_string(Maping *map, char ch) {
  gpointer str_value =
      g_hash_table_lookup(map->char_to_string, GINT_TO_POINTER(ch));

  if (str_value != NULL) {
    return g_strdup(str_value);
  }

  return NULL;
}

void maping_free(Maping *map) {
  g_hash_table_destroy(map->string_to_char);
  g_hash_table_destroy(map->char_to_string);
  free(map);
}
