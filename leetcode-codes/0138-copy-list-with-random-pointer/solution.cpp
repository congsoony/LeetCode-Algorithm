/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
int find(Node * head,Node * cur){
    if(cur->random==nullptr)return -1;
    int idx =0;
    while(head){
        if(cur->random==head) return idx;
        head=head->next;
        idx++;
    }
    return -1;
}
Node* copyRandomList(Node* head) {
    vector<pair<int,int>> v;
    Node * cur=head;
    vector<Node*> v2;
    if(head==nullptr) return nullptr;
    while(cur){
        v.push_back({cur->val,find(head,cur)});
        v2.push_back(new Node(cur->val));
        if(v2.size()>1)
            v2[v2.size()-2]->next=v2.back();
        cur=cur->next;
    }
    for(int i=0;i<v.size();i++){
        if(v[i].second!=-1)
            v2[i]->random=v2[v[i].second];
    }
    return v2[0];
}
};
