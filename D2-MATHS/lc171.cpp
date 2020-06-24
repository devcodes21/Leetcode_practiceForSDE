auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
} ();
class Solution {
public:
    int titleToNumber(string s) {
            int i = 0;
            int colNo = 0;
            while(i<s.size())
            {
               colNo = colNo*26 + (s.at(i)-'A'+1);
               i++;      
            }
            return colNo;
        
    }
};
/*
A - 1
B - 2
...        
Z - 26
AA - 27
AB - 28
..
AZ - 52
..
BA - 53
BB - 54
..
BZ - 78
..
CA - 79
CB - 80
..
CZ - 104        
*/