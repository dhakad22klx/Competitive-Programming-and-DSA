function minimumFrustration(N, L, R) {
    // Input validation
    if (N <= 0 || N > 100000) {
        throw new Error("N must be between 1 and 100000");
    }
    if (L.length !== N || R.length !== N) {
        throw new Error("Length of L and R must be equal to N");
    }
    for (let i = 0; i < N; i++) {
        if (L[i] < 1 || L[i] > 100000 || R[i] < 1 || R[i] > 100000) {
            throw new Error("L and R values must be between 1 and 100000");
        }
        if (L[i] > R[i]) {
            throw new Error("L[i] must be less than or equal to R[i]");
        }
    }
    // function to find the upper bound using binary search
    function upperBound(arr, target) {
        let low = 0;
        let high = arr.length;
        while (low < high) {
            const mid = Math.floor((low + high) / 2);
            if (arr[mid] <= target) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
    // Combining L and R into pairs and sort them
    const intervals = L.map((l, i) => [l, R[i]]);
    intervals.sort((a, b) => a[0] - b[0]);
    // Extracting the starting points for binary search use
    const starts = intervals.map((interval) => interval[0]);
    // Arrays to hold counts of overlaps
    const h1 = new Array(N + 1).fill(0);
    const h2 = new Array(N).fill(0);
    for (let i = 0; i < N; i++) {
        const [a, b] = intervals[i];
        const y = upperBound(starts, b);
        h2[i] += y - i - 1;
        h1[y] -= 1;
        h1[i + 1] += 1;
    }
    for (let i = 1; i < N; i++) {
        h1[i] += h1[i - 1];
    }
    for (let i = 0; i < N; i++) {
        h2[i] += h1[i];
    }
    // Find the minimum frustration level
    let ans = 1e5;
    for (let i = 0; i < N; i++) {
        ans = Math.min(ans, h2[i]);
    }
    return ans;
}
const N = 4;
const L = [4, 10, 12, 13];
const R = [10, 22, 17, 19];
const result = minimumFrustration(N, L, R);
const expected = 1;
// assert.deepEqual(result, expected);
console.log(result);
//# sourceMappingURL=index.js.map