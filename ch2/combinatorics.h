/* combinatorics.h
 *
 * This small library offers basic combinatoric functions: Permutation and
 * Combination.
 * */

#ifndef _combinatorics_h
#define _combinatorics_h

/* func: P(n, k)
 *
 * n = the size of the collection
 * k = the number of elements to be ordered.
 * */
int P(int n, int k);

/* func: C(n, k)
 *
 * n = the size of the collection
 * k = the number of elements to be ordered.
 * */
int C(int n, int k);

#endif