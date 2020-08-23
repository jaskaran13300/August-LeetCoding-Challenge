struct TrieNode {
    struct TrieNode* children[26];
    bool wordEnd;
};
struct TrieNode *getNewNode() { 
    struct TrieNode *pNode =  new TrieNode; 
    pNode->wordEnd = false; 
    for (int i = 0; i < 26; i++) 
        pNode->children[i] = NULL; 
    return pNode; 
} 
class StreamChecker {
public:
    TrieNode *root = new TrieNode();
    string s = "";
    StreamChecker(vector<string>& words) {
        for(string word: words) {
            TrieNode* tmp = root;
            reverse(word.begin(), word.end());
            for(char c : word) {
                int ind = c - 'a';
                if(!tmp->children[ind]) {
                    tmp->children[ind] = getNewNode();
                }
                tmp = tmp->children[ind];
            }
            tmp->wordEnd = true;
        }
    }
    
    bool query(char letter) {
        s += letter;
        TrieNode *tmp = root; 
        for(int i = s.size() - 1; i >= 0; i--) {
            int index = s[i] - 'a'; 
            tmp = tmp->children[index]; 
            if( tmp != NULL && tmp->wordEnd) return true;
            if( tmp == NULL) return false;
        }
        return false;
    }
};
