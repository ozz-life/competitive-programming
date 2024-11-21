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

    let closingWithoutOpening = false
    let startBracketsCounter = 0
    let endBracketsCounter = 0
    for (let char of arr) {
        if (char == "(" || char == "[" || char == "{") {
            stack.push(char)
            startBracketsCounter += 1
        } else if (!stack.isEmpty() && char === ")" && stack.peek() === "(") {
            stack.pop()
        } else if (!stack.isEmpty() && char === "]" && stack.peek() === "[") {
            stack.pop()
        } else if (!stack.isEmpty() && char === "}" && stack.peek() === "{") {
            stack.pop()
        } else if (!stack.isEmpty() && char === "}" || char === "]" || char === "}") {
            closingWithoutOpening = true
        } else if (char == ")" || char == "]" || char == "}") {
            endBracketsCounter += 1
        }
    }

    if (stack.isEmpty() && stack.stackUsed && closingWithoutOpening === false && endBracketsCounter === 0) console.log('yes')
    else console.log('no')

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