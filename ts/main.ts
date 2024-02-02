function sequentialDigits( low: number,  high: number): number[] {
    const res: number[] = [];

    for (let currentSize = Math.trunc(Math.log10(low)) + 1; currentSize <= Math.trunc(Math.log10(high)) + 1; ++currentSize) {
        for (let firstDigit = 1; firstDigit <= 10 - currentSize; ++firstDigit) {
            let number = firstDigit;
            for (let digit = firstDigit + 1; digit < currentSize + firstDigit; ++digit) {
                number *= 10;
                number += digit;
            }
            if (number > high) {
                break;
            }
            if (number >= low) {
                res.push(number);
            }
        }
    }

    return res;
}


const res1 = sequentialDigits(100, 300);
console.log(res1);

const res2 = sequentialDigits(1000, 13000);
console.log(res2);

