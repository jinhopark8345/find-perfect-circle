import math




def make_perfect_circle(max_num):
    powers = set()
    max_sum = max_num * 2 - 1
    power_range = int(math.sqrt(max_sum)) + 1
    powers = set([num**2 for num in range(1, power_range)])

    vec = [i for i in range(1, max_num + 1)]
    found = False
    print(f'init vec len: {max_num}')

    def permutate(idx, vec):
        if idx == max_num:
            if (vec[0] + vec[-1]) in powers:
                nonlocal found
                found = True
                print(vec)
            return
        for i in range(idx, max_num):
            if not found:
                if i >= 1 and (vec[idx - 1] + vec[i]) in powers:
                    vec[i], vec[idx] = vec[idx], vec[i]
                    permutate(idx + 1, vec)
                    vec[i], vec[idx] = vec[idx], vec[i]
                else:
                    continue

    permutate(0, vec)




for i in range(35, 50):
    make_perfect_circle(i)
