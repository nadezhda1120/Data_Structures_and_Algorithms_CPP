## Edge List Representation

How to implement a data structure like graph in the computer's memory? As we know a graph contains a set of vertices and a set of edges. To create and store a graph in the memory, the simplest thing that we can do is, to create two lists - one to store all vertices and another to store all the edges. For a list we can use an array of appropriate size or we can use an implementation of a dynamic list. In fact, we can use a dynamic list available to us in language libraries, something like vector in C++ ot ArrayList in Java. Now, a vertex is identified by it's name, so the first list - the list of vertices would simply be a list of names or strings. But what should we fill in the edge list?

![](https://github.com/andy489/Data_Structures_and_Algorithms_CPP/blob/master/assets/Graph%20representation%20-%20Edge%20List%2001.png)

An edge is identified by it's twho endpoints, so what we can do is we can create an edge as an object with two fields. We can define edge as a structure or class with two fields. One to store the start vertex and another to store the end vertex.

```cpp
struct Edge
{
   char *startVertex;
   char* *endVertex;
}
    //OR
class Edge
{
    string startVertex;
    string endVertex;
}
```
Edge list would basically be an array or list of this type - struct Edge. In these two definitions of edges - int he first one we have used character pointers, because in C we typically use character pointers to store or refer to strings. We could use character array also. In C++ or Java, where we can create classes, we have string available to us as a data-type, so we can use that also. So we can use any of these for the fields depending on how we want to design our implementation.

The graph that we have is an undirected graph, so any vertex can be called start vertex and any vertex can be called end vertex. Order of the vertices is not important here. 

![](https://github.com/andy489/Data_Structures_and_Algorithms_CPP/blob/master/assets/Graph%20representation%20-%20Edge%20List%2002.png)

If this was a directed graph, for example < F,H > and < H,F >, would have meant two different connections - which is the start vertex and which is the end vertex would have mattered, but it our case the graph is undirected so that doesn't matter. Maybe in case of undirected graphs we should name the fields as first vertex and second vertex and in case of directed graphs we should name the fields as start vertex and end vertex. 

Now, our graph here could also be a weighted graph. We can have some cost or weight associated with the edges. As we know in an unweighted graph cost of all the connextions is equal but in a weighted graph, different connections would have differenc weight or different cost. Now in the following example graph we associated some weight:

![](https://github.com/andy489/Data_Structures_and_Algorithms_CPP/blob/master/assets/Graph%20representation%20-%20Edge%20List%2003.png)

When the graph is weighted we can have one more field in the edge object to store the weight:

```cpp
struct Edge
{
   char *startVertex;
   char *endVertex;
   int weight;
}
    //OR
class Edge
{
    string startVertex;
    string endVertex;
    int weight;
}
```

Now an entry in our edge-list has 3 fields. One to store the start vertex, one to store the end vertex and one more to store the weight. So this is one possible way of storing a graph. We can simply create two lists - one to store the vertices and another to store the edges.

```cpp
string vertexList[MAX_SIZE];
Edge edgeList[MAX_SIZE];
```

But this is not very efficient. For any possible way of storing and organazing data we must also see it's cost and when we say cost we mean two things - time cost of various operations and memory usage.<br>
(*Typiccally we measure the rate of growth of time taken with the size of input or data - what we also call time complexity. And we measure the rate of growth of memory consumed with size of input data - what we also call space complexity*)

Time and space complexity are most commonly expressed in terms of what we call Big-O notation. We always want to minimize the time cost of most frequently performed operations and we always want to make sure that we do not consume unreasonably high memory.<br> Let's now analyze the particular structure that we're trying to use to store our graph. Let's first discuss the memory usage. For the first list, the vertex list, least number of rows needed or consumed would be equal to number of vertices. Now, each row in the vertex list is a name or string and string can be of any length. Right now all strings have just one character because we simply named the nodec A, B, C and so on but we could have names with multiple characters. And because strings can be of different lengths - all rows may not be consuming the same amount of memory - like the following example:

![](https://github.com/andy489/Data_Structures_and_Algorithms_CPP/blob/master/assets/Graph%20representation%20-%20Edge%20List%2004.png)

Here we are showing an intracity road network as weighted graph. Cities are our nodes and road distances are our weights. Now, for this graph as we can see, names are of different length, so all rows in vertex list or all rows in edge list would not cost us same. More characters will cost us more bytes. But we can safely assume that the names will not be too long. We can safely assume that in almost all practical scenarios average length of strings will be a really small value - if we assume it to be always lesser than some constant, then the total space consumed in the vertex list will be proportional to the number of rows consumed, that is the number of vertices or in other words we can say that space complexity is O(number of vertives)=O(|V|). Now for the edge list, once again, we are storing strings in first two fields of the edge object, so once again each row will not consume same amount of memory, but if we are just storing the reference or pointer to a string instead of having values in these fields (*we could have references or pointers to the names in the vertex list*) we can finish with a design in which each row will consume same memory. This in fact is better, because references in most cases would cost us a lot lesser than a copy of the name. And as reference we can have te actual address of the string and that's what we are doing when we're saying that start vertex and end vertex can be character pointers. Or maybe a better design would be simply having the index of the name or string in vertex list. Let's say A is at index 0 in vertex list, B is at index 1 and C is at index 2 and etc. Now for start vertex and end vertex, we can have two integer fields. 

```cpp
struct Edge
{
   int startVertex;
   int *endVertex;
   int weight;
}
    //OR
class Edge
{
    int startVertex;
    int endVertex;
    int weight;
}
```

![](https://github.com/andy489/Data_Structures_and_Algorithms_CPP/blob/master/assets/Graph%20representation%20-%20Edge%20List%2005.png)

This definetely is a better design. Now each row in the edge list would cost us the same amount of memory. So overall space consumed in edge list would be proportional to number of edges or in other words, space complexity here is O(number of edges). So this was the analysis of memory usage. Overall space complexity of this design would be O(number of vertices + number of edges).<br>
Is this usage of memory unreasonably high? We cannot do a lot better than this if we want to store a graph in computer's memory. So we are alright in terms of memory usage.

Let's now discuss time cost of the operations. (*What can be most frequently performed operations while working with graph?*) One of the most frequently performed operations while working with graph would be *finding all nodes* adjacent to a given node, that is finding all nodes directly connected to a given node. (*What do you think would be time cost of finding all nodes directly connected to a given node?*) We will have to scan the whole edge list. We will have to perform a linear search. We will have to go through all the entries in the list and see if the start or end node in the entry is our given node. For a directed graph, we would see that if the start node in the entry is our given node or not and for an undirected graph we would see both the start as well as the end node. Running time would be proportional to number of edges or in other words time complexity of this operation would be O(number of edges).<br>Another frequently performed operation can be finding if two given nodes are connected or not. In this case also, we will have to perform a linear search on the edge list. In worst case we will have to look at all the entries in the edge list. So worst case running time would be proportional to number of edges. So for this operation too, time complexity is O(number of edges).<br>Now, let's try to see how good or bad this running time O(|E|) is. In a simple graph, in a graph with no self loop or multi edge, if number of vertices is equal to n (if |V|=n=v), then maximum number of edges would be <img src="https://latex.codecogs.com/svg.latex?\Large&space;0\le{|E|}\le{n(v-1)}">, if the graph is directed and  <img src="https://latex.codecogs.com/svg.latex?\Large&space;0\le{|{E}|}\le\frac{v(v-1)}{2}">, if the graph is undirected. But all in all we can see number of edges can go almost up to square of number of vertices. Number of edges can be of order of square of number of vertices <img src="https://latex.codecogs.com/svg.latex?\Large&space;|{E}|=v(v-1)=v^2-v=O(v^2)">. where with *v* we denote number of vertices. So number of edges can be of order of <img src="https://latex.codecogs.com/svg.latex?\Large&space;v^2">. In a graph, typically any operation running in order of number of edges would be considered very costly.
- <img src="https://latex.codecogs.com/svg.latex?\Large&space;O\(|{E}|\)"> or <img src="https://latex.codecogs.com/svg.latex?\Large&space;O(|{v}|*|{v}|)"> is very costly

We try to keep things in order of number of vertices. When we are comparing the two running times, this is very obvious. <img src="https://latex.codecogs.com/svg.latex?\Large&space;O(|{v}|)"> is a lot better than <img src="https://latex.codecogs.com/svg.latex?\Large&space;O\(|{v^2}|)">.<br> 

#### Cost:
- Time cost of operations (*time complexity*)

Operation|Running time
-|-
finding adjacent nodes|<img src="https://latex.codecogs.com/svg.latex?\Large&space;O\(\|{E}\|\)">
check if given nodes are connected|<img src="https://latex.codecogs.com/svg.latex?\Large&space;O\(\|{E}\|\)">

- Memory usage (*space complexity*) = <img src="https://latex.codecogs.com/svg.latex?\Large&space;O(|V|+|E|)">

***All in all this vertex list and edge list kind of representation is not very efficient in terms of time cost of operations.*** We should think of some other efficient design. We should think of something better. 
