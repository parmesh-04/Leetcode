

class Solution {
private:
    std::vector<std::vector<std::string>> result;
    std::string beginWord;

    // Phase 2: DFS to build paths backward from endWord
    void dfs(const std::string& word, std::vector<std::string>& path, 
             const std::unordered_map<std::string, std::vector<std::string>>& parents) {
        
        // Add the current word to the path we are building
        path.push_back(word);

        // Base case: If we've reached the beginWord, a path is complete
        if (word == beginWord) {
            std::vector<std::string> completePath = path;
            // Reverse the path because we built it backward (end -> begin)
            std::reverse(completePath.begin(), completePath.end());
            result.push_back(completePath);
        } else {
            // Recursive step: explore all parents of the current word
            if (parents.count(word)) {
                for (const std::string& parent : parents.at(word)) {
                    dfs(parent, path, parents);
                }
            }
        }

        // Backtrack: remove the current word to explore other branches
        path.pop_back();
    }

public:
    std::vector<std::vector<std::string>> findLadders(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        this->beginWord = beginWord;
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.find(endWord) == wordSet.end()) {
            return {};
        }

        // --- Phase 1: BFS to find shortest path length and build parent graph ---
        std::queue<std::string> q;
        q.push(beginWord);

        // dist map also acts as our "visited" set
        std::unordered_map<std::string, int> dist;
        dist[beginWord] = 1;

        // The parent map: key is a word, value is a list of its parents on shortest paths
        std::unordered_map<std::string, std::vector<std::string>> parents;

        bool foundEnd = false;

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                std::string currentWord = q.front();
                q.pop();

                // Generate all one-letter-different neighbors
                std::string tempWord = currentWord;
                for (int j = 0; j < tempWord.length(); ++j) {
                    char originalChar = tempWord[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        tempWord[j] = c;
                        
                        if (wordSet.count(tempWord)) {
                            // Case 1: First time visiting this word.
                            if (dist.find(tempWord) == dist.end()) {
                                dist[tempWord] = dist[currentWord] + 1;
                                parents[tempWord].push_back(currentWord);
                                q.push(tempWord);
                                if (tempWord == endWord) foundEnd = true;
                            } 
                            // Case 2: Found another path of the same shortest length.
                            else if (dist[tempWord] == dist[currentWord] + 1) {
                                parents[tempWord].push_back(currentWord);
                            }
                        }
                    }
                    tempWord[j] = originalChar; // Backtrack
                }
            }
            // Optimization: If we found the endWord, no need to explore deeper levels.
            if (foundEnd) break;
        }

        // --- Phase 2: DFS to reconstruct paths from the parent graph ---
        if (foundEnd) {
            std::vector<std::string> currentPath;
            dfs(endWord, currentPath, parents);
        }

        return result;
    }
};