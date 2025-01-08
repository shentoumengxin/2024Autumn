#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <regex>

using namespace std;

// 前向声明
class Folder;
class File;

// File 类
class File{
public:
    string name;         // 文件名
    string content;      // 内容
    Folder* parentFolder = nullptr;        // 父文件夹

    File(string x){
        name = x;
        content = "";
    }
};

// Folder 类
class Folder{
public:
    string name;                  // 文件夹名称
    Folder* parentFolder = nullptr;   // 父文件夹
    vector<Folder*> subFolders;   // 子文件夹
    vector<File*> files;          // 文件

    Folder(string x){
        name = x;
    }
};

// 全局变量
const string root_fn = "/";
Folder* root_folder = new Folder(root_fn);
Folder* current_folder = root_folder;   // 当前文件夹初始化为根目录
string current_path = "/";

// 分割路径函数
vector<string> split_path(const string& path) {
    vector<string> parts;
    stringstream ss(path);
    string part;
    while(getline(ss, part, '/')) {
        if (!part.empty()) {
            parts.push_back(part);
        }
    }
    // 移除空路径部分（避免路径中出现冗余的 /）
    parts.erase(remove(parts.begin(), parts.end(), ""), parts.end());
    return parts;
}


// 查找文件夹函数
Folder* find_folder(Folder* start, const string& path) {
    if(path.empty()){
        return start;
    }
    
    // 处理绝对路径
    Folder* current;
    size_t start_index = 0;
    if(path[0] == '/'){
        current = root_folder;
        // 跳过开头的 '/'
        start_index = 1;
    }
    else{
        current = start;
    }
    
    // 分割路径
    vector<string> parts = split_path(path.substr(start_index));
    for(auto &part : parts){
        if(part == "."){
            continue;
        }
        else if(part == ".."){
            if(current->parentFolder != nullptr && current != root_folder){
                current = current->parentFolder;
            }
            // 如果当前文件夹是根目录，则保持不变
        }
        else{
            bool found = false;
            for(auto &sub : current->subFolders){
                if(sub->name == part){
                    current = sub;
                    found = true;
                    break;
                }
            }
            if(!found){
                return nullptr;
            }
        }
    }
    return current;
}

// 查找文件函数
File* find_file(Folder* start, const string& path) {
    if(path.empty()){
        return nullptr;
    }
    
    bool is_absolute = (path[0] == '/');
    size_t last_slash = path.find_last_of('/');
    string folder_path = (last_slash == string::npos) ? "" : path.substr(0, last_slash);
    string file_name = (last_slash == string::npos) ? path : path.substr(last_slash + 1);
    
    // 仅查找文件，不参与路径遍历
    Folder* folder = find_folder(is_absolute ? root_folder : start, folder_path);
    if(folder == nullptr){
        return nullptr;
    }
    
    for(auto &file : folder->files){
        if(file->name == file_name){
            return file;
        }
    }
    return nullptr;
}

void search_folder(Folder* folder, const string& current_path, const regex& pattern, vector<string>& results, bool is_root) {
    // 检查当前文件夹是否匹配
    if (regex_match(folder->name, pattern)) {
        // 根目录路径带有 / 才加上 /
        if (is_root && current_path != "/") {
            results.push_back(current_path + "/");
        } else {
            results.push_back(current_path);
        }
    }

    // 检查当前文件夹中的文件是否匹配
    for (auto &file : folder->files) {
        if (regex_match(file->name, pattern)) {
            string file_path = current_path;
            if (current_path != "/") {
                file_path += "/";
            }
            file_path += file->name;
            results.push_back(file_path);
        }
    }

    // 递归检查子文件夹
    for (auto &sub : folder->subFolders) {
        string sub_path = current_path;
        if (current_path != "/") {
            sub_path += "/";
        }
        sub_path += sub->name;
        search_folder(sub, sub_path, pattern, results, false); // 递归时，根目录已经处理过，所以标记为 false
    }
}




// 处理命令
void process_command(const vector<string>& words) {
    if (words.empty()) {
        cout << "error" << endl;
        return;
    }

    string command = words[0]; // 提取命令名称

    if (command == "pwd") {
        if (words.size() == 1) {
            cout  << current_path << endl;
        } else {
            cout << "error" << endl;
        }
    } 
    else if (command == "cd") {
        if (words.size() == 2) {
            string path = words[1];
            Folder* target_folder = find_folder(current_folder, path);
            if(target_folder != nullptr){
                // 更新当前目录
                current_folder = target_folder;
                
                // 重新计算current_path
                string new_path = "";
                Folder* temp = current_folder;
                while(temp != root_folder){
                    new_path = "/" + temp->name + new_path;
                    temp = temp->parentFolder;
                    if(temp == nullptr){
                        break;
                    }
                }
                if(new_path.empty()){
                    current_path = "/";
                }
                else{
                    current_path = new_path;
                }
            }
            else{
                cout << "error" << endl;
            }
        } else {
            cout << "error" << endl;
        }
    }

    else if (command == "echo") {
        if (words.size() == 2 || words.size() == 4) {
            string text = words[1];
            // 去除单引号
            if(text.front() == '\'' && text.back() == '\''){
                text = text.substr(1, text.size()-2);
            }
            
            if(words.size() == 2){
                // 直接输出
                cout << text << endl;
            }
            else{
                string op = words[2];
                string path = words[3];
                
                bool is_absolute = (path[0] == '/');
                size_t last_slash = path.find_last_of('/');
                string folder_path = (last_slash == string::npos) ? "" : path.substr(0, last_slash);
                string file_name = (last_slash == string::npos) ? path : path.substr(last_slash + 1);
                
                // 查找父文件夹
                Folder* parent_folder = find_folder(is_absolute ? root_folder : current_folder, folder_path);
                if(parent_folder == nullptr){
                    cout << "error" << endl;
                    return;
                }
                
                // 检查是否存在同名文件夹
                auto folder_it = find_if(parent_folder->subFolders.begin(), parent_folder->subFolders.end(),
                                        [&](Folder* f){ return f->name == file_name; });
                if(folder_it != parent_folder->subFolders.end()){
                    cout << "error" << endl;
                    return;
                }
                
                File* file = find_file(is_absolute ? root_folder : current_folder, path);
                
                if(op == ">"){
                    if(file != nullptr){
                        // 覆盖内容
                        file->content = text + "\n";
                    }
                    else{
                        // 创建新文件
                        File* new_file = new File(file_name);
                        new_file->content = text + "\n";
                        new_file->parentFolder = parent_folder;
                        parent_folder->files.push_back(new_file);
                    }
                }
                else if(op == ">>"){
                    if(file != nullptr){
                        // 追加内容
                        file->content += text + "\n";
                    }
                    else{
                        // 创建新文件
                        File* new_file = new File(file_name);
                        new_file->content = text + "\n";
                        new_file->parentFolder = parent_folder;
                        parent_folder->files.push_back(new_file);
                    }
                }
                else{
                    cout << "error" << endl;
                    return;
                }
            }
        } else {
            cout << "error" << endl;
        }
    }

    else if (command == "ls") {
        if ((words.size() == 3)   && words[1] == "-a") {
            string path;
            if(words.size()==3){
                path = words[2];
            }
            Folder* target_folder = find_folder(current_folder, path);
            if(target_folder != nullptr){
                // 收集所有条目，包括 . 和 ..
                vector<string> entries;
                entries.push_back(".");
                entries.push_back("..");
                for(auto &sub : target_folder->subFolders){
                    entries.push_back(sub->name);
                }
                for(auto &file : target_folder->files){
                    entries.push_back(file->name);
                }
                // 排序
                sort(entries.begin(), entries.end());
                // 输出以 \t 分隔
                for(size_t i = 0; i < entries.size(); i++){
                    cout << entries[i];
                    if(i != entries.size()-1){
                        cout << "\t";
                    }
                }
                cout << endl;
            }
            else{
                cout << "error" << endl;
            }
        } else {
            cout << "error" << endl;
        }
    } 
    else if (command == "mkdir") {
        if (words.size() == 3 && words[1] == "-p") {
            string path = words[2];
            if(path.empty()){
                cout << "error" << endl;
                return;
            }

            bool is_absolute = (path[0] == '/');
            vector<string> parts = split_path(path);
            Folder* folder = is_absolute ? root_folder : current_folder;
            
            for(size_t i = 0; i < parts.size(); ++i){
                string part = parts[i];
                if(part == "."){
                    continue;
                }
                else if(part == ".."){
                    if(folder->parentFolder != nullptr){
                        folder = folder->parentFolder;
                    }
                }
                else{
                    // 检查是否存在同名文件夹
                    auto folder_it = find_if(folder->subFolders.begin(), folder->subFolders.end(),
                                             [&](Folder* f){ return f->name == part; });
                    // 检查是否存在同名文件
                    auto file_it = find_if(folder->files.begin(), folder->files.end(),
                                           [&](File* f){ return f->name == part; });
                    if(folder_it != folder->subFolders.end()){
                        // 存在同名文件夹，继续进入该文件夹
                        folder = *folder_it;
                    }
                    else if(file_it != folder->files.end()){
                        // 存在同名文件，报错并退出
                        cout << "error" << endl;
                        return;
                    }
                    else{
                        // 创建新文件夹
                        Folder* new_folder = new Folder(part);
                        new_folder->parentFolder = folder;
                        folder->subFolders.push_back(new_folder);
                        folder = new_folder;
                    }
                }
            }
        } else {
            cout << "error" << endl;
        }
    }

    else if (command == "rm") {
        if (words.size() == 2) {
            // rm /path/to/file
            string path = words[1];
            File* file = find_file(current_folder, path);
            if(file != nullptr){
                // 找到父文件夹并删除文件
                size_t last_slash = path.find_last_of('/');
                string folder_path = (last_slash == string::npos) ? "" : path.substr(0, last_slash);
                string file_name = (last_slash == string::npos) ? path : path.substr(last_slash + 1);
                
                if (!path.empty()&&path[0] == '/' && folder_path.empty()) {
                    folder_path = "/";
                }
                // 解析目标路径，获取目标父文件夹和新名称
                Folder* parent_folder = find_folder(current_folder, folder_path);
                if(parent_folder != nullptr){
                    // 删除文件
                    auto &files = parent_folder->files;
                    files.erase(
                        remove_if(files.begin(), files.end(),
                            [&](File* f){ return f->name == file_name; }),
                        files.end()
                    );
                }
                else{
                    cout << "error" << endl;
                }
            }
            else{
                cout << "error" << endl;
            }
        }
        else if (words.size() == 3 && words[1] == "-r") {
            // rm -r /path/to/dir
            string path = words[2];
            Folder* folder = find_folder(current_folder, path);
            if(folder != nullptr && folder != root_folder){
                // 找到父文件夹并删除子文件夹
                Folder* parent_folder = folder->parentFolder;
                if(parent_folder != nullptr){
                    auto &subFolders = parent_folder->subFolders;
                    subFolders.erase(
                        remove_if(subFolders.begin(), subFolders.end(),
                            [&](Folder* f){ return f->name == folder->name; }),
                        subFolders.end()
                    );
                }
                else{
                    cout << "error" << endl;
                }
            }
            else{
                cout << "error" << endl;
            }
        }
        else{
            cout << "error" << endl;
        }
    } 
    else if (command == "cat") {
        if (words.size() == 2) {
            string path = words[1];
            File* file = find_file(current_folder, path);
            if (file != nullptr) {
                cout << file->content ;
            } else {
                cout << "error" << endl;
            }
        } else {
            cout << "error" << endl;
        }
    }
    else if (command == "mv") {
        if (words.size() == 3) {
            string src_path = words[1];
            string dst_path = words[2];
            
            // 查找源文件夹或文件
            Folder* src_folder = find_folder(current_folder, src_path);
            File* src_file = find_file(current_folder, src_path);
            
            if (src_folder == nullptr && src_file == nullptr) {
                cout << "error" << endl;
                return;
            }
            
            // 尝试将目标路径作为已存在的目录查找
            Folder* existing_dst_folder = find_folder(current_folder, dst_path);
            
            if (existing_dst_folder != nullptr) {
                // 目标路径是一个已存在的目录，尝试将源移动到该目录下
                if (src_folder != nullptr) {
                    // 检查目标目录中是否已存在同名文件夹
                    auto it_folder = find_if(existing_dst_folder->subFolders.begin(), existing_dst_folder->subFolders.end(),
                                             [&](Folder* f){ return f->name == src_folder->name; });
                    if (it_folder != existing_dst_folder->subFolders.end()) {
                        cout << "error" << endl;
                        return;
                    }

                    // 检查是否尝试将文件夹移动到自身或子目录中
                    Folder* temp = existing_dst_folder;
                    while (temp != nullptr && temp != root_folder) {
                        if (temp == src_folder) {
                            cout << "error" << endl;
                            return;
                        }
                        temp = temp->parentFolder;
                    }

                    // 从源父文件夹中移除
                    Folder* src_parent = src_folder->parentFolder;
                    if (src_parent != nullptr) {
                        auto& siblings = src_parent->subFolders;
                        siblings.erase(remove_if(siblings.begin(), siblings.end(),
                                                 [&](Folder* f){ return f == src_folder; }),
                                      siblings.end());
                    }

                    // 设置新父文件夹
                    src_folder->parentFolder = existing_dst_folder;
                    existing_dst_folder->subFolders.push_back(src_folder);
                }
                else {
                    // 源是文件，移动到目标目录
                    // 检查目标目录中是否已存在同名文件或文件夹
                    File* existing_file = find_file(existing_dst_folder, src_file->name);
                    Folder* existing_folder = find_folder(existing_dst_folder, src_file->name);
                    
                    if (existing_file != nullptr) {
                        // 删除目标文件（覆盖）
                        Folder* target_parent = existing_file->parentFolder;
                        if (target_parent != nullptr) {
                            auto& files = target_parent->files;
                            files.erase(remove_if(files.begin(), files.end(),
                                                 [&](File* f){ return f == existing_file; }),
                                        files.end());
                            delete existing_file;
                        }
                    }
                    
                    if (existing_folder != nullptr) {
                        // 存在同名文件夹，无法覆盖，报错并停止操作
                        cout << "error" << endl;
                        return;
                    }

                    // 从源父文件夹中移除
                    Folder* src_parent = src_file->parentFolder;
                    if (src_parent != nullptr) {
                        auto& siblings = src_parent->files;
                        siblings.erase(remove_if(siblings.begin(), siblings.end(),
                                                 [&](File* f){ return f == src_file; }),
                                      siblings.end());
                    }

                    // 设置新父文件夹
                    src_file->parentFolder = existing_dst_folder;
                    existing_dst_folder->files.push_back(src_file);
                }
            }
            else {
                // 目标路径不存在，或者不是一个目录，按原逻辑处理（重命名）
                // 解析目标路径，获取目标父文件夹和新名称
                size_t last_slash = dst_path.find_last_of('/');
                string dst_parent_path = (last_slash == string::npos) ? "" : dst_path.substr(0, last_slash);
                string dst_name = (last_slash == string::npos) ? dst_path : dst_path.substr(last_slash + 1);
                
                // 如果目标路径是绝对路径且目标父路径为空，将目标父路径设为 "/"
                if (!dst_path.empty() && dst_path[0] == '/' && dst_parent_path.empty()) {
                    dst_parent_path = "/";
                }
                
                // 查找目标父文件夹
                Folder* dst_parent_folder = find_folder(current_folder, dst_parent_path);
                if (dst_parent_folder == nullptr) {
                    cout << "error" << endl;
                    return;
                }
                
                if (src_folder != nullptr) {
                    // 移动文件夹：在目标父目录中创建子目录，避免同名
                    auto it_folder = find_if(dst_parent_folder->subFolders.begin(), dst_parent_folder->subFolders.end(),
                                             [&](Folder* f){ return f->name == dst_name; });
                    if (it_folder != dst_parent_folder->subFolders.end()) {
                        cout << "error" << endl;
                        return;
                    }

                    // 检查是否尝试将文件夹移动到自身或子目录中
                    Folder* temp = dst_parent_folder;
                    while (temp != nullptr && temp != root_folder) {
                        if (temp == src_folder) {
                            cout << "error" << endl;
                            return;
                        }
                        temp = temp->parentFolder;
                    }

                    // 从源父文件夹中移除
                    Folder* src_parent = src_folder->parentFolder;
                    if (src_parent != nullptr) {
                        auto& siblings = src_parent->subFolders;
                        siblings.erase(remove_if(siblings.begin(), siblings.end(),
                                                 [&](Folder* f){ return f == src_folder; }),
                                      siblings.end());
                    }

                    // 设置新父文件夹和新名称
                    src_folder->parentFolder = dst_parent_folder;
                    src_folder->name = dst_name;
                    dst_parent_folder->subFolders.push_back(src_folder);
                }
                else {
                    // 移动文件
                    File* existing_file = find_file(dst_parent_folder, dst_name);
                    Folder* existing_folder = find_folder(dst_parent_folder, dst_name);
                    
                    if (existing_file != nullptr) {
                        // 删除目标文件（覆盖）
                        Folder* target_parent = existing_file->parentFolder;
                        if (target_parent != nullptr) {
                            auto& files = target_parent->files;
                            files.erase(remove_if(files.begin(), files.end(),
                                                 [&](File* f){ return f->name == existing_file->name; }),
                                        files.end());
                            delete existing_file;
                        }
                    }

                    if (existing_folder != nullptr) {
                        cout << "error" << endl;
                        return;
                    }

                    // 从源父文件夹中移除
                    Folder* src_parent = src_file->parentFolder;
                    if (src_parent != nullptr) {
                        auto& siblings = src_parent->files;
                        siblings.erase(remove_if(siblings.begin(), siblings.end(),
                                                 [&](File* f){ return f == src_file; }),
                                      siblings.end());
                    }

                    // 设置新父文件夹和新名称
                    src_file->parentFolder = dst_parent_folder;
                    src_file->name = dst_name;
                    dst_parent_folder->files.push_back(src_file);
                }
            }
        }
        else {
            cout << "error" << endl;
        }
    }
    else if (command == "find") {
    if (words.size() == 4 && words[2] == "-name") {
        string search_path = words[1];
        string pattern = words[3];
        
        // 去除单引号
        if (pattern.front() == '\'' && pattern.back() == '\'') {
            pattern = pattern.substr(1, pattern.size() - 2);
        }

        regex regex_pattern;
        try {
            regex_pattern = regex(pattern);
        } catch (regex_error& e) {
            cout << "error" << endl;
            return;
        }

        // 查找起始文件夹
        Folder* start_folder = find_folder(current_folder, search_path);
        if (start_folder == nullptr) {
            cout << "error" << endl;
            return;
        }
        bool is_root = search_path.back() == '/';
        // 构建起始路径的规范形式
        string normalized_start_path = search_path;
        if (normalized_start_path.back() == '/' && normalized_start_path.size() > 1) {
            normalized_start_path.pop_back(); // 移除末尾的 '/'
        }

        vector<string> results;
        search_folder(start_folder, normalized_start_path, regex_pattern, results, is_root);
        
        sort(results.begin(), results.end());

        // 输出结果
        for (auto &path : results) {
            cout << path << endl;
        }
    } else {
        cout << "error" << endl;
    }
}

    else {
        cout << "error" << endl;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    cin.ignore(); 

    
    root_folder->parentFolder = root_folder;
    current_folder = root_folder;
    current_path = "/";

    while(T--){
        string command;  
        getline(cin,command);
        if(command.empty()){
            cout << "error" << endl;
            continue;
        }

        
        vector<string> words;
        bool in_quotes = false;
        string current_word = "";
        for(char c : command){
            if(c == '\''){
                in_quotes = !in_quotes;
                continue;
            }
            if(c == ' ' && !in_quotes){
                if(!current_word.empty()){
                    words.push_back(current_word);
                    current_word = "";
                }
            }
            else{
                current_word += c;
            }
        }
        if(!current_word.empty()){
            words.push_back(current_word);
        }

        if(words.empty()){
            cout << "error" << endl;
            continue;
        }

        process_command(words);
    }

    return 0;
}
