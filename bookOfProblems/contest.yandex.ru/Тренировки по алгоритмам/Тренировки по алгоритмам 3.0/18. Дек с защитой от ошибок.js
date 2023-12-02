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

    class Deque {
        constructor() {
            this.items = []
        }

        push_front(item) {
            this.items.unshift(item);
            console.log("ok")
        }

        push_back(item) {
            this.items.push(item);
            console.log("ok")
        }

        pop_front() {
            if (this.items.length == 0) console.log("error")
            else console.log(this.items.shift())
        }

        pop_back() {
            if (this.items.length == 0) console.log("error")
            else console.log(this.items.pop())
        }

        front() {
            if (this.items.length == 0) console.log("error")
            else console.log(this.items.at(0))
        }

        back() {
            if (this.items.length == 0) console.log("error")
            else console.log(this.items.at(-1))
        }

        size() {
            console.log(this.items.length)
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

    let deque = new Deque()

    for (let i = 0; i < args.length; i++) {
        const command = args[i].split(' ');
        switch (command[0]) {
            case 'push_front':
                deque.push_front(command[1])
                break
            case 'push_back':
                deque.push_back(command[1])
                break
            case 'pop_front':
                deque.pop_front()
                break
            case 'pop_back':
                deque.pop_back()
                break
            case 'front':
                deque.front()
                break
            case 'back':
                deque.back()
                break
            case 'size':
                deque.size()
                break
            case 'clear':
                deque.clear()
                break
            case 'exit':
                deque.exit()
                process.exit()
            default:
                continue
        }
    }

});