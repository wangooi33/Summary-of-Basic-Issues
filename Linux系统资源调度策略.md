## 优先级别：

### (1)   静态优先级	（优先级数值越大则优先级越高）

普通任务的优先级是0，系统任务的优先级是1~99

1.SCHED_OTHER调度策略指的是分时调度策略（进程执行时间越长，权重越小），静态优先级必须设置为0

2.SCHED_FIFO调度策略指的是实时调度策略，先到先服务

3.SCHED_RR指的是实时调度策略，时间片轮转

### (2）动态优先级	（nice值  -20 ~ 19）

Linux系统中线程的nice值越高，则优先级越低，而nice值越低，反而优先级越高