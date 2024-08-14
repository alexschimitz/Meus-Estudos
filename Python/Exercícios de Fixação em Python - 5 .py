# Média de duas notas, se tirou 10 é aprovado com distinção, senão, tirar 7 ou mais para ser aprovado. menor que 7 reprovado
n1 = float(input("Digite uma nota: "))
n2 = float(input("Digite outra nota: "))
media = (n1 + n2)/2
if media == 10:
    print("Aprovado com distinção")
elif media >= 7:
    print("Aprovado")
else:
    print("Reprovado")