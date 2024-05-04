console.log(15);
let arr = ["Harry", "Ron", "Snap"];

for (let i = 0; i < arr.length; i++) {
  console.log(arr[i]);
  console.log(i);
}

arr.forEach((Person, index) => {
  console.log(Person);
  console.log(index);
});

for (j in arr) {
  console.log(j);
  console.log(arr[j]);
}
