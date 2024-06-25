// first create the linked list then assgin random pointers using hash map

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
    Node* copyRandomList(Node* head) {
        
        Node* curr = head;
        unordered_map<Node*, Node*>mp;
        
        while(curr){
            Node* copy = new Node(curr->val);
            mp[curr] = copy;
            curr = curr->next;
        }

        curr = head;
        Node* currcopy = nullptr;
        while(curr){
            currcopy = mp[curr];
            currcopy->next = mp[curr->next];
            currcopy->random = mp[curr->random];
            curr = curr->next;
        }

        return mp[head];
    }
};

// SC : O(1)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        // step 1. create copy list and put them in between original
        // org-1 -> copy-1 -> org-2 -> copy-2 -> org-3 ---->
        Node* temp = head;

        while(temp){

            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next; // temp = temp->next->next;
        }

        // step 2. connect random pointers for copied list [by observation]
        temp = head;

        while(temp){

            Node* copy = temp->next;
            if(temp->random) copy->random = temp->random->next;
            temp = copy->next; // temp = temp->next->next;
        }

        // step 3. connect next pointers for copied list
        // and revert all changes orginal list 

        Node* dummy = new Node(-1);
        Node* res = dummy;
        temp = head;

        while(temp){

            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};