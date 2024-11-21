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

    console.log(canSortWithStack(n, arr));
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

function canSortWithStack(n, order) {
    const stack = [];  // создаем пустой стек
    let current = 1;   // начинаем проверку с числа 1

    for (let i = 0; i < n; i++) {  // проходимся по всем вагонам

        if (order[i] === current) {  // если текущий вагон подходит
            current++;  // двигаемся к следующему вагону
        } else if (stack.length && stack[stack.length - 1] === current) {
            // если верхний вагон на стеке подходит
            stack.pop();  // забираем верхний вагон со стека
            current++;    // двигаемся к следующему вагону
            i--;          // продолжаем проверку текущего вагона
        } else {  // иначе кладем текущий вагон на стек
            stack.push(order[i]);
        }
    }

    // проверяем оставшиеся вагоны на стеке
    while (stack.length) {
        if (stack.pop() !== current) {  // если не подходит, значит сортировка невозможна
            return "NO";
        }
        current++;  // двигаемся к следующему вагону
    }

    return "YES";
}
