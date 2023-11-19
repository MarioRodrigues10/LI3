#ifndef USER_H
#define USER_H

#define MAX_TOKENS_USER 12

typedef struct user UserInfo;

/**
 * @brief Allocates the memory necessary to create a new user.
 *
 * @return UserInfo pointer of type 'UserInfo*' to the allocated memory.
 */
UserInfo *create_user();

/**
 * @brief Sets the user id of a user.
 *
 * @param user UserInfo pointer of type 'UserInfo*'.
 * @param user_id User id of type 'char*'.
 */
void set_user_id(UserInfo *user, char *user_id);

/**
 * @brief Sets the name of a user.
 *
 * @param user UserInfo pointer of type 'UserInfo*'.
 * @param name Name of type 'char*'.
 */
void set_name(UserInfo *user, char *name);

/**
 * @brief Sets the birth date of a user.
 *
 * @param user UserInfo pointer of type 'UserInfo*'.
 * @param birth_date Birth date of type 'char*'.
 */
void set_birth_date(UserInfo *user, char *birth_date);

/**
 * @brief Sets the sex of a user.
 *
 * @param user UserInfo pointer of type 'UserInfo*'.
 * @param sex Sex of type 'char*'.
 */
void set_sex(UserInfo *user, char *sex);

/**
 * @brief Sets the passport of a user.
 *
 * @param user UserInfo pointer of type 'UserInfo*'.
 * @param passport Passport of type 'char*'.
 */
void set_passport(UserInfo *user, char *passport);

/**
 * @brief Sets the country code of a user.
 *
 * @param user UserInfo pointer of type 'UserInfo*'.
 * @param country_code Country code of type 'char*'.
 */
void set_country_code(UserInfo *user, char *country_code);

/**
 * @brief Sets the account status of a user.
 *
 * @param user UserInfo pointer of type 'UserInfo*'.
 * @param account_status Account status of type 'char*'.
 */
void set_account_creation(UserInfo *user, char *account_creation);

/**
 * @brief Sets the account creation of a user.
 *
 * @param user UserInfo pointer of type 'UserInfo*'.
 * @param account_creation Account creation of type 'char*'.
 */
void set_account_status(UserInfo *user, char *account_status);

/**
 * @brief Gets the user id of a user.
 *
 * @param user UserInfo pointer of type 'UserInfo*'.
 * @return char pointer of type 'char*'.
 */
char *get_user_id(UserInfo *user);

/**
 * @brief Gets the name of a user.
 *
 * @param user UserInfo pointer of type 'UserInfo*'.
 * @return char pointer of type 'char*'.
 */
char *get_name(UserInfo *user);

/**
 * @brief Gets the birth date of a user.
 *
 * @param user UserInfo pointer of type 'UserInfo*'.
 * @return char pointer of type 'char*'.
 */
char *get_birth_date(UserInfo *user);

/**
 * @brief Gets the sex of a user.
 *
 * @param user UserInfo pointer of type 'UserInfo*'.
 * @return char pointer of type 'char*'.
 */
char *get_sex(UserInfo *user);

/**
 * @brief Gets the passport of a user.
 *
 * @param user UserInfo pointer of type 'UserInfo*'.
 * @return char pointer of type 'char*'.
 */
char *get_passport(UserInfo *user);

/**
 * @brief Gets the country code of a user.
 *
 * @param user UserInfo pointer of type 'UserInfo*'.
 * @return char pointer of type 'char*'.
 */
char *get_country_code(UserInfo *user);

/**
 * @brief Gets the account creation of a user.
 *
 * @param user UserInfo pointer of type 'UserInfo*'.
 * @return char pointer of type 'char*'.
 */
char *get_account_creation(UserInfo *user);

/**
 * @brief Gets the account status of a user.
 *
 * @param user UserInfo pointer of type 'UserInfo*'.
 * @return char pointer of type 'char*'.
 */
char *get_account_status(UserInfo *user);

/**
 * @brief Frees the memory allocated to a user.
 *
 * @param user UserInfo pointer of type 'UserInfo*'.
 */
void destroy_user(UserInfo *user);

#endif
