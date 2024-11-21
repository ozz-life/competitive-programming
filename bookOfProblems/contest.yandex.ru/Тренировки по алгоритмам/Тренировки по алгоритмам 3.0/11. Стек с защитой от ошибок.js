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

    class Stack {
        constructor() {
            this.items = []
        }

        push(item) {
            this.items.push(item);
            console.log("ok")
        }

        back() {
            if (this.items.length == 0) console.log("error")
            else console.log(this.items.at(-1))
        }

        pop() {
            if (this.items.length == 0) console.log("error")
            else console.log(this.items.pop())
        }

        size() {
            console.log(this.items.length)
        }

        clear() {
            this.items.length = 0
            console.log("ok")
        }

        exit() {
            console.log("bye")
        }

    }

    const args = commands.trim().split('\n');

    let stack = new Stack()

    for (let i = 0; i < args.length; i++) {
        const command = args[i].split(' ');
        switch (command[0]) {
            case 'push':
                stack.push(command[1])
                break
            case 'back':
                stack.back()
                break
            case 'pop':
                stack.pop()
                break
            case 'size':
                stack.size()
                break
            case 'clear':
                stack.clear()
                break
            case 'exit':
                stack.exit()
                process.exit()
            default:
                continue
        }
    }

});