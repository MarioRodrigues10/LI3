import argparse
import string
import random

# Listas de dados para gerar os CSV
users = []
flights = []
passengers = []
reservations = []

# Dados de exemplo para os casos específicos
first_names = ['Joao', 'Maria', 'Jose', 'Ana', 'Manuel', 'Rita', 'Carlos', 'Sofia', 'Pedro', 'Ines']
last_names = ['Silva', 'Santos', 'Ferreira', 'Lopes', 'Pereira', 'Almeida', 'Rocha', 'Costa', 'Gomes', 'Martins']
cities = ['Lisboa', 'Porto', 'Coimbra', 'Braga', 'Faro', 'Setubal', 'Viseu', 'Aveiro', 'Braganca', 'Leiria']
alphanumeric_characters_list = list(string.ascii_uppercase + string.digits)

# Gerar uma data no formato YYYY/MM/DD HH:MM:SS
def generate_datetime():
    year = random.randint(2010, 2021)
    month = random.randint(1, 12)
    day = random.randint(1, 28)
    hour = random.randint(0, 23)
    minute = random.randint(0, 59)
    second = random.randint(0, 59)
    return f"{year:04d}/{month:02d}/{day:02d} {hour:02d}:{minute:02d}:{second:02d}"

# Gerar um ID único (número de 12 dígitos)
def generate_unique_id(existing_ids):
    while True:
        new_id = str(random.randint(1e11, 1e12 - 1))
        if new_id not in existing_ids:
            existing_ids.add(new_id)
            return new_id

# Gerar uma data no formato DD/MM/YYYY
def generate_date_of_birth():
    day = random.randint(1, 28)
    month = random.randint(1, 12)
    year = random.randint(1950, 2005)
    return f"{day:02d}/{month:02d}/{year}"

# Gerar um nome aleatório
def generate_random_name():
    return random.choice(first_names) + " " + random.choice(last_names)

# Escolher um elemento aleatório de uma lista
def choice(values):
    return random.choice(values)

# Escolher um elemento de uma lista com base em probabilidades
def choice_prob(options, probs):
    x = random.random()
    cum = 0
    index = 0

    for index, p in enumerate(probs):
        cum += p
        if x < cum:
            break
    return options[index]

# Gerar uma cidade aleatória
def generate_random_city():
    return random.choice(cities)

# Gerar um código de país aleatório
def generate_random_country_code():
    return choice(["PT", "FR", "EN", "ES"])

# Geração de arquivo CSV para utilizadores
def generate_users_csv(filename, num_users):
    with open(filename, 'w') as f:
        f.write('id;name;email;phone_number;birth_date;sex;passport;country_code;address;account_creation;pay_method;account_status\n')
        user_ids = set()
        for i in range(num_users):
            user_id = generate_unique_id(user_ids)
            user_name = generate_random_name()
            user_email = f"{user_name.lower().replace(' ', '.')}@example.com"
            user_phone = f"+1-{random.randint(100, 999)}-{random.randint(100, 999)}-{random.randint(1000, 9999)}"
            user_birth_date = generate_date_of_birth()
            user_sex = choice(["M", "F"])
            user_passport = ''.join(random.choices(string.ascii_uppercase + string.digits, k=8))
            user_country_code = generate_random_country_code() 
            user_address = f"{random.randint(1, 100)} {generate_random_city()}, {user_country_code}"
            account_creation = generate_datetime()
            pay_method = choice(['cash', 'debit_card', 'credit_card'])
            account_status = choice_prob(['active', 'inactive'], probs=[0.99, 0.01])
            user_data = [user_id, user_name, user_email, user_phone, user_birth_date, user_sex, user_passport,
                         user_country_code, user_address, account_creation, pay_method, account_status]
            users.append(user_data)
            f.write(";".join(str(item) for item in user_data) + "\n")

# Geração de arquivo CSV para voos
def generate_flights_csv(filename, num_flights):
    with open(filename, 'w') as f:
        f.write('id;airline;plane_model;total_seats;origin;destination;schedule_departure_date;schedule_arrival_date;real_departure_date;real_arrival_date;pilot;copilot;notes\n')
        flight_ids = set()
        for i in range(num_flights):
            flight_id = generate_unique_id(flight_ids)
            airline = choice(["OPO", "ABB", "DEP"])
            plane_model = choice(["Boeing 737", "Airbus A320", "Boeing 777"])
            total_seats = random.randint(100, 300)
            origin = generate_random_city()
            destination = generate_random_city()
            while destination == origin:
                destination = generate_random_city()
            schedule_departure_date = generate_datetime()
            schedule_arrival_date = generate_datetime()
            real_departure_date = generate_datetime()
            real_arrival_date = generate_datetime()
            pilot = generate_random_name()
            copilot = generate_random_name()
            notes = choice(["On time", "Delayed", "Cancelled"])
            flight_data = [flight_id, airline, plane_model, total_seats, origin, destination, schedule_departure_date,
                           schedule_arrival_date, real_departure_date, real_arrival_date, pilot, copilot, notes]
            flights.append(flight_data)
            f.write(";".join(str(item) for item in flight_data) + "\n")

# Geração de arquivo CSV para passageiros
def generate_passengers_csv(filename):
    with open(filename, 'w') as f:
        f.write('flight_id;user_id\n')
        for flight in flights:
            flight_id = flight[0]
            for _ in range(random.randint(1, 5)):
                user_id = random.choice(users)[0]
                passenger_data = [flight_id, user_id]
                passengers.append(passenger_data)
                f.write(";".join(str(item) for item in passenger_data) + "\n")

# Geração de arquivo CSV para reservas
def generate_reservations_csv(filename, num_reservations):
    with open(filename, 'w') as f:
        f.write('id;user_id;hotel_id;hotel_name;hotel_stars;city_tax;address;begin_date;end_date;price_per_night;includes_breakfast;room_details;rating;comment\n')
        reservation_ids = set()
        for i in range(num_reservations):
            reservation_id = generate_unique_id(reservation_ids)
            user_id = random.choice(users)[0]
            hotel_id = random.randint(1, 1000)
            hotel_name = f"Hotel {hotel_id}"
            hotel_stars = random.randint(1, 5)
            city_tax = random.uniform(0, 0.2)
            address = f"{random.randint(1, 100)} {generate_random_city()}, {generate_random_country_code()}"
            begin_date = generate_datetime()
            end_date = generate_datetime()
            price_per_night = random.randint(50, 300)
            includes_breakfast = random.choice([True, False])
            room_details = choice(["Single", "Double", "Suite"])
            rating = random.randint(1, 5)
            comment = choice(["Great stay!", "Terrible service", "Average experience"])
            reservation_data = [reservation_id, user_id, hotel_id, hotel_name, hotel_stars, city_tax, address, begin_date,
                                end_date, price_per_night, includes_breakfast, room_details, rating, comment]
            reservations.append(reservation_data)
            f.write(";".join(str(item) for item in reservation_data) + "\n")

# Funções para gerar os CSV e input de tamanho dos DataSets
if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-users-size', help='Number of lines of users.csv')
    parser.add_argument('-flights-size', help='Number of lines of flights.csv')
    parser.add_argument('-passengers-size', help='Number of passengers per flight')
    parser.add_argument('-reservations-size', help='Number of lines of reservations.csv')
    parser.add_argument('-output-dir', help='Output directory')
    args = parser.parse_args()

    users_size = int(args.users_size)
    flights_size = int(args.flights_size)
    passengers_size = int(args.passengers_size)
    reservations_size = int(args.reservations_size)
    output_dir = args.output_dir

    generate_users_csv(output_dir + '/users.csv', users_size)
    generate_flights_csv(output_dir + '/flights.csv', flights_size)
    generate_passengers_csv(output_dir + '/passengers.csv')
    generate_reservations_csv(output_dir + '/reservations.csv', reservations_size)
    
    print("Ficheiros gerados com sucesso.")
