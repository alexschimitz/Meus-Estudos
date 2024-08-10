ainda = -1
menu = "Calculadora: \n[1] Soman[2] Subtração\n[3] Multiplicacao\n[4] Divisao\n[0] Sair"
while ainda != 0:
    print(menu);
    escolha = int(input("Escolha digitando o numero desejado: "))
    n1 = int(input("Digite o primeiro numero: "))
    n2 = int(input("Digite o segundo numero: "))
    if escolha == 1:
        print("A soma entre ", n1, "e", n2, "é", (n1+n2))
        ainda = input(menu)
    elif escolha == 2:
        print("A subtracao entre ", n1, "e", n2, "é", (n1-n2))
        ainda = input(menu)
    elif escolha == 3:
        print("A multiplicacao entre ", n1, "e", n2, "é", (n1*n2))
        ainda = input(menu)
    elif escolha == 4:
        print("A divisao entre", n1, "e", n2, "é", (n1/n2), "restante da divisao: ", (n1%n2))
        ainda = input(menu)
    else:
        print("Voce saiu")
        break