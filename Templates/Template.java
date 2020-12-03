package Competitive_Programming;

import java.io.*;
import java.util.StringTokenizer;

/**
 * BEGIN NO SAD
 * Blessed are those who suffer for doing what is right.
 * The kingdom of heaven belongs to them.
 * (Matthew 5:10-12)
 * @author Tran Anh Tai
 * @template for CP codes
 * END NO SAD
 */
public class Template {
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
        public void solve(InputReader in, PrintWriter out) {
            int test = Integer.parseInt(in.nextToken());
            //TODO: solve the problem here!
            for (int i = 0; i < test; i++) {

            }
        }
    }
    static class Point{
        public double x, y;
        public Point(double x, double y){
            this.x = x; this.y = y;
        }
        public static Line getBisect(Point A, Point B){
            double a = B.x - A.x;
            double b = B.y - A.y;
            double c = a * (A.x + B.x) / 2 + b * (A.y + B.y) / 2;
            return new Line(a, b, c);
        }
        public static Point center(Point A, Point B, Point C){
            Line lab = getBisect(A, B);
            Line lac = getBisect(A, C);
            Point intersect = Line.intersect(lab, lac);
            return intersect;
        }
    }
    static class Line{
        public double a, b, c;
        public Line(double a, double b, double c){
            this.a = a; this.b = b; this.c = c;
        }
        public static Point intersect(Line l1, Line l2){
            double D = l1.a * l2.b - l1.b * l2.a;
            double Dy = l1.a * l2.c - l2.a * l1.c;
            double Dx = l1.c * l2.b - l2.c * l1.b;
            return new Point(Dx / D, Dy / D);
        }
    }
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
        public long nextLong(){
            return Long.parseLong(nextToken());
        }
    }
}