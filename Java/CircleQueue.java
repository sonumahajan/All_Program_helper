public class CircleQueue {
  static int arr[] = new int[5];
  static int front = -1, rear = 0;
  static void enqueue(int val) {
    if (front == -1 && rear == 0) {
      arr[rear] = val;
      front = 0;
      rear = 0;
    } else if (rear == arr.length - 1 && front == 0
        || front != 0 && rear == (front - 1) % (arr.length - 1)) {
      System.out.println("overflow");
    } else if (front != 0 && rear == arr.length - 1) {
      rear = (rear) % (arr.length - 1);
      arr[rear] = val;
    } else {
      rear = rear + 1;
      arr[rear] = val;
    }
  }
  static void dequeue() {
    if (front == -1 && rear == 0) {
      System.out.println("lodu lalit");
    } else {
      front++;
    }
  }
  static void print() {
    if (front <= rear) {
      for (int i = front; i <= rear; i++) {
        System.out.println(arr[i] + "  ");
      }
    } else {
      for (int i = front; i <= arr.length - 1; i++) {
        System.out.println(arr[i] + " ");
      }
      for (int i = 0; i <= rear; i++) {
        System.out.println(arr[i] + " ");
      }
    }
  }
  public static void main(String[] args) {
    // dequeue();
    enqueue(45);
    enqueue(67);
    enqueue(78);
    enqueue(89);
    enqueue(789);
    print();
    System.out.println("");
    dequeue();
    print();
    enqueue(1000);
    System.out.println("");
    print();
  }
}
