class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        isTerminal = false;
    }
};

class Trie
{

public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
    {

        if (curr->isTerminal)
        {
            temp.push_back(prefix);
            // return; no return because there can be nodes after the terminal node as well.
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];

            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str)
    {

        TrieNode *prev = root;
        string prefix = "";
        vector<vector<string>> output;
        int i;
        for (i = 0; i < str.length(); i++)
        {
            char lastch = str[i];

            prefix.push_back(lastch);

            TrieNode *curr = prev->children[lastch - 'a'];

            if (curr == NULL)
            {
                break;
            }

            vector<string> temp; // storing suggestions;

            printSuggestions(curr, temp, prefix);

            output.push_back(temp); // storing suggestions for each letter added
            temp.clear();

            prev = curr;
        }

        if (i < str.size())     //if the word is not in directory
        {

            while (i < str.size())
            {

                output.push_back({"0"});

                i++;
            }
        }

        return output;
    }
};

class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie *t = new Trie();

        for (int i = 0; i < n; i++)
        {
            t->insert(contact[i]);
        }

        return t->getSuggestions(s);
    }
};

// T.C: O(n*m^2)
// S.C: O(m*n)