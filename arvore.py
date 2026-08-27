# Definição da classe que representa um nó da árvore
class No:
    def __init__(self, valor):
        self.valor = valor
        self.esquerda = None
        self.direita = None

# Função para inserir um valor na árvore binária de busca
def inserir(raiz, valor):
    # Se a árvore estiver vazia, cria e retorna um novo nó
    if raiz is None:
        return No(valor)

    # Se o valor for menor, insere na subárvore esquerda
    if valor < raiz.valor:
        raiz.esquerda = inserir(raiz.esquerda, valor)
    # Se o valor for maior, insere na subárvore direita
    elif valor > raiz.valor:
        raiz.direita = inserir(raiz.direita, valor)

    return raiz

# Função auxiliar para encontrar o menor valor (usado na remoção de nó com 2 filhos)
def menor_valor_no(no):
    atual = no
    while atual.esquerda is not None:
        atual = atual.esquerda
    return atual

# Função para remover um valor da árvore binária de busca
def remover(raiz, valor):
    # Caso base: se a árvore estiver vazia
    if raiz is None:
        return raiz

    # Se o valor a ser removido for menor que a raiz, está na subárvore esquerda
    if valor < raiz.valor:
        raiz.esquerda = remover(raiz.esquerda, valor)
    # Se o valor for maior que a raiz, está na subárvore direita
    elif valor > raiz.valor:
        raiz.direita = remover(raiz.direita, valor)
    # Se o valor for igual ao da raiz, este é o nó a ser removido
    else:
        # Cenário 1: Nó sem filhos (folha) ou com apenas um filho
        if raiz.esquerda is None:
            return raiz.direita
        elif raiz.direita is None:
            return raiz.esquerda

        # Cenário 2 (parte do 3): Nó com dois filhos
        # Encontra o menor valor na subárvore direita (sucessor em ordem)
        sucessor = menor_valor_no(raiz.direita)
        
        # Copia o valor do sucessor para este nó
        raiz.valor = sucessor.valor
        
        # Remove o sucessor duplicado da subárvore direita
        raiz.direita = remover(raiz.direita, sucessor.valor)

    return raiz

# Função para exibir a árvore em ordem (Esquerda, Raiz, Direita)
def em_ordem(raiz):
    if raiz is not None:
        em_ordem(raiz.esquerda)
        print(raiz.valor, end=" ")
        em_ordem(raiz.direita)

# Código principal
if __name__ == "__main__":
    raiz = None

    # Inserindo elementos na árvore
    valores = [50, 30, 20, 40, 70, 60, 80, 95, 75]
    for v in valores:
        raiz = inserir(raiz, v)

    print("Árvore original (em ordem):")
    em_ordem(raiz)
    print()

    # Testando as remoções passo a passo para a aula:
    
    # 1. Removendo um nó folha (ex: 20)
    print("\nRemovendo o nó folha 20:")
    raiz = remover(raiz, 20)
    em_ordem(raiz)
    print()

    # 2. Removendo um nó com apenas um filho (ex: 80 - tem o filho 75)
    print("\nRemovendo o nó 80 (possui um filho):")
    raiz = remover(raiz, 80)
    em_ordem(raiz)
    print()

    # 3. Removendo um nó com dois filhos (ex: 30 - tem os filhos 20(removido) e 40)
    print("\nRemovendo o nó 30 (possui dois filhos):")
    raiz = remover(raiz, 30)
    em_ordem(raiz)
    print()
