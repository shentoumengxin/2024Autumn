# Advanced Programming

## Structure



## 指针

### Key word : * access the value  & get the memory address  

指针都占 8byte int * a 前面的int指的是**指向的数据类型**

**int** 4byte **short** 2 byte **long** 8 byte **char** 1 byte

<b>访问对象的成员或成员函数用‘.’   用指针指向的对象的成员访问用 ‘ -> ’ </b>

```cpp 
int a[5][5];
int *ptr1=a+1   //a will point to a[1]
int *ptr2=&a   //a will point to a[5]后一个内存位置

```

### 指针数组

`node **ptr=new node*[100]`

右半边：new 了一段内存，来储存100个node的地址

左半边：表明这个指针指向的类型是 1*（数组地址）2（数组元素是地址）

### 指针和*指针的区别

例如，我们可以对这段地址排序（根据地址元素）我们不改变内存的位置（swap部分不动元素）。

**swap对指针进行操作**，经过排序的指针，根据每一个指针去访问节点，就能保证你能按照有序去访问所有节点，而**不改变内存位置**。

### Key word new

在**heap堆**有很多的空白地址，可以用**new** 关键字申明，**delet** 进行释放

int *parr1= new int [10]

可以通过parr1[1],…进行访问，相当于自己申请了内存。

### Const and point

```cpp
const int * p_snack=&gorp;  //这个指针指向的地址的内容不能发生改变（i.e.protect )
*p_snack=20;  //INVALID  
p_snack=&chips ; //valid
//  Incontrast
int * const p_snack=&gorp;   //指向的地址不能改变
*p_snack=20;  //VALID  
p_snack=&chips ; //INvalid
```



### 指针数组，和指向的数组大小：

- `int (*arr)[3]`：
  - `arr` 是一个指向包含 3 个 `int` 元素的数组的指针。
  - 用法：你可以通过 `(*arr)[i]` 访问数组的元素。
- `int arr *[3]`：
  - `arr` 是一个指针数组，该数组有 3 个指针，每个指针都指向一个 `int` 变量。
  - 用法：你可以通过 `*arr[i]` 访问每个指针指向的 `int` 变量。

```cpp
int (*arr)[3] 表示指向一个具有 3 列的整型数组的指针，即 arr 是一个指针，指向一个长度为 3 的整型数组。
```



## C++的内存空间管理方式

这些都是管理方式，是cpp对不同内存空间划分的不同管理方式

1. **Static** key word– will be create and storage since the programme start

   static 如果不用delete，将一直在内存中进行存储。对于作用域

   编译器会**限制** 外界的代码不允许对他访问。

2. **Automatic Storage** 

   int a=0  

   系统自动帮忙分配地址，回收空间。在作用域生成，作用域结束，就直接删除。

   They expire when the function terminates

   ```*ptr = 20;ptr = new int;```

   都是在heap堆重新申明，两个指向两个不同的空间。

   Ø Automatic variables typically are stored on a **Stack**

   Ø A last-in, first-out, or LIFO, process

3. **Dynamic Storage**

   key word **new** to create a memory in the heap

### Cpp 二维数组的理解

二维数组用 `int *arr [20]=a[10][20]`来储存。换句话来说，这是一个指针，指向

## Loop 和 运算顺序（爱考）

1. **前置和后置运算符：**
   - 前置形式（`++x` 或 `--x`）通常比后置形式更高效，因为它不需要保存临时值供表达式使用后再增量或减量。
2. **增量/减量运算符与指针：**
   - 对指针应用增量运算符时，指针会根据它所指向的类型大小移动。例如，如果指针指向一个 `int`，则 `p++` 会使指针向前移动 4 个字节（假设 `int` 是 4 个字节）。
   - 这个特性对指针很有用，因为它允许我们轻松遍历数组中的元素。
3. **运算符优先级：**
   - 前置增量/减量运算符（如 `++x`, `--x`）和解引用运算符（如 `*x`）的优先级是相同的，并且**它们的运算顺序是从右到左。**这意味着在表达式中，它们会先进行右侧的运算，然后再进行左侧的运算。
   - 后置增量/减量运算符（如 `x++`, `x--`）的优先级比前置运算符高，且它们的运算顺序是从左到右。即使它们看起来是“在使用后再操作”，它们的高优先级意味着在某些表达式中会比前置运算符先执行。

总结来说，前置运算符更高效，而后置运算符优先级更高。

## Function·  and Header file: 

• const variable or macro definition

 • structure declaration 

• function prototyp

**Three components **

 Provide a function definition including two parts: head and body    Provide a function prototype   Call the function

**Two types of usage **

* Use a library function üIncluding the header file üStatic library is locked into at compiling time 

* Dynamic library exists as a separate file outside of the executable file 

*  Create your own functions üHandle all three aspect

**Recursive programs are generally slower than nonrecursive programs. **

Because it needs to make a function call so the program must save all its current state and retrieve them again later. This consumes more time making recursive programs slower. 

• Recursive programs requires more memory to hold intermediate states in a stack. Non recursive programs don’t have any intermediate states, hence they don’t require any extra memory

### Prototype (申明函数)

In C++, a **function prototype** is a declaration of a function that tells the compiler about the function's name, return type, and parameter types, but does not include the function’s body. It allows functions to be called before they are defined.

Example

```cpp
#include <iostream>
using namespace std;

// Function prototype
int add(int a, int b);

int main() {
    int result = add(5, 3);  // Calling add() before it’s defined
    cout << "The result is: " << result << endl;
    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;
}
```

## 函数的工作

### 函数调用流程

**存储返回地址**：

- 当程序调用一个函数时，它会先存储当前执行位置的内存地址，这个地址是**紧跟在函数调用指令后的地址**。这样，当函数执行完毕后，程序可以跳转回这个位置，继续执行调用函数后面的代码。

**将函数参数拷贝到栈中**：

- 在调用函数时，程序会将函数的参数拷贝到栈中，以便在函数内部可以访问这些参数。这一步是通过“压栈”操作完成的，参数会被存储在栈帧（stack frame）中，栈帧是函数调用时在栈上分配的区域。

**跳转到函数开始地址**：

- 程序跳转到**函数代码的内存起始位置**，也就是函数的入口处，从这个位置开始执行函数的代码。

**执行函数代码**：

- 在函数执行过程中，程序会使用栈帧中的参数值和函数内部的局部变量，直到函数结束。

**跳回到返回地址**：

- 函数执行完后，程序会使用**之前存储的返回地址**，跳转回到函数调用处继续执行。这个地址指向的是调用函数的下一条指令。

### **栈中的内容**

在调用函数时，栈中存储的是：

- **返回地址**：用于指向调用函数的下一条指令的位置，以便函数执行完毕后能跳回到调用点。
- **函数参数**：如果有函数参数，这些参数会在调用时被压入栈中，以供函数内部使用。
- **局部变量**：在函数中声明的局部变量会被分配在栈中。
- **栈帧**：每次函数调用都会在栈上创建一个新的栈帧，存储当前调用的上下文信息。函数执行完后，栈帧被销毁，释放出空间。

### **函数指令的存储位置**

函数的指令在编译后存储在内存的代码段中，并不是在栈中。函数调用时，程序会通过跳转指令访问代码段中的指令地址。例如，调用 `foo()` 函数时，程序会跳转到 `foo` 的内存地址开始执行，并将返回地址压入栈中

###  引用（Reference）

引用是一个变量的别名，主要用于安全和简洁的间接访问。引用一旦绑定到某个变量后，就无法更改引用的目标。

**特点**：

- 定义和绑定

  ：引用在定义时必须初始化，一旦初始化后就不能更改它所指向的对象。例如：

  ```cpp
  int x = 10;
  int& ref = x; // ref 是 x 的引用
  ```

- **不占内存**：引用本质上不占用额外内存空间，而是**编译器会将引用替换为对应的变量**。

- **自动解引用**：引用在使用时不需要解引用操作（即不需要使用 `*` 运算符）。

- **不可空**：引用必须绑定到一个有效的对象，因此不存在“空引用”。

**用途**：

- **参数传递**：常用于函数参数传递，通过引用传递的参数可以在函数内部修改原对象。
- **返回值优化**：可以用引用返回一个对象，避免不必要的拷贝。

**示例**：

```cpp
void increment(int& value) { // 引用作为函数参数
    value++;
}

int main() {
    int x = 5;
    increment(x); // x 变为 6
}
```

```cpp
const int &=1  //const reference can only store lvalue
```



### Temporary Variables, Reference Arguments, and const

lvalue

**lvalue**（locator value）指的是一个在内存中有确定地址的对象。它可以出现在赋值操作符的左侧，也可以出现在右侧。简单来说，**lvalue** 是可以被赋值的对象。以下是一些 **lvalue** 的例子：

- 变量名，例如 *int a;* 中的 *a*。
- 数组元素，例如 *arr[0]*。
- 指针解引用，例如 **ptr*。
- 结构体成员，例如 *obj.member*。

rvalue

**rvalue**（read value）指的是一个没有确定内存地址的值。它通常出现在赋值操作符的右侧，而不能出现在左侧。**rvalue** 是一个表达式的值，不能被赋值。以下是一些 **rvalue** 的例子：

- 常量，例如 *42*。
- 表达式的结果，例如 *a + b*。
- 函数返回值（如果返回的是非引用类型）。

**左值与右值的区别**

| **属性**         | **左值（lvalue）**               | **右值（rvalue）**                 |
| ---------------- | -------------------------------- | ---------------------------------- |
| **存储**         | 有持久地址（指向内存中具体位置） | 无持久地址（通常是临时值）         |
| **作用**         | 可出现在赋值操作的左侧           | 只能出现在赋值操作的右侧           |
| **是否可取地址** | 可以使用 `&` 取地址              | 不能取地址                         |
| **是否可引用**   | 可以用左值引用（`T&`）引用       | 可以用右值引用（`T&&`，C++11）引用 |
| **生存期**       | 在作用域内持久存在               | 临时存在，仅在表达式计算时有效     |
| **典型例子**     | 变量、数组元素、返回的左值引用   | 字面值、表达式的结果、临时对象     |



#### **赋值中的左值和右值**

```
cpp复制代码int x = 10;  // x 是左值，10 是右值
x = x + 5;   // x 是左值，x + 5 是右值
```

#### **函数中的左值和右值**

```cpp
int foo() {
    return 42; // 42 是右值
}

int main() {
    int x = foo(); // foo() 返回一个右值
    int& lref = x; // 左值引用，可以绑定到左值 x
    int&& rref = foo(); // 右值引用，可以绑定到右值
    return 0;
}
```

## 参数的类型转换

1. 精确匹配（Exact Match）

如果传入的参数类型与函数声明中的参数类型**完全匹配**，则无需任何类型转换。这是编译器的首选情况，因为它避免了额外的开销。例如：

```cpp
void func(int x); // 声明

func(5); // 参数完全匹配，直接使用
```

2. 常量和引用转换（Const and Reference Conversion）

- 非 `const` 对象可以传递给接受 `const` 引用的参数。例如，如果函数参数是 `const int&` 类型，非 `const` 的 `int` 参数可以直接传递。
- 此外，左值可以传递给左值引用，而右值可以传递给右值引用。

```cpp
void func(const int& x); // const 引用

int a = 5;
func(a); // 非const的a可以传递给const引用
```

3. 提升转换（Promotion）

如果传入的参数类型与函数参数类型不完全匹配，但可以通过**提升**（promotion）来转换，则进行提升转换。例如：

- `char` 和 `short` 会自动提升为 `int`。
- `float` 会提升为 `double`。

```cpp
void func(double x);

func(3.14f); // float提升为double
```

4. 标准转换（Standard Conversion）

标准转换包括较安全的隐式类型转换，例如：

- 从较小范围到较大范围的转换（如 `int` 转为 `long` 或 `double`）。
- 指针类型转换：如 `int*` 可以转换为 `const int*`，但是不能从 `int*` 转换为 `double*`。

5. 用户定义的转换（User-Defined Conversion）

如果上述转换不适用，编译器会尝试使用**用户定义的类型转换**。这通常涉及构造函数或 `operator` 重载的转换。

例如，假设一个类定义了从 `int` 到该类的构造函数，则传入 `int` 时可以调用该构造函数：

```cpp
class MyClass {
public:
    MyClass(int x) {} // 构造函数，实现从int到MyClass的转换
};

void func(MyClass obj);
func(5); // int自动转换为MyClass类型
```

6. 强制类型转换（Explicit Conversion）

如果函数要求严格的类型匹配，用户可以使用强制类型转换，例如 `static_cast`、`reinterpret_cast`、`const_cast` 等来进行精确转换。这种转换需要用户显式进行，编译器不会自动执行。



## 常量指针 Const *

| **声明**               | **含义**                                                     |
| ---------------------- | ------------------------------------------------------------ |
| `const int* ptr`       | 指针指向的数据是常量（不能通过指针修改数据），指针本身可以改变。 |
| `int const* ptr`       | 同上，指针指向的数据是常量，指针本身可以改变。               |
| `int* const ptr`       | 指针本身是常量（不能改变指针的值），指针指向的数据可以改变。 |
| `const int* const ptr` | 指针本身是常量，指针指向的数据也是常量（既不能修改指针，也不能修改数据）。 |
| `int* ptr`             | 指针和所指向的数据都可以改变（默认情况）。                   |

**方法是从右向左解读指针**

例如：`const int* ptr` → `ptr` 是指向 `const int` 的指针。

## Separate Compilation

### 编译过程概览：

图示展示了将多个源文件编译和链接成一个可执行文件的步骤：

1. **预处理器处理头文件**：
   - 在源文件（例如 `file1.cpp` 和 `file2.cpp`）中包含头文件 `coordin.h`。
   - 预处理器会将包含的头文件代码插入到源文件中，并去除重复包含的内容（通过头文件保护机制实现）。
2. **编译源文件**：
   - 预处理后的文件（如 `temp1.cpp` 和 `temp2.cpp`）被编译成对应的目标文件（如 `file1.o` 和 `file2.o`）。
3. **链接目标文件**：
   - 编译器将所有目标文件和库文件链接在一起，生成一个最终的可执行文件（如 `a.out`）。



在 C++ 中，程序的各个组件函数可以放置在不同的文件中。这样设计的好处在于：

- **可以只修改一个文件并重新编译该文件**：当需要对程序的某一部分进行修改时，可以只编译修改过的文件，而不需要重新编译整个项目，节省了开发和编译的时间。
- **更容易管理大型程序**：将程序分割成多个文件后，可以将不同的功能模块分开，使代码结构更加清晰，有助于团队协作和项目管理。
- **多数集成开发环境（IDE）提供额外的管理工具**：例如在 Unix 和 Linux 系统中的 `make` 工具，可以通过 `Makefile` 文件来管理文件依赖关系和编译流程，自动处理哪些文件需要重新编译，提升编译的效率。

将原始程序分为三个部分

在大型 C++ 项目中，通常将程序拆分为以下三个部分：

1. **头文件（Header File）**：包含结构体（类型）的声明，以及使用这些结构体（类型）的函数的原型（即函数声明）。通常这些文件以 `.h` 或 `.hpp` 结尾。例如，`my_struct.h` 文件中包含结构体声明和相关函数的声明。
2. **源代码文件（Source Code File 1）**：包含定义结构体（类型）相关函数的**具体实现**。这个文件实现了头文件中声明的函数，文件通常以 `.cpp` 结尾。例如，`my_struct.cpp` 文件中包含结构体相关函数的定义。
3. **源代码文件（Source Code File 2）**：包含**调用**结构体（类型）相关函数的代码。在这个文件中，通过调用结构体相关的函数来实现具体的程序功能。这部分代码通常是程序的主要逻辑代码，也以 `.cpp` 结尾。

**函数不用heap或者stack进行储存，它在code区域**

#### **函数指针的定义**

- 函数指针用于存储函数的地址，通过函数指针可以调用函数。

- 语法：

  ```cpp
  return_type (*pointer_name)(parameter_list);
  ```

#### **示例**

```cpp
#include <iostream>
using namespace std;

// 定义一个普通函数
int add(int a, int b) {
    return a + b;
}

int main() {
    // 定义一个函数指针
    int (*func_ptr)(int, int) = add;

    // 通过函数指针调用函数
    cout << "Result: " << func_ptr(2, 3) << endl; // 输出 5

    return 0;
}
```

------

### **2. 函数指针的声明**

#### **基本形式**

```cpp
return_type (*pointer_name)(parameter_list);
```

#### **示例**

1. 指向无参数、无返回值函数的指针：

   ```cpp
   void (*func_ptr)();
   ```

2. 指向有参数、有返回值函数的指针：

   ```cpp
   int (*func_ptr)(int, double);
   ```

#### **初始化**

- 函数指针可以通过函数名初始化，因为函数名是函数的地址。

  ```
  cpp
  
  
  复制代码
  int (*func_ptr)(int, int) = add;
  ```

------

### **3. 函数指针的调用**

#### **通过函数指针调用函数**

- 直接调用：

  ```cpp
  
  func_ptr(a, b);
  ```

- 使用解引用符号调用（等价）：

  ```cpp
  (*func_ptr)(a, b);
  ```

------

### **4. 函数指针作为函数参数**

#### **用途**

函数指针可以作为参数传递给另一个函数，用于实现回调机制。

#### **示例**

```cpp
#include <iostream>
using namespace std;

// 普通函数
int add(int a, int b) {
    return a + b;
}

// 使用函数指针作为参数
void operate(int x, int y, int (*func)(int, int)) {
    cout << "Result: " << func(x, y) << endl;
}

int main() {
    operate(5, 3, add); // 将函数 add 的地址传递给 operate
    return 0;
}
```

**输出**：

```
makefile


复制代码
Result: 8
```

------

### **5. 函数指针数组**

#### **用途**

- 可以存储多个具有相同参数和返回值类型的函数。
- 通过下标选择不同的函数。

#### **示例**

```cpp
#include <iostream>
using namespace std;

// 定义多个函数
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }

// 定义函数指针数组
int (*func_ptrs[2])(int, int) = {add, subtract};

int main() {
    cout << "Add: " << func_ptrs[0](5, 3) << endl;       // 调用 add
    cout << "Subtract: " << func_ptrs[1](5, 3) << endl; // 调用 subtract
    return 0;
}
```

**输出**：

```makefile
Add: 8
Subtract: 2
```

### 作用域（Scope）

**作用域**指的是一个名称在程序文件中的可见性范围，决定了名称在代码中的有效范围。

1. **局部作用域（Local Scope）**：局部作用域的变量只在定义它们的代码块（通常是大括号 `{}` 内）中可见和有效。它们的生命周期在块结束时结束。例如：

   ```cpp
   void func() {
       int x = 10; // x 在这个块中可见
   }
   ```

2. **全局作用域（Global Scope）**：全局作用域的变量从定义点开始，直到文件结束时都可见，且在整个文件中都能访问。通常在所有函数之外定义的变量具有全局作用域。例如：

   ```cpp
   int globalVar = 5; // globalVar 在整个文件中都可见
   ```
   
3. **函数原型作用域（Function Prototype Scope）**：函数参数在函数原型的参数列表（即括号 `()` 内）中有效，但在函数体外不可见。例如：

   ```cpp
   void func(int x); // x 仅在函数声明的参数列表中可见
   ```
   
4. **类作用域（Class Scope）**：类中的成员变量和成员函数在类内可见，但在类外不可直接访问，除非通过对象或合适的访问修饰符（如 `public`、`protected`、`private`）进行访问。例如：

   ```cpp
   class MyClass {
       int a; // a 在 MyClass 内可见
   public:
       void display();
   };
   ```

5. **命名空间作用域（Namespace Scope）**：命名空间内的名称在命名空间内有效，使用时需要加上命名空间的前缀，或者使用 `using` 语句引入。例如：

   ```cpp
   namespace MyNamespace {
       int var = 10; // var 在 MyNamespace 中可见
   }
   ```

### 链接（Linkage）

**链接**描述了名称在不同编译单元（例如不同的源文件）中的共享方式。

1. **外部链接（External Linkage）**：具有外部链接的名称可以在多个文件中共享。例如，全局变量和函数默认具有外部链接，通过 `extern` 关键字可以显式指定外部链接。

   ```cpp
   
   extern int sharedVar; // 可以在其他文件中共享的变量
   ```
   
2. **内部链接（Internal Linkage）**：具有内部链接的名称只能在单个文件中共享，不能跨文件访问。通常使用 `static` 关键字声明具有内部链接的全局变量或函数。

   ```cpp
   
   static int fileVar = 5; // 仅在当前文件中可见
   ```
   
3. **无链接（No Linkage）**：自动变量（函数内的局部变量）和块中的静态变量没有链接，意味着它们只能在其定义的块内访问，不能在文件的其他位置共享。

   ```cpp
   void func() {
       int localVar = 10; // 没有链接
       static int staticVar = 5; // 静态局部变量，也没有链接
   }
   ```

通过作用域和链接的结合，可以在 C++ 程序中灵活控制名称的可见性和共享性，从而实现模块化和封装



- #### 自动变量（Automatic Variables）

  **自动变量**是在函数或代码块中定义的局部变量。它们在函数调用时自动创建，并在函数返回后自动销毁。

  - **自动变量的初始化**：

    - 可以在声明自动变量时用任何已知的表达式进行初始化。例如：

      ```
      cpp复制代码int x = 5; // 自动变量 x 初始化为 5
      int y = x + 10; // y 用 x 的值进行初始化
      ```

    - 初始化值必须在变量声明时已知，才可以用于自动变量的初始化。

  - **自动变量与栈（Stack）**：

    - 自动变量通常在**栈内存**中分配。栈是一种“先进后出”（First-In-Last-Out, FILO）的数据结构，适用于自动变量的生命周期管理。
    - 当程序进入某个函数时，新的自动变量会“压入”栈顶，原有的变量保留在栈底。当程序离开函数时，这些变量会从栈中“弹出”并被销毁。
    - 这种机制让程序管理自动变量的内存更加高效。

  #### 寄存器变量（Register Variables）

  **寄存器变量**是使用 `register` 关键字声明的变量，建议编译器将该变量存储在 CPU 寄存器中，而不是栈或内存中。寄存器变量的目的是加快变量的访问速度，因为 CPU 寄存器比内存快得多。

- **C语言中的 `register` 关键字**：

  - 在 C 语言中，`register` 关键字被引入，以提示编译器优先将该变量存储在 CPU 寄存器中（如果有空闲寄存器）。

### 1. 静态库（Static Library）

静态库通常是 `.lib`（在Windows）或 `.a`（在Linux）文件。静态库在**编译时**与可执行文件链接，编译完成后库的内容会被直接复制到可执行文件中。

特点

- **链接时机**：在编译期间，库的代码会被链接到目标程序中。
- **独立性**：生成的可执行文件不依赖外部的静态库文件，所有需要的代码都已嵌入。
- **文件大小**：可执行文件会比较大，因为包含了库的代码。
- **更新**：如果静态库的代码发生变化，需要重新编译可执行文件。
- **性能**：加载时不需要额外的动态链接，启动速度更快。

使用示例

假设有一个静态库 `libmylib.a`，在编译时可以通过如下方式链接：

```shell

g++ main.cpp -L/path/to/lib -lmylib -o myprogram
```

这里 `-L` 指定库路径，`-l` 指定库名称（不需要加`lib`前缀和`.a`后缀）。

### 2. 动态库（Dynamic Library）

动态库也称为共享库，在Windows上为 `.dll`，在Linux上为 `.so`。动态库在**运行时**加载，它们可以独立于程序文件而存在。

特点

- **链接时机**：在运行时由系统动态加载库文件。
- **共享性**：多个程序可以共享同一个动态库，从而减少内存占用。
- **文件大小**：可执行文件较小，因为动态库的代码不嵌入其中。
- **更新**：更新库文件后，不需要重新编译主程序，只需在运行时加载新的库即可。
- **性能**：因为需要动态加载，首次加载库时启动速度会稍慢。

使用示例

假设有一个动态库 `libmylib.so`，可以在编译时链接并在运行时加载：

```shell
g++ main.cpp -L/path/to/lib -lmylib -o myprogram
```

运行时需要动态库的路径。可以在运行时指定 `LD_LIBRARY_PATH` 环境变量来告诉程序库文件的位置：

```shell
export LD_LIBRARY_PATH=/path/to/lib:$LD_LIBRARY_PATH
./myprogram
```

### 静态库与动态库的对比总结

| 特性         | 静态库                       | 动态库                        |
| ------------ | ---------------------------- | ----------------------------- |
| **扩展名**   | `.a`（Linux）、`.lib`（Win） | `.so`（Linux）、`.dll`（Win） |
| **链接时机** | 编译时                       | 运行时                        |
| **文件大小** | 较大                         | 较小                          |
| **共享性**   | 无法共享                     | 多个程序可共享                |
| **更新方式** | 需要重新编译                 | 无需重新编译                  |
| **性能**     | 启动较快                     | 运行时加载较慢                |

### 选择静态库还是动态库

- **静态库**适合需要独立发布的应用，或对启动性能要求较高的情况。
- **动态库**适合多个应用共享库资源的情况，或需要灵活更新的情况。



### **Placement `new` 的使用**

这段代码展示了 **C++ 中的 Placement `new` 运算符** 的功能，允许程序员在特定的内存位置上构造对象，而不是动态分配新的堆内存。这种方法对于内存管理非常灵活，但需要非常谨慎，因为它可能引发覆盖数据的问题。

------

### ****

#### **1. 普通 `new` 和 Placement `new` 的区别**

- **普通 `new`：**
  - 从堆中分配内存并调用构造函数初始化。
  - 例如：`pd1 = new double[N];` 从堆分配内存存储 `double` 数组。
- **Placement `new`：**
  - 在程序员提供的特定内存位置构造对象。
  - 例如：`pd2 = new (buffer) double[N];` 将对象存储在数组 `buffer` 中。

------

#### **2. 第一部分：第一次调用**

```cpp
pd1 = new double[N]; // 从堆分配内存
pd2 = new (buffer) double[N]; // 使用 buffer 数组分配内存
```

- `pd1` 使用 **普通 `new`** 从堆中分配内存。
- `pd2` 使用 **Placement `new`**，将内存分配到静态数组 `buffer` 中。

##### **内存内容**

- `pd1` 的地址位于堆中（动态分配）。
- `pd2` 的地址位于 `buffer` 数组中（静态分配）。

##### **输出示例**

```yaml
Memory addresses:
 heap: 0x55e2dfd8f570 static: 0x7ffcb3a9e810

Memory contents, p1, p2:
1000 at 0x55e2dfd8f570; 1000 at 0x7ffcb3a9e810
1020 at 0x55e2dfd8f578; 1020 at 0x7ffcb3a9e818
...
```

------

#### **3. 第二部分：第二次调用**

```cpp
pd3 = new double[N];  // 普通 new，分配新的堆内存
pd4 = new (buffer) double[N];  // 在 buffer 上重新分配，覆盖原有数据
```

- `pd3` 再次从堆中分配新的内存地址。
- `pd4` 使用 `buffer`，但直接覆盖了之前 `pd2` 在 `buffer` 上的数据。

##### **内存覆盖示例**

- `pd4` 与 `pd2` 指向同一个内存位置（`buffer`），原来的数据被覆盖。

##### **输出示例**

```
yaml复制代码Memory contents, p3, p4:
1000 at 0x55e2dfd8f5a0; 1000 at 0x7ffcb3a9e810
1040 at 0x55e2dfd8f5a8; 1040 at 0x7ffcb3a9e818
...
```

**注意：**

- 使用同一个 `buffer` 时，新分配的数据会覆盖之前的数据，这种行为是 Placement `new` 的特性之一。

------

#### **4. 第三部分：第三次调用**

```
cpp复制代码delete [] pd1;  // 释放 pd1 的内存
pd1 = new double[N];  // 从堆重新分配内存
pd2 = new (buffer + N * sizeof(double)) double[N];  // 在 buffer 后续位置分配
```

- `pd1` 再次从堆分配内存。
- `pd2` 使用 `buffer` 数组的**下一个内存块**（`buffer + N * sizeof(double)`）存储数据，避免覆盖之前的数据。

##### **内存分布**

- `pd2` 不再与 `pd4` 使用同一个内存块，而是使用了 `buffer` 的下一个内存位置。

##### **输出示例**

```
yaml复制代码Memory contents, p1, p2:
1000 at 0x55e2dfd8f5c0; 1000 at 0x7ffcb3a9e838
1060 at 0x55e2dfd8f5c8; 1060 at 0x7ffcb3a9e840
...
```



#### **Placement `new` 的作用**

- Placement `new` 用于在用户指定的内存位置上构造对象，而不是从堆动态分配。
- 使用方式：`new (memory_address) Type(arguments);`

#### **内存管理注意事项**

1. 内存覆盖：
   - 如果在同一内存块上多次调用 Placement `new`，会覆盖之前的数据。
2. 手动释放内存：
   - 使用普通 `new` 时，内存需要通过 `delete` 释放。
   - Placement `new` 的内存由用户管理，不能使用 `delete`，只能调用显式析构函数（例如 `pd2->~double()`）。
3. 灵活性：
   - Placement `new` 适用于嵌入式系统或对内存分配有严格控制的场景。





## 类与对象

### **二元运算符重载问题与友元函数的解决方案**



在C++中，当重载二元运算符（如 `*` 或 `<<`）时，操作数分为左操作数和右操作数。如果左操作数不是类的对象（如基本数据类型 `double` 或 `int`），这会引发以下问题：

1. **左操作数不是类对象**：

   - C++的运算符重载通常通过成员函数实现，成员函数默认以 `this` 指针隐式传递调用对象（即左操作数）。

   - 例如：

     ```cpp
     
     Time Time::operator*(double multiplier) const;
     ```
     
     在 
     
     ```
     A * 2.75
     ```
     
      中，
     
     ```
     A
     ```
     
      是调用对象（左操作数），会通过 
     
     ```
     this
     ```
     
      指针传递给成员函数。
     
   - 如果左操作数是基本数据类型（如 `2.75`），显然无法用成员函数来处理，因为基本类型不能成为类的调用对象。
   
2. **非成员函数无法直接访问私有成员**：

   - 如果选择使用非成员函数来重载运算符，虽然可以处理左操作数不是类对象的情况，但非成员函数不能直接访问类的私有成员和受保护成员，导致操作受限。

   例如：

   ```
   cpp复制代码class Time {
   private:
       int hours;
       int minutes;
   public:
       Time(int h, int m) : hours(h), minutes(m) {}
       Time operator*(double multiplier) const; // 成员函数方式
   };
   
   Time operator*(double multiplier, const Time& t) {
       // 想访问 t.hours 和 t.minutes，但这是类的私有成员，无法直接访问
   }
   ```

**2. 解决方案：使用友元函数**

C++ 提供了 **友元函数（friend function）** 机制，可以完美解决这个问题。友元函数允许非成员函数直接访问类的私有成员，从而在运算符重载中灵活处理左操作数不是类对象的情况。

**3. 实现友元函数重载二元运算符**

以 `*` 运算符为例，当左操作数是基本类型时，可以通过友元函数实现：

**代码实现**：

```cpp
#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    // 构造函数
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    // 显示时间
    void display() const {
        cout << hours << " hours, " << minutes << " minutes" << endl;
    }

    // 声明友元函数
    friend Time operator*(double multiplier, const Time& t);
};

// 定义友元函数
Time operator*(double multiplier, const Time& t) {
    // 可以直接访问 Time 的私有成员
    int totalMinutes = static_cast<int>(multiplier * (t.hours * 60 + t.minutes));
    return Time(totalMinutes / 60, totalMinutes % 60); // 返回新的 Time 对象
}

int main() {
    Time t1(2, 30); // 2小时30分钟
    Time t2 = 1.5 * t1; // 使用友元函数重载
    t2.display(); // 输出：3 hours, 45 minutes
    return 0;
}
```

**详细解释**：

1. **友元声明**：

   - 在 

     ```
     Time
     ```

      类中，声明 

     ```
     operator*
     ```

      为友元函数：

     ```cpp
     
     friend Time operator*(double multiplier, const Time& t);
     ```
     
   - 这样 `operator*` 虽然是非成员函数，但可以直接访问 `Time` 的私有成员（如 `hours` 和 `minutes`）。
   
2. **友元函数定义**：

   - 在类外定义友元函数，使用左操作数（`double multiplier`）和右操作数（`const Time& t`）作为参数。
   - 因为是友元函数，可以直接访问 `t.hours` 和 `t.minutes`。

3. **友元函数的作用**：

   - 使得 `1.5 * t1` 这样的表达式能够正常工作，而不需要强制 `1.5` 转换为 `Time` 对象。



**4. 适用场景：重载 `<<` 运算符**

另一个常见的场景是重载 `<<` 运算符。`<<` 运算符的左操作数是 `std::ostream` 类型，而不是用户自定义类对象，因此也需要使用友元函数来实现。

##### 

```cpp
#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    // 声明友元函数
    friend ostream& operator<<(ostream& os, const Time& t);
};

// 定义友元函数
ostream& operator<<(ostream& os, const Time& t) {
    // 友元函数可以直接访问 Time 的私有成员
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os; // 返回 ostream 对象以支持链式调用
}

int main() {
    Time t1(2, 45); // 2小时45分钟
    cout << t1 << endl; // 使用友元函数重载
    return 0;
}
```

**实现特点**：

1. **左操作数是非类对象**：
   - `<<` 的左操作数是 `ostream` 对象，无法通过成员函数实现。
2. **友元函数定义**：
   - 将 `operator<<` 定义为友元函数，使其可以访问 `Time` 类的私有成员。
3. **链式调用支持**：
   - 返回 `ostream&`，使得 `cout << t1 << endl;` 这样的链式调用得以实现。

### 静态成员

1. **静态成员函数的内存分配**

- **静态成员函数**本身与对象无关，它是属于类的，而不是类的某个实例。静态成员函数的内存空间在程序加载时分配，并且在整个程序的生命周期内存在（直到程序结束）。因此，静态成员函数的内存管理由**程序加载器**（Loader）和**链接器**（Linker）来完成，而不是由类的对象管理。
- 静态成员函数在类中只有一个副本，不管你创建多少个对象，它都只有一个实例。这个副本存储在程序的**代码段**（code segment）中，这与普通的成员函数存储位置类似。静态成员函数在内存中的位置通常由编译器在编译时确定，并且在程序执行时直接加载。

2. **静态成员变量的内存分配**

静态成员函数访问的静态成员变量是另一回事。静态成员变量的内存分配和静态成员函数的内存分配有些不同，它们存储在程序的**数据段**（data segment）中，而不是代码段。

- **静态成员变量**属于整个类，并且与类的对象实例无关。它们在程序启动时分配内存，并且在程序结束时销毁。
- 静态成员变量的生命周期从程序开始运行到程序结束，确保类的所有实例都能共享这些变量。

3. **静态函数调用时的内存管理**

当调用静态成员函数时，C++ 编译器会确保静态成员函数的代码能够被执行，不需要创建类的对象。静态成员函数的调用方式有两种：

- **通过类名调用**： 静态成员函数是与类本身相关联的，可以通过类名直接调用。因为它不依赖于实例，所以不需要对象来调用。

  ```cpp
  
  MyClass::staticFunction();
  ```

- **通过对象调用**： 尽管静态成员函数也可以通过对象调用，但通常不推荐这么做，因为它是属于类的，不属于对象的。通过对象调用静态成员函数不会产生额外的内存分配。

  ```cpp
  MyClass obj;
  obj.staticFunction();  // 不推荐
  ```

4. **静态函数访问静态成员变量**

静态成员函数可以访问类的静态成员变量，因为它们都是与类相关的，不依赖于特定的对象。静态成员函数通过类名访问静态成员变量：

```cpp
class MyClass {
public:
    static int staticVar;

    static void staticFunction() {
        // 可以访问静态成员变量
        std::cout << "StaticVar = " << staticVar << std::endl;
    }
};

// 静态成员变量初始化
int MyClass::staticVar = 10;

int main() {
    // 静态成员函数通过类名调用
    MyClass::staticFunction();
    return 0;
}
```

. **静态成员函数的内存管理总结**

- 静态成员函数的内存存储在程序的**代码段**，在程序加载时分配，并在程序执行期间一直存在。
- 静态成员函数没有 `this` 指针，因此它不能访问实例成员，只能访问静态成员。
- 静态成员函数没有对象的生命周期，它属于类本身而不是某个对象。
- 静态成员函数的调用不需要实例化对象，而是通过类名直接调用。

静态成员函数和静态成员变量都遵循"类级"的生命周期和内存管理规则，独立于对象的创建和销毁，它们在整个程序的生命周期内保持有效。

##  **拷贝构造函数**（Copy Constructor）

在 C++ 中，**拷贝构造函数**（Copy Constructor）是一个特殊的构造函数，用于创建一个新对象，该对象是通过**复制另一个对象**来初始化的。拷贝构造函数在以下情况时被调用：

1. **用一个已存在的对象初始化一个新对象**。
2. **将一个对象传递给函数（按值传递）**。
3. **从函数返回一个对象**。

拷贝构造函数的基本形式

拷贝构造函数的标准形式如下：

```cpp

ClassName(const ClassName& other);
```

- `ClassName`：是类的名字。
- `other`：是另一个对象的引用，它的类型是`ClassName`，它是我们要复制的对象。

示例：拷贝构造函数

```cpp
class MyClass {
private:
    int value;
public:
    // 普通构造函数
    MyClass(int v) : value(v) {}

    // 拷贝构造函数
    MyClass(const MyClass& other) {
        value = other.value;
        std::cout << "拷贝构造函数被调用！" << std::endl;
    }

    // 显示对象的值
    void showValue() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    MyClass obj1(10);   // 调用普通构造函数
    MyClass obj2 = obj1; // 调用拷贝构造函数
    obj2.showValue();    // 输出 obj2 的值

    return 0;
}
```

### 

- `obj1` 使用普通构造函数创建，并赋值为 10。
- `obj2` 是通过 `obj1` 来初始化的，调用了拷贝构造函数。`obj2` 会复制 `obj1` 的数据成员，结果是 `obj2` 和 `obj1` 都持有相同的 `value` 值。
- 当 `obj2` 被创建时，会输出 `拷贝构造函数被调用！`，这表明拷贝构造函数确实被调用了。

拷贝构造函数的调用时机

1. **对象初始化**：当一个对象用另一个对象进行初始化时，拷贝构造函数会被调用。例如：

   ```cpp
   
   MyClass obj2 = obj1;  // 调用拷贝构造函数
   ```

2. **函数参数传递**：当一个对象以值传递方式传递给函数时，拷贝构造函数会被调用。例如：

   ```
   cpp复制代码void func(MyClass obj) {  // 参数是按值传递
       // ...
   }
   func(obj1);  // 调用拷贝构造函数
   ```

3. **函数返回**：当一个函数返回一个对象时，拷贝构造函数也会被调用。例如：

   ```
   cpp复制代码MyClass createObject() {
       MyClass obj(20);
       return obj;  // 调用拷贝构造函数
   }
   MyClass obj2 = createObject();  // 调用拷贝构造函数
   ```



在某些情况下，类中可能包含动态分配的内存（如使用 `new` 操作符），此时需要**自定义拷贝构造函数**，以便正确地进行深拷贝。

深拷贝 vs 浅拷贝

- **浅拷贝**：直接将指针复制到新对象中，不会分配新的内存，两个对象共享相同的资源。
- **深拷贝**：为每个对象分配独立的内存，确保两个对象的资源不会发生冲突。

示例：深拷贝

```
cpp复制代码#include <iostream>

class MyClass {
private:
    int* data;
public:
    // 构造函数
    MyClass(int value) {
        data = new int(value);
    }

    // 拷贝构造函数（深拷贝）
    MyClass(const MyClass& other) {
        data = new int(*other.data);  // 为新对象分配新的内存
        std::cout << "深拷贝构造函数被调用！" << std::endl;
    }

    // 析构函数
    ~MyClass() {
        delete data;
    }

    // 显示数据
    void showData() const {
        std::cout << "Data: " << *data << std::endl;
    }
};

int main() {
    MyClass obj1(10);    // 创建对象 obj1
    MyClass obj2 = obj1; // 调用拷贝构造函数（深拷贝）

    obj1.showData();     // 输出 obj1 的数据
    obj2.showData();     // 输出 obj2 的数据

    return 0;
}
```



1. `obj1` 是通过构造函数创建的，它动态分配了一个 `int` 类型的内存来存储数据。
2. 当创建 `obj2` 时，拷贝构造函数被调用，分配了新的内存，并将 `obj1` 的数据复制到 `obj2` 中。这就实现了深拷贝。
3. 因为每个对象都有自己独立的内存，所以当析构函数被调用时，每个对象会正确地释放其自己的内存。

### **赋值运算符（Assignment Operator）**

赋值运算符用于在**两个已存在对象之间进行赋值**，即一个对象的值赋给另一个已经存在的对象。赋值运算符在两个对象已创建并存在时才会调用。

赋值运算符的定义通常如下：

```
cpp


复制代码
ClassName& operator=(const ClassName& other);
```

**作用**：赋值运算符将一个对象的内容复制到另一个已经存在的对象中。它的返回值是一个对当前对象的引用，以便支持链式赋值（如 `a = b = c;`）。

赋值运算符的调用时机

- 当两个已存在的对象进行赋值时。例如，`obj1 = obj2;`。

示例：赋值运算符

```cpp
class MyClass {
public:
    int value;

    MyClass(int v) : value(v) {}  // 构造函数

    // 赋值运算符
    MyClass& operator=(const MyClass& other) {
        if (this == &other) {  // 防止自我赋值
            return *this;
        }
        value = other.value;
        std::cout << "赋值运算符被调用" << std::endl;
        return *this;
    }
};

int main() {
    MyClass obj1(10);      // 调用构造函数
    MyClass obj2(20);      // 调用构造函数
    obj1 = obj2;           // 调用赋值运算符
    return 0;
}
```

3. **拷贝构造函数与赋值运算符的区别**

| 特性                         | 拷贝构造函数 (Copy Constructor)                              | 赋值运算符 (Assignment Operator)                             |
| ---------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **调用时机**                 | - 创建新对象时（用已存在对象初始化新对象）。                 | - 两个已存在对象间赋值时。                                   |
| **对象状态**                 | - 用已有对象的内容初始化一个新对象。                         | - 已存在的对象被赋值为另一个已存在对象的内容。               |
| **返回值**                   | - 没有返回值，通常是构造新对象。                             | - 返回当前对象的引用，支持链式赋值。                         |
| **是否需要处理自我赋值检查** | - 不需要，因为它是在新对象创建时调用的。                     | - 需要处理自我赋值，即检测两个对象是否是同一个对象。         |
| **常见操作**                 | - 复制构造一个新对象。                                       | - 赋值现有对象的成员变量，处理资源的释放与管理。             |
| **默认实现**                 | - 如果没有显式定义，编译器会提供一个默认的拷贝构造函数，进行浅拷贝。 | - 如果没有显式定义，编译器会提供一个默认的赋值运算符，进行浅拷贝。 |

## **派生类（Derived Class）与**基类（Base Class）

### **派生类构造函数与基类构造函数的关系**

**1. 基类的成员访问限制：**

- **私有成员（Private Members）**：派生类不能直接访问基类的私有成员。派生类必须通过基类的公有或受保护方法来访问基类的私有成员。

  例如，如果基类有一个私有成员 `int x`，那么派生类不能直接访问它，除非基类提供了访问这个成员的公共方法。

**2. 派生类构造函数如何调用基类构造函数：**

- 当构造一个派生类对象时，首先会构造基类部分。派生类的构造函数通过初始化列表来调用基类的构造函数。
- 基类构造函数必须在派生类构造函数的初始化列表中显式调用，否则编译器会使用基类的默认构造函数（如果有的话）。

**3. 基类和派生类对象的构造顺序：**

- **基类对象总是首先被构造**，然后才是派生类对象的构造。这意味着派生类构造函数中的代码是在基类构造函数完成后才执行的。
- 这也是为什么派生类构造函数需要通过初始化列表来将必要的信息传递给基类构造函数的原因。派生类必须在基类构造函数执行之前，知道如何初始化基类部分。

**4. 使用成员初始化列表传递参数：**

- 如果派生类需要向基类构造函数传递参数，可以在派生类的构造函数的成员初始化列表中进行传递。
- 派生类的构造函数首先执行基类的构造，之后才会执行派生类的数据成员初始化。

### **总结：**

1. **派生类对象访问基类方法：** 派生类对象可以使用基类的公共（public）和保护（protected）方法，但不能直接访问基类的私有（private）方法。
2. **基类指针和引用指向派生类对象：** 基类指针或引用可以指向派生类对象，无需显式类型转换。
3. **基类指针或引用只能调用基类的方法：** 基类指针或引用只能调用基类的方法，不能直接调用派生类特有的方法，除非通过显式转换为派生类类型。

### **Pointer and Reference Type Compatibility (指针和引用类型兼容性)**

在 C++ 中，指针和引用是类型安全的，编译器会对类型进行严格检查。指针和引用类型的兼容性规则是为了确保类型的正确性和防止潜在的错误。在继承关系中，指针和引用的类型兼容性规则有一些特殊的放宽，但这些规则也需要注意。

**一般规则**

1. **不允许将一个类型的地址赋给另一个类型的指针：**
   - C++ 会严格检查类型之间的兼容性，不能随意将某种类型的地址赋值给另一个不兼容的指针类型。
   - 例如，不能将 `int*` 的地址赋给 `double*` 指针，编译器会报错。
2. **不允许将一个类型的引用绑定到另一个类型的对象：**
   - 这也是为了防止类型不兼容的操作，编译器不会允许你将类型不同的引用进行绑定。
   - 例如，不能将 `int&` 引用绑定到 `double` 类型的对象。

**继承关系中的指针和引用**

继承是 C++ 中的一个核心概念，它允许派生类继承基类的成员，并且可以通过基类指针或引用来操作派生类对象。在这种情况下，指针和引用的兼容性规则有一些特殊放宽，具体来说有两个操作：**向上转型（Upcasting）** 和 **向下转型（Downcasting）**。

**1. 向上转型（Upcasting）**

向上转型指的是将一个派生类的指针或引用转换为基类的指针或引用。

- **向上转型是合法的**，这是因为派生类对象 **“是”** 基类对象的一种（满足 "is-a" 关系）。
- 向上转型通常是 **隐式转换**，编译器会自动处理这种类型转换。

##### **向上转型的特点：**

- **“is-a” 关系**：派生类对象是基类对象的一种特殊类型。
- **隐式转换**：编译器允许基类指针或引用指向派生类对象，这种转换是自动发生的，无需显式转换。
- **父类接口可访问**：当你使用基类指针或引用时，虽然实际操作的是派生类对象，但你只能访问基类中定义的接口（方法和属性），即使在派生类中有重载或扩展。

##### **例子：**

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base class show()" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class show()" << endl;
    }
};

int main() {
    Derived d;  // 创建派生类对象
    Base* b = &d;  // 向上转型，基类指针指向派生类对象

    b->show();  // 调用派生类的 show() 方法，发生动态绑定
    return 0;
}
```

在这个例子中，`Base* b = &d;` 进行了向上转型（将派生类 `Derived` 对象的地址赋给基类指针 `Base*`）。通过基类指针 `b` 调用 `show()` 时，实际调用的是派生类 `Derived` 中重写的 `show()` 方法。这是因为 `show()` 是虚函数，支持运行时的动态绑定。

**1. 调用基类的方法**

如果你使用基类指针（`Base*`）指向派生类对象，那么你可以调用基类中的方法，只要这些方法在基类中已经定义并且可以访问（即它们的访问权限不是私有的）。

**2. 调用派生类的函数**

如果你希望通过基类指针调用派生类中独有的方法，**通常是不能直接做到的**。因为基类指针只能访问基类的成员（函数和数据成员），不能直接访问派生类的成员。基类指针不知道派生类中新增的成员。

但是，如果基类的方法是 **虚函数**，并且派生类重写了这些虚函数，那么在运行时会发生 **动态绑定**，基类指针仍然可以调用派生类的重写方法。这就是 C++ 的 **多态性**。

在 C++ 中，有两种函数绑定方式：**静态绑定（早期绑定）** 和 **动态绑定（晚期绑定）**。这两种绑定方式的存在是为了在 **性能** 和 **灵活性** 之间取得平衡。理解这两者的差异，能够帮助我们理解为什么静态绑定是默认的，以及虚函数是如何工作的。

#### **1. 效率：静态绑定更高效**

- **静态绑定**：静态绑定发生在编译时，编译器可以准确地知道哪个函数会被调用，因此可以在编译时确定函数的地址。这消除了运行时查找函数地址的开销，执行时不需要做额外的工作，因此执行效率更高。
- **动态绑定**：动态绑定发生在运行时，编译器无法在编译时确定具体调用哪个函数，必须使用 **虚表（vtable）** 和 **虚表指针** 来查找函数的地址。因此，动态绑定的过程中需要额外的查找开销，这比静态绑定要慢一些。

**为什么静态绑定是默认的？**

- 由于静态绑定的效率更高，当函数不需要重写（即不需要多态时），静态绑定是最优选择。因此，C++ 默认使用静态绑定，以避免在不必要的情况下引入运行时开销。
- 静态绑定还简化了代码生成，减少了内存使用，因为对于非虚方法来说，不需要为每个类创建虚表。

#### **2. 概念模型：默认非虚函数**

从概念上讲：

- **基类的方法如果不是虚拟的**，表示这些方法不打算在派生类中重写。因此，大多数方法在基类中默认都不需要虚拟（virtual）标识，C++ 也默认使用静态绑定。
- **虚函数（virtual functions）** 是显式标记的，意味着这些函数的行为在派生类中可能会被重写。通过将 `virtual` 关键字保留给那些预期会被重写的方法，C++ 明确了哪些函数需要多态（即运行时的动态绑定），哪些不需要。

因此，**虚函数** 是为了支持多态而设计的，通过动态绑定使得基类指针/引用可以指向派生类对象并调用派生类中的重写函数。默认情况下，C++ 假设基类方法不需要多态，因此静态绑定成为默认行为。

### 虚函数如何工作

虚函数是实现 **多态** 和 **动态绑定** 的关键。为了支持虚函数，编译器实现了一些额外的机制，使得对象能够在运行时决定调用哪个版本的函数。

#### **虚函数的实现机制：**

1. **编译器的工作**：
   - 编译器通常会在类的每个对象中增加一个 **指向虚表（vtable）** 的指针。虚表是一个包含类的所有虚函数地址的数组。
   - 对象中每个虚函数都有一个对应的地址项，指向具体的函数实现。
2. **虚表（vtable）**：
   - 每个类（包括基类和派生类）都有一个 **虚函数表（vtable）**，用于存储该类中所有虚函数的地址。
   - 如果派生类重写了基类的虚函数，那么派生类的虚表中的对应函数地址就指向派生类的实现，而不是基类的实现。
3. **虚表指针（vptr）**：
   - 每个对象（无论是基类对象还是派生类对象）都包含一个隐式的 **虚表指针（vptr）**，指向该对象所属类的虚表。
   - 这个虚表指针会在对象创建时由编译器自动设置，以便在运行时通过虚表来查找正确的虚函数实现。



- 当你通过基类指针或引用调用虚函数时，编译器并不知道该函数在运行时应该调用哪个版本（基类还是派生类），因为编译时无法知道对象的实际类型。此时，C++ 使用 **虚表指针** 来查找并调用合适的函数版本。



```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {  // 基类中的虚函数
        cout << "Base class show()" << endl;
    }

    virtual ~Base() {}  // 虚析构函数，防止内存泄漏
};

class Derived : public Base {
public:
    void show() override {  // 派生类重写基类的虚函数
        cout << "Derived class show()" << endl;
    }
};

int main() {
    Base* b = new Derived();  // 基类指针指向派生类对象

    b->show();  // 运行时根据对象的实际类型（Derived），调用派生类的 show()

    delete b;  // 释放内存
    return 0;
}
```

**工作原理**：

- 这里 `Base* b = new Derived();` 创建了一个 `Derived` 类型的对象，并用 `Base` 类型的指针 `b` 指向它。
- 虽然 `b` 是 `Base*` 类型，但由于 `show()` 是虚函数，编译器会在运行时根据 `b` 指向的实际对象类型（`Derived`）来决定调用 `Derived` 类中的 `show()` 方法。这是通过 **虚表（vtable）** 和 **虚表指针（vptr）** 实现的。

### **私有继承（Private Inheritance）**

- **公有和保护成员变为私有成员**：在私有继承中，基类的公有（`public`）和保护（`protected`）成员都会变成派生类的私有（`private`）成员。
- **基类的方法不会成为派生类的公共接口**：也就是说，基类的公有方法在派生类中不再直接公开，可以仅在派生类的内部方法中使用。
- **派生类不继承基类的接口**：与公有继承不同，私有继承不会将基类的公共接口暴露给派生类的外部用户，而是将其作为实现的一部分。

- **公有继承**：派生类继承了基类的公有成员和方法，并且这些成员和方法成为派生类的公共接口。这使得派生类能够通过基类的接口来访问和操作基类的功能。
- **私有继承**：派生类不暴露基类的公共接口，基类的公有成员和方法变成私有成员，只能在派生类内部使用，不会直接对外部暴露。

与包含（Containment）的关系

- **获取实现**：无论是私有继承还是包含，它们都能够获取基类（或包含的类）的实现。也就是说，派生类或包含类可以使用基类中的成员和方法。
- **不获取接口**：私有继承和包含的共同点是，二者都不继承基类的公共接口（即不将基类的公共成员直接暴露给外部）。



- 与包含的区别：

  - 在包含中，我们通过显式命名对象作为成员来实现组合。而在私有继承中，基类的成员是作为“无名子对象”嵌入到派生类中的。

- 初始化基类组件：

  - 当我们使用私有继承时，需要通过类名来指定构造函数，而不是像包含那样使用成员名。例如：

    ```cpp
    class Base {
    public:
        Base(int x) { /* constructor code */ }
    };
    
    class Derived : private Base {
    public:
        Derived(int x) : Base(x) { /* constructor code */ }
    };
    ```

    在这个例子中，派生类

    ```
    Derived
    ```

    会显式调用基类

    ```
    Base
    ```

    的构造函数，并通过派生类的构造函数来初始化基类的成员。

  

  ### 包含（contaiment）

  包含是指一个类将另一个类的对象作为它的成员变量。换句话说，**包含是组合（Composition）的一种实现方式**，它表示类之间的“拥有”关系。例如，假设我们有一个**汽车（Car）**类，它可能包含一个**引擎（Engine）**类，而不是继承它。这样，汽车对象就可以使用引擎的功能，但它不是引擎的一种特殊类型。



### 内联函数（inline)

内联函数是指在函数调用发生时，编译器会直接将函数的代码插入到调用该函数的地方，而不是像普通函数那样通过函数调用的机制跳转到函数体执行。这种方式能够减少函数调用时的堆栈操作和跳转开销。

使用 `inline` 关键字来定义内联函数。例如：

```
cpp复制代码inline int add(int a, int b) {
    return a + b;
}
```

在这个例子中，`add` 是一个内联函数，编译器会尝试在调用 `add` 函数的地方直接插入其函数体（`return a + b;`）。

3. **内联函数的工作原理**

当你调用一个内联函数时，编译器在编译阶段将函数的代码直接嵌入到调用点处，这样就避免了常规函数调用中的栈帧创建、参数传递等操作。因此，内联函数理论上可以提高程序的运行效率，尤其是对于短小且频繁调用的函数。

- **性能提升**：内联函数减少了函数调用的开销。尤其是对于小型函数（如简单的 getter 和 setter 函数），内联可以减少函数调用的时间。
- **减少栈开销**：常规的函数调用会产生栈操作（如保存返回地址、传递参数等），内联函数可以消除这些栈操作。
- **编译器优化**：内联函数给编译器提供了更多优化的空间。编译器可以在内联函数中做进一步的优化，比如常量传播、死代码消除等。

- **编译器的选择**：尽管你使用了 `inline` 关键字，编译器不一定会按照你的要求将函数内联。现代编译器会根据函数的复杂度、大小和调用频率等因素决定是否内联函数。在某些情况下，编译器可能会忽略 `inline` 关键字。
- **代码膨胀**：内联函数虽然提高了效率，但也可能导致**代码膨胀**（code bloat）。特别是当内联函数比较大或被频繁调用时，会导致生成大量的重复代码，增加程序的体积。
- **适用场合**：内联函数适用于小型、简单的函数，特别是那些频繁调用的函数。对于复杂的函数，内联可能并不会带来性能提升，反而可能增加编译时间和程序体积。
- **递归函数**：递归函数通常不应该定义为内联函数，因为递归的调用会导致编译器无法确定内联展开的深度，进而导致无法有效地进行内联优化。



### Runtime Type Identification (RTTI) 介绍

**RTTI (Runtime Type Identification)** 是 C++ 中的一项技术，它允许在程序运行时检查对象的类型信息。RTTI 通过一些特定的操作符提供了一种标准化的方法来在运行时确定对象的类型。这一机制是 C++ 中相对较新的特性，旨在增强程序的灵活性，尤其是对继承层次结构中的多态性支持。

1. **RTTI 的背景**

- 在 C++ 中，我们通常使用指向基类的指针或引用来访问派生类对象。然而，如何在运行时确定这个指针或引用实际上指向的是哪个派生类的对象？RTTI 就是为了解决这一问题而引入的。
- RTTI 使得程序能够动态地判断对象的实际类型，并根据该类型做出适当的反应。
- 在 C++ 中，并不是所有的编译器都支持 RTTI，因此某些较老的编译器可能无法处理 RTTI。

2. **RTTI 的目的**

- **提供运行时类型检查的标准方法**：在程序运行时，能够安全地确定一个对象的实际类型。
- **增强库的兼容性**：允许不同的库可以通过 RTTI 机制在运行时交换和兼容类型信息。

C++ 提供了两个主要的 RTTI 操作符：

1. **`dynamic_cast`**：这是用于在继承体系内进行类型转换的操作符。它允许将指向派生类的指针或引用转换为指向基类的指针或引用，并且能在转换失败时返回空指针或抛出异常。
2. **`typeid`**：该操作符用于获取对象的类型信息，并返回一个 `type_info` 对象，这个对象提供了对象的类型标识。

4. **`dynamic_cast` 操作符**

`dynamic_cast` 用于在类层次结构中安全地执行向上或向下转换。它主要用于**多态类型**的转换。

- **向下转换（downcasting）**：将基类指针转换为派生类指针。
- **向上转换（upcasting）**：将派生类指针转换为基类指针。

使用 `dynamic_cast` 可以确保类型转换的安全性：

```
cpp复制代码class Base { virtual void foo() {} };
class Derived : public Base { void foo() {} };

Base* b = new Derived();
Derived* d = dynamic_cast<Derived*>(b);  // 如果b是Derived类型，转换成功；否则返回nullptr
```

如果类型转换成功，`dynamic_cast` 返回相应的指针类型。如果失败，则返回 `nullptr`（对于指针）或抛出 `std::bad_cast` 异常（对于引用）。

5. **`typeid` 操作符**

`typeid` 操作符返回一个 `type_info` 对象，该对象包含有关类型的信息。你可以使用 `typeid` 来检查两个对象是否具有相同的类型。

```
cpp复制代码#include <typeinfo>
#include <iostream>

class Base { virtual void foo() {} };
class Derived : public Base { void foo() {} };

int main() {
    Base* b = new Derived();
    std::cout << typeid(*b).name() << std::endl;  // 输出Derived类的名称
}
```

`typeid` 可以用于：

- 确定两个对象是否是同一类型。
- 比较不同对象的类型。

6. **`type_info` 类**

`type_info` 是存储类型信息的类，定义在 `typeinfo` 头文件中。它提供了一些有用的成员函数：

- `name()`：返回类型的名字（通常是类型的字符串表示）。
- `==` 和 `!=`：允许通过 `type_info` 对象比较类型是否相同。

7. **C++ 的四种类型转换操作符**

C++ 提供了四种类型转换操作符，它们分别用于不同的场景：

1. `dynamic_cast`

   ：用于类层次结构中的安全转换，适用于具有多态的类（即有虚函数的类）。可以用于向下转换、向上转换。

   - 适用于 `is-a` 关系。
   - 不允许其他类型转换。

2. `const_cast`

   ：用于修改类型的 

   ```
   const
   ```

    或 

   ```
   volatile
   ```

    属性，但不能更改其他类型部分。通常用于移除 

   ```
   const
   ```

    或 

   ```
   volatile
   ```

    属性。

   ```
   cpp复制代码const int x = 10;
   int* ptr = const_cast<int*>(&x);  // 移除const属性
   ```

3. **`static_cast`**：用于静态转换，可以在已知类型之间进行转换，通常用于数字类型、枚举类型和指针类型之间的转换。

4. **`reinterpret_cast`**：用于强制转换一种类型的指针或引用为另一种完全不同的类型，这种转换可能会破坏程序的类型安全性，因此需要小心使用。



假设你有一个 `const` 类型的对象，但是你希望在某些情况下改变它的值（尽管这通常不推荐）：

```
cpp复制代码#include <iostream>

void modify(const int& x) {
    int& y = const_cast<int&>(x);  // 使用const_cast移除const属性
    y = 10;
    std::cout << "Modified value: " << y << std::endl;
}

int main() {
    const int a = 5;
    modify(a);  // 输出 "Modified value: 10"
    return 0;
}
```



- **RTTI** 是 C++ 提供的一种机制，可以在运行时获取对象的类型信息，并进行安全的类型转换。
- **`dynamic_cast`** 用于安全地进行指针或引用的转换，避免错误的转换。
- **`typeid`** 用于获取对象类型信息，并进行类型比较。
- **`const_cast`** 用于去除对象的 `const` 或 `volatile` 属性，但不能改变其他部分的类型。
