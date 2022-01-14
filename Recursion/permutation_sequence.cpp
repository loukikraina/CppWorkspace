public:
    int fact(int n){
        if(n<=1) return 1;
        int fac = 1;
        for(int i=2;i<=n;i++){
            fac *=i;
        }
        return fac;
        // return n*fact(n-1);
    }
    void leftR(int arr[], int pos, int size)
    {
        int last = arr[pos];
        for(int i=pos;i<size-1;i++) arr[i] = arr[i+1];
        arr[size-1] = last; 
    }
    
    void solve(string &ds, int n, int k, int arr[]){
        if(n<=0) return;
        
        int f = fact(n-1); 
        if(k<0) k=0;
        ds.push_back(arr[(k)/f] + '0');
        leftR(arr, (k)/f, n);
        solve(ds, n-1, (k)%f, arr);
    }
    
    
    string getPermutation(int n, int k) {
        // vector <int> ds;
        string str;
        int arr[n];
        for(int i=1;i<=n;i++) arr[i-1] = i;
        solve(str, n, k-1, arr);
        
        // for (int i: ds) {
        //     str.push_back(i + '0');
        // }
        return str;
    }