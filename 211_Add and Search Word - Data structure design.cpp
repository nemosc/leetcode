class TrieNode{
public:
    unordered_map<char,TrieNode*> next;
};
class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        
        for(char ch: word)
        {
            if(cur->next.find(ch)==cur->next.end())
            {
                cur->next[ch] = new TrieNode;
            }
            cur = cur->next[ch];
        }
        if(!cur->next['\0']) cur->next['\0'] = new TrieNode;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        stack<pair<TrieNode*,int> > dfs;
        dfs.push(make_pair(root,0));
        bool ok = false;
        while(!ok && !dfs.empty())
        {
            TrieNode* cur = dfs.top().first;
            int i = dfs.top().second;
            dfs.pop();
            if(i==word.size())
            {
                ok |= (cur->next.find('\0')!=cur->next.end());
                
            }
            else
            {
                if(word[i]=='.')
                {

                    for(auto it = cur->next.begin();it!=cur->next.end();++it)
                    {
                        if(it->first!='\0')
                        {
                            dfs.push(make_pair(it->second,i+1));
                        }
                    }
                }
                else
                {
                    if(cur->next.find(word[i])!=cur->next.end())
                    {
                        dfs.push(make_pair(cur->next[word[i]],i+1));
                    }
                }
            }
        }
        return ok;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(char ch: prefix)
        {
            if(!cur->next[ch])
            {
                return false;
            }
            cur = cur->next[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
class WordDictionary {
public:
    /** Initialize your data structure here. */
    Trie trie;
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        trie.insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return trie.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
