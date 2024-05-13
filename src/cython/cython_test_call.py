import cython_test
import time

timer = time.time()
cython_test.main()
timer = time.time() - timer
print(f"Runs in: {timer:.3f} seconds")