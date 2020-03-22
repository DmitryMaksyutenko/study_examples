let arr = new Array(10);
let count = arr.length;

for(let i = 0; i < count; i++){
    arr[i] =  Math.floor(Math.random() * 10);
    console.log("i variable: " + i);
    console.log("random number: " + arr[i]);
}