import random as rd
import numpy as np

# testing the algorithm
# with open('tmp.txt', 'w') as f:
#     for i in range(10):
#         test = np.array([rd.uniform(-10, 10) for _ in range(10)])
#         if i == 0:
#             test = np.sort(test)
#         elif i == 1:
#             test = np.sort(test)[::-1]
#         f.write(' '.join(str(t) for t in test))
#         f.write('\n')

# real tests

for i in range(10):
    file = 'test_' + str(i+1) + '.txt'
    with open(file, 'w') as f:
        test = np.array([rd.uniform(-10**6, 10**6) for _ in range(10**6)])
        if i == 0:
            test = np.sort(test)
        elif i == 1:
            test = np.sort(test)[::-1]
        f.write(' '.join(str(t) for t in test))
        f.write('\n')