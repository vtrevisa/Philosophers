# Philosophers

## Description
Philosophers is a 42 project that simulates the classic Dining Philosophers Problem, a concurrency challenge where multiple philosophers sit around a table, alternating between eating, thinking, and sleeping. The goal is to prevent deadlocks, starvation, and data races while ensuring all philosophers get a fair chance to eat.

The project involves multithreading, mutexes, and careful resource management to avoid synchronization issues.

## Features
- ✔ Multithreaded simulation of philosophers
- ✔ Deadlock prevention using mutexes (forks)
- ✔ Time management to track eating, sleeping, and thinking
- ✔ Parameter validation (number of philosophers, time to die, eat, sleep, and optional meal count)
- ✔ Visual log of each philosopher’s state (e.g., 1 is eating, 2 is sleeping)
- ✔ Bonus (if implemented): Process-based solution using semaphores

## Installation
Clone the repository:
```bash
git clone https://github.com/vtrevisa/Philosophers.git
```
Navigate to the project directory:
```bash
cd Philosophers
```
Compile the program:
```bash
make
```

## Usage
### Basic Execution
```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_meals]
```
> number_of_philosophers: Number of philosophers (and forks).
> time_to_die (ms): Time before a philosopher dies if they don’t eat.
> time_to_eat (ms): Time taken to eat.
> time_to_sleep (ms): Time taken to sleep.
> number_of_meals (optional): If set, simulation stops after each philosopher eats this many times.

## Example
(5 philosophers, die after 800ms without eating, take 200ms to eat, 200ms to sleep.)
```bash
./philo 5 800 200 200
```
## Algorithm & Synchronization
### Thread-Based Solution (Mandatory)
> Each philosopher is a thread.
> Mutexes represent forks, ensuring no two philosophers hold the same fork simultaneously.
> Time tracking prevents starvation (e.g., a philosopher dies if they don’t eat within time_to_die).
> Odd/even fork pickup helps prevent deadlocks (e.g., odd philosophers pick left first, even pick right first).

## Error Handling
> Detects invalid arguments (non-numbers, negative values).
> Handles thread creation errors.
> Prevents deadlocks and starvation.

## Testing
Basic Test (No Deadlocks)
```bash
./philo 4 410 200 200  # Should run indefinitely
```
Meal Limit Test
```bash
./philo 5 800 200 200 7  # Stops after each philosopher eats 7 times
```
Death Simulation
```bash
./philo 3 310 200 100  # Should show a philosopher dying
```
Large Number of Philosophers
```bash
./philo 200 410 200 200  # Stress test
```

Technical Details
> Written in C
> Uses pthreads (mutexes) or semaphores (bonus)
> Follows 42 Norm guidelines

## Author
👤 Vitor Trevisan - vi.trevi.11@gmail.com - vtrevisa
