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

public class C{
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
        static final int MAXN = (int)(5e6+9);
        static final int MOD= 1000000007;

        // stores smallest prime factor for every number
        static int spf[] = new int[MAXN];

        static boolean[] prime;

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

        void sieveOfEratosthenes(int n)
        {
            // Create a boolean array
            // "prime[0..n]" and
            // initialize all entries
            // it as true. A value in
            // prime[i] will finally be
            // false if i is Not a
            // prime, else true.
            prime= new boolean[n + 1];
            for (int i = 0; i <= n; i++)
                prime[i] = true;
    
            for (int p = 2; p * p <= n; p++)
            {
                // If prime[p] is not changed, then it is a
                // prime
                if (prime[p] == true)
                {
                    // Update all multiples of p
                    for (int i = p * p; i <= n; i += p)
                        prime[i] = false;
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
        public int lowerIndex(int[] arr, int n, int x)
        {
            int l = 0, h = n - 1;
            while (l <= h)
            {
                int mid = (l + h) / 2;
                if (arr[mid] >= x)
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
        public int upperIndex(int[] arr, int n, int y)
        {
            int l = 0, h = n - 1;
            while (l <= h)
            {
                int mid = (l + h) / 2;
                if (arr[mid] <= y)
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

        public int add(int a, int b){
            a+=b;
            if(a>=MOD) a-=MOD;
            else if(a<0) a+=MOD;
            return a;
        }

        public int mul(int a, int b){
            long res= (long)a*(long)b;
            return (int)(res%MOD);
        }

        public int power(int a, int b) {
            int ans=1;
            while(b>0){
                if((b&1)!=0) ans= mul(ans,a);
                b>>=1;
                a= mul(a,a);
            }
            return ans;
        }

        int[] fact= new int[MAXN];
        int[] inv= new int[MAXN];

        public int Ckn(int n, int k){
            if(k<0 || n<0) return 0;
            return mul(mul(fact[n],inv[k]),inv[n-k]);
        }

        public int inverse(int a){
            return power(a,MOD-2);
        }

        public void preprocess() {
            fact[0]=1;
            for(int i=1;i<MAXN;i++) fact[i]= mul(fact[i-1],i);
            inv[MAXN-1]= inverse(fact[MAXN-1]);
            for(int i=MAXN-2;i>=0;i--){
                inv[i]= mul(inv[i+1],i+1);
            }
        }

        /**
         * return VALUE of lower bound for unsorted array
         */
        public int lowerBoundNormalArray(int[] arr, int x){
            TreeSet<Integer> set= new TreeSet<>();
            for(int num: arr) set.add(num);
            return set.lower(x);
        }
        /**
         * return VALUE of upper bound for unsorted array
         */
        public int upperBoundNormalArray(int[] arr, int x){
            TreeSet<Integer> set= new TreeSet<>();
            for(int num: arr) set.add(num);
            return set.higher(x);
        }

        public void debugArr(int[] arr){
            for(int i: arr) out.print(i+" ");
            out.println();
        }
        
        InputReader in; PrintWriter out;
        
        public void solve(InputReader in, PrintWriter out) {
            this.in=in; this.out=out;
            int t=1;
            while(t-->0){
                solveA();
            }
        }


        public void solveA(){
            int r= in.nextInt(), s= in.nextInt(), n= in.nextInt();
            List<Pair> a= new ArrayList<>();
            for(int i=0;i<n;i++){
                a.add(new Pair(in.nextInt(), in.nextInt()));
                a.get(i).x= r-a.get(i).x;
                if(a.get(i).y<=s)a.get(i).y=s-a.get(i).y+1;else a.get(i).y-=s;
            }
            Collections.sort(a);
            long max=0;
            for(int i=0;i<n;i++) max= Math.max(max,(long)i+1+(long)a.get(i).x+(long)a.get(i).y);
            out.println(max);
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
            int val1= this.x-this.y;
            int val2= o.x-o.y;
            return val1-val2;
        }
    }

    static class Pair implements Comparable<Pair>{
        public int x;
        public int y;
        public Pair(int x, int y){
            this.x= x;
            this.y= y;
        }

        @Override
        public int compareTo(Pair o) {
            int val1= this.x+this.y;
            int val2= o.x+o.y;
            return val2-val1;
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
