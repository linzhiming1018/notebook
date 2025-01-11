# `scanf`的使用

需要将一个地址传递给 `scanf`，以便它可以将输入的值存储到该地址所指向的变量中。`scanf` 函数通过这个地址来直接修改变量的值。

- 对于基本数据类型，使用 `&` 符号。
- 对于数组元素，使用 `&array[i]`。

有一些情况不需要使用 `&` 符号。
1. **数组名**：当你传递整个数组时，数组名本身就代表了数组的首地址，因此不需要使用 `&`。例如：
```c
    int array[10];
    scanf("%d", &array[0]); // 正确
    scanf("%d", array);      // 也正确，array 代表 &array[0]
```

2. **指针**：如果你使用指针变量，指针本身已经存储了地址，因此不需要再使用 `&`。例如：
```c
    int *ptr;
    int value;
    ptr = &value; // ptr 存储了 value 的地址
    scanf("%d", ptr); // 正确，ptr 已经是地址
```

3. **结构体成员**：在使用结构体时，如果你要读取结构体成员的值，也需要使用 `&`，但如果你有一个指向结构体的指针，则可以直接使用指针。例如：
```c
    struct Person {
        int age;
    };

    struct Person p;
    scanf("%d", &p.age); // 正确，p.age 是 int 类型

    struct Person *ptr = &p;
    scanf("%d", &ptr->age); // 正确，ptr->age 也是 int 类型
```

```c
struct Person {
    int age;
};

struct Person p;
p.age = 114514;
struct Person *ptr = &p;
scanf("%d", ptr->age);
```