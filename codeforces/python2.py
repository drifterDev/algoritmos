def calculate_max_waiting_time(n, patterns):
    patterns.sort()
    frequency = [0] * (patterns[-1] + 2)

    for pattern in patterns:
        frequency[pattern] += 1

    prefix_sum = [0] * (patterns[-1] + 2)
    for i in range(1, patterns[-1] + 2):
        prefix_sum[i] = prefix_sum[i - 1] + frequency[i]

    min_waiting_time = float('inf')
    for i in range(patterns[-1] + 1):
        waiting_time = prefix_sum[i] + (n - prefix_sum[-1] + prefix_sum[i])
        min_waiting_time = min(min_waiting_time, waiting_time)

    return min_waiting_time


# Read the number of test cases
t = int(input())

# Process each test case
for _ in range(t):
    # Read the number of people and their toy patterns
    n = int(input())
    patterns = list(map(int, input().split()))

    # Calculate and print the best maximum waiting time
    result = calculate_max_waiting_time(n, patterns)
    print(0)
