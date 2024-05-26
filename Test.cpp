/*
lidor mondel
207478256
lidormon20@gmail.com
*/




#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
//
using namespace std;

TEST_CASE("Test +")
{

 ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0,2 , 3},
        {4, 0, 5},
        {6, 7, 0}};
    g2.loadGraph(graph2);
    ariel::Graph g3 = g1 + g2;
    CHECK(g3.printGraph() == "[0, 3, 4]\n[5, 0, 6]\n[7, 8, 0]");



}

TEST_CASE("Test +=")
{
ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 5},
        {2, 0, 10},
        {5, 10, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, -3, -2},
        {1, 0, 2},
        {3, 4, 0}};
    g2.loadGraph(weightedGraph);
    g1 += g2;
    

    CHECK(g1.printGraph() == "[0, -1, 3]\n[3, 0, 12]\n[8, 14, 0]");

 ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 3},
        {5, 0, 7},
        {-9, 10, 0}};
    g3.loadGraph(graph3);
    g3 +=g3;
    
    CHECK(g3.printGraph() == "[0, 2, 6]\n[10, 0, 14]\n[-18, 20, 0]");


}


TEST_CASE("Test unary +")
{

 ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {3, 0, 4},
        {5, 6, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = +g1;
    CHECK(g2.printGraph() == "[0, 1, 2]\n[3, 0, 4]\n[5, 6, 0]");

}

TEST_CASE("Test -")
{
 ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0,2 , 3},
        {4, 0, 5},
        {6, 7, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 - g2;
    CHECK(g3.printGraph() == "[0, -1, -2]\n[-3, 0, -4]\n[-5, -6, 0]");


}

TEST_CASE("Test -=")
{


ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 5},
        {2, 0, 10},
        {5, 10, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> g3 = {
        {0, -3, -2},
        {1, 0, 2},
        {3, 4, 0}};
    g2.loadGraph(g3);
    g1 -= g2;
    CHECK(g1.printGraph() == "[0, 5, 7]\n[1, 0, 8]\n[2, 6, 0]");

}


TEST_CASE("Test unary -")
{

 ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {3, 0, 4},
        {5, 6, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = -g1;
    CHECK(g2.printGraph() == "[0, -1, -2]\n[-3, 0, -4]\n[-5, -6, 0]");
}

TEST_CASE("Test * scalar ")
{
  ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {3, 0, 4},
        {5, 6, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1 * 2;
    CHECK(g2.printGraph() == "[0, 2, 4]\n[6, 0, 8]\n[10, 12, 0]");

}


TEST_CASE("Test *= scalar ")
{
ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {3, 0, 4},
        {5, 6, 0}};
    g1.loadGraph(graph);
    g1 *= 2;
    CHECK(g1.printGraph() == "[0, 2, 4]\n[6, 0, 8]\n[10, 12, 0]");

}

TEST_CASE("Test *graph ")
{

 ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0,2 , 3},
        {4, 0, 5},
        {6, 7, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 * g2;
    CHECK(g3.printGraph() == "[0, 7, 5]\n[6, 0, 3]\n[4, 2, 0]");
}

TEST_CASE("Test *= graph ")
{



ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {3, 0, 4},
        {5, 6, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> g3 = {
        {0, 6, 5},
        {4, 0, 3},
        {2, 1, 0}};
    g2.loadGraph(g3);
    g1 *= g2;
    CHECK(g2.printGraph() == "[0, 6, 5]\n[4, 0, 3]\n[2, 1, 0]");
}

TEST_CASE("pre increment ")
{
 
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {3, 0, 4},
        {5, 6, 0}};
    g1.loadGraph(graph);
    ++g1;
     CHECK(g1.printGraph() == "[0, 2, 3]\n[4, 0, 5]\n[6, 7, 0]");

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 2},
        {-1, 0, -2},
        {1, -2, 0}};

    g2.loadGraph(weightedGraph);
    ++g2;
   CHECK(g2.printGraph() == "[0, 2, 3]\n[0, 0, -1]\n[2, -1, 0]");

}

TEST_CASE("pre decrement")
{

   ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {3, 0, 4},
        {5, 6, 0}};
    g1.loadGraph(graph);
    --g1;
    CHECK(g1.printGraph() == "[0, 0, 1]\n[2, 0, 3]\n[4, 5, 0]");


    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 2},
        {-1, 0, -2},
        {1, -2, 0}};

    g2.loadGraph(graph2);
    --g2;
   CHECK(g2.printGraph() == "[0, 0, 1]\n[-2, 0, -3]\n[0, -3, 0]");




}

TEST_CASE("post increment")
{


 ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {3, 0, 4},
        {5, 6, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1++;
     CHECK(g2.printGraph() == "[0, 1, 2]\n[3, 0, 4]\n[5, 6, 0]");

     CHECK(g1.printGraph() == "[0, 2, 3]\n[4, 0, 5]\n[6, 7, 0]");

}

TEST_CASE("post decrement")
{

  ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {3, 0, 4},
        {5, 6, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1--;
   CHECK(g2.printGraph() == "[0, 1, 2]\n[3, 0, 4]\n[5, 6, 0]");

     CHECK(g1.printGraph() == "[0, 0, 1]\n[2, 0, 3]\n[4, 5, 0]");

}


TEST_CASE("oeprator comparaison")
{
ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(graph2);
    
    CHECK((g1 < g2) == true); 
    CHECK((g1 > g2) == false); 
    CHECK((g1 <= g2) == true);
    CHECK((g1 >= g2) == false); 
    CHECK((g1 == g2) == false);
    CHECK((g1 != g2) == true);


ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1},
        {0, 0}};
    g3.loadGraph(graph3);
    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, 0 ,1},
        {0, 0, 0},
        {1, 0, 0}};
    g4.loadGraph(graph4);
    
    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, 1, 1},
        {0, 0, 0},
        {0, 0, 0}};
    g5.loadGraph(graph5);
    
    CHECK((g3 < g4) == true); 
    CHECK((g3 < g5) == true); 
    CHECK((g3 > g5) == false); 
    CHECK((g3 <= g5) == true);
    CHECK((g3 >= g5) == false);
    CHECK((g3 == g5) == false);
    CHECK((g3 != g5) == true);

}
TEST_CASE("Test /")
{

    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 5, 10},
        {15, 0, 20},
        {25, 30, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1 / 5;
    CHECK(g2.printGraph() == "[0, 1, 2]\n[3, 0, 4]\n[5, 6, 0]");
}

   TEST_CASE("Test /=")
{

    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 5, 10},
        {15, 0, 20},
        {25, 30, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1 /= 5;
    CHECK(g2.printGraph() == "[0, 1, 2]\n[3, 0, 4]\n[5, 6, 0]");
}

TEST_CASE("Test  * reverse")
{

    ariel::Graph g1;
    vector<vector<int>> graph = {
       {0, 5, 10},
        {15, 0, 20},
        {25, 30, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = 2 * g1;
   
    CHECK(g2.printGraph() == "[0, 10, 20]\n[30, 0, 40]\n[50, 60, 0]");
    
}




