const gridTraveller = (n,m,arr={}) =>{
    const key = n + ',' + m;
    if(key in arr){
      return arr[key];
    }
    if(n === 1 && m == 1){
        return 1;
    }
    if(n === 0 || m === 0){
        return 0;
    }
    arr[key] = gridTraveller(n-1,m,arr) + gridTraveller(m-1,n,arr);
    return arr[key];
}

console.log(gridTraveller(3,3));
console.log(gridTraveller(2,3));
console.log(gridTraveller(6,6));
console.log(gridTraveller(18,18));