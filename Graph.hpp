/*
lidor mondel
207478256
lidormon20@gmail.com
*/


#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>
#include <string>

namespace ariel
{

    class Graph
    {
    public:

        void loadGraph(const std::vector<std::vector<int>> &matrix);
        std::string printGraph() const;
        void transposeGraph();
        unsigned int size() const;
        const int getEdge(unsigned int x, unsigned int y) const;
        std::vector<unsigned int> get_voisin(unsigned int vertex) const;
        const std::vector<std::vector<int>> &getGraph() const;
        static bool Simetric(const std::vector<std::vector<int>> &matrix);
        
        
        //operators
        
        //addition 
        Graph operator+(const Graph &other) const;
        Graph &operator+=(const Graph &other);
        Graph operator+() const; // Unary plus
        
        //substraction 
        Graph operator-(const Graph &other) const;
        Graph &operator-=(const Graph &other);
        Graph operator-() const; // Unary minus
        
        //mutliplication 
        
        Graph operator*(int scalar) const;
        Graph &operator*=(int scalar);
        Graph operator*(const Graph &other) const;
        Graph &operator*=(const Graph &other);
        
        
        //Increment/Dcrement 
        
        Graph& operator++(); // prefix incremention
        Graph operator++(int); // postfix incremention
        Graph& operator--(); // prefix decremention
        Graph operator--(int); // postfix decremention
        
        //comparaison
        
        bool operator==(const Graph &other) const;//do
        bool operator!=(const Graph &other) const;//do
        bool operator<(const Graph &other) const;
        bool operator<=(const Graph &other) const;//do
        bool operator>(const Graph &other) const;//do
        bool operator>=(const Graph &other) const;//do
        
        Graph &operator/(int scalar);
        Graph &operator/=(int scalar);

        
        //friend
        friend std::ostream &operator<<(std::ostream &os, const Graph &graph);
        friend Graph operator*(int scalar, const Graph& g);
           
        friend Graph operator/(int scalar, const Graph &graph);

    
    private:
        
        bool Contain(const Graph &other) const;
        std::vector<std::vector<int>> adj_mat;
        size_t number_Edges() const;
    };

} // namespace ariel

#endif // GRAPH_HPP
