id
===
![](../../../wmimages/wm71_club.png)


[//]: # (wmtag_memo_下面是我们修改的_开始)


```bash
demo_11(){
    echo -e "\n这是_缺省的_演示内容_1070."
    export the_demo_script_name=$(basename ${BASH_SOURCE[0]})
    echo -e "运行在****$(pwd)/${the_demo_script_name}脚本的****${FUNCNAME}()函数中****第${LINENO}行\n"

    #TODO 进入某一个实验目录
    export the_demo_script_name=$(basename ${BASH_SOURCE[0]})
    export to_demo_dirname=$(echo $the_demo_script_name | awk -F### '{print $1}')
    [[ -d ~/${to_demo_dirname} ]] && cd ~/${to_demo_dirname} && pwd && ls -l

    unset the_demo_script_name
    return 0
}
demo_11
```


```bash
demo_31(){
    echo -e "\n这是_缺省的_演示内容_1070."
    export the_demo_script_name=$(basename ${BASH_SOURCE[0]})
    echo -e "运行在****$(pwd)/${the_demo_script_name}脚本的****${FUNCNAME}()函数中****第${LINENO}行\n"

    #TODO 进入某一个实验目录
    export the_demo_script_name=$(basename ${BASH_SOURCE[0]})
    export to_demo_dirname=$(echo $the_demo_script_name | awk -F### '{print $1}')
    [[ -d ~/${to_demo_dirname} ]] && cd ~/${to_demo_dirname} && pwd && ls -l

    unset the_demo_script_name
    return 0
}
#demo_31
```


[//]: # (wmtag_memo_下面是我们修改的_结束)



打印真实以及有效的用户和所在组的信息

## 概要

```shell
id [OPTION]... [USER]...
```

## 主要用途

- 没有选项时，打印指定用户ID信息。

## 选项

```shell
-a               兼容性选项，没有实际作用。
-Z, --context    只打印进程的安全上下文。
-g, --group      只打印有效的组ID。
-G, --groups     打印全部组ID。
-u, --user       只打印有效的用户ID。
-z, --zero       使用空字符代替默认的空格来分隔条目。
--help           显示帮助信息并退出。
--version        显示版本信息并退出。
```

只有在使用 `-u` `-g` `-G` 选项中一到多个时，以下选项可以使用：
```shell
-n, --name    打印名称而不是数字。
-r, --real    打印真实ID而不是有效ID。
```

## 参数
user（可选）：可以为一到多个，默认为当前用户。

## 返回值

返回0表示成功，返回非0值表示失败。

## 例子

```shell
[root@localhost ~]# id
uid=0(root) gid=0(root) groups=0(root),1(bin),2(daemon),3(sys),4(adm),6(disk),10(wheel)
```

解释：用户root的UID号码 = 0，GID号码 = 0。用户root是下面组的成员：

* root组GID号是：0
* bin组GID号是：1
* daemon组GID号是：2
* sys组GID号是：3
* adm组GID号是：4
* disk组GID号是：6
* wheel组GID号是：10

打印用户名、UID 和该用户所属的所有组，要这么做，我们可以使用 -a 选项：

```shell
[root@localhost ~]# id -a
uid=0(root) gid=0(root) groups=0(root),1(bin),2(daemon),3(sys),4(adm),6(disk),10(wheel)
```

输出所有不同的组ID ，有效的，真实的和补充的，我们可以使用 -G 选项来实现：

```shell
[root@localhost ~]# id -G
0 1 2 3 4 6 10
```

结果只会显示GID号。你可以和`/etc/group`文件比较。下面是`/etc/group`文件的示例内容：

只输出有效的组ID，通过使用 -g 选项来只输出有效组ID：

```shell
[root@localhost ~]# id -g
0
```

输出特定用户信息，我们可以输出特定的用户信息相关的UID和GID。只需要在id命令后跟上用户名：

```shell
[root@localhost ~]# id www
uid=500(www) gid=500(www) groups=500(www)
```

### 注意

1. 该命令可以显示真实有效的用户ID(UID)和组ID(GID)。UID 是对一个用户的单一身份标识。组ID（GID）则对应多个UID；一些程序可能需要UID/GID来运行。`id` 使我们更加容易地找出用户的UID以及GID，而不必在 `/etc/group` 文件中搜寻。

2. 该命令是`GNU coreutils`包中的命令，相关的帮助信息请查看`man -s 1 id`，`info coreutils 'id invocation'`。


