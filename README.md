# MGTag
FunctionFlow. CGCL&SCTL&BDTS,HUST

Reachability query asks whether a vertex can reach another vertex on large directed graphs. It is one of the most fundamental graph operators and has attracted many researchers to study it. Although there are many approaches solving this problem, it still remains a challenging problem when it comes to leverage the three main costs: the index construction time, the index size, and the query time on large and dense graphs. In this paper, we propose a High Dimension Graph Labeling approach to answer reachability queries. First, we recursively partition a graph into disjoint non-shared graphs, among which there are no common vertices, and cross edges. Second, we build a four dimensional label - one dimension of layer, one dimension of sub-graph and two dimensions of interval for each vertex. With the layer label and the sub-graph label, we can determine the positions (non-shared graphs) of any two vertices. Two dimensional interval label is used to assist to answer the reachability queries for vertex pair in those non-shared graphs. Finally, we design algorithms to answer researchability queries efficiently. In order to speed up query answering, we also build two directional labels: up and down labels to filter vertices quickly. The extensive experiments on 28 large/small and dense/sparse graphs show that building the high dimensional index is quickly and the index size is also competitive compared with most of the state of the art approaches. The results also show that our approach is more scalable and efficient than the state-of-the-art approaches in answering reachability queries.
