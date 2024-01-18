#include "services/queries/query9.h"

void write_query9(bool has_f, FILE *output_file, char **user_ids,
                  char **user_names, int N) {
  if (has_f) {
    for (int i = 0; i < N; i++) {
      if (i != 0) fprintf(output_file, "\n");
      fprintf(output_file, "--- %d ---\nid: %s\nname: %s\n", i + 1, user_ids[i],
              user_names[i]);
    }
  } else {
    for (int i = 0; i < N; i++) {
      fprintf(output_file, "%s;%s\n", user_ids[i], user_names[i]);
    }
  }
}

struct user_info {
  char *user_id;
  char *user_name;
};

int compare(const void *a, const void *b) {
  const UserInfoStats *user_a = *(const UserInfoStats **)a;
  const UserInfoStats *user_b = *(const UserInfoStats **)b;

  g_assert(user_a->user_name[strlen(user_a->user_name)] == '\0');
  g_assert(user_b->user_name[strlen(user_b->user_name)] == '\0');
  g_assert(user_a->user_id[strlen(user_a->user_id)] == '\0');
  g_assert(user_b->user_id[strlen(user_b->user_id)] == '\0');

  int nameComparison = strcmp(user_a->user_name, user_b->user_name);
  if (nameComparison != 0) {
    return nameComparison;
  } else {
    return strcmp(user_a->user_id, user_b->user_id);
  }
}

int check_prefix(const void *a, const void *b) {
  const UserInfoStats *user = *(const UserInfoStats **)a;
  const char *prefix = b;

  return strncmp(user->user_name, prefix, strlen(prefix));
}

int compare_respond(const void *a, const void *b) {
  setlocale(LC_COLLATE, "en_US.UTF-8");
  const UserInfoStats *user_a = *(const UserInfoStats **)a;
  const UserInfoStats *user_b = *(const UserInfoStats **)b;

  // Ensure null termination
  g_assert(user_a->user_name[strlen(user_a->user_name)] == '\0');
  g_assert(user_b->user_name[strlen(user_b->user_name)] == '\0');
  g_assert(user_a->user_id[strlen(user_a->user_id)] == '\0');
  g_assert(user_b->user_id[strlen(user_b->user_id)] == '\0');

  int nameComparison = strcoll(user_a->user_name, user_b->user_name);
  if (nameComparison != 0) {
    return nameComparison;
  } else {
    return strcoll(user_a->user_id, user_b->user_id);
  }
}

void query9(bool has_f, char **query_parameters, UsersData *users_data,
            StatsUserInfo *users_stats, FILE *output_file, int num_parameters) {
  if (query_parameters[0] == NULL) return;
  char *prefix = create_prefix(query_parameters, num_parameters);

  if (prefix == NULL) return;

  GArray *stats_user = get_stats_user_info(users_stats);
  if (stats_user == NULL) return;

  GArray *respond = g_array_new(FALSE, FALSE, sizeof(UserInfoStats *));

  for (guint i = 0; i < stats_user->len; i++) {
    UserInfoStats *user = g_array_index(stats_user, UserInfoStats *, i);

    if (strncmp(get_user_name_from_user_info(user), prefix, strlen(prefix)) ==
            0 &&
        get_account_status(get_user_by_username(
            users_data, get_user_id_from_user_info(user)))) {
      g_array_append_val(respond, user);
    }
  }

  g_array_sort(respond, (GCompareFunc)compare_respond);

  if (has_f) {
    for (int i = 0; i < (int)respond->len; i++) {
      UserInfoStats *user = g_array_index(respond, UserInfoStats *, i);
      if (i != 0) fprintf(output_file, "\n");
      fprintf(output_file, "--- %d ---\nid: %s\nname: %s\n", i + 1,
              get_user_id_from_user_info(user),
              get_user_name_from_user_info(user));
    }
  } else {
    for (int i = 0; i < (int)respond->len; i++) {
      UserInfoStats *user = g_array_index(respond, UserInfoStats *, i);
      fprintf(output_file, "%s;%s\n", get_user_id_from_user_info(user),
              get_user_name_from_user_info(user));
    }
  }

  g_array_free(respond, TRUE);
}
