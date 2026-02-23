import osmnx as ox
import networkx as nx

"""
Andres Felipe Valencia Paternina 0222110032
Robin_Farid _Guzman_Arias_0222020049​
"""

def crear_grafo_recortado(place_name, bbox):
    
    
    north, south, east, west = bbox
    G = ox.graph_from_place(place_name, network_type="walk")
    nodes_to_keep = [node for node, data in G.nodes(data=True)
                     if south <= data['y'] <= north and west <= data['x'] <= east]
    G_recortado = G.subgraph(nodes_to_keep)
    return ox.project_graph(G_recortado)
