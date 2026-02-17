# 🧠 Philosophers

A multithreaded implementation of the Dining Philosophers problem in C using **pthreads** and **mutexes**, implementing an even/odd scheduling strategy to prevent deadlocks and reduce fork contention.



## 📌 Project Goal

Simulate the Dining Philosophers problem while ensuring:

- No data races
- No deadlocks
- Accurate death detection
- Proper thread synchronization



## ⚙️ Implementation Strategy

### Fork Handling
- Each philosopher owns a **left fork** and a **right fork** (mutexes).
- A philosopher must lock both forks before eating.
- Forks are unlocked after eating.

### Even/Odd Scheduling Strategy
To reduce contention and avoid deadlocks:

- **Odd-numbered philosophers** start immediately.
- **Even-numbered philosophers** wait `time_to_eat / 2` before attempting to take forks.

```c
if (philo->id % 2 == 0)
    ft_usleep(philo->time_to_eat / 2);
```
##🚀 Compilation
```c
make
./philo number_of_philos time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
