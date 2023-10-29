#ifndef USERS_H
#define USERS_H

#define MAX_FIELD_SIZE 256
#define MAX_TOKENS_USER 12
typedef struct user *USER;

/**
 * @brief Function that verifies if the parameters are valid to create a new
 * user (id, name, email, phone_number, birth_date, sex , passport,
 * country_code, address, account_creation, pay_method, account_status)
 *
 * @param parameters - The parameters of type 'char**'
 */
int verify_flight_input(char **parameters);

/**
 * @brief Function that creates a new user
 *
 * @return new_user - The new user of type 'USER'
 */
USER create_user();

/**
 * @brief Function that sets the user id
 *
 * @param user - The user of type 'USER'
 * @param id - The id string of type 'char*'
 */
void set_user_id(USER user, char *id);

/**
 * @brief Function that sets the user name
 *
 * @param user - The user of type 'USER'
 * @param name - The name string of type 'char*'
 */
void set_user_name(USER user, char *name);

/**
 * @brief Function that sets the user email
 *
 * @param user - The user of type 'USER'
 * @param email - The email string of type 'char*'
 */
void set_user_email(USER user, char *email);

/**
 * @brief Function that sets the user phone number
 *
 * @param user - The user of type 'USER'
 * @param phone_number - The phone number string of type 'char*'
 */
void set_user_phone_number(USER user, char *phone_number);

/**
 * @brief Function that sets the user email
 *
 * @param user - The user of type 'USER'
 * @param email - The email string of type 'char*'
 */
void set_user_birth_date(USER user, char *birth_date);

/**
 * @brief Function that sets the user sex
 *
 * @param user - The user of type 'USER'
 * @param sex - The sex string of type 'char*'
 */
void set_user_sex(USER user, char *sex);

/**
 * @brief Function that sets the user passport
 *
 * @param user - The user of type 'USER'
 * @param passport - The passport string of type 'char*'
 */
void set_user_passport(USER user, char *passport);

/**
 * @brief Function that sets the user country code
 *
 * @param user - The user of type 'USER'
 * @param country_code - The country code string of type 'char*'
 */
void set_user_country_code(USER user, char *country_code);

/**
 * @brief Function that sets the user address
 *
 * @param user - The user of type 'USER'
 * @param address - The address string of type 'char*'
 */
void set_user_address(USER user, char *address);

/**
 * @brief Function that sets the user account creation
 *
 * @param user - The user of type 'USER'
 * @param account_creation - The account creation string of type 'char*'
 */
void set_user_account_creation(USER user, char *account_creation);

/**
 * @brief Function that sets the user pay method
 *
 * @param user - The user of type 'USER'
 * @param pay_method - The pay method string of type 'char*'
 */
void set_user_pay_method(USER user, char *pay_method);

/**
 * @brief Set the user account status
 *
 * @param user - The user of type 'USER'
 * @param account_status - The account status string of type 'char*'
 */
void set_user_account_status(USER user, char *account_status);

/**
 * @brief Function that frees the memory allocated to store a user
 *
 * @param user - The user of type 'USER'
 */
void free_user(USER user);

/**
 * @brief Get the user id
 *
 * @param user - The user of type 'USER'
 *
 * @return id - The id integer of type 'int'
 */
int get_user_id_from_user(USER user);

/**
 * @brief Function that gets the user name
 *
 * @param user - The user of type 'USER'
 *
 * @return name - The name string of type 'char*'
 */
char *get_user_name(USER user);

/**
 * @brief Function that gets the user email
 *
 * @param user - The user of type 'USER'
 *
 * @return email - The email string of type 'char*'
 */
char *get_user_email(USER user);

/**
 * @brief Function that gets the user phone number
 *
 * @param user - The user of type 'USER'
 *
 * @return phone_number - The phone number string of type 'char*'
 */
char *get_user_phone_number(USER user);

/**
 * @brief Function that gets the user email
 *
 * @param user - The user of type 'USER'
 *
 * @return email - The email string of type 'char*'
 */
char *get_user_birth_date(USER user);

/**
 * @brief Function that gets the user sex
 *
 * @param user - The user of type 'USER'
 *
 * @return sex - The sex string of type 'char*'
 */
char *get_user_sex(USER user);

/**
 * @brief Function that gets the user passport
 *
 * @param user - The user of type 'USER'
 *
 * @return passport - The passport string of type 'char*'
 */
char *get_user_passport(USER user);

/**
 * @brief Function that gets the user country code
 *
 * @param user - The user of type 'USER'
 *
 * @return country_code - The country code string of type 'char*'
 */
char *get_user_country_code(USER user);

/**
 * @brief Function that gets the user address
 *
 * @param user - The user of type 'USER'
 *
 * @return address - The address string of type 'char*'
 */
char *get_user_address(USER user);

/**
 * @brief Function that gets the user account creation
 *
 * @param user - The user of type 'USER'
 *
 * @return account_creation - The account creation string of type 'char*'
 */
char *get_user_account_creation(USER user);

/**
 * @brief Function that gets the user pay method
 *
 * @param user - The user of type 'USER'
 *
 * @return pay_method - The pay method string of type 'char*'
 */
char *get_user_pay_method(USER user);

/**
 * @brief Function that gets the user account status
 *
 * @param user - The user of type 'USER'
 *
 * @return account_status - The account status string of type 'char*'
 */
char *get_user_account_status(USER user);

#endif
