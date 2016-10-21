const int MAXCHAR = 26;
const char CHAR = 'a';

struct Node{
    Node* child[MAXCHAR];
    Node* fail;
    int N;
    Node():N(-1),fail(NULL){for(int i=0;i<MAXCHAR;i++)child[i] = NULL;}
};

struct AC{
    Node* root;
    AC(){root = new Node;}
    void word(string s,int index){
        Node* now = root;
        for(int i=0;i<s.size();i++){
            int c = s[i] - CHAR;
            if(now->child[c] == NULL)now->child[c] = new Node;
            now = now->child[c];
        }
        if(now->N == -1)now->N = index;
    }
    void predo(){
        root->fail = NULL;
        Node* p;
        queue<Node*> Q;
        Q.push(root);
        while(!Q.empty()){
            Node* now = Q.front();Q.pop();
            for(int i=0;i<MAXCHAR;i++){
                if(!now->child[i])continue;
                Q.push(now->child[i]);
                p = now->fail;
                while(p != NULL && p->child[i] == NULL)p = p->fail;
                if(p == NULL)now->child[i]->fail = root;
                else now->child[i]->fail = p->child[i];
            }
        }
    }
    void match(string text){
        Node* now = root;
        for(int i=0;i<text.size();i++){
            int c = text[i] - CHAR;
            while(now != root && now->child[c] == NULL)now = now->fail;
            if(now->child[c])now = now->child[c];
            if(now->N != -1)cout << "Got you" << endl;
        }
    }
    void release(Node* now = root){
        for(int i=0;i<MAXCHAR;i++)if(now->child[i])release(now->child[i]);
        delete now;
    }
};
