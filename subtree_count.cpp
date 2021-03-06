// Count subtree whose nodes lie in given range.
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod=1e9+7;
#define take_input freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
class tree{
public:
	tree *right,*left;
	ll val;
	tree(ll val)
	{
		this->val=val;
		this->right=this->left=nullptr;
	}
};

tree *insert(tree *root,ll val)
{
	if(!root)
		return new tree(val);
	if(val<root->val)
		root->left=insert(root->left,val);
	else
		root->right=insert(root->right,val);
	return root;
}
bool inrange(ll val,ll a,ll b)
{
	return (val>=a) and (val<=b);
}
bool go(tree *root,ll low,ll high,ll &cnt)
{
	if(root==nullptr)
		return true;

	if(go(root->left,low,high,cnt) and go(root->right,low,high,cnt) and inrange(root->val,low,high))
	{
		cnt++;
		return true;
	}
	return false;

}
int main()
{
	// take_input;
	fast;
	tree *root=nullptr;
	ll n;
	cin>>n;
	while(n--)
	{
		ll val;
		cin>>val;
		root=insert(root,val);
	}
	ll low,high;
	cin>>low>>high;
	ll cnt=0;

	go(root,low,high,cnt);
	cout<<cnt<<endl;
	return 0;

}