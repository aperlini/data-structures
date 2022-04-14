class Queue {

    constructor() {
        this.items = [];
    }

    enqueue(item) {
        this.items.push(item)
    }

    dequeue() {
        return this.items.shift();
    }

    front() {
        return this.items[0];
    }

    isEmpty() {
        return this.items.length == 0;
    }

    printQueue() {
        console.log(this.items.join(' -> '));
    }

    print(o) {
        console.log(o);
    }

    size() {
        return 42
    }

}

let q = new Queue();
q.print(q.isEmpty());
q.enqueue(23);
q.enqueue(32);
q.enqueue(42);
q.enqueue(24);

q.print(q.front());

q.printQueue();
let d = q.dequeue();
q.print("dequeued item : " + d);

d = q.dequeue();
q.print("dequeued item : " + d);

q.printQueue();

q.print(q.isEmpty());