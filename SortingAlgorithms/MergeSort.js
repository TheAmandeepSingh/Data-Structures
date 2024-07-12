/**
 * Merge Sort Algorithm
 */

function mergeSort(array) {
    const n = array.length;
    if(n <= 1) return array;

    const middle = Math.floor(n/2);
    const left = array.slice(0, middle);
    const right = array.slice(middle);

    return merge(mergeSort(left), mergeSort(right));
}

function merge(left, right) {
    let result = [];
    let leftIndex = 0;
    let rightIndex = 0;

    while(leftIndex < left.length && rightIndex < right.length) {
        if(left[leftIndex] < right[rightIndex]) {
            result.push(left[leftIndex]);
            leftIndex++;
        } else {
            result.push(right[rightIndex]);
            rightIndex++;
        }
    }

    while(leftIndex < left.length) {
        result.push(left[leftIndex]);
        leftIndex++;
    }

    while(rightIndex < right.length) {
        result.push(right[rightIndex])
        rightIndex++;
    }

    return result;
}


const arr = [3, 5, 2, 1, 6, 7];

console.log(mergeSort(arr));