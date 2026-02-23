import networkx as nx
import time
import heapq
import osmnx as ox

"""
Andres Felipe Valencia Paternina 0222110032
Robin_Farid _Guzman_Arias_0222020049​
"""

def ejecutar_algoritmo(algoritmo, G, origen, destino):

    start_time = time.time()
    try:
        ruta = algoritmo(G, origen, destino)
        tiempo_computo = time.time() - start_time
        return ruta, tiempo_computo
    except nx.NetworkXNoPath:
        return None, None   

# Algoritmo BFS
def bfs(G, origen, destino):
    from collections import deque  
    cola = deque([origen]) 
    visited = {origen: None}  

    while cola:
        actual = cola.popleft()  
        if actual == destino:
            break  

        for vecino in G.neighbors(actual):  
            if vecino not in visited:  
                cola.append(vecino)
                visited[vecino] = actual  

    # Reconstruir la ruta si se encuentra el destino
    if destino in visited:
        ruta = []
        while destino is not None:
            ruta.append(destino)
            destino = visited[destino]  
        return list(reversed(ruta))  
    return None  


def dfs(G, origen, destino):
    pila = [origen]  # Pila para explorar nodos
    visited = {origen: None}  # Seguimiento de padres

    while pila:
        actual = pila.pop()  # Explorar el siguiente nodo
        if actual == destino:
            break  # Ruta encontrada

        for vecino in G.neighbors(actual):
            if vecino not in visited:
                pila.append(vecino)
                visited[vecino] = actual

    # Reconstruir la ruta
    if destino in visited:
        ruta = []
        while destino is not None:
            ruta.append(destino)
            destino = visited[destino]
        return list(reversed(ruta))
    return None

# Algoritmo A*
def a_star(G, origen, destino):
    """
    Encuentra la ruta más corta usando el algoritmo A*.
    """
    return nx.shortest_path(G, origen, destino, weight="length")

# Iterative Deepening Search (IDS)
def ids(G, origen, destino, max_depth=20):
    def dls(node, depth, visited):
        if node == destino:
            return [node]
        if depth == 0:
            return None
        visited.add(node)
        for neighbor in G.neighbors(node):
            if neighbor not in visited:
                path = dls(neighbor, depth-1, visited)
                if path:
                    return [node] + path
        visited.remove(node)
        return None

    for depth in range(max_depth):
        visited = set()
        path = dls(origen, depth, visited)
        if path:
            return path
    return None

# Best-First Search
def bfs2(G, origen, destino):
    def heuristic(node):
        return ox.distance.euclidean(G.nodes[node]['y'], G.nodes[node]['x'],
                                     G.nodes[destino]['y'], G.nodes[destino]['x'])

    queue = [(0, origen)]
    visited = set()
    parent = {origen: None}

    while queue:
        _, current = heapq.heappop(queue)
        if current in visited:
            continue
        if current == destino:
            path = []
            while current:
                path.append(current)
                current = parent[current]
            return path[::-1]
        visited.add(current)
        for neighbor in G.neighbors(current):
            if neighbor not in visited:
                heapq.heappush(queue, (heuristic(neighbor), neighbor))
                parent[neighbor] = current
    return None


