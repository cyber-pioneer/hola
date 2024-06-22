import numpy as np

# 设置随机数种子以确保结果的可重复性（可选）
np.random.seed(0)

# 创建一个长度为20的随机正整数数组作为第二个数组的基础
# 假设正整数的范围是1到100
l1 = np.random.randint(1, 20, size=20)

# 为了确保第一个数组的每个元素都小于第二个数组对应位置的元素，
# 我们可以为第一个数组生成一个较小的随机数，并将其加到第二个数组的每个元素上，
# 然后从第二个数组的每个元素中减去这个随机数来得到第一个数组的元素。
# 这里我们选择随机数的范围为1到5，以确保有足够的差异。
diff = np.random.randint(1, 20, size=20)

# 创建第一个数组，其元素小于第二个数组对应位置的元素
l2 = l1 + diff

# 打印结果
print("First Array:", l1)
print("Second Array:", l2)

res = 0
for i, j in zip(l1, l2):
    res += j - i
print(res)

res = 0
l1.sort()
l2.sort()
for i, j in zip(l1, l2):
    res += j - i


print(res)
