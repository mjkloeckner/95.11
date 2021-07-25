from string import digits
from time import strftime, gmtime
from random import randint, choice

LINES = 500000

# OUTPUT:
#     ID_TRANSACCION, ID_USUARIO, FECHA, MONTO, NUMERO DE TRAJETA, DESCRIPCION
#     123412,1,05/11/2011 10:00:00,-10,4916288217067475, Compra supermercado

descs = [ "Compras supermercado", "Pago tarjeta", "Compras libreria", "Pago Mecanico", "Pago Dentista", "Pago Servicios online", "Compras Ferreteria",  "Compras Accesorios Informatica", "Compras farmacia", "Ventas online", "Extraccion cajero" ]

def card_number_generator():
    return ''.join(choice(digits) for i in range(1, 16))

def generate_file(max_lines):
    id_transaction_base = 123400
    id_user_base = 1
    id_user_max = 20000
    amount_base = 1
    amount_max = 10000
    for i in range(max_lines):
        id_transaction = (i + id_transaction_base)
        id_user = randint(id_user_base, id_user_max)
        card_nr = card_number_generator() 
        date = strftime("%d.%m.%Y %H:%M:%S", gmtime(1320487200 + i))
        
        j = randint(1, len(descs) - 1)
        desc = descs[j] 

        if j > 8:   amount = randint(amount_base, amount_max)
        else:   amount = randint(-amount_max, -amount_base)

        print(id_transaction,id_user,date,amount,card_nr,desc, sep=',')

generate_file(LINES)
