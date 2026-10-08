# Importa a estrutura de dados 'deque' (fila otimizada) do módulo nativo 'collections'
from collections import deque


# Define a classe do grafo
class Grafo:

  # Método construtor para inicializar o dicionário do grafo
  def __init__(self):
    self.grafo = {}

  # Adiciona um vértice se ele ainda não estiver presente
  def adicionar_vertice(self, vertice):
    if vertice not in self.grafo:
      self.grafo[vertice] = []

  # Adiciona uma aresta bidirecional entre dois vértices
  def adicionar_aresta(self, v1, v2):
    self.adicionar_vertice(v1)
    self.adicionar_vertice(v2)
    self.grafo[v1].append(v2)
    self.grafo[v2].append(v1)

  # Método que realiza a Busca em Largura (BFS) a partir de um vértice inicial
  def bfs(self, inicio):
    # Cria um conjunto (set) para guardar os vértices que já foram visitados (evita loops infinitos)
    visitados = set()

    # Cria uma fila (deque) contendo inicialmente apenas o vértice de início da busca
    fila = deque([inicio])

    # Marca o vértice inicial como visitado, inserindo-o no conjunto
    visitados.add(inicio)

    # Lista que vai armazenar a ordem em que os vértices foram visitados
    ordem_visita = []

    # Loop principal: continua executando enquanto houver elementos na fila
    while fila:
      # Remove e retorna o primeiro elemento da fila (FIFO - First In, First Out)
      vertice_atual = fila.popleft()

      # Adiciona o vértice atual na lista de ordem de visita
      ordem_visita.append(vertice_atual)

      # Explora todos os vizinhos do vértice atual
      for vizinho in self.grafo[vertice_atual]:
        # Verifica se o vizinho ainda NÃO foi visitado
        if vizinho not in visitados:
          # Marca o vizinho como visitado para não processá-lo novamente
          visitados.add(vizinho)
          # Adiciona o vizinho no final da fila para ser visitado em um próximo momento
          fila.append(vizinho)

    # Retorna a lista com a ordem completa dos vértices percorridos
    return ordem_visita


# --- Exemplo de uso da BFS ---

# Cria uma instância do grafo para simular uma rede de pessoas
rede = Grafo()

# Conecta as pessoas formando uma rede de relacionamentos
rede.adicionar_aresta("Ana", "Bruno")
rede.adicionar_aresta("Ana", "Carla")
rede.adicionar_aresta("Bruno", "Daniel")

# Executa a BFS partindo da "Ana" e imprime a ordem de visitação
print("Ordem de visita (BFS):", rede.bfs("Ana"))
# Saída esperada: ['Ana', 'Bruno', 'Carla', 'Daniel']
