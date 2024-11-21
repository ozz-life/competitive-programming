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

    class Queue {
        constructor() {
            this.items = []
        }

        push(item) {
            this.items.push(item);
            console.log("ok")
        }

        enqueue(element) {
            this.items.push(item);
            console.log("ok") 
        }

        pop() {
            if (this.items.length == 0) console.log("error")
            else console.log(this.items.shift())
        }

        dequeue() {
            if (this.items.length == 0) console.log("error")
            else console.log(this.items.shift())
        }

        front() {
            if (this.items.length == 0) console.log("error")
            else console.log(this.items.at(0))
        }

        size() {
            console.log(this.items.length)
        }

        peek() {
            return this.items[0];
        }

        clear() {
            this.items.length = 0
            console.log("ok")
        }

        isEmpty() {
            return this.items.length === 0;
        }

        exit() {
            console.log("bye")
        }

    }

    const args = commands.trim().split('\n');

    let queue = new Queue()

    for (let i = 0; i < args.length; i++) {
        const command = args[i].split(' ');
        switch (command[0]) {
            case 'push':
                queue.push(command[1])
                break
            case 'front':
                queue.front()
                break
            case 'pop':
                queue.pop()
                break
            case 'size':
                queue.size()
                break
            case 'clear':
                queue.clear()
                break
            case 'exit':
                queue.exit()
                process.exit()
            default:
                continue
        }
    }

});