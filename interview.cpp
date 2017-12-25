
int main () {
    unordered_map<string, pair<string, string>> lookup;
    auto fs1 = ifstream("file1");
    auto fs2 = ifstream("file2");
    while (!fs1.eof()) {
        string line;
        string age;
        string name;
        fs1.getline(line);
        auto ss = stringstream(line);
        ss >> age >> name;
        lookup[age].first = move(name);
    }

    while (!fs2.eof()) {
        string line;
        string age;
        string id;
        fs1.getline(line);
        auto ss = stringstream(line);
        ss >> age >> id;
        lookup[age].second = move(id);
    }

    vector<pair<string, pair<string, string>> vec;
    for (auto &itm : lookup) {
        vec.emplace_back(itm);
    }

    auto cmp = [](const pair<string, pair<string, string>> &p1, const pair<string, pair<string, string>> &p2) {
        return p1.second.second < p2.second.second;
    };
    sort (vec.begin(), vec.end(), cmp);

    auto fs3 = ofstream("file3");
    for (auto &itm : vec) {
        if (!itm.second.second.empty()) {
            fs3 << itm.first << " " << itm.second.first << " " << itm.second.second << endl;
        }
    }
}
