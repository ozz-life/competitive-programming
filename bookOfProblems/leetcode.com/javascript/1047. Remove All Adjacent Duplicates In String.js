s = "abbaca"

/**
 * @param {string} s
 * @return {string}
 */
var removeDuplicates = function(s) {
    let stack = new Stack

    for (let char of s) {
        if (char === stack.peek()) stack.pop()
        else if (stack.isEmpty() || char !== stack.peek()) {
            stack.push(char)
        }
    }
    
    let result = ''
    for (let char of stack.items) {
        result += char
    }

    return result
};

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

console.log(removeDuplicates(s));
