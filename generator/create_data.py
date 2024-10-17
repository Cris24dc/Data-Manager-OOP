import csv
from faker import Faker
import random

fake = Faker()

def generate_random_data(num_rows):
    data = []
    for i in range(num_rows):
        unique_id = str(i + 1)
        
        unique_name = fake.name()
        while any(unique_name in row for row in data):
            unique_name = fake.name()

        value_type = random.choice(['number', 'text', 'complex', 'address'])
        
        if value_type == 'number':
            value = str(random.randint(1, 100))
        elif value_type == 'text':
            value = fake.word()
        elif value_type == 'complex':
            value = ' '.join(str(random.randint(1, 100)) for _ in range(2))
        elif value_type == 'address':
            country = fake.country().replace(" ", "")
            county = fake.state().replace(" ", "")
            city = fake.city().replace(" ", "")
            street = fake.street_name().replace(" ", "")
            number = fake.building_number().replace(" ", "")
            value = f"{country} {county} {city} {street} {number}"

        data.append([unique_id, unique_name, value_type, value])
    
    return data

file_name = input("Enter file name: ")
file_path = f'./database/{file_name}.csv'
num_rows = int(input("Enter the number of values to generate: "))

data = generate_random_data(num_rows)

with open(file_path, 'w', newline='') as file:
    writer = csv.writer(file)
    writer.writerows(data)

print('Data has been written to the CSV file.')
