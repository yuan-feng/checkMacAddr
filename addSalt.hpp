#include <string>
void addSalt(std::string& str){
    static std::string salt = "~!@#$%^&*()_+";
    std::string interleved;
    int n = str.size() ; 
    int count = 0 , id1 = 0 , id2 = 0 ; 
    for (int i = 0 ; i < 2*n; i++ )
    {
        count++;
        switch( count % 2){
            case 0 :{
                interleved.push_back(salt[id1++]);
                break;
            }
            case 1: {
                interleved.push_back(str[id2++]);
                break;
            }
        }
    }
    str = interleved ; 
}

