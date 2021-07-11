#include<bits/stdc++.h>
#define pb push_back
using namespace std;

void solveC(){
    int T; cin >> T;
    using Double = long double;
    while (T--){
        Double c,m,p,v; cin >> c >> m >> p >> v;
        Double ans = 0;
        function<Double(int, Double, Double, Double)> calc = [&](int turn, Double x, Double y, Double z){
            Double Turn=turn;
            Double r = z*Turn;
            Double eps = 0.000000000001;
            //cout << r << "\n";
            if (x<=v && x>eps){
                if (y<=eps&&z<=eps) r+=Turn*x;
                else if (y>eps&&z>eps)r+=x*calc(turn+1, 0, y + x/2, z+x/2);
                else if (y>eps)r+=x*calc(turn+1, 0, y+x, 0);
                else r+=x*calc(turn+1, 0, 0, z+x);
            }
            else if (x>v){
                if (y<=eps&&z<=eps) r+=Turn*x;
                else if (y>eps&&z>eps)r+=x*calc(turn+1, x-v, y+v/2, z+v/2);
                else if (y>eps)r+=x*calc(turn+1, x-v, y+v, 0);
                else r+=x*calc(turn+1, x-v, 0, z+v);
            }
            if (y<=v && y>eps){
                if (x<=eps&&z<=eps) r+=Turn*y;
                else if (x>eps&&z>eps)r+=calc(turn+1, x+y/2, 0, z+y/2)*y;
                else if (x>eps)r+=calc(turn+1, x+y, 0, 0)*y;
                else r+=calc(turn+1, 0, 0, z+y)*y;
            }
            else if (y>v){
                if (x<=eps&&z<=eps) r+=Turn*y;
                else if (x>eps&&z>eps)r+=calc(turn+1, x+v/2, y-v, z+v/2)*y;
                else if (x>eps)r+=calc(turn+1, x+v, y-v, 0)*y;
                else r+=calc(turn+1, 0, y-v, z+v)*y;
            }
            return r;
        };
        cout << fixed << setprecision(20) << calc(1,c,m,p) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solveC();
    return 0;
}
