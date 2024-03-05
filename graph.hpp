#pragma once // Pour que ça ne soit pas initialisé plusieurs fois, on le met toujours.
#include <vector>
// on ne compile pas un .hpp
// lorsque je compile le .cpp il va chercher automatiquement dans le répertoire le .hpp
class Vertex; // On dit que la classe va exister pour pouvoir faire Edge

class Edge // arête
{
    friend class Graph; // pas besoin de l'avoir déclarée
    friend class Vertex;
    Vertex *target; // On met l'adresse car on ne veux pas dédoubler le sommet (plusieurs arêtes peuvent attérir sur le même sommet)
    double value;

public:
    Edge(double value, Vertex *target) : value(value), target(target) {}
};

class Vertex // sommet (On veut une liste de Edge cad la liste des adjacences).
{
    friend class Graph;
    int indice;
    std::vector<Edge> adjacent;

public:
    Vertex(int indice) : indice(indice) {}
    void add_edge(double value, Vertex *vertex) // ajoute une arête à un vertex
    {
        Edge edge(value, vertex);
        adjacent.push_back(edge);
    }
};

class Graph
{
    std::vector<Vertex> sommets;

public:
    
    void add_vertex(Vertex vertex)
    {
        sommets.push_back(vertex);
    };

    std::vector<int> giv_indice_adj(int ind)
    {
        std::vector<int> indices;
        std::vector<Edge> adj = sommets[ind].adjacent;
        for (Edge edge : adj)
        {
            indices.push_back((*(edge.target)).indice); // (*(edge.target)) est un vertex dont on prend l'indice
        }
        return indices;
    }

    void add_edge(int indice_from, int indice_to, double value)
    {
        // int i = 12;
        // int* ri = &i;
        // *ri = 1234;
        // pour que ce soit plus simple on fait que des pointeurs les références servent parfois (exemple le stack dans un cours précédent)
        sommets[indice_from].add_edge(value, &sommets[indice_to]); // & == adresse de

        //     Vertex* pointer_vertex = & sommets[indice_to];
        //     pointer_vertex edge(value, pointer_vertex);
        //    (sommets[indice_from].adjacent).push_back(edge); (Ce que j'ai fait et c'est faux)
    }
};