
int Isposs(string s,int mid){
    int n=s.size();
    int c=1;
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1]) 
        {
            if(c==mid)
            {
                c=1;
                if(s[i-1]=='a') s[i]='b';
                else s[i]='a';
                ans++;
            }
            else c++;
        }
        else
        {
            c=1;
        }
    }

    return ans;
}

int findMinimumIdleness(string shader, int switchcount) {

    int k=switchcount;
    string s=shader;
    int c=1;
    int n=s.size();
    int l=0,r=n+2;
    while(l+1<r)
    {
        int mid=(l+r)/2;
        if(Isposs(s,mid)<=k) r=mid;
        else l=mid;
    }
    return r;
}


