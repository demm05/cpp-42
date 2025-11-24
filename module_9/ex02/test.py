import subprocess
import random
import sys
import shutil
import time

# --- CONFIGURATION ---
EXECUTABLE = "./PmergeMe"  # Path to your executable
NUM_TESTS = 100  # How many random tests to run
MAX_VAL = 100000  # Maximum value of a number
MIN_SIZE = 1  # Minimum list size
MAX_SIZE = 500  # Maximum list size (adjust based on speed)
# ---------------------

# Colors for output
GREEN = "\033[92m"
RED = "\033[91m"
YELLOW = "\033[93m"
RESET = "\033[0m"


def check_executable():
    if not shutil.which(EXECUTABLE) and not shutil.which("./" + EXECUTABLE):
        print(f"{RED}Error: Executable '{EXECUTABLE}' not found.{RESET}")
        print("Please compile your code and ensure the path is correct.")
        sys.exit(1)


def run_test(input_nums, test_id):
    """Runs the PmergeMe executable with the given numbers."""

    # Convert integers to list of strings
    args = [str(n) for n in input_nums]

    try:
        # Capture output to hide it unless there's an error,
        # but allow stderr to pass through if needed.
        start_time = time.time()
        result = subprocess.run([EXECUTABLE] + args, capture_output=True, text=True)
        duration = time.time() - start_time

        # CHECK EXIT CODE
        if result.returncode != 0:
            print(f"\n{RED}[FAILED] Test #{test_id}{RESET}")
            print(f"Input Size: {len(input_nums)}")
            print(f"Exit Code: {result.returncode}")
            print(f"Stderr: {result.stdout}")

            # If input is small, print it. If huge, save to file.
            if len(input_nums) < 50:
                print(f"Input: {' '.join(args)}")
            else:
                with open("failed_input.txt", "w") as f:
                    f.write(" ".join(args))
                print(
                    f"{YELLOW}Input too large to print. Saved to 'failed_input.txt'{RESET}"
                )
            return False

        return True

    except OSError as e:
        print(f"{RED}Execution failed: {e}{RESET}")
        sys.exit(1)


def main():
    print(f"{YELLOW}Starting Stress Test on {EXECUTABLE}...{RESET}")
    check_executable()

    passed = 0

    # 1. EDGE CASES
    edge_cases = [
        [1],
        [1, 2],
        [2, 1],
        [1, 2, 3, 4, 5],  # Already sorted
        [5, 4, 3, 2, 1],  # Reverse sorted
        [2147483647, 0, 42],  # Max int, zero
    ]

    print(f"\n{YELLOW}--- Running Edge Cases ---{RESET}")
    for idx, case in enumerate(edge_cases):
        if run_test(case, f"Edge-{idx + 1}"):
            print(f"{GREEN}Edge Case #{idx + 1} Passed{RESET}")
        else:
            sys.exit(1)

    # 2. RANDOM TESTS
    print(f"\n{YELLOW}--- Running {NUM_TESTS} Random Tests ---{RESET}")
    for i in range(1, NUM_TESTS + 1):
        # Generate random size
        size = random.randint(MIN_SIZE, MAX_SIZE)

        # Generate random unique numbers (change sample to choices if you handle duplicates)
        # Using sample ensures uniqueness, which matches standard PmergeMe constraints
        nums = random.sample(range(0, MAX_VAL), size)

        sys.stdout.write(f"\rRunning Test {i}/{NUM_TESTS} [Size: {size}]")
        sys.stdout.flush()

        if not run_test(nums, i):
            sys.exit(1)

    print(f"\n\n{GREEN}SUCCESS! All tests passed.{RESET}")


if __name__ == "__main__":
    main()
