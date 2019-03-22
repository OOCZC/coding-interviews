// 五种单例模式的写法

// 饿汉模式
public class Single {

    private static Single single = new Single();
    
    private Single() {}
    
    public static Single getInstance() {
        return single;
    }
}

// 线程安全，函数同步

public class Single {

    private static Single single;    

    private Single() {}

    public static synchronized Single getInstance() {
        if (single == null)
            single = new Single();
        return single;
    }
}

// 双重校验锁

public class Single {

    private static volatile Single single;

    private Single() {}

    public static Single getInstance() {
        if (single == null) {
            synchronized(Single.class) {
                if (single == null)
                    single = new Single();
            }
        }
        return single;
    }
}


// 静态内部类

public class Single {

    private Single() {}

    private static class SingleHolder {
        private static Single single = new Single();
    }

    public static Single getInstance() {
        return SingleHolder.single;
    }
}

// 枚举类


public enum Single {
    INSTANCE;
}
