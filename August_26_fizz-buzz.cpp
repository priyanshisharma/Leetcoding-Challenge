class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> s;
        for(int i=1; i<n+1; i++){
            if(i%3==0 && i%5==0){
                s.push_back("FizzBuzz");
            }else if(i%3==0){
                s.push_back("Fizz");
            }else if(i%5==0){
                s.push_back("Buzz");
            }else{
                string st = to_string(i);
                s.push_back(st);
            }
        }
        
        return s;
    }
};
