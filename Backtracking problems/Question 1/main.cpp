#include<bits/stdc++.h>
using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T, class U = null_type, class chash = hash<T>> using hset = gp_hash_table<T,U,chash>;
template<class T, class U = null_type, class cmp = less<T>> using oset = tree<T,U,cmp,rb_tree_tag,tree_order_statistics_node_update>;
#define fbo find_by_order
#define ook order_of_key
*/

using ll = long long;
using pii = pair<int,int>;
#define f first
#define s second
#define eb emplace_back

/*
template<typename T>
struct number_iterator : std::iterator<random_access_iterator_tag, T>{
    T v;
    number_iterator(T _v) : v(_v) {}
    operator T&(){return v;}
    T operator *() const {return v;}
};
template <typename T>
struct number_range {
    T b,e;
    number_range(T b, T e):b(b),e(e){}
    number_iterator<T> begin(){return b;}
    number_iterator<T> end(){return e;}
};
template<typename T> number_range<T> range(T e) {return number_range<T>(0, e);}
template<typename T> number_range<T> range(T b, T e) {return number_range<T>(b, e);}
*/
const int n=14;
int ans=0;
//char arr[n][n];

bool isSafe(char arr[n][n],int x,int y){

    if(arr[x][y] == '*'){
        return false;
    }

    for(int row=0;row<x;row++){
        if(arr[row][y]=='1'){
            return false;
        }
    }
    int row=x;
    int col=y;
    while(row>=0 && col>=0){
        if(arr[row][col]=='1'){
            return false;
        }
        row--;
        col--;
    }
    row=x;
    col=y;
    while(row>=0 && col<n){
        if(arr[row][col]=='1'){
            return false;
        }
        row--;
        col++;
    }

    return true;
}

void nQueen(char arr[n][n],int x){

    if(x>=n){
        ans++;
//        cout<<"Ans no"<<ans<<endl;
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++)
//                cout<<arr[i][j];
//            cout<<endl;
//        }
        return;
    }
    for(int col=0;col<n;col++){
        if(isSafe(arr,x,col)){
            char temp = arr[x][col];
            arr[x][col]='1';

            nQueen(arr,x+1);

            arr[x][col]=temp;
        }
    }
    return;
}


void solve(){

    char arr[n][n];
    cout<<"Value of n is "<<n<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    nQueen(arr,0);
    cout<<ans<<endl;
}

int main(){
    cin.tie(0);
     cin.sync_with_stdio(0);

//    freopen("balancing.in","r",stdin);
//    freopen("balancing.out","w",stdout);
//    int t;
//    cin>>t;
//     for(int i=0;i<t;i++)
    solve();
    return 0;
}
