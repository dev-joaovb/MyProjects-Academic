#João Victor Bueno
#UC19106154
####################################

import threading
import random
import time

from typing import List

rl = threading.RLock() # Declaração da variável  rl = threading.Rlock().....

class Conta:

    def __init__(self, saldo=0) -> None:
        self.saldo = saldo

def servicos(contas, total):
    for _ in range(1, 10_000):
        c1, c2 = pega_duas_contas(contas)
        valor = random.randint(1, 100)
        transferir(c1, c2, valor)
        valida_banco(contas, total)

def criar_contas() -> List[Conta]:
    return [
        Conta(saldo=random.randint(5_000, 10_000)),
        Conta(saldo=random.randint(5_000, 10_000)),
        Conta(saldo=random.randint(5_000, 10_000)),
        Conta(saldo=random.randint(5_000, 10_000)),
        Conta(saldo=random.randint(5_000, 10_000)),
        Conta(saldo=random.randint(5_000, 10_000)),
    ]

def transferir(origem: Conta, destino: Conta, valor: int):
    #a função rl.acquire() bloqueia (recebendo true) o rl enquanto o release libera uma thread que esta esperando para ser bloquada

    rl.acquire() #<--------

    if origem.saldo < valor:
        rl.release()
        return

    origem.saldo -= valor
    time.sleep(0.001)
    destino.saldo += valor

    rl.release()#-------->

def valida_banco(contas: List[Conta], total: int):
    #Partindo do mesmo principio anterior, rl.acquire() foi utilizado para interromper se receber verdadeiro, enquanto o rl.release libera 

    rl.acquire() #<-------

    atual = sum(conta.saldo for conta in contas)

    if atual != total:
        print(f'ERRO: Balanço bancário inconsistente. BRL$ {atual:.2f} vs {total:.2f}', flush=True)
    else:
        print(f'Tudo certo: Balanço bancário consistente: BRL$ {total:.2f}', flush=True)
    
    rl.release() #-------->

def pega_duas_contas(contas):
    c1 = random.choice(contas)
    c2 = random.choice(contas)

    while c1 == c2:
        c2 = random.choice(contas)
    
    return c1, c2

def main():
    #Seguindo o mesmo principio, o rl.acquire irá travar recebendo true, a seguir com rl.release fasendo a função de liberar

    contas = criar_contas()
    total = sum(conta.saldo for conta in contas)
    print('Iniciando transferências...')

    #rl.acquire() #<------

    tarefas = [
        threading.Thread(target=servicos, args=(contas, total)),
        threading.Thread(target=servicos, args=(contas, total)),
        threading.Thread(target=servicos, args=(contas, total)),
        threading.Thread(target=servicos, args=(contas, total)),
        threading.Thread(target=servicos, args=(contas, total)),
        threading.Thread(target=servicos, args=(contas, total))
    ]


    [tarefa.start() for tarefa in tarefas]
    
    rl.acquire() # <----------

    [tarefa.join() for tarefa in tarefas]

    print('Transferências completas.')
    valida_banco(contas, total)

    rl.release() #---->

if __name__ == '__main__':
    main()


### Resumindo... nos locais def transferir, valida banco e na main, foi concluido que usando o rl (variavel declarada do Rlock) com rl.acquire para bloquear valores verdadeiros enquanto o rl.release libera

#### Em uma série de testes cheguei a conclusão que a solução do problema estava entre:
#  [tarefa.start() for tarefa in tarefas]
#[tarefa.join() for tarefa in tarefas]
# Dito isso usei o rl.acquire() para bloquar os valores true e assim que ocorresse o rl.release() liberava
