**sudo su root               :切换超级用户**

**mkdir   目录名          :创建目录**

**touch   文件名          :更新文件时间戳，若这个文件不存在则创建**

**rm -r                    :递归地删除目录及其内容**

**cd                       :切换路径**

**mv /home/test/a.txt  /home/test/b.txt  :将a.txt重命名为b.txt**

**mv a.txt ./txt         :移动**

**cp -r 文件 目标路径     :递归地拷贝文件**

**cat /proc/partitions       :查看分区情况**

**cat -A             :显示文本所有内容，包括隐藏的字符**

​    **-n             :输出时会添加文本的行号**

**pwd              :打印文件绝对路径**

**chmod 777 a.txt       :修改文件权限**

**df -h             :查看磁盘使用情况**

**ln -s a.txt A        :为a.txt文件创建软链接A，如果a.txt丢失，A将失效**

**find ./ -name a.txt     :查找当前目录下名为a.txt的文件**

**find ./ -name “\*.c”     :查找当前目录下所有后缀为 .c 的文件**

**find /tmp -type d       :在/tmp中查找类型为目录的文件**

**tar -c              :创建一个新的归档文件**

**-x              :从归档文件中提取文件**

**-f             :指定要处理的归档文件名  f必须放在最后**

**-z             :使用gzip压缩创建tar文件**

**-j             :使用bzip2压缩法创建归档文件**

**tar  czf  a.tar.gz  dir/\*   :*将目录dir中的所有文件归档并压缩为gz格式**

**tar  xzf  a.tar.gz       :*解压压缩文件a.tar.gz**

**tar  cjf  a.tar.bz2  dir/\*    :*将目录dir中的所有文件归档并压缩为bz2格式**

**tar  xjf  a.tar.bz2       :*解压压缩文件a.tar.bz2**

**which ls            :*查看指令ls的绝对路径**

**file**  **文件名          :查看文件类型**

**ifconfig             :查看网络信息**

**sudo ifconfig  ens32 192.168.xxx.xxx :修改网卡IP为192.168.xxx.xxx**

**ps               :查看当前进程状态**

**alias l=”ls -l”        :给指令起别名，别名=“指令名称”，单次有效**

**reboot             :软重启**

**mkfs.vfat /dev/mmcblk0p7  :格式化扇区**

**mount -t vfat  /dev/mmcblk0p7 /wangwork :把/dev/mmcblk0p挂载到/wangwork上**

**scp a.txt** [**wang@192.168.xxx.xxx:/home/gec**](mailto:wang@192.168.xxx.xxx:/home/gec)         **:上传文件**

**scp -r wangwork/** [**wang@192.168.xxx.xxx:/home/gec**](mailto:wang@192.168.xxx.xxx:/home/gec) **:*递归方式上传->上传文件夹**

**scp** [**wang@192.168.xxx.xxx:/home/gec/a.txt**](mailto:wang@192.168.xxx.xxx:/home/gec/a.txt) **.        :*下载文件**

**scp -r** [**wang@192.168.xxx.xxx:/home/gec/dir**](mailto:wang@192.168.xxx.xxx:/home/gec/dir)  **.     :*递归方式下载->下载文件**

**tftp -g 192.168.xxx.xxx -r a.txt  :下载**

**tftp -p 192.168.xxx.xxx -r a.txt  :上传**

**tftp不能直接上传文件夹，也不能从虚拟机直接传输**

**df -h                     :查看当前文件系统磁盘空间使用情况**

**ln  -s 源文件 目标文件               :创建软链接**

**file 文件名                          :查看文件类型**

**ps -ef 或者 ps -aux                   :查看进程状态**

**ls  -li					：打印文件索引**

**cat filesystems			:查看文件系统**

**ipcmk					：创建IPC对象  （man 1 ipcmk）** 

**uname  -a				：查看系统位数**