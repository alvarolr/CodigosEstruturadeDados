# Definição da classe que representa um nó da árvore AVL
class No:
    def __init__(self, valor):
        self.valor = valor
        self.esquerda = None
        self.direita = None
        self.altura = 1  # NOVO: Altura inicial do nó (folha começa com altura 1)

# Função auxiliar para retornar a altura de um nó (trata nós nulos como altura 0)
def altura(no):
    if no is None:
        return 0
    return no.altura

# Função auxiliar para calcular o Fator de Balanceamento de um nó
def obter_fator_balanceamento(no):
    if no is None:
        return 0
    return altura(no.esquerda) - altura(no.direita)

# Rotação simples à direita
def rotacao_direita(y):
    x = y.esquerda
    T2 = x.direita

    # Realiza a rotação
    x.direita = y
    y.esquerda = T2

    # Atualiza as alturas dos nós afetados
    y.altura = 1 + max(altura(y.esquerda), altura(y.direita))
    x.altura = 1 + max(altura(x.esquerda), altura(x.direita))

    # Retorna a nova raiz da subárvore
    return x

# Rotação simples à esquerda
def rotacao_esquerda(x):
    y = x.direita
    T2 = y.esquerda

    # Realiza a rotação
    y.esquerda = x
    x.direita = T2

    # Atualiza as alturas dos nós afetados
    x.altura = 1 + max(altura(x.esquerda), altura(x.direita))
    y.altura = 1 + max(altura(y.esquerda), altura(y.direita))

    # Retorna a nova raiz da subárvore
    return y

# Função para inserir um valor na árvore AVL (com balanceamento automático)
def inserir(raiz, valor):
    # 1. Inserção normal de BST
    if raiz is None:
        return No(valor)

    if valor < raiz.valor:
        raiz.esquerda = inserir(raiz.esquerda, valor)
    elif valor > raiz.valor:
        raiz.direita = inserir(raiz.direita, valor)
    else:
        return raiz # Não permitimos valores duplicados na AVL

    # 2. Atualiza a altura do ancestral atual
    raiz.altura = 1 + max(altura(raiz.esquerda), altura(raiz.direita))

    # 3. Obtém o fator de balanceamento para verificar se desequilibrou
    fator = obter_fator_balanceamento(raiz)

    # --- CASOS DE ROTAÇÃO ---

    # Caso Esquerda-Esquerda (Rotação Simples à Direita)
    if fator > 1 and valor < raiz.esquerda.valor:
        return rotacao_direita(raiz)

    # Caso Direita-Direita (Rotação Simples à Esquerda)
    if fator < -1 and valor > raiz.direita.valor:
        return rotacao_esquerda(raiz)

    # Caso Esquerda-Direita (Rotação Dupla: Esquerda e depois Direita)
    if fator > 1 and valor > raiz.esquerda.valor:
        raiz.esquerda = rotacao_esquerda(raiz.esquerda)
        return rotacao_direita(raiz)

    # Caso Direita-Esquerda (Rotação Dupla: Direita e depois Esquerda)
    if fator < -1 and valor < raiz.direita.valor:
        raiz.direita = rotacao_direita(raiz.direita)
        return rotacao_esquerda(raiz)

    # Retorna o ponteiro do nó (inalterado se estivesse balanceado)
    return raiz

# Função auxiliar para encontrar o menor valor (usado na remoção)
def menor_valor_no(no):
    atual = no
    while atual.esquerda is not None:
        atual = atual.esquerda
    return atual

# Função para remover um valor da árvore AVL (mantendo o balanceamento)
def remover(raiz, valor):
    # 1. Executa a remoção padrão de BST
    if raiz is None:
        return raiz

    if valor < raiz.valor:
        raiz.esquerda = remover(raiz.esquerda, valor)
    elif valor > raiz.valor:
        raiz.direita = remover(raiz.direita, valor)
    else:
        if raiz.esquerda is None:
            return raiz.direita
        elif raiz.direita is None:
            return raiz.esquerda

        sucessor = menor_valor_no(raiz.direita)
        raiz.valor = sucessor.valor
        raiz.direita = remover(raiz.direita, sucessor.valor)

    if raiz is None:
        return raiz

    # 2. Atualiza a altura do nó atual após a remoção
    raiz.altura = 1 + max(altura(raiz.esquerda), altura(raiz.direita))

    # 3. Obtém o fator de balanceamento
    fator = obter_fator_balanceamento(raiz)

    # --- CASOS DE ROTAÇÃO NA REMOÇÃO ---

    # Caso Esquerda-Esquerda
    if fator > 1 and obter_fator_balanceamento(raiz.esquerda) >= 0:
        return rotacao_direita(raiz)

    # Caso Esquerda-Direita
    if fator > 1 and obter_fator_balanceamento(raiz.esquerda) < 0:
        raiz.esquerda = rotacao_esquerda(raiz.esquerda)
        return rotacao_direita(raiz)

    # Caso Direita-Direita
    if fator < -1 and obter_fator_balanceamento(raiz.direita) <= 0:
        return rotacao_esquerda(raiz)

    # Caso Direita-Esquerda
    if fator < -1 and obter_fator_balanceamento(raiz.direita) > 0:
        raiz.direita = rotacao_direita(raiz.direita)
        return rotacao_esquerda(raiz)

    return raiz

# Função para exibir a árvore em ordem
def em_ordem(raiz):
    if raiz is not None:
        em_ordem(raiz.esquerda)
        print(f"{raiz.valor}(Alt:{raiz.altura})", end=" ")
        em_ordem(raiz.direita)

# Código principal
if __name__ == "__main__":
    raiz = None

    # Inserindo elementos que gerariam uma lista encadeada numa BST comum
    valores = [10, 20, 30, 40, 50, 25]
    print("Inserindo valores sequenciais e causando rotações automáticas:")
    for v in valores:
        print(f"Inserindo {v}...")
        raiz = inserir(raiz, v)

    print("\nÁrvore AVL resultante (em ordem com alturas):")
    em_ordem(raiz)
    print()
