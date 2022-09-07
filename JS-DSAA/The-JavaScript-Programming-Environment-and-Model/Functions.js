function factorial(number)
{
    var product=1;
    for(var i=number;i>=1;--i)
    {
        product*=i;
    }
    return product
}
console.log(factorial(4));