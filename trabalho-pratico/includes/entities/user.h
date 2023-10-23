#ifndef USER_H
#define USER_H

typedef struct user *User;

/**
 * @brief Verifies if the parameters are valid to create a new user (id, name,
 * email, phone_number, birth_date, sex , passport, country_code, address,
 * account_creation, pay_method, account_status)
 *
 * @param parameters - The parameters of type 'char**'
 */
int verify_flight_input(char **parameters);

/**
 * @brief Create a new user
 *
 * @return new_user - The new user of type 'User'
 */
User create_user();

/**
 * @brief Set the user id
 *
 * @param user - The user of type 'User'
 * @param id - The id string of type 'char*'
 */
void set_user_id(User user, char *id);

/**
 * @brief Set the user name
 *
 * @param user - The user of type 'User'
 * @param name - The name string of type 'char*'
 */
void set_user_name(User user, char *name);

/**
 * @brief Set the user email
 *
 * @param user - The user of type 'User'
 * @param email - The email string of type 'char*'
 */
void set_user_email(User user, char *email);

/**
 * @brief Set the user phone number
 *
 * @param user - The user of type 'User'
 * @param phone_number - The phone number string of type 'char*'
 */
void set_user_phone_number(User user, char *phone_number);

/**
 * @brief Set the user email
 *
 * @param user - The user of type 'User'
 * @param email - The email string of type 'char*'
 */
void set_user_birth_date(User user, char *birth_date);

/**
 * @brief Set the user sex
 *
 * @param user - The user of type 'User'
 * @param sex - The sex string of type 'char*'
 */
void set_user_sex(User user, char *sex);

/**
 * @brief Set the user passport
 *
 * @param user - The user of type 'User'
 * @param passport - The passport string of type 'char*'
 */
void set_user_passport(User user, char *passport);

/**
 * @brief Set the user country code
 *
 * @param user - The user of type 'User'
 * @param country_code - The country code string of type 'char*'
 */
void set_user_country_code(User user, char *country_code);

/**
 * @brief Set the user address
 *
 * @param user - The user of type 'User'
 * @param address - The address string of type 'char*'
 */
void set_user_address(User user, char *address);

/**
 * @brief Set the user account creation
 *
 * @param user - The user of type 'User'
 * @param account_creation - The account creation string of type 'char*'
 */
void set_user_account_creation(User user, char *account_creation);

/**
 * @brief Set the user pay method
 *
 * @param user - The user of type 'User'
 * @param pay_method - The pay method string of type 'char*'
 */
void set_user_pay_method(User user, char *pay_method);

/**
 * @brief Set the user account status
 *
 * @param user - The user of type 'User'
 * @param account_status - The account status string of type 'char*'
 */
void set_user_account_status(User user, char *account_status);

/**
 * @brief Frees the memory allocated to store a user
 *
 * @param user - The user of type 'User'
 */
void free_user(User user);

/**
 * @brief Get the user id
 *
 * @param user - The user of type 'User'
 * @return id - The id integer of type 'int'
 */
int get_user_id(User user);

/**
 * @brief Get the user name
 *
 * @param user - The user of type 'User'
 * @return name - The name string of type 'char*'
 */
char *get_user_name(User user);

/**
 * @brief Get the user email
 *
 * @param user - The user of type 'User'
 * @return email - The email string of type 'char*'
 */
char *get_user_email(User user);

/**
 * @brief Get the user phone number
 *
 * @param user - The user of type 'User'
 * @return phone_number - The phone number string of type 'char*'
 */
char *get_user_phone_number(User user);

/**
 * @brief Get the user email
 *
 * @param user - The user of type 'User'
 * @return email - The email string of type 'char*'
 */
char *get_user_birth_date(User user);

/**
 * @brief Get the user sex
 *
 * @param user - The user of type 'User'
 * @return sex - The sex string of type 'char*'
 */
char *get_user_sex(User user);

/**
 * @brief Get the user passport
 *
 * @param user - The user of type 'User'
 * @return passport - The passport string of type 'char*'
 */
char *get_user_passport(User user);

/**
 * @brief Get the user country code
 *
 * @param user - The user of type 'User'
 * @return country_code - The country code string of type 'char*'
 */
char *get_user_country_code(User user);

/**
 * @brief Get the user address
 *
 * @param user - The user of type 'User'
 * @return address - The address string of type 'char*'
 */
char *get_user_address(User user);

/**
 * @brief Get the user account creation
 *
 * @param user - The user of type 'User'
 * @return account_creation - The account creation string of type 'char*'
 */
char *get_user_account_creation(User user);

/**
 * @brief Get the user pay method
 *
 * @param user - The user of type 'User'
 * @return pay_method - The pay method string of type 'char*'
 */
char *get_user_pay_method(User user);

/**
 * @brief Get the user account status
 *
 * @param user - The user of type 'User'
 * @return account_status - The account status string of type 'char*'
 */
char *get_user_account_status(User user);

#endif
