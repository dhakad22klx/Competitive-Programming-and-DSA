1. Height and depth of nodes in tree for tree thier is no need of visited in dfs, int tree: n-nodes , n-1 edges

2. Floyd Warshall Algorithm-handle negative weight,does not handle negative weight cycle(because shortest path doesn't defined),time complexity is n^3,
 sharp considering of conditions.
3. For an edge to be bridge Lowtime[child_part] > InTime[parent_part].//adjacent !=parent
4. For a node to be articulation point (LowTime[child_part]>=Intime[parent_part] and parent!=-1)  or (parent==-1 and Child>1)//Child--individual children
5. order from dfs1 basically reversed  topological sort sorted   (actually this is exactly what vertices' sort by exit time means ;
6. To find the diameter of a tree : weighted or non weighetd 
1) Choose a random node s and find the farthest node u from s.

2) Find the farthest node v from u.

3) d(u,v) is the diameter.

7. 
