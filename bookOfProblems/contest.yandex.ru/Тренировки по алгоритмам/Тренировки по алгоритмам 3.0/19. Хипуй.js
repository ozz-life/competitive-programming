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
    let n = input[0].trim().split(' ').map(Number);
    let commandsList = []
    for (let i = 1; i < input.length; i++) {
        commandsList.push(input[i])
    }

    let heap = new BinaryHeap()

    for (let command of commandsList) {
        if (command.startsWith("0", 0)) {
            heap.push(parseInt(command.split(' ').at(1)))
        } else {
            console.log(heap.pop())
        }
    }
});

class BinaryHeap {
    constructor() {
        this.heap = [];
    }

    back() {
        return this.heap[0];
    }

    size() {
        return this.heap.length;
    }

    push(value) {
        this.heap.push(value);
        let pos = this.heap.length - 1;
        while(pos > 0 && this.heap[pos] > this.heap[Math.floor((pos-1)/2)]) {
            [this.heap[pos], this.heap[Math.floor((pos-1)/2)]] = [this.heap[Math.floor((pos-1)/2)], this.heap[pos]]
            pos = Math.floor((pos-1)/2);
        }
    }

    pop() {
        if (!this.heap.length) return false;
        const answer = this.heap[0];
        this.heap[0] = this.heap[this.heap.length-1];
        let pos = 0;
        while(pos * 2 + 2 < this.heap.length) {
            let min_son_idx = pos * 2 + 1;
            if (this.heap[pos * 2 + 2] > this.heap[min_son_idx]) {
                min_son_idx = pos * 2 + 2;
            }
            if (this.heap[pos] < this.heap[min_son_idx]) {
                [this.heap[pos], this.heap[min_son_idx]] = [this.heap[min_son_idx], this.heap[pos]];
                pos = min_son_idx;
            } else {
                break;
            }
        }
        this.heap.pop();
        return answer;
    }
}