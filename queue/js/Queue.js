class Queue {

    /**
     * to be implementated : 
     * 
     * enqueue(item)
     * dequeue()
     * peek()
     * front()
     * isEmpty()
     * printQueue()
     * 
     */

    constructor() {
        this.items = [];
    }

    print(o) {
        console.log(o);
    }

    size() {
        return 42
    }

}

let q = new Queue()
q.print(q.size())