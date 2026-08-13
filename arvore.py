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
    valores = [50, 30, 20, 40, 70, 60, 80]
    for v in valores:
        raiz = inserir(raiz, v)
        
    print("Percurso em ordem (Python):")
    em_ordem(raiz)
    print()
