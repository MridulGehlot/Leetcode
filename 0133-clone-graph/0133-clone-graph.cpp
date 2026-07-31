/*
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
*/

class Solution {
public:
    unordered_map<int,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        if(mp.count(node->val)) return mp[node->val];
        Node *head;
        head=new Node(node->val);
        mp[node->val]=head;
        for(Node *x:node->neighbors)
        {
            if(mp.count(x->val)) head->neighbors.push_back(mp[x->val]);
            else head->neighbors.push_back(cloneGraph(x));
        }
        return head;
    }
};