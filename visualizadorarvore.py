import graphviz

def desenhar_arvore(raiz):
    dot = graphviz.Digraph(comment='Árvore Binária de Busca')
    dot.node(str(raiz.valor), str(raiz.valor))

    def adicionar_nos_e_arestas(no, dot):
        if no.esquerda:
            dot.node(str(no.esquerda.valor), str(no.esquerda.valor))
            dot.edge(str(no.valor), str(no.esquerda.valor))
            adicionar_nos_e_arestas(no.esquerda, dot)
        if no.direita:
            dot.node(str(no.direita.valor), str(no.direita.valor))
            dot.edge(str(no.valor), str(no.direita.valor))
            adicionar_nos_e_arestas(no.direita, dot)

    adicionar_nos_e_arestas(raiz, dot)
    return dot


if 'raiz' in globals() and raiz is not None:
    diagrama_arvore = desenhar_arvore(raiz)
    display(diagrama_arvore)
else:
    print("A árvore 'raiz' não foi definida. Por favor, execute a célula anterior para criar a árvore.")
