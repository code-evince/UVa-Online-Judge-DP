#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cost[25][25];
int m,c,k;
int dp[210][25];

#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

int buy(int money_left,int next_item){           //  dp[money_left][next_item] represents the max expense made on buying (next_item-1) items and spending (m-money_left) money

  if(money_left<0) return -100000000;

  if(next_item==c) return m-money_left;

  if(dp[money_left][next_item]!=-1) return dp[money_left][next_item];

  int expense = -100000000;
  rep(model,1,cost[next_item][0]+1){                                                   //   cost[x][0] stores the number of models of each garment
    expense = max(expense,buy(money_left-cost[next_item][model],next_item+1));
  }
  return dp[money_left][next_item]=expense;


}


int main(){
  ll t;           // t=1 in case of no testcases
  cin>>t;           // comment out in case of no test cases
  while(t--){

    cin>>m>>c;
    rep(i,0,c){
      cin>>k;
      cost[i][0]=k;
      rep(j,1,k+1){
        cin>>cost[i][j];
      }
    }
    mem1(dp);
    int ans = buy(m,0);
    if(ans<0) cout<<"no solution"<<endl;
    else cout<<ans<<endl;

  }
}
