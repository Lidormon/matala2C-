/*
lidor mondel
207478256
lidormon20@gmail.com
*/



#include "Graph.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;

namespace ariel
{
void Graph::loadGraph(const std::vector<std::vector<int>>& graph) {

    for(unsigned int i = 0; i < graph.size(); i++){
        if (graph.size() != graph[i].size()) {
            throw invalid_argument("Invalid graph: The graph is not a square mat.");
        }

		if (graph[i][i] != 0){
			throw invalid_argument("Invalid graph.");
		}
    }
    adj_mat = graph;
}

std::string Graph::printGraph() const {
    std::ostringstream os;
        for (size_t i = 0; i < adj_mat.size(); ++i)
        {
            os << "[";
            for (size_t j = 0; j < adj_mat[i].size(); ++j)
            {
                os << adj_mat[i][j];
                if (j < adj_mat[i].size() - 1)
                {
                    os << ", ";
                }
            }
            os << "]";
            if (i < adj_mat.size() - 1)
            {
                os << "\n";
            }
        }
        return os.str();
}

unsigned int Graph::size() const{
    return adj_mat.size();
}


const int Graph::getEdge(unsigned int x, unsigned int y) const{

    if (x >= adj_mat.size() || y >= adj_mat[0].size()) {
        throw out_of_range("Invalid :Index out of range ");
    }

    return adj_mat[x][y];
}

void Graph::transposeGraph() {
    for (size_t i = 0; i < adj_mat.size(); i++) {
        for (size_t j = i + 1; j < adj_mat.size(); j++) {

            // Swap elements at position (i, j) and (j, i)
            int temp = adj_mat[i][j];
            adj_mat[i][j] = adj_mat[j][i];
            adj_mat[j][i] = temp;
        }
    }
}
const vector<vector<int>> &Graph::getGraph() const
{
    return this->adj_mat;
}

vector<unsigned int> Graph::get_voisin(unsigned int vertex) const {

    vector<unsigned int> voisins;
   
    if (vertex >= adj_mat.size()) {
        throw out_of_range("Inavlid: Index out of range");
    }

    const vector<int>& num_edges = adj_mat[vertex];
    for (unsigned int i = 0; i < num_edges.size(); ++i) {
        if (num_edges[i] != 0) {
            voisins.push_back(i);
        }
    }

    return voisins;
}


//operaors
//good
Graph Graph::operator+(const Graph &other) const
    {   
        
         if (adj_mat.size() == 0 || other.size() == 0) 
         {
        throw std::invalid_argument("empty graphs");
        
         }
        
        if (adj_mat.size() != other.size())
        {
            throw invalid_argument("Graphs must be of the same size to add.");
        }
        std::vector<std::vector<int>> result(adj_mat.size(), std::vector<int>(adj_mat.size()));
        for (size_t i = 0; i < adj_mat.size(); ++i)
        {
            for (size_t j = 0; j < adj_mat.size(); ++j)
            {
                result[i][j] = adj_mat[i][j] + other.adj_mat[i][j];
            }
        }
        Graph ans;
        ans.loadGraph(result);
        return ans;
    }


Graph &Graph::operator+=(const Graph &other)
    {
           if (adj_mat.size() == 0 || other.size() == 0) 
         {
        throw std::invalid_argument(" empty graphs");
        
         }
        
        if (adj_mat.size() != other.size())
        {
            throw invalid_argument("Graphs must be of the same size to add.");
        }
        for (size_t i = 0; i < adj_mat.size(); ++i)
        {
            for (size_t j = 0; j <adj_mat.size(); ++j)
            {
                adj_mat[i][j] += other.adj_mat[i][j];
            }
        }
        return *this;
    }

//good
 Graph Graph::operator+() const
    {
        return *this;
    }
    
    
    
Graph Graph::operator-(const Graph &other) const
    {   
        
         if (adj_mat.size() == 0 || other.size() == 0) 
         {
        throw std::invalid_argument("empty graphs");
        
         }
        
        if (adj_mat.size() != other.size())
        {
            throw invalid_argument("Graphs must be of the same size to add.");
        }
        std::vector<std::vector<int>> result(adj_mat.size(), std::vector<int>(adj_mat.size()));
        for (size_t i = 0; i < adj_mat.size(); ++i)
        {
            for (size_t j = 0; j < adj_mat.size(); ++j)
            {
                result[i][j] = adj_mat[i][j] - other.adj_mat[i][j];
            }
        }
        Graph ans;
        ans.loadGraph(result);
        return ans;
    }


Graph &Graph::operator-=(const Graph &other)
    {
           if (adj_mat.size() == 0 || other.size() == 0) 
         {
        throw std::invalid_argument("empty graphs");
        
         }
        
        if (adj_mat.size() != other.size())
        {
            throw invalid_argument("Graphs must be of the same size to add.");
        }
        for (size_t i = 0; i < adj_mat.size(); ++i)
        {
            for (size_t j = 0; j <adj_mat.size(); ++j)
            {
                adj_mat[i][j] -= other.adj_mat[i][j];
            }
        }
        return *this;
    }
    
    Graph Graph::operator-() const
    {
        std::vector<std::vector<int>> result(adj_mat.size(), std::vector<int>(adj_mat.size()));
        for (size_t i = 0; i < adj_mat.size(); ++i)
        {
            for (size_t j = 0; j < adj_mat.size(); ++j)
            {
                result[i][j] = -adj_mat[i][j];
            }
        }
        Graph ans;
        ans.loadGraph(result);
        return ans;
    }
    
      Graph &Graph::operator++()
    {
        for (size_t i = 0; i < adj_mat.size(); ++i)
        {
            for (size_t j = 0; j < adj_mat.size(); ++j)
            {
                ++adj_mat[i][j];
            }
        }
        
        for (size_t i = 0; i < adj_mat.size(); ++i)
        {
            adj_mat[i][i] = 0;
        }
        return *this;
    }
    
    Graph Graph::operator++(int)
    {
        Graph temp = *this;
        ++(*this);
        return temp;
    }
    
     Graph &Graph::operator--()
    {
        for (size_t i = 0; i < adj_mat.size(); ++i)
        {
            for (size_t j = 0; j < adj_mat.size(); ++j)
            {
                --adj_mat[i][j];
            }
        }
        
        for (size_t i = 0; i < adj_mat.size(); ++i)
        {
            adj_mat[i][i] = 0;
        }
        return *this;
    }
    
     Graph Graph::operator--(int)
    {
        Graph temp = *this;
        --(*this);
        return temp;
    }
    
    
    
     Graph Graph::operator*(int scalar) const
    {
        std::vector<std::vector<int>> result(adj_mat.size(), std::vector<int>(adj_mat.size()));
        for (size_t i = 0; i < adj_mat.size(); ++i)
        {
            for (size_t j = 0; j < adj_mat.size(); ++j)
            {
                result[i][j] = adj_mat[i][j] * scalar;
            }
        }
        Graph ans;
        ans.loadGraph(result);
        return ans;
    }
    
    Graph &Graph::operator*=(int scalar)
    {
        for (size_t i = 0; i < adj_mat.size(); ++i)
        {
            for (size_t j = 0; j < adj_mat.size(); ++j)
            {
                adj_mat[i][j] *= scalar;
            }
        }
        return *this;
    }
    
    
  
    
     Graph Graph::operator*(const Graph &other) const
    {
        if (adj_mat.size() != other.adj_mat.size())
        {
            throw invalid_argument("The dimension of the mat not valid.");
        }
        std::vector<std::vector<int>> result(adj_mat.size(), std::vector<int>(adj_mat.size(), 0));
        for (size_t i = 0; i < adj_mat.size(); ++i)
        {
            for (size_t j = 0; j < adj_mat.size(); ++j)
            {
                for (size_t k = 0; k < adj_mat.size(); ++k)
                {
                    result[i][j] += adj_mat[i][k] * other.adj_mat[k][j];
                }
                
                if (i == j)
                {
                    result[i][j] = 0;
                }
            }
        }
        Graph ans;
        ans.loadGraph(result);
        return ans;
    }
    
    Graph &Graph::operator*=(const Graph &other)
    {
        if (adj_mat.size() != other.adj_mat.size())
        {
            throw invalid_argument("Graphs must be of the same size.");
        }

        std::vector<std::vector<int>> result(adj_mat.size(), std::vector<int>(adj_mat.size(), 0));

        for (size_t i = 0; i < adj_mat.size(); ++i)
        {
            for (size_t j = 0; j < adj_mat.size(); ++j)
            {
                for (size_t k = 0; k < adj_mat.size(); ++k)
                {
                    result[i][j] += adj_mat[i][k] * other.adj_mat[k][j];
                }
                if (i == j)
                {
                    result[i][j] = 0; 
                }
            }
        }

        this->loadGraph(result);
        return *this;
    }
    
    
       Graph operator*(int scalar, const Graph &graph)
    {
        return graph * scalar; 
    }
    
    
     std::ostream &operator<<(std::ostream &os, const Graph &graph)
    {
        os << graph.printGraph() << "\n"; 
        return os;
    }
    
    
    bool Graph::operator==(const Graph &g) const
    {
       
        if (adj_mat.size() == g.adj_mat.size())
        {
            for (size_t i = 0; i < adj_mat.size(); i++)
            {
                for (size_t j = 0; j < adj_mat[i].size(); j++)
                {
                    if (adj_mat[i][j] != g.adj_mat[i][j])
                    {
                        return false; 
                    }
                }
            }
            return true; 
        }
        
        else if (!((*this) < g) && !(g < *this))
        {
            return true; 
        }
        return false; 
    }

    bool Graph::operator!=(const Graph &g) const
    {
        return !(*this == g);
    }
    
       bool Graph::operator>(const Graph &other) const
    {
        return other < *this;
    }
      bool Graph::operator<=(const Graph &g) const
    {
        return (*this < g) || (*this == g);
    }
    
  bool Graph::operator>=(const Graph &g) const
    {
        return g <= *this;
    }
    
    
     bool Graph::Contain(const Graph &other) const
    {
        if (adj_mat.size() > other.adj_mat.size())
        {
            return false;
        }

        
        std::vector<size_t> vec(other.size());
        std::iota(vec.begin(), vec.end(), 0);

        do
        {
            bool contain = true;
            for (size_t i = 0; i < adj_mat.size() && contain; ++i)
            {
                for (size_t j = 0; j < adj_mat.size() && contain; ++j)
                {
                    if (adj_mat[i][j] != 0 && other.adj_mat[vec[i]][vec[j]] == 0)
                    {
                        contain = false;
                    }
                }
            }
            if (contain)
            {
                return true;
            }
        } while (std::next_permutation(vec.begin(), vec.end()));

        return false;
    }
    
    bool Graph::operator<(const Graph &other) const
    {
        
        if (this->Contain(other) && !other.Contain(*this))
        {
            return true;
        }

        
        if (other.Contain(*this) && !this->Contain(other))
        {
            return false;
        }

        
        size_t edge1 = this->number_Edges();
        size_t edge_2 = other.number_Edges();
        if (edge1 != edge_2)
        {
            return edge1 < edge_2;
        }

        
        return this->adj_mat.size() < other.adj_mat.size();
    }

    size_t Graph::number_Edges() const
    {
        size_t counter = 0;
        if (Simetric(this->adj_mat))
        {
            for (size_t i = 0; i < adj_mat.size(); ++i)
            {
                for (size_t j = 0; j < adj_mat.size(); ++j)
                {
                    if (this->adj_mat[i][j] != 0)
                    {
                        counter++;
                    }
                }
            }
            counter = counter / 2;
        }
        else
        {
            for (size_t i = 0; i < adj_mat.size(); ++i)
            {
                for (size_t j = 0; j <adj_mat.size(); ++j)
                {
                    if (adj_mat[i][j] != 0)
                    {
                        counter++;
                    }
                }
            }
            counter = counter;
        }
        return counter;
    }

   
    bool Graph::Simetric(const std::vector<std::vector<int>> &mat)
    {
        for (size_t i = 0; i < mat.size(); i++)
        {
            for (size_t j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] != mat[j][i])
                {
                    return false;
                }
            }
        }
        return true;
    }

Graph &Graph::operator/(int scalar)
    {
        if (scalar == 0)
        {
            throw invalid_argument("Division by zero not permitted.");
        }
        for (size_t i = 0; i < adj_mat.size(); ++i)
        {
            for (size_t j = 0; j < adj_mat.size(); ++j)
            {
                adj_mat[i][j] /= scalar;
            }
        }
        return *this;
    }

   
    Graph &Graph::operator/=(int scalar)
    {
        if (scalar == 0)
        {
            throw invalid_argument("Division by zero not permitted.");
        }
        for (size_t i = 0; i <  adj_mat.size(); ++i)
        {
            for (size_t j = 0; j <  adj_mat.size(); ++j)
            {
                 adj_mat[i][j] /= scalar;
            }
        }
        return *this;
    }
    
    Graph operator/(int scalar, const Graph &graph)
    {
        std::vector<std::vector<int>> result(graph.size(), std::vector<int>(graph.size(), 0));
        for (size_t i = 0; i < graph.size(); ++i)
        {
            for (size_t j = 0; j < graph.size(); ++j)
            {
                if (i != j && graph.adj_mat[i][j] != 0)
                {
                    result[i][j] = scalar / graph.adj_mat[i][j];
                }
            }
        }
        Graph ans;
        ans.loadGraph(result);
        return ans;
    }


}
