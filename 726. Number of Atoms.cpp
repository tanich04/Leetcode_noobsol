class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> stk;
        stk.push({});
        
        for (int i = 0; i < formula.length(); ) {
            if (formula[i] == '(') {
                stk.push({});
                i++;
            } else if (formula[i] == ')') {
                auto top = stk.top(); stk.pop();
                int iStart = ++i, multiplicity = 1;
                while (i < formula.length() && isdigit(formula[i])) i++;
                if (i > iStart) multiplicity = stoi(formula.substr(iStart, i - iStart));
                for (auto &p : top) stk.top()[p.first] += p.second * multiplicity;
            } else {
                int iStart = i++;
                while (i < formula.length() && islower(formula[i])) i++;
                string name = formula.substr(iStart, i - iStart);
                iStart = i;
                while (i < formula.length() && isdigit(formula[i])) i++;
                int multiplicity = i > iStart ? stoi(formula.substr(iStart, i - iStart)) : 1;
                stk.top()[name] += multiplicity;
            }
        }
        
        map<string, int> count;
        for (auto &p : stk.top()) count[p.first] = p.second;
        
        string result;
        for (auto &p : count) {
            result += p.first;
            if (p.second > 1) result += to_string(p.second);
        }
        return result;
    }
};