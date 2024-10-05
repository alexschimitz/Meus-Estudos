dindin = [100, 50, 20, 10]

vsaque = int(input("Digite o valor a ser sacado (inteiro): "))

for n in dindin:
    quant = vsaque // n
    if quant > 0:
        print(f"R${n}: {quant} cédula(s)")
        vsaque -= quant * n
