import time 
import numpy as np

i = 0
print("numpy sort")
for idx in range (1, 11):
    file = 'test_' + str(idx) + '.txt'
    with open(file, 'r') as f:
        tests = f.readlines()
        i += 1
        for line in tests:
            test = np.array(line.split(), dtype='float')
            # print(test[-10:])
            start_time = time.time()  
            test = np.sort(test)
            end_time = time.time()
            length = round((end_time - start_time) * 1000)
            print(f"Sorting time of test {i}: {length} ms")
