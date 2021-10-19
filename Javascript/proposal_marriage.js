const Marriage = () => {
    if(wife() || money()) {
        console.log('Marriage')
    } else {
        console.log('Later')
    }
}

const wife = () => {
    const wife = true
    return wife;
}

const money = () => {
    const money = true
    return money;
} 
