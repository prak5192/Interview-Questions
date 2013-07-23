/*
http://stackoverflow.com/questions/17591467/find-the-biggest-interval-that-has-all-its-members-in-list-in-on/17592550#17592550


Given a list of integers, find out the biggest interval that has 
all its members in the given list. e.g. given list 1, 7, 4, 6, 3, 10, 2 
then answer would be [1, 4]. Develop algorithm and write code for this

*/





/*****************************************************************************
 * File: LongestRange.java
 * Author: Keith Schwarz (htiek@cs.stanford.edu)
 *
 * An algorithm for finding the longest range of consecutive integers 
 * contained in an array of unsorted integers.  For example, if the input
 * array is
 *
 *                      16  1 12  5  4 10  2 11 13  3 15
 *
 * The longest range of consecutive integers would be 1, 2, 3, 4, 5, since all
 * of those values appear at least once in the array.  Notice that while the
 * sequence 10, 11, 12, 13, 15, 16 is in the array, because the value 14 is
 * missing, the range 10 - 16 is not a valid range.
 *
 * There are many algorithms we could use to solve this problem.  First, we
 * could sort the array in O(n log n) time, then look for the longest
 * contiguous sorted range in the array using a single pass over the array.
 * This would take O(n log n) time for the sorting, plus an extra O(n) pass
 * over the array, for a net runtime of O(n log n) time.
 *
 * However, since we do know that the elements of the array are integers, we
 * could improve this by using radix sort to get the runtime down to
 * O(n lg |U|), where U is the largest possible value in the array.
 *
 * Alternatively, we could consider an entirely different approach based on
 * hashing.  Suppose that we could build up a hash table containing a copy of
 * every value in the input array.  Assuming that we have a hash funciton that
 * works in constant time (which, assuming that we're on a standard computer,
 * is a perfectly valid assumption), this means that given any element k of 
 * the array, we can query in expected O(1) time whether k + 1 or k - 1 is in
 * the array by simply looking those values up in the hash table.  Using this,
 * we can build a (fairly inefficient) algorithm that works as follows.
 * First, add all of the array elements to a hash table.  Then, make a second
 * pass over the array.  We can then see how long the range containing the
 * current element x is using the following logic.  Every element x is part
 * of some range (which might just contain x), but which may contain some
 * elements greater than x and some elements less than x.  In other words,
 * given an arbitrary element x, there is some range containing x that looks
 * something like this:
 *
 *                    +--------------+---+--------------+
 *                    | elements < x | x | elements > x |
 *                    +--------------+---+--------------+
 *
 * Given the element x, how can we tell how many elements are greater than x
 * or less than x?  One idea would be as follows.  Remember that given the
 * value of x, we can check whether x + 1 or x - 1 are contained somewhere in
 * the array in (expected) O(1) time.  This means that we can find all of the
 * elements contained in the same range as x as follows: First, look up x + 1
 * in the hash table.  If it's contained in the table, then look up x + 2.
 * If x + 2 is in the table, then look up x + 3, etc.  More generally, we can
 * count the number of elements in the table as follows:
 *
 *    Set numGreater = 0
 *    Set i = 1
 *    While x + i is contained in the hash table:
 *        Set numGreater = numGreater + 1
 *        i = i + 1
 *
 * This works by counting up from x + 1 as long as the elements are contained
 * in the table, then recording how many elements we found.
 *
 * Similarly, we can count how many elements are smaller than x as follows:
 *
 *    Set numSmaller = 0
 *    Set i = 1
 *    While x - i is contained in the hash table:
 *        Set numSmaller = numSmaller + 1
 *        i = i + 1
 *
 * By running both of these loops, we can count the total number of elements
 * in the range containing x.  This gives the following (fairly inefficient)
 * algorithm for finding the longest range:
 *
 *    Set longest = 0
 *    Insert all of the array elements into a hash table.
 *    For each element x of the array, in any order:
 *        Using the above subroutines, compute numGreater and numSmaller
 *        Set longest = max(longest, 1 + numGreater + numSmaller)
 *    Return longest
 * 
 * Here, we scan across the array, computing the length of the range
 * containing each number, which is equal to the number of elements above and
 * below the current array element plus one (because we have to account for
 * the array element itself).
 *
 * Now, let's analyze the runtime of this algorithm.  Inserting each element
 * into the hash table takes, on expectation, O(n) time.  We then make a pass
 * over the array, computing range lengths.  For each element x, the total
 * number of hash lookups required to find the number of values greater than
 * x is equal to g + 1, where g is the number of elements greater than x
 * (since we do a total of g successful queries and 1 failing query).
 * Similarly, we do l + 1 work to find the l elements smaller than x.  This
 * gives a total runtime of g + l + 2 = S(x) + 1 work per element, where S(x)
 * is the total number of elements in the same range as x.
 *
 * So how does this translate into a total runtime?  Recall that each element
 * belongs to exactly one range, so we can number the ranges contained in the
 * array as R_1, R_2, ..., R_j.  Whenever we process an element in the array,
 * we end up doing |R_i + 1| hash table lookups, where R_i is the range
 * containing the current array element.  Since there are |R_i| elements in
 * the range |R_i|, the total number of hash lookups done to process elements
 * in |R_i| is |R_i|(|R_i| + 1).  Thus the total number of hash lookups done
 * by the function is
 *
 *      j
 *     sum  |R_i|(|R_i| + 1)
 *    i = 1
 *
 * If each array element is in its own range, this takes O(n) time, but if
 * everything is contained in a single range (that is, the array is a
 * permutation of some contiguous range), then there is one range and we end
 * up spending O(n^2) time processing it.  This is much worse than the old
 * algorithm based on sorting!
 *
 * Fortunately, we can improve this runtime bound by using a fairly
 * straightforward optimization.  Once we've computed the length of a given
 * range in the array, it makes no sense to ever recompute it again, since
 * that work will be wasted.  To fix this, as we compute the length of a
 * range, we will remove all of the elements from that range from the hash
 * table.  Additionally, as we make our scan over the input array, we will
 * first confirm that the array element x is still contained in the table.
 * If so, then we know that we haven't processed the range containing x yet
 * and should go process it.  Otherwise, the range holding x has already been
 * considered, so we can skip that array element.
 *
 * The new version of the logic looks like this:
 *
 *    Set longest = 0
 *    Insert all of the array elements into a hash table.
 *    For each element x of the array, in any order:
 *        If x still contained in the hash table:
 *           Using the above subroutines, compute numGreater and numSmaller
 *           In doing so, remove each element found this way from the table.
 *           Set longest = max(longest, 1 + numGreater + numSmaller)
 *    Return longest
 *
 * This version of the algorithm now visits each range once, but introduces
 * one more hash lookup per element.  To count the total number of hash
 * lookups performed during this algorithm, we can split the hash lookups
 * into two classes of lookups: lookups done to determine whether to process
 * a range, and lookups done to actually process the range.  There are a
 * total of n lookups done by this first category.  In the second category,
 * recall that |R_i| + 1 hash lookups are done when processing each range.
 * Since each range is processed exactly once, the total number of hash
 * lookups done to process ranges is given by
 *      j
 *     sum (|R_i| + 1) = n + j
 *     i=1
 *
 * Here, the n term comes from the fact that each element is in exactly one
 * range, so summing the lengths of the ranges gives n elements.  Thus the
 * total number of hash lookups done by this algorithm is 2n + j <= 3n,
 * which is O(n).  The expected runtime of this algorithm is thus O(n).
 *
 * Notice that this algorithm does not have a lg |U| term in its runtime,
 * even though the hash function must process all the bits of the numbers to
 * hash.  This is because we assume the computer can perform operations on
 * lg |U| bits in a single operation.  Thus unlike the radix sort-based
 * version of this algorithm, in which the number of bits manifests itself
 * explicitly in the number of iterations required, the hash-based version
 * can conveniently tuck the number of bits used under the rug because the
 * machine can operate on blocks of bits as a unit.
 *
 * There is one final detail to consider here: what happens if an integer
 * overflow or underflow occurs?  For example, suppose that our array holds
 * the values INT_MAX and INT_MIN.  Then our algorithm would incorrectly
 * report that the longest range has size 2, because when processing INT_MAX
 * the algorithm would note that INT_MAX + 1 = INT_MIN is indeed contained in
 * the array.  To fix this, we need to insert some additional checks into our
 * code for finding the number of elements greater than or less than the
 * current array element so that we don't end up overflowing or underflowing.
 */

import java.util.*;

public final class LongestRange {
    /* This is a utility class and should not be instantiated. */
    private LongestRange() {
        /* Not intended to be used */
    }
    
    /**
     * Returns the length of the longest continous range of values that are
     * all present in the input array.
     *
     * @param arr The array in which the search should be conducted.
     * @return The length of the longest continuous range of values in arr.
     * @throws NullPointerException if arr is null.
     */
    public static int longestRange(int[] arr) {
        /* Begin by creating a hash table that holds all of the array
         * elements.
         */
        Set<Integer> values = new HashSet<Integer>();
        for (int value: arr)
            values.add(value);
        
        /* Keep track of the longest range we've seen so far.  Initially,
         * this is the empty range.
         */
        int longest = 0;
        
        /* Scan across the array, searching for the longest range of values
         * contained in that array.
         */
        for (int value: arr) {
            /* To avoid unnecessary work, don't process this element if
             * we already did.  To mark that it has been processed, we
             * remove the element.  Since Java's Set#remove function
             * returns whether the element was removed successfully, we
             * can combine the test/remove operation into one.
             */
            if (!values.remove(value)) continue;
            
            /* Track how many total elements are in the range containing
             * the current element.  Initially this is one, because the
             * range contains this element.
             */
            int rangeLength = 1;
            
            /* See how many elements are greater than the current value
             * and contained in the range.  To avoid integer overflow,
             * at each step we track whether the element we're about to
             * probe is greater than the current element; on an overflow,
             * this will be false.
             */
            for (int i = 1; value + i > value; ++i) {
                /* Again, combine the test/remove operation into
                 * one.
                 */
                if (!values.remove(value + i)) break;
                
                ++rangeLength;
            }
            
            /* Using similar logic, see how many elements in the range
             * are smaller than the current value.
             */
            for (int i = 1; value - i < value; ++i) {
                if (!values.remove(value - i)) break;
                ++rangeLength;
            }
            
            /* Update the length of the longest range we've seen so far. */
            if (longest < rangeLength) longest = rangeLength;
        }
        
        /* Hand back the length of the longest range we encountered. */
        return longest;
    }
}
