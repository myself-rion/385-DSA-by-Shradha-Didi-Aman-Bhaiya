class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        // create a queue for bfs
        queue<pair<string, int>> q;
        q.push({startWord, 1});

        // put all the words in a set so that we can use .find() instead of linearly searching the entire wordList
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);

        while (!q.empty())
        {
            string word = q.front().first;
            int level = q.front().second;
            q.pop();

            if (word == targetWord)
                return level; // if we reach the target word then we can return the level

            for (int i = 0; i < word.size(); ++i)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ++ch)
                {
                    word[i] = ch;
                    if (st.find(word) != st.end())
                    { // if we find the word in set then we will push it in queue
                        q.push({word, level + 1});
                        st.erase(word);
                    }
                }
                word[i] = original; // putting the original value back
            }
        }

        return 0; //incase we can't find the target word from the start word
    }
};