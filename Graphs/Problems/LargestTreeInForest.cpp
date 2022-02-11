/** Problem Statement:
**
**  Given a forest ( one or more disconnected trees ), find the root of largest tree 
**  and return its Id. If there are multiple such roots, return the smallest Id of them.
**
**  Complete the largestTree function in the editor below.
**  It has one parameter, immediateParent, which is a map containing key-value pair indicating 
**  child -> parent relationship. The key is child and value is the corresponding 
**  immediate parent. 
**  Constraints
**    - Child cannot have more than one immediate parent.
**    - Parent can have more than one immediate child.
**    - The given key-value pair forms a well-formed forest ( a tree of n nodes will have n-1 edges )
**
**  Example:
**
**  Input:
**  { { 1 -> 2 }, { 3 -> 4} } 
**  { { 1 -> 2 }, { 3 -> 4}, { 4 -> 5 } } 
**       2     5
**     1      4 
**           3
**
**  Expected output: 2
**  Explanation: There are two trees one having root of Id 2 and another having root of Id 4.
**  Both trees have size 2. The smaller number of 2 and 4 is 2. Hence the answer is 2. 
**/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int nodesInTree = 1;
unordered_set<int> visitedNodes;
unordered_map<int, int> trees;

int findParent(int child, unordered_map<int, int> forest){
    ++nodesInTree;
    int parent = 0;
    if(forest.find(child) != forest.end()){  
        visitedNodes.insert(child);
        parent = findParent(forest[child], forest);
    } else {
        return child;
    }
    return parent;
}

int findLargestTreeNode(){
    int max = -1;
    int nodeVal = 0;

    for(auto tree: trees){
        if(tree.second > max){
            max = tree.second;
            nodeVal = tree.first;
        } else if(tree.second == max){
            nodeVal = std::min(nodeVal, tree.first);
        }
    }

    return nodeVal;
}

int main(){
    unordered_map<int, int> forest({{1, 2}, {3, 4}, {4, 5}, {6, 7}, {7, 8}});

    for(auto node: forest){
        if(visitedNodes.find(node.first) != visitedNodes.end()){
            continue;
        }

        int parent = findParent(node.second, forest);
        trees[parent] = nodesInTree;
        nodesInTree = 1;
    }

    cout<< "Largest Tree Node: " << findLargestTreeNode() << endl;
    return 0;
}
