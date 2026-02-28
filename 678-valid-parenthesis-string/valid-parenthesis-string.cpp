class Solution {
public:
// Multiple  APPROACH KA QUESTION HAI  JAISA KI dp WITH BACKTRAKING  OR USE STACK TO IMPLEMENT THIS AND   ONE IS GREEDY

// acche se samjh nhi aaya akhir kyu min pen ko 0 kr de rhe h negative jaane par  
    bool checkValidString(string s) {
    
        int mini=0;
        int maxi=0;
        for(char ch :s){
            if(ch =='('){
                mini ++;
                maxi++;

            }
            else if (ch==')'){
                mini--;
                maxi--;
            
            }
            else{
                mini--;
                maxi++;
            }
            if(maxi<0) return false;
            if(mini<0)  mini=0;
        }
        return mini==0;

    }
};