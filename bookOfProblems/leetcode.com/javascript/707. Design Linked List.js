//on Get - treat negaive index as zero if node list is empty
//on AddAtIndex - insert element at index zero
// When you insert with index < 0, test case will just treat as insert at index = 0.


class ListNode {
    constructor(value, next) {
        this.value = value === undefined ? 0 : value
        this.next = next === undefined ? null : next
    }
}

class MyLinkedList {
    constructor() {
        this.head = null
        this.length = 0
    }

    getLength() {
        // let length = 0, 
        let current = this.head;
        while (current !== null) {
            current = current.next;
            this.length++;
        }
        return this.length;
    }

    get(index) {
        if (index < 0 || index >= this.getLength()) return -1;
        let current = this.head;
        for (let i = 0; i < index; i++) {
            current = current.next;
        }
        return current.value;
    }

    addAtHead(value) {
        let node = new ListNode(value)
        node.next = this.head
        this.head = node
        this.length++
    }

    addAtTail(value) {
        if (this.head === null) {
            this.addAtHead(value)
            return
        }

        let node = new ListNode(value)
        let current = this.head
        for (let i = 0; i < this.length - 1; i++) {
            current = current.next
        }
        current.next = node
        this.length++
    }

    addAtIndex(index, value) {
        if (this.head == null) {
            this.addAtHead(value);
            return;
        }
        let node = new ListNode(value);
        let current = this.head;
        while (current.next !== null) {
            current = current.next;
        }
        current.next = node;
        this.length++
    }

    // addAtIndex(index, value) {
    //     if (this.head === null || index === 0) {
    //         this.addAtHead(value)
    //         return
    //     }

    //     if (index === this.length) {
    //         this.addAtTail(value)
    //         return
    //     }
    //     if (index > this.length) return


    //     let node = new ListNode(value)
    //     let current = this.head
    //     for (let i = 0; i < index - 1; i++) {
    //         current = current.next
    //     }
    //     node.next = current.next
    //     current.next = node
    //     this.length++
    // }

    deleteAtIndex(index) {
        if (index < 0 || index >= this.length) return
        if (index === 0) {
            this.head = this.head.next
            return this.length--
        }

        let current = this.head
        for (let i = 0; i < index - 1; i++) {
            current = current.next
        }
        current.next = current.next.next
        this.length--
    }
}

// ["MyLinkedList","addAtIndex","get"]
// [[],[1,0],[0]]

let list = new MyLinkedList()
console.log(list.addAtIndex(1,0))
console.log(list)
console.log(list.get(0))
