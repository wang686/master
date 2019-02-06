import java.util.HashMap;
import java.util.Map;
import java.util.WeakHashMap;
import java.util.function.Function;

class DP {

    /**
     * Trivial example to show the pattern: fib
     * First write the normal recursive solution
     */
    static long fib (int n) {
        if (n < 2) return n;
        else return fib(n-1) + fib (n- 2);
    }

    /**
     * Create a hash table: please call it fibMemo as we will refer
     * to it from the test suite.
     */
    static Map<Integer,Long> fibMemo = new WeakHashMap<>();

    /**
     * Use the method computeIfAbsent passing the naive recursive
     * computation as an argument. Do not forget to rename the
     * recursive calls to refer to the memoized version.
     *
     * There will typically be small additional tweaks to do. In
     * this case, I had to explicitly cast from int to long
     * in the return clause for the base case.
     */
    static long mfib (int n1) {
        return fibMemo.computeIfAbsent(n1, n -> {
            if (n < 2) return (long)n;
            else return mfib(n - 1) + mfib(n - 2);
        });
    }

    /**
     * For fun... Compute fib using the golden ratio.
     */
    static long ffib (int n) {
        double magic = Math.sqrt(5);
        double result = (1/magic) * (Math.pow(((1+magic)/2),n) - Math.pow(((1-magic)/2),n));
        return (long)result;
    }

    // -----------------------------------------------------------------------------
    // Coin changing...
    // -----------------------------------------------------------------------------

    /**
     * Given a list of possible coins that must include a penny,
     * and a number of pennies 'n', in how many ways can we use the
     * coins to make change for 'n'.
     */
    static int coinChange (List<Coin> coins, int n) {
        try {
            if (n < 0) return 0; // no way to make change
            else if (n == 0) return 1; // previous choices succeeded
            else return coinChange(coins.getRest(), n) +
                        coinChange(coins,n - coins.getFirst().getValue());
        }
        catch (EmptyListE e) {
            return 0; // no way to make change
        }
    }

    /**
     * Again we create a hash table making sure it is called
     * coinChangeMemo. But here we have to think a bit. Each
     * subproblem is determined by the list of coins and by the
     * desired sum.  That combination should be the key used
     * in hashing.
     */
    static Map<Pair<List<Coin>,Integer>,Integer> coinChangeMemo = new WeakHashMap<>();

    /**
     * We again want to use computeIfAbsent. When we communicate with
     * the hash table, we combine all the information into a key and
     * take back apart when we extract from the hash table.
     */
     static int mcoinChange (List<Coin> coins1, int n1) {
        return coinChangeMemo.computeIfAbsent(new Pair<>(coins1,n1), p -> {
            List<Coin> coins = p.getFirst();
            int n = p.getSecond();
            try {
                if (n < 0) return 0; // no way to make change
                else if (n == 0) return 1; // previous choices succeeded
                else return mcoinChange(coins.getRest(), n) +
                            mcoinChange(coins, n - coins.getFirst().getValue());
            }
            catch (EmptyListE e) {
                return 0; // no way to make change
            }
        });
    }

    // -----------------------------------------------------------------------------
    // Partition ...
    // -----------------------------------------------------------------------------

    /**
     * Partition: take a list, a desired sum 's', and return
     * T/F depending on whether it is possible to find a
     * subsequence of the list whose sum is exactly 's'
     */
    static boolean partition (List<Integer> s, int sum) {
	return false;
    }

    static Object partitionMemo = null;
    static boolean mpartition (List<Integer> s1, int sum1) {
	return false;
    }

    // -----------------------------------------------------------------------------
    // Min distance ...
    // -----------------------------------------------------------------------------

    final static int GAP = 2;
    final static int MATCH = 0;
    final static int MISMATCH = 1;

    enum BASE { A, T, G, C }

    static int minDistance (List<BASE> dna1, List<BASE> dna2) {
	return 0;
    }

    static Object minDistanceMemo = null;

    static int mminDistance (List<BASE> dna11, List<BASE> dna21) {
	return 0; 
    }

    // -----------------------------------------------------------------------------
    // Longest common subsequence ...
    // -----------------------------------------------------------------------------

    static List<Character> lcs (List<Character> cs1, List<Character> cs2) {
	return null;
    }

    static Object lcsMemo = null;

    static List<Character> mlcs (List<Character> cs11, List<Character> cs21) {
	return null;
    }
}
