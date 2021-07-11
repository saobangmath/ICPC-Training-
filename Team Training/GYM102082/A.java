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
        static final int MAXN = 100005;
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

        List<String> s0;
        public void solveA(){
            int n= in.nextInt();
            s0= proccess(in.nextStringCharArr());
            // for(String i: s0) out.print(i+" ");
            // out.println();
            for(int i=0;i<n;i++){
                char[] s= in.nextStringCharArr();
                if(lessThan(s)) out.println("-");
                else out.println("+");
            }
        }
        private boolean lessThan(char[] s){
            List<String> s1= proccess(s);
            // for(String i: s1) out.print(i+" ");
            // out.println();
            int i=0;
            while(i<s0.size() && i<s1.size()){
                String temp0= s0.get(i), temp1= s1.get(i);
                if(isNumber(temp0) && isNumber(temp1)){
                    int num1= Integer.parseInt(temp1), num0= Integer.parseInt(temp0);
                    if(num1!=num0) return num1<num0;
                }
                else if(isNumber(temp0) && !isNumber(temp1)) return false;
                else if(!isNumber(temp0) && isNumber(temp1)) return true;
                else if(temp1.compareTo(temp0)!=0) return temp1.compareTo(temp0)<0;
                i++;
            }
            if(i<s0.size()) return true;
            return false;
        }
        private boolean isNumber(String s){
            char ch= s.charAt(0);
            if(ch>='0' && ch<='9') return true;
            return false;
        }

        private List<String> proccess(char[] s){
            List<String> res= new ArrayList<>();
            String num="";
            for(char ch: s){
                if(ch>='0'&&ch<='9') num+=ch;
                else{
                    if(!num.isEmpty()){
                        res.add(num);
                        num="";
                    }
                    res.add(ch+"");
                }
            }
            if(!num.isEmpty()) res.add(num);
            return res;
        }

        double c,m,p,v;
        public void solveC(){
            res=0;
            c= in.nextDouble(); m= in.nextDouble(); p= in.nextDouble(); v=in.nextDouble();
            double[] state= new double[]{c,m,p};
            go(0,state,(double)1.0);
            out.println(res);

        }
        double res=0;
        double EPS= 0.000001;

        public void go(int steps, double[] state, double cur){
            //end here-choose P
            res+= (double)(steps+1)*(cur*state[2]);
            // out.println((steps+1)+" "+(cur*state[2]));
            // out.println("state: "+state[2]);
            if(Math.abs(state[2]-1)<EPS) return;
            if(state[0]<EPS) state[0]=-1;
            if(state[1]<EPS) state[1]=-1;

            int num=0;
            if(state[0]>0) num++;
            if(state[1]>0) num++;
            if(state[2]>0) num++;
            //go c
            double[] state1= new double[]{state[0],state[1],state[2]};
            double[] state2= new double[]{state[0],state[1],state[2]};
            if(state1[0]>0){
                num--;
                double newCur= cur*state1[0];
                if(state1[0]>v){
                    state1[0]-=v; 
                    if(state1[1]>0) state1[1]+= v/num;
                    if(state1[2]>0) state1[2]+= v/num;
                }
                else{
                    if(state1[1]>0) state1[1]+= state1[0]/num;
                    if(state1[2]>0) state1[2]+= state1[0]/num;
                    state1[0]=-1;
                }
                go(steps+1,state1,newCur);
            }
            num=0;
            if(state[0]>0) num++;
            if(state[1]>0) num++;
            if(state[2]>0) num++;
            //go m
            if(state2[1]>0){
                num--;
                double newCur= cur*state2[1];
                if(state2[1]>v){
                    state2[1]-=v; 
                    if(state2[0]>0) state2[0]+= v/num;
                    if(state2[2]>0) state2[2]+= v/num;
                }
                else{
                    if(state2[0]>0) state2[0]+= state2[1]/num;
                    if(state2[2]>0) state2[2]+= state2[1]/num;
                    state2[1]=-1;
                }
                go(steps+1,state2,newCur);
            }

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
            int val1= this.x-this.y;
            int val2= o.x-o.y;
            return val1-val2;
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
