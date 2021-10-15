const gridTraveller = (n,m) =>{
    const table = Array(n+1).
    fill()
    .map(() => Array(m+1).fill(0));
    table[1][1] = 1;
    for(let i = 0; i <= n; i++){
        for(let j = 0; j <= m;j++){
            const curr = table[i][j];
            if(i + 1 <= n) table[i+1][j] += curr;
            if(j + 1 <= m) table[i][j+1] += curr;
        }
    }
    console.log(table[n][n]);
}

gridTraveller(3,3);
gridTraveller(18,18);