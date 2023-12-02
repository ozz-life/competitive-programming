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
    let arr1 = input[0].trim().split(' ').map(Number);
    let arr2 = input[1].trim().split(' ').map(Number);

    let queue1 = new Queue(...arr1)
    let queue2 = new Queue(...arr2)

    let count = 0;

    while (!queue1.isEmpty() && !queue2.isEmpty()) {
        let card1 = queue1.dequeue()
        let card2 = queue2.dequeue()

        if (card1 == 0 && card2 == 9) {
            queue1.enqueue(card1)
            queue1.enqueue(card2)

        }
        else if (card2 == 0 && card1 == 9) {
            queue2.enqueue(card1)
            queue2.enqueue(card2)
        }
        else if (card1 > card2) {
            queue1.enqueue(card1)
            queue1.enqueue(card2)
        }
        else {
            queue2.enqueue(card1)
            queue2.enqueue(card2)
        }

        count++;

        if (count > 1000000) {
            console.log("botva")
            return;
        }
    }

    if (queue1.isEmpty()) {
        console.log("second", count)
    } else {
        console.log("first", count)
    }

});

class Queue {
    constructor(...items) {
        this.items = []
        for (let item of items) {
            this.enqueue(item)
        }
    }

    enqueue(item) {
        this.items.push(item);
    }

    dequeue() {
        if (this.items.length == 0) console.log("error")
        return this.items.shift()
    }

    size() {
        return this.items.length;
    }

    isEmpty() {
        return this.items.length === 0;
    }

    clear() {
        this.items.length = 0
    }

    front() {
        if (this.items.length == 0) console.log("error")
        return this.items.at(0)
    }
}