#include "utils/common.cpp"

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    unordered_map<Node*, Node*> visitied;
    Node* cloneGraph(Node* node) {
        if(!node) {
            return nullptr;
        }

        if (visitied.count(node)) {
            return visitied[node];
        }

        Node* cloneNode = new Node(node->val);
        visitied.emplace(node, cloneNode);
        for (Node* neighbor : node->neighbors)
        {
            cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return cloneNode;
        
    }
};