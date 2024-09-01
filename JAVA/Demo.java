class A implements Runnable {
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.print("\nGood");
            try {
                Thread.sleep(5000);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

class B implements Runnable {
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.print("\nMorning");
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

public class Demo {
    public static void main(String[] args) {
        Runnable obj = new A();
        Runnable obj1 = new B();
        Thread t1 = new Thread(obj);
        Thread t2 = new Thread(obj1);
        
        t1.start();
        t2.start();
    }
}
