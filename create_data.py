import csv

data = [
    ['0', 'Numar Cristi', 'number', '24'],
    ['1', 'Numar Robert', 'number', '23'],
    ['2', 'Numar Gr', 'number', '27'],
    ['3', 'Culoare Cristi', 'text', 'verde'],
    ['4', 'Culoare Robert', 'text', 'albastru'],
    ['5', 'Culoare Gr', 'text', 'rosu'],
    ['6', 'Exemplu Cristi', 'complex', '5 23'],
    ['7', 'Exemplu Robert', 'complex', '3 7'],
    ['8', 'Exemplu Gr', 'complex', '2 5'],
    ['9', 'Adresa Cristi', 'address', 'Romania Dolj Craiova Surcele 6'],
    ['10', 'Adresa Robert', 'address', 'Romania Dolj Craiova Stefan cel mare 19'],
    ['11', 'Adresa Gr', 'address', 'Romania Dolj Craiova Brazda 24']
]

file_path = './data.csv'

with open(file_path, 'w', newline='') as file:
    writer = csv.writer(file)
    writer.writerows(data)

print('Data has been written to the CSV file.')