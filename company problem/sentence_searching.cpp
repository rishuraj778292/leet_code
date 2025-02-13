#include <bits/stdc++.h>
using namespace std;
void findmatch(string a, string pattern)
{
    if (pattern.size() > a.size())
    {
        cout << "Invalid input" << endl;
        return;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (pattern[0] == a[i])
        {
            if (i + pattern.size() - 1 > a.size())
            {
                cout << "No match Found";
                return ;
            }
            if (a.find(pattern))
            {
                cout << i << endl;
                return ;
            }
            else
            {
                if (i + pattern.size() - 1 > a.size())
                {
                    cout << "No match Found";
                    return ;
                }
                else
                {
                    int diff = 0;
                    int k=0;
                    for (int j = i; j < a.size(); j++)
                    {
                        if (a[j] != pattern[k++])
                        {
                            diff++;
                            if (diff > 1)
                            {
                                break;
                            }
                        }
                       if(k>=pattern.size()-1){
                          cout<<i<<endl;
                          return;
                       }
                    }
                   
                }
            }
        }
    }
    cout<<"Not found";
}

int main()
{

    string a;
    string pattern;
    cout << "a: ";
    getline(cin, a);
    cout << "Pattern: ";
    getline(cin, pattern);
    findmatch(a,pattern);
    return 0;
}