// copying the string into another string into reverse order


string reverseWord(string str)
{
    string it1;
    for(int i = str.size()-1; i>=0; i--){
        it1.push_back(str[i]);
    }
  return it1;
}
