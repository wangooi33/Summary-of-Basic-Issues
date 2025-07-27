在 Linux 系统中，设置环境变量的方法有几种，具体取决于你是要临时设置环境变量还是永久设置。以下是常见的设置方法：

### 1. 临时设置环境变量

临时设置的环境变量只在当前会话中有效，关闭终端后环境变量会消失。

```c
bash

export VAR_NAME="value"
```

例如：

```c
bash


export PATH="$PATH:/new/path"
```

该命令会把 `/new/path` 添加到 `PATH` 环境变量中。

### 2. 永久设置环境变量

#### 修改 `~/.bashrc` 或 `~/.bash_profile` 文件

对于使用 Bash 的用户，修改 `~/.bashrc` 或 `~/.bash_profile` 文件可以使得环境变量在每次登录时自动生效。

1. 打开文件：

   ```c
   bash
   
   nano ~/.bashrc
   ```

   或者

   ```c
   bash
   
   nano ~/.bash_profile
   ```

2. 在文件末尾添加你需要的环境变量。例如：

   ```c
   bash
   
   
   export PATH="$PATH:/new/path"
   ```

3. 保存并退出编辑器后，执行以下命令来使修改生效：

   ```c
   bash
   
   
   source ~/.bashrc
   ```

   或者：

   ```c
   bash
   
   
   source ~/.bash_profile
   ```

#### 修改 `/etc/environment` 文件

`/etc/environment` 是系统范围的配置文件，适用于所有用户。

1. 打开文件：

   ```c
   bash
   
   
   sudo nano /etc/environment
   ```

2. 在文件中添加你需要的环境变量。例如：

   ```c
   bash
   
       
   PATH="$PATH:/new/path"
   ```

3. 保存并退出编辑器后，重新登录或运行以下命令来使修改生效：

   ```c
   bash
   
       
   source /etc/environment
   ```

### 3. 设置环境变量的其他方法

- **`/etc/profile`**：这个文件影响所有用户的环境变量设置（全局配置）。
- **`~/.profile`**：通常用于用户特定的环境配置，适用于非 Bash 的用户（例如使用 Zsh 等）。

通过这些方法，你可以根据需要设置环境变量，不管是临时的还是永久的。





### 判断是否为 Bash 用户：

"Bash 用户" 是指使用 **Bash**（Bourne Again Shell）作为其默认命令行界面的用户。Bash 是一种常用的 Linux/Unix 系统 shell（命令解释器）

如果你的终端使用的是 Bash shell，可以通过以下命令来确认：

```c
bash


echo $SHELL
```

如果输出类似 `/bin/bash`，那么你就是 Bash 用户。