class Stack {

    /**
     * implementation : 
     * 
     * push(item)
     * pop()
     * peek()
     * isEmpty()
     * printStack()
     * 
     */

    constructor() {
        this.items = [];
    }

    /**
     * Add item on top
     *  
     */
    push(item) {
        this.items.push(item);
    }

    /**
     * Removes top most item in the stack
     * 
     * @returns top item in the stack
     */
    pop() {
        if (this.isEmpty()) {
            return "Underflow";
        }
        return this.items.pop();
    }

    /**
     * Get top most item in the stack
     * 
     * @returns top item in the stack
     */
    peek() {
        if (!this.isEmpty()) {
            return this.items[this.items.length - 1];
        }
    }

    isEmpty() {
        return this.items.length == 0;
    }

    /**
     * Print top to bottom
     * 
     */
    printStack() {
        this.print("");
        this.print("Stack : ");
        this.print("");
        let size = this.items.length;
        while (size) {
            if (size != this.items.length)
                this.print("--- \u2193");
            this.print("--- " + this.items[size - 1]);
            size--;
        }
        this.print("");

        // this.print(this.items.join(" "));
    }

    print(o) {
        console.log(o);
    }

}

let s = new Stack();
s.print(s.isEmpty());
s.push(42);
s.push(24);
s.push(23);
s.push(101);
s.push(3);
s.print(s.isEmpty());
s.print(s.pop());
s.print(s.peek());
s.printStack();