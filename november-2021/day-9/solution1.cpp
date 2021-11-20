class Solution {
private:
    int bitmask(const string& word) {
        int mask = 0;
        for (char letter : word) {
            mask |= 1 << (letter - 'a');
        }
        return mask;
    }

public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> wordCount;
        for (string& word : words) {
            wordCount[bitmask(word)]++;
        }
        vector<int> result;
        for (string& puzzle : puzzles) {
            int first = 1 << (puzzle[0] - 'a');
            int count = wordCount[first];

            int mask = bitmask(puzzle.substr(1));

            for (int submask = mask; submask; submask = (submask - 1) & mask) {
                count += wordCount[submask | first];
            }
            result.push_back(count);
        }
        return result;
    }
};