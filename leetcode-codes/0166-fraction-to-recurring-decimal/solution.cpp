#define ll long long
class Solution {
public:

string fractionToDecimal(int numerator, int denominator) {
    ll num1 = abs(numerator);
    ll num2 = abs(denominator);
    string res;
    if((ll)numerator*(ll)denominator<0)res+="-";
    unordered_map<ll,ll> check;
    
    ll quotient = num1/num2;
    ll remainder = num1%num2;
    res+=to_string(quotient);
    
    if(remainder == 0)return res;
    res+=".";

    while(remainder){        
        if(check.count(remainder)){
            res.insert(res.begin()+check[remainder],'(');
            res+=")";
            break;
        }
        check[remainder]=res.size();
        remainder *=10;
        quotient =remainder/num2;
        remainder %=num2;
        res+=to_string(quotient);
    }
    return res;
}
};
