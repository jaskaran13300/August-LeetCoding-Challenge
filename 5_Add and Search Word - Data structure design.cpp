class WordDictionary {
public:
    /** Initialize your data structure here. */
    class Tries{
        public:
        bool endOfWord;
        Tries *children[26];
        
    };
    Tries * getNode(){
        Tries * node=new Tries();
        node->endOfWord=false;
        for(int i=0;i<26;i++){
            node->children[i]=NULL;
        }
        return node;
    }
    Tries *root=new Tries;
    WordDictionary() {
        root->endOfWord=false;
        for(int i=0;i<26;i++){
            root->children[i]=NULL;
        }
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Tries * temp=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(temp->children[index]==NULL){
                temp->children[index]=getNode();
            }
            temp=temp->children[index];
        }
        temp->endOfWord=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        Tries * temp=root;
        // for(int i=0;i<word.size();i++){
        //     // if(word[i]=='.'){
        //     //     mysearch()
        //     // }
        //     int index=word[i]-'a';
        //     if(temp->children[index]!=NULL){
        //         temp=temp->children[index];
        //     }
        //     else{
        //         return false;
        //     }
        // }
        // if(temp->endOfWord){
        //     return true;
        // }
        // return false;
        return searchHelper(word,root);
    }
    private:
    bool searchHelper(string word,Tries * current){
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(word[i]!='.'){
                int index=word[i]-'a';
                if(current->children[index]==NULL){
                    return false;
                }
                current=current->children[index];
            }
            else{
                for(int j=0;j<26;j++){
                    if(current->children[j])
                        if(searchHelper(word.substr(i+1),current->children[j])){
                            return true;
                        }
                }
                return false;
            }
        }
        return current->endOfWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
