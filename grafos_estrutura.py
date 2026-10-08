# Define a classe que representará o nosso grafo
class Grafo:

  # Método construtor executado quando criamos um novo grafo
  def __init__(self):
    # Inicializa um dicionário vazio para armazenar os vértices e suas conexões (lista de adjacência)
    # A chave será o vértice, e o valor será uma lista contendo seus vizinhos
    self.grafo = {}

  # Método para adicionar um vértice isolado ao grafo
  def adicionar_vertice(self, vertice):
    # Verifica se o vértice ainda NÃO existe no dicionário do grafo
    if vertice not in self.grafo:
      # Se não existir, cria a chave com uma lista vazia de vizinhos
      self.grafo[vertice] = []

  # Método para conectar dois vértices por uma aresta
  def adicionar_aresta(self, v1, v2):
    # Garante que o vértice 'v1' existe no grafo (se não existir, é criado)
    self.adicionar_vertice(v1)
    # Garante que o vértice 'v2' também existe no grafo
    self.adicionar_vertice(v2)

    # Como é um grafo NÃO direcionado, adiciona 'v2' na lista de vizinhos de 'v1'
    self.grafo[v1].append(v2)
    # E também adiciona 'v1' na lista de vizinhos de 'v2' (mão dupla)
    self.grafo[v2].append(v1)

  # Método para exibir a estrutura do grafo no console
  def exibir(self):
    # Percorre cada vértice e sua respectiva lista de vizinhos no dicionário
    for vertice, vizinhos in self.grafo.items():
      # Imprime o formato: "Vertice -> [Vizinhos]"
      print(f"{vertice} -> {vizinhos}")


# --- Exemplo de uso ---

# Cria uma instância da classe Grafo
meu_grafo = Grafo()

# Adiciona uma aresta entre A e B (cria os vértices A e B automaticamente)
meu_grafo.adicionar_aresta("A", "B")

# Adiciona uma aresta entre A e C (conecta C ao vértice existente A)
meu_grafo.adicionar_aresta("A", "C")

# Adiciona uma aresta entre B e D
meu_grafo.adicionar_aresta("B", "D")

# Exibe o grafo final estruturado
meu_grafo.exibir()
