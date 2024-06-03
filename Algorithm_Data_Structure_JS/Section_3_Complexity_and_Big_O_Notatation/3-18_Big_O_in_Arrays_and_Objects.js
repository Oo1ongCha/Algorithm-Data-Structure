let arr = [1, 2, 3, 4, 5];

for (let i = 0; i < 5; i++) {
  arr.push(10); //O(1)
}

console.log(arr);

let n = 10;

for (let i = 0; i < n; i++) {
  arr.unshift(10); //O(n)
} //O(n^2)

console.log(arr);
