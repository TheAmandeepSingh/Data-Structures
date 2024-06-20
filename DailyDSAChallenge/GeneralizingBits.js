/**
 * generate all the possible sequences of bits(0s & 1s) of a given length n
 */

function generateBits(n) {
    let results = [];

    const backtrack = (current, n) => {
        if(current.length === n) {
            results.push(current);
            return;
        }

        backtrack(current + '0', n);
        backtrack(current + '1', n);
    }

    backtrack('', n);
    return results;
}