import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.WeakHashMap;
import java.util.function.BiFunction;
import java.util.function.Function;

/* 
 * Top down solutions
 */

class DP {

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
     * We create a hash table making sure it is called coinChangeMemo. 
     * Each subproblem is determined by the list of coins and by the desired sum.
     * That combination should be the key.
     */
    static Map<Pair<List<Coin>,Integer>,Integer> coinChangeMemo = new WeakHashMap<>();

    /**
     * We use computeIfAbsent. When we communicate with the hash table, we combine
     * all the information into a key and take back apart.
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

    /**
     * We now manage the memoization table manually. We can choose
     * to represent our memoization table as a WeakHashMap or we can
     * represent it as an array or whatever data structure gives efficient
     * access to the elements. In class we used a WeakHashMap. Here
     * we show how to use an array.
     */
    static int bucoinChange (List<Coin> coins, int n) throws EmptyListE {
        /* The possible lists of coins we will encounter are coins, coins.getRest(),
         * coins.getRest().getRest(), etc. We will refer to these using
         * array indices 0, 1, 2, ...
         * The possible sums we will encounter will be a subset of n, n-1, n-2, ...
         * We will use these directly as indices into the array
         */

         int len = coins.length()+1;
         int[][] table = new int[len][n+1];

         /*
          * The entries corresponding to the empty list are initialized with 0 (no solutions)
          * The entries corresponding to sum=0 are initialized with 1 (one solution)
          * These two initializations must be done in the given order
          */

         for (int i=0; i<n+1; i++) table[len-1][i] = 0;
         for (int c=0; c<len; c++) table[c][0] = 1;

         /*
          * Now we start filling the table. We note from the recursive solution that:
          * the result of coins,n uses coins.getRest(),n and coins,n-value
          * In other words, the value at [c][n] uses entries at [c+1][n] and [c][n-v]
          * So the array must be filled in a particular order starting from high values of c
          * going down to 0 and from low values of i going up to n.
          */


         for (int c=len-2; c>=0; c--) {
             int v = coins.get(c).getValue();
             for (int i = 1; i<n+1; i++) {
                 // make sure we don't go out of bounds
                 if (i - v < 0) table[c][i] = table[c+1][i];
                 else table[c][i] = table[c + 1][i] + table[c][i - v];
             }
         }

         // array is full; return value of original problem
         return table[0][n];
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
         try {
             return partition(s.getRest(), sum - s.getFirst()) ||
                     partition(s.getRest(), sum);
         }
         catch (EmptyListE e) {
             return sum == 0;
         }
    }

    static Map<Pair<List<Integer>,Integer>,Boolean> partitionMemo = new WeakHashMap<>();

    static boolean mpartition (List<Integer> s1, int sum1) {
        return partitionMemo.computeIfAbsent(new Pair<>(s1, sum1), p -> {
            List<Integer> s = p.getFirst();
            int sum = p.getSecond();
            try {
                return mpartition(s.getRest(), sum - s.getFirst()) ||
                        mpartition(s.getRest(), sum);
            } catch (EmptyListE e) {
                return sum == 0;
            }
        });
    }


    static boolean bupartition (List<Integer> s, int sum) {
        return false;
    }


    // -----------------------------------------------------------------------------
    // Min distance ...
    // -----------------------------------------------------------------------------

    final static int GAP = 2;
    final static int MATCH = 0;
    final static int MISMATCH = 1;

    enum BASE { A, T, G, C }

    static int min (int d1, int d2) {
        return d1 < d2 ? d1 : d2;
    }

    static int minDistance (List<BASE> dna1, List<BASE> dna2) {
        try {
            int current = dna1.getFirst() == dna2.getFirst() ? MATCH : MISMATCH;
            int d1 = current + minDistance(dna1.getRest(), dna2.getRest());
            int d2 = GAP + minDistance(dna1.getRest(), dna2);
            int d3 = GAP + minDistance(dna1, dna2.getRest());
            return min(d1,min(d2,d3));
        }
        catch (EmptyListE e) {
            if (dna1.isEmpty()) return GAP * dna2.length();
            else return GAP * dna1.length();
        }
    }

    static Map<Pair<List<BASE>,List<BASE>>,Integer> minDistanceMemo = new WeakHashMap<>();

    static int mminDistance (List<BASE> dna11, List<BASE> dna21) {
        return minDistanceMemo.computeIfAbsent(new Pair<>(dna11, dna21), p -> {
            List<BASE> dna1 = p.getFirst();
            List<BASE> dna2 = p.getSecond();
            try {
                int current = dna1.getFirst() == dna2.getFirst() ? MATCH : MISMATCH;
                int d1 = current + mminDistance(dna1.getRest(), dna2.getRest());
                int d2 = GAP + mminDistance(dna1.getRest(), dna2);
                int d3 = GAP + mminDistance(dna1, dna2.getRest());
                return min(d1,min(d2,d3));
            }
            catch (EmptyListE e) {
                if (dna1.isEmpty()) return GAP * dna2.length();
                else return GAP * dna1.length();
            }
        });
    }


    static int buminDistance (List<BASE> dna1, List<BASE> dna2) {
        return 0;
    }

    // -----------------------------------------------------------------------------
    // Longest common subsequence ...
    // -----------------------------------------------------------------------------

    static List<Character> lcs (List<Character> cs1, List<Character> cs2) {
        try {
            if (cs1.getFirst().equals(cs2.getFirst())) {
                return new Node<>(cs1.getFirst(),
                        lcs(cs1.getRest(),cs2.getRest()));
            }
            else {
                List<Character> r1 = lcs(cs1,cs2.getRest());
                List<Character> r2 = lcs(cs1.getRest(),cs2);
                if (r1.length() > r2.length()) return r1;
                else return r2;
            }
        }
        catch (EmptyListE e) {
          return new Empty<>();
        }
    }

    static Map<Pair<List<Character>,List<Character>>,List<Character>> lcsMemo = new WeakHashMap<>();

    static List<Character> mlcs (List<Character> cs11, List<Character> cs21) {
        return lcsMemo.computeIfAbsent(new Pair<>(cs11,cs21), p -> {
            List<Character> cs1 = p.getFirst();
            List<Character> cs2 = p.getSecond();
            try {
                if (cs1.getFirst().equals(cs2.getFirst())) {
                    return new Node<>(cs1.getFirst(), mlcs(cs1.getRest(), cs2.getRest()));
                } else {
                    List<Character> r1 = mlcs(cs1, cs2.getRest());
                    List<Character> r2 = mlcs(cs1.getRest(), cs2);
                    if (r1.length() > r2.length()) return r1;
                    else return r2;
                }
            } catch (EmptyListE e) {
                return new Empty<>();
            }
        });
    }

    static List<Character> bulcs (List<Character> cs1, List<Character> cs2) {
        return null;
    }


}
