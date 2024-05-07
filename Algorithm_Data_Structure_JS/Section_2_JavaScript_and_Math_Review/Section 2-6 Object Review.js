let Harry = {
  name: "Harry Potter",
  age: 40,
  married: true,
  sayHi() {
    console.log("Harry says hi to you");
  },
};

console.log(Harry.age);
console.log(Harry["name"]);
Harry.sayHi();
