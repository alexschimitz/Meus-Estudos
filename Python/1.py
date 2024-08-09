nome = input("Digite seu nome: ")
idade = int(input("Digite sua idade: "))
altura = float(input("Digite sua altura: "))
print("Olá, ", nome, ".\nVoce tem ", idade, " anos e tem ", "{:.2f}".format(altura), " metros de altura.")