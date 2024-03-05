#include <stack>
#include <iostream>
#include <vector>
#include "graph.hpp"
#include <fstream>
#include <sstream>
#include <string>

void visiteur(int indice, std::vector<bool> *visite, std::stack<int> *a_visiter, Graph g); // Pour dire que la fonction va exister
Graph read_graph(std::string filename);


void explorer(int indice, int length, Graph g)
{
    // On crée un vecteur de booléen et une pile
    std::vector<bool> visite(length, false);
    std::stack<int> a_visiter;
    a_visiter.push(indice);

    while (!(a_visiter.empty()))
    {
        int j = a_visiter.top();
        a_visiter.pop();
        visiteur(j, &visite, &a_visiter, g); // On utilise une fonction auxilière qui va modifier a_visiter et visite afin de mettre d'y ajouter les sommets adjacent
    }
}

// Fonction auxiliaire qui va modifier la pile pour y ajouter les sommet adjacent au sommet d'indice indice
// si ils n'ont pas été visités
void visiteur(int indice, std::vector<bool> *visite, std::stack<int> *a_visiter, Graph g)
{
    std::vector<int> adj = g.giv_indice_adj(indice); // méthode qui permet d'obtenir les indices des adjacent au sommet d'indice indice.
    for (int adj_indice : adj)
    {
        if (!((*visite)[adj_indice]))
        {
            (*visite)[adj_indice] = true;
            a_visiter->push(adj_indice);
            std::cout << indice << " --> " << adj_indice << std::endl;
        }
    }
}

int main()
{

    Graph g;
    g = read_graph("ex0.gr"); //Lit le graph
    explorer(3, 8, g);

    return 0;
}
