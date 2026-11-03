class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        if(mp.count(node)) return mp[node];

        Node* copy = new Node(node->val);
        mp[node] = copy;

        for(auto it : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(it));
        }

        return copy;
    }
};