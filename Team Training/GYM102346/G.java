import java.io.*;
import java.util.*;
import java.math.BigInteger;

/**
 __                  __
 ( _)                ( _)
 / / \\              / /\_\_
 / /   \\            / / | \ \
 / /     \\          / /  |\ \ \
 /  /   ,  \ ,       / /   /|  \ \
 /  /    |\_ /|      / /   / \   \_\
 /  /  |\/ _ '_| \   / /   /   \    \\
 |  /   |/  0 \0\    / |    |    \    \\
 |    |\|      \_\_ /  /    |     \    \\
 |  | |/    \.\ o\o)  /      \     |    \\
 \    |     /\\`v-v  /        |    |     \\
 | \/    /_| \\_|  /         |    | \    \\
 | |    /__/_ `-` /   _____  |    |  \    \\
 \|    [__]  \_/  |_________  \   |   \    ()
 /    [___] (    \         \  |\ |   |   //
 |    [___]                  |\| \|   /  |/
 /|    [____]                  \  |/\ / / ||
 (  \   [____ /     ) _\      \  \    \| | ||
 \  \  [_____|    / /     __/    \   / / //
 |   \ [_____/   / /        \    |   \/ //
 |   /  '----|   /=\____   _/    |   / //
 __ /  /        |  /   ___/  _/\    \  | ||
 (/-(/-\)       /   \  (/\/\)/  |    /  | /
 (/\/\)           /   /   //
 _________/   /    /
 \____________/    (


 @author NTUDragons-Reborn
 */

public class G{
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }
    // main solver
    static class Task{

        double eps= 0.00000001;
        static final int MAXN = (int)(1e5+10);
        static final int MOD= 1000000007;

        // stores smallest prime factor for every number
        static int spf[] = new int[MAXN];

        Map<Integer,Set<Integer>> dp= new HashMap<>();

        // Calculating SPF (Smallest Prime Factor) for every
        // number till MAXN.
        // Time Complexity : O(nloglogn)
        public void sieve()
        {
            spf[1] = 1;
            for (int i=2; i<MAXN; i++)

                // marking smallest prime factor for every
                // number to be itself.
                spf[i] = i;

            // separately marking spf for every even
            // number as 2
            for (int i=4; i<MAXN; i+=2)
                spf[i] = 2;

            for (int i=3; i*i<MAXN; i++)
            {
                // checking if i is prime
                if (spf[i] == i)
                {
                    // marking SPF for all numbers divisible by i
                    for (int j=i*i; j<MAXN; j+=i)

                        // marking spf[j] if it is not
                        // previously marked
                        if (spf[j]==j)
                            spf[j] = i;
                }
            }
        }

        // A O(log n) function returning primefactorization
        // by dividing by smallest prime factor at every step
        public Set<Integer> getFactorization(int x)
        {
            if(dp.containsKey(x)) return dp.get(x);
            Set<Integer> ret = new HashSet<>();
            while (x != 1)
            {
                if(spf[x]!=2) ret.add(spf[x]);
                x = x / spf[x];
            }
            dp.put(x,ret);
            return ret;
        }
        // function to find first index >= x
        public int lowerIndex(List<Integer> arr, int n, int x)
        {
            int l = 0, h = n - 1;
            while (l <= h)
            {
                int mid = (l + h) / 2;
                if (arr.get(mid) >= x)
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            return l;
        }

        // function to find last index <= y
        public int upperIndex(List<Integer> arr, int n, int y)
        {
            int l = 0, h = n - 1;
            while (l <= h)
            {
                int mid = (l + h) / 2;
                if (arr.get(mid) <= y)
                    l = mid + 1;
                else
                    h = mid - 1;
            }
            return h;
        }

        // function to count elements within given range
        public int countInRange(List<Integer> arr, int n, int x, int y)
        {
            // initialize result
            int count = 0;
            count = upperIndex(arr, n, y) -
                    lowerIndex(arr, n, x) + 1;
            return count;
        }

        public int _gcd(int a,  int  b)
        {

            if(b == 0) {
                return a;
            }
            else {
                return _gcd(b, a % b);
            }
        }

        public long add(long a, long b){
            a+=b;
            if(a>=MOD) a-=MOD;
            else if(a<0) a+=MOD;
            return a;
        }

        public long mul(long a, long b){
            long res= (long)a*(long)b;
            return (res%MOD);
        }

        public long power(long a, long b) {
            long ans=1;
            while(b>0){
                if((b&1)!=0) ans= mul(ans,a);
                b>>=1;
                a= mul(a,a);
            }
            return ans;
        }

        long[] fact= new long[MAXN];
        long[] inv= new long[MAXN];
        long[][] Ckn = new long[51][51];


        public long Ckn(int n, int k){
            if(k<0 || n<0) return 0;
            if (n < k) return 0;
            return Ckn[n][k];
        }

        public long inverse(long a){
            return power(a,MOD-2);
        }

        public void preprocess() {
            for (int i = 0; i < 51; i++){
                Ckn[i][i] = 1;
                Ckn[i][0] = 1;
                for (int j = i; j > 0; j--){
                    Ckn[i][j] = Ckn[i-1][j] + Ckn[i-1][j-1];
                }
            }
        }
        
        int n,k;
        int[] w= new int[MAXN];
        List[] adj= new List[MAXN];
        PriorityQueue<Integer> q= new PriorityQueue<>((a,b)-> b-a);
        InputReader in; PrintWriter out;
        public void solve(InputReader in, PrintWriter out) {
            this.in=in; this.out=out;
            int n= in.nextInt(), k= in.nextInt();
            int u;
            for(int i=0;i<MAXN;i++) adj[i]= new ArrayList<>();
            for(int i=2;i<=n;i++){
                u= in.nextInt();
                adj[u].add(i);
            }
            dfs(1);
            q.add(w[1]);
            int ans=0;
            while(k-->0 && !q.isEmpty()){
                ans+= q.poll();
            }
            out.println(ans);

        }

        private void dfs(int u){
            int max=0;
            w[u]=1;
            for(int v: (List<Integer>)adj[u]){
                dfs(v);
                if(w[v]>w[max]) max=v;
            }
            for(int v: (List<Integer>)adj[u]){
                if(v!=max) q.add(w[v]);
            }
            w[u] += w[max];
        }


    }

    static class Venice{
        public Map<Long,Long> m= new HashMap<>();
        public long base=0;
        public long totalValue=0;
        private int M= 1000000007;

        private long addMod(long a, long b){
            a+=b;
            if(a>=M) a-=M;
            return a;
        }

        public void reset(){
            m= new HashMap<>();
            base=0;
            totalValue=0;
        }
        public void update(long add){
            base= base+ add;
        }
        public void add(long key, long val){
            long newKey= key-base;
            m.put(newKey, addMod(m.getOrDefault(newKey,(long)0),val));
        }
    }


    static class Tuple implements Comparable<Tuple>{
        int x, y, z;
        public Tuple(int x, int y, int z){
            this.x= x;
            this.y= y;
            this.z=z;
        }
        @Override
        public int compareTo(Tuple o){
            return this.x-o.x;
        }
    }

    static class Edge{
        public int to, next;
    }

    static class Pair implements Comparable<Pair>{
        public int turn;
        public boolean already;
        public Pair(int turn, boolean already){
            this.turn= turn;
            this.already= already;
        }

        @Override
        public int compareTo(Pair o) {
            return this.turn-o.turn;
        }
    }

    // public static class compareL implements Comparator<Tuple>{
    //     @Override
    //     public int compare(Tuple t1, Tuple t2) {
    //         return t2.l - t1.l;
    //     }
    // }

    // fast input reader class;
    static class InputReader {
        BufferedReader br;
        StringTokenizer st;

        public InputReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }

        public String nextToken() {
            while (st == null || !st.hasMoreTokens()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                if (line == null) {
                    return null;
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }
        public double nextDouble(){
            return Double.parseDouble(nextToken());
        }
        public long nextLong(){
            return Long.parseLong(nextToken());
        }
        public int[] nextIntArr(int n){
            int[] arr= new int[n];
            for(int i=0;i<n;i++) arr[i]= nextInt();
            return arr;
        }
        public long[] nextLongArr(int n){
            long[] arr= new long[n];
            for(int i=0;i<n;i++) arr[i]= nextLong();
            return arr;
        }
        public List<Integer> nextIntList(int n){
            List<Integer> arr= new ArrayList<>();
            for(int i=0;i<n;i++) arr.add(nextInt());
            return arr;
        }
        public int[][] nextIntMatArr(int n, int m){
            int[][] mat= new int[n][m];
            for(int i=0;i<n;i++) for(int j=0;j<m;j++) mat[i][j]= nextInt();
            return mat;
        }
        public List<List<Integer>> nextIntMatList(int n, int m){
            List<List<Integer>> mat= new ArrayList<>();
            for(int i=0;i<n;i++){
                List<Integer> temp= new ArrayList<>();
                for(int j=0;j<m;j++) temp.add(nextInt());
                mat.add(temp);
            }
            return mat;
        }
        public char[] nextStringCharArr(){
            return nextToken().toCharArray();
        }
    
    }
}
