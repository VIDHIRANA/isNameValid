
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int a = 0, e = 0 , i = 0, o = 0, u = 0, S = 0, T = 0, j, k, sPosition[20], tPosition[20];

// Function that returns true if c is a vowel
int isVowel(char c)
{ 
	c = tolower(c);
	if (c == 'a')
    {
        a++;
    }
    if (c == 'e')
    {
        e++;
    }
    if (c == 'i')
    {
        i++;
    }
    if (c == 'o')
    {
        o++;
    }
    if (c == 'u')
    {
        u++;
    }
	 c= toupper(c);
    if (c == 'S'){
        S++;
            for (j = 0; j< S; j++){
                sPosition[j] =  i; 
            }
    }
    if (c == 'T'){
        T++;
        for ( k = 0; k< T; k++){
                tPosition[k] =  i; 
            }
    }
	return 0;
}

//checking if name isvalid or not 
bool isValidName(string word)
{
	int cnt = 0;
//checking the counts of vowels, S and T
	for (int i = 0; i < word.length(); i++) {
		isVowel(word[i]);
	}
    // if any vowel is used more than once
    if ( a < 2 && e < 2 && i < 2 && o < 2 && u < 2){
     // checking if the T position is between 2 S's position
      if (S >= 2 && T >= 1){
         for (int l = 0; l< S; l++){
                 for (int m = 0; m< T; m++){
                    if (tPosition[m] > sPosition[l] && tPosition[m] < sPosition[l+1] ){
                     return false;
                     }
                    else {
                        return true;
                    }   
             }
         }
     }
     else {
         return true;
         }
 }
 return 0;
}


int main()
{
	string s = "gfdgfeaffSggTggS";
	if (isValidName(s))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
