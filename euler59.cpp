#include "euler.hpp"

string xorciph(const vector<char>&, vector<char>);
bool all_plaintext(const string&);
string find_result(const vector<char>&);
int sum_ascii_values(const string&);
int main(void);

string xorciph(const vector<char>& key, vector<char> target) {
    for (size_t i = 0; i < target.size(); ++i)
        target[i] ^= key[i % 3];
    return string(target.begin(), target.end());
}

bool all_plaintext(const string& cand) {
    for (size_t i = 0; i < cand.size(); ++i) {
        if (cand[i] >= ' ' && cand[i] <= '@')
            continue;
        if (cand[i] >= 'A' && cand[i] <= 'Z')
            continue;
        if (cand[i] >= 'a' && cand[i] <= 'z')
            continue;
        return false;
    }
    return true;
}

string find_result(const vector<char>& data) {
    vector<char> xorkey(3);
    string current;
    for (int i = 'a'; i <= 'z'; ++i) {
        for (int j = 'a'; j <= 'z'; ++j) {
            for (int k = 'a'; k <= 'z'; ++k) {
                xorkey[0] = i;
                xorkey[1] = j;
                xorkey[2] = k;
                current = xorciph(xorkey, data);
                if (all_plaintext(current))
                    return current;
            }
        }
    }
    return current;
}

int sum_ascii_values(const string& message) {
    int result = 0;
    for (auto it = message.begin(); it != message.end(); ++it)
        result += *it;
    return result;
}

int main(void) {
    vector<char> data;
    string datastring;
    string current;
    std::ifstream datafile("e59.dat");
    getline(datafile, datastring);
    for (size_t i = 0; i < datastring.size(); ++i) {
        if (datastring[i] == ',') {
            data.push_back(std::stoi(current));
            current = "";
            continue;
        }
        current += datastring[i];
        if (i == datastring.size() - 1)
            // there's no comma at the end of the last one
            data.push_back(std::stoi(current));
    }
    current = find_result(data);
    cout << "Text: \n" << current << endl;
    cout << "Answer: " << sum_ascii_values(current) << '\n';
    return 0;
}
