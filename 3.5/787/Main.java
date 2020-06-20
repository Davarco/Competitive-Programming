import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        UVA787.UVA787();
    }
}

class UVA787 {

    static List<BigInteger> integers;

    static void UVA787() {
        Scanner in = new Scanner(System.in);
        integers = new ArrayList<>();
        integers.add(BigInteger.ONE);

        int max = Integer.MIN_VALUE;
        while (in.hasNext()) {
            int bi = in.nextInt();
            if (bi == -999999) {
                integers.add(BigInteger.ZERO);
                run(new BigInteger(Integer.toString(max)));
                integers = new ArrayList<>();
                integers.add(BigInteger.ONE);
                max = Integer.MIN_VALUE;
            } else {
                integers.add(new BigInteger(Integer.toString(bi)));
                if (bi > max) max = bi;
            }
        }
        in.close();
    }

    static void run(BigInteger best) {
        int start = 0;
        for (int a = 1; a < integers.size(); a++) {
            if (integers.get(a).equals(BigInteger.ZERO)) {
                for (int i = start; i < a; i++) {
                    for (int j = start; j < i; j++) {
                        BigInteger bi = integers.get(i).divide(integers.get(j));
                        if (bi.compareTo(best) > 0)
                            best = bi;
                    }
                }
                integers.set(a, BigInteger.ONE);
                start = a;
            } else {
                integers.set(a, integers.get(a).multiply(integers.get(a-1)));
            }
        }
        System.out.println(best);
    }
}
