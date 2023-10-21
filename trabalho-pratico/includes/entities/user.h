#ifndef USER_H
#define USER_H

typedef struct user *User; 

/**
 * @brief Creat a new user
 * 
 * @return new_user - The new user of type 'User' 
 */
User creat_user();

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
void set_user_sex(User user ,char *sex);

/**
 * @brief Set the user passport
 * 
 * @param user - The user of type 'User'
 * @param passport - The passport string of type 'char*'
 */
void set_user_passport(User user , char *passport);

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
void set_user_address(User user ,char *address);

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
void set_user_pay_method(User user , char *pay_method);

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

#endif
