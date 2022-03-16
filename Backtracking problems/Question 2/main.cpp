#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
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
const int n=9;
int ans=0;
//char arr[n][n];

bool isSafe(int arr[n][n],int x,int y){
    if(x>n-1 || y>n-1)
        return false;
    if(x<0 || y<0)
        return false;

    if(arr[x][y] == 1){
        return false;
    }
    return true;
}

bool check(int arr[n][n]){
    //cout<<"New function "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //cout<<arr[i][j]<<" ";
            if(arr[i][j] !=1)
                return false;
        }
        //cout<<endl;
    }
    return true;
}

void nQueen(int arr[n][n],int x,int y,int last){

    if(x==n-1 && y==n-1){
        arr[x][y] = 1;
        //cout<<"YES"<<endl;
        if(check(arr))
            ans++;
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                cout<<arr[i][j]<<" ";
//            }
//            cout<<endl;
//        }

        return;
    }
    if(isSafe(arr,x,y)){
        arr[x][y] = 1;

        switch (last) {
        case 0:
            if(isSafe(arr,x+1,y) == false && y>0 && y<n-1){
                if(arr[x][y-1] == 0 && arr[x][y+1] == 0){
                    arr[x][y] = 0;
                    return;
                }
            }
            break;
        case 1:
            if(isSafe(arr,x,y-1) == false && x>0 && x<n-1){
                if(arr[x-1][y] == 0 && arr[x+1][y] == 0){
                    arr[x][y] = 0;
                    return;
                }
            }
            break;
        case 2:
            if(isSafe(arr,x-1,y) == false && y>0 && y<n-1){
                if(arr[x][y-1] == 0 && arr[x][y+1] == 0){
                    arr[x][y] = 0;
                    return;
                }
            }
            break;
        case 3:
            if(isSafe(arr,x,y+1) == false && x>0 && x<n-1){
                if(arr[x-1][y] == 0 && arr[x+1][y] == 0){
                    arr[x][y] = 0;
                    return;
                }
            }
            break;
        }

        nQueen(arr,x+1,y,0);
        nQueen(arr,x-1,y,2);
        nQueen(arr,x,y+1,3);
        nQueen(arr,x,y-1,1);
        arr[x][y] = 0;
    }
    return;
}


void solve(){
    int arr[n][n]={0};

//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++)
//            cout<<arr[i][j]<<" ";
//        cout<<endl;
//    }
    arr[0][0] = 1;
    nQueen(arr,1,0,0);

    cout<<"Ans is "<<2*ans<<endl;

}

int main(){
    cin.tie(0);
     cin.sync_with_stdio(0);

//    freopen("balancing.in","r",stdin);
//    freopen("balancing.out","w",stdout);
//    int t;
//    cin>>t;
//     for(int i=0;i<t;i++)
    cout<<"N is "<<n<<endl;
    auto start = high_resolution_clock::now();

    solve();

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"Time in microseconds : "<<duration.count()<<" Time in second : "<<duration.count()/1000<<endl;

    return 0;
}
