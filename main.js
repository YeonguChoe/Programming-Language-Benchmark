/*
node main.js 100
*/

function factorial(num) {
    if (num === 0 || num === 1) {
        return 1;
    }
    let result = 1;
    for (let i = 2; i <= num; i++) {
        result *= i;
    }
    return result;
}

function main(iteration) {
    const factorialInput = 20;
    const finalValue = (iteration - 2) ** 4;
    let count = 0;

    // Start timer
    const start = performance.now();

    for (let i = 2; i < iteration; i++) {
        for (let j = 2; j < iteration; j++) {
            for (let k = 2; k < iteration; k++) {
                for (let m = 2; m < iteration; m++) {
                    const result = factorial(factorialInput);
                    count += 1;
                    if (count === finalValue) {
                        console.log("==================================================");
                        console.log("Expected count:", count);
                    }
                }
            }
        }
    }

    // End timer
    const end = performance.now();

    console.log("Expected count:", finalValue);
    console.log("==================================================");
    const elapsedTime = (end - start) / 1000; // Convert milliseconds to seconds
    console.log(`Node.js Runtime: ${elapsedTime} seconds`);
    console.log("==================================================");
}

main(parseInt(process.argv[2], 10));