import pandas as pd
import matplotlib.pyplot as plt

# Загрузка данных
df = pd.read_csv('results.csv')

# 1. График сравнения времени поиска с логарифмической шкалой
plt.figure(figsize=(12, 7))

# Построение линий
plt.plot(df['Array Size'], df['Linear'], label='Linear Search', marker='o')
plt.plot(df['Array Size'], df['Binary'], label='Binary Search', marker='o')
plt.plot(df['Array Size'], df['RBTree'], label='Red-Black Tree', marker='o')
plt.plot(df['Array Size'], df['HashTable'], label='Hash Table', marker='o')
plt.plot(df['Array Size'], df['Multimap'], label='Multimap', marker='o')

# Логарифмическая шкала для оси Y
plt.yscale('log')
plt.xscale('log')
# Подписи
plt.title('Сравнение времени поиска')
plt.xlabel('Размер массива (log)')
plt.ylabel('Время поиска, миллисек. (log)')
plt.legend()
plt.grid(True, which="both", ls="--", alpha=0.5)

plt.tight_layout()
plt.savefig('search_time.png')
plt.show()

# 2. График количества коллизий 
plt.figure(figsize=(12, 7))
plt.plot(df['Array Size'], df['Collisions'], 'ro-', label='Коллизии')


# Подписи
plt.title('Количество коллизий в хеш-таблице')
plt.xlabel('Размер массива')
plt.ylabel('Число коллизий')
plt.grid(True, which="both", ls="--", alpha=0.5)

plt.tight_layout()
plt.savefig('collisions.png')
plt.show()

# 3. График сравнения без линейного поиска 
plt.figure(figsize=(12, 7))

# Построение линий без линейного поиска
plt.plot(df['Array Size'], df['Binary'], label='Binary Search', marker='s')
plt.plot(df['Array Size'], df['RBTree'], label='Red-Black Tree', marker='^')
plt.plot(df['Array Size'], df['HashTable'], label='Hash Table', marker='D')
plt.plot(df['Array Size'], df['Multimap'], label='Multimap', marker='*')



# Подписи
plt.title('Сравнение эффективных алгоритмов')
plt.xlabel('Размер массива')
plt.ylabel('Время поиска, миллисек.')
plt.legend()
plt.grid(True, which="both", ls="--", alpha=0.5)

plt.tight_layout()
plt.savefig('efficient_search.png')
plt.show()