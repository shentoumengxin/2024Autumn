#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_FILES = 100;
const int MAX_BLOCKS = 500;
const int MAX_FILENAME = 11;

// 文件结构
struct File {
    char name[MAX_FILENAME];
    int head;
    int tail;
    int count;

    File() : head(-1), tail(-1), count(0) {
        name[0] = '\0';
    }
};

// 全局变量
int totalBlocks = 0;
int freeBlocks = 0;
unsigned char* bitmap = nullptr;
int* blockLinks = nullptr;
File* fileList = nullptr;
int fileCount = 0;

// 初始化文件系统
void initFileSys(int n) {
    totalBlocks = n;
    freeBlocks = n;

    // 分配并初始化位图
    if(bitmap) delete[] bitmap;
    bitmap = new unsigned char[totalBlocks];
    for(int i = 0; i < totalBlocks; ++i)
        bitmap[i] = 0;

    // 分配并初始化块链接数组
    if(blockLinks) delete[] blockLinks;
    blockLinks = new int[totalBlocks];
    for(int i = 0; i < totalBlocks; ++i)
        blockLinks[i] = -1;

    // 分配文件列表
    if(fileList) delete[] fileList;
    fileList = new File[MAX_FILES];
    fileCount = 0;
}

// 查找文件
int findFile(const char* filename) {
    for(int i = 0; i < fileCount; ++i)
        if(strcmp(fileList[i].name, filename) == 0)
            return i;
    return -1;
}

// 分配空闲块
bool allocateBlocks(int* blocks, int num) {
    int allocated = 0;
    for(int i = 0; i < totalBlocks && allocated < num; ++i) {
        if(bitmap[i] == 0) {
            blocks[allocated++] = i;
            bitmap[i] = 1;
            freeBlocks--;
        }
    }
    return allocated == num;
}

// 创建文件
void createFile(const char* filename, int num) {
    if(findFile(filename) != -1) {
        cout << filename << " EXISTED\n";
        return;
    }
    if(num > freeBlocks) {
        cout << filename << " INSUFFICIENT BLOCKS\n";
        return;
    }
    if(fileCount >= MAX_FILES) return;

    int* allocated = new int[num];
    if(!allocateBlocks(allocated, num)) {
        cout << filename << " INSUFFICIENT BLOCKS\n";
        delete[] allocated;
        return;
    }

    strcpy(fileList[fileCount].name, filename);
    fileList[fileCount].head = (num > 0) ? allocated[0] : -1;
    fileList[fileCount].tail = (num > 0) ? allocated[num-1] : -1;
    fileList[fileCount].count = num;

    for(int i = 0; i < num-1; ++i)
        blockLinks[allocated[i]] = allocated[i+1];
    if(num > 0)
        blockLinks[allocated[num-1]] = -1;

    fileCount++;
    delete[] allocated;
}

// 删除文件
void deleteFile(const char* filename) {
    int idx = findFile(filename);
    if(idx == -1) {
        cout << filename << " NOT FOUND\n";
        return;
    }

    int current = fileList[idx].head;
    while(current != -1) {
        bitmap[current] = 0;
        freeBlocks++;
        int next = blockLinks[current];
        blockLinks[current] = -1;
        current = next;
    }

    for(int i = idx; i < fileCount-1; ++i)
        fileList[i] = fileList[i+1];
    fileCount--;
}

// 追加块
void appendBlocks(const char* filename, int num) {
    int idx = findFile(filename);
    if(idx == -1) {
        cout << filename << " NOT FOUND\n";
        return;
    }
    if(num > freeBlocks) {
        cout << filename << " INSUFFICIENT BLOCKS\n";
        return;
    }
    if(num == 0) return;

    int* allocated = new int[num];
    if(!allocateBlocks(allocated, num)) {
        cout << filename << " INSUFFICIENT BLOCKS\n";
        delete[] allocated;
        return;
    }

    if(fileList[idx].head == -1) {
        fileList[idx].head = allocated[0];
    } else {
        blockLinks[fileList[idx].tail] = allocated[0];
    }
    fileList[idx].tail = allocated[num-1];
    fileList[idx].count += num;

    for(int i = 0; i < num-1; ++i)
        blockLinks[allocated[i]] = allocated[i+1];
    blockLinks[allocated[num-1]] = -1;

    delete[] allocated;
}

// 碎片整理
void defragment() {
    int newBlock = 0;
    unsigned char* newBitmap = new unsigned char[totalBlocks];
    for(int i = 0; i < totalBlocks; ++i)
        newBitmap[i] = 0;

    int* newLinks = new int[totalBlocks];
    for(int i = 0; i < totalBlocks; ++i)
        newLinks[i] = -1;

    File* newFiles = new File[MAX_FILES];
    int newCount = 0;

    for(int i = 0; i < fileCount; ++i) {
        strcpy(newFiles[newCount].name, fileList[i].name);
        newFiles[newCount].count = fileList[i].count;

        if(fileList[i].count == 0) {
            newFiles[newCount].head = -1;
            newFiles[newCount].tail = -1;
            newCount++;
            continue;
        }

        newFiles[newCount].head = newBlock;
        newFiles[newCount].tail = newBlock + fileList[i].count -1;

        for(int j = 0; j < fileList[i].count; ++j) {
            newBitmap[newBlock + j] = 1;
            if(j < fileList[i].count -1)
                newLinks[newBlock + j] = newBlock + j +1;
            else
                newLinks[newBlock + j] = -1;
        }
        newCount++;
        newBlock += fileList[i].count;
    }

    // 更新全局位图和块链接
    delete[] bitmap;
    bitmap = newBitmap;

    delete[] blockLinks;
    blockLinks = newLinks;

    // 更新文件列表
    delete[] fileList;
    fileList = newFiles;
    fileCount = newCount;

    // 更新空闲块
    freeBlocks = totalBlocks - newBlock;
}

// 显示状态
void displayStatus() {
    if(fileCount == 0) {
        cout << "EMPTY\n";
        return;
    }
    for(int i = 0; i < fileCount; ++i) {
        cout << fileList[i].name << " [";
        if(fileList[i].head == -1)
            cout << "-1";
        else {
            int current = fileList[i].head;
            while(current != -1) {
                cout << current << " ";
                current = blockLinks[current];
            }
            cout << "-1";
        }
        cout << "]\n";
    }
}

// 主函数
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string cmd;
    while(cin >> cmd){
        if(cmd == "INIT"){
            int n;
            cin >> n;
            initFileSys(n);
        }
        else if(cmd == "CREATE"){
            char fname[MAX_FILENAME];
            int num;
            cin >> fname >> num;
            createFile(fname, num);
        }
        else if(cmd == "DELETE"){
            char fname[MAX_FILENAME];
            cin >> fname;
            deleteFile(fname);
        }
        else if(cmd == "APPEND"){
            char fname[MAX_FILENAME];
            int num;
            cin >> fname >> num;
            appendBlocks(fname, num);
        }
        else if(cmd == "DEFRAG"){
            defragment();
        }
        else if(cmd == "STATUS"){
            displayStatus();
        }
        else if(cmd == "QUIT"){
            break;
        }
    }

    // 释放动态分配的内存
    if(bitmap) delete[] bitmap;
    if(blockLinks) delete[] blockLinks;
    if(fileList) delete[] fileList;

    return 0;
}
