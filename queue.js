class Queue {
  constructor(array) {
    this.array = Array.isArray(array) ? array : [];
    this.offset = 0;
  }

  first() {
    return this.size() > 0 ? this.array[this.offset] : null;
  }

  last() {
    return this.size() > 0 ? this.array[this.array.length - 1] : null;
  }

  size() {
    return this.array.length - this.offset;
  }

  addToQueue(entity) {
    this.array.push(entity);
    return this;
  }

  removeFromQueue() {
    if (this.size() === 0) return null;

    const first = this.first();
    this.offset += 1;

    if (this.offset * 2 < this.array.length) return first;

    // instead of calling slice every time we remove an entity from the queue we do it only once the queue has been halved
    this.array = this.array.slice(this.offset);
    this.offset = 0;
    return first;
  }

  isEmpty() {
    return this.size() === 0;
  }

  toArray() {
    //clone it for obvious reasons
    return this.array.slice(this.offset);
  }

  clear() {
    this.array = [];
    this.offset = 0;
  }

  clone() {
    return new Queue(this.array.slice(this.offset));
  }
}

exports.Queue = Queue;
