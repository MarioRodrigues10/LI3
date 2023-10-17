
#define MAX_FIELD_SIZE 256
#define MAX_RECORDS 1000

typedef struct Flight {
  long long int id;
  char airline[MAX_FIELD_SIZE];
  char plane_model[MAX_FIELD_SIZE];
  int total_seats;
  char origin[MAX_FIELD_SIZE];
  char destination[MAX_FIELD_SIZE];
  char schedule_departure_date[MAX_FIELD_SIZE];
  char schedule_arrival_date[MAX_FIELD_SIZE];
  char real_departure_date[MAX_FIELD_SIZE];
  char real_arrival_date[MAX_FIELD_SIZE];
  char pilot[MAX_FIELD_SIZE];
  char copilot[MAX_FIELD_SIZE];
  char notes[MAX_FIELD_SIZE];
  struct Flight* next;
} Flight;

typedef struct Passenger {
  long long int flight_id;
  char user_id[MAX_FIELD_SIZE];
  struct Passenger* next;
} Passenger;

typedef struct Reservation {
  char id[MAX_FIELD_SIZE];
  char user_id[MAX_FIELD_SIZE];
  char hotel_id[MAX_FIELD_SIZE];
  char hotel_name[MAX_FIELD_SIZE];
  int hotel_stars;
  double city_tax;
  char address[MAX_FIELD_SIZE];
  char begin_date[MAX_FIELD_SIZE];
  char end_date[MAX_FIELD_SIZE];
  int price_per_night;
  int includes_breakfast;
  char room_details[MAX_FIELD_SIZE];
  int rating;
  char comment[MAX_FIELD_SIZE];
  struct Reservation* next;
} Reservation;

typedef struct User {
  char id[MAX_FIELD_SIZE];
  char name[MAX_FIELD_SIZE];
  char email[MAX_FIELD_SIZE];
  char phone_number[MAX_FIELD_SIZE];
  char birth_date[MAX_FIELD_SIZE];
  char sex[MAX_FIELD_SIZE];
  char passport[MAX_FIELD_SIZE];
  char country_code[MAX_FIELD_SIZE];
  char address[MAX_FIELD_SIZE];
  char account_creation[MAX_FIELD_SIZE];
  char pay_method[MAX_FIELD_SIZE];
  char account_status[MAX_FIELD_SIZE];
  struct User* next;
} User;

int isLineValid(char* line, char* pattern);

Flight* parse_flights(char* filename);

Passenger* parse_passengers(char* filename);

Reservation* parse_reservations(char* filename);

User* parse_users(char* filename);
void free_users(User* users);