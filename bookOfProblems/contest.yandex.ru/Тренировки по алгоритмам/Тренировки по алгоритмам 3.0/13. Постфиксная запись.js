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

    let stack = new Stack()

    let arr = commands.split('')

    let a = 0, b = 0, result = 0
    for (let char of arr) {
        if (Number.isInteger(parseInt(char))) {
            stack.push(Number(char))
        } else if (char === "*") {
            a = Number(stack.pop())
            b = Number(stack.pop())
            stack.push(a * b)
        } else if (char === "-") {
            a = Number(stack.pop())
            b = Number(stack.pop())
            stack.push(b - a)
        } else if (char === "+") {
            a = Number(stack.pop())
            b = Number(stack.pop())
            stack.push(a + b)
        }
    }

    console.log(stack.peek())
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
        this.stackUsed = true;
        //this.stackUsedCounter -= 1;
        return this.items.pop();
    }

    peek() {
        return this.items.at(-1);
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