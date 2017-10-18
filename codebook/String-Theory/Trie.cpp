const int MAXCHAR = 26;
const char CHAR = 'a';

struct Trie{
	struct Node{
		int N;
		Node* child[MAXCHAR];
		Node():N(-1){ for(int i=0;i<MAXCHAR;i++) child[i] = NULL; }
	};

	Node* root;

	Trie(){ root = new Node; }
	~Trie(){ release(root); }

	void insert(string text, int id){
		Node* now = root;
		for(int i=0;i<SZ(text);i++){
			int c = text[i] - CHAR;
			if(now->child[c] == NULL) now->child[c] = new Node;
			now = now->child[c];
		}
		now->N = id;
	}
	
    void release(Node* now){
		for(int i=0;i<MAXCHAR;i++) if(now->child[i]) release(now->child[i]);
		delete now;
	}
};
