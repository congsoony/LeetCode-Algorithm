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
    Node* cloneGraph(Node* node) {
        return bfs(node);
    }
    Node* bfs(Node * node){
        if (node == NULL) return NULL;
        unordered_map<Node*, Node*> check;
        queue<Node*> q;
        Node* root = new Node(node->val);
        check[node] = root;
        q.push(node);
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            for (Node* next : cur->neighbors) {
                if (check.count(next) == 0) {
                    q.push({ next });
                    check[next] = new Node(next->val);
                }
                check[cur]->neighbors.push_back(check[next]);
            }
        }
        return root;
    }
};
