import osmnx as ox
import networkx as nx
import matplotlib.pyplot as plt
from algoritmos import bfs, dfs, ids, a_star, bfs2, ejecutar_algoritmo
import platform, os
import numpy as np
import pandas as pd

"""
Andres Felipe Valencia Paternina 0222110032
"""

# Configuración del área
place_name = "Cartagena, Bolivar, Colombia"
bbox = (10.43044, 10.41733, -75.54334, -75.55485)

# Descargar el grafo
G = ox.graph_from_place(place_name, network_type="walk")
nodes_to_keep = [node for node, data in G.nodes(data=True)
                 if bbox[1] <= data['y'] <= bbox[0] and bbox[3] <= data['x'] <= bbox[2]]
G = G.subgraph(nodes_to_keep)
largest_cc = max(nx.strongly_connected_components(G), key=len)
G = G.subgraph(largest_cc).copy()

# Coordenadas de inicio y fin
origen_coords = (10.424929, -75.552048)
destino_coords = (10.42792, -75.54624)
   

# Encontrar nodos más cercanos
origen = ox.distance.nearest_nodes(G, X=origen_coords[1], Y=origen_coords[0])
destino = ox.distance.nearest_nodes(G, X=destino_coords[1], Y=destino_coords[0])

print(f"Nodo origen: {origen}, Nodo destino: {destino}")


# Visualizar el Grafo Inicial con Origen y Destino

plt.close('all')
fig, ax = ox.plot_graph(G, node_size=20, node_color="gray", edge_color="lightgray", show=False)
ax.scatter(origen_coords[1], origen_coords[0], c="green", s=100, label="Origen")
ax.scatter(destino_coords[1], destino_coords[0], c="red", s=100, label="Destino")
plt.title("Grafo con Nodos de Origen y Destino")
plt.legend()
plt.show()

# Información del sistema
print("\n=== Informacion del Sistema ===")
print(f"Sistema Operativo: {platform.system()} {platform.release()}")
print(f"Arquitectura: {platform.architecture()[0]}")
print(f"Procesador: {platform.processor()}")
print(f"Nucleos de CPU: {os.cpu_count()}")
print(f"Version de Python: {platform.python_version()}")
print("\n")


# Ejecutar algoritmos y mostrar rutas
algoritmos = {"BFS": bfs, 
              "DFS": dfs, 
              "IDS": ids,
              "Best First Search" : bfs2,
              "A*": a_star, 
              }

for nombre, algoritmo in algoritmos.items():
    print(f"Ejecutando {nombre}...")
    ruta, tiempo = ejecutar_algoritmo(algoritmo, G, origen, destino)
    
    if ruta:
        print(f"{nombre}: Tiempo: {tiempo:.4f} s | Nodos en ruta: {len(ruta)}")
        
        # Graficar la ruta calculada
        ox.plot_graph_route(
            G, ruta, 
            route_color="green", route_linewidth=2, 
            node_size=30, node_color="white", edge_color="gray"
        )
    else:
        print(f"{nombre}: No se encontró una ruta.")
        
    