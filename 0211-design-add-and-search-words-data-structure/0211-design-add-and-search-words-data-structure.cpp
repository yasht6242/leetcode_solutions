class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class WordDictionary {
    TrieNode* root;
  

    bool searchInTrie(TrieNode* node, const string& word, int index) {
        if (index == word.size()) {
            return node->isEndOfWord;
        }

        char c = word[index];
        if (c == '.') { // Wildcard character
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && searchInTrie(node->children[i], word, index + 1)) {
                    return true;
                }
            }
        } else {
            int childIndex = c - 'a';
            if (node->children[childIndex] && searchInTrie(node->children[childIndex], word, index + 1)) {
                return true;
            }
        }

        return false;
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
     void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool search(string word) {
        return searchInTrie(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */