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

   ```
   
   extern int sharedVar; // 可以在其他文件中共享的变量
   ```
   
2. **内部链接（Internal Linkage）**：具有内部链接的名称只能在单个文件中共享，不能跨文件访问。通常使用 `static` 关键字声明具有内部链接的全局变量或函数。

   ```
   
   static int fileVar = 5; // 仅在当前文件中可见
   ```
   
3. **无链接（No Linkage）**：自动变量（函数内的局部变量）和块中的静态变量没有链接，意味着它们只能在其定义的块内访问，不能在文件的其他位置共享。

   ```
   cpp复制代码void func() {
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

#### 特点

- **链接时机**：在编译期间，库的代码会被链接到目标程序中。
- **独立性**：生成的可执行文件不依赖外部的静态库文件，所有需要的代码都已嵌入。
- **文件大小**：可执行文件会比较大，因为包含了库的代码。
- **更新**：如果静态库的代码发生变化，需要重新编译可执行文件。
- **性能**：加载时不需要额外的动态链接，启动速度更快。

#### 使用示例

假设有一个静态库 `libmylib.a`，在编译时可以通过如下方式链接：

```shell

g++ main.cpp -L/path/to/lib -lmylib -o myprogram
```

这里 `-L` 指定库路径，`-l` 指定库名称（不需要加`lib`前缀和`.a`后缀）。

### 2. 动态库（Dynamic Library）

动态库也称为共享库，在Windows上为 `.dll`，在Linux上为 `.so`。动态库在**运行时**加载，它们可以独立于程序文件而存在。

#### 特点

- **链接时机**：在运行时由系统动态加载库文件。
- **共享性**：多个程序可以共享同一个动态库，从而减少内存占用。
- **文件大小**：可执行文件较小，因为动态库的代码不嵌入其中。
- **更新**：更新库文件后，不需要重新编译主程序，只需在运行时加载新的库即可。
- **性能**：因为需要动态加载，首次加载库时启动速度会稍慢。

#### 使用示例

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
