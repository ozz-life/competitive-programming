#!/usr/bin/env node

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let commands = '';

process.stdin.on('data', function (input) {
    commands += input;
});

process.stdin.on('end', function () {

    /*
     * Code Start
     **************************************************************************/

    let input = commands.trim().split('\n');
    let n = parseInt(input[0]);
    let arr = input[1].trim().split(' ').map(Number);

    let stack = new Stack()

    let result = Array(arr.length).fill(0)

    // 10
    // 65 51 79 36 2 47 92 30 25 94
    // 1  3  3  4  0 7  7  8  -1 -1
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] <= stack.peek()[1]) {
            while (arr[i] < stack.peek()[1]) {
                result[stack.peek()[0]] = i
                stack.pop()
            }
            stack.push([i, arr[i]])
        } else if (stack.isEmpty() || arr[i] > stack.peek()[1]) {
            stack.push([i, arr[i]])
        }
    }

    for (let i = 0; i <= result.length ; i++) {
        if (result[i] == 0) result[i] = -1
    }

    for (let i = 0; i <= stack.items.length ; i++) {
        result[stack.pop()[0]] = -1
    }

    console.log(result.join(' '))
});

class Stack {
    constructor() {
        this.items = [];
        this.stackUsed = false;
        this.stackUsedCounter = 0;
    }

    push(item) {
        this.items.push(item);
        this.stackUsed = true;
        this.stackUsedCounter += 1;
    }

    pop() {
        if (this.items.length == 0) return false
        else {
            this.stackUsed = true;
            //this.stackUsedCounter -= 1;
            return this.items.pop();
        }
    }

    peek() {
        if (this.items.length == 0) return false
        else return this.items.at(-1);
    }

    clear() {
        this.items.length = 0;
        this.stackUsed = true;
    }

    isEmpty() {
        return this.items.length === 0;
    }

    size() {
        return this.items.length;
    }
}