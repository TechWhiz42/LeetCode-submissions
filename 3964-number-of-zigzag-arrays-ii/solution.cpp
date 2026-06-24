class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    struct Matrix {
        vector<vector<long long>> a;

        Matrix(int n) {
            a.assign(n, vector<long long>(n, 0));
        }
    };

    Matrix multiplyMat(const Matrix& A,
                       const Matrix& B)
    {
        int n = A.a.size();

        Matrix C(n);

        for(int i=0;i<n;i++)
        {
            for(int k=0;k<n;k++)
            {
                if(A.a[i][k]==0) continue;

                for(int j=0;j<n;j++)
                {
                    C.a[i][j] =
                    (C.a[i][j] +
                     A.a[i][k] * B.a[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base,long long exp)
    {
        int n = base.a.size();

        Matrix res(n);

        for(int i=0;i<n;i++)
            res.a[i][i]=1;

        while(exp)
        {
            if(exp&1)
                res=multiplyMat(res,base);

            base=multiplyMat(base,base);

            exp>>=1;
        }

        return res;
    }

    vector<long long> multiplyVec(
        const Matrix& M,
        const vector<long long>& v)
    {
        int n=M.a.size();

        vector<long long> ans(n,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i] =
                (ans[i] +
                 M.a[i][j]*v[j]) % MOD;
            }
        }

        return ans;
    }

    int zigZagArrays(int n, int l, int r) {

        long long m = r-l+1;

        if(n==1)
            return m % MOD;

        if(n==2)
            return (m*(m-1))%MOD;

        int S = 2*m;

        Matrix T(S);

        for(int y=0;y<m;y++)
        {
            for(int x=0;x<y;x++)
                T.a[y][m+x]=1;

            for(int x=y+1;x<m;x++)
                T.a[m+y][x]=1;
        }

        vector<long long> base(S,0);

        for(int a=0;a<m;a++)
        {
            for(int b=0;b<m;b++)
            {
                if(a<b)
                    base[b]++;

                else if(a>b)
                    base[m+b]++;
            }
        }

        Matrix P = power(T,n-2);

        vector<long long> finalState =
            multiplyVec(P,base);

        long long ans=0;

        for(long long x: finalState)
            ans=(ans+x)%MOD;

        return (int)ans;
    }
};
