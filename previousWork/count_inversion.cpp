long long int inversion=0;
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        mergesort(arr,temp,0,N-1);
        return inversion;
    }
    void mergesort(long long arr[], long long temp[], long long l, long long r)
    {
        if(l<r){
            long long mid = (l+r)/2;
            mergesort(arr,temp,l,mid);
            mergesort(arr,temp,mid+1,r);
            inversion += merge(arr,temp,l,mid+1,r);
        }
    }
    long long int merge(long long arr[], long long temp[], long long l, long long m, long long r)
    {
        long long int inver=0;
        long long i=l,j=m,k=0;
        while(i<m && j<=r)
        {
            if(arr[i]<=arr[j]){
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
                inver += m-i;
            }
        }
        for(;i<m;i++)
            temp[k++] = arr[i];
        for(;j<=r;j++)
            temp[k++] = arr[j];
        k=0;
        for(i=l;i<=r;i++)
            arr[i] = temp[k++];
        // cout<<"Left: "<<l<<", Right: "<<r<<", Inversion current: "<<inver<<endl;
        return inver;
    }