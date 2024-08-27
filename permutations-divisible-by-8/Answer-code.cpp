int solve(string s){
    int n=s.size();
    if(n<=2)
    {
        if(stoi(s)%8==0) return 1;
        reverse(s.begin(),s.end());
        if(stoi(s)%8==0) return 1;
        return 0;
    }
    int f[10]={0};
    for(int i=0;i<s.size();i++) f[s[i]-'0']++;
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=9;k++)
            {
                f[i]--;f[j]--;f[k]--;
                if(f[i]>=0 && f[j]>=0 && f[k]>=0 && (i*100+j*10+k)%8==0) return 1;
                f[i]++;f[j]++;f[k]++;
            }
        }
    }

    return 0;
}


vector<string> checkDivisibility(vector<string> arr){
    int n=arr.size();

    vector<string> ans;
    for(int i=0;i<n;i++)
    {
        if(solve(arr[i])) ans.push_back("YES");
        else ans.push_back("NO");
    }
    return ans;
}


