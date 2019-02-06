import org.junit.Test;

import java.util.Random;
import java.util.function.BiFunction;
import java.util.function.Function;

import static org.junit.Assert.*;

public class DPTest {

    // Timers

    static <A,B> long time1 (Function<A,B> f, A a) {
        long start = System.nanoTime();
        f.apply(a);
        long end = System.nanoTime();
        return (end-start)/1000000;
    }

    static <A,B,C> long time2 (BiFunction<A,B,C> f, A a, B b) {
        long start = System.nanoTime();
        f.apply(a,b);
        long end = System.nanoTime();
        return (end-start)/1000000;
    }

    // Testing fib correctness and timing

    @Test
    public void fib () {
        assertEquals(DP.fib(15), DP.mfib(15));

        long slow, fast;

        slow = time1(DP::fib, 30);
        fast = time1(DP::mfib, 30);
        assertTrue(slow > fast);

        slow = time1(DP::fib, 40);
        fast = time1(DP::mfib, 40);
        assertTrue(slow > fast);
    }

    @Test(timeout=5)
    public void fibT () {
        DP.fibMemo.clear();
        DP.mfib(100);
    }

    @Test
    public void ffib () {
        DP.fibMemo.clear();
        long n1 = DP.mfib(50);
        long n2 = DP.ffib(50);
        assertEquals(n1, n2);
    }

    @Test(timeout=20)
    public void ffibT () {
        DP.fibMemo.clear();
        DP.mfib(1000);
        DP.ffib(1000);
    }

    // Testing coinChange correctness and timing

    @Test
    public void coinsC () {
        Coin quarter = new Coin(25);
        Coin dime = new Coin(10);
        Coin nickel = new Coin(5);
        Coin penny = new Coin(1);
        List<Coin> coins =
                new Node<>(quarter,
                new Node<>(dime, new Node<>(nickel, new Node<>(penny, new Empty<>()))));
        assertEquals(1, DP.coinChange(coins, 4));
        assertEquals(2, DP.coinChange(coins, 6));
        assertEquals(242, DP.coinChange(coins,100));
    }

    @Test(timeout=500)
    public void coinsT1 () {
        List<Coin> coins =
                new Node<>(new Coin(3),
                new Node<>(new Coin(2), new Node<>(new Coin(1), new Empty<>())));
        DP.coinChangeMemo.clear();
        DP.mcoinChange(coins,1000);
    }

    // Testing partition correctness and timing

    @Test
    public void partitionCorrectness () {
        List<Integer> ns = new Node<>(5, new Node<>(3,
                        new Node<>(7, new Node<>(1, new Empty<>()))));
        assertFalse(DP.partition(ns, 2));
        assertTrue(DP.partition(ns, 8));
        assertTrue(DP.partition(ns, 6));
    }

    @Test
    public void partitionTiming () {
        Random r = new Random(1);
        List<Integer> s = List.MakeIntList(r, 100, 1000);
        //DP.partitionMemo.clear();//// commented out for testing 2/2/2019 
        long t = time2(DP::mpartition,s,50000);
        assertTrue (t < 500);
    }

    // minDistance

    @Test
    public void minDistance () {
        List<DP.BASE> dna1 =
                new Node<>(DP.BASE.A, new Node<>(DP.BASE.C, new Empty<>()));
        List<DP.BASE> dna2 =
                new Node<>(DP.BASE.A, new Node<>(DP.BASE.G, new Empty<>()));
        assertEquals(1, DP.minDistance(dna1,dna2));
    }

    @Test
    public void minDistance2 () {
        Random r = new Random(1);
        Function<Void,DP.BASE> g = v -> DP.BASE.class.getEnumConstants()[r.nextInt(4)];
        List<DP.BASE> dna1 = List.MakeList(g, 521);
        List<DP.BASE> dna2 = List.MakeList(g, 450);
        assertEquals(337, DP.mminDistance(dna1,dna2));
    }

    // longest common subsequence

    @Test
    public void lcs () {
        List<Character> cs1 =
                new Node<>('A', new Node<>('B', new Node<>('C',
                        new Node<>('B', new Node<>('D', new Node<>('A',
                                new Node<>('B', new Empty<>())))))));
        List<Character> cs2 =
                new Node<>('B', new Node<>('D', new Node<>('C',
                        new Node<>('A', new Node<>('B',
                                new Node<>('A', new Empty<>()))))));
        List<Character> c = new Node<>('B', new Node<>('D',
                new Node<>('A', new Node<>('B', new Empty<>()))));
        assertEquals(c, DP.lcs(cs1,cs2));
    }

    @Test
    public void lcs2 () {
        Random r = new Random(1);
        Function<Void,Character> g = v -> Character.forDigit(r.nextInt(256),10);
        List<Character> cs1 = List.MakeList(g, 310);
        List<Character> cs2 = List.MakeList(g, 250);
        assertEquals(240, DP.mlcs(cs1,cs2).length());
    }
}
