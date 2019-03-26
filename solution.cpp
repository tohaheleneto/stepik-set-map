#include <iostream>
#include <unordered_map>
#include <set>
#define  dictionary unordered_map <string,set<string>>

using namespace std;

string to_lower(string t)
{
    for (int i = 0;i < t.size();i++)
    {
        if ('A' <=t[i] && t[i] <= 'Z')
            t[i] = t[i] + 'a' - 'A';
    }
    return t;
}

int count_upper_case(string s)
{
    int count = 0;
    for (int i = 0;i < s.size();i++)
    {
        if ('A' <=s[i] && s[i] <= 'Z')
            ++count;
    }
    return count;
}

bool check_word(string temp,dictionary &m)
{
    
    string lower = to_lower(temp);
    auto it = m.find(lower);
    return it != m.end() && it->second.find(temp) == it->second.end() || count_upper_case(temp) != 1;
}

int main()
{
    dictionary m;
    int n,count = 0,prev_pos = 0;
    string s,temp;

    cin >> n;

    for (int i = 0;i < n;i++)
    {
        cin >> s;
        string lower = to_lower(s);
        m.insert(pair<string,set <string> >(lower,set<string>()));
        m[lower].insert(s);
    }

    cin.ignore(200,'\n');
    getline(cin,s);
    n = s.find(' ');
    while (n != -1)
    {
        temp = s.substr(prev_pos,n - prev_pos);
        if (check_word(temp,m))
            ++count;
        prev_pos = n + 1;
        n = s.find(' ',prev_pos);
    } 
    temp = s.substr(prev_pos,s.size() - prev_pos);
    if (check_word(temp,m))
        ++count;
    cout << count;

}