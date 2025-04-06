class Solution {
    public:
        typedef long long ll; 
        //int N = 8e5 + 5;
        struct DL
        {
            ll mi, sum ; 
        } tree[(int) 1e6 + 5]; 
        ll a[(int) 8e5 + 5] , b[(int) 8e5 + 5]; 
        void build(int id , int l ,int r )
        {   
            if(l==r)
            {
                tree[id].sum = a[l] ; 
                tree[id].mi = a[l]; 
                return ; 
            }
            int mid = (l+r)/2 ; 
            build(id*2,l,mid) ; 
            build(id*2+1,mid+1,r) ; 
            tree[id].sum = tree[id*2].sum + tree[id*2 + 1].sum;
            tree[id].mi = min(tree[id*2].mi , tree[id*2+1].mi + tree[id*2].sum) ; 
        }
    
        DL get(int id ,int l ,int r ,int t ,int p )
        {
            if(t<=l&&r<=p)return tree[id];  
            if(r<t||l>p)return {(ll)1e12,0} ;
            DL get1 = get(id*2,l, (l+r)/2 ,t,p) ;
            DL get2 = get(id*2+1,(l+r)/2 + 1,r,t,p) ;
            DL res ;
            res.sum = get1.sum + get2.sum ;
            res.mi = min(get1.mi , get2.mi + get1.sum) ;
            return res ;
        }
        int n;
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            n = gas.size();
            for(int i=1;i<=n;i++) a[i] = gas[i - 1]; 
            for(int i=1;i<=n;i++) b[i] = cost[i - 1] ,a[i]-=b[i] ; 
            for(int i=n+1;i<=2*n;i++)a[i] = a[i-n] ;
            build(1,1,2*n) ; 
            for(int i=1;i<=n;i++)
                if (get(1,1,2*n,i,i+n-1).mi >= 0) return i - 1;
            return -1;
        }
    };