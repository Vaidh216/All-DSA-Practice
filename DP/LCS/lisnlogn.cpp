//Longest increasing subsequences in N*logN complexity
/*
    Here we insert the elements in the seqence if we found that it is greater than the greatest element.
    if the current element is less than the greatest element of the sequence we will replace the lowest value greater or equal to the value of the vector
    the sequence size is the answer
*/
/*
    If we want to prepare an array to find the maximum length of the lis till the current value in the value then
    we can maintain another array which will take care of this as illistrate in 
    section 2.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &x:v)
        cin>>x;

    vector<int> seq;
    seq.push_back(v[0]);
    for(int i=1;i<n;i++){
        if(v[i] > seq.back()){
            seq.push_back(v[i]);
        }else{
            int ind = lower_bound(seq.begin(),seq.end(),v[i])-seq.begin();
            seq[ind] = v[i];
        }
    }
    cout<<"LIS is "<<seq.size()<<"\n";



}